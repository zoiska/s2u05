#include <iostream>
#include <array>
#include <list>
#include <string>
#include "Container/Array.h"

template<typename T> class Node {
public:
    T data;
    Node* next;
    Node(const T d, Node* n){
        this->data = d;
        this->next = n;
    }
};

template<typename T>
class LinkedList {
private:
    Node<T> *head;
public:
    LinkedList() { head = nullptr; }
    ~LinkedList() {
        while (head) {
            Node<T> *p = head->next;
            delete head;
            head = p;
        }
    }
    LinkedList(const LinkedList &) = delete;
    LinkedList &operator=(const LinkedList &) = delete;
    void push_front(const T &val) {
        head = new Node<T>(val, head);
    }
    void pop_front() {
        Node<T> *p = head;
        head = head->next;
        delete p;
    }
    bool empty() const { return head == nullptr; }
    T &front() const { return head->data; }
    void einfuegen(int number) {
        if(number <= head->data) {
            push_front(number);
        }
        Node<T> *p = head;
        while(p->next != nullptr) {
            if (p->data < number && number <= p->next->data) {
                Node<T> *q = new Node<T>(number, p->next);
                p->next = q;
            }
            p = p->next;
        }
        if(p->next == nullptr && number > p->data) {
            p->next = new Node<T>(number, nullptr);
        }
    }
};

template<typename T> void sum(std::list<T> liste1,std::list<T> liste2, std::list<T> *erg) {
    typename std::list<T>::iterator j = liste1.begin();
    typename std::list<T>::iterator k = liste2.begin();
    for(int  i = 0; i< std::max(liste1.size(), liste2.size()); ++i) {
        if(j == liste1.end()) {
            erg->push_back(*k);
            k++;
        }
        else if(k == liste2.end()) {
            erg->push_back(*j);
            j++;
        }
        else {
            erg->push_back(*j + *k);
            k++;
            j++;
        }
    }
}

int main() {
    std::array<std::string, 3> array1 = {"Programmieren I", "Soziale Medien"};
    array1[2] = "Programmieren II";
    print_Array(array1);
    array1[1] = "Kaffeetrinken";
    print_Array(array1);

//--------------------------------------------------------------------------

    LinkedList<int> *liste = new LinkedList<int>();
    liste->push_front(10);
    liste->push_front(5);
    liste->push_front(2);
    liste->einfuegen(1);
    while(!liste->empty()) {
        std::cout << liste->front();
        liste->pop_front();
    }
    std::cout << "\n";

//--------------------------------------------------------------------------

    std::list<std::string> Liebligsvorlesung = {"Programmieren I", "Programmieren II", "Rechnernetze"};

    std::list<std::string>::iterator i = Liebligsvorlesung.begin();
    i++;
    *i = "Kaffeepause";

    while(!Liebligsvorlesung.empty()) {
        std::cout << Liebligsvorlesung.front() << ", ";
        Liebligsvorlesung.pop_front();
    }
    std::cout << "\n";

//--------------------------------------------------------------------------

    std::list<int> a {1, 2, 3, 4, 5,6};
    std::list<int> b {1, 2, 3, 4, 5};
    std::list<int> *erg = new std::list<int>();
    sum(a,b,erg);
    for(std::list<int>::iterator i = erg->begin(); i != erg->end(); i++){
        std::cout << " " << *i << "\n";
    }

    return 0;
}
