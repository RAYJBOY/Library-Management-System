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

  printf("\nWelcome to my Library Management System!\n");

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

            if(addNewBook(tempBookName,tempAuthorName, numberofBooks) == 1)
            {
              printf("Done!\n");
            }

            else{
              printf("\nSomething went wrong...\n");
            }

            fflush(stdin);
            continue;
          }

          else if(librarianChoice == 2)
          {
            getchar();
            printf("Enter the book name: ");
            fgets(bookToRemove,20,stdin);
            //removeBook(bookToRemove);

            if(removeBook(bookToRemove) == 0)
            {
              printf("\nBook not in library!\n");
            }

            else{
              printf("\nBook removed!\n");
            }
          }

          else if(librarianChoice == 3)
          {
            listStudents();
          }

          else if(librarianChoice == 4)
          {
            listBooks();
          }

          else if(librarianChoice == 5)
          {
            int IDOfStudent;
            printf("Enter the student ID: ");
            scanf("%d", &IDOfStudent);
            StudentStructure* studentDetails = searchStudent(IDOfStudent);
            printf("\nStudent details...\n");
            printf("Student name: %s", studentDetails->studentName);
            printf("\nStudent ID: %d", studentDetails->studentID);
            printf("\nBook borrowed: %s", studentDetails->bookBorrowed);
            printf("\n");
          }


      }while(librarianChoice != 0);


    }

    else if(userChoice == 2)
    {
      int check;
      do
      {
          printf("\n\nChoose what you want to do\n0)Back to menu\n1)Register to library\n2)List all books in library\n3)Search for book\n4)Borrow a book\n5)Return a book\nAnswer: ");
          scanf("%d",&studentChoice);
          if(studentChoice == 1)
          {
            getchar();
            printf("Enter student name: ");
            fgets(tempStudentName,20,stdin);

            printf("Enter student ID: ");
            scanf("%d", &tempID);

            check = registerStudent(tempID,tempStudentName);

            if(check == 1){
              printf("\nDone!\n");
            }

            else if(check == 0){
              printf("\nStudent is already registered!\n");
            }

            else if(check == 2){
              printf("\nStudent ID taken!\n");
            }

            else if(check == 3){
              printf("\nInvalid ID!\n");
            }

            fflush(stdin);
            continue;
          }

          else if(studentChoice == 2)
          {
            listBooks();
          }

          else if(studentChoice == 3)
          {
            getchar();
            printf("Enter the book name: ");
            fgets(tempBookName,20,stdin);
            BookStructure* bookDetails = searchBook(tempBookName);
            printf("\nBook details...\n");
            printf("\nName of book: %s",bookDetails->bookName);
            printf("\nName of author: %s",bookDetails->authorName);
            printf("\nAmount: %d", bookDetails->bookNumber);
            printf("\n");
          }

          else if(studentChoice == 4)
          {
            int check;
            getchar();
            printf("Enter your name: ");
            fgets(tempStudentName,20,stdin);
            printf("Enter book name: ");
            fgets(tempBookName,20,stdin);
            check = borrowBook(tempStudentName,tempBookName);

            if(check == 1){
              printf("\nDone\n");
            }

            else if(check == 0){
              printf("\nStudent cannot borrow 2 books at the same time!\n");
            }

            else if(check == 2){
              printf("\nBook is not in library!\n");
            }

            else if(check == 3){
              printf("\nStudent is not registered!\n");
            }
          }

          else if(studentChoice == 5)
          {
            int check;
            getchar();
            printf("Enter your ID: ");
            scanf("%d", &tempID);
            getchar();
            printf("Enter book name: ");
            fgets(tempBookName,20,stdin);
            check = returnBook(tempID,tempBookName);

            if(check == 1){
              printf("\nDone!\n");
            }

            else if(check == 0){
              printf("\nIncorrect details!\n");
            }

            else if(check == 2){
              printf("\nYou cannot return a book that is not in the library!\n");
            }

            else if(check == 3){
              printf("\nYou cannot return a book you have not borrowed!\n");
            }
          }


      }while(studentChoice != 0);

    }


}while(userChoice != 3);
}
