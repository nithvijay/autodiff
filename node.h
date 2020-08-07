#ifndef node_h
#define node_h
class Node { //essentially an interface
public:
    Node();
    float virtual compute();
protected:
    Node* right;
    Node* left;
};

class Variable : public Node { //always the leaf nodes
public:
    Variable(float val, bool grad_required);
    float compute();
    
private:
    float value;
    float grad;
    bool grad_required;
};

class Operator : public Node { //always the inner nodes
public:
    Operator(char op);
    Operator(char op, Node* node1, Node* node2);
    float compute();
    void setLeft(Node* var);
    void setRight(Node* var);
private:
    char operation;
};

class Constant : public Node {
public:
    Constant(float val);
    float compute();
    
private:
    float value;
};


#endif /* Node_h */
