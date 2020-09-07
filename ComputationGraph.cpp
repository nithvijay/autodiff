#include "ComputationGraph.h"

ComputationGraph::ComputationGraph(){};

Node* ComputationGraph::add(Node *node1, Node *node2){
    Operator *temp = new Operator('+');
    temp->setLeft(node1);
    temp->setRight(node2);
    return temp;
}

Node* ComputationGraph::subtract(Node *node1, Node *node2){
    return (new Operator('-', node1, node2));
}

Node* ComputationGraph::multiply(Node *node1, Node *node2){
    return (new Operator('*', node1, node2));
}

Node* ComputationGraph::divide(Node *node1, Node *node2){
    return (new Operator('/', node1, node2));
}

Node* ComputationGraph::power(Node *node1, Node *node2){
    return (new Operator('^', node1, node2));
}

Node* ComputationGraph::Linear(Node *w, Node *b, Node *x){
    return add(multiply(w, x), b);
}

Node* ComputationGraph::MSE(Node *pred, Node *y){
    return power(subtract(pred, y), new Constant(2));
}
