//
// Created by Tom on 17.11.2023.
//
#include "huffman.h"
#include "huffman_common.h"
#include "io.h"
#include <stdio.h>

void test_rd_chars_wr_bits(char in_filename[], char out_filename[])
{
	unsigned char c;

	//Buffer initiieren
	init_in(in_filename);
	init_out();

	while (has_next_char())
	{
		//holt sich den nächsten char
		c = read_char();

		//Überprüfung, ob der gelesene char kleiner als 'a' ist
		if (c < 'a')
		{
			write_bit(ONE);
		}
		else
		{
			write_bit(ZERO);
		}
	}

	get_out_buffer(out_filename);

	printf("\n");
}

void test_rd_bits_wr_chars(char in_filename[], char out_filename[])
{
	BIT b;

	//Buffer initiieren
	init_in(in_filename);
	init_out();

	while (has_next_bit())
	{
		//holt sich den nächsten Bit
		b = read_bit();

		//Überprüfung, was für ein Bit gelesen wurde
		if (b == ONE)
		{
			write_char('1');
		}
		else
		{
			write_char('0');
		}
	}

	get_out_buffer(out_filename);

	printf("\n");
}