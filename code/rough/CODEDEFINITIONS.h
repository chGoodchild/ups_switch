#ifndef CODEDEF
#define CODEDEF

// BEGIN: MULTIMETER.cpp

// Refference voltage
// @@@ Do this in the EEProm? Allow the user to modify / influence this?
// MCP1702 in grace
// @@@ Dyuman knows what needs to be done...
const float Vref = 4.99;

// @@@ Check the value
const float scaling_err_LB = 9.5;

// @@@ Check the value
const float scaling_err_UB = 14.5;

// Error messages
const float no_error = 1;

// This voltage is not expected for any "devisor" between 1 and 4.
// @@@ Switch to TNEB and don't do anything.
const float scaling_error = -1;

// The voltage should never be this low. 
const float V_LB_Error = -2;

// The voltage should never be this low. 
const float V_UB_Error = -3;

// The percentage should never be this low. Note that the battery
// should be safe between 0 percent and 100 percent.
const float perc_LB_Error = -4;

// The percentage should never be this high. Note that the battery
// should be safe between 0 percent and 100 percent.
const float perc_UB_Error = -5;

// The voltage is out of bounds for the given current.
const float percent_function_V_Error = -6;

// The percentage is out of bounds.
const float percent_function_percent_Error = -7;

// @@@ Check the following constants.
// Error / Boundary constantsconst float scaling_boundary = 9.5;
const float V_LB_Const = 8.5;
const float V_UB_Const = 15.5;
const float perc_LB_Cons = 15;
const float perc_UB_Cons = 85;

// END: MULTIMETER.cpp


// BEGIN: rough.ino


// END: rough.ino

#endif
