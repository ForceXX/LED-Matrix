/*
 * HT16K33.c
 *
 *  Created on: 26.10.2015
 *      Author: Jonas Heim/Alexander Rabenstein
 */

#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <inttypes.h>
#include <unistd.h>
#include <string.h>
#include "util.h"

#include "HT16K33.h"

void ht16k33_write_command(int fd, uint8_t command) {
    int result = i2c_smbus_write_byte(fd, command);
    if (result == -1) {
        printf("Failed to write command to I2C.\n");
    }
}

void ht16k33_write_byte(int fd, uint8_t command, uint8_t data) {
    data = (data>>1)|(data<<7);
    int result = i2c_smbus_write_byte_data(fd, command, data);
    if (result == -1) {
        printf("Failed to write byte to I2C.\n");
    }
}

void ht16k33_print_array_dimm(int fd, unsigned char arr8x8[8][8]) {
    unsigned char i, j;
    unsigned char arr[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (arr8x8[i][j] != 0)
                arr[i] |= (1 << j);
            else
                arr[i] &= ~(1 << j);
        }
    }
    for (i = 0; i < 16; i = i + 2) {
        ht16k33_write_byte(fd, i, arr[i / 2]);
    }
    usleep(500000);
    return;
}

/*
 * Clears the LED-Matrix
 */
void ht16k33_clear(int fd){
    ht16k33_print_array(fd, char_clean);
}

/*
 * Prints given Arrays of 8 chars to the LED-Matrix
 */
void ht16k33_print_array(int fd, unsigned char arr8x8[8]) {
    for (int i = 0; i < 8 ; i++) {
        ht16k33_write_byte(fd, row_address[7-i], arr8x8[i]);
    }
}
//Initialize the HT16K33-Controller
int ht16k33_init_i2c() {
    int fd;
    fd = open("/dev/i2c-1", O_RDWR);
    if (fd == -1) {
        printf("Failed to open I2C device.\n");
	return -1;
    }
    int result = ioctl(fd, I2C_SLAVE, 0x70);
    if (result == -1) {
        printf("Failed to set address.\n");
	return -1;
    }
    ht16k33_write_command(fd, 0x21); // Start oscillator (page 10)
    ht16k33_write_command(fd, 0x81); // Display on, blinking off (page 11)
    ht16k33_write_command(fd, 0xef); // Full brightness (page 15)
    ht16k33_write_command(fd, 0x00); // Start writing to address 0 (page 13)
    return fd;
}

//Prints string, redraw every single character
void ht16k33_print_string(int fd, char input[]) {
    int size = strlen(input);
    for (int i = 0; i < size; i++) {
        ht16k33_print_array(fd, charInHex(input[i]));
        usleep(500000);
    }
}

/*
 * Scrolls two chars from the right to the left
 */
void ht16k33_scroll_chars_left(int fd, unsigned char char1[], unsigned char char2[]){
    for(int j = 1; j <= 8; j++){
        for (int i = 0; i < 8 ; i++) {
                    ht16k33_write_byte(fd, row_address[7-i],((char1[i]<<j)|(char2[i]>>(8-j)) ) );
                    //printf("row%d: %x\n",7-i,(char)(char1[i]<<j)|(char2[i]>>(8-j)) );
        }
        usleep(SCROLL_WAIT);
    }
}

/*
 * Scrolls the given char Array from the right to the left
 */
void ht16k33_print_left(int fd, char s[]){
        int size = strlen(s)-1;
        for(int i = 0; i <size; i++){
            ht16k33_scroll_chars_left(fd, charInHex(s[i]), charInHex(s[i+1]));
        }
        usleep(SCROLL_WAIT_STILL);
        ht16k33_clear(fd);
}

/*
 * Scrolls two chars from the left to the right
 */
void ht16k33_scroll_chars_right(int fd, unsigned char char1[], unsigned char char2[]){
    for(int j = 1; j <= 8; j++){
        for (int i = 0; i < 8 ; i++) {
                    ht16k33_write_byte(fd, row_address[7-i],((char1[i]<<(8-j))|(char2[i]>>j) ) );
                    //printf("row%d: %x\n",7-i,(char)(char1[i]>>j)|(char2[i]<<(8-j)) );
        }
        usleep(SCROLL_WAIT);
    }
}

/*
 * Scrolls the given char Array from the left to the right
 */
void ht16k33_print_right(int fd, char s[]){
        int size = strlen(s)-1;
        for(int i = 0; i <size; i++){
            ht16k33_scroll_chars_right(fd, charInHex(s[i]), charInHex(s[i+1]));
        }
        usleep(SCROLL_WAIT_STILL);
        ht16k33_clear(fd);
}

//Sets given LED with coordinates X=posX, Y=posY to 1, if value != 0, else to 0
void ht16k33_set_single_led(int fd, int posX, int posY, int value){
    if(((posX<=7)&&(posX>=0)) && ((value==0)||(value==1))){
        ht16k33_write_byte(fd, row_address[posY], (value<<posX));
    }
}

//Sets brightness of the LEDs
void ht16k33_set_brigthness(int fd, unsigned char brigthness){
    ht16k33_write_command(fd, brigthness);
}
