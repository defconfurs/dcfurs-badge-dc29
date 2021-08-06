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
    disp.SetLEDPWM(IS31FL3737_CS, IS31FL3737_SW, 127);
    Serial.println("SetLEDState...");
    delay( 100 );
    disp.SetLEDState(IS31FL3737_CS, IS31FL3737_SW, IS31FL3737_LED_STATE_ON);
}

void loop() 
{
    //  //waiting for input
    for (uint8_t i_sw = 11; i_sw<12; i_sw--){
        for (uint8_t i_cs = 0; i_cs<12; i_cs++){
            Serial.print(disp.GetLEDStatus(i_cs, i_sw));
        }
        Serial.println("");
    }
    Serial.println("################");
    delay(3000);
}
