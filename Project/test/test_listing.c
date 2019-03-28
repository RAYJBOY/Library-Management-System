#include "addToLibrary.h"
#include "listing.h"
#include "unity/unity.h"

extern BookStructure* bookArray;
extern StudentStructure* studentArray;
extern int indexOfBookArray;
extern int indexOfStudentArray;

void search_correct_book(){

  addNewBook("Into The Wormhole", "Morgan Freeman", 3);
  BookStructure* myPointer;
  myPointer = searchBook("Into The Wormhole");
  TEST_ASSERT_EQUAL_STRING("Into The Wormhole", myPointer->bookName);
  TEST_ASSERT_EQUAL_STRING("Morgan Freeman", myPointer->authorName);
  TEST_ASSERT_EQUAL_INT(3, myPointer->bookNumber);

}


void search_correct_student(){

  registerStudent(550, "SomeGUY");
  addNewBook("WW2", "John Weasley", 3);
  borrowBook("SomeGUY", "WW2");

  StudentStructure* studentPointer;
  studentPointer = searchStudent(550);

  TEST_ASSERT_EQUAL_STRING("SomeGUY", studentPointer->studentName);
  TEST_ASSERT_EQUAL_STRING("WW2",studentPointer->bookBorrowed);
  TEST_ASSERT_EQUAL_INT(550, studentPointer->studentID);

}


void setUp (void){}

void tearDown (void){}

int main (void){

  UNITY_BEGIN();

  RUN_TEST(search_correct_book);
  RUN_TEST(search_correct_student);





  return UNITY_END();
}
