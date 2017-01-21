#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "validator.h"

bool isOperator(char c) {
    if (c == '+' || c == '*' || c == '-')
		return true;
	else
		return false;
}

int getPivotOperatorPosition(char* expr) {
    int parenthesisCount = 0;
    int i = 0;
    char* exprTmp = expr;
    while(exprTmp) {
        if(exprTmp[0] == '(')
            parenthesisCount++;
        else if(exprTmp[0] == ')')
            parenthesisCount--;
        if(parenthesisCount == 1 && isOperator(exprTmp[0]))
            return i;
        i++;
    }
    return -1;
}

int getNextVar(char* line) {

}

int getNextVal(char* line) {
    
}

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

PairInt** parseInitialisationList(char* line, int maxNumOfVars) {
    int i = 0;
    char* linePtr = line;
    linePtr = line;
    PairInt** initList = malloc(sizeof(PairInt*) * maxNumOfVars);
    while(linePtr) {
        int varNum = getNextVar(linePtr);
        int varVal = getNextVal(linePtr);
        PairInt* pairInt = createPairInt(varNum, varVal);
        initList[i] = pairInt;
        i++;
    }
    return initList;
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