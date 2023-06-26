#include<iostream>
using namespace std;

//Encapsulation : Data/Information Hiding

class Student{
    private:
        string name;
        int age;
        int height;
    public:
        int getAge(){
            return this->age;
        }
};

int main()
{
    Student first;

    cout<<"All is ok"<<endl;

    return 0;
}