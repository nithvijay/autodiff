#include <stdio.h>
#include <iostream>
#include "Node.h"
#include "ComputationGraph.h"

void LinearRegression(int epochs, float learning_rate);


int main(int argc, const char *argv[]){
    LinearRegression(1000, 0.001);
    return 0;
}
 /*
 TODO:
 
 1. Add support for vectors and vector operations
 2. Refactor ComputationGraph and Node
    - (Necessary?) Create subclasses of Operator for basic operations (add, subtract, multiply, divide) with backward functions
    - ComputationGraph should contain higher level operations (MSE, Linear, Sigmoid, etc.)
    - Include support for more complex operations (log, rational exponents, exp, etc.)
    - Overload operators for +,-,*,/,^
 3. Research more efficient methods instead of dynamically allocating memory for each value (creating object by value)
 4. Use smart pointers to alleviate issues with memory deallocation in the constructor
 5. Add support for matrices and matrix operations - use external library?
 */

void LinearRegression(int epochs, float learning_rate){
    /*
     Creates a Linear Regression model and learns parameters via Stochastic Gradient Descent
     */
    ComputationGraph *g = new ComputationGraph();
    
    Variable* w = new Variable(0.0, true);
    Variable* b = new Variable(0.0, true);
    
    int num_params = 2;
    Variable* params[] = {w, b};
    
    float raw_x[] = {1.0, 2.0, 3.0, 3.0, 4.0, 4.0, 6.0, 7.0, 8.0, 9.0};
    float raw_y[] = {10.0, 10.0, 10.0, 7.0, 6.0, 4.0, 5.0, 3.0, 2.0, 1.0};
    int m = 10;
    
    /*
     Support for vectors/matrices not yet implemented, so each value is given its own Variable object.
     */
    Variable* x[m];
    Variable* y[m];
    for(int i = 0; i < m; ++i){
        x[i] = new Variable(raw_x[i], false);
        y[i] = new Variable(raw_y[i], false);
    }
    
    float total_MSE = 0;
    
    // training loop
    for (int epoch = 1; epoch < epochs + 1; epoch++){
        for(int i = 0; i < m; ++i){
            Node* pred = g->Linear(w, b, x[i]);
            Node* MSE = g->MSE(pred, y[i]);
            
            total_MSE+=MSE->compute() / m;
            MSE->backward(1);
            for(int j = 0; j < num_params; ++j){
                params[j]->setValue(params[j]->getValue() - learning_rate * params[j]->grad);
                params[j]->zero_grad();
            }
        }
        if(epoch == 1 || epoch % 200 == 0)
            std::cout << "Epoch: " << epoch << ": \n\tMSE: " << total_MSE << "\n\tw,b: " << w->getValue() << ", " << b->getValue() << std::endl;
        
        total_MSE = 0;
    }
}
