EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
Title "UI Board"
Date "2020-01-11"
Rev "0.3"
Comp "GZT project"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector1:XLR3_Ground J1
U 1 1 5E19DFCD
P 8000 1000
F 0 "J1" H 8000 1350 50  0000 C CNN
F 1 "XLR3_Ground" H 8000 1250 50  0000 C CNN
F 2 "Connector_Audio:Jack_XLR_Neutrik_NC3FAAH2_Horizontal" H 8000 1000 50  0001 C CNN
F 3 "" H 8000 1000 50  0001 C CNN
	1    8000 1000
	1    0    0    -1  
$EndComp
$Comp
L Connector1:XLR3_Ground J2
U 1 1 5E19DFD4
P 8000 2200
F 0 "J2" H 8000 2550 50  0000 C CNN
F 1 "XLR3_Ground" H 8000 2450 50  0000 C CNN
F 2 "Connector_Audio:Jack_XLR_Neutrik_NC3MAAH_Horizontal" H 8000 2200 50  0001 C CNN
F 3 "" H 8000 2200 50  0001 C CNN
	1    8000 2200
	1    0    0    1   
$EndComp
$Comp
L power1:GNDPWR #PWR030
U 1 1 5E19DFFB
P 7300 2300
F 0 "#PWR030" H 7300 2100 50  0001 C CNN
F 1 "GNDPWR" H 7300 2170 50  0000 C CNN
F 2 "" H 7300 2250 50  0001 C CNN
F 3 "" H 7300 2250 50  0001 C CNN
	1    7300 2300
	1    0    0    -1  
$EndComp
$Comp
L power1:GNDA #PWR031
U 1 1 5E19E008
P 7500 2300
F 0 "#PWR031" H 7500 2050 50  0001 C CNN
F 1 "GNDA" H 7500 2150 50  0000 C CNN
F 2 "" H 7500 2300 50  0001 C CNN
F 3 "" H 7500 2300 50  0001 C CNN
	1    7500 2300
	1    0    0    -1  
$EndComp
Entry Wire Line
	1050 2800 1150 2900
Entry Wire Line
	1050 2900 1150 3000
Entry Wire Line
	1050 3000 1150 3100
Entry Wire Line
	1050 3100 1150 3200
Entry Wire Line
	1050 3200 1150 3300
Entry Wire Line
	1050 3300 1150 3400
Entry Wire Line
	1050 3400 1150 3500
Entry Wire Line
	1050 3500 1150 3600
Text Label 1150 2900 0    60   ~ 0
Disp-A
Text Label 1150 3000 0    60   ~ 0
Disp-B
Text Label 1150 3100 0    60   ~ 0
Disp-C
Text Label 1150 3200 0    60   ~ 0
Disp-D
Text Label 1150 3300 0    60   ~ 0
Disp-E
Text Label 1150 3400 0    60   ~ 0
Disp-F
Text Label 1150 3500 0    60   ~ 0
Disp-G
Text Label 1150 3600 0    60   ~ 0
Disp-DP
Entry Wire Line
	1050 3650 1150 3750
Text Label 1150 3750 0    60   ~ 0
Disp-CA1
Entry Wire Line
	2150 2800 2250 2900
Entry Wire Line
	2150 2900 2250 3000
Entry Wire Line
	2150 3000 2250 3100
Entry Wire Line
	2150 3100 2250 3200
Entry Wire Line
	2150 3200 2250 3300
Entry Wire Line
	2150 3300 2250 3400
Entry Wire Line
	2150 3400 2250 3500
Entry Wire Line
	2150 3500 2250 3600
