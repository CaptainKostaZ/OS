#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void signal_handler(int sig) {
    if (sig == SIGUSR1) {
        printf("Child received SIGUSR1 signal\n");
        exit(0);
    }
}

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        signal(SIGUSR1, signal_handler);
        pause(); // Wait for signal
    } else if (pid > 0) {
        // Parent process
        sleep(1); // Give the child time to set up signal handler
        kill(pid, SIGUSR1);
        printf("Parent sent SIGUSR1 to child\n");
    } else {
        perror("Fork failed");
        return 1;
    }
    return 0;
}
