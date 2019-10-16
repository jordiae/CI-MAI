#include "__cf_compound_pendulum.h"
#ifndef RTW_HEADER_compound_pendulum_h_
#define RTW_HEADER_compound_pendulum_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef compound_pendulum_COMMON_INCLUDES_
#define compound_pendulum_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "compound_pendulum_types.h"
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#define MODEL_NAME compound_pendulum
#define NSAMPLE_TIMES (2) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (9) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (4)   
#elif NCSTATES != 4
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T c2qz4jwewh ; real_T lzy5okyygr ; real_T ep1karuv5l ;
real_T frehoim4d2 ; real_T liqjkwbtr1 ; real_T kqvezaiebf ; real_T ahysq3g2yy
[ 2 ] ; real_T on3px0zwn2 [ 2 ] ; real_T m1qgzfrcwm ; } B ; typedef struct {
real_T kuhyfz23rp ; real_T dipvx2lu4h ; real_T pfqrwxz4vf ; real_T pnl0qragbx
; struct { void * LoggedData ; } lbmqk1bfth ; struct { void * LoggedData ; }
dzqn0ial5x ; struct { void * LoggedData ; } hhosvyyevh ; struct { void *
LoggedData ; } ayqen25mhj ; } DW ; typedef struct { real_T f0rhaugahz [ 2 ] ;
real_T pvzt5hwfuo [ 2 ] ; } X ; typedef struct { real_T f0rhaugahz [ 2 ] ;
real_T pvzt5hwfuo [ 2 ] ; } XDot ; typedef struct { boolean_T f0rhaugahz [ 2
] ; boolean_T pvzt5hwfuo [ 2 ] ; } XDis ; typedef struct { real_T f0rhaugahz
[ 2 ] ; real_T pvzt5hwfuo [ 2 ] ; } CStateAbsTol ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T
OutputSamplePoints_Value [ 101 ] ; real_T TransferFcn1_A [ 2 ] ; real_T
TransferFcn1_C [ 2 ] ; real_T Gain_Gain ; real_T TransferFcn_A [ 2 ] ; real_T
TransferFcn_C [ 2 ] ; real_T Gain_Gain_mi31umwyue ; real_T Constant_Value ;
real_T Constant1_Value ; } ; extern const char * RT_MEMORY_ALLOCATION_ERROR ;
extern B rtB ; extern X rtX ; extern DW rtDW ; extern P rtP ; extern const
rtwCAPI_ModelMappingStaticInfo * compound_pendulum_GetCAPIStaticMap ( void )
; extern SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern
const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern const int_T gblNumRootInportBlks ; extern const int_T
gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ; extern
const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [ ] ;
extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model ( void
) ;
#endif
