#ifndef GRAPH_H
#define GRAPH_H

typedef struct CircuitVertex CircuitVertex;

typedef struct CircuitVertex {
    int numOfEdges;
    int varName;
    char* expr;
    CircuitVertex** vertices;
} CircuitVertex;



typedef struct CircuitGraph {
    int maxNumOfVars;
    char** vars;
    CircuitVertex* root;
} CircuitGraph;

#endif // GRAPH_H