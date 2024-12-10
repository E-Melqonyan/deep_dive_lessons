/*
Objective: Understand the process hierarchy when multiple sequential fork syscalls are invoked.
Write a program that:
Calls multiple  fork syscalls one after another. Check what the process tree looks like.
Pay attention to the hierarchy of processes, how many parents and children are created
*/


#include <iostream>
#include <unistd.h>

int main() {
    pid_t main_parent_pid = getpid();

    std::cout << "Parent process id: " << main_parent_pid << std::endl;

    fork();
    fork();
    fork();

    if (getpid() == main_parent_pid) {
        std::string command = "pstree -p " + std::to_string(main_parent_pid) + " > output.txt";
        system(command.c_str());
    }

    sleep(10);
    return 0;
}
