Created by Jackson Goldberg
Email: jacksonagoldberg@gmail.com

All work is designed and written by me.

Dependences:
    C++
Importent Notes:
    - File input is prompted in terminal
    - Output File is DFA.txt located in local directory
    - All testing was done with compiler g++
Example Files:
    - example.txt is visualized in example.pdf
    - example1.txt is visualized in Example1.pdf
How to use:
    g++ *.cpp
    ./a.out
    /*prompted for file*/: /*file name*/ (example.txt and example1.txt are provided)

Returns:
    Dfa.txt

Input File Formating:
    - Line 1: List of states spererated by tabs (eg. A   B   C   D   E)
    - Line 2: List of input alphabet seperated by tabs (eg. 0   1   2   3   4   5   6   7   8)
    - Line 3: The start state  (eg. A)(Importent Note: Only enter a single string with no spaces)
    - Line 4: The accept state (eg. E)(Importent Note: Not used for anything atm, included for future applications)
    - Line 5: BEGIN (Used to indicate start of transitions)
    - Line 6-n: State transitions, represented : "State selected","Transition value" = "Destination state"
    - Line n+1: END (Indicates the end of the transitions)

