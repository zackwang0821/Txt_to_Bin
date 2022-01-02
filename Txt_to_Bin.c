#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

size_t ReadTxtFile(FILE *inf, unsigned char *dest, FILE *outfile) 
{
    size_t count = 0;
    int n;
    unsigned char OneByte;
    
    if (dest == NULL) 
    {  
             
        while ((n = fscanf(inf, "%hhx", &OneByte)) == 1 ) 
        {
          //printf("%x\n",OneByte);
           
          fwrite(&OneByte, sizeof(unsigned char), 1, outfile);
          count++;
        }
    }
  
    if (n != EOF) 
    {
        ;  // handle syntax error
    }
    
    //printf("count=%d\n",count);
    return count;
}

int main() 
{
    char name[80];
    
	printf("Enter the file name:");
	scanf("%s", name);


    //FILE *FileIn = fopen("1.txt", "rt");   
	FILE* FileIn = fopen(name, "rt");  
    if (!FileIn) 
    {
        fclose(FileIn);
        return -1;
    }
    
    
    FILE* FileOut = fopen("fileOut.bin","wb+");
    
    if (!FileOut) 
    {
        fclose(FileOut);
        return -1;
    }
    
    
    size_t n = ReadTxtFile(FileIn, NULL, FileOut);
    
    
    rewind(FileIn);
  
    
    fclose(FileIn);
    fclose(FileOut);
    
    //system("PAUSE");
    return 0;
 }
