#include <stdio.h>
#include "exit.h"

int main(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        printf("arv[%d] = %s", i, argv[i]);
        printf("\n");
    }

    for (int i = 1; i < argc; i++)
    {
        if (*argv[i] != '-')
        {

        }
        else
        {
            switch(*(argv[i]+1))
            {
                case 'c':
                    printf("Compress!\n");
                    break;
                case 'd':
                    printf("Decompress!\n");
                    break;
                case 'l': {
                    unsigned char c = *(argv[i]+2);
                    if (c == '\0')
                    {
                        printf("Level of compression: %c\n", '2');
                    } else
                    {
                        printf("Level of compression: %c\n", *(argv[i]+2));
                    }
                }
                    break;
                case 'v':
                    printf("Information about compression: \n");
                    break;
                case 'o':
                    printf("Name of file: %s\n", argv[i+1]);
                    break;
                case 'h':
                    printf("List of tips: \n");
                    break;
            }
        }
        //printf("i: %c\n", *argv[i]);
        //printf("1: %c\n", *(argv[2]+1));
    }

	return EXIT_SUCCESS;
}
