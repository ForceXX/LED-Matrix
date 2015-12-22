/*
 * HT16K33.h
 *
 *  Created on: 26.10.2015
 *      Author: Jonas Heim/Alexander Rabenstein
 */


#ifndef HT16K33_H
#define HT16K33_H

#include <inttypes.h>
#include "util.h"
/*!
@defgroup WAIT Wartezeit-Konstanten
@{
*/
/*! Wartezeit zwischen Spaltenweiser Verschiebung während der Laufschrift in µs*/
#define SCROLL_WAIT 100000
/*! Wartezeit zwsichen abgeschlossener Laufschrift und Löschen der Matrix in µs*/
#define SCROLL_WAIT_STILL 500000
/*!
@}
*/
/*
 * Prototypen
 */
/*!
 \brief Schreibt ein Datenbyte 'data' zugehörig zum Befehlsbyte 'command' über I2C

 \param fd I2C-Variable
 \param uint8_t Befehlsbyte
 \param uint8_t Datenbyte
*/
void ht16k33_write_byte (int fd, uint8_t command, uint8_t data );
/*!
 \brief Schreibt ein Befehlsbyte 'command' über I2C

 \param fd I2C-Variable
 \param uint8_t command
*/
void ht16k33_write_command (int fd, uint8_t command);
/*!
 \brief Initialisiert den Controller HT16K33 mit Standardwerten und liefert die zum
 Geraet gehoerige I2C-Variable zurück

 \return I2C-Variable
*/
int ht16k33_init_i2c();
/*!
 \brief Leert die Matrix

 \param int I2C-Variable
*/
void ht16k33_clear(int);
/*!
 \brief Gibt ein char-Array interpretiert als Zeilen auf der LED-Matrix aus

 \param int I2C-Variable
 \param char* char-Array
*/
void ht16k33_print_array(int, unsigned char*);
/*!
 \brief Gibt ein zweidimensionales char-Array Gibt ein char-Array
 interpretiert als Zeilen auf der LED-Matrix aus

 \param int I2C-Variable
 \param char[][] char-Array
*/
void ht16k33_print_array_dimm(int, unsigned char[8][8]);
/*!
 \brief Gibt nacheinander die Zeichen eines Strings auf der LED-Matrix aus

 \param int I2C-Variable
 \param char* String
*/
void ht16k33_print_string(int, char*);
/*!
 \brief Schiebt zwei einzelne Zeichen mithilfe von Bitoperationen von links nach rechts

 \param int I2C-Variable
 \param char* linkes Zeichen
 \param char* rechtes Zeichen
*/
void ht16k33_scroll_chars_left(int, unsigned char*, unsigned char*);
/*!
 \brief Laufschrift von links nach rechts

 \param int I2C-Variable
 \param char* String
*/
void ht16k33_print_left(int, char*);
/*!
 \brief Schiebt zwei einzelne Zeichen mithilfe von Bitoperationen von rechts nach links

 \param int I2C-Variable
 \param char* linkes Zeichen
 \param char* rechtes Zeichen
*/
void ht16k33_scroll_chars_right(int, unsigned char*, unsigned char*);
/*!
 \brief Laufschrift von rechts nach links

 \param int I2C-Variable
 \param char* String
*/
void ht16k33_print_right(int, char*);
/*!
 \brief Ändert die Helligkeit der LED-Matrix

 \param int I2C-Variable
 \param char Helligkeitswert
*/
void ht16k33_set_brigthness(int, unsigned char);
/*!
 \brief Setzt eine einzelne LED

 \param int I2C-Variable
 \param int X-Position
 \param int Y-Position
 \param int Wert der LED (1=an,0=aus)
*/
void ht16k33_set_single_led(int,int,int,int);


/*!
@defgroup BRIGTHNESS Helligkeitskonstanten
@{
 */

 #define brigthness_1_16 0xE0/*!< Helligkeitswert 1 von 16 */
 #define brigthness_2_16 0xE1/*!< Helligkeitswert 2 von 16 */
 #define brigthness_3_16 0xE2/*!< Helligkeitswert 3 von 16 */
 #define brigthness_4_16 0xE3/*!< Helligkeitswert 4 von 16 */
 #define brigthness_5_16 0xE4/*!< Helligkeitswert 5 von 16 */
 #define brigthness_6_16 0xE5/*!< Helligkeitswert 6 von 16 */
 #define brigthness_7_16 0xE6/*!< Helligkeitswert 7 von 16 */
 #define brigthness_8_16 0xE7/*!< Helligkeitswert 8 von 16 */
 #define brigthness_9_16 0xE8/*!< Helligkeitswert 9 von 16 */
 #define brigthness_10_16 0xE9/*!< Helligkeitswert 10 von 16 */
 #define brigthness_11_16 0xEA/*!< Helligkeitswert 11 von 16 */
 #define brigthness_12_16 0xEB/*!< Helligkeitswert 12 von 16 */
 #define brigthness_13_16 0xEC/*!< Helligkeitswert 13 von 16 */
 #define brigthness_14_16 0xED/*!< Helligkeitswert 14 von 16 */
 #define brigthness_15_16 0xEE/*!< Helligkeitswert 15 von 16 */
 #define brigthness_16_16 0xEF/*!< Helligkeitswert 16 von 16 */
/*!
@}
*/
#endif // HT16K33_H
