#include <iostream>
#include <thread>

void print() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Thread ID: " << std::this_thread::get_id() << " value: "  << i << std::endl;
    }
}

int main() {
    std::thread t1(print);
    std::thread t2(print);
    std::thread t3(print);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}