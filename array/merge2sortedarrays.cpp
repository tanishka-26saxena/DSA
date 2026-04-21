#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>&vec1 , vector<int>&vec2, int num1,int num2,vector<int>&vec3)
{
    int i=0;
    int j=0;
    int k=0;
    while(i<num1 && j<num2)
    {
        if(vec1[i]<vec2[j])
        {
            vec3[k]=vec1[i];
            i++;
            k++;
        }
        else
        {
            vec3[k]=vec2[j];
            k++;
            j++;
        }
    }
    while(i<num1)
    {
        vec3[k]=vec1[i];
        k++;
        i++;
    }
    while(j<num2)
    {
        vec3[k]=vec2[j];
        k++;
        j++;
    }
    cout<<"merged array is\n";
    for(int l=0;l<num1+num2;l++)
    {
        cout<<vec3[l]<<" ";
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
    int n3=n+m;
    vector<int> v3(n3);
    merge(v1,v2,n,m,v3);
    return 0;
}