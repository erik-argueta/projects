===========|| CROSS-REFERENCER || ===========



======DIRECTIONS======
* If you are trying to run the program, save the files onto your desktop and run it from there.




======ABOUT======
* Purpose of this project is to cross-reference files via an input.txt and the files to reference. 
* Ideally, this will display onto the terminal which items were found to be a match, or which items failed to match. 
* I hope to turn this into an actual program with a nice User Interface. (Later tho)




======SPECIFICS======
- input.txt is the file where the user will insert the specific Serial Numbers they wish to cross-reference.

- output.txt is the file where the (un)matched numbers will be saved with the results.

- The terminal output will display which serial numbers were matched and failed to match.

- DEBUGGER.txt will display all the processes that occur. It should list the user's S/N and the S/N's being cross-referenced.

- EHS-X.txt is one of the list of Serial Numbers
- Pool.txt is the generic pool of Serial Numbers
- State.txt is another list of S/N's
- EHS-Basic.txt is the last list of S/N's




======LANGUAGE======
* For now, the program will be coded in C++




======AUTHORS======
* Erik Argueta



======EXAMPLE======
|| input.txt ||
abcde
fghijkl
mnop


|| Terminal ||
Welcome to the Cross-Referencer! 
Cross-Referencing the files from: input/txt
with *insert the name of the txt files being referenced*
.
.
.
.
abcde == MATCH
fghijkl == FAILED
mnop == FAILED


|| debugger.txt ||
abcde == abcdf
abcde == abcdg
abcde == abcdh
...

|| output.txt || 
abcde == MATCH
fghijkl == FAILED
mnop == FAILED
