#include "listing.h"


extern int indexOfBookArray;
extern BookStructure* bookArray;
extern StudentStructure* studentArray;
extern int indexOfStudentArray;
extern int indexOfStudentArray;

void inListing()
{
  printf("In listing\n");
}

void listBooks()
{
  int i;

  printf("----------------------------Books so far---------------------------\n");
  for(i = 0; i<=indexOfBookArray; i++)
  {
    printf("\nBook name: %s", bookArray[i].bookName);
    printf("Author name: %s", bookArray[i].authorName);
    printf("Number of books: %d\n", bookArray[i].bookNumber);
  }

  printf("-------------------------------------------------------------------\n");


}
