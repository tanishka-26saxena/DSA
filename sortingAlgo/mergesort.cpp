#include<iostream>
using namespace std;
void merge(int *arr,int s,int e)
{
    int mid=(s+e)/2;
    //left aur right part ki length calculate kr lo
    int leftlen=mid-s+1;
    int rightlen=e-mid;

    //2 arrays bna lo left aur right side ki length ke jitne
    int *left= new int(leftlen);
    int *right= new int(rightlen);

    //values copy kr lo dono arrays m main array se
    int k=s;
    for(int i=0;i<leftlen;i++)
    {
        left[i]=arr[k++];
    }

    k=mid;
    for(int i=0;i<rightlen;i++)
    {
        right[i]=arr[k++];
    }

    //merge kr lo ab dono parts ko

    int index1=0;
    int index2=0;
    k=s;
    while(index1<leftlen && index2<rightlen)
    {
        if(left[index1]<right[index2])
        {
            arr[k++]=left[index1++];
        }
        else{
            arr[k++]=right[index2++];
        }
    }
    while(index1<leftlen)
    {
        arr[k++]=left[index1++];
    }
    while(index2<rightlen)
    {
        arr[k++]=right[index2++];
    }
}
//recursion lga do
void sorting(int *arr,int s,int e)
{
    //base case
    if(s>=e)
    {
        return ;
    }
    int mid=(s+e)/2;

    //right part sort krna hai
    sorting(arr,mid+1,e);

    //left part sort krna hai
    sorting(arr,s,mid);

    //merge
    merge(arr,s,e);

}
int main()
{
    int arr[5]={3,5,3,2,1};
    sorting(arr,0,4);
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
}