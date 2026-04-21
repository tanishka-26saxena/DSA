#include<iostream>
using namespace std;
/*class student
{
    private:
    int roll;
    char name[30];
    public:
    void get_data()
    {
        cout<<"enter roll number and name\n";
        cin>>roll>>name;
    }
    void put_data()
    {
        cout<<"roll number is "<<roll<<endl;
        cout<<"name is "<<name<<endl;
    }
};
int main()
{
    student stu;
    stu.get_data();
    stu.put_data();
    return 0;
}*/

//using scope resolution operator

class area
{
    int l;
    int b;
    public:
    void getd();
    void calc();
};
void area::getd()
{
    cout<<"length "<<endl;
    cin>>l;
    cout<<"breadth"<<endl;
    cin>>b;
}
void area::calc()
{
    cout<<"area is "<<l*b;
}
int main()
{
    area r;
    r.getd();
    r.calc();
    return 0;
}