#include<iostream>
#include<vector>
using namespace std;
bool check(vector<int> vec,int num)
{
    int c;
    for(int i=0;i<num;i++)
    {
        if(vec[i-1]>vec[i])
        {
            c++;
        }
    }
    if(vec[num-1]>vec[0])
    {
        c++;
    }
    return c<=1;
}
int main()
{
    vector<int> v;
    int n;
    
    cout << "Enter length of array: ";
    cin >> n;
    
    int ele;
    
    cout << "Enter array:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        v.push_back(ele);
    }
    
    cout << "Entered array is:\n";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    
   
   bool checked= check(v, n);
   if(checked)
   {
    cout<<"is sorted and rotated"<<endl;
   }
   else
   {
    cout<<"not sorted and rotated";
   }
    
    return 0;
}