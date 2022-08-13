# sc-22-cpp-client
A client-library for the Software Challenge 2022, written in C++

## Dependencies:
 * Boost
 * pugiXML (included)
 * a C++11 compatible compiler

## Building:
First, create and change to a build directory, for example build/

`mkdir build && cd build`

Then, create the cmake project

`cmake ..`

Now you can build the project

`make`

The executable will be created in the bin directory.

## Usage

Run the client via `SC_2022_STARTER`
If you want to specify an IP adress and a port number, you can do so via `SC_2022_STARTER IP PORT`.