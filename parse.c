//
// Created by  Easy Living on 9/23/20.
//

#include "parse.h"

#define QUO_MAX 256
#define SINGLE 1
#define DOUBLE 2

static int quote_queue[QUO_MAX];
static int quote_num;
const char quotestr[3][2] = {"\0", "\'", "\""};

void append(char subject[], const char insert[], int pos) {
    char buffer[LINE_LEN] = {};
    strncpy(buffer, subject, pos);
    int len = strlen(buffer);
    strcpy(buffer + len, insert);
    len += strlen(insert);
    strcpy(buffer + len, subject + pos);
    strcpy(subject, buffer);
}

void addspace(char *line, int *i) {
    if (line[*i] == '\0') {
        return;
    }
    if ((*i == 0) && (line[*i] == '\"' || line[*i] == '\'')) {
        append(line, " ", *i);
        ++*i;
    } else if (line[*i] == '>') {
        if ((*i > 0) && (!isspace(line[*i - 1])) && (line[*i - 1] != '>') && (line[*i - 1] != '\0')) {
            append(line, " ", *i);
            ++*i;
        }
        if ((!isspace(line[*i + 1])) && (line[*i + 1] != '>') && (line[*i + 1] != '\0')) {
            append(line, " ", *i + 1);
            ++*i;
        }
    } else if ((line[*i] == '<') || (line[*i] == '|')) {
        if ((*i > 0) && (!isspace(line[*i - 1])) && (line[*i - 1] != '\0')) {
            append(line, " ", *i);
            ++*i;
        }
        if (!isspace(line[*i + 1]) && (line[*i + 1] != '\0')) {
            append(line, " ", *i + 1);
            ++*i;
        }
    }
}

int readinput(char *line) {
    if (fgets(line, LINE_LEN, stdin) == NULL) {
        if (feof(stdin)) {
            printf("exit\n");
            exit(EXIT_SUCCESS);
        } else {
            perror("mumsh");
            exit(EXIT_FAILURE);
        }
    }
    int len = 0;
    while (len < LINE_LEN) {
        if (((line[len] == '\"') && (line[len + 1] == '\"')) || ((line[len] == '\'') && (line[len + 1] == '\''))) {
            char buffer[LINE_LEN] = {};
            strcpy(buffer, &line[len + 2]);
            strcpy(&line[len], buffer);
        }
        if (line[len] == '\n') {
            line[len] = '\0';
            break;
        }
        if (line[len] == '\0') {
            break;
        }
        ++len;
    }
    return len;
}

int quotestatus(char *line) {
    for (int i = 0; i < QUO_MAX; ++i) {
        quote_queue[i] = 0;
    }
    quote_num = 0;
    int single_quote = 0;
    int double_quote = 0;
    for (int i = 0; i < LINE_LEN; ++i) {
        if (line[i] == '\0') {
            break;
        }
        if ((single_quote == 0) && (double_quote == 0)) {
            addspace(line, &i);
        }
        if ((line[i] == '\"') && (single_quote == 0)) {
            if (double_quote == 0) {
                double_quote = 1;
            } else {
                double_quote = 0;
                quote_queue[quote_num] = DOUBLE;
                ++quote_num;
            }
        } else if ((line[i] == '\'') && (double_quote == 0)) {
            if (single_quote == 0) {
                single_quote = 1;
            } else {
                single_quote = 0;
                quote_queue[quote_num] = SINGLE;
                ++quote_num;
            }
        }
    }
    if (single_quote || double_quote) {
        return 1;
    }
    return 0;
}

char lastchr(char *line) {
    int len = strlen(line);
    for (int i = len - 1; i > 0; --i) {
        if (!isspace(line[i])) {
            return line[i];
        }
    }
    return line[0];
}

char secondlastchr(char *line) {
    int len = strlen(line);
    int status = 0;
    for (int i = len - 1; i > 0; --i) {
        if (!isspace(line[i])) {
            if (status == 0) {
                status = 1;
            } else {
                return line[i];
            }
        }
    }
    return '\0';
}

char tail(char *line) {
    return line[strlen(line) - 1];
}

