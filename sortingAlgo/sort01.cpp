#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cout<<"enter length f array"<<endl;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        v.push_back(ele);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=n;j>0;j--)
        {
            
            if(v[i]==0 && i<j)
            {
                i++;
            }
            else if(v[j]==1 && i<j)
            {
                j--;
            }
            else if(v[i]==1 && v[j]==0 && i<j)
            {
                int temp=0;
                temp=v[i];
                v[i]=v[j];
                v[j]=temp;
                i++;
                j--;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<v[i];
    }
}
