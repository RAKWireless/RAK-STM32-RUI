
/*
PERMISSION LEVEL:
ATCMD_PERM_READ,
ATCMD_PERM_WRITE,
ATCMD_PERM_WRITEONCEREAD,
ATCMD_PERM_DISABLE

ATCMD_PERM_DISABLE will have the highest priority then other permission.

Can also add the directives in variant.h
The format is AT_*your_command*_PERM.
For example:
#define AT_APPKEY_PERM      ATCMD_PERM_READ
#define AT_DEVEUI_PERM     ATCMD_PERM_WRITE
#define AT_PWORD_PERM     ATCMD_PERM_WRITEONCEREAD
#define AT_APPEUI_PERM      ATCMD_PERM_DISABLE
#define AT_ALIAS_PERM       ATCMD_PERM_READ | ATCMD_PERM_WRITE
*/

CHANGE_ATCMD_PERM("AT+APPKEY",ATCMD_PERM_READ);
CHANGE_ATCMD_PERM("AT+DEVEUI",ATCMD_PERM_WRITE);
CHANGE_ATCMD_PERM("AT+PWORD",ATCMD_PERM_WRITEONCEREAD);
CHANGE_ATCMD_PERM("AT+APPEUI",ATCMD_PERM_DISABLE);
CHANGE_ATCMD_PERM("AT+ALIAS",ATCMD_PERM_READ | ATCMD_PERM_WRITE);

void setup()
{

    Serial.println("RAKwireless AT Command Permission Example");
    Serial.println("------------------------------------------------------");
}

void loop()
{
    
}
