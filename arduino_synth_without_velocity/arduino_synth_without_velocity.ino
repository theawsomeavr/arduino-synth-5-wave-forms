#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();


const int freq[128] =
{
  16, 17, 18, 19, 21, 22, 23, 24, 26, 28, 29, 31, 33, 35, 37, 39, 41,
  44, 46, 49, 52, 55, 58, 62, 65, 69, 73, 78, 82, 87, 92, 98, 104, 110,
  117, 123, 131, 139, 147, 156, 165, 175, 185, 196, 208, 220, 233,
  247, 262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494,
  523, 554, 587, 622, 659, 698, 740, 784, 831, 880, 932, 988, 1047,
  1109, 1175, 1245, 1319, 1397, 1480, 1568, 1661, 1760, 1865, 1976,
  2093, 2217, 2349, 2489, 2637, 2794, 2960, 3136, 3322, 3520, 3729,
  3951, 4186, 4435, 4699, 4978, 5274, 5588, 5920, 6272, 6645, 7040,
  7459, 7902, 8372, 8870, 9397, 9956, 10548, 11175, 11840, 12544,
  13290, 14080, 14917, 15804, 16744, 17740, 18795, 19912, 21096,
  22351, 23680, 25088
};
char wave256 [256]  __attribute__ ((aligned(256)))={
  0 , 3 , 6 , 9 , 12 , 15 , 18 , 21 , 24 , 27 , 30 , 33 , 36 , 39 , 42 , 45 , 
48 , 51 , 54 , 57 , 59 , 62 , 65 , 67 , 70 , 73 , 75 , 78 , 80 , 82 , 85 , 87 , 
89 , 91 , 94 , 96 , 98 , 100 , 102 , 103 , 105 , 107 , 108 , 110 , 112 , 113 , 114 , 116 , 
117 , 118 , 119 , 120 , 121 , 122 , 123 , 123 , 124 , 125 , 125 , 126 , 126 , 126 , 126 , 126 , 
127 , 126 , 126 , 126 , 126 , 126 , 125 , 125 , 124 , 123 , 123 , 122 , 121 , 120 , 119 , 118 , 
117 , 116 , 114 , 113 , 112 , 110 , 108 , 107 , 105 , 103 , 102 , 100 , 98 , 96 , 94 , 91 , 
89 , 87 , 85 , 82 , 80 , 78 , 75 , 73 , 70 , 67 , 65 , 62 , 59 , 57 , 54 , 51 , 
48 , 45 , 42 , 39 , 36 , 33 , 30 , 27 , 24 , 21 , 18 , 15 , 12 , 9 , 6 , 3 , 
0 , -3 , -6 , -9 , -12 , -15 , -18 , -21 , -24 , -27 , -30 , -33 , -36 , -39 , -42 , -45 , 
-48 , -51 , -54 , -57 , -59 , -62 , -65 , -67 , -70 , -73 , -75 , -78 , -80 , -82 , -85 , -87 , 
-89 , -91 , -94 , -96 , -98 , -100 , -102 , -103 , -105 , -107 , -108 , -110 , -112 , -113 , -114 , -116 , 
-117 , -118 , -119 , -120 , -121 , -122 , -123 , -123 , -124 , -125 , -125 , -126 , -126 , -126 , -126 , -126 , 
-127 , -126 , -126 , -126 , -126 , -126 , -125 , -125 , -124 , -123 , -123 , -122 , -121 , -120 , -119 , -118 , 
-117 , -116 , -114 , -113 , -112 , -110 , -108 , -107 , -105 , -103 , -102 , -100 , -98 , -96 , -94 , -91 , 
-89 , -87 , -85 , -82 , -80 , -78 , -75 , -73 , -70 , -67 , -65 , -62 , -59 , -57 , -54 , -51 , 
-48 , -45 , -42 , -39 , -36 , -33 , -30 , -27 , -24 , -21 , -18 , -15 , -12 , -9 , -6 , -3 

};
const PROGMEM char sine256[256] = {
0 , 3 , 6 , 9 , 12 , 15 , 18 , 21 , 24 , 27 , 30 , 33 , 36 , 39 , 42 , 45 , 
48 , 51 , 54 , 57 , 59 , 62 , 65 , 67 , 70 , 73 , 75 , 78 , 80 , 82 , 85 , 87 , 
89 , 91 , 94 , 96 , 98 , 100 , 102 , 103 , 105 , 107 , 108 , 110 , 112 , 113 , 114 , 116 , 
117 , 118 , 119 , 120 , 121 , 122 , 123 , 123 , 124 , 125 , 125 , 126 , 126 , 126 , 126 , 126 , 
127 , 126 , 126 , 126 , 126 , 126 , 125 , 125 , 124 , 123 , 123 , 122 , 121 , 120 , 119 , 118 , 
117 , 116 , 114 , 113 , 112 , 110 , 108 , 107 , 105 , 103 , 102 , 100 , 98 , 96 , 94 , 91 , 
89 , 87 , 85 , 82 , 80 , 78 , 75 , 73 , 70 , 67 , 65 , 62 , 59 , 57 , 54 , 51 , 
48 , 45 , 42 , 39 , 36 , 33 , 30 , 27 , 24 , 21 , 18 , 15 , 12 , 9 , 6 , 3 , 
0 , -3 , -6 , -9 , -12 , -15 , -18 , -21 , -24 , -27 , -30 , -33 , -36 , -39 , -42 , -45 , 
-48 , -51 , -54 , -57 , -59 , -62 , -65 , -67 , -70 , -73 , -75 , -78 , -80 , -82 , -85 , -87 , 
-89 , -91 , -94 , -96 , -98 , -100 , -102 , -103 , -105 , -107 , -108 , -110 , -112 , -113 , -114 , -116 , 
-117 , -118 , -119 , -120 , -121 , -122 , -123 , -123 , -124 , -125 , -125 , -126 , -126 , -126 , -126 , -126 , 
-127 , -126 , -126 , -126 , -126 , -126 , -125 , -125 , -124 , -123 , -123 , -122 , -121 , -120 , -119 , -118 , 
-117 , -116 , -114 , -113 , -112 , -110 , -108 , -107 , -105 , -103 , -102 , -100 , -98 , -96 , -94 , -91 , 
-89 , -87 , -85 , -82 , -80 , -78 , -75 , -73 , -70 , -67 , -65 , -62 , -59 , -57 , -54 , -51 , 
-48 , -45 , -42 , -39 , -36 , -33 , -30 , -27 , -24 , -21 , -18 , -15 , -12 , -9 , -6 , -3 
  };
 const PROGMEM char square256[256]/*  __attribute__ ((aligned(256)))*/ = {
127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 
127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 
127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 
127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 
127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 
127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 
127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 
127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 
-127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , 
-127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , 
-127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , 
-127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , 
-127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , 
-127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , 
-127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , 
-127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 , -127 
  };
   const PROGMEM char tri256[256]/*  __attribute__ ((aligned(256)))*/ = {
 0x00, 0x02, 0x04, 0x06, 0x08, 0x0a, 0x0c, 0x0e,  0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 
    0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e,  0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 
    0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e,  0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 
    0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e,  0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 
    0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c, 0x8e,  0x90, 0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 0x9e, 
    0xa0, 0xa2, 0xa4, 0xa6, 0xa8, 0xaa, 0xac, 0xae,  0xb0, 0xb2, 0xb4, 0xb6, 0xb8, 0xba, 0xbc, 0xbe, 
    0xc0, 0xc2, 0xc4, 0xc6, 0xc8, 0xca, 0xcc, 0xce,  0xd0, 0xd2, 0xd4, 0xd6, 0xd8, 0xda, 0xdc, 0xde, 
    0xe0, 0xe2, 0xe4, 0xe6, 0xe8, 0xea, 0xec, 0xee,  0xf0, 0xf2, 0xf4, 0xf6, 0xf8, 0xfa, 0xfc, 0xfe, 

    0xff, 0xfd, 0xfb, 0xf9, 0xf7, 0xf5, 0xf3, 0xf1,  0xef, 0xed, 0xeb, 0xe9, 0xe7, 0xe5, 0xe3, 0xe1,  
    0xdf, 0xdd, 0xdb, 0xd9, 0xd7, 0xd5, 0xd3, 0xd1,  0xcf, 0xcd, 0xcb, 0xc9, 0xc7, 0xc5, 0xc3, 0xc1,  
    0xbf, 0xbd, 0xbb, 0xb9, 0xb7, 0xb5, 0xb3, 0xb1,  0xaf, 0xad, 0xab, 0xa9, 0xa7, 0xa5, 0xa3, 0xa1,  
    0x9f, 0x9d, 0x9b, 0x99, 0x97, 0x95, 0x93, 0x91,  0x8f, 0x8d, 0x8b, 0x89, 0x87, 0x85, 0x83, 0x81,  
    0x7f, 0x7d, 0x7b, 0x79, 0x77, 0x75, 0x73, 0x71,  0x6f, 0x6d, 0x6b, 0x69, 0x67, 0x65, 0x63, 0x61,  
    0x5f, 0x5d, 0x5b, 0x59, 0x57, 0x55, 0x53, 0x51,  0x4f, 0x4d, 0x4b, 0x49, 0x47, 0x45, 0x43, 0x41,  
    0x3f, 0x3d, 0x3b, 0x39, 0x37, 0x35, 0x33, 0x31,  0x2f, 0x2d, 0x2b, 0x29, 0x27, 0x25, 0x23, 0x21,  
    0x1f, 0x1d, 0x1b, 0x19, 0x17, 0x15, 0x13, 0x11,  0x0f, 0x0d, 0x0b, 0x09, 0x07, 0x05, 0x03, 0x01
  };
     const PROGMEM char sawup256[256]/*  __attribute__ ((aligned(256)))*/ = {
0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
    0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
    0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
    0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f,
    0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f,
    0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f,
    0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7a, 0x7b, 0x7c, 0x7d, 0x7e, 0x7f,
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
    0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f,
    0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf,
    0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf,
    0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf,
    0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf,
    0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef,
    0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff
  };
     const PROGMEM char special256[256]/*  __attribute__ ((aligned(256)))*/ = {
127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 
127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 
127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 
127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 
127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 
127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 
127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 
127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 , 127 ,
    0x7f, 0x7d, 0x7b, 0x79, 0x77, 0x75, 0x73, 0x71,  0x6f, 0x6d, 0x6b, 0x69, 0x67, 0x65, 0x63, 0x61,  
    0x5f, 0x5d, 0x5b, 0x59, 0x57, 0x55, 0x53, 0x51,  0x4f, 0x4d, 0x4b, 0x49, 0x47, 0x45, 0x43, 0x41,  
    0x3f, 0x3d, 0x3b, 0x39, 0x37, 0x35, 0x33, 0x31,  0x2f, 0x2d, 0x2b, 0x29, 0x27, 0x25, 0x23, 0x21,  
    0x1f, 0x1d, 0x1b, 0x19, 0x17, 0x15, 0x13, 0x11,  0x0f, 0x0d, 0x0b, 0x09, 0x07, 0x05, 0x03, 0x01,
    0x00, 0x02, 0x04, 0x06, 0x08, 0x0a, 0x0c, 0x0e,  0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 
    0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e,  0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 
    0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e,  0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 
    0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e,  0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e
    
   };

