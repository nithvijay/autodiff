#ifndef node_h
#define node_h
#include <string>

class Node { //essentially an interface
public:
    Node();
    ~Node();
    float virtual compute();
    std::string virtual print() const;
    virtual void backward(float part_deriv);
    float virtual getValue() const;
    bool virtual getGradRequired() const;
    
protected:
    Node* right;
    Node* left;
    bool grad_required;
};

class Variable : public Node { //always the leaf nodes
public:
    Variable(float val, bool grad_required);
    ~Variable();
    float compute();
    std::string print() const;
    void backward(float part_deriv);
    float getValue() const;
    void setValue(float val);
    bool getGradRequired() const;
    void zero_grad();
    float grad;
private:
    float value;
    bool grad_required;
};

class Constant : public Node {
public:
    Constant(float val);
    ~Constant();
    float compute();
    std::string print() const;
    void backward(float part_deriv);
    float getValue() const;
    
private:
    float value;
    bool grad_required;
};

class Operator : public Node { //always the inner nodes
public:
    Operator(char op);
    Operator(char op, Node* node1, Node* node2);
    ~Operator();
    
    float compute();
    std::string print() const;
    void setLeft(Node* var);
    void setRight(Node* var);
    void backward(float part_deriv);
    float getValue() const;
    bool getGradRequired() const;
    
private:
    char operation;
    float value;
    bool grad_required;
};

#endif /* Node_h */
