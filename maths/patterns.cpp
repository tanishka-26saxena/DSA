#include<iostream>
using namespace std;
/*
int main()
{                                              *
    for(int i=1;i<=5;i++)                      **
    {                                          ***
        for(int j=1;j<=i;j++)                  ****
        {                                      *****
            cout<<"*";
            cout<<" ";
        }
        
        cout<<endl;
        
    }
    return 0;
    }
*/
/*
int main()
{
    for(int i=1;i<=5;i++)                      1
    {                                          12
        for(int j=1;j<=i;j++)                  123
        {                                      1234
            cout<<j;                           12345
        cout<<" ";
        }
        
        cout<<endl;
        
    }
    return 0;
    }
*/
/*
int main()
{
    for(int i=1;i<=5;i++)                      
    {                                          
        for(int j=1;j<=i;j++)                  
        {    
            if((i+j)%2==0)
            {                                  
            cout<<"1";                         
            cout<<" ";
        }
        else{
            cout<<"0";
            cout<<" ";
        }
        }
        
        cout<<endl;
        
    }
    return 0;
    }
*/
/*
int main()
{
    for(int i=1;i<=5;i++)                      
    {                                          
        for(int j=5;j>=i;j--)                 
        {                                    
            cout<<"*";                       
           cout<<" ";
        }
        
        cout<<endl;
        
    }
    return 0;
    }
    */
   /*
int main()
{
    for(int i=1;i<=5;i++)                      
    {                                          
        for(int j=1;j<=5-i;j++)                 
        {                                                   
           cout<<" ";
        }
        for(int j=1;j<=i;j++)
        {
        cout<<"*";
        }
        cout<<endl;
    }        
    return 0;
    }
   */
  /*
   int main()
{
    for(int i=1;i<=5;i++)                      
    {                                          
        for(int j=1;j<=5-i;j++)                 
        {                                                   
           cout<<" ";
        }
        for(int j=1;j<=i;j++)
        {
        cout<<"* ";
        }
        cout<<endl;
    }        
    return 0;
    }
*/
int main()
{
    for(int i=1;i<=5;i++)                      
    {                                          
        for(int j=1;j<=5-i;j++)                 
        {                                                   
           cout<<" ";
        }
        for(int j=1;j<=2*i-1;j++)
        {
        cout<<i+j;
        }
        cout<<endl;
    }        
    return 0;
    }