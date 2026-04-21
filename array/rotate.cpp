#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<int>& vec, int num, int l)
{
    vector<int> temp(num);
    
    for (int i = 0; i < num; i++)
    {
        temp[(i + l) % num] = vec[i];
    }
    
    vec = temp;
    
    cout << "Array after rotation:\n";
    for (int i = 0; i < num; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
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
    
    int k;
    cout << "Enter the number of positions to rotate: ";
    cin >> k;
    rotate(v, n, k);
    
    return 0;
}
