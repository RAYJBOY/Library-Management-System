#include "addToLibrary.h"
#include "unity/unity.h"

extern BookStructure* bookArray;
extern StudentStructure* studentArray;
extern int indexOfBookArray;
extern int indexOfStudentArray;

void test_addNewBookToLibrary(){ //DONE

  addNewBook("Harry Potter", "J.K Rowling", 5);

  TEST_ASSERT_EQUAL_STRING("Harry Potter", bookArray[0].bookName);
  TEST_ASSERT_EQUAL_STRING("J.K Rowling", bookArray[0].authorName);
  TEST_ASSERT_EQUAL_INT(5, bookArray[0].bookNumber);

}





void test_add_same_book(){ //DONE

  addNewBook("Sherlock Holmes", "Arthur Conan", 3);
  addNewBook("Sherlock Holmes", "Arthur Conan", 4);


  TEST_ASSERT_EQUAL_INT_MESSAGE(7, bookArray[1].bookNumber, "System added the same book as 2 different items"); //might have to change the index of the array depeneding if test resets the entire program.
}





void test_does_not_add_0_books(){ //DONE

  int i;
  int j = 5;
  addNewBook("Lorean Legacies", "Pittacus Lore", 0);


  for(i = 0; i<=indexOfBookArray; i++)
  {
    if(strcmp("Lorean Legacies", bookArray[i].bookName) == 0)
    {
      j = 1;
    }

    else
    {
      j = 0;
    }

  }

  TEST_ASSERT_EQUAL_INT_MESSAGE(0, j, "Added book when 0 books were to be added!"); //might have to change the index of the array depeneding if test resets the entire program.
}





void register_student_to_library(){ //DONE

  registerStudent(506, "Rajesh Gupta");
  TEST_ASSERT_EQUAL_STRING_MESSAGE("Rajesh Gupta", studentArray[0].studentName, "Entered wrong name into library!");
  TEST_ASSERT_EQUAL_INT_MESSAGE(506, studentArray[0].studentID, "Wrong student ID in library");

}





void invalid_student_ID(){ //DONE

  registerStudent(-907, "Hamza Imam");
  registerStudent(-543, "Jay");

  int i, j = 5;
  for(i = 0; i<=indexOfStudentArray; i++)
  {
    if(strcmp("Jay", studentArray[i].studentName) == 0){
      j = 0; //if "Jay" is there, j is 0.
      break;
    }

    else{
      j = 1;
    }
  }
  TEST_ASSERT_EQUAL_INT_MESSAGE(1,j, "Registered student with invalid ID!");

}





void register_same_student_twice(){ //DONE

  registerStudent(786, "Hamza");
  registerStudent(676, "Hamza");

  int i, j=0;

  for(i=0;i<=indexOfStudentArray;i++)
  {
    if(strcmp("Hamza", studentArray[i].studentName) == 0){
      j++;
    }
  }

  TEST_ASSERT_EQUAL_INT_MESSAGE(1,j,"Same student inserted twice with different IDs");
}





void register_student_with_same_ID(){ //DONE

  registerStudent(555, "Person 1");
  registerStudent(555, "Person 2");

  int i, j = 0;

  for(i=0;i<=indexOfStudentArray;i++){
    if(studentArray[i].studentID == 555){
      j++;
    }
  }

  TEST_ASSERT_EQUAL_INT_MESSAGE(1,j,"Inserted different person with same ID");


}



void borrow_correct_book(){

  int i;

  registerStudent(854,"RAYJBOI");
  addNewBook("A Book I Like", "Some Random Author", 3);
  borrowBook("RAYJBOI", "A Book I Like");

  for(i=0; i<=indexOfStudentArray; i++)
  {
    if(strcmp(studentArray[i].studentName, "RAYJBOI") == 0)
    {
      if(strcmp(studentArray[i].bookBorrowed, "A Book I Like") == 0)
      {
        i = 1;
      }
    }
  }

  TEST_ASSERT_EQUAL_INT_MESSAGE(1,i,"Student couldn't borrow book!");


}





void borrow_invalid_book(){ //DONE

  registerStudent(654, "Hamza Imam");
  borrowBook("Hamza Imam", "A Book I Like");

  int i;
  int check;

  for(i = 0; i<=indexOfStudentArray; i++)
  {
    if(strcmp(studentArray[i].bookBorrowed, "A Book I Like") == 0)
    {
      check = 1;
    }

    else
    {
      check = 5;
    }
  }

  TEST_ASSERT_EQUAL_INT_MESSAGE(5,check, "Student borrowed a book that doesn't exist!");

}



void setUp (void){}

void tearDown (void){}

int main (void){

  UNITY_BEGIN();

  RUN_TEST(test_addNewBookToLibrary);
  RUN_TEST(test_add_same_book);
  RUN_TEST(test_does_not_add_0_books);
  RUN_TEST(register_student_to_library);
  RUN_TEST(invalid_student_ID);
  RUN_TEST(register_same_student_twice);
  RUN_TEST(register_student_with_same_ID);
  RUN_TEST(borrow_invalid_book);
  RUN_TEST(borrow_correct_book);



  return UNITY_END();
}
