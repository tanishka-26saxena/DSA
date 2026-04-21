#include<iostream>
using namespace std;

int partition(int arr[],int s, int e)
{
    int v=arr[s];
    int c=0;
    for(int i=0;i<e;i++)
    {
        if(arr[i]<=v)
        {
            c++;
        }
    }
    int pivotindex= s+c;
    swap(arr[s],arr[pivotindex]);

    int i=s,j=e;
    while(i<pivotindex && j>pivotindex)
    {
        while(arr[i]<v)
        {
            i++;
        }
        while(arr[j]>v)
        {
            j--;
        }
        if(arr[i]>v && arr[j]<v)
        {
            swap(arr[i++],arr[j--]);
        }
        
        return pivotindex;
    }
}
void quicksort(int arr[],int s,int e)
{
    //base case
    if(s>=e)
    {
        return ;
    }
    
    //partition krenge 
    int p=partition(arr,s,e);
    //left side sort krenge
    quicksort(arr,s,p-1);
    //right side sort krenge
    quicksort(arr,p+1,e);

}

int main()
{
    int arr[5]={3,2,5,3,1};
   quicksort(arr,0,4);
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}
