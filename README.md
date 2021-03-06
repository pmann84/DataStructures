# Data Structures
An attempt to write various STL classes. DISCLAIMER: These classes are in now way meant to be as good as the STL classes that they mimic or even completely correct. This is purely used as a bit of fun and/or a learning exercise. Personally I find STL code hard to read, so this is partly an attempt to demystify the STL classes and the way they are written. All classes are kept in the `ds` namespace.

# Make sure you clone the repo submodules
If you have cloned this using the command line, you make sure the submodules are pulled down by running 
`git submodule update --init --recursive`

# Build and Run Tests
- Make sure the googletest submodule has been initialised and cloned
- `cd vendor\googletest` and then run `cmake .`
- This will generate Visual Studio project files
- Open `ALL_BUILD.vcxproj` in Visual Studio and build all configurations of the `ALL_BUILD` project

# Structures Available

## array
Stack allocated memory block, mimicing the `std::array` class. 

### Features Implemented
- Basic stack allocated memory
- Size
- Index (square bracket) operator

### Features To Implement
- Iterators
- Swap
- Debug checks for out of bounds access

## vector
Dynamically allocated memory block, mimicing the `std::vector` class.

### Features Implemented
- Basic heap allocated memory
- Size
- Index (square bracket) operator
- Growing and shrinking of capacity depending on how many elements added
- Some basic functions, `clear`, `pop_back`, `push_back`, `emplace_back`

### Features To Implement
- Iterators
- Swap
- Erase
- Debug checks for out of bounds access

## Future Data Structures
- list
- map
- unordered_map
- stack allocated array with dynamic size (?)
- queue
- stack
etc etc

# General Todos
- Remove main.cpp and implement tests with gtest