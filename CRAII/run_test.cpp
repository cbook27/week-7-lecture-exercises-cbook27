#include <cassert>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <type_traits>

#define main exercise_main
#include "main.cpp"
#undef main

int main()
{
    std::ostringstream output;
    auto* original = std::cout.rdbuf(output.rdbuf());

    {
        Connection first("12.34.56.78");
    }
    assert(output.str() ==
           "Connecting to ip address: 12.34.56.78\n"
           "Disconnecting from ip address 12.34.56.78\n");

    output.str("");
    output.clear();
    try {
        Connection second("98.76.54.32");
        throw std::runtime_error("test exception cleanup");
    } catch (const std::runtime_error&) {
    }
    std::cout.rdbuf(original);
    assert(output.str() ==
           "Connecting to ip address: 98.76.54.32\n"
           "Disconnecting from ip address 98.76.54.32\n");
    std::cout << "CRAII passed\n";
}
