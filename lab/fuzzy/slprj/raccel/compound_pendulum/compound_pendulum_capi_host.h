#include "__cf_compound_pendulum.h"
#ifndef RTW_HEADER_compound_pendulum_cap_host_h_
#define RTW_HEADER_compound_pendulum_cap_host_h_
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"
typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
compound_pendulum_host_DataMapInfo_T ;
#ifdef __cplusplus
extern "C" {
#endif
void compound_pendulum_host_InitializeDataMapInfo (
compound_pendulum_host_DataMapInfo_T * dataMap , const char * path ) ;
#ifdef __cplusplus
}
#endif
#endif
#endif
