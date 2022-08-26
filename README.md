# sc-22-cpp-client
A client-library for the Software Challenge 2022, written in C++

## Disclaimer
This project is still not entirely finished. The client is able to fully play games without crashing, but various functions are not yet implemented or tested fully! If you run into issues, please write an issue or contact me on Discord (Estugon#3234).

## Dependencies:
 * Boost
 * pugiXML (included)
 * a C++11 compatible compiler

## Building for C++:
First, create and change to a build directory, for example build/

`mkdir build && cd build`

Then, create the cmake project

`cmake ..`

Now you can build the project

`make`

The executable will be created in the bin directory.

## Building for Python

# Warning: As of now, the python bindings are not fully finished!

First, create and change to a build directory, for example `build/`

`mkdir build && cd build`

Then, create the cmake project with the python flag:

`cmake .. -DBUILD_PYTHON=ON`

Now you can build the project

`make`

Your starter, logic and libraries are now located in `bin/python_wrapper`

## Creating your own logic

### C++
Either edit the template logic in `starter/custom_logic.cpp`, or create your own file and include it in `starter/starter.cpp`.
When compiling for C++, these files will be included and the logic defined in starter.cpp will be used.

### Python
Either edit the template logic in `python_starter/custom_logic.py`, or create your own file and import it in `python_starter/starter.py`.
When compiling for Python, these files will be copied to `bin/python_wrapper/` where the library file will be placed.

## Usage

Run the client via `SC_2022_STARTER`
If you want to specify an IP adress and a port number, you can do so via `SC_2022_STARTER IP PORT`.