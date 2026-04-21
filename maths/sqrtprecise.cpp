#include <iostream>

using namespace std;

long long int squareroot(int n){
    int s=0;
    int e=n-1;
    long long int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        long long int square=mid*mid;
        if(square==n){
            return mid;
        }
        if(square<n){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
double moreprecise(int n,int precise,int tempsol){
    double factor=1;
    double ans=tempsol;
    for(int i=0;i<precise;i++){
        factor=factor/10;
        for(double j=ans;j*j<=n;j=j+factor){
        ans=j;
    }
    }
    return ans;

}
int main(){
    int n;
    cout<<"enter the number:"<<endl;
    cin>>n;
    int tempsol=squareroot(n);
    cout<<"answer is:"<<moreprecise(n,3,tempsol)<<endl;
    cout<<tempsol;
    return 0;

}