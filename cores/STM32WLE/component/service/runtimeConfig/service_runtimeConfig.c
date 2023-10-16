#include <stdint.h>
#include <stdbool.h>
#include "service_runtimeConfig.h"

#ifdef SUPPORT_LORA_P2P
static bool useRuntimeConfigP2P = false;
static runtimeConfigP2P_t gRutimeConfigP2P;

bool get_useRuntimeConfigP2P(void)
{
    return useRuntimeConfigP2P;
}

void set_useRuntimeConfigP2P(bool useRuntimeConfig)
{
    useRuntimeConfigP2P = useRuntimeConfig;
    return;
}

bool get_runtimeConfigP2P(runtimeConfigP2P_t *configP2P)
{
    memcpy(configP2P, &gRutimeConfigP2P, sizeof(runtimeConfigP2P_t));
	return true;
}

bool set_runtimeConfigP2P(runtimeConfigP2P_t *configP2P)
{
    memcpy(&gRutimeConfigP2P, configP2P, sizeof(runtimeConfigP2P_t));
    return true;
}
#endif

