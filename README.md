# sc-penguins-cpp
A client-library for the Software Challenge, written in C++
Originally used for the Saison in 2020/23, but can be used if this game comes back at a later point.

If you are interested in the Software Challenge, take a look at our [Website](https://software-challenge.de)!

## Disclaimer
If you run into issues, please write an issue or contact me on Discord (@Estugon).

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

## Creating your own logic

Either edit the template logic in `starter/custom_logic.cpp`, or create your own file and include it in `starter/starter.cpp`.
When compiling for C++, these files will be included and the logic defined in starter.cpp will be used.

To get started, you want to look into the `sc_library/include/game/gameState.h` file, in there are basic functions that will help you create your own logic, including documentation.

## Usage

Run the client via `SC_PENGUINS_STARTER`
If you want to specify an IP adress and a port number, you can do so via `SC_PENGUINS_STARTER IP PORT`.