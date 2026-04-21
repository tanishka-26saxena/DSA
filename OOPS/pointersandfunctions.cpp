#include<iostream>
using namespace std;
/*void printpointer(int *p)
{
    cout<<p<<endl;
    cout<<*p<<endl;
    p++;
    cout<<p<<endl;
   *p=*p+1;
    cout<<*p<<endl;
}
*/

/*int getval(int arr[])
{
    cout<<"size-> "<<sizeof(arr)<<endl;
}
int getsize(int *arr)
{
    cout<<"size- "<<sizeof(arr)<<endl;
}
int main()
{
    int value=56;
    int *p=&value;
    printpointer(p);
    
   int a[5]={1,2,3,4,5};
    cout<<"size->"<<sizeof(a)<<endl;
    getval(a);
    getsize(a);

    return 0;
}
*/

int main()
{
    int v=5;
    int *p=&v;
    int **ptr=&p;

    cout<<v<<endl;
    cout<<&v<<endl;
    cout<<*p<<endl;
    cout<<p<<endl;
    cout<<&p<<endl;
    cout<<**ptr<<endl;
    cout<<*ptr<<endl;
    cout<<ptr<<endl;
    cout<<*p+1<<endl;;
    cout<<p+1<<endl;
    cout<<*ptr+1<<endl;
    cout<<**ptr+1<<endl;
    cout<<ptr<<endl;

    return 0;
}

