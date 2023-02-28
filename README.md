<h1>String Implementation </h1>
<hr>

<b>
<br> std::string is a built-in class in C++ that represents a sequence of characters as a string. It is part of the Standard Template Library (STL) and is defined in the <string> header file.

<hr>
  
std::string is implemented as a dynamically allocated array of characters, and provides a number of convenient member functions for manipulating strings, such as concatenation, substring extraction, searching for substrings, and more.

std::string is implemented in such a way that it automatically manages memory allocation and deallocation for the underlying character array. This makes it easier to use than C-style character arrays, which require manual memory management.

<hr>

std::string is a container class, which means it can be used with iterators and algorithms from the STL. This allows for efficient processing of large strings, and makes it easy to write generic code that works with strings of different sizes and contents. </b>
<hr>
  
If you want to compile this code.
You must write

```
g++ -std=c++2a main.cpp implementation.cpp

```

and then if you want to run this code you must write

```
./a.out 

```
![string image](https://user-images.githubusercontent.com/112478852/221839312-135ec5c5-055b-4604-9869-0435e08b8d6d.png)

  
