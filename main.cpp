#include <iostream>
#include "libraries/Deque.h"

using std::cout;

int main() {
    Deque *d = new Deque();
    d->push(1);
    d->push(2);
    d->push(3);
    d->push(4);
    d;
    while(!d->is_empty()) {
        cout << d->unshift() << " ";
    }

    cout << "\n";

    return 0;
}
