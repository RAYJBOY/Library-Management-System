#ifndef addToLib
#define addToLib


//#include "removeFromLibrary.h"
#include "Structures.h"

int addNewBook(char* nameOfBook, char* nameOfAuthor, int numberOfBooks);
int registerStudent(int student_ID, char* nameOfStudent);
int borrowBook(char* nameOfStudent, char* nameOfBook);
int returnBook(int studID, char* bookToReturn);
int removeBook(char* bookTitle);




#endif
