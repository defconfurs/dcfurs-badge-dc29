#include "Arduino_is31fl3737.h"

Arduino_is31fl3737 disp(0xA0);

void setup() 
{
    pinMode( A2, OUTPUT );
    digitalWrite( A2, HIGH );
    Serial.begin(9600);  // start Serial for output
    Serial.println("Starting...");
    delay( 100 );
    Serial.println("ISSI Init...");
    delay( 100 );
    disp.Init();
    Serial.println("SetGCC...");
    delay( 100 );
    disp.SetGCC(0x7F);
    Serial.println("SetLEDPWM...");
    delay( 100 );
    for(uint8_t i_cs = 0; i_cs<12; i_cs++){
        for(uint8_t i_sw = 0; i_sw<12; i_sw++){
            disp.SetLEDPWM(i_cs, i_sw, 127);
        }
    } 
//    disp.SetLEDPWM(IS31FL3737_CS, IS31FL3737_SW, 127);
}

void loop() 
{
    for(uint8_t i_cs = 0; i_cs<12; i_cs++){
        for(uint8_t i_sw = 0; i_sw<12; i_sw++){
            disp.SetLEDState(i_cs, i_sw, IS31FL3737_LED_STATE_ON);
        }
    }
    delay(500);
    for(uint8_t i_cs = 0; i_cs<12; i_cs++){
        for(uint8_t i_sw = 0; i_sw<12; i_sw++){
            disp.SetLEDState(i_cs, i_sw, IS31FL3737_LED_STATE_OFF);
        }
    }
    delay(500);
}
