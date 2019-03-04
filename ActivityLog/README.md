# Resources
https://stackoverflow.com/questions/3501338/c-read-file-line-by-line
https://blog.csdn.net/qq_21808961/article/details/78157113
https://blog.csdn.net/qq_27474589/article/details/53011403
http://www.runoob.com/cprogramming/c-file-io.html
https://en.wikibooks.org/wiki/C_Programming/stdlib.h/atoi
https://stackoverflow.com/questions/13039023/words-counting-in-file-like-linux-wc-command-in-c


# Problems
## 1. Activity log
Write a program that logs activity to the file `activity.tsv`.  For example,

    ./log run 34 "getting back into shape"
    ./log bike 25 "grocery trip"
    ./log swim 40 "I'm doing a triathlon backwards"

The log file should consist of four columns in the following order, separated by tabs:
  1. Epoch time (seconds since 00:00 January 1, 1970 UTC)
  2. The activity, which could be any string ("run", "bike", etc) 
  3. The duration (in minutes)
  4. Notes

If the file does not exist, it should be created.  Otherwise, each call to `log` should keep the current contents of the log, and add a single line with the new activity.

Three of the columns are specified on the command line; the time should simply be the current time.  The note may be left empty.  However, if the activity or duration are not specified, the program should print a message containing the word 'usage', explaining to the user how the program should be used.

Your Makefile should produce a binary named `log`.

## 2. Activity summary
Write a program that summarizes activity over some duration of the past.  It should take a single argument, which is how far back from the current time to summarize.  For the above `log` commands,

    ./summarize 1w

should print:

    Total exercise: 99 minutes

The argument consists of an integer plus one of 'd', 'w', or 'y', for days, weeks or years respectively.

If the summary duration is not specifed, your program should print a message containing the word 'usage', explaining how the program should be used.
If the file does not exist or is corrupted, your program should print a message containing the word 'error'.

Your Makefile should produce a binary named `summarize`.
