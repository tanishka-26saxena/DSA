#include<iostream>
#include<vector>
using namespace std;
int sort(vector<int> &arr,int n)
{
    for(int i=0;i<n;i++)
    {
        int temp=arr[i];
        int j=i-1;
        while(j>=0)
        {
            if(arr[j]>temp)
            {
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
            j--;
        }
        arr[j+1]=temp;
    }
    cout<<"sorted array is "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}
int main()
{
    int num;
    cout<<"enter length of array"<<endl;
    cin>>num;
    vector <int> arr;
    for(int i=0;i<num;i++)
    {
        int ele;
        cin>>ele;
        arr.push_back(ele);
    }
    sort(arr,num);
    return 0;

}