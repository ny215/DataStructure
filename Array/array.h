#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <exception>
#include <string>

using namespace std;
class OutOfBoundsException: public exception
{
public:
	const char *what() const throw(){
		return "out of bounds";
	}

};

template <class T>
class Array{
  // You'll need to fill in the function declarations here, since writing them
  // correctly is half the challenge of some of these functions.  Be careful to
  // give them the same names as specified in the README, and pay special
  // attention to things which should be const, references, or both.

  // Note that if your function declarations are incorrect, the autograder will
  // fail to compile.  We'll make sure the autograder is at least able to test
  // compiling your code before the submission deadline.


public:
	//default constructor 
	Array();

	//constructor
	Array(int length, T value);

	//constructor with pointer
	Array(int length, T* values);

	//desstructor
	~Array();

	//Copy constructor
	Array(const Array& arr);

	//Return the current size of the 'Array'
	int size();

	//Add the element 'x' to the end of the array
	void append(T x);

	//add all of the contents of Array 'y' to the end of the array
	void append(Array y);
    
    //Assigning one Array to another
    Array<T>& operator = (Array<T> &a); 

    //read and write elements of the Array using bracket notation.
    T& operator[](int index);

    //operator +
    Array& operator + (Array &a); 

    //operator <<
    template <typename U>  
    friend ostream &operator<<(ostream& out, Array<U> &a);



private:
	T* array;      // pointer to the array
	int arr_length;      // arr_length of the array
	int nextIndex;   // the next highest index value

};

template <typename T>
Array<T>:: Array()     
{
}

template<typename T>
Array<T>:: ~Array()
{
	delete[] array;
}

template <class T>
Array<T>:: Array(int length, T value)
{
	arr_length = length;
	nextIndex = length;
	array = new T[nextIndex];
	for(int i = 0; i< nextIndex; ++i){
		array[i] = value;
	}
}

template <class T>
Array<T>:: Array(int length, T* values)
{ 
	if(values != NULL){
		arr_length = length;
		array = new T[arr_length];
		for(int i = 0; i< length; i++){
			array[i] = values[i];
		}
		nextIndex = length;
	}

}

template <class T>
Array<T>:: Array(const Array<T>& arr)
{
	arr_length = arr.arr_length;
	nextIndex = arr.nextIndex;
	array = new T[nextIndex];
	memcpy(array, arr.array, arr_length*sizeof(T));

}


template<class T>
int Array<T>:: size()
{
	return arr_length;
}


template<class T>
void Array<T>:: append(T x)
{
 	T* newarray;
 	if(nextIndex == arr_length){
 		int newlength = arr_length + 1;   				// if no enough space, add one more space
 		newarray = new T[newlength]; // get a new array
 		for(int i = 0; i < nextIndex; i++){
 			newarray[i] = array[i];
 		}
 		newarray[nextIndex] = x; 
 		nextIndex = newlength;
 		delete[] array;
 		array = newarray;
 	}
}

template<class T>
void Array<T>:: append(Array<T> y)
{
    T* newarray;
    int newlength = arr_length + y.size();
    newarray = new T[newlength]; // get a new array
	for(int i = 0; i < nextIndex; i++){
		newarray[i] = array[i];
	}
	for(int j = 0; j < y.size(); j++){
		newarray[nextIndex+j] = y[j];
	}
	delete[] array;			//delete old 
	array = newarray;
	nextIndex = newlength;  //update nextIndex

}

template <class T>
Array<T>& Array<T>:: operator=(Array<T> &a)
{
	if(this == &a){
		return * this;
	}

	T* newarray;
    int newlength = a.size();
    newarray = new T[newlength];     // get a new array
	for(int i = 0; i < newlength; i++){	//copy the contents from a to newarray
		newarray[i] = a[i];
	}
	delete[] array;
	array = newarray;
	nextIndex = newlength;
	return *this;
}

template<class T>
Array<T>& Array<T>:: operator+ (Array &a)  
{
	static Array sum;
	T* newarray;
	int newlength = a.size() + arr_length;
	newarray = new T[newlength];
	for(int i = 0; i< arr_length; i++){		//copy the content from first array
		newarray[i] = array[i];
	}
	for(int j = arr_length; j <newlength; j++){ //copy the content from second array a
		newarray[j] = a[j-arr_length];

	}
	delete[] sum.array;
	sum.array = newarray;
	sum.nextIndex = newlength;
	sum.arr_length = newlength;
	return sum;
} 

template<class T>
T& Array<T>:: operator[](int index)
{

	if(index < 0 || index >= arr_length){
		throw OutOfBoundsException();
		//printf("error, out of index at %d!\n",index);
	//exit(0);
	}
	else{
		return array[index];
	}
}

template<class T>
std:: ostream &operator<< (std::ostream& out, Array<T> &array){
	int i;
	out<<"[";
	for(i = 0; i< array.size()-1; i++){
		out<<array[i]<<", ";
	}
	out<<array[i];
	out<<"]\n";
	return out;
}



#endif
