#include "listing.h"


extern int indexOfBookArray;
extern BookStructure* bookArray;
extern StudentStructure* studentArray;
extern int indexOfStudentArray;



void listBooks()
{
  int i;

  printf("----------------------------Books so far---------------------------\n");
  for(i = 0; i<=indexOfBookArray; i++)
  {
    if(bookArray[i].bookNumber!=0)
    {
      printf("\nBook name: %s", bookArray[i].bookName);
      printf("Author name: %s", bookArray[i].authorName);
      printf("Number of books: %d\n", bookArray[i].bookNumber);
    }
  }

  printf("-------------------------------------------------------------------\n");

}


void listStudents()
{
  int i;

  printf("----------------------------Students so far---------------------------\n");
  for(i = 0; i<=indexOfStudentArray; i++)
  {
    printf("\nStudent name: %s", studentArray[i].studentName);
    printf("Student ID: %d", studentArray[i].studentID);
    printf("Book borrowed: %s\n", studentArray[i].bookBorrowed);
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
  BookStructure* bookToPrint = searchBook(NameOfBook);
  printf("\nBook name: %s", bookToPrint->bookName);
  printf("\nAuthor name: %s", bookToPrint->authorName);
  printf("\nAmount of books: %d", bookToPrint->bookNumber);

}

void printSearchedStudent(int stdID)
{
  StudentStructure* studentToPrint = searchStudent(stdID);
  printf("\nStudent name: %s", studentToPrint->studentName);
  printf("\nStudent ID: %d", studentToPrint->studentID);
  printf("\nBook Borrowed: %s", studentToPrint->bookBorrowed);

}
