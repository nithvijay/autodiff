#ifndef ComputationGraph_h
#define ComputationGraph_h
#include "node.h"

class CG {
    
public:
    CG();
    Node* getRoot();
    Node* add(Node* node1, Node* node2);
    Node* subtract(Node* node1, Node* node2);
    Node* multiply(Node* node1, Node* node2);
    Node* divide(Node* node1, Node* node2);
    Node* power(Node* node1, Node* node2);
};


#endif /* ComputationGraph_h */
