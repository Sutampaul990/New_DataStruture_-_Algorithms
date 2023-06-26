#include<iostream>
using namespace std;

class Animal{
    public:
    int age;
    int weight;
    public:
    void speak(){
        cout<<"Speaking"<<endl;
    }
};

class A{
    public:
    void func1(){
        cout<<"Speaking for function 1"<<endl;
    }
};

class B:public A{
    public:
    void func2(){
        cout<<"Function 2"<<endl;
    }
};
class C:public A,public Animal{
    public:
    void func3(){
        cout<<"Function 3"<<endl;
    }
};

int main()
{

    B h1;
    C h2;

    // For Hierarchical Inheritance

    h1.func1();
    h1.func2();
    h2.func1();
    h2.func3();

    // For multilevel Inheritance
    h2.speak();

    return 0;
}