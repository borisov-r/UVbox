EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:turnAndHeat-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L CONN_4 P?
U 1 1 543667DD
P 1800 2050
F 0 "P?" V 1750 2050 50  0000 C CNN
F 1 "CONN_4" V 1850 2050 50  0000 C CNN
F 2 "" H 1800 2050 60  0000 C CNN
F 3 "" H 1800 2050 60  0000 C CNN
	1    1800 2050
	-1   0    0    -1  
$EndComp
Text Notes 1700 1650 0    100  ~ 0
Hard disk drive\npower supply connector
Text Notes 2250 1900 0    60   ~ 0
YELLOW
Text Notes 2250 2000 0    60   ~ 0
BLACK
Text Notes 2250 2100 0    60   ~ 0
BLACK
Text Notes 2250 2200 0    60   ~ 0
RED
Wire Wire Line
	2150 1900 2950 1900
Wire Wire Line
	2150 2000 2950 2000
Wire Wire Line
	2150 2100 2950 2100
Wire Wire Line
	2150 2200 2950 2200
Text Label 2950 1900 0    60   ~ 0
+12V
Text Label 2950 2000 0    60   ~ 0
GND
Text Label 2950 2100 0    60   ~ 0
GND
Text Label 2950 2200 0    60   ~ 0
+5V
$Comp
L CONN_2 P?
U 1 1 5436697B
P 10000 1650
F 0 "P?" V 9950 1650 40  0000 C CNN
F 1 "CONN_2" V 10050 1650 40  0000 C CNN
F 2 "" H 10000 1650 60  0000 C CNN
F 3 "" H 10000 1650 60  0000 C CNN
	1    10000 1650
	1    0    0    -1  
$EndComp
Text Notes 9300 1400 0    49   ~ 0
To heating element 1
Text Notes 9300 2150 0    49   ~ 0
To heating element 2
$Comp
L CONN_2 P?
U 1 1 54366A20
P 10000 2350
F 0 "P?" V 9950 2350 40  0000 C CNN
F 1 "CONN_2" V 10050 2350 40  0000 C CNN
F 2 "" H 10000 2350 60  0000 C CNN
F 3 "" H 10000 2350 60  0000 C CNN
	1    10000 2350
	1    0    0    -1  
$EndComp
Wire Notes Line
	10400 2700 7900 2700
Wire Notes Line
	7900 1000 10400 1000
Text Notes 8450 950  0    100  ~ 0
Heaters - 20 to 200 deg
Wire Wire Line
	6000 1750 9650 1750
Wire Wire Line
	8250 1550 9650 1550
Wire Wire Line
	8300 1550 8300 1200
Text Label 8300 1200 0    60   ~ 0
+12V
$Comp
L LED D?
U 1 1 54366BA4
P 7500 1550
F 0 "D?" H 7500 1650 50  0000 C CNN
F 1 "LED" H 7500 1450 50  0000 C CNN
F 2 "" H 7500 1550 60  0000 C CNN
F 3 "" H 7500 1550 60  0000 C CNN
	1    7500 1550
	-1   0    0    1   
$EndComp
$Comp
L R R?
U 1 1 54366C05
P 8000 1550
F 0 "R?" V 8080 1550 40  0000 C CNN
F 1 "R" V 8007 1551 40  0000 C CNN
F 2 "" V 7930 1550 30  0000 C CNN
F 3 "" H 8000 1550 30  0000 C CNN
	1    8000 1550
	0    1    1    0   
$EndComp
Connection ~ 8300 1550
Wire Wire Line
	7750 1550 7700 1550
Wire Wire Line
	7300 1550 7250 1550
Text Notes 7250 1350 0    49   ~ 0
ON / OFF
Wire Wire Line
	8250 2250 9650 2250
Wire Wire Line
	8300 2250 8300 1900
Text Label 8300 1900 0    60   ~ 0
+12V
$Comp
L LED D?
U 1 1 54366D7F
P 7500 2250
F 0 "D?" H 7500 2350 50  0000 C CNN
F 1 "LED" H 7500 2150 50  0000 C CNN
F 2 "" H 7500 2250 60  0000 C CNN
F 3 "" H 7500 2250 60  0000 C CNN
	1    7500 2250
	-1   0    0    1   
$EndComp
$Comp
L R R?
U 1 1 54366D85
P 8000 2250
F 0 "R?" V 8080 2250 40  0000 C CNN
F 1 "R" V 8007 2251 40  0000 C CNN
F 2 "" V 7930 2250 30  0000 C CNN
F 3 "" H 8000 2250 30  0000 C CNN
	1    8000 2250
	0    1    1    0   
