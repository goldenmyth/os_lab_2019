#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>

int main() {
    pid_t child_pid;
    child_pid = fork();
    if (child_pid > 0) {
        sleep(10);
    }
    return 0;
}