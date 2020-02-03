#ifndef CONFIG_H
#define CONFIG_H

//Output pins:

#define TRIG_POS 1 //positive IGBT trigger output
#define TRIG_NEG 2 //Negative IGBT trigger output

//DMX pins:

#define DMX_IN 0 //DMX signal input pin

//UI input pins:

#define BTN1PIN A0 //Button 1
#define BTN2PIN A1 //Button 2
#define BTN3PIN A2 //Button 3
#define POTPIN A3  //Fader

//Display pins:

#define DISP_A 6   //Displays segment A
#define DISP_B 7   //Displays segment B
#define DISP_C 8   //Displays segment C
#define DISP_D 9   //Displays segment D
#define DISP_E 10  //Displays segment E
#define DISP_F 11  //Displays segment F
#define DISP_G 12  //Displays segment G
#define DISP_DP 13 //Displays decimal point

#define DISP_CA1 3 //Display 1 common anode
#define DISP_CA2 4 //Display 2 common anode
#define DISP_CA3 5 //Display 3 common anode

//EEPROM:

#define EEPROM_ADDRESS 0

//Misc

#define MENU_SHOW_TIME 1000
#define MENU_TIMEOUT 20000


#endif