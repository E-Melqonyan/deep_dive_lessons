/*
Multiple Forks and Execs
Objective: Work with multiple child processes created using fork and run different commands using execl.
Write a program that:
Creates two child processes using fork.
The first child process should use execl to run the ls command.
The second child process should use execl to run the date command.
The parent process should print "Parent process done" after creating both child processes.

Expected Output: The output of the ls command followed by the output of the date command, and finally the parent's message.
*/

#include <iostream>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    int child1 = fork();

    // child process 1
    if (child1 == 0) {
        dup2(fd, STDOUT_FILENO);
        int err = execl("/usr/bin/ls", "ls", NULL);
        if (err == -1) {
            std::cerr << "Error: execl 1 failed" << std::endl;
        }
    }
    // parent process
    else {
        int child2 = fork();
        // child process 2
        if (child2 == 0) {
             dup2(fd, STDOUT_FILENO);
            int err = execl("/usr/bin/date", "date", NULL);
            if (err == -1) {
                std::cerr << "Error: execl 2 failed" << std::endl;
            }
        }
        // parent process
        else {
            dup2(fd, STDOUT_FILENO);
            std::cout << "Parent process done" << std::endl;
        }
    }

    return 0;
}