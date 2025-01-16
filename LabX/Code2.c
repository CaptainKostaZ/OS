#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2];
    char buffer[100];
    pipe(pipefd);

    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        close(pipefd[1]); // Close unused write end
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Child received message: %s\n", buffer);
        close(pipefd[0]);
    } else if (pid > 0) {
        // Parent process
        close(pipefd[0]); // Close unused read end
        char message[] = "Hello from parent!";
        write(pipefd[1], message, strlen(message) + 1);
        close(pipefd[1]);
    } else {
        perror("Fork failed");
        return 1;
    }
    return 0;
}
