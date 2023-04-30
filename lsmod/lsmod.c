#include "lsmod/liblsmod.h"

void lsmodValidation(int argc, char * argv[])
{
	if(argc <= 1)
	{
	FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    
    
    printf("Module\tSize\tUsed by\n");
    
    fp = fopen("/proc/modules", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
        int count = 0;
        char *token = strtok(line," ");
        
        while(token != NULL)
        {
           if((strcmp(token, "Live") != 0) && (strcmp(token, " - ") != 0))//count < 3)
           {
           printf("%s \t", token);
                token = strtok(NULL," ");
                count++;
           }
           else
           {
             printf("\n");
             break;
           }

        }
    }

    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
	}
	else
	{
	printf("not enabled to print lsmod with more options\n");
	}
}
