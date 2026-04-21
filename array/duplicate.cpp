#include<iostream>
#include<vector>
using namespace std;

int main()
{
    cout << "Enter the length of the array: ";
    int n;
    cin >> n;
    vector<int> v1;
    vector<int> v2;
    cout << "Enter the elements of the first array in sorted form: \n";
    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        v1.push_back(element);
    }
    cout << "Enter the elements of the second array in sorted form: \n";
    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        v2.push_back(element);
    }
    vector<int> inter;
    int count = 0;
    int i=0,j=0;
    while(i<n && j<n)
    {
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            if (v1[i] == v2[j])
            {
            inter.push_back(j);  // Store the index from the second array
               i++;
               j++;
            }
            else if(v1[i]<v2[j])
            {
                i++;
            }
            else{
                j++;
            }
        }
    }
    }
    
    cout << "Indices of common elements: ";
    for (i = 0; i < inter.size(); i++)
    {
        cout << inter[i] << " ";
    }
    
    return 0;
}
