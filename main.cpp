#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <sstream>
#include <stack>
#include "graph.h"

using namespace std;

int optype(string s);

int main() {
    freopen("in.txt","r",stdin);
    int n;
    cin >> n;
    Graph tf;
    for (int i = 0; i < n; ++i) {
        string name, j;
        cin >> name >> j;
        if (j == "P") tf.insertP(name);
        else if (j == "C") {
            float val;
            cin >> val;
            tf.insertC(name, val);
        }
    }
    int m;
    cin >> m; getchar();
    stack<string> opnd;
    for (int i = 0; i < m; ++i) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string name, temp, op;
        ss >> name;
        unsigned int p = s.find('=');
        ss.clear();
        ss.str(s.substr(p+2));
        while (ss >> temp) {
            if (optype(temp) == 0) opnd.push(temp);
            else op = temp;
        }
        int type = optype(op);
        if (type == 1) {
            tf.insertO(name,op,opnd.top());
            opnd.pop();
        } else if (type == 2) {
            string right = opnd.top();
            opnd.pop();
            string left = opnd.top();
            opnd.pop();
            tf.insertO(name,op,left,right);
        } else if (type == 3) {

        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        string op;
        cin >> op;
        if (op == "EVAL"){
            string resname,argname;
            cin>>resname;
            int Pnum;
            cin>>Pnum;
            vector<pair<string,float> > argumentP;
            while(Pnum--){
                float value;
                cin>>argname>>value;
                argumentP.emplace_back(make_pair(argname,value));
            }
            tf.Eval(resname,argumentP);
        }
    }
}

int optype(string s) {
    if (s == "sin" || s == "log" || s == "exp" || s == "tanh" || s == "sigmoid") return 1;
    if (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/' || s[0] == '>' || s[0] == '<' || s[0] == '=') return 2;
    if (s == "COND") return 3;
    return 0;
}