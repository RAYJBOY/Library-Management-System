#include "addToLibrary.h"


int indexOfBookArray = -1;
int indexOfStudentArray = -1;
int maxBookIndex = 2;
int maxStudentIndex = 2;
BookStructure* bookArray;
StudentStructure* studentArray;





int addNewBook(char* nameOfBook, char* nameOfAuthor, int numberOfBooks)//1 for fine, 0 for something went wrong
{
  int indexOfBook;

  for(indexOfBook = 0; indexOfBook<=indexOfBookArray; indexOfBook++)
  {
    if(strcmp(bookArray[indexOfBook].bookName, nameOfBook) == 0 && strcmp(bookArray[indexOfBook].authorName, nameOfAuthor) == 0) //if its the same author and book name, number is just added
    {
      bookArray[indexOfBook].bookNumber = bookArray[indexOfBook].bookNumber + numberOfBooks;
      return 1;
    }
  }

  if(numberOfBooks == 0){
    return 0;
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
      return 1;
    }

    else if(indexOfBookArray == maxBookIndex-1) //if array becomes full, reallocated to another bigger array
    {
      maxBookIndex+=2;
      indexOfBookArray++;
      bookArray = (BookStructure*)realloc(bookArray, maxBookIndex*sizeof(BookStructure));
      strcpy(bookArray[indexOfBookArray].bookName, nameOfBook);
      strcpy(bookArray[indexOfBookArray].authorName, nameOfAuthor);
      bookArray[indexOfBookArray].bookNumber = numberOfBooks;
      return 1;
    }

    else{
      indexOfBookArray++;
      strcpy(bookArray[indexOfBookArray].bookName, nameOfBook);
      strcpy(bookArray[indexOfBookArray].authorName, nameOfAuthor);
      bookArray[indexOfBookArray].bookNumber = numberOfBooks;
      return 1;
    }
  }

}

//----------------------------------------------------------------------------------------------------------------

int registerStudent(int student_ID, char* nameOfStudent){ //1 for fine, 0 for student already exists, 2 for ID already exists, 3 for invalid ID
  int i; //used in the for loop below

  for(i = 0; i<=indexOfStudentArray; i++) //checks if the same student name is already present in the array
  {
    if(strcmp(studentArray[i].studentName, nameOfStudent) == 0)
    {
      return 0;
    }
  }

  for(i=0; i<=indexOfStudentArray; i++) //prevents 2 students with same ID to register
  {
    if(studentArray[i].studentID == student_ID)
    {
      return 2;
    }
  }

  if(student_ID<0) //if the student_ID is invalid, it returns to caller.
  {
    return 3;
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

int borrowBook(char* nameOfStudent, char* nameOfBook)//1 for fine, 0 for already has book, 2 for book not in library, 3 for student not in library
{
  int studentIndex;
  int bookIndex;
  int amountOfBooks;
  int referenceBookIndex;
  int referenceStudentIndex;
  int studentCheck;


  for(studentIndex = 0; studentIndex<=indexOfStudentArray; studentIndex++)
  {

    if(strcmp(studentArray[studentIndex].studentName, nameOfStudent) == 0)
    {
      if(strcmp(studentArray[studentIndex].bookBorrowed, "") != 0) //if student already has a book borrowed, he cannot borrow another one.
      {
        return 0;
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
    return 2;
  }


  else if(amountOfBooks != 0) //if there are books in the library
  {

    for(studentIndex = 0; studentIndex<=indexOfStudentArray; studentIndex++)
    {
      if(strcmp(studentArray[studentIndex].studentName, nameOfStudent) == 0) //finds the student who requested the book
      {
        studentCheck = 1;
        strcpy(studentArray[studentIndex].bookBorrowed, nameOfBook); //gives him/her the book
        for(referenceBookIndex = 0; referenceBookIndex<=indexOfBookArray; referenceBookIndex++)
        {
          if(strcmp(bookArray[referenceBookIndex].bookName, nameOfBook) == 0) //finds the book in the book array
          {
            bookArray[referenceBookIndex].bookNumber--; //reduces the number of copies in the book array
            return 1;
          }
        }
      }
      else{
        studentCheck = 0;
      }
    }
    if(studentCheck == 0){
      return 3;
    }
  }

}

//----------------------------------------------------------------------------------------------------------------

int returnBook(int studID, char* bookToReturn)
{

  int i;
  int j;
  int correctDetail; //1 for correct details, 0 for wrong details, 2 for book not in library, 3 for returning wrong book

  for(i=0;i<=indexOfStudentArray;i++)
  {
    if(studentArray[i].studentID == studID && strcmp(studentArray[i].bookBorrowed,bookToReturn) == 0) //checks if student is returning correct book
    {
      correctDetail = 1;
      for (j=0;j<=indexOfBookArray;j++)
      {
        if(strcmp(bookArray[j].bookName, bookToReturn) == 0) //sees where the book is in the library
        {
          bookArray[j].bookNumber++;
          strcpy(studentArray[i].bookBorrowed,""); //after returning book, student has nothing left
          return 1;
        }
        else
        {
          correctDetail = 2;
        }
      }

      if(correctDetail == 2)
      {
        return 3;
      }

    }
    else //wrong details
    {
      correctDetail = 0;
    }
  }

  if(correctDetail == 0)
  {
    return 0;
  }
}


int removeBook(char* bookTitle, int amount){

  int i;
  int bookInLibrary; //checks whether the book being removed is in library

  for(i=0;i<=indexOfBookArray;i++)
  {
    if(strcmp(bookArray[i].bookName, bookTitle) == 0)
    {
      bookInLibrary = 1;
      bookArray[i].bookNumber = bookArray[i].bookNumber-amount;
      if(bookArray[i].bookNumber<0)
      {
        bookArray[i].bookNumber = 0;
      }
      break;
    }
    else
    {
      bookInLibrary = 0;
    }
  }
  return bookInLibrary;
}
