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

BookStructure* searchBook(char* BookName)
{
  int i;

  for(i=0;i<=indexOfBookArray;i++)
  {
    if(strcmp(bookArray[i].bookName, BookName) == 0){
      return (bookArray+i);
    }
  }
}



StudentStructure* searchStudent(int StudentID)
{
  int i;

  for(i=0;i<=indexOfStudentArray;i++)
  {
    if(studentArray[i].studentID == StudentID){
      return (studentArray+i);
    }
  }
}


void printSearchedBook(char* NameOfBook)
{
  StudentStructure* bookToPrint = searchBook(NameOfBook);
  printf("\nBook name: %s", bookToPrint->bookName);
  printf("\nAuthor name: %s", bookToPrint->authorName);
  printf("\nAmount of books: %d", bookToPrint->bookNumber);

}
