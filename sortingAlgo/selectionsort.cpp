#include<iostream>
#include<vector>
using namespace std;
int sort(vector<int> &arr,int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min_index=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min_index])
            {
                min_index=j;
            }
        }
        swap(arr[min_index],arr[i]);
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