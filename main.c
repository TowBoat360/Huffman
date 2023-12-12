#include <stdio.h>
#include <stdbool.h>
#include "exit.h"
#include <time.h>

int main(int argc, char **argv)
{
	clock_t prg_start;
	clock_t prg_end;

	prg_start = clock();

	bool compress = false;
	bool decompress = false;

	bool l = false;
	char level = 2;

	bool v_info = false;

	bool output_file = false;
	int index_output;

	bool help = false;

    for (int i = 1; i < argc; i++)
    {
        printf("arv[%d] = %s", i, argv[i]);
        printf("\n");
    }

	//printf("%d\n", argc);
	if (argc == 1)
	{
		printf("\n");
		printf("argc = 1\n");
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
				if (output_file)
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
					compress = true;
					break;
				case 'd':
					decompress = true;
					break;
				case 'l': {
					char c = *(argv[i]+2);
					l = true;

					if (c == '\0')
					{
						level = 2;
					} else if (*(argv[i]+3) == '\0')
					{
						level = '2';
					}
					else
					{
						printf("\n");
						printf("zweistelliges level angegeben!\n");
						printf("Fehler bei den Argumenten!\n");
						printf("benutze -h für eine Hilfe!\n");

						return ARGS_ERROR;
					}
				}
					break;
				case 'v':
					v_info = true;
					break;
				case 'o':
				{
					if (i < argc - 1)
					{
						char c = *argv[i + 1];
						index_output = i + 1;
						if (c != '-' && c != '\0')
						{
							output_file = true;
							//printf("Name of file: %s\n", argv[i + 1]);
						}
						else
						{
							printf("\n");
							printf("kein Name für Output-Datei vorhanden!\n");
							printf("Fehler bei den Argumenten!\n");
							printf("benutze -h für eine Hilfe!\n");

							return ARGS_ERROR;
						}
					}
					else
					{
						printf("\n");
						printf("kein Name für Output-Datei vorhanden!\n");
						printf("Fehler bei den Argumenten!\n");
						printf("benutze -h für eine Hilfe!\n");

						return ARGS_ERROR;
					}
					break;
				}
				case 'h':
					help = true;
					break;
				default:
					printf("\n");
					printf("default\n");
					printf("Fehler bei den Argumenten!\n");
					printf("benutze -h für eine Hilfe!\n");

					return ARGS_ERROR;
				}
			}
			//printf("i: %c\n", *argv[i]);
			//printf("1: %c\n", *(argv[2]+1));
		}

		if (compress)
		{
			printf("Komprimieren!\n");
		}

		if (decompress)
		{
			printf("Dekomprimieren!\n");
		}

		if (l)
		{
			printf("Level of compression: %c\n", level);
		}

		if (help)
		{
			printf("List of tips: \n");
			printf("	-c --> Komprimiere\n");
			printf("	-d --> Dekomprimiere\n");
			printf("	-l<Level> --> Level der Kompression, wird als Zahl angegeben.\n"
				   "		Wenn kein Level angegeben wird, wird der Standardwert 2 genommen.\n");
			printf("	-v --> Informationen zu der Kompression\n");
			printf("	-o <Ausgabedatei> --> Name der Ausgabedatei festlegen.\n"
				   "		Wenn weggelassen, wird standardname '<Eingabedatei>.h bzw .d' genommen.\n");
			printf("	<Eingabedatei>\n");
		}

		printf("\n");
		printf("Erfolgreich!\n");

		prg_end = clock();

		if (v_info)
		{
			printf("Ausfuehrungsstatistik\n");
			printf(" - Groessee der Eingabedatei: \n");
			printf(" - Groessee der Ausgabedatei: \n");
			printf(" - Die Programmlaufzeit betrug %.2f Sekunden\n",
					(float) (prg_end - prg_start) / CLOCKS_PER_SEC);
		}

		return EXIT_SUCCESS;
	}
}