Text Label 2250 2900 0    60   ~ 0
Disp-A
Text Label 2250 3000 0    60   ~ 0
Disp-B
Text Label 2250 3100 0    60   ~ 0
Disp-C
Text Label 2250 3200 0    60   ~ 0
Disp-D
Text Label 2250 3300 0    60   ~ 0
Disp-E
Text Label 2250 3400 0    60   ~ 0
Disp-F
Text Label 2250 3500 0    60   ~ 0
Disp-G
Text Label 2250 3600 0    60   ~ 0
Disp-DP
Entry Wire Line
	2150 3650 2250 3750
Text Label 2250 3750 0    60   ~ 0
Disp-CA2
Entry Wire Line
	3250 2800 3350 2900
Entry Wire Line
	3250 2900 3350 3000
Entry Wire Line
	3250 3000 3350 3100
Entry Wire Line
	3250 3100 3350 3200
Entry Wire Line
	3250 3200 3350 3300
Entry Wire Line
	3250 3300 3350 3400
Entry Wire Line
	3250 3400 3350 3500
Entry Wire Line
	3250 3500 3350 3600
Text Label 3350 2900 0    60   ~ 0
Disp-A
Text Label 3350 3000 0    60   ~ 0
Disp-B
Text Label 3350 3100 0    60   ~ 0
Disp-C
Text Label 3350 3200 0    60   ~ 0
Disp-D
Text Label 3350 3300 0    60   ~ 0
Disp-E
Text Label 3350 3400 0    60   ~ 0
Disp-F
Text Label 3350 3500 0    60   ~ 0
Disp-G
Text Label 3350 3600 0    60   ~ 0
Disp-DP
Entry Wire Line
	3250 3650 3350 3750
Text Label 3350 3750 0    60   ~ 0
Disp-CA3
$Comp
L Device1:R_POT RV1
U 1 1 5E1A04B5
P 4700 3450
F 0 "RV1" V 4600 3450 50  0000 C CNN
F 1 "10k" V 4700 3450 50  0000 C CNN
F 2 "Potentiometer_THT:Potentiometer_Bourns_PTA6043_Single_Slide" H 4700 3450 50  0001 C CNN
F 3 "" H 4700 3450 50  0001 C CNN
	1    4700 3450
	-1   0    0    1   
$EndComp
$Comp
L power1:+5V #PWR032
U 1 1 5E1A04BC
P 5150 2800
F 0 "#PWR032" H 5150 2650 50  0001 C CNN
F 1 "+5V" H 5150 2940 50  0000 C CNN
F 2 "" H 5150 2800 50  0001 C CNN
F 3 "" H 5150 2800 50  0001 C CNN
	1    5150 2800
	1    0    0    -1  
$EndComp
$Comp
L power1:GND #PWR033
U 1 1 5E1A04C2
P 5650 3900
F 0 "#PWR033" H 5650 3650 50  0001 C CNN
F 1 "GND" H 5650 3750 50  0000 C CNN
F 2 "" H 5650 3900 50  0001 C CNN
F 3 "" H 5650 3900 50  0001 C CNN
	1    5650 3900
	1    0    0    -1  
$EndComp
$Comp
L Switch1:SW_Push SW1
U 1 1 5E1A04C8
P 5450 3700
F 0 "SW1" H 5500 3800 50  0000 L CNN
F 1 "SW_Push" H 5450 3640 50  0000 C CNN
F 2 "Buttons_Switches_THT:SW_PUSH_6mm_h7.3mm" H 5450 3900 50  0001 C CNN
F 3 "" H 5450 3900 50  0001 C CNN
	1    5450 3700
	-1   0    0    -1  
$EndComp
$Comp
L Switch1:SW_Push SW2
U 1 1 5E1A04CF
P 5450 3450
F 0 "SW2" H 5500 3550 50  0000 L CNN
F 1 "SW_Push" H 5450 3390 50  0000 C CNN
F 2 "Buttons_Switches_THT:SW_PUSH_6mm_h7.3mm" H 5450 3650 50  0001 C CNN
F 3 "" H 5450 3650 50  0001 C CNN
	1    5450 3450
	-1   0    0    -1  
