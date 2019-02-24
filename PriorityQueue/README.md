# Resources
http://www.cplusplus.com/reference/vector/vector/vector/
http://www.cplusplus.com/reference/thread/thread/?kw=thread

# Overview
The task is to build a priority queue class using a heap as the underlying data structure and update the PriorityQueue class to be thread-safe.

# Problem

Write a class called `PriorityQueue` which uses a max-heap to implement a priority queue.  It should be templated, and work with any object type which implements the comparison operators (<, >, ==, and !=).  Your class should have the functionality below:

* A default constructor, which takes no arguments
* Copy constructor, which creates a deep copy of the `PriorityQueue`.
* Destructor which cleans up any memory associated with the `PriorityQueue`.
* Assigning one PriorityQueue to another should make a deep copy of the PriorityQueue.

* `int size()` returns the current number of elements in the `PriorityQueue`.
* `T top()` returns the first (highest value) item in the `PriorityQueue`.
* `void push(T x)` should add the element `x` to the `PriorityQueue`.
* `void pop()` should remove the top item in the PriorityQueue.



