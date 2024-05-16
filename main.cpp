#include <iostream>
#include <array>
#include <string>
#include "Container/Array.h"

int main() {
    std::array<std::string, 3> array1 = {"Programmieren I", "Soziale Medien"};
    array1[2] = "Programmieren II";
    print_Array(array1);
    array1[1] = "Kaffeetrinken";
    print_Array(array1);

    return 0;
}
