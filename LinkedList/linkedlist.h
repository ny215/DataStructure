#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
using namespace std;

template <class T>
class LinkedList{
  // You'll need to fill in the function declarations here, since writing them
  // correctly is half the challenge of some of these functions.  Be careful to
  // give them the same names as specified in the README, and pay special
  // attention to things which should be const, references, or both.

  // Note that if your function declarations are incorrect, the autograder will
  // fail to compile.  We'll make sure the autograder is at least able to test
  // compiling your code before the submission deadline.
class Node{

public:
	T data;			//data stored in node
	Node* next;		//point to next node
};

private:
  	Node* head;			//head of LinkedList
  	Node* tail;			//tail of LinkedList
  	int _size;			//size of Linkedlist	
  	bool isEmpty();			//check if LinkedList is empty
  	void addHead(T);   		//add new node at first node
  	void addTail(T);		//add new node at end node
  public:
  	//default constructor
  	LinkedList();

	//constructor from array
	LinkedList(int length, T* values);

  	//copy Linkedlist
	LinkedList(const LinkedList& other);

  	//insertion
  	void insert(T x, int pos);

  	//remove
  	void remove(int pos);

  	//get size
  	int size();

  	//get n-th item
  	T getItem(int n);

	//assgin one Linklist to another
	LinkedList<T> & operator = (LinkedList<T> &other);

	//destructor
  	~LinkedList();

};

template <typename T>
LinkedList<T>:: LinkedList()
{	
	head = NULL;
	tail = NULL;
	_size = 0;
}

template <typename T>
bool LinkedList<T>:: isEmpty()			//check if the list is empty
{
	if(head == NULL && tail == NULL) 	//if both head and tail are NULL
		return 1;
	else
		return 0;
}

template <typename T>
void LinkedList<T>:: addHead(T dataIn)	//adding case: add to head
{
	if(isEmpty())
	{
		Node* newNode = new Node();		//if is empty, then assign dataIn to newNode. assign both head and tail to newNode.
		newNode->data = dataIn;
		head = newNode;
		tail = newNode;
	}
	else
	{
		Node* newNode = new Node();
		newNode->data = dataIn;
		newNode->next = head; 		//the next pointer of the new node is the old head
		head = newNode;		 		//new head is the newNode
	}
	this->_size++;
}


template <typename T>
void LinkedList<T>:: addTail(T dataIn) //adding cae: add to tail
{
	if(isEmpty())
	{
		Node* newNode = new Node(); //if is empty, then assign dataIn to newNode. assign both head and tail to newNode.
		newNode->data = dataIn;
		head = newNode;
		tail = newNode;
	}
	else
	{
		Node* newNode = new Node();
		newNode->data = dataIn;
		tail->next = newNode;		//the next pointer of the old tail is newNode
		tail = newNode;				//new tail is the newNode
	}
	this->_size++;
}




template<typename T>
LinkedList<T>:: LinkedList(int length, T* values)    	//constructor from array
{
	this->head = NULL;									//initialize head, tail, _size
	this->tail = NULL;
	this->_size = 0;
	for(int i = 0; i < length; i++)
	{	
		addTail(values[i]);								//add each new value to tail
	}

}



template <typename T>									//copy linkedlist
LinkedList<T>::	LinkedList(const LinkedList<T>& other)
{
	if(other.head == NULL)								//if the other LinkedList is empty, then return.
	{
		printf("It's an empty LinkedList\n");
		return;
	}
	else
	{										
		this-> head = NULL;								//initialize head, tail, _size
		this-> tail = NULL;
		this-> _size = 0;
		Node* tmp = other.head;							//get head of other
		Node* newNode = new Node();						//create new Node
		newNode->data = tmp->data;						//copy data
		newNode->next = NULL;							//assign next of newNode to be NULL
		this->head = newNode;							//assign this head to be newNode
		this->_size++;									//add size
		tmp = tmp->next;								//increase tmp to be the next node
		while(tmp != NULL && this->_size < other._size)//copy node by node
		{

			newNode->next = new Node();
			newNode = newNode->next;
			newNode->data = tmp->data;
			newNode->next = NULL;
			tmp = tmp->next;
			this->_size++;
		}
	}

}


template <typename T>
LinkedList<T> & LinkedList<T>::operator = (LinkedList<T> &other)
{
	if(this == &other)    							// if they are euqal, then return itself.
	{
		return * this;
	}
	LinkedList<T>tmp(other);						//copy other into LinkedList tmp
	std::swap(tmp.head, head);						//swap head, tail, _size of this with tmp
	std::swap(tmp.tail, tail);				
	std::swap(tmp._size, _size);
	return *this;

}




template <typename T>
void LinkedList<T>:: insert(T x, int pos)		//insertion
{
	if(isEmpty())		
	{
		addHead(x);								//if LinkedList is empty, then add to head
	}
	else
	{
		if(pos == 0)							//if pos == 0, then add to head
		{	
			addHead(x);
		}
		else if (pos == this->size())			//if pos = size(), then add to tail
		{
			addTail(x);
		}
		else									//other common cases
		{
			Node* newNode = new Node();
			newNode->data = x;
			Node* tmp = this->head;   
			for(int i = 0; i < pos-1; i++)		//get to the position to insert
			{
				tmp = tmp->next;
			}
			Node* tmp_next = tmp->next;			//track the node after the insertion positon
			tmp->next = newNode;				// assgin next of node at pos to be the newNode
			newNode->next = tmp_next;			// assgin next of newNode to be the node after the insertion postion
			this->_size++;
		}

	}	
}


template <typename T>
void LinkedList<T>::remove(int pos)
{
	if(pos < 0 || pos > this->size())			//if the position is invalid
	{
		printf("it's invalid\n");
	}
	else
	{
		if(pos == 0)							//case: remove from head
		{
			Node* tmp = this->head;				
			Node* tmp_next = tmp->next;			//store the next node of head
			this->head = tmp_next;
			delete tmp;
			this->_size--;			
		}

		else if (pos == this->_size - 1)		//case: remove from tail
		{
			Node* tmp = this->head;
			for(int i = 0; i < pos-1; i++)
			{
				tmp = tmp->next;
			}
			this->tail = tmp;
			Node* tmp_next = tmp->next;
			delete tmp_next;
			this->_size--;
		}
		else
		{
			Node* tmp = this->head;				//common case
			for(int i = 0; i <pos - 1; i++)
			{
				tmp = tmp->next;
			}
			Node* tmp_next = tmp->next;
			Node* tmp_next_next = tmp_next->next;
			tmp->next = tmp_next_next;
			delete tmp_next;
			this->_size--;
		}
	}

}


template <typename T>
T LinkedList<T>:: getItem(int n)
{
	if(n > this->size() || n < 0)			//if position is invalid
	{
		printf("it's invalid\n");
		return 0; 			
	}
	else
	{
		Node* tmp = this->head;
		for(int i = 0; i < n; i++)			//iterate to the wanted position
		{
			tmp = tmp->next;
		}
		return tmp->data;
	}

}


template <typename T>
int LinkedList<T>:: size()
{
	return _size;
}


template<typename T>
LinkedList<T>:: ~LinkedList()
{
	Node* tmp = this->head;
	for(int i = 0; i < this->_size; i++)    //delete from head
	{
		Node* tmp_next = tmp->next;
		delete tmp;
		tmp = tmp_next;
	}
}

#endif
