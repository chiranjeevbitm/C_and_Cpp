#include<stdio.h>
#include<stdlib.h>
/*
int fseek(FILE *pointer, long int offset, int position)
pointer: pointer to a FILE object that identifies the stream.
offset: number of bytes to offset from position
position: position from where offset is added.

returns:
zero if successful, or else it returns a non-zero value
position defines the point with respect to which the file pointer needs to be moved. It has three values:
SEEK_END : It denotes end of the file.
SEEK_SET : It denotes starting of the file.
SEEK_CUR : It denotes file pointer’s current position.
*/
void main()
{
    FILE *fp;
    int len;
    fp = fopen("/Users/chiranjeev/Documents/Atom C and C++/FileHandling_in_C/test1.txt","r");
    if(fp==NULL)
    {
        printf("Error in opening file\n");
        exit(1);
    }
    fseek(fp,0,SEEK_END);
    len= ftell(fp);
    fclose(fp);
    printf("Total size of text1.txt file is %d bytes",len );
}
