//
//  node.cpp
//  output
//
//  Created by Nithin Vijayakumar on 8/6/20.
//  Copyright © 2020 Nithin Vijayakumar. All rights reserved.
//

#include <stdio.h>
#include "node.h"
#include <iostream>

using namespace std;

float power(float x, int n) { // x^n
    if(n < 1)
        return 1;
    else
        return x * power(x, n - 1);
}

Node::Node(){
    right = NULL;
    left = NULL;
};

float Node::compute(){
    return -999; //should never be used
}

/*--------Variable--------*/

Variable::Variable(float val, bool grad_required) : Node(){
    value = val;
    grad_required = grad_required;
    grad = 0.0;
}

float Variable::compute(){
    return value;
}

/*--------Constant--------*/

Constant::Constant(float val) : Node(){
    value = val;
}

float Constant::compute(){
    return value;
}

/*--------Operator--------*/

Operator::Operator(char op) : Node(){
    operation = op;
}

Operator::Operator(char op, Node *node1, Node *node2) : Node(){
    operation = op;
    setLeft(node1);
    setRight(node2);
}

float Operator::compute(){
    switch (operation) {
        case '+':
            cout << operation << endl;
            return left->compute() + right->compute();
        case '-':
            return left->compute() - right->compute();
        case '*':
            return left->compute() * right->compute();
        case '/':
            return left->compute() / right->compute();
        case '^':
            return power(left->compute(), int(right->compute()));
        default:
            std::cout << "not valid" << std::endl;
    }
    return 0;
}

void Operator::setLeft(Node *var){
    left = var;
}

void Operator::setRight(Node *var){
    right = var;
}


