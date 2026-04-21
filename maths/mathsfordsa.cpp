/* ****************GCD**********************/
#include<iostream>
using namespace std;
int gcd(int m,int n)
{
    if (m==0)
    {
        return n;
    }
    else if(n==0)
    {
        return m;
    }
    else{
        while(m!=n)
        {
            if(m>n)
            {
                m=m-n;
            }
            else{
                n=n-m;
            }
        }
        return m;
    }
}

// ***********************optimized gcd******************
int GCD(int x , int y){
        while(y > 0){
            int temp = x % y;
            x = y;
            y = temp;
        }

        return x;
    }

//**********************************LCM*************** */
int lcm(int m, int n)
{
    return (m*n)/gcd(m,n);
}
int main()
{
    int a,b;
    cout<<"enter 2 numbers for their gcd\n";
    cin>>a>>b;
    int gres=gcd(a,b);
    int lres=lcm(a,b);
    cout<<"gcd is "<<gres;
    cout<<"lcm is "<<lres;
    return 0;
}

/*****************MODULAR EXPONENTION***************************/

#include<iostream>
using namespace std;
expo(int a,b,c)
{
    if(b%2==0)
    {
        
    }
}
int main()
{
    cout<<"enter x,m,n\n";
    int x,m,n;
    cin>>x,m,n;
    expo(x,m,n);
    return 0;
}