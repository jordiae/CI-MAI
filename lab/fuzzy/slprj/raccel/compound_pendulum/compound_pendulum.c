#include "__cf_compound_pendulum.h"
#include "rt_logging_mmi.h"
#include "compound_pendulum_capi.h"
#include <math.h>
#include "compound_pendulum.h"
#include "compound_pendulum_private.h"
#include "compound_pendulum_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; extern boolean_T
gblExtModeStartPktReceived ; void raccelForceExtModeShutdown ( ) { if ( !
gblExtModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 1 , & stopRequested ) ; }
rtExtModeShutdown ( 1 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 2 ; const char_T
* gbl_raccel_Version = "9.2 (R2018b) 24-May-2018" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj//raccel//compound_pendulum//compound_pendulum_Jpattern.mat" ; const
int_T gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
const int_T gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [
] = { - 1 } ; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ; int_T enableFcnCallFlag [ ] = { 1 , 1 } ;
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; static real_T hywhu1rqsn ( real_T x , const real_T params [ 3 ] )
; static void foi15xcysa ( const real_T x [ 101 ] , const real_T params [ 3 ]
, real_T y [ 101 ] ) ; static void mu2nj2keib ( const real_T
outputSamplePoints [ 101 ] , real_T outputMFCache [ 303 ] ) ; static int32_T
geqdjh2fvl ( int32_T x ) ; static real_T cqv5cjnvom ( const real_T x [ 2 ] )
; static real_T pxlouccwjb ( const real_T x [ 2 ] ) ; static real_T
hywhu1rqsn ( real_T x , const real_T params [ 3 ] ) { real_T y ; y = 0.0 ; if
( ( params [ 0 ] != params [ 1 ] ) && ( params [ 0 ] < x ) && ( x < params [
1 ] ) ) { y = 1.0 / ( params [ 1 ] - params [ 0 ] ) * ( x - params [ 0 ] ) ;
} if ( ( params [ 1 ] != params [ 2 ] ) && ( params [ 1 ] < x ) && ( x <
params [ 2 ] ) ) { y = 1.0 / ( params [ 2 ] - params [ 1 ] ) * ( params [ 2 ]
- x ) ; } if ( x == params [ 1 ] ) { y = 1.0 ; } return y ; } static void
foi15xcysa ( const real_T x [ 101 ] , const real_T params [ 3 ] , real_T y [
101 ] ) { real_T a ; real_T b ; real_T c ; int32_T i ; a = params [ 0 ] ; b =
params [ 1 ] ; c = params [ 2 ] ; for ( i = 0 ; i < 101 ; i ++ ) { y [ i ] =
0.0 ; if ( ( a != b ) && ( a < x [ i ] ) && ( x [ i ] < b ) ) { y [ i ] = 1.0
/ ( b - a ) * ( x [ i ] - a ) ; } if ( ( b != c ) && ( b < x [ i ] ) && ( x [
i ] < c ) ) { y [ i ] = 1.0 / ( c - b ) * ( c - x [ i ] ) ; } if ( x [ i ] ==
b ) { y [ i ] = 1.0 ; } } } static void mu2nj2keib ( const real_T
outputSamplePoints [ 101 ] , real_T outputMFCache [ 303 ] ) { real_T tmp [
101 ] ; real_T tmp_p [ 101 ] ; real_T tmp_e [ 3 ] ; real_T tmp_i [ 101 ] ;
int32_T i ; tmp_e [ 0 ] = - 25.0 ; tmp_e [ 1 ] = - 12.5 ; tmp_e [ 2 ] = 0.0 ;
foi15xcysa ( outputSamplePoints , tmp_e , tmp_i ) ; tmp_e [ 0 ] = - 12.5 ;
tmp_e [ 1 ] = 0.0 ; tmp_e [ 2 ] = 12.5 ; foi15xcysa ( outputSamplePoints ,
tmp_e , tmp_p ) ; tmp_e [ 0 ] = 0.0 ; tmp_e [ 1 ] = 12.5 ; tmp_e [ 2 ] = 25.0
; foi15xcysa ( outputSamplePoints , tmp_e , tmp ) ; for ( i = 0 ; i < 101 ; i
++ ) { outputMFCache [ 3 * i ] = tmp_i [ i ] ; outputMFCache [ 1 + 3 * i ] =
tmp_p [ i ] ; outputMFCache [ 2 + 3 * i ] = tmp [ i ] ; } } static int32_T
geqdjh2fvl ( int32_T x ) { int32_T y ; if ( x < 0 ) { if ( x <= MIN_int32_T )
{ y = MAX_int32_T ; } else { y = - x ; } } else { y = x ; } return y ; }
static real_T cqv5cjnvom ( const real_T x [ 2 ] ) { real_T y ; if ( ( x [ 0 ]
> x [ 1 ] ) || ( muDoubleScalarIsNaN ( x [ 0 ] ) && ( ! muDoubleScalarIsNaN (
x [ 1 ] ) ) ) ) { y = x [ 1 ] ; } else { y = x [ 0 ] ; } return y ; } static
real_T pxlouccwjb ( const real_T x [ 2 ] ) { real_T y ; if ( ( x [ 0 ] < x [
1 ] ) || ( muDoubleScalarIsNaN ( x [ 0 ] ) && ( ! muDoubleScalarIsNaN ( x [ 1
] ) ) ) ) { y = x [ 1 ] ; } else { y = x [ 0 ] ; } return y ; } void
MdlInitialize ( void ) { rtX . f0rhaugahz [ 0 ] = 0.0 ; rtX . pvzt5hwfuo [ 0
] = 0.0 ; rtX . f0rhaugahz [ 1 ] = 0.0 ; rtX . pvzt5hwfuo [ 1 ] = 0.0 ; rtDW
. kuhyfz23rp = ( rtInf ) ; rtDW . pfqrwxz4vf = ( rtInf ) ; } void MdlStart (
void ) { { void * * slioCatalogueAddr = rt_slioCatalogueAddr ( ) ; void * r2
= ( NULL ) ; void * * pOSigstreamManagerAddr = ( NULL ) ; const int
maxErrorBufferSize = 16384 ; char errMsgCreatingOSigstreamManager [ 16384 ] ;
bool errorCreatingOSigstreamManager = false ; const char *
errorAddingR2SharedResource = ( NULL ) ; * slioCatalogueAddr =
rtwGetNewSlioCatalogue ( rt_GetMatSigLogSelectorFileName ( ) ) ;
errorAddingR2SharedResource = rtwAddR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) , 1 ) ; if (
errorAddingR2SharedResource != ( NULL ) ) { rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = ( NULL ) ; ssSetErrorStatus ( rtS
, errorAddingR2SharedResource ) ; return ; } r2 = rtwGetR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ) ;
pOSigstreamManagerAddr = rt_GetOSigstreamManagerAddr ( ) ;
errorCreatingOSigstreamManager = rtwOSigstreamManagerCreateInstance (
rt_GetMatSigLogSelectorFileName ( ) , r2 , pOSigstreamManagerAddr ,
errMsgCreatingOSigstreamManager , maxErrorBufferSize ) ; if (
errorCreatingOSigstreamManager ) { * pOSigstreamManagerAddr = ( NULL ) ;
ssSetErrorStatus ( rtS , errMsgCreatingOSigstreamManager ) ; return ; } } {
bool externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( ) ; rtwISigstreamManagerGetInputIsInDatasetFormat (
pISigstreamManager , & externalInputIsInDatasetFormat ) ; if (
externalInputIsInDatasetFormat ) { } } MdlInitialize ( ) ; } void MdlOutputs
( int_T tid ) { int_T iy ; real_T * lastU ; real_T inputMFCache [ 6 ] ;
int32_T inputID ; static const int8_T b [ 18 ] = { 1 , 1 , 1 , 2 , 2 , 2 , 3
, 3 , 3 , 1 , 2 , 3 , 1 , 2 , 3 , 1 , 2 , 3 } ; static const real_T c [ 3 ] =
{ 0.0 , 2.0 , 5.0 } ; static const real_T d [ 3 ] = { - 5.0 , - 2.0 , 0.0 } ;
real_T outputMFCache [ 303 ] ; static const int8_T b_p [ 9 ] = { 1 , 1 , 1 ,
1 , 2 , 3 , 3 , 3 , 3 } ; real_T area ; real_T acor01uhe5 [ 9 ] ; real_T
f35dzldaz1 [ 101 ] ; real_T tmp [ 3 ] ; real_T outputMFCache_p [ 2 ] ; real_T
byqr2fke04 [ 2 ] ; int32_T q0 ; real_T gq05xbidqc ; real_T x_idx_1 ; int32_T
q0_p ; rtB . c2qz4jwewh = 0.0 ; rtB . c2qz4jwewh += rtP . TransferFcn1_C [ 0
] * rtX . f0rhaugahz [ 0 ] ; rtB . c2qz4jwewh += rtP . TransferFcn1_C [ 1 ] *
rtX . f0rhaugahz [ 1 ] ; rtB . lzy5okyygr = rtP . Gain_Gain * rtB .
c2qz4jwewh ; rtB . ep1karuv5l = 0.0 ; rtB . ep1karuv5l += rtP . TransferFcn_C
[ 0 ] * rtX . pvzt5hwfuo [ 0 ] ; rtB . ep1karuv5l += rtP . TransferFcn_C [ 1
] * rtX . pvzt5hwfuo [ 1 ] ; rtB . frehoim4d2 = rtP . Gain_Gain_mi31umwyue *
rtB . ep1karuv5l ; rtB . liqjkwbtr1 = rtP . Constant_Value - rtB . frehoim4d2
; if ( ( rtDW . kuhyfz23rp >= ssGetT ( rtS ) ) && ( rtDW . pfqrwxz4vf >=
ssGetT ( rtS ) ) ) { rtB . kqvezaiebf = 0.0 ; } else { area = rtDW .
kuhyfz23rp ; lastU = & rtDW . dipvx2lu4h ; if ( rtDW . kuhyfz23rp < rtDW .
pfqrwxz4vf ) { if ( rtDW . pfqrwxz4vf < ssGetT ( rtS ) ) { area = rtDW .
pfqrwxz4vf ; lastU = & rtDW . pnl0qragbx ; } } else { if ( rtDW . kuhyfz23rp
>= ssGetT ( rtS ) ) { area = rtDW . pfqrwxz4vf ; lastU = & rtDW . pnl0qragbx
; } } rtB . kqvezaiebf = ( rtB . liqjkwbtr1 - * lastU ) / ( ssGetT ( rtS ) -
area ) ; } rtB . on3px0zwn2 [ 0 ] = rtB . liqjkwbtr1 ; rtB . on3px0zwn2 [ 1 ]
= rtB . kqvezaiebf ; area = 0.0 ; tmp [ 0 ] = - 80.0 ; tmp [ 1 ] = - 40.0 ;
tmp [ 2 ] = 0.0 ; inputMFCache [ 0 ] = hywhu1rqsn ( rtB . on3px0zwn2 [ 0 ] ,
tmp ) ; tmp [ 0 ] = - 40.0 ; tmp [ 1 ] = 0.0 ; tmp [ 2 ] = 40.0 ;
inputMFCache [ 1 ] = hywhu1rqsn ( rtB . on3px0zwn2 [ 0 ] , tmp ) ; tmp [ 0 ]
= 0.0 ; tmp [ 1 ] = 40.0 ; tmp [ 2 ] = 80.0 ; inputMFCache [ 2 ] = hywhu1rqsn
( rtB . on3px0zwn2 [ 0 ] , tmp ) ; inputMFCache [ 3 ] = hywhu1rqsn ( rtB .
on3px0zwn2 [ 1 ] , d ) ; tmp [ 0 ] = - 2.5 ; tmp [ 1 ] = 0.0 ; tmp [ 2 ] =
2.5 ; inputMFCache [ 4 ] = hywhu1rqsn ( rtB . on3px0zwn2 [ 1 ] , tmp ) ;
inputMFCache [ 5 ] = hywhu1rqsn ( rtB . on3px0zwn2 [ 1 ] , c ) ; for ( iy = 0
; iy < 9 ; iy ++ ) { x_idx_1 = inputMFCache [ b [ iy ] - 1 ] ; if ( 1.0 >
x_idx_1 ) { gq05xbidqc = x_idx_1 ; } else { gq05xbidqc = 1.0 ; } x_idx_1 =
inputMFCache [ b [ iy + 9 ] + 2 ] ; if ( ( gq05xbidqc > x_idx_1 ) || (
muDoubleScalarIsNaN ( gq05xbidqc ) && ( ! muDoubleScalarIsNaN ( x_idx_1 ) ) )
) { gq05xbidqc = x_idx_1 ; } area += gq05xbidqc ; acor01uhe5 [ iy ] =
gq05xbidqc ; } rtB . ahysq3g2yy [ 0 ] = rtB . liqjkwbtr1 ; rtB . ahysq3g2yy [
1 ] = rtB . kqvezaiebf ; memset ( & f35dzldaz1 [ 0 ] , 0 , 101U * sizeof (
real_T ) ) ; mu2nj2keib ( rtP . OutputSamplePoints_Value , outputMFCache ) ;
q0 = geqdjh2fvl ( 0 ) ; for ( iy = 0 ; iy < 9 ; iy ++ ) { if ( ( q0 < 0 ) &&
( b_p [ iy ] < MIN_int32_T - q0 ) ) { q0_p = MIN_int32_T ; } else if ( ( q0 >
0 ) && ( b_p [ iy ] > MAX_int32_T - q0 ) ) { q0_p = MAX_int32_T ; } else {
q0_p = q0 + b_p [ iy ] ; } for ( inputID = 0 ; inputID < 101 ; inputID ++ ) {
outputMFCache_p [ 0 ] = outputMFCache [ ( 3 * inputID + q0_p ) - 1 ] ;
outputMFCache_p [ 1 ] = acor01uhe5 [ iy ] ; byqr2fke04 [ 0 ] = f35dzldaz1 [
inputID ] ; byqr2fke04 [ 1 ] = cqv5cjnvom ( outputMFCache_p ) ; f35dzldaz1 [
inputID ] = pxlouccwjb ( byqr2fke04 ) ; } } if ( area == 0.0 ) { rtB .
m1qgzfrcwm = 0.0 ; } else { rtB . m1qgzfrcwm = 0.0 ; area = f35dzldaz1 [ 0 ]
; for ( iy = 0 ; iy < 100 ; iy ++ ) { area += f35dzldaz1 [ iy + 1 ] ; } if (
area == 0.0 ) { rtB . m1qgzfrcwm = ( rtP . OutputSamplePoints_Value [ 0 ] +
rtP . OutputSamplePoints_Value [ 100 ] ) / 2.0 ; } else { for ( iy = 0 ; iy <
101 ; iy ++ ) { rtB . m1qgzfrcwm += rtP . OutputSamplePoints_Value [ iy ] *
f35dzldaz1 [ iy ] ; } rtB . m1qgzfrcwm *= 1.0 / area ; } } UNUSED_PARAMETER (
tid ) ; } void MdlUpdate ( int_T tid ) { real_T * lastU ; if ( rtDW .
kuhyfz23rp == ( rtInf ) ) { rtDW . kuhyfz23rp = ssGetT ( rtS ) ; lastU = &
rtDW . dipvx2lu4h ; } else if ( rtDW . pfqrwxz4vf == ( rtInf ) ) { rtDW .
pfqrwxz4vf = ssGetT ( rtS ) ; lastU = & rtDW . pnl0qragbx ; } else if ( rtDW
. kuhyfz23rp < rtDW . pfqrwxz4vf ) { rtDW . kuhyfz23rp = ssGetT ( rtS ) ;
lastU = & rtDW . dipvx2lu4h ; } else { rtDW . pfqrwxz4vf = ssGetT ( rtS ) ;
lastU = & rtDW . pnl0qragbx ; } * lastU = rtB . liqjkwbtr1 ; UNUSED_PARAMETER
( tid ) ; } void MdlUpdateTID1 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; }
void MdlDerivatives ( void ) { XDot * _rtXdot ; _rtXdot = ( ( XDot * )
ssGetdX ( rtS ) ) ; _rtXdot -> f0rhaugahz [ 0 ] = 0.0 ; _rtXdot -> f0rhaugahz
[ 0 ] += rtP . TransferFcn1_A [ 0 ] * rtX . f0rhaugahz [ 0 ] ; _rtXdot ->
f0rhaugahz [ 1 ] = 0.0 ; _rtXdot -> f0rhaugahz [ 0 ] += rtP . TransferFcn1_A
[ 1 ] * rtX . f0rhaugahz [ 1 ] ; _rtXdot -> f0rhaugahz [ 1 ] += rtX .
f0rhaugahz [ 0 ] ; _rtXdot -> f0rhaugahz [ 0 ] += rtP . Constant1_Value ;
_rtXdot -> pvzt5hwfuo [ 0 ] = 0.0 ; _rtXdot -> pvzt5hwfuo [ 0 ] += rtP .
TransferFcn_A [ 0 ] * rtX . pvzt5hwfuo [ 0 ] ; _rtXdot -> pvzt5hwfuo [ 1 ] =
0.0 ; _rtXdot -> pvzt5hwfuo [ 0 ] += rtP . TransferFcn_A [ 1 ] * rtX .
pvzt5hwfuo [ 1 ] ; _rtXdot -> pvzt5hwfuo [ 1 ] += rtX . pvzt5hwfuo [ 0 ] ;
_rtXdot -> pvzt5hwfuo [ 0 ] += rtB . m1qgzfrcwm ; } void MdlProjection ( void
) { } void MdlTerminate ( void ) { if ( rt_slioCatalogue ( ) != ( NULL ) ) {
void * * slioCatalogueAddr = rt_slioCatalogueAddr ( ) ;
rtwSaveDatasetsToMatFile ( rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( )
) , rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 4 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
1 ) ; ssSetNumBlocks ( rtS , 22 ) ; ssSetNumBlockIO ( rtS , 9 ) ;
ssSetNumBlockParams ( rtS , 113 ) ; } void MdlInitializeSampleTimes ( void )
{ ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 3975548443U ) ;
ssSetChecksumVal ( rtS , 1 , 13897423U ) ; ssSetChecksumVal ( rtS , 2 ,
197978788U ) ; ssSetChecksumVal ( rtS , 3 , 798625299U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo
; ( void ) memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void )
memset ( ( char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ;
( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = (
void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork ,
0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset (
( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS
, & dtInfo ) ; dtInfo . numDataTypes = 18 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; dtInfo . dataTypeInfoTable = rtDataTypeInfoTable ; }
compound_pendulum_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive (
rtS , true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "compound_pendulum" ) ;
ssSetPath ( rtS , "compound_pendulum" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , 80.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) ,
( NULL ) ) ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 4 ] ; static
real_T absTol [ 4 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 } ; static uint8_T
absTolControl [ 4 ] = { 0U , 0U , 0U , 0U } ; ssSetSolverRelTol ( rtS , 0.001
) ; ssSetStepSize ( rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 ) ;
ssSetMaxNumMinSteps ( rtS , - 1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ;
ssSetMaxStepSize ( rtS , 1.6 ) ; ssSetSolverMaxOrder ( rtS , - 1 ) ;
ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , ( NULL ) ) ;
ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 ) ;
ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 0 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
0 ) ; ssSetNonContDerivSigInfos ( rtS , ( NULL ) ) ; ssSetSolverInfo ( rtS ,
& slvrInfo ) ; ssSetSolverName ( rtS , "VariableStepAuto" ) ;
ssSetVariableStepSolver ( rtS , 1 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector ( rtS , absTol )
; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetSolverStateProjection ( rtS , 0 ) ; ssSetSolverMassMatrixType ( rtS , (
ssMatrixType ) 0 ) ; ssSetSolverMassMatrixNzMax ( rtS , 0 ) ;
ssSetModelOutputs ( rtS , MdlOutputs ) ; ssSetModelLogData ( rtS ,
rt_UpdateTXYLogVars ) ; ssSetModelLogDataIfInInterval ( rtS ,
rt_UpdateTXXFYLogVars ) ; ssSetModelUpdate ( rtS , MdlUpdate ) ;
ssSetModelDerivatives ( rtS , MdlDerivatives ) ;
ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 3975548443U ) ; ssSetChecksumVal ( rtS , 1 ,
13897423U ) ; ssSetChecksumVal ( rtS , 2 , 197978788U ) ; ssSetChecksumVal (
rtS , 3 , 798625299U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 5 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = & rtAlwaysEnabled ;
systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = & rtAlwaysEnabled ;
systemRan [ 4 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; } return
rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 1 ; void MdlOutputsParameterSampleTime (
int_T tid ) { UNUSED_PARAMETER ( tid ) ; }
