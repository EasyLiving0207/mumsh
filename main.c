#include <signal.h>
#include "execute.h"

pid_t parent_id;
extern int child_num;

void handler(int signal) {
    pid_t self = getpid();
    if (signal == SIGINT) {
        if (self == parent_id) {
            printf("\n");
            if (child_num > 0) {
                for (int i = 0; i < child_num; ++i) {
                    wait(NULL);
                    child_num--;
                }
            } else {
                fflush(NULL);
                printf("mumsh $ ");
                fflush(NULL);
            }
        } else {
            exit(0);
        }
    }
}

int main() {
    parent_id = getpid();
    signal(SIGINT, handler);
    int status;
    char *line;
    char ***commands;
    do {
        child_num = 0;
        fflush(NULL);
        printf("mumsh $ ");
        fflush(NULL);
        line = readline();
        commands = parseline(line);
        //checkcommands(commands);
        status = execute(commands);
        for (int i = 0; i < ARG_MAX; ++i) {
            if (commands[i] == NULL) {
                break;
            }
            free(commands[i]);
        }
        free(commands);
        free(line);
    } while (status);

    return 0;
}