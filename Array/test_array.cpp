#include "array.h"
#include <cstdio>
#include <iostream>

int main(int argc, char* argv[])
{
  // Here's some quick test code to get you started.  You'll need much more
  // thorough testing, of course.
  int tmp[4] = {99,98,97,96};
  int *ptr = tmp;

  Array<int> arr(10,5);
  // copy constructor  
  Array<int> rthree(arr); 
  //cout<<"rthree "<<rthree<<endl;

  //test constructor with pointer
  Array<int> rfour(2,ptr);

  //cout<<"rfour "<<rfour<<endl;

  //test size()
  int haha = arr.size();

  //test append
  arr.append(80);

  Array<int> rtoo(2,33);
  //test [] out of index
  arr[1] = 9876; 

  //cout<<"three is"<<rthree<<endl;
  //arr + rtoo + arr;

  cout<<"rthree is"<<arr + rtoo + arr<<endl;
//  cout<<arr + rtoo + arr<<endl;


  /*
  cout<<rthree<<endl;
  cout<<arr<<endl;
  cout<<rtoo<<endl;

  cout<<rthree<<endl;
  rthree = arr + rtoo + rtoo;
  cout<<rthree<<endl;
  


  //test []

  //test =
  rtoo = arr;   

  for(int i = 0; i < arr.size(); i++){
    arr[i] = i * 2;
  }

  for(int i = 0; i < arr.size(); i++){
    printf(" arr[%d] = %d\n", i, arr[i]);
  }

  for(int i = 0; i < rtoo.size(); i++){
    printf("rtoo[%d] = %d\n", i, rtoo[i]);
  }

*/
  //test <<
  //cout << rtoo;
  //test cleanup()


  return(0);
}

