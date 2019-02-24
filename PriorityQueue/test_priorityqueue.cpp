#include "priorityqueue.h"
#include <cstdio>
#include <thread>
#include <mutex>

//multi threads
void multipush1(PriorityQueue<int> &q)
{
  for(int i = 0; i < 50; i++)
  {
     q.push(i);
     printf("%d is pushed into heap\n", i);
    printf("size of heap is %d\n",q.size());

  }
}

void multipush2(PriorityQueue<int> &q)
{
  for(int i = 51; i < 100; i++)
  {
     q.push(i);
     printf("%d is pushed into heap\n", i);
     printf("size of heap is %d\n",q.size());

  }
}

void multiremove(PriorityQueue<int> &q)
{
  for (int i = 0; i < 50; i++)
  {
    printf("%d th remove\n", i);
    printf("%d is poped from heap\n", q.top());
    printf("size of heap is %d\n",q.size());

    q.pop();
  }
}

int main(int argc, char* argv[])
{
  // Here's some quick test code to get you started.  You'll need much more
  // thorough testing, of course.

  PriorityQueue<int> q;
  // try pop when priorityqueue is empty.
  printf("%d ", q.top());
  q.pop();
  printf("\n");

  PriorityQueue<int> q2;


  // Push 5 elements onto the front   32145
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);

  //test operator =
  q2 = q;
  q.push(6);
  q.push(7);
  while(q2.size() > 0){
    printf("%d ", q2.top());
    q2.pop();
  }
  printf("\n");


  // Make a copy
  PriorityQueue<int> another = q;
  while(q.size() > 0){
    printf("%d ", q.top());
    q.pop();
  }
  printf("\n");

  while(another.size() > 0){
    printf("%d ", another.top());
    another.pop();
  }
  printf("\n");

  
  //test mutex
  PriorityQueue<int> heap;		
  thread first(multipush1, ref(heap));
  thread second(multiremove, ref(heap));
  thread third(multipush2, ref(heap));

  first.join();
  second.join();
  third.join();
  printf("top of heap is %d \n", heap.top());

  return(0);
}

