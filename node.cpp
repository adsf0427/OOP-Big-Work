//
// Created by zsx on 2019/3/31.
//

#include "node.h"

float Node::operator+(const Node& x) const{
    return value+x.value;
}

float Node::operator-(const Node& x) const{
    return value-x.value;
}

float Node::operator*(const Node& x) const{
    return value*x.value;
}

float Node::operator/(const Node& x) const{
    if(x.value == 0) errortype =2;
    else return value/x.value;
    return 0;
}

void Placeholder_Node::set_val(float val) {
    value = val;
    beenset = true;
}

void Placeholder_Node::reset() {
    beenset = false;
    value = 0;
}


void Placeholder_Node::cal() {
    if(errortype) return;
    if (!beenset) errortype=1;
}


void Operation_Node_2::cal() {
    if(errortype) return;
    input1->cal();
    input2->cal();
}

void Operation_Plus_Node::cal() {
    if(errortype) return;
    Operation_Node_2::cal();
    value = *input1 + *input2;
}

void Operation_Minus_Node::cal() {
    if(errortype) return;
    Operation_Node_2::cal();
    value = *input1 - *input2;
}

void Operation_Multiple_Node::cal() {
    if(errortype) return;
    Operation_Node_2::cal();
    value = *input1 * *input2;
}

void Operation_Division_Node::cal() {
    if(errortype) return;
    Operation_Node_2::cal();
    value = *input1 / *input2;
}
