## Hardware implementation

Three tables are implemented:

 * INTERFACE TABLE
 * STATE
 * COMMAND QUEUE

Fields in the table (short explanation):
 
 * Name   : Human readable interface name
 * I/O    : Input (logical "1") / Output (logical "0")
 * Index  : 5 bit unique number for fast control (starts from "0" for Inputs and Outputs)
 * Type   : variable type ( bool (00), int (01), float (10), char (11) )
 * VALUE  : read only (actual value from ADC or current state)


## Example:

#### INTERFACE TABLE

| Name   | I/O | Index | Type | Pin |
|--------|:---:|:-----:|:----:|-----|
| LAMP1  | 0   | 00000 | 00   | 13  |
| LAMP2  | 0   | 00001 | 00   |  1  |
| TIMER1 | 1   | 00000 | 01   |  0  |
| TIMER1 | 0   | 00000 | 01   |  0  |

#### STATE

| Inputs |       | Outputs |       |
|--------|-------|---------|-------|
| Index  | VALUE | Index   | VALUE |
| 00000  | 1255  | 00000   | 0     |
|        |       | 00001   | 0     |

#### COMMAND QUEUE

| Condition (When)  | Set (Then) |
|-------------------|------------|
| if 00000 > 1255   | 00000   1  |
|                   | 00001   1  |
|                   | 00010   0  |
