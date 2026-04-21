#include<iostream>
using namespace std ;
int main()
{
    int arr[10]={1,6,3,4,1,2,3,4,2,2};
    /*
    cout<<"address of first memory block without using & is: "<<arr<<endl;
    cout<<"value of first memory block in array is: "<<arr[0]<<endl;
    cout<<"address of first memory block using & is"<<&arr[0]<<endl;
*/
    //playing with pointers in arrays

    /*cout<<*arr<<endl;
    cout<<*arr+1<<endl;
    cout<<*(arr+1)<<endl;
    cout<<arr[2]<<endl;
    cout<<*(arr+2)<<endl;
    cout<<2[arr]<<endl;
    cout<<*(2+arr)<<endl;

    */

   //printing character arrays

   char ch[6]="abcde";
   int a[6]={1,2,3,4,5,6};
   cout<<ch<<endl;
   cout<<ch[0]<<endl;
   cout<<a[0]<<endl;
   cout<<a<<endl;

   char *ptr=&ch[0];
   int *p=&a[0];
   cout<<ptr<<endl;
   cout<<p<<endl;


} 