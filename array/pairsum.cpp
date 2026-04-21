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
cout<<"enter the number whose pairs of sum u want"<<endl;
cin>>s;
vector<vector<int>>ans;
//to find pairsum
for(int i=0;i<n;i++)
{
    for(int j=i+1;j<n;j++)
    {
        if(v[i]+v[j]==s)
        {
            vector<int>temp;
            temp.push_back(min(v[i],v[j]));
            temp.push_back(max(v[i],v[j]));
            ans.push_back(temp);
        }
        
    }
}
for (auto pair : ans)
    {
        cout << pair[0] << " , " << pair[1] << endl;
    }
return 0;

}