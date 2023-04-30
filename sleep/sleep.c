#include "libsleep.h"

void sleepCall(int seconds)
{
   sleep(seconds);
}

void sleepValidations(int argc, char * argv[])
{
   if(argc > 1)
   {
      if(strcmp(argv[1], "--help") == 0)
      {
        printf("printing sleep's help\n");
      }
	  else if(strcmp(argv[1], "--version") == 0)
      {
        printf("printing sleep's version\n");
      }	  
      else
      {
      for(int i = 1; i < argc; i++)
	  {
	  
      if(isNumber(argv[i]))
      {      
         int seconds = atoi((argv[i]));
         if(!seconds && argv[i] != "0" ) 
            {
               // error 
               printf("sleep invalid option\n");
            } 
         else 
            {
               // great success!
               if(seconds <= 0)
                 {
                     printf("cant execute sleep on negative numbers\n");
                 }
               else
                 {
                    printf("sleeping for %d seconds\n", seconds);
                    sleepCall(seconds);
                    printf("done sleeping\n");
                 }

            }
       
       }
       else
       {       
          printf("Argument not valid\n");
       }
	  }
      
      }
   }
   else
   {
    printf("sleep without arguments has no meaning\n");
   }
   
}