$EndComp
$Comp
L Switch1:SW_Push SW3
U 1 1 5E1A04D6
P 5450 3200
F 0 "SW3" H 5500 3300 50  0000 L CNN
F 1 "SW_Push" H 5450 3140 50  0000 C CNN
F 2 "Buttons_Switches_THT:SW_PUSH_6mm_h7.3mm" H 5450 3400 50  0001 C CNN
F 3 "" H 5450 3400 50  0001 C CNN
	1    5450 3200
	-1   0    0    -1  
$EndComp
$Comp
L Device1:R R8
U 1 1 5E1A04DD
P 4950 3000
F 0 "R8" H 5000 3150 50  0000 C CNN
F 1 "15k" V 4950 3000 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 4880 3000 50  0001 C CNN
F 3 "" H 4950 3000 50  0001 C CNN
	1    4950 3000
	-1   0    0    1   
$EndComp
$Comp
L Device1:R R9
U 1 1 5E1A04E4
P 5050 3000
F 0 "R9" H 5100 3150 50  0000 C CNN
F 1 "15k" V 5050 3000 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 4980 3000 50  0001 C CNN
F 3 "" H 5050 3000 50  0001 C CNN
	1    5050 3000
	-1   0    0    1   
$EndComp
$Comp
L Device1:R R10
U 1 1 5E1A04EB
P 5150 3000
F 0 "R10" H 5200 3150 50  0000 C CNN
F 1 "15k" V 5150 3000 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5080 3000 50  0001 C CNN
F 3 "" H 5150 3000 50  0001 C CNN
	1    5150 3000
	-1   0    0    1   
$EndComp
Text HLabel 4050 6800 0    60   Input ~ 0
+5V
$Comp
L power1:+5V #PWR034
U 1 1 5E1A1AE8
P 4150 6750
F 0 "#PWR034" H 4150 6600 50  0001 C CNN
F 1 "+5V" H 4150 6890 50  0000 C CNN
F 2 "" H 4150 6750 50  0001 C CNN
F 3 "" H 4150 6750 50  0001 C CNN
	1    4150 6750
	-1   0    0    -1  
$EndComp
$Comp
L power1:GND #PWR035
U 1 1 5E1A1BC5
P 2550 7400
F 0 "#PWR035" H 2550 7150 50  0001 C CNN
F 1 "GND" H 2550 7250 50  0000 C CNN
F 2 "" H 2550 7400 50  0001 C CNN
F 3 "" H 2550 7400 50  0001 C CNN
	1    2550 7400
	-1   0    0    -1  
$EndComp
Text HLabel 2450 7350 0    60   Input ~ 0
GND
Text HLabel 3500 4550 0    60   Output ~ 0
Pot
Text HLabel 3550 4650 0    60   Output ~ 0
BTN3
Text HLabel 3600 4750 0    60   Output ~ 0
BTN2
Text HLabel 3700 4850 0    60   Output ~ 0
BTN1
Entry Wire Line
	1050 4300 1150 4400
Entry Wire Line
	1050 4400 1150 4500
Entry Wire Line
	1050 4500 1150 4600
Entry Wire Line
	1050 4600 1150 4700
Entry Wire Line
	1050 4700 1150 4800
Entry Wire Line
	1050 4800 1150 4900
Entry Wire Line
	1050 4900 1150 5000
Entry Wire Line
	1050 5000 1150 5100
Entry Wire Line
	1050 5100 1150 5200
Text HLabel 2250 4400 2    60   Input ~ 0
Disp-A
Text HLabel 2200 4500 2    60   Input ~ 0
Disp-B
Text HLabel 2150 4600 2    60   Input ~ 0
Disp-C
Text HLabel 2100 4700 2    60   Input ~ 0
Disp-D
Text HLabel 2050 4800 2    60   Input ~ 0
Disp-E
Text HLabel 2000 4900 2    60   Input ~ 0
Disp-F
Text HLabel 1950 5000 2    60   Input ~ 0
Disp-G
Text HLabel 1900 5100 2    60   Input ~ 0
Disp-DP
Text HLabel 2850 5200 2    60   Input ~ 0
Disp-CA1
Text HLabel 2900 5300 2    60   Input ~ 0
Disp-CA2
Text HLabel 2950 5400 2    60   Input ~ 0
Disp-CA3
Entry Wire Line
	1050 5200 1150 5300
