/*
 * HT16K33.h
 *
 *  Created on: 26.10.2015
 *      Author: Jonas Heim
 */


#ifndef HT16K33_H
#define HT16K33_H

#include <inttypes.h>
#include "util.h"

#define SCROLL_WAIT 100000

/*
 * Prototypen
 */
void ht16k33_write_byte (int fd, uint8_t command, uint8_t data );
void ht16k33_write_command (int fd, uint8_t command);
int ht16k33_init_i2c();
void ht16k33_clear(int);
void ht16k33_print_array(int, unsigned char*);
void ht16k33_print_array_dimm(int, unsigned char[8][8]);
void ht16k33_print_string(int, char*);
void ht16k33_scroll_chars_left(int, unsigned char*, unsigned char*);
void ht16k33_print_left(int, char*);
void ht16k33_scroll_chars_right(int, unsigned char*, unsigned char*);
void ht16k33_print_right(int, char*);
void ht16k33_set_brigthness(int, unsigned char);
void ht16k33_set_single_led(int,int,int,int);


/*
 * Brigthness constants
 */

 #define brigthness_1_16 0xE0
 #define brigthness_2_16 0xE1
 #define brigthness_3_16 0xE2
 #define brigthness_4_16 0xE3
 #define brigthness_5_16 0xE4
 #define brigthness_6_16 0xE5
 #define brigthness_7_16 0xE6
 #define brigthness_8_16 0xE7
 #define brigthness_9_16 0xE8
 #define brigthness_10_16 0xE9
 #define brigthness_11_16 0xEA
 #define brigthness_12_16 0xEB
 #define brigthness_13_16 0xEC
 #define brigthness_14_16 0xED
 #define brigthness_15_16 0xEE
 #define brigthness_16_16 0xEF

#endif // HT16K33_H
