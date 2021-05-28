//
// Created by  Easy Living on 9/27/20.
//

#include "execute.h"

static int in = 0;
static int out = 0;

int execute(char ***commands) {
    int command_num = 0;
    for (int j = 0; j < ARG_MAX; ++j) {
        if (commands[j] == NULL) {
            command_num = j;
            break;
        }
    }
    char **args;
    int input = 0;
    for (int i = 0; i < command_num; ++i) {
        if (commands[i] == NULL) {
            fprintf(stderr, "error: missing program\n");
            return 1;
        }
    }
    for (int k = 0; k < command_num; ++k) {
        args = commands[k];
        if (strcmp(args[0], "exit") == 0) {
            clean(child_num);
            printf("exit\n");
            return 0;
        }
//        int built_in = 0;
//        for (int i = 0; i < BUILTIN_NUM; i++) {
//            if (strcmp(args[0], builtin_str[i]) == 0) {
//                builtin_func[i](args);
//                built_in = 1;
//                break;
//            }
//        }
//        if (built_in == 1) {
//            continue;
//        }
        if (strcmp(args[0], "cd") == 0) {
            cd(args);
            continue;
        }
        int pip[2];
        pipe(pip);
        pid_t pid = fork();
        ++child_num;
        if (pid == 0) {
            // Child process
            in = 0;
            out = 0;
            if (k > 0) { // not the first command
                dup2(input, STDIN_FILENO);
                in = 1;
            }
            if (k < command_num - 1) { // not the last command
                dup2(pip[WRITE], STDOUT_FILENO);
                out = 1;
            }
            redirect(args);
            if (strcmp(args[0], "pwd") == 0) {
                pwd(args);
            } else if (execvp(args[0], args) == -1) {
                fprintf(stderr, "%s: command not found\n", args[0]);
            }
            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            // Error forking
            perror("mumsh");
        } else {
            // Parent process
            if (input != 0) {
                close(input);
            }
            close(pip[WRITE]);
            if (k == command_num - 1) { // last command
                close(pip[READ]);
            }
            input = pip[READ];
        }
    }
    clean(child_num);
    return 1;
}

void redirect(char **args) {
    int fd;
    for (int i = 0; i < ARG_MAX; ++i) {
        if (args[i] == NULL) {
            break;
        }
        if (strcmp(args[i], "<") == 0) {
            if (in == 1) {
                fprintf(stderr, "error: duplicated input redirection\n");
                exit(EXIT_FAILURE);
            }
            in = 1;
            fd = open(args[i + 1], O_RDONLY);
            if (fd < 0) {
                perror(args[i + 1]);
                exit(1);
            }
            dup2(fd, STDIN_FILENO);
            close(fd);
            shiftargs(args, i);
            --i;
        } else if (strcmp(args[i], ">") == 0) {
            if (args[i + 1] == NULL) {
                fprintf(stderr, "syntax error near unexpected token `|'\n");
                exit(EXIT_FAILURE);
            }
            if ((strcmp(args[i + 1], ">") == 0)) {
                fprintf(stderr, "syntax error near unexpected token `>'\n");
                exit(EXIT_FAILURE);
            }
            if ((strcmp(args[i + 1], "<") == 0)) {
                fprintf(stderr, "syntax error near unexpected token `<'\n");
                exit(EXIT_FAILURE);
            }
            if ((strcmp(args[i + 1], "<<") == 0)) {
                fprintf(stderr, "syntax error near unexpected token `<<'\n");
                exit(EXIT_FAILURE);
            }
            if (out == 1) {
                fprintf(stderr, "error: duplicated output redirection\n");
                exit(EXIT_FAILURE);
            }
            out = 1;
            fd = open(args[i + 1], O_WRONLY | O_CREAT | O_TRUNC, MODE);
            if (fd < 0) {
                fprintf(stderr, "%s: Permission denied\n", args[i + 1]);
                exit(1);
            }
            dup2(fd, STDOUT_FILENO);
            close(fd);
            shiftargs(args, i);
            --i;
        } else if (strcmp(args[i], ">>") == 0) {
            if (out == 1) {
                fprintf(stderr, "error: duplicated output redirection\n");
                exit(EXIT_FAILURE);
            }
            out = 1;
            fd = open(args[i + 1], O_WRONLY | O_APPEND | O_CREAT, MODE);
            if (fd < 0) {
                fprintf(stderr, "%s: Permission denied\n", args[i + 1]);
                exit(1);
            }
            dup2(fd, STDOUT_FILENO);
            close(fd);
            shiftargs(args, i);
            --i;
        }
    }
}

void clean(int child) {
    for (int l = 0; l < child; ++l) {
        wait(NULL);
        child_num--;
    }
}