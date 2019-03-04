# Resources

https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/
https://blog.csdn.net/apull/article/details/5379819
http://zetcode.com/articles/cdatetime/
https://www.oschina.net/translate/the-tic-tac-toe-game-with-python
https://www.tutorialspoint.com/c_standard_library/c_function_isalpha.htm
https://stackoverflow.com/questions/34024433/excess-elements-in-char-array-initializer-error
# Problems
## 1.
Write a function that prints the prime factors of an integer.  The input to the function is an int; it should return 0 if it was successful; -1 if it was not (e.g., the number doesn't have any prime factors).  The prime factors should be printed one on each line.  Remember that 1 is not prime.

## 2.
Write a function that returns the largest power of 2 that is less than or equal to N (i.e., 5 returns 4, 12 returns 8, etc.).

## 3.
Write a function that behaves like a simple calculator: it takes two double-precision arguments and a character operand (one of '+', '-', '*', '/', or '^') and returns the result as a double.
You might want to use the 'pow' function; type 'man pow' at the command-line for the reference page. (If you use 'pow', you'll need to add -lm to your gcc command.)

## 4.
Write a function that returns the triangle with the larger area.
typedef struct {
  double x;
  double y;
} Point;

typedef struct {
  point a;
  point b;
  point c;
} Triangle;

Triangle getLarger(Triangle first, Triangle second);

## 5.
Write a function that prints out N random numbers between 0 and M

## 6.
scanf() is sort of the reverse of printf(): it reads input and converts values according to a format string.  For example, to read two integers:

    scanf("%d %d", number1, number2);

The catch is that since scanf needs to modify the arguments, they must be pass-by-reference.  That is, number1 and number2 are not ints, but rather pointers to ints.

Write a command-line calculator program that reads what to do using scanf.  Your code should take both operands and the operation all on one line (e.g., "45 + 3") and then print the result.  You should re-use your calculator code from the previous assignment, and just add scanf to get the arguments.

## 7.
Write a function that prints the date and time represented by a `time_t`, using the format: `Weekday, Month Day, Year hours:minutes:seconds`

For example, `Wednesday, September 19, 2018 16:30:02`

You will probably want to use the time() and gmtime() functions.  You can access the help pages with `man 2 time` and `man gmtime`.

## 8.
We use pass-by-reference when the function needs to modify the parameters, but it can also be useful when the parameters take a large amount of memory and we want to avoid the overhead of copying them.

To simulate this case, write a new version of your which-triangle-is-larger function which operates with pass-by-reference.  If one triangle is NULL, then you should return the non-NULL one as "larger".
## 9. linspace
Write the function
  void linspace(double * array, double min, double max, int n)
which fills in an array with a set of linearly-spaced values from min to max, inclusive.
Your function should behave like the [MATLAB linspace function](https://www.mathworks.com/help/matlab/ref/linspace.html), except that n is always provided, and you don't need to handle complex numbers.
If n is 1, then the array should be filled with the value min.

Needless to say, you should be careful not to modify memory off the ends of the array.

## 10. find_min
Write the function:
    int * find_min(int *array, int n)
which returns a pointer to the smallest element of the array (whose length is n).  If the array has no elements (n is 0), then the function should return NULL.


## 11. Increasing sequence
Return a pointer to the beginning of the longest sequence of continuously increasing integers in an array.  For example, given the array:
  int arr[] = { 7, 2, 10, 13, 15, 8, 3, 20 }
the fuction should return a pointer to arr[2], since this begins the sequence {10, 13, 15}.
If there are no sequences of increasing integers, then you should return NULL.  The integers do not need to increase by any particular amount; just that each number is greater than the one before it.

## 12. Tic-Tac-Toe
Write a function which checks a tic-tac-toe board for a win condition; i.e., one or the other players has completed a row of 3, either vertically, horizontally, or diagonally.  The board is a 3x3 array of char, which contains `x`, `o`, ` `, and possibly invalid characters.
Your function should return:

* `x` if X has won,
* `o` if O has won,
* ` ` if the game is still going,
* `.` if the game if no one has won and all the spaces are filled ("cat's game")
* `0` (NULL) if the board is invalid (contains invalid characters, or there are more 'x' or 'o' than would be possible if players were taking turns).

## 13. Convert to lowercase
Write a function which converts the characters in a string to lowercase:

    void lower(char* str);

Characters which are not letters should not be modified.  The function should not crash if given a NULL string.  You should not use any C string functions in your implementation.

## 14. Cipher cracking
The textbook motivated the need for arrays by discussing cipher cracking by counting characters, but never implemented this function.  Write a function which computes a histogram of characters a-z for a string of length `len`:

    void find_frequency(const char* str, int len, unsigned int histogram[26])

The result in `histogram` should be a count of the occurances of each character in the string: The number of 'a's in histogram[0], etc.
Uppercase and lowercase letters should be treated as the same character; other characters should be ignored.  You should avoid writing a 26-case switch statement in your code, which means you'll need to be clever with the ASCII representation and array indexing.

## 15. Short string finding
Given an array of strings, find the shortest one and return a pointer to it:

    const char* find_shortest(const char * const * strings, int len)

You can assume that the strings are well-formed; that is, any string which is not NULL is terminated properly with a `\0`.

##Array
##LinkedList
##PriorityQueue
