# CSC3022F assignment 1

This assignment I made a program that can parse a text file which contains XML-like tags, in order to extract the tag types and the text elements they surround. More specifically, given such a text file this program can:

1. identify each element tag
2. count the number of occurrences of the tag and store the tag label 
3. store the text enclosed by each tag type.

## Data

All assignment examples are located in the examples directory. If you wish to test a different file, simply add it to the examples directory and enter only the name of the file when prompted.


## Usage

In the root directory run the following to create object and executable files:

```
make
```

After succesfull compilation, you can navigate to the location of the 'driver' target executable with the following command:

```
cd build/executables
```

In the executables directory, there should be a single driver file called driver.

To run this simply run: 
 
```
./driver
```

To clean the build directory (object files and executables) run:

```
make clean
```

