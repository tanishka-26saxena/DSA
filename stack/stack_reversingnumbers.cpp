#include<iostream>
#include<stack>
using namespace std;
int main()
{
    string word="tanishka";

    stack<char> s;
     for(int i=0;i<word.size();i++)
     {
        char ch=word[i];
        s.push(ch);
     }
      string ans="";
      while(!s.empty())
      {
        char ch=s.top();
        ans.push_back(ch);

        s.pop();
      }
      cout<<ans;
      return 0;
}
