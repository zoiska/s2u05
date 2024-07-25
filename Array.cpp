#include "Array.h"

void print_Array(std::array<std::string, 3> arr) {
    std::cout << "Meine Vorlesungen sind: ";
    for(int i = 0; i < arr.size(); i++) {
        std::cout << arr[i];
        if (i < 2) {
            std::cout << ", ";
        } else {
            std::cout << "";
        }
    }
    std::cout << std::endl;
}