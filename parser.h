#ifndef PARSER_H
#define PARSER_H

#include <stdbool.h>
#include "graph.h"
#include "graph.h"

bool parseInputParameters(char* line, int params[3]);
CircuitGraph* parseCircuitEquation(char* line);
int** parseInitialisationList(char* line);
void parse();

#endif // PARSER_H
