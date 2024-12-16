#include <iostream>
#include <thread>

void print_thread_id() {
    std::cout << "Thread " << std::this_thread::get_id() << " is running" << std::endl;
}

int main() {
    std::thread t1(print_thread_id);
    std::thread t2(print_thread_id);
    std::thread t3(print_thread_id);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}