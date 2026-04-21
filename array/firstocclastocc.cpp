#include<iostream>
using namespace std;
int firstocc(int a[],int n,int k)
{
    for(int i=0;i<n;i++)
    {
        int start=0;
        int end=n-1;
        int ans=-1;
        int mid=(start+((end-start)/2));
        while(start<=end)
        {
            if(k==a[mid])
            {
                ans=mid;
                end=mid-1;
                
            }
            else if(k>a[mid])
            {
                start=mid+1;
            }
            else if(k<a[mid])
            {
                
                end=mid-1;
            }
            mid=(start+((end-start)/2));
            
            
        }
        return ans;

    }
}
int lastocc(int a[],int n,int k)
{
    for(int i=0;i<n;i++)
    {
        int start=0;
        int end=n-1;
        int ans=-1;
        int mid=(start+((end-start)/2));
        while(start<=end)
        {
            if(k==a[mid])
            {
                ans=mid;
                start=mid+1;
            
            }
            else if(k>a[mid])
            {
                start=mid+1;
            }
            else if(k<a[mid])
            {
                
                end=mid-1;
            }
            mid=(start+((end-start)/2));
           
            
        }
        return ans;

    }
}
int main()
{
    int arr[100];
    int num;
    cout<<"enter the lenth of array"<<endl;
    cin>>num;

    cout<<"enter array in sorted  form"<<endl;
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
    int key;
    cout<<"enter the number to be seached\n";
    cin>>key;
    int indexf=firstocc(arr,num,key);
    int indexl=lastocc(arr,num,key);
    cout<<"index of the first occurrence of the searched number in array is "<<indexf<<endl;
    cout<<"index of the first occurrence of the searched number in array is "<<indexl<<endl;
    cout<<"number of occurences are "<<((lastocc(arr,num,key)-firstocc(arr,num,key)+1));
    return 0;
}
