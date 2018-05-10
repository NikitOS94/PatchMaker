# PatchMaker

PatchMaker - c++ based app for generation and application of patches.
Patch - binary or text file which considered text of file2 encrypted by hash of file1.

## Installation

Typical installation procedure may look like this:
    
    $ git clone https://github.com/NikitOS94/PatchMaker.git
    $ cd PatchMaker
    $ mkdir build
    $ cd build
    $ cmake ..

## Execution
Pass to PatchMaker as a parameters three paths to files: 
* Input file1 - file can be empty but should exists
* Input file2 or patch - file can be empty but should exists
* Otput file

Example:
    
    $ ./PatchMaker tests/test1/i1.txt tests/test1/patch.txt tests/test1/output.txt
   
### Possible outputs:
* "You pass only N arguments. You should pass 3 paths of files!" - prints if you pass not enough arguments.
* "Input file FILE_NAME does not exist!" - prints if you pass as a input file which not exist.
* "Output file FILE_NAME not available!" - prints if you pass as a output file which can't be acceptable.
* "Patch successfully created!" - patch created.
* "Patch successfully applied!" - patch applied.

## Launch tests
To launch test use next command:
    
    $ make test
    
Now, tests considered 7 groups with 6 tests in each.
   
