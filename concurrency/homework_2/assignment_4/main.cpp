#include <iostream>
#include <thread>

void square(int num) {
    std::cout << "Square of " << num << " is " << num * num << std::endl;
}

int main() {
    const int arry_size = 10;
    int arr[arry_size];
    for (int i = 0; i < arry_size; ++i) {
        arr[i] = i + 1;
    }

    std::thread threads[arry_size];

    for (int i = 0; i < arry_size; ++i) {
        threads[i] = std::thread(square, arr[i]);
    }

    for (int i = 0; i < arry_size; ++i) {
        threads[i].join();
    }

    return 0;
}