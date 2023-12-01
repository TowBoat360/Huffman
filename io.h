//
// Created by Tom on 17.11.2023.
//

#ifndef HUFFMAN_IO_H
#define HUFFMAN_IO_H

#include <stdbool.h>
#include "huffman_common.h"

/**
 * bereitet den Input-Buffer vor,
 * indem der Input-Buffer geleert wird,
 * und der Zeiger für die Position zurückgesetzt und der Füllstand aktualisiert werden
 *
 * @param text ist der String, der in den Input-Buffer geschrieben werden soll
 */
void init_in(char text[]);

/**
 * bereitet den Output-Buffer vor,
 * indem der Output-Buffer geleert wird und Position des zeigers und Füllstand auf 0 gesetzt werden
 */
void init_out();

/**
 * schreibt den Inhalt des Output-Buffers in den Vektor text, sodass dieser als String ausgelesen werden kann.
 *
 * @param text ist der Vektor, in den geschrieben wird
 */
void get_out_buffer(char text[]);

//Byteweise lesen und schreiben

/**
 * überprüft, ob noch ein weiteres Zeichen aus dem Input-Buffer gelesen werden kann
 *
 * @return gibt true wieder, wenn noch ein weiterer Char vorhanden ist und false, wenn nicht.
 */
bool has_next_char(void);

/**
 * liest den nächsten Char aus dem Input-Buffer
 *
 * @return gibt den aktuellen Char wieder
 */
unsigned char read_char(void);

/**
 * schreibt einen char in den Output-Buffer
 *
 * @param c ist der Char der in den Buffer geschrieben werden soll
 */
void write_char(unsigned char c);

//Bitweise lesen und schreiben

/**
 * prüft ob ein weiteren Bit im aktuellen Byte des Input-Buffers vorhanden ist
 *
 * @return gibt true wieder, wenn ein weiteres Bit vorhanden ist und false, wenn dies nicht der Fall ist.
 */
bool has_next_bit(void);

/**
 * liest den nächsten Bit aus dem Input-Buffer
 *
 * @return gibt ONE wieder, wenn der aktuelle Bit 1 ist und ZERO, wenn dieser 0 ist.
 */
BIT read_bit(void);

/**
 * schreibt ein Bit in den Output-Buffer
 *
 * @param c ist der Bit, der in den Buffer geschrieben werden soll.
 */
void write_bit(BIT c);

#endif //HUFFMAN_IO_H
