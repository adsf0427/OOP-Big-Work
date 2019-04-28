//
// Created by zsx on 2019/4/6.
//

#pragma once
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include "node.h"
using std::string;
using std::map;
using std::vector;
using std::pair;
using std::cout;
using std::setprecision;
using std::endl;
class Graph
{
private:
    map<string,Node*> Map;
    vector<Node*> nodes;
    vector<float> result;
    int errortype = 0;
public:
    void insertP(const string& name);
    void insertC(const string &name,float val);
    void insertO(const string &name,const string &op,const string &input);
    void insertO(const string &name,const string &op,const string &input1,const string &input2);
    void Eval(const string &name,const vector<pair<string,float> >&);
    ~Graph(){
        for(const auto &i:Map){
            delete i.second;
        }
    }
};