volatile char* curWave=wave256;

#include "avr/pgmspace.h"

#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))


byte poly[4];
// set both timer to do phase correct PCM at
// a nominal frequency of 31372.549
void setupTimers() 
{
  
// Timer1 and 2 Clock Prescaler to : 1, set WGM22 to zero, and WGM12,13
// for phase correct PCM
  TCCR1B = (TCCR1B & 0b11100000) | 0b00001;
  TCCR2B = (TCCR2B & 0b11110000) | 0b0001;

// set it to clear compare match mode
// on both pins, and phase correct PCM (WGM21 and WGM20)
  TCCR1A = (TCCR1A &0b00001100)| 0b10100001;
  TCCR2A = (TCCR2A &0b00001100)| 0b10100001;

// set overflow interrupts enabled for timers 1 and 2
  TIMSK2 |= (1<<TOIE2);
  TIMSK1 |= (1<<TOIE1);
  
}

// information about the current state of a single oscillator
struct OscillatorState
{
  unsigned int phaseStep; // frequency of this oscillator
   char volume; // volume multiplier for this oscillator
   unsigned int phaseAccu; // accumulator that steps through
                           // this oscillator
                           // high byte = current sample index
};

// our 4 oscillators
struct OscillatorState oscillators[4];

//********* interrupt routines for each of the timer overflows ******

