#include <stdio.h>
int main()
{
    char ch;

    /* Pointer for both the file*/
    FILE *fpr, *fpw;
    /* Opening file FILE1.C in “r” mode for reading */
    fpr = fopen("/Users/chiranjeev/Documents/Atom C and C++/FileHandling_in_C/test1.txt", "r");


    /* Ensure FILE1.C opened successfully*/
    if (fpr == NULL)
    {
         puts("Input file cannot be opened");
    }

    /* Opening file FILE2.C in “w” mode for writing*/
    fpw= fopen("/Users/chiranjeev/Documents/Atom C and C++/FileHandling_in_C/test2.txt", "w");

    /* Ensure FILE2.C opened successfully*/
    if (fpw == NULL)
    {
       puts("Output file cannot be opened");
    }

    /*Read & Write Logic*/
    while(1)
    {
        ch = fgetc(fpr);
        if (ch==EOF)
            break;
        else
            fputc(ch, fpw);
    }

    /* Closing both the files */
    fclose(fpr);
    fclose(fpw);

    printf("Text from test1.txt is copied to test2.txt\n");
    return 0;
}
