#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
static const char *included_files[MAX_FILES];
static int num_included_files = 0;

extern FILE *yyin;
extern int yylex();

void reset_included_files() {
    for (int i = 0; i < num_included_files; ++i) {
        free((char *)included_files[i]);
    }
    num_included_files = 0;
}

int is_file_included(const char *filename) {
    for (int i = 0; i < num_included_files; ++i) {
        if (strcmp(included_files[i], filename) == 0) {
            return 1;
        }
    }
    return 0;
}

void add_included_file(const char *filename) {
    if (num_included_files < MAX_FILES) {
        included_files[num_included_files++] = strdup(filename);
    } else {
        fprintf(stderr, "Error: Too many included files\n");
        exit(EXIT_FAILURE);
    }
}

void handle_include(const char *filename) {
    if (is_file_included(filename)) {
        fprintf(stderr, "Error: Circular include detected with file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    add_included_file(filename);

    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open include file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    yyin = file; // Set the new input file for the lexer
}

