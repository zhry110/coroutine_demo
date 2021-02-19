#include <iostream>
#include "CoroutineTask.h"

CoroutineTask<int> create() {
    co_await suspend_never();
}

int main() {
    auto task = create();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
