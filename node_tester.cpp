#include <stdio.h>
#include <iostream>
#include "node.h"
#include "ComputationGraph.h"

using namespace std;

int main(int argc, const char *argv[]){
    CG *g = new CG();
    
    Variable* x1 = new Variable(1, false);
    Variable* x2 = new Variable(2, false);
    
    Variable* y1 = new Variable(1, false);
    Variable* y2 = new Variable(2, false);
    
    Variable* w = new Variable(.7, false);
    
    Variable* b = new Variable(.5, false);
    
    Constant* CONST_2 = new Constant(2);
    // Explicit Graph Construction
    
    Node* yhat1 = g->add(g->multiply(w, x1), b);
    Node* yhat2 = g->add(g->multiply(w, x2), b);
    
    Node* square_error1 = g->power(g->subtract(yhat1, y1), CONST_2); // (yhat - y)^2
    Node* square_error2 = g->power(g->subtract(yhat2, y2), CONST_2);
    
    Node* MSE = g->divide(g->add(square_error1, square_error2), CONST_2);
    
    
    
    cout << MSE->compute() << endl;
    
    return 0;
}
