#include"Deque.h"

#include<iostream>
#include <fstream>

using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;

Node::Node(int _value, Node *_next = nullptr) : value(_value), next(_next) {}

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
    delete first;
}

bool Deque::is_empty() {
    return first == nullptr;
}

void Deque::push(int value) {
    if(is_empty()) {
        shift(value);
    } else if(){
        prev_last->next = new Node(value, prev_last->next);
        prev_last = prev_last->next;
    }
}

//int Deque::pop() {
//    if(is_empty()) {
//        throw 1;
//    } else if(first == prev_last){
//        int value = first->value;
//
//        first
//        delete temp;
//
//        return value;
//    }
//}

void Deque::shift(int value) {
    first = new Node(value, first);

    if(prev_last == nullptr) {
        prev_last = first;
    }
}

int Deque::unshift() {
    if(is_empty()) {
        throw 1;
    } else {
        int value = first->value;
        Node *temp = first;

        first = first->get_next();
        temp->next = nullptr;
        delete temp;

        return value;
    }
}
