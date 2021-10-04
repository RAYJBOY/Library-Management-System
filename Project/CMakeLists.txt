project(QuadTree)

set( CMAKE_BUILD_TYPE Release)
#set( CMAKE_BUILD_TYPE Debug)

cmake_minimum_required(VERSION 2.6)

include_directories( include ${CMAKE_CURRENT_LIST_DIR})

add_executable(testing 	
  src/addToLibrary.c
  test/test_addToLibrary.c
  unity/unity.c
  src/listing.c
)

add_executable(list_testing 	
  src/listing.c
  src/addToLibrary.c
  test/test_listing.c
  unity/unity.c
)

add_executable(library 	
  src/addToLibrary.c
  src/main.c
  src/listing.c
  src/interface.c
)

target_link_libraries(testing m)
