#ifndef ComputationGraph_h
#define ComputationGraph_h
#include "Node.h"

class ComputationGraph {
    
public:
    ComputationGraph();
    Node* getRoot();
    Node* add(Node* node1, Node* node2);
    Node* subtract(Node* node1, Node* node2);
    Node* multiply(Node* node1, Node* node2);
    Node* divide(Node* node1, Node* node2);
    Node* power(Node* node1, Node* node2);
    Node* Linear(Node* w, Node* b, Node* x);
    Node* MSE(Node* pred, Node* y);
};


#endif
