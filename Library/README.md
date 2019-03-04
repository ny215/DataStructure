# Resources
You should fill in this section with the resources that you used to develop your code.  You don't need to include the teaching staff or the textbook, but you should list anyone you worked with, and any online or paper resources you used.
https://www.geeksforgeeks.org/binary-tree-set-1-introduction/
https://stackoverflow.com/questions/9181146/freeing-memory-of-a-binary-tree-c
http://cslibrary.stanford.edu/110/BinaryTrees.html
https://blog.csdn.net/baiziyuandyufei/article/details/43021011
https://www.geeksforgeeks.org/construct-binary-tree-string-bracket-representation/ 
https://blog.csdn.net/liukcqu/article/details/51258028?utm_source=blogxgwz3 
# Overview
This assignment requires writing a group of related functions, which form a simple library.  It combines material from the last few chapters on pointers, recursion, and now `malloc` and `free`.

In this problem, you'll write a library of functions for reading, writing, and manipulating "Minimal Object Notation" (MON).

The basic "object" in MON is the `Element` struct:

    typedef struct element_t {
      char* name;
      struct element_t* left_child;
      struct element_t* right_child;
    } Element;

Since `left_child` and `right_child` are also `Element`s, we can construct trees of Element objects by manipulating pointers appropriately.

You will write the following five functions:

## create_left

    Element* create_left(Element* root, char* data)

Creates a new Element with the string in `data`, and adds it as the left child to the Element `root`.  Returns a pointer to the newly-created Element.  If the `root` Element already has a left child, the function should not create a new element, and should return NULL.

## create_right

    Element* create_right(Element* root, char* data)

Same as `create_left`, but adds the element as a right child instead.

## free_tree

    void free_tree(Element* root)

Frees all of the memory allocated for an Element and all of its children (and their children).

## write_tree

    int write_tree(FILE* f, Element* root)

Writes a tree to a file.  Formally, the file format is:

    <File> ::= [<Element>]
    <Element> ::= {<Element><Element><String>} | "NULL "
    <String> ::= Any characters, whitespace, etc., except for '{' and '}'

A sample file is included in the repository.
The function should return 0 if successful, and a negative number if it failed for some reason.

## read_tree

    Element* load_tree(FILE* f)

Reads a tree from a MON file and creates the appropriate `Element`s.
The return value should be a pointer to the root of the tree (i.e., the top `Element`).  If the file is corrupt, then the function should return NULL.

# Valgrind
Your code must be valgrind-clean.  That is, Valgrind should not report any memory leaks when running your code.
You'll need to be particularly careful when reading a file that turns out to be corrupt.  It is probable that you will have allocated some memory already, and will need to free it before returning to the user.

