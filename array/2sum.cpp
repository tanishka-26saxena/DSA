#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
twosum(vector<int>vec1,vector<int>vec2)
    {
      vector<int>ans;
      int i=0;
      int j=0;
      int carry=0;
      while(i>=0 && j>=0)
      {
        int val1=vec1[i];
        int val2=vec2[j];
        int sum=val1+val2+carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
        i--;
        j--;
      }  
      while(i>=0)
      {
        int sum=carry+vec1[i];
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
        i--;

      }
      while(j>=0)
      {
        int sum=carry+vec2[j];
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
        j--;

      }
      while(carry!=0)
      {
        int sum=carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);

      }
      reverse(ans.begin(),ans.end());
      cout<<"added array is\n";
    for(int l=0;l<ans.size();l++)
    {
        cout<<ans[l]<<" ";
    }
    }
int main()
{
    vector<int>v1;
    vector<int>v2;
    int n,m;
    cout<<"enter length of first array"<<endl;
    cin>>n;
    cout<<"enter length of second array"<<endl;
    cin>>m;
    cout<<"enter first array \n";
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        v1.push_back(ele);
    }
    cout<<"enter second array \n";
    for(int i=0;i<m;i++)
    {
        int ele;
        cin>>ele;
        v2.push_back(ele);
    }
    cout<<"entered first array is"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<v1[i]<<endl;
    }
    cout<<"entered second array is"<<endl;
    for(int i=0;i<m;i++)
    {
        cout<<v2[i]<<endl;
    }
    twosum(v1,v2);
    return 0;
}

