#include"Deque.h"

#include<iostream>

using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;
using std::out_of_range;

Node::Node(int _value, Node *_next = nullptr) : value(_value), next(_next) {
}

Node::~Node() {
    delete next;
}

Node *Node::get_next() {
    return next;
}

int Node::get_value() {
    return value;
}

Deque::~Deque() {
    delete node;
}

bool Deque::is_empty() {
    return node == nullptr;
}

void Deque::push(int value) {
    if (is_empty()) {
        shift(value);
    } else {
        Node *current = node;

        while (current->next) {
            current = current->next;
        }

        current->next = new Node(value);
    }
}

int Deque::pop() {
    int value;

    if (is_empty()) {
        throw out_of_range("Deque is empty");
    } else if (node->next == nullptr) {
        value = node->value;

        node = nullptr;
        delete node;
    } else {
        Node *current = node;

        while (current->next->next) {
            current = current->next;
        }

        value = current->next->value;

        delete current->next;
        current->next = nullptr;
    }

    return value;
}

void Deque::shift(int value) {
    node = new Node(value, node);
}

int Deque::unshift() {
    if (is_empty()) {
        throw out_of_range("Deque is empty");
    } else {
        int value = node->value;
        Node *temp = node;

        node = node->next;
        temp->next = nullptr;
        delete temp;

        return value;
    }
}
