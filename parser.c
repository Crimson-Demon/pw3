#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "validator.h"

bool parseInputParameters(char* line, int params[3]) {
    char** results = str_split(line, ' ');
    params[0] = atoi(results[0]);
    params[1] = atoi(results[1]);
    params[2] = atoi(results[2]);
    for(int i = 0; *(results + i); i++)
        free(*(results + i));
    free(results);
    return true;
}

CircuitGraph* parseCircuitEquation(char* line) {
    
}

int** parseInitialisationList(char* line) {

}

void parse() {
    int params[3];
    char* line = NULL;
    size_t len = 0;
    int read = 0;

    read = getline(&line, &len, stdin);
    #ifdef D_DEBUG
    if(read == -1)
        fprintf(stderr, "Reading error!");
    #endif // D_DEBUG
    parseInputParameters(line, params);
    int N = params[0];
    int K = params[1];
    int V = params[2];
    if(line)
        free(line);

    for(int i = 0; i < K; i++) {
        read = getline(&line, &len, stdin);
        #ifdef D_DEBUG
        if(read == -1)
            fprintf(stderr, "Reading error!");
        #endif // D_DEBUG
        parseCircuitEquation(line);
        if(line)
            free(line);
    }

    for(int i = K; i < N; i++) {
        read = getline(&line, &len, stdin);
        #ifdef D_DEBUG
        if(read == -1)
            fprintf(stderr, "Reading error!");
        #endif // D_DEBUG
        parseInitialisationList(line);
        if(line)
            free(line);
    }
}