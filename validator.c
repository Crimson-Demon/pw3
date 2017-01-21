#include "validator.h"
#include <stdbool.h>
#include <stdlib.h>



bool validateCircuitEquation(CircuitGraph* graph) {

}

CircuitGraph* mergeCircuitGraphs(CircuitGraph* graph1, CircuitGraph* graph2) {
    CircuitGraph* result = malloc(sizeof(CircuitGraph));
    CircuitVertex* root = NULL;

    // Ustalamy nowy korzen grafu
    // Preferujemy x0, ale jak nie ma, to bierzemy korzen graphu 1
    if((root = findVarVertex(graph1, 0)))
        result->root = root;
    else if((root = findVarVertex(graph2, 0)))
        result->root = root;
    else
        result->root = graph1->root;

    // Ustalamy liste wspolnych zmiennych
    int* vars1 = graph1->vars;
    int* vars2 = graph2->vars;
    int totalNumOfVars = graph1->numOfVars + graph2->numOfVars;
    int* varsCommon = malloc(sizeof(int) * totalNumOfVars);
    int i = 0;
    while(vars1 || vars2) {
        if(*vars1 == *vars2)
            varsCommon[i++] = *vars1;
        else if(*vars1 < *vars2)
            vars1 += 1;
        else
            vars2 += 1;
    }
    varsCommon = realloc(varsCommon, i - 1);

    // Podmieniam wskazniki odpowiadajace wspolnym zmiennym w drugim na wskazniki z pierwszego
    for(int j = 0; j < i - 1; j++) {
        // Znajduje wierzcholek odpowiadajacy zmiennej w grafie 1
        CircuitVertex* vertex1 = findVarVertex(graph1, varsCommon[j]);
        CircuitVertex** sons1 = vertex1->outgoingVertices;

        // Znajduje wierzcholek odpowiadajacy zmiennej w grafie 2
        CircuitVertex* vertex2 = findVarVertex(graph2, varsCommon[j]);
        CircuitVertex** sons2 = vertex2->outgoingVertices;
        int outgoing2 = vertex2->numOfOutgoingEdges;
   
    }

    // Kasuje wskaznik do grafu pierwszego i drugiego (ale nie kasuje samych struktur grafow)
    free(graph1->vars);
    free(graph1);
    free(graph2->vars);
    free(graph2);
    return result;
}