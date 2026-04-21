#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
movezeroes(vector<int>vec , int num)
{
    for(int i=0;i<num;i++)
    {
        for (int j=i+1;j<num;j++)
        {
            if(vec[j]!=0)
            {
                swap(vec[i],vec[j]);
            }
            
        }
        
    }
    cout<<"after array is \n";
    for(int i=0;i<num;i++)
    {
        cout<<vec[i];
    }
}
int main()
{
    vector<int>v;
    int n;
    cout<<"enter length of array"<<endl;
    cin>>n;
    int ele;
    cout<<"enter array \n";
    for(int i=0;i<n;i++)
    {
        cin>>ele;
        v.push_back(ele);
    }
    cout<<"entered array is"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<endl;
    }
    movezeroes(v,n);
    return 0;

}