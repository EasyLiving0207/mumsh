//
// Created by  Easy Living on 9/27/20.
//

#ifndef P1_BUILT_IN_H
#define P1_BUILT_IN_H

#include <unistd.h>
#include "parse.h"

#define BUILTIN_NUM 2
#define DIR_LEN 256

void cd(char **args);

void pwd(char **args);

#endif //P1_BUILT_IN_H
