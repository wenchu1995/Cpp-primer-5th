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

class strBob {
public:
    typedef vector<string>::size_type size_type;
    strBob();
    strBob(initializer_list<string> il);
    size_type size()const { return data->size(); }
    bool empty()const { return data->empty(); }
    void push_back(const string& s) { data->push_back(s); }
    void pop_back();
    string& front() const;
    string& back() const;
private:
    shared_ptr<vector<string>>data;
    void check(size_type i, const string& msg)const;
};

strBob::strBob() {
    data = make_shared<vector<string>>();
}
strBob::strBob(initializer_list<string>il) :data(make_shared<vector<string>>(il)) {}

void strBob::check(size_type i, const string& msg) const
{
    if (i >= data->size()) {
        throw out_of_range(msg);
    }
}

string& strBob::front() const {
    check(0, "front on empty strBob");
    return data->front();
}

string& strBob::back() const{
    check(0, "back on empty strBob");
    return data->back();
}

void strBob::pop_back() {
    check(0, "pop back on empty strBob");
    data->pop_back();
}

int main()
{
    strBob b1 = { "a","v","sd" };
    strBob b2 = b1;
    b1.push_back("hello");
    cout << b2.back() << endl;  //hello
    cout << b1.back() << endl;   //hello
    system("pause");
    return 0;
}
