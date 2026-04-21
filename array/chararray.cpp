#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    char ch[20];
    cout<<"enter your name"<<endl;
    cin>>ch;
    //TO CALCULATE LENGTH OF CHAR ARRAY
    int c=0;
    for(int i=0;ch[i]!='\0';i++)
    {
        c++;
    }
    
    cout<<"length of your name is ";
    cout<<c<<endl;
    //TO REVERSE CHARACTER ARRAY
    char temp[c];
    for(int i=0;i<c;i++)
    {
        temp[i]=ch[i];
    }

    int s=0;
    int e=c-1;
    for(int i=0;i<c/2;i++)//or while(s<e)
    {
        swap(ch[s],ch[e]);
        s++;
        e--;
    }
    cout<<"reversed naame is "<<endl;
    cout<<ch<<endl;
    //TO CHECK PALINDROME OR NOT (2 APPROACHES)
    /*for(int i=0;i<c;i++)
    {
    if(temp[i]!=ch[i])
    {
        cout<<"not palindrome";
    }
    else{
        cout<<"palindrome";
    }*/
    int st=0;
    int en=c-1;
    int t=0;
    for(int i=0;i<c/2;i++)
    {
        if(ch[st]==ch[en])
        {
            t++;
            st++;
            en--;
        }
    }
    if(t>0)
    {
        cout<<"palindrome\n";
    }
    else{
        cout<<"not palindrome\n";
    }
    //TO CONVERT CHARACTER ARRAY TO LOWER CASE
    for(int i=0;i<c;i++)
    {
        if(temp[i]>='a' && temp[i]<='z')
        {
            
            cout<<temp[i];
        }
        else{
            char newca = temp[i]-'A'+'a';  //first calculating the differnce between the capital letters to get the differnce in their ASCII codes and then adding it two small letter 'a' to get the equivalent small letter(try solving with an example u will get)
            
            cout<<newca;
        }
    }
    //REMOVE EXTRA CHARACTERS STRING TO MAKE IT A PALINDROME
    string s;
    cout<<"enter a string\n";
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>=0 && s[i]<=9))
        {
            continue;
        }
        else{
            s.erase(i,1);
        }
    }
    for(int i=0;i<s.length();i++)
    {
        cout<<s[i];
    }
    return 0;
}
