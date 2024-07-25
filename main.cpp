#include <iostream>
#include <array>
#include <string>
#include <list>
#include "Array.h"
#include "linearlist.h"
#include "sum.h"

int main() {
    std::array<std::string, 3> array1 = {"Programmieren I", "Soziale Medien"};
    array1[2] = "Programmieren II";
    print_Array(array1);
    array1[1] = "Kaffeetrinken";
    print_Array(array1);

    //------------------------------------------------------------//

    LinkedList<int> list;
    list.push_front(12);
    list.push_front(7);
    list.push_front(3);

    std::cout << "Liste vor dem Einfuegen: ";
    list.print_list();

    list.einfuegen(6);
    list.einfuegen(13);
    list.einfuegen(1);

    std::cout << "Liste nach dem Einfuegen: ";
    list.print_list();

    //------------------------------------------------------------//

    auto *list2 = new std::list<std::string> {"Programmieren I", "Rechnernetze", "Programmieren II"};
    std::list<std::string> *templist = list2;
    for(auto i : *templist) {
        std::cout << templist->front();
        templist->pop_front();
        if(!templist->empty()){
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    //------------------------------------------------------------//

    std::list<int> a {1, 2, 3, 4, 5};
    std::list<int> b {1, 2, 3, 4, 5, 6, 7};

    auto *erg = new std::list<int>();
    sum(a,b,erg);
    std::cout << "\n";
    for(std::list<int>::iterator i = erg->begin(); i != erg->end(); i++){
        std::cout << " " << *i << "\n";
    }

    auto *erg2 = new std::list<int>();
    interleave(a,b,erg2);
    std::cout << "\n";
    for(std::list<int>::iterator i = erg2->begin(); i != erg2->end(); i++) {
        std::cout << " " << *i << "\n";
    }

    return 0;
}
