
#include <iostream>
#include <fstream>
#include "func.h"

#pragma warning(disable : 4996)

int main()
{
    std::fstream in("assets/input.txt");
    if (!in.is_open()) {
        std::cerr << "File open error" << std::endl;
        return -1;
    }
    else {
        F::print_of_text();
    }
}