Entry Wire Line
	1050 5300 1150 5400
Text HLabel 8550 1400 2    60   Output ~ 0
DMX+
Text HLabel 8550 1800 2    60   Output ~ 0
DMX-
Text HLabel 9150 1400 2    60   Input ~ 0
GNDA
$Comp
L power1:GNDA #PWR036
U 1 1 5E1AA05E
P 9100 1900
F 0 "#PWR036" H 9100 1650 50  0001 C CNN
F 1 "GNDA" H 9100 1750 50  0000 C CNN
F 2 "" H 9100 1900 50  0001 C CNN
F 3 "" H 9100 1900 50  0001 C CNN
	1    9100 1900
	1    0    0    -1  
$EndComp
Text HLabel 7950 3150 2    60   Input ~ 0
GNDPWR
$Comp
L power1:GNDPWR #PWR037
U 1 1 5E1AA1C7
P 7850 3250
F 0 "#PWR037" H 7850 3050 50  0001 C CNN
F 1 "GNDPWR" H 7850 3120 50  0000 C CNN
F 2 "" H 7850 3200 50  0001 C CNN
F 3 "" H 7850 3200 50  0001 C CNN
	1    7850 3250
	1    0    0    -1  
$EndComp
$Comp
L Connector1:Conn_01x03_Male J6
U 1 1 5E1BDAB2
P 9350 1650
F 0 "J6" H 9350 1850 50  0000 C CNN
F 1 "Conn_01x03_Male" H 9150 1450 50  0000 C CNN
F 2 "Connectors_Molex:Molex_PicoBlade_53047-0310_03x1.25mm_Straight" H 9350 1650 50  0001 C CNN
F 3 "" H 9350 1650 50  0001 C CNN
	1    9350 1650
	-1   0    0    -1  
$EndComp
$Comp
L Mechanical1:MountingHole_Pad H8
U 1 1 5E1BDAB9
P 7850 3050
F 0 "H8" H 7850 3300 50  0000 C CNN
F 1 "MountingHole_Pad" H 7850 3225 50  0000 C CNN
F 2 "MountingHole:MountingHole_4mm_Pad_Via" H 7850 3050 50  0001 C CNN
F 3 "" H 7850 3050 50  0001 C CNN
	1    7850 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	7700 1000 7700 1800
Wire Wire Line
	7900 1300 7900 1700
Wire Wire Line
	8000 1300 8000 1700
Wire Wire Line
	8300 2200 8300 1500
Wire Wire Line
	7500 2300 7500 1800
Wire Wire Line
	7500 1800 7700 1800
Connection ~ 7700 1800
Wire Wire Line
	7900 1700 7300 1700
Wire Wire Line
	7300 1700 7300 2300
Connection ~ 7900 1700
Wire Wire Line
	8300 1500 8500 1500
Connection ~ 8300 1500
Wire Wire Line
	8000 1700 8500 1700
Connection ~ 8000 1700
Wire Wire Line
	1150 2900 1500 2900
Wire Wire Line
	1150 3000 1500 3000
Wire Wire Line
	1150 3100 1500 3100
Wire Wire Line
	1150 3200 1500 3200
Wire Wire Line
	1150 3300 1500 3300
Wire Wire Line
	1150 3400 1500 3400
Wire Wire Line
	1150 3500 1500 3500
Wire Wire Line
	1150 3600 1500 3600
Wire Wire Line
	2100 3750 1150 3750
