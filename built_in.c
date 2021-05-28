//
// Created by  Easy Living on 9/27/20.
//

#include "built_in.h"

void cd(char **args) {
    if (args[1] == NULL) {
        return;
    }
    if (chdir(args[1]) != 0) {
        perror(args[1]);
    }
}

void pwd(char **args) {
    char dir[DIR_LEN];
    getcwd(dir, DIR_LEN);
    printf("%s\n", dir);
}