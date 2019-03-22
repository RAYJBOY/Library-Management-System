#include "addToLibrary.h"


int indexOfBookArray = -1;
int indexOfStudentArray = -1;
int maxBookIndex = 2;
int maxStudentIndex = 2;
BookStructure* bookArray;
StudentStructure* studentArray;



void inaddToLibrary()
{
  printf("This is in addToLibrary\n");
}

void addNewBook(char* nameOfBook, char* nameOfAuthor, int numberOfBooks)
{
  int indexOfBook;

  for(indexOfBook = 0; indexOfBook<=indexOfBookArray; indexOfBook++)
  {
    if(strcmp(bookArray[indexOfBook].bookName, nameOfBook) == 0 && strcmp(bookArray[indexOfBook].authorName, nameOfAuthor) == 0) //if its the same author and book name, number is just added
    {
      bookArray[indexOfBook].bookNumber = bookArray[indexOfBook].bookNumber + numberOfBooks;
      return;
    }
  }

  if(numberOfBooks == 0){
    return;
  }

  else if(numberOfBooks != 0)
  {
    if(indexOfBookArray == -1) //if first time entering a book, new array created and book added into array
    {
      bookArray = (BookStructure*)malloc(maxBookIndex*sizeof(BookStructure));
      indexOfBookArray++;
      strcpy(bookArray[indexOfBookArray].bookName, nameOfBook);
      strcpy(bookArray[indexOfBookArray].authorName, nameOfAuthor);
      bookArray[indexOfBookArray].bookNumber = numberOfBooks;
    }

    else if(indexOfBookArray == maxBookIndex-1) //if array becomes full, reallocated to another bigger array
    {
      maxBookIndex+=2;
      indexOfBookArray++;
      bookArray = (BookStructure*)realloc(bookArray, maxBookIndex*sizeof(BookStructure));
      strcpy(bookArray[indexOfBookArray].bookName, nameOfBook);
      strcpy(bookArray[indexOfBookArray].authorName, nameOfAuthor);
      bookArray[indexOfBookArray].bookNumber = numberOfBooks;
    }

    else{
      indexOfBookArray++;
      strcpy(bookArray[indexOfBookArray].bookName, nameOfBook);
      strcpy(bookArray[indexOfBookArray].authorName, nameOfAuthor);
      bookArray[indexOfBookArray].bookNumber = numberOfBooks;
    }
  }

}

//----------------------------------------------------------------------------------------------------------------

void registerStudent(int student_ID, char* nameOfStudent){
  int i; //used in the for loop below

  for(i = 0; i<=indexOfStudentArray; i++) //checks if the same studeny name is already present in the array
  {
    if(strcmp(studentArray[i].studentName, nameOfStudent) == 0)
    {
      return;
    }
  }

  for(i=0; i<=indexOfStudentArray; i++) //prevents 2 students with same ID to register
  {
    if(studentArray[i].studentID == student_ID)
    {
      return;
    }
  }

  if(student_ID<0) //if the student_ID is invalid, it returns to caller.
  {
    return;
  }

  else if(indexOfStudentArray == -1) //if its the first time registering student.
  {
    studentArray = (StudentStructure*)malloc(maxStudentIndex*sizeof(StudentStructure));
    indexOfStudentArray++;
    strcpy(studentArray[indexOfStudentArray].studentName, nameOfStudent);
    studentArray[indexOfStudentArray].studentID = student_ID;
  }

  else if(indexOfStudentArray == maxStudentIndex-1) //if the dynamic array for students is full
  {
    maxStudentIndex+=2;
    indexOfStudentArray++;
    studentArray = (StudentStructure*)realloc(studentArray, maxStudentIndex*sizeof(StudentStructure));
    strcpy(studentArray[indexOfStudentArray].studentName, nameOfStudent);
    studentArray[indexOfStudentArray].studentID = student_ID;
  }

  else{ //if its a normal entry
    indexOfStudentArray++;
    strcpy(studentArray[indexOfStudentArray].studentName, nameOfStudent);
    studentArray[indexOfStudentArray].studentID = student_ID;
  }

}

//----------------------------------------------------------------------------------------------------------------

void borrowBook(char* nameOfStudent, char* nameOfBook)
{
  int studentIndex;
  int bookIndex;
  int amountOfBooks;
  int referenceBookIndex;
  int referenceStudentIndex;


  for(studentIndex = 0; studentIndex<indexOfStudentArray; studentIndex++)
  {

    if(strcmp(studentArray[studentIndex].studentName, nameOfStudent) == 0)
    {
      if(strcmp(studentArray[studentIndex].bookBorrowed, "") != 0) //if student already has a book borrowed, he cannot borrow another one.
      {
        return;
      }

      else{
        break;
      }
    }

  }


  for(bookIndex = 0; bookIndex<=indexOfBookArray; bookIndex++) //this, along with the if statement checks if the books the user wants exists in the library.
  {
    if(strcmp(bookArray[bookIndex].bookName, nameOfBook) == 0)
    {
      amountOfBooks = bookArray[bookIndex].bookNumber;
      break;
    }

    else //if there are no books in the library with that name
    {
      amountOfBooks = 0;
    }

  }


  if(amountOfBooks == 0)
  {
    return;
  }


  else if(amountOfBooks != 0) //if there are books in the library
  {

    for(studentIndex = 0; studentIndex<=indexOfStudentArray; studentIndex++)
    {
      if(strcmp(studentArray[studentIndex].studentName, nameOfStudent) == 0) //finds the student who requested the book
      {
        strcpy(studentArray[studentIndex].bookBorrowed, nameOfBook); //gives him/her the book
        for(referenceBookIndex = 0; referenceBookIndex<=indexOfBookArray; referenceBookIndex++)
        {
          if(strcmp(bookArray[referenceBookIndex].bookName, nameOfBook) == 0) //finds the book in the book array
          {
            bookArray[referenceBookIndex].bookNumber--; //reduces the number of copies in the book array
          }
        }
      }
    }
  }

}
//----------------------------------------------------------------------------------------------------------------
