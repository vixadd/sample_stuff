#include <stdio.h>
#include <stdlib.h>

#define NUMLETTERS 26

// Struct to hold our letters.
typedef struct {
  char letter;
  int number;
} record_t;

// Main method to run all this shit.
int main(void) {

  // FILE object to hold a pointer to the CSV file.
  FILE *fp;

  // Create a list of structs.
  record_t records[NUMLETTERS];

  // Record the size of our struct list.
  size_t count = 0;

  // Open the CSV file.
  fp = fopen("./letters.csv", "r");

  // If the file doesn't exist then you're a pleb.
  if(fp == NULL) {
    fprintf(stderr, "you suck");
    return 1;
  }

  // scan everything from the CSV file into the records of structs.
  while (fscanf(fp, " %c,%d\n", &records[count].letter,
				&records[count].number) == 2) {
    printf("%zd  %zu \n", &records[count].letter, &records[count].number);
    count++;
  }

  printf("%zu \n",  count);

  // Print our current list of structs.
  for (size_t i=0; i<count ; i++) {
    printf("%c,%d\n", records[i].letter, records[i].number);
  }

  fclose(fp);

  return 0;
}
