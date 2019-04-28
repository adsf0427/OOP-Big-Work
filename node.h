//
// Created by zsx on 2019/3/31.
//
#pragma once

#include <string>

using std::string;
using std::move;

class Node {
protected:
    float value;
    string name;
    int& errortype;
public:
    Node() = delete;

    Node(string _name,int& _errortype,float _value = 0) : name(move(_name)), value(_value), errortype(_errortype){}

    float operator+(const Node& x) const;

    float operator-(const Node& x) const;

    float operator*(const Node& x) const;

    float operator/(const Node& x) const;

    float getvalue() { return value; }

    virtual void cal(){}

    virtual ~Node()= default;
};

class Operation_Node_1 : public Node {
    Node *input;
};

class Operation_Node_2 : public Node {
protected:
    Node *input1, *input2;
public:
    Operation_Node_2(string name,int& _errortype, Node *x1, Node *x2) : Node(move(name),_errortype), input1(x1), input2(x2) {}

    void cal() override;
};

class Operation_Plus_Node : public Operation_Node_2 {
    using Operation_Node_2::Operation_Node_2;

    void cal() override;
};

class Operation_Minus_Node : public Operation_Node_2 {
    using Operation_Node_2::Operation_Node_2;

    void cal() override;
};

class Operation_Multiple_Node : public Operation_Node_2 {
    using Operation_Node_2::Operation_Node_2;

    void cal() override;
};

class Operation_Division_Node : public Operation_Node_2 {
    using Operation_Node_2::Operation_Node_2;

    void cal() override;
};

class Variable_Node : public Node {
public:
    void set_val();
};

class Placeholder_Node : public Node {
private:
    bool beenset = false;
public:
    Placeholder_Node(string name,int& _errortype) : Node(move(name),_errortype) {}

    void set_val(float val);
    void cal() override;
    void reset();
};

class Constant_Node : public Node {
public:
    Constant_Node(string name, int& _errortype,float value) : Node(move(name), _errortype,value) {}
};