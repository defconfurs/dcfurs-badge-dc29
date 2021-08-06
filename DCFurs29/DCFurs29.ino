#include "Arduino_is31fl3737.h"

Arduino_is31fl3737 disp(0xA0);

int dropletiterator = 0;
int rainiterator = 0;
int starsiterator = 0;
int raincounter = 0;


const int dropletinten = 60;
const int raininten = 60;
const int starsinten = 5;


const int dropletlimit = 256;
const int rainlimit = 128;
const int starslimit = 1024;
const int raintrigger = 0;


void SetLEDRGB( uint8_t LED, uint8_t Red, uint8_t Green, uint8_t Blue )
{
  disp.SetLEDPWM( (LED - 1) % 12, ((LED - 1) / 12) * 3 , Blue);
  disp.SetLEDPWM( (LED - 1) % 12, ((LED - 1) / 12) * 3 + 1, Green);
  disp.SetLEDPWM( (LED - 1) % 12, ((LED - 1) / 12) * 3 + 2, Red);
}



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
    disp.SetLEDPWM(IS31FL3737_CS, IS31FL3737_SW, 0);
    Serial.println("SetLEDState...");
    delay( 100 );
    disp.SetLEDState(IS31FL3737_CS, IS31FL3737_SW, IS31FL3737_LED_STATE_ON);
    SetLEDRGB( 3, 0, 0, 45 );
    SetLEDRGB( 4, 0, 0, 45 );
    SetLEDRGB( 7, 22, 22, 22 );
    SetLEDRGB( 8, 22, 22, 22 );
    SetLEDRGB( 9, 22, 22, 22 );
    SetLEDRGB( 10, 22, 22, 22 );
    SetLEDRGB( 11, 22, 22, 22 );
    SetLEDRGB( 12, 22, 22, 22 );
    SetLEDRGB( 5, 22, 12, 12 );
}

