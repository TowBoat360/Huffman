#include <stdio.h>
#include <stdbool.h>
#include "exit.h"

int main(int argc, char **argv)
{
	bool boo = false;
	int index_output;

    for (int i = 1; i < argc; i++)
    {
        printf("arv[%d] = %s", i, argv[i]);
        printf("\n");
    }

	//printf("%d\n", argc);
	if (argc == 1)
	{
		printf("\n");
		printf("Fehler bei den Argumenten!\n");
		printf("benutze -h für eine Hilfe!\n");

		return ARGS_ERROR;
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			if (*argv[i] != '-')
			{
				if (boo)
				{
					if (i == index_output)
					{
						printf("Ausgabedatei: %s\n", argv[i]);
					}
					else
					{
						printf("Eingabedatei: %s\n", argv[i]);
					}
//				else
//				{
//					printf("\n");
//					printf("Fehler bei den Argumenten!\n");
//
//					return ARGS_ERROR;
//				}

				}
				else
				{
					printf("Eingabedatei: %s\n", argv[i]);
				}
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
					char c = *(argv[i]+2);
					if (c == '\0')
					{
						printf("Level of compression: %c\n", '2');
					} else if (c < 10)
					{
						printf("Level of compression: %c\n", *(argv[i]+2));
					}
					else
					{
						printf("\n");
						printf("Fehler bei den Argumenten!\n");
						printf("benutze -h für eine Hilfe!\n");

						return ARGS_ERROR;
					}
				}
					break;
				case 'v':
					printf("Information about compression: \n");
					break;
				case 'o':
				{
					if (i < argc - 1)
					{
						char c = *argv[i + 1];
						index_output = i + 1;
						if (c != '-' && c != '\0')
						{
							boo = true;
							//printf("Name of file: %s\n", argv[i + 1]);
						}
						else
						{
							printf("\n");
							printf("Fehler bei den Argumenten!\n");
							printf("benutze -h für eine Hilfe!\n");

							return ARGS_ERROR;
						}
					}
					else
					{
						printf("\n");
						printf("Fehler bei den Argumenten!\n");
						printf("benutze -h für eine Hilfe!\n");

						return ARGS_ERROR;
					}
					break;
				}
				case 'h':
					printf("List of tips: \n");
					printf("	-c --> Komprimiere\n");
					printf("	-d --> Dekomprimiere\n");
					printf("	-l<Level> --> Level der Kompression, wird als Zahl angegeben.\n"
						   "		Wenn kein Level angegeben wird, wird der Standardwert 2 genommen.\n");
					printf("	-v --> Informationen zu der Kompression\n");
					printf("	-o <Ausgabedatei> --> Name der Ausgabedatei festlegen.\n"
						   "		Wenn weggelassen, wird standardname '<Eingabedatei>.h bzw .d' genommen.\n");
					printf("	<Eingabedatei>\n");

					break;
				default:
					printf("\n");
					printf("Fehler bei den Argumenten!\n");
					printf("benutze -h für eine Hilfe!\n");

					return ARGS_ERROR;
				}
			}
			//printf("i: %c\n", *argv[i]);
			//printf("1: %c\n", *(argv[2]+1));
		}

		printf("\n");
		printf("Erfolgreich!\n");

		return EXIT_SUCCESS;
	}
}
