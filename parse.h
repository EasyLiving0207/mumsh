//
// Created by  Easy Living on 9/23/20.
//

#ifndef P1_PARSE_H
#define P1_PARSE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LINE_LEN 1024
#define ARG_MAX 512

void append(char subject[], const char insert[], int pos);

void addspace(char *line, int *i);

char *readline(void);

char ***parseline(char *line);

void shiftargs(char **args, int pos);

void checkcommands(char ***commands);

void checkargs(char **args);

#endif //P1_PARSE_H