$EndComp
Connection ~ 8300 2250
Wire Wire Line
	7750 2250 7700 2250
Wire Wire Line
	7300 2250 7250 2250
Text Notes 7250 2050 0    49   ~ 0
ON / OFF
Wire Wire Line
	7250 2450 9650 2450
$Comp
L MOSFET_N Q?
U 1 1 54366F75
P 5900 2850
F 0 "Q?" H 5850 3050 60  0000 R CNN
F 1 "IRL3803PbF" V 6100 3000 60  0000 R CNN
F 2 "TO-220AB" H 5900 2850 60  0001 C CNN
F 3 "" H 5900 2850 60  0000 C CNN
	1    5900 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 3050 6000 3550
Text Label 6000 3550 3    60   ~ 0
GND
$Comp
L MOSFET_N Q?
U 1 1 543671BE
P 7150 2850
F 0 "Q?" H 7100 3050 60  0000 R CNN
F 1 "IRL3803PbF" V 7400 3000 60  0000 R CNN
F 2 "TO-220AB" H 7150 2850 60  0001 C CNN
F 3 "" H 7150 2850 60  0000 C CNN
	1    7150 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 3050 7250 3550
Text Label 7250 3550 3    60   ~ 0
GND
Wire Wire Line
	7250 2250 7250 2650
Wire Wire Line
	6000 2650 6000 1750
$Comp
L R R?
U 1 1 543673D0
P 6900 3150
F 0 "R?" V 6980 3150 40  0000 C CNN
F 1 "R" V 6907 3151 40  0000 C CNN
F 2 "" V 6830 3150 30  0000 C CNN
F 3 "" H 6900 3150 30  0000 C CNN
	1    6900 3150
	-1   0    0    1   
$EndComp
$Comp
L R R?
U 1 1 54367474
P 5650 3150
F 0 "R?" V 5730 3150 40  0000 C CNN
F 1 "R" V 5657 3151 40  0000 C CNN
F 2 "" V 5580 3150 30  0000 C CNN
F 3 "" H 5650 3150 30  0000 C CNN
	1    5650 3150
	-1   0    0    1   
$EndComp
Wire Wire Line
	6900 3450 6900 3400
Wire Wire Line
	5650 3450 5650 3400
Wire Wire Line
	5650 2900 5650 2850
Wire Wire Line
	5450 2850 5700 2850
Wire Wire Line
	6900 2900 6900 2850
Wire Wire Line
	6700 2850 6950 2850
Connection ~ 6900 2850
Connection ~ 5650 2850
Wire Wire Line
	6900 3450 7250 3450
Connection ~ 7250 3450
Wire Wire Line
	5650 3450 6000 3450
Connection ~ 6000 3450
Wire Wire Line
	7250 1550 7250 1750
Connection ~ 7250 1750
Connection ~ 7250 2450
$Comp
L DIODESCH D?
U 1 1 54367F09
P 9000 1650
F 0 "D?" H 9000 1750 40  0000 C CNN
F 1 "MUR880E" V 9000 1400 40  0000 C CNN
F 2 "TO-220AC" H 9000 1650 60  0001 C CNN
F 3 "" H 9000 1650 60  0000 C CNN
	1    9000 1650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9000 1450 9150 1450
Wire Wire Line
	9150 1450 9150 1550
Connection ~ 9150 1550
Wire Wire Line
	9000 1850 9150 1850
Wire Wire Line
	9150 1850 9150 1750
Connection ~ 9150 1750
Wire Wire Line
	9000 2150 9150 2150
Wire Wire Line
	9150 2150 9150 2250
Connection ~ 9150 2250
Wire Wire Line
	9000 2550 9150 2550
Wire Wire Line
	9150 2550 9150 2450
Connection ~ 9150 2450
Wire Notes Line
	10400 1000 10400 2700
$Comp
L DIODESCH D?
U 1 1 543682D5
P 9000 2350
F 0 "D?" H 9000 2450 40  0000 C CNN
F 1 "MUR880E" V 9000 2100 40  0000 C CNN
F 2 "TO-220AC" H 9000 2350 60  0001 C CNN
F 3 "" H 9000 2350 60  0000 C CNN
	1    9000 2350
	0    -1   -1   0   
