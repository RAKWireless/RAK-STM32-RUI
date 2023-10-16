#include "RAKSystem.h"

extern const char *sw_version;
extern const char *model_id;
extern const char *chip_id;
extern const char *cli_version;
extern const char *api_version;

extern bool no_busy_loop;

RAKSystem::RAKSystem() {
}

RAKSystem::firmwareVersion::firmwareVersion() {
    char version[33];
    service_nvm_get_firmware_ver_from_nvm((uint8_t*)version,32);
    version[32]= '\0';
    ver = version;
}

RAKSystem::cliVersion::cliVersion() {
    char version[33];
    service_nvm_get_cli_ver_from_nvm((uint8_t*)version,32);
    version[32]= '\0';
    ver = version;
}

RAKSystem::apiVersion::apiVersion() {
    RAKSystem::apiVersion::ver = api_version;
}

RAKSystem::modelId::modelId() {
    char model[33];
    service_nvm_get_hwmodel_from_nvm((uint8_t*)model,32);
    model[32]= '\0';
    id = model;
}

RAKSystem::chipId::chipId() {
    RAKSystem::chipId::id = chip_id;
}

String RAKSystem::firmwareVersion::get() {
    char version[33];
    service_nvm_get_firmware_ver_from_nvm((uint8_t*)version,32);
    version[32]= '\0';
    ver = version;
    return ver;
}

bool RAKSystem::firmwareVersion::set(String version) {
    if (UDRV_RETURN_OK == service_nvm_set_firmware_ver_to_nvm((uint8_t*)version.c_str(),version.length()))
        return true;
    return false;
}

String RAKSystem::cliVersion::get() {
    char version[33];
    service_nvm_get_cli_ver_from_nvm((uint8_t*)version,32);
    version[32]= '\0';
    ver = version;
    return ver;
}

bool RAKSystem::cliVersion::set(String version) {
    if (UDRV_RETURN_OK == service_nvm_set_cli_ver_to_nvm((uint8_t*)version.c_str(),version.length()))
        return true;
    return false;
}

const String RAKSystem::apiVersion::get() {
    return RAKSystem::apiVersion::ver;
}

String RAKSystem::modelId::get() {
    char model[33];
    service_nvm_get_hwmodel_from_nvm((uint8_t*)model,32);
    model[32]= '\0';
    id = model;
    return id;
}

bool RAKSystem::modelId::set(String model) {
    if (UDRV_RETURN_OK == service_nvm_set_hwmodel_to_nvm((uint8_t*)model.c_str(),model.length()))
        return true;
    return false;
}


const String RAKSystem::chipId::get() {
    return RAKSystem::chipId::id;
}

void RAKSystem::reboot() {
    udrv_system_reboot();
}

void RAKSystem::restoreDefault() {
#ifdef SUPPORT_LORA
    while (service_lora_set_lora_default() != UDRV_RETURN_OK) {
        udrv_delay_ms(1000);
    }
#else
    while (service_nvm_set_default_config_to_nvm() != UDRV_RETURN_OK) {
        udrv_delay_ms(1000);
    }
#endif
    service_nvm_set_cfg_to_nvm();
}

bool RAKSystem::pword::set(char *passwd, uint32_t len) {
    if (udrv_serial_set_passwd(passwd, len) == UDRV_RETURN_OK)
        return true;
    return false;
}

bool RAKSystem::pword::set(String passwd) {
    if (udrv_serial_set_passwd(passwd.c_str(), passwd.length()) == UDRV_RETURN_OK)
        return true;
    return false;
}

void RAKSystem::pword::lock(void) {
    return udrv_serial_lock();
}

void RAKSystem::pword::unlock(void) {
    return udrv_serial_unlock();
}

float RAKSystem::bat::get(void) {
    float bat_lvl;
    service_battery_get_batt_level(&bat_lvl);
    return bat_lvl;
}

// Obsoleted
//bool RAKSystem::flash::get(uint32_t offset, uint8_t *buff, uint32_t len) {
//    return (bool)!!service_nvm_read_user_data(offset, buff, len);
//}

//bool RAKSystem::flash::set(uint32_t offset, uint8_t *buff, uint32_t len) {
//    return (bool)!!service_nvm_write_user_data(offset, buff, len);
//}

bool RAKSystem::atMode::add(char *cmd, char *usage, char *title, PF_handle handle, unsigned int perm) {
    return service_mode_cli_register(cmd, title, handle, 0xFF, usage, perm);
}

#ifdef SUPPORT_FS
int32_t RAKSystem::fs::ferrno(SERVICE_FS_FILE file) {
    return service_fs_ferrno(file);
}

int32_t RAKSystem::fs::derrno(SERVICE_FS_DIR dir) {
    return service_fs_derrno(dir);
}

SERVICE_FS RAKSystem::fs::init(void) {
    return service_fs_init();
}

SERVICE_FS RAKSystem::fs::reset(void) {
    return service_fs_reset();
}

int32_t RAKSystem::fs::list(SERVICE_FS fs, SERVICE_FS_DIR *d, SERVICE_FS_DIRENT *entry) {
    return service_fs_list(fs, d, entry);
}

SERVICE_FS_FILE RAKSystem::fs::open(SERVICE_FS fs, const char* path, uint32_t flags, uint32_t mode) {
    return service_fs_open(fs, path, flags, mode);
}

