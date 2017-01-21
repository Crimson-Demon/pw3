#ifndef PARSER_H
#define PARSER_H

#include <stdbool.h>
#include "graph.h"
#include "util.h"

bool parseInputParameters(char* line, int params[3]);
CircuitGraph* parseCircuitEquation(char* line);
PairInt** parseInitialisationList(char* line, int maxNumOfVars);
void parse();

#endif // PARSER_H
