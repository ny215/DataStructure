#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include <vector>
#include <iostream>
#include <cstdio>
#include <thread>
#include <mutex>
using namespace std;
mutex mtx;

template <typename T>
class PriorityQueue{
  // You'll need to fill in the function declarations here, since writing them
  // correctly is half the challenge of some of these functions.  Be careful to
  // give them the same names as specified in the README, and pay special
  // attention to things which should be const, references, or both.
private:
	int _size;  //size of the heap
	vector<T> heap;

public:
	//default constructor
	PriorityQueue();

	//copy constructor
	PriorityQueue(const PriorityQueue& other);	

	//assgin one PriorityQueue to another
	PriorityQueue<T> & operator = (PriorityQueue<T> &other);
	
	//get size
	int size();

	//returns the first (highest value) item
	T top();

	//add element x to heap
	void push(T x);

	//remove the top item in the PriorityQueue
	void pop();

	//destructor
	~PriorityQueue();

	


};
	
template<typename T>				//default constructor
PriorityQueue<T>:: PriorityQueue()
{
	_size = 0;
}

template<typename T>
PriorityQueue<T>:: PriorityQueue(const PriorityQueue& other) //copy constructor
{
	if(other._size == 0)					//if empty, just return
	{
		printf("It's an empty heap\n");
		return;
	}
	else
	{
		this->_size = other._size;			//copy the size
		this->heap = other.heap;			//copy the content in heap
	}
}


template<typename T>
PriorityQueue<T>& PriorityQueue<T>:: operator = (PriorityQueue<T>& other)
{
	if(this == &other)					//if equal, return itself
	{
		return *this;
	}
	this->_size = other._size;			//assgin the size
	this->heap = other.heap;			//assgin the content
	return *this;
}

template<typename T>
int PriorityQueue<T>:: size()			//get size
{
	return _size;
}

template<typename T>
void PriorityQueue<T>:: push(T x)		//add new element into heap
{
	mtx.lock();
	heap.push_back(x);							//push into heap
	_size++;									//update the size
	int child_index = this->_size - 1;			//initialize the index of new element. at the end of heap
	int parent_index = (child_index-1)/2;		//initialize the index of the parent of child
	while(heap[parent_index] < heap[child_index] & (parent_index >= 0))  //if child > parent & the index is valid
	{
		iter_swap(heap.begin()+child_index, heap.begin()+parent_index);	//swap child & child
		child_index = parent_index;				//update index of child
		parent_index = (parent_index-1)/2;		//update index of parent
	}
	mtx.unlock();
}

template<typename T>
T PriorityQueue<T>:: top()
{
	if(this->_size > 0)
	{
		return heap[0];							//get the value of the top element.(max element)
	}
	else
	{
		printf("Error. Out of index.\n");		//if heap is empty
		return 0;
	}
}

template<typename T>
void PriorityQueue<T>:: pop()				//get max element in heap
{	
	mtx.lock();
	if(_size != 0) //if heap not empty
	{
		iter_swap(heap.begin(), heap.end()-1); 	//swap the first with last item
		heap.erase(heap.end()-1);				//pop the last item(desired) out
		_size--;								//update size

		int parent_index = 0;					//initialize parent's index
		int left_child_index = parent_index * 2 + 1; //intialzie children index
		int right_child_index = parent_index * 2 + 2;
		while(right_child_index <= this->_size-1)		//while the index is valid
		{
			if(heap[parent_index] < heap[left_child_index] || heap[parent_index] < heap[right_child_index]) 
			{												//if parent is smaller than any child
				if(heap[left_child_index] > heap[right_child_index])    //if left is larger, swap parent with left child, update index
				{
					iter_swap(heap.begin() + left_child_index, heap.begin()+ parent_index); 
					parent_index = left_child_index;
					left_child_index = parent_index * 2 + 1;
					right_child_index = parent_index * 2 + 2;
				}
				else
				{												//if right is larger, swap parent with right child, update index
					iter_swap(heap.begin() + right_child_index, heap.begin()+ parent_index);
					parent_index = right_child_index;
					left_child_index = parent_index * 2 + 1;
					right_child_index = parent_index * 2 + 2;			
				}
			}
			else{
				break;
			}
		}
	}
	mtx.unlock();

}

template<typename T>					//destructor
PriorityQueue<T>:: ~PriorityQueue()
{
	heap.clear();
	_size = 0;
}


#endif
