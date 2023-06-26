#include<iostream>
using namespace std;

class A{
    public:
    void sayHello(){
        cout<<"Hello Sutam"<<endl;
    }

    int sayHello(string name,int n)
    {
        cout<<"Hello"<<name<<n<<endl;
        return 1;
    }

    void sayHello(string name){
        cout<<"Hello "<<name<<endl;
    }
};

int main()
{
    A obj;
    obj.sayHello();

    return 0;
}