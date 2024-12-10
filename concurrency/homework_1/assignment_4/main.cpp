/*
ork and Exec with Command-Line Arguments
Objective: Use fork and execl to run a command with multiple arguments.
Prepare a test.txt file with some text.
Write a program that:
Uses fork to create a child process.
The child process should use execl to run the grep command to search for a specific word (e.g., "main") in a text file (e.g., test.txt).
The parent process should print "Parent process completed".

Expected Output: The lines in the file test.txt that contain the word "main" followed by "Parent process completed".
*/

#include <iostream>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    int pid = fork();
    if (pid == 0) {
        dup2(fd, STDOUT_FILENO);
        int ret = execl("/bin/grep", "grep", "concurrency", "test.txt", NULL);
        if (ret == -1) {
            std::cerr << "Error: execl failed" << std::endl;
        }
    } else {
        dup2(fd, STDOUT_FILENO);
        std::cout << "Parent process completed" << std::endl;
    }
    return 0;
}