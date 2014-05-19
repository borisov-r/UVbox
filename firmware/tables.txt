## Hardware implementation

Three tables are implemented:

 * INTERFACE TABLE
 * STATE
 * COMMAND QUEUE

Example:

#### INTERFACE TABLE

| Name   | I/O | Index | Type | Pin |
|--------|:---:|:-----:|:----:|-----|
| LAMP1  | 0   | 00000 | 00   | 13  |
| LAMP2  | 0   | 00001 | 00   |  1  |
| TIMER1 | 1   | 00000 | 01   |  0  |
| TIMER1 | 0   | 00000 | 01   |  0  |

#### STATE

| I             | O             |
|---------------|---------------|
| Index | VALUE | INDEX | VALUE |
|---------------|---------------|
| 00000 | 1255  | 00000 | 0     |
|       |       | 00001 | 0     |

#### COMMAND QUEUE

| Condition (When)  | Set (Then) |
|-------------------|------------|
| if 00000 > 1255   | 00000   1  |
|                   | 00001   1  |
|                   | 00010   0  |
