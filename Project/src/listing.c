#include "listing.h"


extern int indexOfBookArray;
extern BookStructure* bookArray;
extern StudentStructure* studentArray;
extern int indexOfStudentArray;



void listBooks() //lists all books in the library in a separate file called "listBooks.txt"
{
  int i;
  FILE *fptr;
  fptr = fopen("bookList.txt","w"); //opens in write mode to edit the file

  fprintf(fptr, "%s","\t\t\t\t\tList Of All Books\n\n\n");

  fprintf(fptr, "----------------------------------------------------------------------------------------------\n");
  fprintf(fptr, "|\t %-20s|\t\t %-20s|\t\t %-20s|\n", "Book Name", "Author Name", "Amount");
  fprintf(fptr, "----------------------------------------------------------------------------------------------\n");


  for(i=0;i<=indexOfBookArray;i++)
  {
    if(bookArray[i].bookNumber!=0) //prints details of all books that are available in the library
    {
      char tempBookName[strlen(bookArray[i].bookName)];
      char tempAuthorName[strlen(bookArray[i].authorName)];
      strcpy(tempBookName, bookArray[i].bookName);
      strcpy(tempAuthorName, bookArray[i].authorName);
      tempBookName[strlen(tempBookName)-1] = '\0';
      tempAuthorName[strlen(tempAuthorName)-1] = '\0';
      fprintf(fptr, "|\t %-20s|\t\t %-20s|\t\t %-20d|\n", tempBookName, tempAuthorName, bookArray[i].bookNumber);
      fprintf(fptr, "----------------------------------------------------------------------------------------------\n");
    }

  }
  fclose(fptr); //closes the file after done

}


void listStudents() //prints student details in a separate file called "studentList.txt"
{
  int i;
  FILE *fptr;
  fptr = fopen("studentList.txt","w");

  fprintf(fptr, "%s","\t\t\t\t\tList Of All Students\n\n\n");

  fprintf(fptr, "----------------------------------------------------------------------------------------------\n");
  fprintf(fptr, "|\t %-20s|\t\t %-20s|\t\t %-20s|\n", "Student Name", "Student ID", "Book Borrowed");
  fprintf(fptr, "----------------------------------------------------------------------------------------------\n");


  for(i=0;i<=indexOfStudentArray;i++) //prints out all details of students in the library
  {
    char tempStudentName[strlen(studentArray[i].studentName)+1];
    char tempBookBorrowed[strlen(studentArray[i].bookBorrowed)+1];
    strcpy(tempStudentName, studentArray[i].studentName);
    strcpy(tempBookBorrowed, studentArray[i].bookBorrowed);
    tempStudentName[strlen(tempStudentName)-1] = '\0';
    tempBookBorrowed[strlen(tempBookBorrowed)-1] = '\0';
    fprintf(fptr, "|\t %-20s|\t\t %-20d|\t\t %-20s|\n", tempStudentName, studentArray[i].studentID, tempBookBorrowed);
    fprintf(fptr, "----------------------------------------------------------------------------------------------\n");
  }
  fclose(fptr); //closes file after done

}



BookStructure* searchBook(char* BookName) //returns a pointer to the struct of the searched book
{
  int i;

  for(i=0;i<=indexOfBookArray;i++)
  {
    if(strcmp(bookArray[i].bookName, BookName) == 0){
      return (bookArray+i);
    }
  }
}



StudentStructure* searchStudent(int StudentID) //returns a pointer to the struct of the searched student
{
  int i;

  for(i=0;i<=indexOfStudentArray;i++)
  {
    if(studentArray[i].studentID == StudentID){
      return (studentArray+i);
    }
  }
}


void printSearchedBook(char* NameOfBook) //prints the searched book
{
  BookStructure* bookToPrint = searchBook(NameOfBook);
  printf("\nBook name: %s", bookToPrint->bookName);
  printf("Author name: %s", bookToPrint->authorName);
  printf("Amount of books: %d", bookToPrint->bookNumber);

}

void printSearchedStudent(int stdID) //prints the searched student
{
  StudentStructure* studentToPrint = searchStudent(stdID);
  printf("\nStudent name: %s", studentToPrint->studentName);
  printf("Student ID: %d", studentToPrint->studentID);
  printf("\nBook Borrowed: %s", studentToPrint->bookBorrowed);

}

void memFree() //frees all memory before terminating
{
  free(studentArray);
  free(bookArray);
}
