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
    if(strcmp(bookArray[indexOfBook].bookName, nameOfBook) == 0 && strcmp(bookArray[indexOfBook].authorName, nameOfAuthor) == 0) //if its the same author and book name, book amount is just added
    {
      bookArray[indexOfBook].bookNumber = bookArray[indexOfBook].bookNumber + numberOfBooks;
      return 1; //everything went ok
    }
  }

  if(numberOfBooks == 0){
    return 0; //something is wrong if librarian adds 0 books
  }

  else if(numberOfBooks != 0)
  {
    if(indexOfBookArray == -1) //if first time entering a book, new array created and book added into array
    {
      bookArray = (BookStructure*)malloc(maxBookIndex*sizeof(BookStructure)); //craetes dynamic array for storing book structs
      indexOfBookArray++; //index incremented before book added
      strcpy(bookArray[indexOfBookArray].bookName, nameOfBook); //updates details of the book
      strcpy(bookArray[indexOfBookArray].authorName, nameOfAuthor);
      bookArray[indexOfBookArray].bookNumber = numberOfBooks;
      return 1; //everything went fine if book could be added
    }

    else if(indexOfBookArray == maxBookIndex-1) //if array becomes full, reallocated to another bigger array
    {
      maxBookIndex+=2;
      indexOfBookArray++;
      bookArray = (BookStructure*)realloc(bookArray, maxBookIndex*sizeof(BookStructure)); //reallocates the dynamic array if it gets full
      strcpy(bookArray[indexOfBookArray].bookName, nameOfBook); //updating details
      strcpy(bookArray[indexOfBookArray].authorName, nameOfAuthor);
      bookArray[indexOfBookArray].bookNumber = numberOfBooks;
      return 1; //if book details were updated, then everything went fine
    }

    else{ //if its not the first time and the array is not full
      indexOfBookArray++;
      strcpy(bookArray[indexOfBookArray].bookName, nameOfBook); //updating details
      strcpy(bookArray[indexOfBookArray].authorName, nameOfAuthor);
      bookArray[indexOfBookArray].bookNumber = numberOfBooks;
      return 1; //everything went ok
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
      return 0; //student already exists in library system
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
    studentArray = (StudentStructure*)malloc(maxStudentIndex*sizeof(StudentStructure)); //dynamic array to store student structs
    indexOfStudentArray++; //increment index before updating array
    strcpy(studentArray[indexOfStudentArray].studentName, nameOfStudent); //updates student details
    studentArray[indexOfStudentArray].studentID = student_ID;
  }

  else if(indexOfStudentArray == maxStudentIndex-1) //if the dynamic array for students is full
  {
    maxStudentIndex+=2; //increases the size for the new array
    indexOfStudentArray++;
    studentArray = (StudentStructure*)realloc(studentArray, maxStudentIndex*sizeof(StudentStructure)); //similar to book array reallocation
    strcpy(studentArray[indexOfStudentArray].studentName, nameOfStudent); //updates details
    studentArray[indexOfStudentArray].studentID = student_ID;
  }

  else{ //if its a normal entry
    indexOfStudentArray++;
    strcpy(studentArray[indexOfStudentArray].studentName, nameOfStudent); //updates student details
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
        return 0; //cannot borrow 2 books at the same time
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
      break; //if book found, breaks out of the for loop
    }

    else //if there are no books in the library with that name
    {
      amountOfBooks = 0;
    }

  }


  if(amountOfBooks == 0)
  {
    return 2; //if book is unavailable to be borrowed
  }


  else if(amountOfBooks != 0) //if there are books in the library
  {

    for(studentIndex = 0; studentIndex<=indexOfStudentArray; studentIndex++) //iterates through all students
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
      return 3; //student was not in library
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
      correctDetail = 1; //all details were fine
      for (j=0;j<=indexOfBookArray;j++)
      {
        if(strcmp(bookArray[j].bookName, bookToReturn) == 0) //sees where the book is in the library
        {
          bookArray[j].bookNumber++;
          strcpy(studentArray[i].bookBorrowed,""); //after returning book, student has nothing left
          return 1; //everyting went fine
        }
        else
        {
          correctDetail = 2;
        }
      }

      if(correctDetail == 2) //if book not in library
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
    if(strcmp(bookArray[i].bookName, bookTitle) == 0) //finds the book in the library
    {
      bookInLibrary = 1; //everything went fine
      bookArray[i].bookNumber = bookArray[i].bookNumber-amount;
      if(bookArray[i].bookNumber<0)
      {
        bookArray[i].bookNumber = 0; //if user removes more books than present, book number becomes 0
      }
      break;
    }
    else
    {
      bookInLibrary = 0; // something went wrong
    }
  }
  return bookInLibrary;
}
