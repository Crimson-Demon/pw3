#ifndef PARSER_H
#define PARSER_H

#include <stdbool.h>
#include "graph.h"

bool parseInputParameters(char* line, int params[3]);
bool parseCircuitEquation(char* line);
bool parseInitialisationList(char* line);
void parse();

#endif // PARSER_H
