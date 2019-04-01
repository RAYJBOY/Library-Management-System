#include"interface.h"

int userChoice;
int librarianChoice;
char tempBookName[20];
char tempAuthorName[20];
char bookToRemove[20];
int numberofBooks;

void startingPoint(){

  printf("Welcome to my Library Management System!");

  do{
    printf("\n\nChoose an option below\n1)Librarian\n2)Student\n3)Quit\nAnswer: ");
    scanf("%d",&userChoice);

    if(userChoice == 1){

      do
      {
          printf("\n\nChoose what you want to do\n0)Back to menu\n1)Add a book to the library\n2)Remove a book from the library\n3)List all registered students\n4)List all books in the library\n5)Search for student\nAnswer: ");
          scanf("%d",&librarianChoice);
          if(librarianChoice == 1)
          {
            getchar();
            printf("Enter book name: ");
            fgets(tempBookName,20,stdin);

            printf("Enter author name: ");
            fgets(tempAuthorName,20,stdin);

            printf("Enter the number of books: ");
            scanf("%d", &numberofBooks);

            addNewBook(tempBookName,tempAuthorName, numberofBooks);
            printf("Done!");
            fflush(stdin);
            continue;
          }

          else if(librarianChoice == 2)
          {
            getchar();
            printf("Enter the book name: ");
            fgets(bookToRemove,20,stdin);
            removeBook(bookToRemove);
          }

          else if(librarianChoice == 3)
          {
            listStudents();
          }

          else if(librarianChoice == 4)
          {
            listBooks();
          }


      }while(librarianChoice != 0);


    }


}while(userChoice != 3);
}