inline byte getByteLevel(int accumulator)
{
    char valOut=((unsigned int)(accumulator))>>7;
    valOut+=128;
    return (byte)valOut;
}


// interrupt for timer 1 overflow (pins 9 and 10)
// in this, we set the next value for the PWM for those pins
// ie. we set the sample value
ISR(TIMER1_OVF_vect) 
{
  // update sample position (ignore overflow, as 
  // we use the top byte to index into a 256 byte buffer
  // and the overflow means it loops through the buffer)

  //oscillator 0 update 
  oscillators[0].phaseAccu+=oscillators[0].phaseStep;
  int valOut0=curWave[oscillators[0].phaseAccu>>8]*oscillators[0].volume;

  //oscillator 1 update 
  oscillators[1].phaseAccu+=oscillators[1].phaseStep;
  int valOut1=curWave[oscillators[1].phaseAccu>>8]*oscillators[1].volume;

// write these two oscillators out
// to individual pins

// write to pin 9
  poly[0]=getByteLevel(valOut0);
  // write to pin 10
  poly[1]=getByteLevel(valOut1);
  OCR1A=(poly[0]+poly[1]+poly[2]+poly[3])/4;
}
// interrupt for timer 2 overflow (pins 11 and 3)
// in this, we set the next value for the PWM for those pins
// ie. we set the sample value
ISR(TIMER2_OVF_vect) 
{
  // update sample position (ignore overflow, as 
  // we use the top byte to index into a 256 byte buffer
  // and the overflow means it loops through the buffer)
  
  // update the oscillators - make sure you update the oscillator
  // in the correct interrupt function, based on what pin you're 
  // outputting from
  
  // oscillator 2 update  
  oscillators[2].phaseAccu+=oscillators[2].phaseStep;
  int valOut2=curWave[oscillators[2].phaseAccu>>8]*oscillators[2].volume;
  
  // oscillator 3 update  
  oscillators[3].phaseAccu+=oscillators[3].phaseStep;
  int valOut3=curWave[oscillators[3].phaseAccu>>8]*oscillators[3].volume;
    
// write the oscillators to individual pins
  poly[2]=getByteLevel(valOut2); // write to pin 11
  poly[3]=getByteLevel(valOut3); // write pin 3
  
// if you want to mix multiple oscillators, put it in here instead
// e.g.  OCR2A=getByteLevel(valOut2+valOut3);

}

