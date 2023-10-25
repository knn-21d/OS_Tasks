#include <sys/types.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int n = stoi(argv[1]);

    cout << "main process started... PID = " << getpid() << endl;

    for (int i = 0; i < n; i++) {
        pid_t pid = fork();

        if (pid == 0) {
            cout << "child started... PID = " << getpid() << ", PPID = " <<
            getppid() << " (i = " << i << ")" << endl;
            sleep(5);
            cout << i << " child finished... PID = " << getpid() <<
            ", PPID = " << getppid() << endl;
            return 0;
        }
    }

    cout << "main process finished... PID = " << getpid() << endl;

    return 0;
}
