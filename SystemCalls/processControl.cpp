#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

using namespace std;

int main() {
    pid_t pid = fork(); // Create a new process

    if (pid < 0) {
        cerr << "Fork failed!" << endl;
        return 1;
    }

    if (pid == 0) { 
        // Child process: Execute a program (e.g., gedit)
        cout << "Child Process Created!" << endl;
        cout << "Process ID (PID): " << getpid() << endl;
        cout << "Parent Process ID (PPID): " << getppid() << endl;

        execlp("gedit", "gedit", NULL); // Run gedit
        cerr << "Failed to execute process!" << endl;
        return 1;
    } 
    else { 
        // Parent process
        cout << "Parent Process: " << getpid() << endl;
        cout << "Waiting for 3 seconds..." << endl;
        sleep(3);

        cout << "Checking if child is still running..." << endl;
        if (kill(pid, 0) == 0) {  // Check if child is alive
            cout << "Terminating child process..." << endl;
            kill(pid, SIGTERM);  // Send terminate signal
            waitpid(pid, NULL, 0);  // Wait for the child process to terminate
            cout << "Child process terminated!" << endl;
        } else {
            cout << "Child process has already exited!" << endl;
        }
    }

    return 0;
}
