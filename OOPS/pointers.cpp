#include<iostream>
using  namespace std;
int main()
{
    int num=523;
    int *p=&num;

   /* cout<<"value of num: "<<num<<endl;
    cout<<"address of num: "<<p<<endl;
    cout<<"value mapped in p pointer is: "<<*p<<endl;
    cout<<"size of num: "<<sizeof(num)<<endl;
    cout<<"size of pointer: "<<sizeof(p)<<endl;
    */


    //playing with pointers

   /* int a=num;
    cout<<"value of a beforeis: "<<a<<endl;

    a++;
    cout<<"value of a after is: "<<a<<endl;
    cout<<"value of num is: "<<num<<endl;
    cout<<"value mapped in pointer before is: "<<*p<<endl;
    (*p)++;
    cout<<"value mapped in pointer after is: "<<*p<<endl;
    cout<<"value of num after pointer increment is: "<<num<<endl;
*/


    //copying pointer
    int *q=p;
    cout<<"value mapped in new pointer before is: "<<*q<<endl;
    cout<<"value mapped in old pointer before is: "<<*p<<endl;
    cout<<"address of new pointer is: "<<q<<endl;
    cout<<"address of old pointer is: "<<p<<endl;

    //pointer arithmetics
    cout<<"value mapped in p before is:"<<*p<<endl;
    (*p)++;
    cout<<"value mapped in p after is:"<<*p<<endl;

    cout<<"address stored in p before is: "<<p<<endl;
    p++;
    cout<<"address stored in p after is: "<<p<<endl;//increases by 4 values because on increment of 1 in pointer address it increases its memory by 4 bytes(memory taken by the data type of variable)




    return 0;

}