#include<iostream>
#include<vector>
using namespace std;
int sort(vector<int> &arr,int n)
{
    for(int i=1;i<n;i++)//for round 1 and so on
    {
        for(int j=0;j<n;j++)//for comparison in ith rounds
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
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