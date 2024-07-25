#ifndef LINEARLIST_H
#define LINEARLIST_H

#include <iostream>

template<typename T>
class Node {
public:
    T data;
    Node *next;

    Node(const T d, Node *n = nullptr) {
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

    void einfuegen(const T &val) {
        if (!head || val < head->data) {
            head = new Node<T>(val, head);
            return;
        } else {
            Node<T> *current = head;
            while (current->next && current->next->data < val) {
                current = current->next;
            }
            current->next = new Node<T>(val, current->next);
        }
    }

    void print_list() const {
        Node<T> *current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

#endif