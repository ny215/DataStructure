# Resources

https://stackoverflow.com/questions/30857668/assignment-operator-in-linked-list-c
http://www.cplusplus.com/articles/E3wTURfi/
# Overview
The task is to build a linkedlist.

# Problem

* A default constructor, which takes no arguments
* Constructor which takes the length and a pointer to an array to initialize the elements: `LinkedList(int length, int* values)`.  You may assume that if the pointer is not NULL, it points to a valid array that holds at least `length` elements.  The LinkedList should create its own copy of the data.
* Copy constructor, which creates a deep copy of the `LinkedList`.
* Destructor which cleans up any memory associated with the `LinkedList`.

* `size()` returns the current size of the `LinkedList`.
* `getItem(int n)` returns the n-th item in the `LinkedList`.
* The function `insert(T x, int pos)` should insert the element `x` into the list at position `pos`.  Position 0 corresponds to the beginning of the list (before the first item), position `size()` would be after the last element.  Calling `getItem(pos)` should retrieve the newly-inserted element.
* The function `remove(int pos)` should remove the n-th item in the LinkedList.

* Assigning one LinkedList to another should make a deep copy of the LinkedList.


