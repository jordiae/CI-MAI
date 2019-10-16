#include "__cf_compound_pendulum.h"
#ifndef RTW_HEADER_compound_pendulum_types_h_
#define RTW_HEADER_compound_pendulum_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_Lvwsl52K9nkTEmAguKrvfF_
#define DEFINED_TYPEDEF_FOR_struct_Lvwsl52K9nkTEmAguKrvfF_
typedef struct { uint8_T SimulinkDiagnostic ; uint8_T Model [ 17 ] ; uint8_T
Block [ 41 ] ; uint8_T OutOfRangeInputValue ; uint8_T NoRuleFired ; uint8_T
EmptyOutputFuzzySet ; uint8_T sl_padding0 [ 2 ] ; }
struct_Lvwsl52K9nkTEmAguKrvfF ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_RCP1oovUDF2zF6C9vcJmtG_
#define DEFINED_TYPEDEF_FOR_struct_RCP1oovUDF2zF6C9vcJmtG_
typedef struct { uint8_T type [ 5 ] ; uint8_T sl_padding0 [ 3 ] ; int32_T
origTypeLength ; uint8_T sl_padding1 [ 4 ] ; real_T params [ 3 ] ; int32_T
origParamLength ; uint8_T sl_padding2 [ 4 ] ; } struct_RCP1oovUDF2zF6C9vcJmtG
;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_OTlcYhhT3UxB0PEhAC2ANE_
#define DEFINED_TYPEDEF_FOR_struct_OTlcYhhT3UxB0PEhAC2ANE_
typedef struct { struct_RCP1oovUDF2zF6C9vcJmtG mf [ 3 ] ; int32_T origNumMF ;
uint8_T sl_padding0 [ 4 ] ; } struct_OTlcYhhT3UxB0PEhAC2ANE ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_M2KjdghxeIBw8CLQXGCS1D_
#define DEFINED_TYPEDEF_FOR_struct_M2KjdghxeIBw8CLQXGCS1D_
typedef struct { uint8_T type [ 7 ] ; uint8_T andMethod [ 3 ] ; uint8_T
orMethod [ 3 ] ; uint8_T defuzzMethod [ 8 ] ; uint8_T impMethod [ 3 ] ;
uint8_T aggMethod [ 3 ] ; uint8_T sl_padding0 [ 5 ] ; real_T inputRange [ 4 ]
; real_T outputRange [ 2 ] ; struct_OTlcYhhT3UxB0PEhAC2ANE inputMF [ 2 ] ;
struct_OTlcYhhT3UxB0PEhAC2ANE outputMF ; real_T antecedent [ 18 ] ; real_T
consequent [ 9 ] ; real_T connection [ 9 ] ; real_T weight [ 9 ] ; int32_T
numSamples ; int32_T numInputs ; int32_T numOutputs ; int32_T numRules ;
int32_T numInputMFs [ 2 ] ; int32_T numCumInputMFs [ 2 ] ; int32_T
numOutputMFs ; int32_T numCumOutputMFs ; real_T outputSamplePoints [ 101 ] ;
int32_T orrSize [ 2 ] ; int32_T aggSize [ 2 ] ; }
struct_M2KjdghxeIBw8CLQXGCS1D ;
#endif
#ifndef struct_tag_sDfM9XCdU9DLkphJPFDd11C
#define struct_tag_sDfM9XCdU9DLkphJPFDd11C
struct tag_sDfM9XCdU9DLkphJPFDd11C { uint8_T type [ 5 ] ; int32_T
origTypeLength ; real_T params [ 3 ] ; int32_T origParamLength ; } ;
#endif
#ifndef typedef_kxxztocvgx
#define typedef_kxxztocvgx
typedef struct tag_sDfM9XCdU9DLkphJPFDd11C kxxztocvgx ;
#endif
#ifndef struct_tag_shO0IWYgEilomEPNnioDLBD
#define struct_tag_shO0IWYgEilomEPNnioDLBD
struct tag_shO0IWYgEilomEPNnioDLBD { kxxztocvgx mf [ 3 ] ; int32_T origNumMF
; } ;
#endif
#ifndef typedef_crj35yw3v2
#define typedef_crj35yw3v2
typedef struct tag_shO0IWYgEilomEPNnioDLBD crj35yw3v2 ;
#endif
#ifndef struct_tag_spVuWf9iDJ8dBHmHfm0h57E
#define struct_tag_spVuWf9iDJ8dBHmHfm0h57E
struct tag_spVuWf9iDJ8dBHmHfm0h57E { uint8_T type [ 7 ] ; uint8_T andMethod [
3 ] ; uint8_T orMethod [ 3 ] ; uint8_T defuzzMethod [ 8 ] ; uint8_T impMethod
[ 3 ] ; uint8_T aggMethod [ 3 ] ; real_T inputRange [ 4 ] ; real_T
outputRange [ 2 ] ; crj35yw3v2 inputMF [ 2 ] ; crj35yw3v2 outputMF ; real_T
antecedent [ 18 ] ; real_T consequent [ 9 ] ; real_T connection [ 9 ] ;
real_T weight [ 9 ] ; int32_T numSamples ; int32_T numInputs ; int32_T
numOutputs ; int32_T numRules ; int32_T numInputMFs [ 2 ] ; int32_T
numCumInputMFs [ 2 ] ; int32_T numOutputMFs ; int32_T numCumOutputMFs ;
real_T outputSamplePoints [ 101 ] ; int32_T orrSize [ 2 ] ; int32_T aggSize [
2 ] ; } ;
#endif
#ifndef typedef_abgyhsjgjl
#define typedef_abgyhsjgjl
typedef struct tag_spVuWf9iDJ8dBHmHfm0h57E abgyhsjgjl ;
#endif
#ifndef struct_tag_sSaUo69n8Ln4881c24RpIJD
#define struct_tag_sSaUo69n8Ln4881c24RpIJD
struct tag_sSaUo69n8Ln4881c24RpIJD { uint8_T SimulinkDiagnostic ; uint8_T
Model [ 17 ] ; uint8_T Block [ 41 ] ; uint8_T OutOfRangeInputValue ; uint8_T
NoRuleFired ; uint8_T EmptyOutputFuzzySet ; } ;
#endif
#ifndef typedef_btfb5nand5
#define typedef_btfb5nand5
typedef struct tag_sSaUo69n8Ln4881c24RpIJD btfb5nand5 ;
#endif
#ifndef struct_tag_sXsSeVB4E0ntMvFGNG3D1eC
#define struct_tag_sXsSeVB4E0ntMvFGNG3D1eC
struct tag_sXsSeVB4E0ntMvFGNG3D1eC { uint8_T type [ 5 ] ; real_T params [ 3 ]
; } ;
#endif
#ifndef typedef_dwfj4yrx2z
#define typedef_dwfj4yrx2z
typedef struct tag_sXsSeVB4E0ntMvFGNG3D1eC dwfj4yrx2z ;
#endif
typedef struct P_ P ;
#endif
