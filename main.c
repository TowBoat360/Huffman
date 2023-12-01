#include <stdio.h>
#include "huffman.h"
#include <string.h>

int main()
{
	int output;

	char test_input_1[] = "";
	char test_output_1[50] = {0};
	test_rd_chars_wr_bits(test_input_1, test_output_1);
	output = strcmp(test_output_1, "");
	printf("%s\n", output ? "Testfall 1 fehlgeschlagen!" : "Testfall 1 erfolgreich!");

	char test_input_2[] = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxX";
	char test_output_2[50] = {0};
	test_rd_chars_wr_bits(test_input_2, test_output_2);
	output = strcmp(test_output_2, "UUUUUU");
    //printf("%s\n", test_output_2);
	printf("%s\n", output ? "Testfall 2 fehlgeschlagen!" : "Testfall 2 erfolgreich!");

	char test_input_3[] = "abCdefGHijKlmnOPqrStuvWXyzAbcdEF";
	char test_output_3[50] = {0};
	test_rd_chars_wr_bits(test_input_3, test_output_3);
	output = strcmp(test_output_3, "####");
    //printf("%s\n", test_output_3);
	printf("%s\n", output ? "Testfall 3 fehlgeschlagen!" : "Testfall 3 erfolgreich!");

	char test_input_4[] = "";
	char test_output_4[50] = {0};
	test_rd_bits_wr_chars(test_input_4, test_output_4);
	output = strcmp(test_output_4, "");
	printf("%s\n", output ? "Testfall 4 fehlgeschlagen!" : "Testfall 4 erfolgreich!");

	char test_input_5[] = "1234567890";
	char test_output_5[50] = {0};
	test_rd_bits_wr_chars(test_input_5, test_output_5);
	output = strcmp(test_output_5, "00110001001100100011001100110100001101010011011000110111001110000011100100110000");
	printf("%s\n", output ? "Testfall 5 fehlgeschlagen!" : "Testfall 5 erfolgreich!");

	char test_input_6[] = "0192837465";
	char test_output_6[50] = {0};
	test_rd_bits_wr_chars(test_input_6, test_output_6);
	output = strcmp(test_output_6, "00110000001100010011100100110010001110000011001100110111001101000011011000110101");
	printf("%s\n", output ? "Testfall 6 fehlgeschlagen!" : "Testfall 6 erfolgreich!");

	return 0;
}