Wire Wire Line
	2250 2900 2600 2900
Wire Wire Line
	2250 3000 2600 3000
Wire Wire Line
	2250 3100 2600 3100
Wire Wire Line
	2250 3200 2600 3200
Wire Wire Line
	2250 3300 2600 3300
Wire Wire Line
	2250 3400 2600 3400
Wire Wire Line
	2250 3500 2600 3500
Wire Wire Line
	2250 3600 2600 3600
Wire Wire Line
	3200 3750 2250 3750
Wire Wire Line
	3350 2900 3700 2900
Wire Wire Line
	3350 3000 3700 3000
Wire Wire Line
	3350 3100 3700 3100
Wire Wire Line
	3350 3200 3700 3200
Wire Wire Line
	3350 3300 3700 3300
Wire Wire Line
	3350 3400 3700 3400
Wire Wire Line
	3350 3500 3700 3500
Wire Wire Line
	3350 3600 3700 3600
Wire Wire Line
	4300 3750 3350 3750
Wire Bus Line
	1050 3850 3250 3850
Wire Wire Line
	4700 2850 4700 3300
Wire Wire Line
	5650 3200 5650 3450
Connection ~ 5650 3450
Connection ~ 5650 3700
Wire Wire Line
	4700 3600 4700 3850
Wire Wire Line
	4700 3850 5650 3850
Connection ~ 5650 3850
Wire Wire Line
	3500 4550 4550 4550
Wire Wire Line
	4950 3200 5250 3200
Wire Wire Line
	3550 4650 4950 4650
Wire Wire Line
	5000 3450 5050 3450
Wire Wire Line
	3600 4750 5000 4750
Wire Wire Line
	5050 3700 5150 3700
Wire Wire Line
	3700 4850 5050 4850
Wire Wire Line
	4550 4550 4550 3450
Wire Wire Line
	4950 4650 4950 3200
Wire Wire Line
	5000 4750 5000 3450
Wire Wire Line
	5050 4850 5050 3700
Connection ~ 4950 3200
Wire Wire Line
	5050 3150 5050 3450
Connection ~ 5050 3450
Wire Wire Line
	5150 3150 5150 3700
Connection ~ 5150 3700
Wire Wire Line
	4700 2850 4950 2850
Connection ~ 4950 2850
Connection ~ 5050 2850
Wire Wire Line
	5150 2850 5150 2800
Wire Wire Line
	4150 6750 4150 6800
Wire Wire Line
	4150 6800 4050 6800
Wire Wire Line
	7950 3150 7850 3150
Wire Wire Line
	7850 3150 7850 3250
Wire Wire Line
	9050 1700 9050 1750
Wire Wire Line
	9050 1750 9150 1750
Wire Wire Line
	9050 1500 9050 1650
Wire Wire Line
	9050 1650 9150 1650
Wire Wire Line
	9100 1400 9100 1550
Wire Wire Line
	9100 1550 9150 1550
Wire Wire Line
	9100 1400 9150 1400
Connection ~ 9100 1550
Wire Wire Line
	8550 1400 8500 1400
Wire Wire Line
	8500 1400 8500 1500
Connection ~ 8500 1500
Wire Wire Line
	8550 1800 8500 1800
Wire Wire Line
	8500 1800 8500 1700
Connection ~ 8500 1700
Wire Wire Line
	1150 4400 2250 4400
Wire Wire Line
	2250 4400 2250 6200
Wire Wire Line
	2250 6200 2300 6200
Wire Wire Line
	1150 4500 2200 4500
Wire Wire Line
	1150 4600 2150 4600
Wire Wire Line
	2200 4500 2200 6300
Wire Wire Line
	2200 6300 2300 6300
Wire Wire Line
	2300 6400 2150 6400
Wire Wire Line
	2150 6400 2150 4600
Wire Wire Line
	1150 4700 2100 4700
Wire Wire Line
	2100 4700 2100 6500