$EndComp
$Comp
L CONN_8 P?
U 1 1 543684FC
P 1800 2900
F 0 "P?" V 1750 2900 60  0000 C CNN
F 1 "CONN_6" V 1850 2900 60  0000 C CNN
F 2 "" H 1800 2900 60  0000 C CNN
F 3 "" H 1800 2900 60  0000 C CNN
	1    1800 2900
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2150 2950 2950 2950
Text Label 2950 2950 0    60   ~ 0
GND
Wire Wire Line
	2150 2550 2950 2550
Wire Wire Line
	2150 2750 2950 2750
Text Label 2950 2550 0    60   ~ 0
HEAT1
Text Label 2950 2750 0    60   ~ 0
HEAT2
Text Label 5450 2850 2    60   ~ 0
HEAT1
Text Label 6700 2850 2    60   ~ 0
HEAT2
Wire Wire Line
	2150 3050 2950 3050
Wire Wire Line
	2150 3150 2950 3150
Wire Wire Line
	2150 3250 2950 3250
Text Label 2950 3050 0    60   ~ 0
PH1
Text Label 2950 3150 0    60   ~ 0
PH2
Text Label 2950 3250 0    60   ~ 0
PH3
$Comp
L CONN_4 P?
U 1 1 54368CF7
P 10000 3900
F 0 "P?" V 9950 3900 50  0000 C CNN
F 1 "CONN_4" V 10050 3900 50  0000 C CNN
F 2 "" H 10000 3900 60  0000 C CNN
F 3 "" H 10000 3900 60  0000 C CNN
	1    10000 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	9650 3750 8300 3750
Wire Wire Line
	8300 3750 8300 3300
Text Label 8300 3300 0    60   ~ 0
+5V
$Comp
L DIODESCH D?
U 1 1 54368E2A
P 8300 3950
F 0 "D?" H 8300 4050 40  0000 C CNN
F 1 "MUR880E" H 8650 4000 40  0000 C CNN
F 2 "TO-220AC" H 8300 3950 60  0001 C CNN
F 3 "" H 8300 3950 60  0000 C CNN
	1    8300 3950
	0    -1   -1   0   
$EndComp
$Comp
L DIODESCH D?
U 1 1 54368ECA
P 8500 3950
F 0 "D?" H 8500 4050 40  0000 C CNN
F 1 "MUR880E" H 8850 4000 40  0000 C CNN
F 2 "TO-220AC" H 8500 3950 60  0001 C CNN
F 3 "" H 8500 3950 60  0000 C CNN
	1    8500 3950
	0    -1   -1   0   
$EndComp
$Comp
L DIODESCH D?
U 1 1 54368F15
P 8700 3950
F 0 "D?" H 8700 4050 40  0000 C CNN
F 1 "MUR880E" H 9050 4000 40  0000 C CNN
F 2 "TO-220AC" H 8700 3950 60  0001 C CNN
F 3 "" H 8700 3950 60  0000 C CNN
	1    8700 3950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8700 4150 8850 4150
Wire Wire Line
	8850 4150 8850 3850
Wire Wire Line
	8850 3850 9650 3850
Wire Wire Line
	9650 3950 8900 3950
Wire Wire Line
	8900 3950 8900 4200
Wire Wire Line
	8900 4200 8500 4200
Wire Wire Line
	8500 4150 8500 4600
Wire Wire Line
	8300 4150 8300 4500
Wire Wire Line
	8300 4250 8950 4250
Wire Wire Line
	8950 4250 8950 4050
Wire Wire Line
	8950 4050 9650 4050
Connection ~ 8300 4250
Connection ~ 8500 4200
Wire Wire Line
	8700 4150 8700 4750
Wire Notes Line
	9100 3250 10400 3250
Wire Notes Line
	10400 3250 10400 4650
Wire Notes Line
	10400 4650 9100 4650
Wire Notes Line
	9100 4650 9100 3250
Text Notes 9100 3250 0    99   ~ 0
HDD MOTOR
Text Notes 9200 4300 0    60   ~ 0
check phases and power
$Comp
L MOSFET_N Q?
U 1 1 54369861
P 8600 4950
F 0 "Q?" H 8550 5150 60  0000 R CNN
F 1 "IRL3803PbF" V 8850 5100 60  0000 R CNN
F 2 "TO-220AB" H 8600 4950 60  0001 C CNN
F 3 "" H 8600 4950 60  0000 C CNN
	1    8600 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	8700 5150 8700 5650
