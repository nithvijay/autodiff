#include "ComputationGraph.h"

CG::CG(){};

Node* CG::add(Node *node1, Node *node2){
    Operator *temp = new Operator('+');
    temp->setLeft(node1);
    temp->setRight(node2);
    return temp;
}

Node* CG::subtract(Node *node1, Node *node2){
    return (new Operator('-', node1, node2));
}

Node* CG::multiply(Node *node1, Node *node2){
    return (new Operator('*', node1, node2));
}

Node* CG::divide(Node *node1, Node *node2){
    return (new Operator('/', node1, node2));
}

Node* CG::power(Node *node1, Node *node2){
    return (new Operator('^', node1, node2));
}