Wire Wire Line
	2100 6500 2300 6500
Wire Wire Line
	1150 4800 2050 4800
Wire Wire Line
	2050 4800 2050 6600
Wire Wire Line
	2050 6600 2300 6600
Wire Wire Line
	1150 4900 2000 4900
Wire Wire Line
	2300 6700 2000 6700
Wire Wire Line
	2000 6700 2000 4900
Wire Wire Line
	1150 5000 1950 5000
Wire Wire Line
	2300 6800 1950 6800
Wire Wire Line
	1950 6800 1950 5000
Wire Wire Line
	1150 5100 1900 5100
Wire Wire Line
	1900 5100 1900 6900
Wire Wire Line
	1900 6900 2300 6900
Wire Wire Line
	1150 5200 2850 5200
Wire Wire Line
	2850 5200 2850 6200
Wire Wire Line
	2850 6200 2800 6200
Wire Wire Line
	1150 5300 2900 5300
Wire Wire Line
	2900 5300 2900 6300
Wire Wire Line
	2900 6300 2800 6300
Wire Wire Line
	1150 5400 2950 5400
Wire Wire Line
	2950 5400 2950 6400
Wire Wire Line
	2950 6400 2800 6400
Wire Wire Line
	2800 6500 3500 6500
Wire Wire Line
	3500 6500 3500 4550
Wire Wire Line
	2800 6600 3550 6600
Wire Wire Line
	3550 6600 3550 4650
Wire Wire Line
	3600 4750 3600 6700
Wire Wire Line
	3600 6700 2800 6700
Wire Wire Line
	2800 6800 3700 6800
Wire Wire Line
	3700 6800 3700 4850
$Comp
L Connector_Generic1:Conn_02x09_Odd_Even J5
U 1 1 5E1C0992
P 2500 6600
F 0 "J5" H 2550 7100 50  0000 C CNN
F 1 "Conn_02x09_Odd_Even" H 2550 6100 50  0000 C CNN
F 2 "connector_more:CONN-TE-MICROMATCH-9X2-PTH-BOSS" H 2500 6600 50  0001 C CNN
F 3 "" H 2500 6600 50  0001 C CNN
	1    2500 6600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 6900 2800 6900
Connection ~ 4150 6800
Wire Wire Line
	3100 7000 2800 7000
Wire Wire Line
	2300 7000 2100 7000
Wire Wire Line
	2100 7000 2100 7250
Wire Wire Line
	2100 7250 2550 7250
Wire Wire Line
	3100 7250 3100 7000
Connection ~ 2550 7250
Wire Wire Line
	7700 1800 7700 2200
Wire Wire Line
	7900 1700 7900 1900
Wire Wire Line
	8300 1500 8300 1000
Wire Wire Line
	8000 1700 8000 1900
Wire Wire Line
	5650 3450 5650 3700
Wire Wire Line
	5650 3700 5650 3850
Wire Wire Line
	5650 3850 5650 3900
Wire Wire Line
	4950 3200 4950 3150
Wire Wire Line
	5050 3450 5250 3450
Wire Wire Line
	5150 3700 5250 3700
Wire Wire Line
	4950 2850 5050 2850
Wire Wire Line
	5050 2850 5150 2850
Wire Wire Line
	9100 1550 9100 1900
Wire Wire Line
	8500 1500 9050 1500
Wire Wire Line
	8500 1700 9050 1700
Wire Wire Line
	4150 6800 4150 6900
Wire Wire Line
	2550 7250 3100 7250
Wire Wire Line
	2550 7250 2550 7400
Connection ~ 7850 3150
$Comp
L Mechanical1:MountingHole_Pad H7
U 1 1 5E31CC73
P 7650 3050
F 0 "H7" H 7650 3300 50  0000 C CNN
F 1 "MountingHole_Pad" H 7650 3225 50  0000 C CNN
F 2 "MountingHole:MountingHole_4mm_Pad_Via" H 7650 3050 50  0001 C CNN
F 3 "" H 7650 3050 50  0001 C CNN
	1    7650 3050
	1    0    0    -1  
