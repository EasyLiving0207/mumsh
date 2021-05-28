//
// Created by  Easy Living on 9/27/20.
//

#ifndef P1_EXECUTE_H
#define P1_EXECUTE_H

#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "parse.h"
#include "built_in.h"

#define READ  0
#define WRITE 1
#define MODE 0664

int child_num;

int execute(char ***commands);

void redirect(char **args);

void clean(int child_num);

#endif //P1_EXECUTE_H