int32_t RAKSystem::fs::read(SERVICE_FS fs, SERVICE_FS_FILE file, void* buf, uint32_t len) {
    return service_fs_read(fs, file, buf, len);
}

int32_t RAKSystem::fs::write(SERVICE_FS fs, SERVICE_FS_FILE file, void* buf, uint32_t len) {
    return service_fs_write(fs, file, buf, len);
}

int32_t RAKSystem::fs::lseek(SERVICE_FS fs, SERVICE_FS_FILE file, int32_t offs, uint32_t whence) {
    return service_fs_lseek(fs, file, offs, whence);
}

int32_t RAKSystem::fs::remove(SERVICE_FS fs, const char* path) {
    return service_fs_remove(fs, path);
}

int32_t RAKSystem::fs::fremove(SERVICE_FS fs, SERVICE_FS_FILE file) {
    return service_fs_fremove(fs, file);
}

int32_t RAKSystem::fs::stat(SERVICE_FS fs, const char* path, SERVICE_FS_FILE_STAT* stat) {
    return service_fs_stat(fs, path, stat);
}

int32_t RAKSystem::fs::fstat(SERVICE_FS fs, SERVICE_FS_FILE file, SERVICE_FS_FILE_STAT* stat) {
    return service_fs_fstat(fs, file, stat);
}

int32_t RAKSystem::fs::flush(SERVICE_FS fs, SERVICE_FS_FILE file) {
    return service_fs_flush(fs, file);
}

int32_t RAKSystem::fs::close(SERVICE_FS fs, SERVICE_FS_FILE file) {
    return service_fs_close(fs, file);
}

int32_t RAKSystem::fs::rename(SERVICE_FS fs, const char* old_name, const char* new_name) {
    return service_fs_rename(fs, old_name, new_name);
}

int32_t RAKSystem::fs::opendir(SERVICE_FS fs, const char* name, SERVICE_FS_DIR* d) {
    return service_fs_opendir(fs, name, d);
}

int32_t RAKSystem::fs::closedir(SERVICE_FS fs, SERVICE_FS_DIR* d) {
    return service_fs_closedir(fs, d);
}

SERVICE_FS_DIRENT* RAKSystem::fs::readdir(SERVICE_FS fs, SERVICE_FS_DIR* d, SERVICE_FS_DIRENT* e) {
    return service_fs_readdir(fs, d, e);
}

int32_t RAKSystem::fs::feof(SERVICE_FS fs, SERVICE_FS_FILE file) {
    return service_fs_feof(fs, file);
}

int32_t RAKSystem::fs::ftell(SERVICE_FS fs, SERVICE_FS_FILE file) {
    return service_fs_ftell(fs, file);
}
#else
bool RAKSystem::flash::get(uint32_t offset, uint8_t *buff, uint32_t len) {
    if (service_nvm_read_user_data(offset, buff, len) == UDRV_RETURN_OK)
        return true;
    else
        return false;
}

bool RAKSystem::flash::set(uint32_t offset, uint8_t *buff, uint32_t len) {
    if (service_nvm_write_user_data(offset, buff, len) == UDRV_RETURN_OK)
        return true;
    else
        return false;
}
#endif

bool RAKSystem::alias::get(char * buf, uint32_t len) {
    if (service_nvm_get_atcmd_alias_from_nvm((uint8_t *)buf, len) == UDRV_RETURN_OK)
        return true;
    else 
        return false;
}

bool RAKSystem::alias::set(char * buf, uint32_t len) {
    if (service_nvm_set_atcmd_alias_to_nvm((uint8_t *)buf, len) == UDRV_RETURN_OK) 
        return true;
    else   
        return false;
}

bool RAKSystem::timer::create(RAK_TIMER_ID id, RAK_TIMER_HANDLER handler, RAK_TIMER_MODE mode) {
    if (udrv_timer_create((TimerID_E)id, (timer_handler)handler, (TimerMode_E)mode) == UDRV_RETURN_OK)
        return true;
    else
        return false;
}

bool RAKSystem::timer::start(RAK_TIMER_ID id, uint32_t ms, void *data) {
    if (udrv_timer_start((TimerID_E)id, ms, data) == UDRV_RETURN_OK)
        return true;
    else
        return false;
}

bool RAKSystem::timer::stop(RAK_TIMER_ID id) {
    if (udrv_timer_stop((TimerID_E)id) == UDRV_RETURN_OK)
        return true;
    else
        return false;
}

bool RAKSystem::scheduler::task::create(char *name, RAK_TASK_HANDLER handler) {
#ifdef SUPPORT_MULTITASK
    if (udrv_create_thread(name, handler) == UDRV_RETURN_OK) {
        return true;
    } else {
        return false;
    }
#else
    return true;
#endif
}

bool RAKSystem::scheduler::task::destroy(char *name) {
#ifdef SUPPORT_MULTITASK
    udrv_destroy_thread(name);
#else
    no_busy_loop = true;
#endif
    return true;
}

bool RAKSystem::scheduler::task::destroy(void) {
#ifdef SUPPORT_MULTITASK
    udrv_destroy_myself();
#else
    no_busy_loop = true;
#endif
    return true;
}

