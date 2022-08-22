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

# WARNING: Building for python does not work right now because of some error that I don't know how to fix. If you have an idea, please create an issue or even a pull request! I am going insane because of this

This project is using swig for python bindings, the swig file and it's CMakeLists are located in python_starter/


First, create and change to a build directory, for example build/

`mkdir build && cd build`

Then, create the cmake project with the python flag:

`cmake .. -DBUILD_PYTHON=ON`

Now you can build the project

`make`

## Usage

Run the client via `SC_2022_STARTER`
If you want to specify an IP adress and a port number, you can do so via `SC_2022_STARTER IP PORT`.

If you want to create your own game logic, you can do so in `starter/custom_logic.cpp`, or create your own file and include it in `starter/starter.cpp`.