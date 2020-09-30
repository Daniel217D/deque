#pragma once

#include <iostream>

using std::string;

class Node {
private:
    int value;

    Node *next;

    friend class Deque;

public:
    explicit Node(int _value, Node *_next);

    ~Node();

    Node *get_next();

    int get_value();
};

class Deque {
private:
    Node *node = nullptr;

public:
    ~Deque();

    bool is_empty();

    void push(int value);

    int pop();

    void shift(int value);

    int unshift();
};
