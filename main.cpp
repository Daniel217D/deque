#include <iostream>
#include "libraries/Deque.h"

using std::cout;

int main() {
    auto *d = new Deque<double>();

    cout << "Push with pop: ";
    d->push(1);
    d->push(2);
    d->push(3);
    d->push(4);
    while(!d->is_empty()) {
        cout << d->pop() << " ";
    }
    cout << "\n";

    cout << "Shift with unshift: ";
    d->shift(1);
    d->shift(2);
    d->shift(3);
    d->shift(4);
    while(!d->is_empty()) {
        cout << d->unshift() << " ";
    }
    cout << "\n";

    cout << "Push with unshift: ";
    d->push(1);
    d->push(2);
    d->push(3);
    d->push(4);
    while(!d->is_empty()) {
        cout << d->unshift() << " ";
    }
    cout << "\n";

    cout << "Shift with pop: ";
    d->shift(1);
    d->shift(2);
    d->shift(3);
    d->shift(4);
    while(!d->is_empty()) {
        cout << d->pop() << " ";
    }
    cout << "\n";

    try {
        cout << d->pop();
    } catch (const std::exception& e) {
        cout << e.what();
    }

    delete d;
    return 0;
}
