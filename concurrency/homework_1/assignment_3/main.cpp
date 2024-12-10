/*
Fork and Exec with Arguments
Objective: Understand how to pass arguments to programs executed with execl.
Write a program that:
Uses fork to create a child process.
The child process should use execl to run the echo command with an argument (e.g., "Hello from the child process").
The parent process should print "Parent process done" after the child process is created.

Expected Output: The message from the echo command followed by the parent's message.
*/

#include <iostream>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    int pid = fork();

    // child process
    if (pid == 0) {
        dup2(fd, STDOUT_FILENO);
        int ret = execl("/bin/echo", "echo", "Hello from the child process", NULL);
        if (ret == -1) {
            std::cerr << "Error: execl failed" << std::endl;
        }
    } else { // parent process
        dup2(fd, STDOUT_FILENO);
        std::cout << "Parent process done" << std::endl;
    }

    return 0;
}