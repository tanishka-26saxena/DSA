#include<iostream>
using namespace std;
/*
int factorial(int n)
{
    //base case
    if (n==0)
    {
        return 1;
    }

    //recursive relation --> f(n)=n*f(n-1)---> f(n) is badi problem and f(n-1) is chhoti problem
    int choti=factorial(n-1);
    int badi=n*choti;
    return badi;
}
int main()
{
    int n;
    cin>>n;

    int ans=factorial(n);
    cout<<ans;
    return 0;
}
*/
/*
int counting(int n)
{
    //base case
    if(n==0)
    {
        return 0;
    }
    
    counting(n-1);
    cout<<(n);
}
int main()
{
    int n;
    cin>>n;
    counting(n);
    
}
*/

/*
void saydigit(int n,string arr[])
{
    if(n==0)
    {
        return ;
    }

    int digit=n%10;
    n=n/10;
    saydigit(n,arr);
    cout<<arr[digit]<<" ";
    
}
int main()
{
    int n;
    cin>>n;
    string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    saydigit(n,arr);
    return 0;
}
*/


//check if array is sorted or not
/*
bool sorted(int arr[],int n)
{
    if (n==0 || n==1)
    {
        return true;
    }
    if(arr[0]>arr[1])
    {
        return false;
    }
    else{
       return sorted(arr+1,n-1);
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    bool b=sorted(arr,n);
    if (b){
        cout<<"sorted";
    }
    else{
        cout<<"not sorted";
    }
}
*/


//get sum of all elements in array
/*
int sums(int arr[],int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return arr[0];
    }
    int ans=arr[0]+sums(arr+1,n-1);
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans=sums(arr,n);
    cout<<ans;
}
*/


//linear saerch using recursion
/*
bool search(int arr[],int n,int val)
{
    if(n==0)
    {
        return false;
    }
    if(arr[0]==val)
    {
        return true;
    }
    else{
        return search(arr+1,n-1,val);
    }
}
int main()
{
    int n;
    cout<<"enter size of array\n";
    cin>>n;
    int arr[100];
    cout<<"enter array\n";
    for(int i=0;i<n;i++)
    {
    cin>>arr[i];
    }
    int val;
    cout<<"enter value to be saerched\n";
    cin>>val;
    if(search(arr,n,val))
    {
        cout<<"found"<<endl;
    }
    else
    cout<<"not found";
}
*/


//binary search using recursion
/*
bool binarysearch(int s,int e,int arr[],int k)
{
    if(s>=e)
    {
        return false;
    }
    int mid=(s+e)/2;
    if(arr[mid]==k)
    {
        return true;
    }
    else if(arr[mid]>k)
    {
        return binarysearch(s,mid-1,arr,k);
    }
    else
    {
        return binarysearch(mid+1,e,arr,k);
    }
}
int main()
{
    int arr[5]={1,2,3,4,5};
    int s=0;
    int e=5;
    int val=5;
    if(binarysearch(s,e,arr,val))
    {
        cout<<"found"<<endl;
    }
    else
    cout<<"not found";
}
*/


//reversing the string using recursion
/*
void reversestring(string& s,int i,int j)
{
    if(i>j)
    {
        return ;
    }

        swap(s[i],s[j]);
        i++;
        j--;
        reversestring(s,i,j);
}

int main()
{
    string s="tanishka";
    reversestring(s,0,s.length()-1);
   cout<<s;
}
*/

//checking if the string is palindrome
/*
bool ispalindrome(string &s, int i, int j)
{
    if(i>=j)
    {
        return true ;
    }
    if(s[i]==s[j])
    {
        return ispalindrome(s,++i,--j);
    }
    return false;
}
int main()
{
    string s="abba";
    bool pali=ispalindrome(s,0,s.length()-1);
    if(pali)
    {
        cout<<"is pali";
    }
   
}
*/

//calculating power (not optimizzed solution)
/*
int power(int a, int b)
{
    if(b==0)
    {
        return 1;
    }
    if(b==1)
    {
        return a;
    }
    return a*power(a,b-1);

}
int main()
{
    int a,b;
    cin>>a;
    cin>>b;
    int p=power(a,b);
    cout<<p;
    return 0;
}
*/
//calculating power (optimizzed solution)

int power(int a,int b)
{
    if(b==0)
    {
        return 1;
    }
    if(b==1)
    {
        return a;
    }
    int ans=power(a,b/2);
    if(b%2==0)
    {
        return ans*ans;
    }
    else
    {
        return a*ans*ans;
    }
}
int main()
{
    int a,b;
    cin>>a;
    cin>>b;
    int p=power(a,b);
    cout<<p;

}