#include<iostream>
using namespace std;
int search(int arr[],int num,int k)
{
    int start=0;
    int end=num-1;
    int mid; //when you will solve this you will again get (start+end)/2  but it is written in this manner so that it doesnt get caught in integer constraints
    mid=(start+((end-start)/2)); 
    while(start<=end)
    {
        if(k==arr[mid])
        {
            return mid;
        }
        else if(k>arr[mid])
        {
            start=mid+1;
        }
        else if(k<arr[mid])
        {
            end=mid-1;
        }
        mid=(start+((end-start)/2)); 
    }
    return -1;
}
int main()
{
    int a[100];
    int n;
    cout<<"enter the lenth of array"<<endl;
    cin>>n;

    cout<<"enter array in sorted  form"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int key;
    cout<<"enter the number to be seached\n";
    cin>>key;
    int index=search(a,n,key);
    cout<<"index of the searched number in array is "<<index<<endl;
    return 0;
}