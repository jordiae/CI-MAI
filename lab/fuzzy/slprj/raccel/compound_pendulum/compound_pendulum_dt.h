#include "__cf_compound_pendulum.h"
#include "ext_types.h"
static DataTypeInfo rtDataTypeInfoTable [ ] = { { "real_T" , 0 , 8 } , {
"real32_T" , 1 , 4 } , { "int8_T" , 2 , 1 } , { "uint8_T" , 3 , 1 } , {
"int16_T" , 4 , 2 } , { "uint16_T" , 5 , 2 } , { "int32_T" , 6 , 4 } , {
"uint32_T" , 7 , 4 } , { "boolean_T" , 8 , 1 } , { "fcn_call_T" , 9 , 0 } , {
"int_T" , 10 , 4 } , { "pointer_T" , 11 , 8 } , { "action_T" , 12 , 8 } , {
"timer_uint32_pair_T" , 13 , 8 } , { "struct_Lvwsl52K9nkTEmAguKrvfF" , 14 ,
64 } , { "struct_RCP1oovUDF2zF6C9vcJmtG" , 15 , 48 } , {
"struct_OTlcYhhT3UxB0PEhAC2ANE" , 16 , 152 } , {
"struct_M2KjdghxeIBw8CLQXGCS1D" , 17 , 1760 } } ; static uint_T
rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T ) , sizeof (
int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof ( uint16_T ) ,
sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T ) , sizeof (
fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof ( action_T )
, 2 * sizeof ( uint32_T ) , sizeof ( struct_Lvwsl52K9nkTEmAguKrvfF ) , sizeof
( struct_RCP1oovUDF2zF6C9vcJmtG ) , sizeof ( struct_OTlcYhhT3UxB0PEhAC2ANE )
, sizeof ( struct_M2KjdghxeIBw8CLQXGCS1D ) } ; static const char_T *
rtDataTypeNames [ ] = { "real_T" , "real32_T" , "int8_T" , "uint8_T" ,
"int16_T" , "uint16_T" , "int32_T" , "uint32_T" , "boolean_T" , "fcn_call_T"
, "int_T" , "pointer_T" , "action_T" , "timer_uint32_pair_T" ,
"struct_Lvwsl52K9nkTEmAguKrvfF" , "struct_RCP1oovUDF2zF6C9vcJmtG" ,
"struct_OTlcYhhT3UxB0PEhAC2ANE" , "struct_M2KjdghxeIBw8CLQXGCS1D" } ; static
DataTypeTransition rtBTransitions [ ] = { { ( char_T * ) ( & rtB . c2qz4jwewh
) , 0 , 0 , 11 } , { ( char_T * ) ( & rtDW . kuhyfz23rp ) , 0 , 0 , 4 } , { (
char_T * ) ( & rtDW . lbmqk1bfth . LoggedData ) , 11 , 0 , 4 } } ; static
DataTypeTransitionTable rtBTransTable = { 3U , rtBTransitions } ; static
DataTypeTransition rtPTransitions [ ] = { { ( char_T * ) ( & rtP .
OutputSamplePoints_Value [ 0 ] ) , 0 , 0 , 113 } } ; static
DataTypeTransitionTable rtPTransTable = { 1U , rtPTransitions } ;
