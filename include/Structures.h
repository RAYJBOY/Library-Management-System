#ifndef myStructures
#define myStructures

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>


struct studentStructure {
  int studentID;
  char bookBorrowed[20];
  char studentName[20];
};
typedef struct studentStructure StudentStructure;


struct bookStructure {
  char bookName[20];
  char authorName[20];
  int bookNumber;
};

typedef struct bookStructure BookStructure;



#endif
