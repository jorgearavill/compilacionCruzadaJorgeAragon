#include "libcat.h"

int is_regular_file(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

int is_directory(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

void catValidation(int argc, char * argv[])
{
	FILE *file = NULL;
	char currentEvaluatedChar;
	
	if(argc > 1)
	{
		for(int currentArgument = 1; currentArgument < argc; currentArgument++)
		{
			if(is_regular_file(argv[currentArgument]))
			{
				
			if((file = fopen(argv[currentArgument], "r")) == NULL)
			{
				fprintf(stderr, "%s failed: opening %s: error is: %s", argv[0], argv[currentArgument], strerror(errno));
			}
			else
			{
				currentEvaluatedChar = fgetc(file);
                while (currentEvaluatedChar != EOF)
				{
					printf ("%c", currentEvaluatedChar);
                    currentEvaluatedChar = fgetc(file);
                }  
                fclose(file);
			}
			}
			else
			{
				fprintf(stderr, "%s failed: opening %s: error is: selected path is not a regular file or program failed to find it", argv[0], argv[currentArgument]);

			}
		}
		
	}
	else
	{
	printf("cat without arguments does not make sense\n");
	}
}