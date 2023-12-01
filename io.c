//
// Created by Tom on 18.11.2023.
//

#include "io.h"


/**
 * Größe des Eingabe-/Ausgabepuffers
 */
#define BUF_SIZE 4096

/**
 * Gibt den Bit an der jeweiligen Stelle
 *
 * @param BYTE ist der Byte aus dem ein Bit extrahiert werden soll
 * @param POS gibt die Stelle des Bits an, der extrahiert werden soll
 */
#define GET_BIT(BYTE, POS) ((BYTE) & (0x80 >> POS))

/**
 * schreibt einen Bit an eine bestimmte Stelle in einem bestimmten byte
 *
 * @param BYTE ist der Byte, in den ein Bit geschrieben werden soll
 * @param BIT ist der bit, der gesetzt werden soll
 * @param POS ist die Position, an der das Bit gesetzt werden soll
 */
#define PUT_BIT(BYTE, BIT, POS) (BYTE) = ((BIT) == ONE ? ((BYTE) | (0x80 >> POS)): ((BYTE) & ~(0x80 >> POS)))



/**
 * gibt an, in welchem Byte des Input-Buffers das aktuelle Bit steht
 */
#define BYTE_POS_IN (pos_in / 8)

/**
 * gibt an, welches das aktuelle Bit im Input-Buffer ist
 */
#define BIT_POS_IN (pos_in % 8)

/**
 * gibt an, in welchem Byte des Output-Buffers das aktuelle Bit steht
 */
#define BYTE_POS_OUT (pos_out / 8)

/**
 * gibt an, welches das aktuelle Bit im Output-Buffer ist
 */
#define BIT_POS_OUT (pos_out % 8)


/*
 * Eingabepuffer
 */
static unsigned char in_buffer[BUF_SIZE];

/*
 * Ausgabepuffer
 */
static unsigned char out_buffer[BUF_SIZE];

/*ein Zeiger, der auf die aktuelle Position im Inout-Buffer zeigt und beginnt bei 0*/
static int pos_in;
/*gibt an, wie viele Bytes sich im Input-Buffer befinden*/
static int fill_in;
/*gibt an, wie viele Bits im Input-Buffer stehen*/
static int bits_in;

/*ein Zeiger auf die aktuelle Position im Output-Buffer und beginnt bei 0*/
static int pos_out;
/*gibt an, wie viele Bytes schon im Output-Buffer stehen*/
static int fill_out;


void init_in(char text[])
{
	pos_in = 0;
	fill_in = 0;

	//hier wird jeder Char von text in den Input-Buffer geschrieben, bis '\0' kommt
	while (text[fill_in] != '\0')
	{
		in_buffer[fill_in] = text[fill_in];
		fill_in += 1;
	}
	bits_in = fill_in * 8;
}


void init_out()
{
	fill_out = 0;
	pos_out = 0;
}


void get_out_buffer(char text[])
{
	for (int i = 0; i < fill_out; i++)
	{
		//Typecast, da text ein String aus signed chars ist
		text[i] = (signed char)out_buffer[i];
	}
	text[fill_out] = '\0';
}


//Byteweise lesen und schreiben

bool has_next_char(void)
{
	return pos_in < fill_in;
}


unsigned char read_char(void)
{
	//holt sich temporär die aktuelle Position, da der Zeiger danach erhöht werden muss
	int pos_in_tmp = pos_in;
	pos_in += 1;
	return in_buffer[pos_in_tmp];
}


void write_char(unsigned char c)
{
	out_buffer[pos_out] = c;
	pos_out += 1;
	fill_out += 1;
}


//Bitweise lesen und schreiben

bool has_next_bit(void)
{
	/* < bits_in, da \0 nicht mehr mit inbegriffen ist*/
	return pos_in < bits_in;
}


BIT read_bit(void)
{
	char b = GET_BIT(in_buffer[BYTE_POS_IN], BIT_POS_IN);
	pos_in += 1;
	return b > 0 ? ONE : ZERO;
}


void write_bit(BIT c)
{
	PUT_BIT(out_buffer[BYTE_POS_OUT], c, BIT_POS_OUT);
	pos_out += 1;
	fill_out = pos_out / 8;
}