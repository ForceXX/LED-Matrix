/*
 * util.h
 *
 *  Created on: 27.10.2015
 *      Author: Jonas Heim/Alexander Rabenstein
 */


#ifndef UTIL_H
#define UTIL_H

/*
 * Prototypes
 */
/*!
 \brief Gibt einen Zeiger auf ein 8*1Byte Array zurück, welches die Codierung der LED-Matrix
 für das Zeichen enthält.

Unterscheidet das gegebene Zeichen mittels einer Switch-Case Abfrage und gibt, falls gefunden,
einen Zeiger auf das Array das das gegebene Zeichen repräsentiert zurück.
 \param char Zeichen
 \return char Zeiger auf Zeichenvariable
*/
unsigned char * charInHex(char);

extern unsigned char row_address[]; /*!< Adressen des Controllers der einzelnen Zeilen der Matrix */

/*!
@defgroup CHARS Zeichenkodierungen
@{
 */
 //Uppercase Letters
extern unsigned char char_A[]; /*!< 'A' */
extern unsigned char char_B[]; /*!< 'B' */
extern unsigned char char_C[]; /*!< 'C' */
extern unsigned char char_D[]; /*!< 'D' */
extern unsigned char char_E[]; /*!< 'E' */
extern unsigned char char_F[]; /*!< 'F' */
extern unsigned char char_G[]; /*!< 'G' */
extern unsigned char char_H[]; /*!< 'H' */
extern unsigned char char_I[]; /*!< 'I' */
extern unsigned char char_J[]; /*!< 'J' */
extern unsigned char char_K[]; /*!< 'K' */
extern unsigned char char_L[]; /*!< 'L' */
extern unsigned char char_M[]; /*!< 'M' */
extern unsigned char char_N[]; /*!< 'N' */
extern unsigned char char_O[]; /*!< 'O' */
extern unsigned char char_P[]; /*!< 'P' */
extern unsigned char char_Q[]; /*!< 'Q' */
extern unsigned char char_R[]; /*!< 'R' */
extern unsigned char char_S[]; /*!< 'S' */
extern unsigned char char_T[]; /*!< 'T' */
extern unsigned char char_U[]; /*!< 'U' */
extern unsigned char char_V[]; /*!< 'V' */
extern unsigned char char_W[]; /*!< 'W' */
extern unsigned char char_X[]; /*!< 'X' */
extern unsigned char char_Y[]; /*!< 'Y' */
extern unsigned char char_Z[]; /*!< 'Z' */

//Lowercase Letters
extern unsigned char char_a[]; /*!< 'a' */
extern unsigned char char_b[]; /*!< 'b' */
extern unsigned char char_c[]; /*!< 'c' */
extern unsigned char char_d[]; /*!< 'd' */
extern unsigned char char_e[]; /*!< 'e' */
extern unsigned char char_f[]; /*!< 'f' */
extern unsigned char char_g[]; /*!< 'g' */
extern unsigned char char_h[]; /*!< 'h' */
extern unsigned char char_i[]; /*!< 'i' */
extern unsigned char char_j[]; /*!< 'j' */
extern unsigned char char_k[]; /*!< 'k' */
extern unsigned char char_l[]; /*!< 'l' */
extern unsigned char char_m[]; /*!< 'm' */
extern unsigned char char_n[]; /*!< 'n' */
extern unsigned char char_o[]; /*!< 'o' */
extern unsigned char char_p[]; /*!< 'p' */
extern unsigned char char_q[]; /*!< 'q' */
extern unsigned char char_r[]; /*!< 'r' */
extern unsigned char char_s[]; /*!< 's' */
extern unsigned char char_t[]; /*!< 't' */
extern unsigned char char_u[]; /*!< 'u' */
extern unsigned char char_v[]; /*!< 'v' */
extern unsigned char char_w[]; /*!< 'w' */
extern unsigned char char_x[]; /*!< 'x' */
extern unsigned char char_y[]; /*!< 'y' */
extern unsigned char char_z[]; /*!< 'z' */

//Numbers
extern unsigned char char_0[]; /*!< '0' */
extern unsigned char char_1[]; /*!< '1' */
extern unsigned char char_2[]; /*!< '2' */
extern unsigned char char_3[]; /*!< '3' */
extern unsigned char char_4[]; /*!< '4' */
extern unsigned char char_5[]; /*!< '5' */
extern unsigned char char_6[]; /*!< '6' */
extern unsigned char char_7[]; /*!< '7' */
extern unsigned char char_8[]; /*!< '8' */
extern unsigned char char_9[]; /*!< '9' */

//Special characters
extern unsigned char char_space[]; /*!< ' ' */
extern unsigned char char_smaller_as[]; /*!< '<' */
extern unsigned char char_greater_as[]; /*!< '>' */
extern unsigned char char_equals[]; /*!< '=' */
extern unsigned char char_exclamation_mark[]; /*!< '!' */
extern unsigned char char_question_mark[]; /*!< '?' */
extern unsigned char char_quotation_mark[]; /*!< '"' */
extern unsigned char char_hash[]; /*!< '#' */
extern unsigned char char_percent[]; /*!< '%' */
extern unsigned char char_and[]; /*!< '&' */
extern unsigned char char_apostrophe[]; /*!< ''' */
extern unsigned char char_bracket_open[]; /*!< '(' */
extern unsigned char char_bracket_close[]; /*!< ')' */
extern unsigned char char_plus[]; /*!< '+' */
extern unsigned char char_minus[]; /*!< '-' */
extern unsigned char char_period[]; /*!< '.' */
extern unsigned char char_comma[]; /*!< ',' */
extern unsigned char char_slash[]; /*!< '/' */
extern unsigned char char_colon[]; /*!< ':' */
extern unsigned char char_semicolon[]; /*!< ; */
extern unsigned char char_underline[]; /*!< _ */
extern unsigned char char_at_sign[]; /*!< @ */
extern unsigned char char_full[]; /*!< Alle LEDs an */
extern unsigned char char_clean[]; /*!< Alles LEDs aus */
extern unsigned char char_smiley[]; /*!< Smiley :-) */

/*
@}
*/

#endif // UTIL_H
