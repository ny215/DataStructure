# Resources
https://www.cs.nmsu.edu/~rth/cs/cs471/C%2B%2BDynamicArray.pdf
https://blog.csdn.net/lisonglisonglisong/article/details/38273665
https://blog.csdn.net/baymin_dly/article/details/78015820
https://gist.github.com/daeltar/90951

# Overview
This assignment requires writing a complete class utilizing many of the object-oriented features of C++.  You'll also need to work with `malloc` and `free` to carefully manage memory. 


# Problem

Write a class called `Array` representing a 1D array of integers, which makes up for some of the deficiencies of traditional C arrays.  Your class should have the functionality below:

* The function `initialize(int size, int val)` should set up the Array with storage for `size` elements, all initialized to `val`.
* The function `cleanup()` should free all `malloc`ed memory associated with the Array.

* `size()` returns the current size of the `Array`.
* The function `append(int x)` should add the element `x` to the end of the array.
* The function `append(Array y)` should add all of the contents of Array `y` to the end of the array.

* Assigning one Array to another should make a *deep copy* of the Array.  For example, after doing

    b = a; // b and a already exist

The Array `b` should be a copy of `a`, but with its own memory allocated, such that modifying `b` does not change `a`.  *Note that you won't be able to do*

    Array b = a; // We're just now declaring b

*because this requires a copy constructor, which we'll learn about next Monday.*

* A user should be able to read and write elements of the `Array` using bracket notation, just like a standard C array.

    arr[3] = 5;
    int x = arr[0];

If any index is invalid, your code should print a string with the word "error" and exit with the status 0.  *This is not a good way to handle errors, and we'll learn better ways of handling these kinds of errors soon.*

* You should be able to print the array using the `<<` operator.  The result should be a comma-separated list of values enclosed in square brackets, like `[1, 3, 5, 7]`.

These functions should be public; all implementation details of your class should be private.

Your code should manage memory with `malloc` (or one of its derivates like `calloc`) and `free`.  We'll learn the C++ ways of managing memory soon.

## Use exceptions
Upgrade your `Array` class to use C++ exceptions.  In particular, you should throw an `OutOfBoundsException` if the user tries to access an element that's off the end of the array.

Your `OutOfBoundsException` should inherit `std::exception` and implement the `what()` method, returning a string with at least the words "out of bounds", so it can be caught generically and printed.  In particular, the following code should catch the exception and print it:

    Array arr(3, 0);
    try {
      std::cout << "The fourth number is: " << arr[3] << std::endl;
    }
    catch (const std::exception& e){
      std::cout << "There was an error: " << e.what() << std::endl;
    }

## Exception safety
Your code should provide a "strong exception guarantee": if something happens which causes an exception, there should be no side effects.  That is, the object should be unmodified from its original state, and no memory should be leaked.  This will require thinking carefully about where exceptions could occur, and rewriting some functions to make them more robust.

The most likely cause for exceptions is allocating memory.  The autograder will cause `new` to fail while running your code, and will check that the exception is caught and your objects are not corrupted.  You can use the test code in `array/test_array_newfail.cpp` to cause `new` to throw an exception.
