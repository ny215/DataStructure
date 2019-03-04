## 3. Word counting
Write an implementation of the Linux utility `wc`, which counts words, newlines, and bytes in a file.
It should take the name of a file on the command line, plus up to three optional arguments:

    -l  Print the number of newlines
    -w  Print the nubmer of words
    -c  Print the number of bytes (characters, including whitespace)

If no counts are specified, print all three.  The counts should always be printed in the following order: newline, word, bytes.  For example, `wc README.md` should give:

    68 614 3618 README.md

If no file is specified, you should read from stdin.

Your Makefile should produce a binary named `wordcount`.

