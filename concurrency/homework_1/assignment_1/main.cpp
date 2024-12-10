/*
Simple Fork and Exec
Objective: Understand the creation of a child process using fork and how to replace it with a new program using execl.
Write a program that:
Uses fork to create a child process.
In the child process, use execl to run the ls command to list the contents of the current directory.
The parent process should print "Parent process done" after the child process is created.

Expected Output: The directory listing should be printed, followed by the parent's message.
*/

#include <iostream>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    pid_t pid = fork();

    // child process
    if (pid == 0) {
        dup2(fd, STDOUT_FILENO);
        int ret = execl("/bin/ls", "ls", NULL);
        if (ret == -1) {
            std::cerr << "Error: execl failed" << std::endl;
        }
    } else {
        dup2(fd, STDOUT_FILENO);
        std::cout << "Parent process done" << std::endl;
    }

    return 0;
}