void loop() 
{

    if ( dropletiterator >= dropletlimit ) { dropletiterator = 0; };
    if ( rainiterator >= rainlimit ) { rainiterator = 0; };
    if ( starsiterator >= starslimit ) { starsiterator = 0; };


    switch ( starsiterator / ( starslimit / 4 ) ) {
      case 0:
        SetLEDRGB( 1, ((float)starsiterator / ( starslimit / 4 )) * starsinten, ((float)starsiterator / ( starslimit / 4 )) * starsinten, ((float)starsiterator / ( starslimit / 4 )) * starsinten );
        SetLEDRGB( 13, ((float)starsiterator / ( starslimit / 4 )) * starsinten, ((float)starsiterator / ( starslimit / 4 )) * starsinten, ((float)starsiterator / ( starslimit / 4 )) * starsinten );
        SetLEDRGB( 22, ((float)starsiterator / ( starslimit / 4 )) * starsinten, ((float)starsiterator / ( starslimit / 4 )) * starsinten, ((float)starsiterator / ( starslimit / 4 )) * starsinten );
        SetLEDRGB( 23, ((float)starsiterator / ( starslimit / 4 )) * starsinten, ((float)starsiterator / ( starslimit / 4 )) * starsinten, ((float)starsiterator / ( starslimit / 4 )) * starsinten );
        SetLEDRGB( 24, ((float)starsiterator / ( starslimit / 4 )) * starsinten, ((float)starsiterator / ( starslimit / 4 )) * starsinten, ((float)starsiterator / ( starslimit / 4 )) * starsinten );
//        Serial.println( ((float)starsiterator / ( starslimit / 4 )) * starsinten  );
        break;
      case 1:
        SetLEDRGB( 1, starsinten, starsinten, starsinten );
        SetLEDRGB( 13, starsinten, starsinten, starsinten );
        SetLEDRGB( 22, starsinten, starsinten, starsinten );
        SetLEDRGB( 23, starsinten, starsinten, starsinten );
        SetLEDRGB( 24, starsinten, starsinten, starsinten );
//        Serial.println( starsinten );
        break;
      case 2:
        SetLEDRGB( 1, ( starsinten - ((float)(starsiterator % ( starslimit / 4 )) / ( starslimit / 4 )) * starsinten), ( starsinten - ((float)(starsiterator % ( starslimit / 4 )) / ( starslimit / 4 )) * starsinten), ( starsinten - ((float)(starsiterator % ( starslimit / 4 )) / ( starslimit / 4 )) * starsinten) );
        SetLEDRGB( 13, ( starsinten - ((float)(starsiterator % ( starslimit / 4 )) / ( starslimit / 4 )) * starsinten), ( starsinten - ((float)(starsiterator % ( starslimit / 4 )) / ( starslimit / 4 )) * starsinten), ( starsinten - ((float)(starsiterator % ( starslimit / 4 )) / ( starslimit / 4 )) * starsinten) );
        SetLEDRGB( 22, ( starsinten - ((float)(starsiterator % ( starslimit / 4 )) / ( starslimit / 4 )) * starsinten), ( starsinten - ((float)(starsiterator % ( starslimit / 4 )) / ( starslimit / 4 )) * starsinten), ( starsinten - ((float)(starsiterator % ( starslimit / 4 )) / ( starslimit / 4 )) * starsinten) );
        SetLEDRGB( 23, ( starsinten - ((float)(starsiterator % ( starslimit / 4 )) / ( starslimit / 4 )) * starsinten), ( starsinten - ((float)(starsiterator % ( starslimit / 4 )) / ( starslimit / 4 )) * starsinten), ( starsinten - ((float)(starsiterator % ( starslimit / 4 )) / ( starslimit / 4 )) * starsinten) );
        SetLEDRGB( 24, ( starsinten - ((float)(starsiterator % ( starslimit / 4 )) / ( starslimit / 4 )) * starsinten), ( starsinten - ((float)(starsiterator % ( starslimit / 4 )) / ( starslimit / 4 )) * starsinten), ( starsinten - ((float)(starsiterator % ( starslimit / 4 )) / ( starslimit / 4 )) * starsinten) );
        
//        Serial.println( ( starsinten - ((float)(starsiterator % ( starslimit / 4 )) / ( starslimit / 4 )) * starsinten) );
        break;
      case 3:
        SetLEDRGB( 1, 0, 0, 0 );
        SetLEDRGB( 13, 0, 0, 0 );
        SetLEDRGB( 22, 0, 0, 0 );
        SetLEDRGB( 23, 0, 0, 0 );
        SetLEDRGB( 24, 0, 0, 0 );
//        Serial.println( 0 );
        break;
    }




    switch ( dropletiterator / ( dropletlimit / 4 ) ) {
      case 0:
        SetLEDRGB( 6, 0, 0, ((float)dropletiterator / ( dropletlimit / 4 )) * dropletinten );
//        Serial.println( ((float)dropletiterator / ( dropletlimit / 4 )) * dropletinten  );
        break;
      case 1:
        SetLEDRGB( 6, 0, 0, dropletinten );
//        Serial.println( dropletinten );
        break;
      case 2:
        SetLEDRGB( 6, 0, 0, ( dropletinten - ((float)(dropletiterator % ( dropletlimit / 4 )) / ( dropletlimit / 4 )) * dropletinten) );
//        Serial.println( ( dropletinten - ((float)(dropletiterator % ( dropletlimit / 4 )) / ( dropletlimit / 4 )) * dropletinten) );
        break;
      case 3:
        SetLEDRGB( 6, 0, 0, 0 );
//        Serial.println( 0 );
        break;
    }
        switch ( rainiterator / ( rainlimit / 16 ) ) {
      case 0:
        SetLEDRGB( 26, 0, 0, ((float)rainiterator / ( rainlimit / 16 )) * raininten );
        SetLEDRGB( 32, 0, 0, ((float)rainiterator / ( rainlimit / 16 )) * raininten );
        SetLEDRGB( 35, 0, 0, ((float)rainiterator / ( rainlimit / 16 )) * raininten );
        SetLEDRGB( 39, 0, 0, ((float)rainiterator / ( rainlimit / 16 )) * raininten );
        SetLEDRGB( 44, 0, 0, ((float)rainiterator / ( rainlimit / 16 )) * raininten );
        SetLEDRGB( 48, 0, 0, ((float)rainiterator / ( rainlimit / 16 )) * raininten );
//        Serial.println( ((float)rainiterator / ( rainlimit / 16)) * raininten  );
        break;
      case 1:
        SetLEDRGB( 26, 0, 0, raininten );
        SetLEDRGB( 32, 0, 0, raininten );
        SetLEDRGB( 35, 0, 0, raininten );
        SetLEDRGB( 39, 0, 0, raininten );
        SetLEDRGB( 44, 0, 0, raininten );
        SetLEDRGB( 48, 0, 0, raininten );
//        Serial.println( raininten );
        break;
      case 2:
        SetLEDRGB( 26, 0, 0, ( raininten - ((float)(rainiterator % ( rainlimit / 16 )) / ( rainlimit / 16 )) * raininten) );
        SetLEDRGB( 32, 0, 0, ( raininten - ((float)(rainiterator % ( rainlimit / 16 )) / ( rainlimit / 16 )) * raininten) );
        SetLEDRGB( 35, 0, 0, ( raininten - ((float)(rainiterator % ( rainlimit / 16 )) / ( rainlimit / 16 )) * raininten) );
        SetLEDRGB( 39, 0, 0, ( raininten - ((float)(rainiterator % ( rainlimit / 16 )) / ( rainlimit / 16 )) * raininten) );
        SetLEDRGB( 44, 0, 0, ( raininten - ((float)(rainiterator % ( rainlimit / 16 )) / ( rainlimit / 16 )) * raininten) );
        SetLEDRGB( 48, 0, 0, ( raininten - ((float)(rainiterator % ( rainlimit / 16 )) / ( rainlimit / 16 )) * raininten) );
//        Serial.println( ( raininten - ((float)(rainiterator % ( rainlimit / 16 )) / ( rainlimit / 16 )) * raininten) );
        break;
      case 3:
        SetLEDRGB( 26, 0, 0, 0 );
        SetLEDRGB( 32, 0, 0, 0 );
        SetLEDRGB( 35, 0, 0, 0 );
        SetLEDRGB( 39, 0, 0, 0 );
        SetLEDRGB( 44, 0, 0, 0 );
        SetLEDRGB( 48, 0, 0, 0 );
//        Serial.println( 0 );
        break;
      case 4:
        SetLEDRGB( 28, 0, 0, ((float)( rainiterator % 16) / ( rainlimit / 16 )) * raininten );
        SetLEDRGB( 30, 0, 0, ((float)( rainiterator % 16) / ( rainlimit / 16 )) * raininten );
        SetLEDRGB( 33, 0, 0, ((float)( rainiterator % 16) / ( rainlimit / 16 )) * raininten );
        SetLEDRGB( 38, 0, 0, ((float)( rainiterator % 16) / ( rainlimit / 16 )) * raininten );
        SetLEDRGB( 42, 0, 0, ((float)( rainiterator % 16) / ( rainlimit / 16 )) * raininten );
        SetLEDRGB( 47, 0, 0, ((float)( rainiterator % 16) / ( rainlimit / 16 )) * raininten );
//        Serial.println( ((float)rainiterator / ( rainlimit / 16)) * raininten  );
        break;
      case 5:
        SetLEDRGB( 28, 0, 0, raininten );
        SetLEDRGB( 30, 0, 0, raininten );
        SetLEDRGB( 33, 0, 0, raininten );
        SetLEDRGB( 38, 0, 0, raininten );
        SetLEDRGB( 42, 0, 0, raininten );
        SetLEDRGB( 47, 0, 0, raininten );
//        Serial.println( raininten );
        break;
      case 6:
        SetLEDRGB( 28, 0, 0, ( raininten - ((float)(rainiterator % ( rainlimit / 16 )) / ( rainlimit / 16 )) * raininten) );
        SetLEDRGB( 30, 0, 0, ( raininten - ((float)(rainiterator % ( rainlimit / 16 )) / ( rainlimit / 16 )) * raininten) );
        SetLEDRGB( 33, 0, 0, ( raininten - ((float)(rainiterator % ( rainlimit / 16 )) / ( rainlimit / 16 )) * raininten) );
        SetLEDRGB( 38, 0, 0, ( raininten - ((float)(rainiterator % ( rainlimit / 16 )) / ( rainlimit / 16 )) * raininten) );
        SetLEDRGB( 42, 0, 0, ( raininten - ((float)(rainiterator % ( rainlimit / 16 )) / ( rainlimit / 16 )) * raininten) );
        SetLEDRGB( 47, 0, 0, ( raininten - ((float)(rainiterator % ( rainlimit / 16 )) / ( rainlimit / 16 )) * raininten) );
//        Serial.println( ( raininten - ((float)(rainiterator % ( rainlimit / 16 )) / ( rainlimit / 16 )) * raininten) );
        break;
      case 7:
        SetLEDRGB( 28, 0, 0, 0 );
        SetLEDRGB( 30, 0, 0, 0 );
        SetLEDRGB( 33, 0, 0, 0 );
        SetLEDRGB( 38, 0, 0, 0 );
        SetLEDRGB( 42, 0, 0, 0 );
        SetLEDRGB( 47, 0, 0, 0 );
//        Serial.println( 0 );
        break;
      case 8:
        SetLEDRGB( 25, 0, 0, ((float)( rainiterator % 16) / ( rainlimit / 16 )) * raininten );
        SetLEDRGB( 27, 0, 0, ((float)( rainiterator % 16) / ( rainlimit / 16 )) * raininten );
        SetLEDRGB( 34, 0, 0, ((float)( rainiterator % 16) / ( rainlimit / 16 )) * raininten );
        SetLEDRGB( 37, 0, 0, ((float)( rainiterator % 16) / ( rainlimit / 16 )) * raininten );
        SetLEDRGB( 40, 0, 0, ((float)( rainiterator % 16) / ( rainlimit / 16 )) * raininten );
        SetLEDRGB( 45, 0, 0, ((float)( rainiterator % 16) / ( rainlimit / 16 )) * raininten );
//        Serial.println( ((float)rainiterator / ( rainlimit / 16)) * raininten  );
        break;
      case 9:
        SetLEDRGB( 25, 0, 0, raininten );
        SetLEDRGB( 27, 0, 0, raininten );
        SetLEDRGB( 34, 0, 0, raininten );
        SetLEDRGB( 37, 0, 0, raininten );
        SetLEDRGB( 40, 0, 0, raininten );
        SetLEDRGB( 45, 0, 0, raininten );
//        Serial.println( raininten );
        break;
      case 10:
        SetLEDRGB( 25, 0, 0, ( raininten - ((float)(rainiterator % ( rainlimit / 16 )) / ( rainlimit / 16 )) * raininten) );
        SetLEDRGB( 27, 0, 0, ( raininten - ((float)(rainiterator % ( rainlimit / 16 )) / ( rainlimit / 16 )) * raininten) );
        SetLEDRGB( 34, 0, 0, ( raininten - ((float)(rainiterator % ( rainlimit / 16 )) / ( rainlimit / 16 )) * raininten) );
        SetLEDRGB( 37, 0, 0, ( raininten - ((float)(rainiterator % ( rainlimit / 16 )) / ( rainlimit / 16 )) * raininten) );
        SetLEDRGB( 40, 0, 0, ( raininten - ((float)(rainiterator % ( rainlimit / 16 )) / ( rainlimit / 16 )) * raininten) );
        SetLEDRGB( 45, 0, 0, ( raininten - ((float)(rainiterator % ( rainlimit / 16 )) / ( rainlimit / 16 )) * raininten) );
//        Serial.println( ( raininten - ((float)(rainiterator % ( rainlimit / 16 )) / ( rainlimit / 16 )) * raininten) );
        break;
      case 11:
        SetLEDRGB( 25, 0, 0, 0 );
        SetLEDRGB( 27, 0, 0, 0 );
        SetLEDRGB( 34, 0, 0, 0 );
        SetLEDRGB( 37, 0, 0, 0 );
        SetLEDRGB( 40, 0, 0, 0 );
        SetLEDRGB( 45, 0, 0, 0 );
//        Serial.println( 0 );
        break;
      case 12:
        SetLEDRGB( 29, 0, 0, ((float)( rainiterator % 16) / ( rainlimit / 16 )) * raininten );
        SetLEDRGB( 31, 0, 0, ((float)( rainiterator % 16) / ( rainlimit / 16 )) * raininten );
        SetLEDRGB( 36, 0, 0, ((float)( rainiterator % 16) / ( rainlimit / 16 )) * raininten );
        SetLEDRGB( 41, 0, 0, ((float)( rainiterator % 16) / ( rainlimit / 16 )) * raininten );
        SetLEDRGB( 43, 0, 0, ((float)( rainiterator % 16) / ( rainlimit / 16 )) * raininten );
        SetLEDRGB( 46, 0, 0, ((float)( rainiterator % 16) / ( rainlimit / 16 )) * raininten );
//        Serial.println( ((float)rainiterator / ( rainlimit / 16)) * raininten  );
        break;
      case 13:
        SetLEDRGB( 29, 0, 0, raininten );
        SetLEDRGB( 31, 0, 0, raininten );
        SetLEDRGB( 36, 0, 0, raininten );
        SetLEDRGB( 41, 0, 0, raininten );
        SetLEDRGB( 43, 0, 0, raininten );
        SetLEDRGB( 46, 0, 0, raininten );
//        Serial.println( raininten );
        break;
      case 14:
        SetLEDRGB( 29, 0, 0, ( raininten - ((float)(rainiterator % ( rainlimit / 16 )) / ( rainlimit / 16 )) * raininten) );
        SetLEDRGB( 31, 0, 0, ( raininten - ((float)(rainiterator % ( rainlimit / 16 )) / ( rainlimit / 16 )) * raininten) );
        SetLEDRGB( 36, 0, 0, ( raininten - ((float)(rainiterator % ( rainlimit / 16 )) / ( rainlimit / 16 )) * raininten) );
        SetLEDRGB( 41, 0, 0, ( raininten - ((float)(rainiterator % ( rainlimit / 16 )) / ( rainlimit / 16 )) * raininten) );
        SetLEDRGB( 43, 0, 0, ( raininten - ((float)(rainiterator % ( rainlimit / 16 )) / ( rainlimit / 16 )) * raininten) );
        SetLEDRGB( 46, 0, 0, ( raininten - ((float)(rainiterator % ( rainlimit / 16 )) / ( rainlimit / 16 )) * raininten) );
//        Serial.println( ( raininten - ((float)(rainiterator % ( rainlimit / 16 )) / ( rainlimit / 16 )) * raininten) );
        break;
      case 15:
        SetLEDRGB( 29, 0, 0, 0 );
        SetLEDRGB( 31, 0, 0, 0 );
        SetLEDRGB( 36, 0, 0, 0 );
        SetLEDRGB( 41, 0, 0, 0 );
        SetLEDRGB( 43, 0, 0, 0 );
        SetLEDRGB( 46, 0, 0, 0 );
//        Serial.println( 0 );
        break;
    }












    

    delay(100);

    dropletiterator++;
    rainiterator++;
    starsiterator++;
 //   raincounter++;
}
