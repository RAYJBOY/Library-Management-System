#include"interface.h"

int userChoice;
int librarianChoice;
int studentChoice;
char tempBookName[20];
char tempAuthorName[20];
char bookToRemove[20];
int numberofBooks;
char tempStudentName[20];
int tempID;

void startingPoint(){

  printf("\nWelcome to my Library Management System!\nNOTES:\n1)Students must register to library before borrowing books\n2)Students can borrow a maximum of 1 book at a time\n3)All details must be written exactly as stated previously (this program is not case sensitive)\n\n"); //the starting message

  do{
    printf("\n\nChoose an option below\n1)Librarian\n2)Student\n3)Quit\nAnswer: "); //allows the user to select librarian or student
    scanf("%d",&userChoice);

    if(userChoice == 1){ //if librarian...

      do
      {
          printf("\n\nChoose what you want to do\n0)Back to menu\n1)Add a book to the library\n2)Remove a book from the library\n3)List all registered students\n4)List all books in the library\n5)Search for student\nAnswer: ");
          scanf("%d",&librarianChoice);
          if(librarianChoice == 1) //if he/she wants to add a book to the library
          {
            getchar();
            printf("Enter book name: ");
            fgets(tempBookName,20,stdin);

            printf("Enter author name: ");
            fgets(tempAuthorName,20,stdin);

            printf("Enter the number of books: ");
            scanf("%d", &numberofBooks);

            int checkerror = addNewBook(tempBookName,tempAuthorName, numberofBooks); //sends the input to addNewBook function in addToLibrary.c

            if(checkerror == 1) //if everything was fine...
            {
              printf("Done!\n");
            }

            else if(checkerror == 0) //if not...
            {
              printf("\nSomething went wrong...\n");
            }

            fflush(stdin); //cleares the buffer
            continue;
          }

          else if(librarianChoice == 2) //if librarian wants to remove a book
          {
            int booksToRemove;
            getchar(); //used to clear the \n from buffer
            printf("Enter the book name: ");
            fgets(bookToRemove,20,stdin);
            printf("Number of books to be removed: ");
            scanf("%d", &booksToRemove);

            if(removeBook(bookToRemove, booksToRemove) == 0) //sends input to removeBook function
            {
              printf("\nBook not in library!\n"); //if book not in library
            }

            else{
              printf("\nBook removed!\n"); //if everything was fine
            }
          }

          else if(librarianChoice == 3) //if librarian wants to list all student
          {
            listStudents(); //listStudents function called
          }

          else if(librarianChoice == 4) //if librarian wants to list all the books, listBooks called
          {
            listBooks();
          }

          else if(librarianChoice == 5) //if librarian wants to search fro student...
          {
            int IDOfStudent;
            printf("Enter the student ID: ");
            scanf("%d", &IDOfStudent);
            StudentStructure* studentDetails = searchStudent(IDOfStudent);
            printf("\nStudent details...\n");
            printf("Student name: %s", studentDetails->studentName); //details printed out on screen
            printf("Student ID: %d", studentDetails->studentID);
            printf("\nBook borrowed: %s", studentDetails->bookBorrowed);
            printf("\n");
          }


      }while(librarianChoice != 0);


    }

    else if(userChoice == 2) //if user is a student
    {
      int check;
      do
      {
          printf("\nSTUDENTS MUST FIRST REGISTER TO LIBRARY BEFORE BORROWING ANY BOOKS!"); //instructs student to register to library before doing anything else
          printf("\n\nChoose what you want to do\n0)Back to menu\n1)Register to library\n2)List all books in library\n3)Search for book\n4)Borrow a book\n5)Return a book\nAnswer: ");
          scanf("%d",&studentChoice);
          if(studentChoice == 1) //if students wants to register to library...
          {
            getchar();
            printf("Enter student name: ");
            fgets(tempStudentName,20,stdin);

            printf("Enter student ID: ");
            scanf("%d", &tempID);

            check = registerStudent(tempID,tempStudentName); //details sent to registerStudent in addToLibrary

            if(check == 1){ //if everything was ok
              printf("\nDone!\n");
            }

            else if(check == 0){ //if that student is already there
              printf("\nStudent is already registered!\n");
            }

            else if(check == 2){ //prevents 2 student from having same ID
              printf("\nStudent ID taken!\n");
            }

            else if(check == 3){ //cannot have a negative ID
              printf("\nInvalid ID!\n");
            }

            fflush(stdin); //clears buffer
            continue;
          }

          else if(studentChoice == 2)
          {
            listBooks(); //if student wants to list books
          }

          else if(studentChoice == 3) //if student wants to search for book
          {
            getchar();
            printf("Enter the book name: ");
            fgets(tempBookName,20,stdin);
            BookStructure* bookDetails = searchBook(tempBookName);
            printf("\nBook details...\n");
            printf("\nName of book: %s",bookDetails->bookName);
            printf("Name of author: %s",bookDetails->authorName);
            printf("Amount: %d", bookDetails->bookNumber);
            printf("\n");
          }

          else if(studentChoice == 4) //if student wants to borrow book
          {
            int check;
            getchar();
            printf("Enter your name: ");
            fgets(tempStudentName,20,stdin);
            printf("Enter book name: ");
            fgets(tempBookName,20,stdin);
            check = borrowBook(tempStudentName,tempBookName);

            if(check == 1){ //if everything went ok
              printf("\nDone\n");
            }

            else if(check == 0){ //if student already has a book borrowed
              printf("\nStudent cannot borrow 2 books at the same time!\n");
            }

            else if(check == 2){ //if book is not in library
              printf("\nBook is not in library!\n");
            }

            else if(check == 3){ //if student hasn't registered
              printf("\nStudent is not registered!\n");
            }
          }

          else if(studentChoice == 5) //if student wants to return a book
          {
            int check;
            getchar();
            printf("Enter your ID: ");
            scanf("%d", &tempID);
            getchar();
            printf("Enter book name: ");
            fgets(tempBookName,20,stdin);
            check = returnBook(tempID,tempBookName); //details sent to returnBook

            if(check == 1){ //if everything went ok
              printf("\nDone!\n");
            }

            else if(check == 0){ //if there were incorrect details
              printf("\nIncorrect details!\n");
            }

            else if(check == 2){ //if students wants to borrow a book not in library
              printf("\nYou cannot return a book that is not in the library!\n");
            }

            else if(check == 3){ //if student returns a book not in library
              printf("\nYou cannot return a book you have not borrowed!\n");
            }
          }


      }while(studentChoice != 0);

    }


}while(userChoice != 3);

  memFree(); //frees all memory allocations bfore terminating
}
