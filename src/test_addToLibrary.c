#include "addToLibrary.h"


void test_addNewBook_1(){

  addNewBook("Harry Potter", "J.K Rowling", 5);

  //TEST_ASSERT_EQUAL_STRING("Harry Potter", bookArray[0].bookName);
  //TEST_ASSERT_EQUAL_STRING("J.K Rowling", bookArray[0].authorName);
  TEST_ASSERT_EQUAL_INT("Harry Potter", bookArray[0].bookNumber);

}

void test_addNewBook_2(){

  addNewBook("Sherlock Holmes", "Arthur Conan", 3);
  addNewBook("Sherlock Holmes", "Arthur Conan", 4);

  TEST_ASSERT_EQUAL_INT(6, bookArray[0].bookNumber); //might have to change the index of the array depeneding if test resets the entire program.
}

void test_addNewBook_3(){

  int i;
  int j = 5;
  addNewBook("Lorean Legacies", "Pittacus Lore", 0);


  for(i = 0; i<indexOfBookArray; i++)
  {
    if(strcmp("Lorean Legacies", bookArray[i].bookName))
    {
      j = 1;
    }

    else
    {
      j = 0;
    }
  }

  TEST_ASSERT_EQUAL_INT(0, j); //might have to change the index of the array depeneding if test resets the entire program.
}





void setUp (void){}

void tearDown (void){}

int main (void){

  UNITY_BEGIN();

  RUN_TEST(test_addNewBook_1);
  RUN_TEST(test_addNewBook_2);
  RUN_TEST(test_addNewBook_3);

  return UNITY_END();
}
