#include <sys/types.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int n = stoi(argv[1]);

    cout << "main process started... PID = " << to_string(getpid()) << endl;

    for (int i = 0; i < n; i++) {
        pid_t pid = fork();

        if (pid == 0) {
            cout << "child started... PID = " << to_string(getpid()) << ", PPID = " <<
            to_string(getppid()) << " (i = " << to_string(i) << ")" << endl;
            sleep(5);
            cout << to_string(i) << " child finished... PID = " << to_string(getpid()) <<
            ", PPID = " << to_string(getppid()) << endl;
            return 0;
        }
    }

    cout << "main process finished... PID = " << to_string(getpid()) << endl;

    return 0;
}