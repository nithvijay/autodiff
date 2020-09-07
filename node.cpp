#include <stdio.h>
#include "Node.h"
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
    grad_required = false;
};

Node::~Node(){
    /*
     Major problem with objects that have multiple pointers pointing at them. E.g. a weight variable that needs to be used with each set of training instances.
     
     Possible resolution is replacing the type of left and right from a raw pointer into a smart pointer. Most pointers, for objects such as operators, will be fine as unique_ptr, but pointeres for shared objects will need to be shared_ptr.
     */
//    if(left != NULL){
//        delete left;
//    }
//
//    if(right != NULL){
//        delete right;
//    }

}

float Node::compute(){
    return -999; //should never be used
}

std::string Node::print() const{
    return "this should never happen";
}

void Node::backward(float part_deriv){
    std::cout << "should not happen" << std::endl;
}

float Node::getValue() const{
    return -123; //should never happen
}

bool Node::getGradRequired() const{
    return grad_required;
}

/*--------Variable--------*/

Variable::Variable(float val, bool grad_required) : Node(){
    value = val;
    this->grad_required = grad_required;
    grad = 0.0;
}

Variable::~Variable(){
    if(left != NULL){
        delete left;
    }
    
    if(right != NULL){
        delete right;
    }
}

float Variable::compute(){
    //cout << this->value << "   \t" << this->getGradRequired() << endl;
    return value;
}

std::string Variable::print() const{
    return std::to_string(value);
}

void Variable::backward(float part_deriv){
    this->grad = part_deriv + this->grad;
}

void Variable::zero_grad(){
    grad = 0.0;
}

float Variable::getValue() const{
    return value;
}

void Variable::setValue(float val){
    value = val;
}

bool Variable::getGradRequired() const{
    return grad_required;
}
/*--------Constant--------*/

Constant::Constant(float val) : Node(){
    value = val;
    grad_required = false;
}

Constant::~Constant(){
    if(left != NULL){
        delete left;
    }
    
    if(right != NULL){
        delete right;
    }
}

float Constant::compute(){
    return value;
}

std::string Constant::print() const{
    return std::to_string(value);
}

void Constant::backward(float part_deriv){
}

float Constant::getValue() const{
    return value;
}

/*--------Operator--------*/

Operator::Operator(char op) : Node(){
    operation = op;
    
}

Operator::~Operator(){
    if(left != NULL){
        delete left;
    }
    
    if(right != NULL){
        delete right;
    }
}

Operator::Operator(char op, Node *node1, Node *node2) : Node(){
    operation = op;
    value = 0.0;
    setLeft(node1);
    setRight(node2);
}


float Operator::compute(){
    switch (operation) {
        case '+':
            value = left->compute() + right->compute();
            break;
        case '-':
            value = left->compute() - right->compute();
            break;
        case '*':
            value = left->compute() * right->compute();
            break;
        case '/':
            value = left->compute() / right->compute();
            break;
        case '^':
            value = power(left->compute(), int(right->compute()));
            break;
        default:
            std::cout << "not valid" << std::endl;
    }
    if (left->getGradRequired() || right->getGradRequired()) {
        grad_required=true;
    }
    return value;
    return 0;
}

void Operator::setLeft(Node *var){
    left = var;
}

void Operator::setRight(Node *var){
    right = var;
}

float Operator::getValue() const{
    return value;
}

bool Operator::getGradRequired() const{
    return grad_required;
}

std::string Operator::print() const{
    string ret_val = "";
    if (left != NULL)
        ret_val+= "(" + left->print();
    ret_val += " " + std::string(1, operation) + " ";
    if (right != NULL)
        ret_val+= right->print() + ")";
    return ret_val;
}

void Operator::backward(float part_deriv){
    //std::cout << left->getValue() << " (" << left->getGradRequired() << ") " << operation << " " << right->getValue() << " (" << right->getGradRequired() << ") " << std::endl;
    if (grad_required){
        switch (operation) {
            case '+':
                left->backward(part_deriv); //no backward function
                right->backward(part_deriv);
                break;
            case '-':
                left->backward(part_deriv); //no backward function
                right->backward(-1 * part_deriv);
                break;
            case '*':
                left->backward(right->getValue() * part_deriv);
                right->backward(left->getValue() * part_deriv);
                break;
            case '/':
                left->backward(1 / right->getValue() * part_deriv);
                right->backward(value * -1 / right->getValue() * part_deriv);
                break;
            case '^':
                left->backward(right->getValue() * power(left->getValue(), right->getValue()-1) * part_deriv);
                break;
            default:
                std::cout << "not valid" << operation << std::endl;
        }
    }
}
