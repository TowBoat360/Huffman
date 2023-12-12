//
// Created by Tom on 17.11.2023.
//

#ifndef HUFFMAN_HUFFMAN_H
#define HUFFMAN_HUFFMAN_H

/**
 * Diese Funktion liest byteweise aus dem Input-Buffer und schreibt bitweise in den Output-Buffer
 *
 * @param in ist ein String, der in den Input-Buffer geschrieben wird
 * @param out ist ein String, in den der Inhalt des Output-Buffers geschrieben wird
 */
void test_rd_chars_wr_bits(char in_filename[], char out_filename[]);

/**
 *
 * Diese Funktion liest den Inhalt von in bitweise aus und schreibt dann byteweise in den Output-Buffer
 *
 * @param in ist ein String, der in den Inout-Buffer geschrieben wird
 * @param out ist ein String, in den der Inhalt des Output-Buffers geschrieben wird
 */
void test_rd_bits_wr_chars(char in_filename[], char out_filename[]);

#endif //HUFFMAN_HUFFMAN_H
