#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
/* REMOVE EXTRA CHARACTERS STRING TO MAKE IT A PALINDROME
int main()
{
string s;
    cout<<"enter a string\n";
    cin>>s;
    /for(int i=0;i<s.length();i++)
    {
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>=0 && s[i]<=9))
        {
            continue;
        }
        else{
            s.erase(i,1);
            i--;
        }
    }
    for(int i=0;i<s.length();i++)
    {
        cout<<s[i];
    }
    return 0;
}*/
//TO FIND MAX OCCURENCE OF CHARACTERS
getmaxoccur(string st)
{
    int arr[26]={0};
    for(int i=0;i<st.length();i++)
    {
        char ch=st[i];
        int number=0;
        number=ch-'a';
        arr[number]++;
    }
    int maxi=-1;
    int ans=0;
    for(int i=0;i<26;i++)
    {
        if(maxi<arr[i])
        {
            maxi=arr[i];
            ans=i;
        }
    }
    return 'a'+ans;
}
int main()
{
    string s;
    cin>>s;
    char max=getmaxoccur(s);
    cout<<max;
    return 0;
}