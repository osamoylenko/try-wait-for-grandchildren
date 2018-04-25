#include <iostream>
#include <unistd.h>

#include <sys/prctl.h>

int main() {


    const int child_sleep = 5;
    const int grandchild_sleep = 10;

    std::cout << "PARENT: I'm parent process with pid " << getpid()
              << " and process group " << getpgrp() << std::endl;
    std::cout << "PARENT: Creating child process ..." << std::endl;

    auto child_pid = fork();
    if (child_pid == 0) {
        std::cout << "CHILD: Creating grandchild process ..." << std::endl;

        auto grandchild_pid = fork();
        if (grandchild_pid == 0) {
            std::cout << "GRANDCHILD: I'm gonna run for " << grandchild_sleep << " secs" << std::endl;
            for (int i = 0; i < grandchild_sleep; ++i) {
                std::cout << "GRANDCHILD: I'm GRAND child process with pid " << getpid()
                          << " ppid " << getppid()
                          << " and process group " << getpgrp() << std::endl;
                sleep(1);
            }
            std::cout << "GRANDCHILD: I'm done" << std::endl;
            exit(0);
        }

        std::cout << "CHILD: I'm gonna run for " << child_sleep << " secs" << std::endl;
        for (int i = 0; i < child_sleep; ++i) {
            std::cout << "CHILD: I'm child process with pid " << getpid()
                      << " and process group " << getpgrp()
                      << " ppid " << getppid() << std::endl;
            sleep(1);
        }
        std::cout << "CHILD: I'm done" << std::endl;
        exit(0);
    }

    pid_t waited_pid;
    int status;
    while ((waited_pid = waitpid(-getpgrp(), &status, 0)) != -1) {
        std::cout << "PARENT: waited the process with pid " << waited_pid << std::endl;
    }
    std::cout << "PARENT: I'm done" << std::endl;

    return 0;
}
