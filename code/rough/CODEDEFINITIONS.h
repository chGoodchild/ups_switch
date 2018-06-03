#ifndef CODEDEF
#define CODEDEF

// BEGIN: MULTIMETER.cpp

// Refference voltage
// @@@ Do this in the EEProm? Allow the user to modify / influence this?
// MCP1702 in grace
const float Vref = 4.99;

// @@@ Check the value
const float scaling_err_LB = 9.5;

// @@@ Check the value
const float scaling_err_UB = 14.5;

// Error messages
const float no_error = 1;
const float scaling_error = -1;
const float V_LB_Error = -2;
const float V_UB_Error = -3;
const float perc_LB_Error = -4;
const float perc_UB_Error = -5;

// @@@ Check the following constants.
// Error / Boundary constants
const float scaling_boundary = 9.5;
const float V_LB_Const = 8.5;
const float V_UB_Const = 15.5;
const float perc_LB_Cons = 15;
const float perc_UB_Cons = 85;

// END: MULTIMETER.cpp


// BEGIN: rough.ino


// END: rough.ino

#endif
