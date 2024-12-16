#include <iostream>
#include <thread>

void sum(int start, int end, int* arr) {
    int sum = 0;
    for (int i = start; i < end; ++i) {
        sum += arr[i];
    }
    std::cout << "Sum: " << sum << std::endl;
}

int main() {
    int arry_size = 100;
    int *arr = new int[arry_size];
    for (int i = 0; i < arry_size; ++i) {
        arr[i] = i;
    }

    std::thread t1(sum, 0, arry_size / 2, arr);
    std::thread t2(sum, arry_size / 2, arry_size, arr);

    t1.join();
    t2.join();

    return 0;
}