Text Label 8700 5650 3    60   ~ 0
GND
$Comp
L R R?
U 1 1 5436986A
P 8350 5250
F 0 "R?" V 8430 5250 40  0000 C CNN
F 1 "R" V 8357 5251 40  0000 C CNN
F 2 "" V 8280 5250 30  0000 C CNN
F 3 "" H 8350 5250 30  0000 C CNN
	1    8350 5250
	-1   0    0    1   
$EndComp
Wire Wire Line
	8350 5550 8350 5500
Wire Wire Line
	8350 5000 8350 4950
Wire Wire Line
	8150 4950 8400 4950
Connection ~ 8350 4950
Wire Wire Line
	8350 5550 8700 5550
Connection ~ 8700 5550
Text Label 8150 4950 2    60   ~ 0
PH3
$Comp
L MOSFET_N Q?
U 1 1 54369907
P 7400 4950
F 0 "Q?" H 7350 5150 60  0000 R CNN
F 1 "IRL3803PbF" V 7650 5100 60  0000 R CNN
F 2 "TO-220AB" H 7400 4950 60  0001 C CNN
F 3 "" H 7400 4950 60  0000 C CNN
	1    7400 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 5150 7500 5650
Text Label 7500 5650 3    60   ~ 0
GND
$Comp
L R R?
U 1 1 54369910
P 7150 5250
F 0 "R?" V 7230 5250 40  0000 C CNN
F 1 "R" V 7157 5251 40  0000 C CNN
F 2 "" V 7080 5250 30  0000 C CNN
F 3 "" H 7150 5250 30  0000 C CNN
	1    7150 5250
	-1   0    0    1   
$EndComp
Wire Wire Line
	7150 5550 7150 5500
Wire Wire Line
	7150 5000 7150 4950
Wire Wire Line
	6950 4950 7200 4950
Connection ~ 7150 4950
Wire Wire Line
	7150 5550 7500 5550
Connection ~ 7500 5550
Text Label 6950 4950 2    60   ~ 0
PH2
$Comp
L MOSFET_N Q?
U 1 1 543699C5
P 6350 4950
F 0 "Q?" H 6300 5150 60  0000 R CNN
F 1 "IRL3803PbF" V 6600 5100 60  0000 R CNN
F 2 "TO-220AB" H 6350 4950 60  0001 C CNN
F 3 "" H 6350 4950 60  0000 C CNN
	1    6350 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 5150 6450 5650
Text Label 6450 5650 3    60   ~ 0
GND
$Comp
L R R?
U 1 1 543699CE
P 6100 5250
F 0 "R?" V 6180 5250 40  0000 C CNN
F 1 "R" V 6107 5251 40  0000 C CNN
F 2 "" V 6030 5250 30  0000 C CNN
F 3 "" H 6100 5250 30  0000 C CNN
	1    6100 5250
	-1   0    0    1   
$EndComp
Wire Wire Line
	6100 5550 6100 5500
Wire Wire Line
	6100 5000 6100 4950
Wire Wire Line
	5900 4950 6150 4950
Connection ~ 6100 4950
Wire Wire Line
	6100 5550 6450 5550
Connection ~ 6450 5550
Text Label 5900 4950 2    60   ~ 0
PH1
Wire Wire Line
	7500 4750 7500 4600
Wire Wire Line
	7500 4600 8500 4600
Wire Wire Line
	6450 4750 6450 4500
Wire Wire Line
	6450 4500 8300 4500
Wire Wire Line
	2150 2650 2950 2650
Wire Wire Line
	2150 2850 2950 2850
Text Label 2950 2650 0    60   ~ 0
T1
Text Label 2950 2850 0    60   ~ 0
T2
$Comp
L CONN_2 P?
U 1 1 5436A1D0
P 10050 5100
F 0 "P?" V 10000 5100 40  0000 C CNN
F 1 "CONN_2" V 10100 5100 40  0000 C CNN
F 2 "" H 10050 5100 60  0000 C CNN
F 3 "" H 10050 5100 60  0000 C CNN
	1    10050 5100
	1    0    0    -1  
$EndComp
$Comp
L CONN_2 P?
U 1 1 5436A263
P 10050 5600
F 0 "P?" V 10000 5600 40  0000 C CNN
F 1 "CONN_2" V 10100 5600 40  0000 C CNN
F 2 "" H 10050 5600 60  0000 C CNN
F 3 "" H 10050 5600 60  0000 C CNN
	1    10050 5600
	1    0    0    -1  
$EndComp
Text Notes 10300 5100 0    60   ~ 0
T1
Text Notes 10300 5600 0    60   ~ 0
T2
$EndSCHEMATC