$EndComp
$Comp
L Mechanical1:MountingHole_Pad H6
U 1 1 5E31D0C8
P 7450 3050
F 0 "H6" H 7450 3300 50  0000 C CNN
F 1 "MountingHole_Pad" H 7450 3225 50  0000 C CNN
F 2 "MountingHole:MountingHole_4mm_Pad_Via" H 7450 3050 50  0001 C CNN
F 3 "" H 7450 3050 50  0001 C CNN
	1    7450 3050
	1    0    0    -1  
$EndComp
$Comp
L Mechanical1:MountingHole_Pad H5
U 1 1 5E31D40D
P 7250 3050
F 0 "H5" H 7250 3300 50  0000 C CNN
F 1 "MountingHole_Pad" H 7250 3225 50  0000 C CNN
F 2 "MountingHole:MountingHole_4mm_Pad_Via" H 7250 3050 50  0001 C CNN
F 3 "" H 7250 3050 50  0001 C CNN
	1    7250 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 3150 7450 3150
Connection ~ 7450 3150
Wire Wire Line
	7450 3150 7650 3150
Connection ~ 7650 3150
Wire Wire Line
	7650 3150 7850 3150
$Comp
L Display_Character1:HDSP-5501 U5
U 1 1 5E23C7FD
P 1800 3200
F 0 "U5" H 1800 3867 50  0000 C CNN
F 1 "HDSP-5501" H 1800 3776 50  0000 C CNN
F 2 "Display_7Segment:7SegmentLED_LTS6760_LTS6780" H 1800 2650 50  0001 C CNN
F 3 "https://docs.broadcom.com/wcs-public/products/data-sheets--technical-specifications/data-sheet/474/1009/av02-1107en_ds_hdsp-k40x_2015-05-26.pdf" H 1800 3200 50  0001 C CNN
	1    1800 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 3600 2100 3750
$Comp
L Display_Character1:HDSP-5501 U6
U 1 1 5E23D22B
P 2900 3200
F 0 "U6" H 2900 3867 50  0000 C CNN
F 1 "HDSP-5501" H 2900 3776 50  0000 C CNN
F 2 "Display_7Segment:7SegmentLED_LTS6760_LTS6780" H 2900 2650 50  0001 C CNN
F 3 "https://docs.broadcom.com/wcs-public/products/data-sheets--technical-specifications/data-sheet/474/1009/av02-1107en_ds_hdsp-k40x_2015-05-26.pdf" H 2900 3200 50  0001 C CNN
	1    2900 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3200 3600 3200 3750
$Comp
L Display_Character1:HDSP-5501 U7
U 1 1 5E23D8FB
P 4000 3200
F 0 "U7" H 4000 3867 50  0000 C CNN
F 1 "HDSP-5501" H 4000 3776 50  0000 C CNN
F 2 "Display_7Segment:7SegmentLED_LTS6760_LTS6780" H 4000 2650 50  0001 C CNN
F 3 "https://docs.broadcom.com/wcs-public/products/data-sheets--technical-specifications/data-sheet/474/1009/av02-1107en_ds_hdsp-k40x_2015-05-26.pdf" H 4000 3200 50  0001 C CNN
	1    4000 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 3600 4300 3750
Wire Wire Line
	4300 3600 4300 3500
Connection ~ 4300 3600
Wire Wire Line
	3200 3600 3200 3500
Connection ~ 3200 3600
Wire Wire Line
	2100 3600 2100 3500
Connection ~ 2100 3600
Wire Bus Line
	2150 2800 2150 3850
Wire Bus Line
	3250 2800 3250 3850
Wire Bus Line
	1050 2800 1050 5300
$EndSCHEMATC