unsigned int hzToPhaseStep(float hz)
{
  float phaseStep= hz *2.0886902978652881446683197032183;
//  (pow(2,16) * frequency) / 31376.6
  return (unsigned int)phaseStep;
}

void setup()
{
         
    
   MIDI.begin(MIDI_CHANNEL_OMNI);  
   pinMode(2,INPUT_PULLUP);
    pinMode(3,INPUT_PULLUP);
      pinMode(4,INPUT_PULLUP);
    pinMode(5,INPUT_PULLUP);
      pinMode(6,INPUT_PULLUP);
   // pinMode(3,INPUT_PULLUP);
   // pinMode(3, OUTPUT);     // pin11= PWM  output / frequency output

    pinMode(9, OUTPUT);     // pin11= PWM  output / frequency output

  pinMode(10, OUTPUT);     // pin11= PWM  output / frequency output
  pinMode(11, OUTPUT);     // pin11= PWM  output / frequency output
  //Serial.begin(9600);        // connect to the serial port
  oscillators[0].volume=127;
  oscillators[1].volume=127;
  oscillators[2].volume=127;
  oscillators[3].volume=127;
  

  setupTimers();

}
bool timerinuse[4];
byte tones[4];
void loop()
{   if (MIDI.read())                // Is there a MIDI message incoming ?
    {
   
     if ( MIDI.getType()==0x90){
  if(timerinuse[0]==1&&timerinuse[1]==1&&timerinuse[2]==1&&timerinuse[3]==0){
  oscillators[3].phaseStep=hzToPhaseStep(freq[MIDI.getData1()-12]);
  oscillators[3].volume=127;
  timerinuse[3]=1;
  tones[3]=MIDI.getData1();
      }
  if(timerinuse[0]==1&&timerinuse[1]==1&&timerinuse[2]==0){
  oscillators[2].phaseStep=hzToPhaseStep(freq[MIDI.getData1()-12]);
  oscillators[2].volume=127;
  timerinuse[2]=1;
  tones[2]=MIDI.getData1();
      }
 if(timerinuse[0]==1&&timerinuse[1]==0){
  oscillators[1].phaseStep=hzToPhaseStep(freq[MIDI.getData1()-12]);
  oscillators[1].volume=127;
  timerinuse[1]=1;
  tones[1]=MIDI.getData1();
      }
      if(timerinuse[0]==0){
  oscillators[0].phaseStep=hzToPhaseStep(freq[MIDI.getData1()-12]);
  oscillators[0].volume=127;
  tones[0]=MIDI.getData1();
  timerinuse[0]=1;
      }

     }
       if ( MIDI.getType()==0x80){
 if(timerinuse[0]==1&&tones[0]==MIDI.getData1()){
  oscillators[0].volume=0;
  timerinuse[0]=0;
 }
  if(timerinuse[1]==1&&tones[1]==MIDI.getData1()){
  oscillators[1].volume=0;
  timerinuse[1]=0;
 }
  if(timerinuse[2]==1&&tones[2]==MIDI.getData1()){
  oscillators[2].volume=0;
  timerinuse[2]=0;
 }
   if(timerinuse[3]==1&&tones[3]==MIDI.getData1()){
  oscillators[3].volume=0;
  timerinuse[3]=0;
 }
     }
    
/*  oscillators[1].phaseStep=hzToPhaseStep(220);
  oscillators[2].phaseStep=hzToPhaseStep(110);
  oscillators[3].phaseStep=hzToPhaseStep(880); */
    }
    if(digitalRead(2)==0){
 for(int b=0;b!=256;b++){
     wave256[b]=(char*)pgm_read_word(&(sine256[b]));
      } 
      curWave=wave256;     
    }
     if(digitalRead(3)==0){
      for(int b=0;b!=256;b++){
     wave256[b]=(char*)pgm_read_word(&(square256[b]));
      }
      curWave=wave256;
    }
         if(digitalRead(4)==0){
      for(int b=0;b!=256;b++){
     wave256[b]=(char*)pgm_read_word(&(tri256[b]))-128;
      }
      curWave=wave256;
    } 
           if(digitalRead(5)==0){
      for(int b=0;b!=256;b++){
     wave256[b]=(char*)pgm_read_word(&(sawup256[b]))-128;
     
      }
      curWave=wave256;
    } 
           if(digitalRead(6)==0){
             for(int b=0;b!=256;b++){
     wave256[b]=(char*)pgm_read_word(&(sine256[b]));
      }
      for(int b=0;b!=127;b++){
     wave256[b]=(char*)pgm_read_word(&(special256[b]));
      }
        for(int b=0;b!=128;b++){
     wave256[b]=(char*)pgm_read_word(&(special256[b+128]))-128;
      }
      curWave=wave256;
    } 
  // byte pwm=

}

