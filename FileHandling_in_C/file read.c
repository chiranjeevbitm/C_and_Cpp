#include <stdio.h>
#include <stdlib.h>
int main() {

  FILE *fileptr;
  int count_lines = 0;
  int count_chars = 0;
  int count_words = 0;
  char chr;

  fileptr = fopen("/Users/chiranjeev/Documents/C_and_Cpp/FileHandling_in_C/program6.txt","r");
//  printf("%d\n",fileptr );
  // extract character from file and store in chr
  chr = getc(fileptr);
  while (chr != EOF) {
    // Count whenever new line is encountered
    if (chr == 'n') {
      count_lines = count_lines + 1;
    }
    if (chr == ' ' || chr == '\n') {
      count_words = count_words + 1;
    }
    // take next character from file.
    chr = getc(fileptr);
    count_chars = count_chars + 1;
  }
  fclose(fileptr); // close file.
  printf("There are %d lines in the file\n", count_lines + 1);
  printf("There are %d characters in the file\n", count_chars);
  printf("There are %d words in the file\n", count_words);

  return 0;
}
