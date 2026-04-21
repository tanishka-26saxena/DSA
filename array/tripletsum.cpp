#include<iostream>
#include<vector>
using namespace std;
int main()
{
int n;
cout<<"enter the length"<<endl;
cin>>n;

vector<int>v;
for(int i=0;i<n;i++)
{
    int ele;
    cin>>ele;
    v.push_back(ele);
}
int s;
cout<<"enter the number whose triplets of sum u want"<<endl;
cin>>s;
vector<vector<int>>ans;
//to find tripletsum
for(int i=0;i<n;i++)
{
    for(int j=i+1;j<n;j++)
    {
        for(int k=j+1;k<n;k++)
        {
        if(v[i]+v[j]+v[k]==s)
        {
            vector<int>temp;
            temp.push_back(v[i]);
            temp.push_back(v[j]);
            temp.push_back(v[k]);
            
            ans.push_back(temp);
            
        }
        }
    }
}
for (auto pair : ans)
    {
        cout << pair[0] << " , " << pair[1] << " , " << pair[2] <<endl;
    }
return 0;

}