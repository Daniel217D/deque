#pragma once

#include <iostream>

using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;
using std::out_of_range;

template<class Type>
class Node {
private:
    Type value;

    Node<Type> *next;

    template<typename> friend
    class Deque;

public:
    Node(Type _value, Node *_next = nullptr) : value(_value), next(_next) {
    }

    ~Node() {
        delete next;
    }

    Node *get_next() {
        return next;
    }

    Type get_value() {
        return value;
    }
};

template<class Type>
class Deque {
private:
    Node<Type> *node = nullptr;

public:
    ~Deque() {
        delete node;
    }

    bool is_empty() {
        return node == nullptr;
    }

    void push(Type value) {
        if (is_empty()) {
            shift(value);
        } else {
            Node<Type> *current = node;

            while (current->next) {
                current = current->next;
            }

            current->next = new Node<Type>(value);
        }
    }

    Type pop() {
        Type value;

        if (is_empty()) {
            throw out_of_range("Deque is empty");
        } else if (node->next == nullptr) {
            value = node->value;

            node = nullptr;
            delete node;
        } else {
            Node<Type> *current = node;

            while (current->next->next) {
                current = current->next;
            }

            value = current->next->value;

            delete current->next;
            current->next = nullptr;
        }

        return value;
    }

    void shift(Type value) {
        node = new Node<Type>(value, node);
    }

    Type unshift() {
        if (is_empty()) {
            throw out_of_range("Deque is empty");
        } else {
            Type value = node->value;
            Node<Type> *temp = node;

            node = node->next;
            temp->next = nullptr;
            delete temp;

            return value;
        }
    }
};
