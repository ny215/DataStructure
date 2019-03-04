# Resources
You should fill in this section with the resources that you used to develop your code.  You don't need to include the teaching staff or the textbook, but you should list anyone you worked with, and any online or paper resources you used.
http://pubs.opengroup.org/onlinepubs/7908799/xsh/readdir.html
http://pubs.opengroup.org/onlinepubs/7908799/xsh/opendir.html
http://pubs.opengroup.org/onlinepubs/7908799/xsh/closedir.html
https://blog.csdn.net/wuheshi/article/details/43406999
https://blog.csdn.net/u012349696/article/details/50084195
https://blog.csdn.net/sunstars2009918/article/details/7076054
https://www.cnblogs.com/fnlingnzb-learner/p/6472391.html
http://www.it610.com/article/4837740.htm
https://blog.csdn.net/u011068702/article/details/61916220

# Problem
Write an implementation of the Linux utility `tree`, which prints out the subdirectory structure of the directory specified on the command line.  If no directory is specified, use the current working directory.

You should indent each successive directory level by 4 spaces.
You do not need to print the pretty lines or color labels (although these are nice features of `tree`).

Some functions that will be helpful (use `man` to read about them):
* `opendir`
* `readdir`
* `closedir` (It's important to clean up after yourself, even if your code works without doing so.)
* `snprintf`