char *readline(void) {
    char *line = malloc(sizeof(char) * LINE_LEN);
    readinput(line);
    char last = lastchr(line);
    while (quotestatus(line) || last == '|' || last == '<' || last == '>') {
        if (!quotestatus(line) && (secondlastchr(line) == '>')) {
            break;
        }
        fflush(NULL);
        printf("> ");
        fflush(NULL);
        if (quotestatus(line)) {
            strcat(line, "\n");
        } else {
            strcat(line, " ");
        }
        char temp[LINE_LEN];
        readinput(temp);
        strcat(line, temp);
        last = lastchr(line);
    }
    return line;
}

int emptyarg(char *arg) {
    int i = 0;
    while (arg[i] != '\0') {
        if (!isspace(arg[i])) {
            return 0;
        }
        ++i;
    }
    return 1;
}

char ***parseline(char *line) {
    char ***commands = malloc(ARG_MAX * sizeof(char **));
    if (emptyarg(line)) {
        commands[0] = NULL;
        return commands;
    }
    commands[0] = malloc(ARG_MAX * sizeof(char *));
    int command_num = 0;
    int arg_num = 0;
    char *tokens;
    char *left;
    char *middle;
    char *right = line;
    char *next;
    for (int j = 0; j < quote_num; ++j) {
        left = strtok(right, quotestr[quote_queue[j]]);
        middle = strtok(NULL, quotestr[quote_queue[j]]);
        right = strtok(NULL, "");
        if ((left != NULL) && (!emptyarg(left))) {
            tokens = strtok(left, "|");
            next = strtok(NULL, "");
            char *token = strtok(tokens, " ");
            while (token != NULL) {
                commands[command_num][arg_num] = token;
                arg_num++;
                token = strtok(NULL, " ");
            }
            while ((next != NULL) && (!emptyarg(next))) {
                tokens = strtok(next, "|");
                next = strtok(NULL, "");
                commands[command_num][arg_num] = NULL;
                arg_num = 0;
                ++command_num;
                if (emptyarg(tokens)) {
                    fprintf(stderr, "error: missing program\n");
                    tokens = strtok(next, "|");
                    next = strtok(NULL, "");
                }
                token = strtok(tokens, " ");
                commands[command_num] = malloc(ARG_MAX * sizeof(char *));
                while (token != NULL) {
                    commands[command_num][arg_num] = token;
                    arg_num++;
                    token = strtok(NULL, " ");
                }
            }
        }
        commands[command_num][arg_num] = middle;
        arg_num++;
    }
    if ((right != NULL) && (!emptyarg(right))) {
        tokens = strtok(right, "|");
        next = strtok(NULL, "");
        char *token = strtok(tokens, " ");
        while (token != NULL) {
            commands[command_num][arg_num] = token;
            arg_num++;
            token = strtok(NULL, " ");
        }
        while ((next != NULL) && (!emptyarg(next))) {
            tokens = strtok(next, "|");
            next = strtok(NULL, "");
            commands[command_num][arg_num] = NULL;
            arg_num = 0;
            ++command_num;
            if (emptyarg(tokens)) {
                fprintf(stderr, "error: missing program\n");
                tokens = strtok(next, "|");
                next = strtok(NULL, "");
            }
            token = strtok(tokens, " ");
            commands[command_num] = malloc(ARG_MAX * sizeof(char *));
            while (token != NULL) {
                commands[command_num][arg_num] = token;
                arg_num++;
                token = strtok(NULL, " ");
            }
        }
    }
    commands[command_num][arg_num] = NULL;
    ++command_num;
    commands[command_num] = NULL;
    return commands;
}

void checkcommands(char ***commands) {
    for (int j = 0; j < ARG_MAX; ++j) {
        if (commands[j] == NULL) {
            break;
        }
        printf("command %d:\n", j);
        checkargs(commands[j]);
    }
}


void checkargs(char **args) {
    for (int j = 0; j < ARG_MAX; ++j) {
        if (args[j] == NULL) {
            break;
        }
        printf("arg %d: %s\n", j, args[j]);
    }
}

void shiftargs(char **args, int pos) {
    if (args[pos + 1] == NULL) {
        args[pos] = NULL;
        return;
    }
    int point = pos + 2;
    while (args[point] != NULL) {
        args[point - 2] = args[point];
        ++point;
    }
    args[point - 2] = NULL;
}