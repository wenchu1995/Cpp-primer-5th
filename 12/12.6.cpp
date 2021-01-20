//
// Created by user on 2021/1/11.
//
#define NDEBUG

#include <cassert>
#include <fstream>
#include <sstream>
#include <memory>
#include "include/headers.h"  //这个自己在跟目录下添加头文件,里面包含可能用到的头文件

using namespace std;

vector<int>*alloc_vector(){
    return new vector<int>();
}

void assign_vector(vector<int> *v){
    int i;
    while(cin >> i){
        v->push_back(i);
    }
}

void print_vector(vector<int>*p){
    for(auto x:*p){
        cout<<x<<"\t";
    }
    cout<<endl;
}
int main()
{
    auto *v = alloc_vector();
    cout<<"add num:\n";
    assign_vector(v);
    cout<<"print num\n";
    print_vector(v);
    delete v;
    return 0;
}
