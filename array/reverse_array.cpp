#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void reverse(vector<int>vec , int num)
{
    int s=0;
    int e=num-1;
    while(s<=e)
    {
        swap(vec[s],vec[e]);
        s++;
        e--;
    }
    cout<<"reversed array is \n";
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
    reverse(v,n);
    return 0;

}