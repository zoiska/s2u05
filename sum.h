#ifndef SUM_H
#define SUM_H

#include <list>

template<typename T> void sum(std::list<T> liste1, std::list<T> liste2, std::list<T> *erg) {
    auto it1 = liste1.begin();
    auto it2 = liste2.begin();

    while (it1 != liste1.end() || it2 != liste2.end()) {
        T val1 = (it1 != liste1.end()) ? *it1 : 0;
        T val2 = (it2 != liste2.end()) ? *it2 : 0;

        if (it1 == liste1.end() || it2 == liste2.end()) {
            erg->push_back(0);
        }
        else {
            erg->push_back(val1 + val2);
        }

        if (it1 != liste1.end()) ++it1;
        if (it2 != liste2.end()) ++it2;
    }
}

template<typename T> void interleave(std::list<T> liste1, std::list<T> liste2, std::list<T> *erg) {
    if (liste1.empty() || liste2.empty()) {
        erg->push_back(0);
    }
    else {
        while (!liste1.empty() && !liste2.empty()){
            erg->push_back(liste1.front());
            erg->push_back(liste2.front());
            liste1.pop_front();
            liste2.pop_front();
        }
    }
}

#endif //SUM_H
