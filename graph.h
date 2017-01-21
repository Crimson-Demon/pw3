#ifndef GRAPH_H
#define GRAPH_H

typedef struct CircuitVertex CircuitVertex;

struct CircuitVertex {
    int numOfOutgoingEdges;
    int numOfIngoingEdges;
    int varName;
    char* expr;
    CircuitVertex** ingoingVertices;
    CircuitVertex** outgoingVertices;
};

CircuitVertex* createCircuitVertex(int varName, char* expr);

void addOutgoingVertex(CircuitVertex* vertex1, CircuitVertex* vertex2);

void deleteCircuitVertex(CircuitVertex* vertex);

typedef struct CircuitGraph {
    int numOfVars;
    int numOfNodes;
    int* vars;
    CircuitVertex** varVertices;
    CircuitVertex* root;
} CircuitGraph;

CircuitGraph* createCircuitGraph();

void deleteCircuitGraph(CircuitGraph* graph);

CircuitVertex* findVarVertex(CircuitGraph* graph, int i);

#endif // GRAPH_H