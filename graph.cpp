//
// Created by zsx on 2019/4/6.
//
#include "graph.h"

void Graph::insertP(const string &name) {
    Map[name]=new Placeholder_Node(name,errortype);
}

void Graph::insertC(const string &name, float val) {
    Map[name] = new Constant_Node(name,errortype,val);
}

void Graph::insertO(const string &name,const string &op,const string &input1,const string &input2) {
    if(op[0]=='+') Map[name]=new Operation_Plus_Node(name,errortype,Map[input1],Map[input2]);
    else if (op[0] == '-') Map[name]=new Operation_Minus_Node(name,errortype,Map[input1],Map[input2]);
    else if (op[0] == '*') Map[name]=new Operation_Multiple_Node(name,errortype,Map[input1],Map[input2]);
    else if (op[0] == '/') Map[name]=new Operation_Division_Node(name,errortype,Map[input1],Map[input2]);
}

void Graph::insertO(const string &name, const string &op, const string &input) {

}

void Graph::Eval(const string &name, const vector<pair<string, float> >& Pinitlist){
    errortype = 0;

    for(const auto &i :Pinitlist){
        auto now = dynamic_cast<Placeholder_Node*>(Map[i.first]);
        now->set_val(i.second);
    }

    Map[name]->cal();

    if (errortype == 0) cout<<std::fixed<<setprecision(4)<<Map[name]->getvalue()<<endl;
    else if (errortype == 1) cout<<"ERROR: Placeholder missing\n";
    else if (errortype == 2) cout<<"ERROR: Division by zero\n";

    for(const auto &i :Pinitlist){
        auto now = dynamic_cast<Placeholder_Node*>(Map[i.first]);
        now->reset();
    }
}


