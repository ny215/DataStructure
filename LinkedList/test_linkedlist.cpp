#include "linkedlist.h"
#include <cstdio>

int main(int argc, char* argv[])
{
  // Here's some quick test code to get you started.  You'll need much more
  // thorough testing, of course.
  printf("-----------------test insert----------------------\n");

  LinkedList<int> list;
  list.insert(2, 0);      //insert from head
  list.insert(3, 0);
  list.insert(4, 0);
  list.insert(100,3);     //insert from tail
  list.insert(22, 2);     //insert from middle
  int size_list = list.size(); 

  for(int i = 0; i < list.size(); i++){
    printf("list[%d] = %d\n", i, list.getItem(i));
  }

  printf("---------------test construct from array-----------\n");

  //test construct from an array
  int arr[] = {9,8,7,6,5,4,3,2,1};
  int arr_len = 9;
  LinkedList<int> list2(9, arr);

  for(int i = 0; i < list2.size(); i++){
    printf("list2[%d] = %d\n", i, list2.getItem(i));
  }

  printf("---------------test remove----------------------\n");

    list2.remove(10);   //invalid case
    list2.remove(8);    //remove from tail
    list2.remove(1);    //remove from middle
    list2.remove(0);    //remove from head

  for(int i = 0; i < list2.size(); i++){
    printf("list2[%d] = %d\n", i, list2.getItem(i));
  }

  printf("---------------test copy LinkedList----------------\n");

  //test with an empty LinkedList;
 // LinkedList<int> tmp;
 // LinkedList<int> list3(tmp);


  //test normal copy
  LinkedList<int> list4(list2);
  int size_list4 = list4.size();
  for(int i = 0; i < list4.size(); i++){
  printf("list4[%d] = %d\n", i, list4.getItem(i));
  }

  printf("---------------test operator = ----------------------\n");
  
  //test assgin one LinkedList to another
  LinkedList<int> list5;
  list5 = list4;
  for(int i = 0; i < list5.size(); i++){
  printf("list5[%d] = %d\n", i, list5.getItem(i));
  }


  list2 = list5;
  for(int i = 0; i < list2.size(); i++){
  printf("list2[%d] = %d\n", i, list2.getItem(i));
  }


/*
  // Push three elements onto the front
  list.insert(1, 0);
  list.insert(2, 0);
  list.insert(3, 0);

  // Make a copy
  LinkedList<int> another = list;

  // Push some more elements onto the front of the original
  list.insert(4, 0);
  list.insert(5, 0);

  for(int i = 0; i < list.size(); i++){
    printf(" list[%d] = %d\n", i, list.getItem(i));
  }


  */
  return(0);
}

