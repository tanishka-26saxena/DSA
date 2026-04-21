//Uses 2 major ways to solve the problems
//1. Tabulation - bottom up DP
//2. Memoization - Top down DP

// In an interview if you are going to talk about the 
//approach then after tabulation / memoization talk about their time and space complexities
//and along with it the optimization solution 


//Memoization : 
//we tend to store the value of subproblems in some data structure say map/table
//so that we do not have to compute it again and again

//performing fibonacci using dp memoization

#include <iostream>
#include <vector>
using namespace std;

int fib(int n ,vector<int>& dp){
    if(n <= 1){
        return n;
    }

    if(dp[n] != -1){
        return dp[n];
    }
    return dp[n] = fib(n-1 , dp) + fib(n-2 , dp);
}
int main(){
    int n;
    cout << "enter some value : ";
    cin >> n;

    vector<int> dp(n+1 , -1);

    cout << fib(n , dp);
    return 0;
}

//now the time complexity for the above code is O(n) as there can be seen a linear pattern forming
//and the space complexity is O(n) for the dp array and O(n) for the recursion stack
//so overall space complexity is O(n) + O(n) = O(2n)

//Tabulation : 
//similar to memoization but here we solve the problem in a bottom up manner
//we look up at the recursive tree and start solving the problem from the base case
//like for the fibonacci problem we start from 0 and 1
//and keep storing the values in a table and use them to solve bigger problems

//performing fibonacci using dp tabulation

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cout << "enter some value : ";
    cin >> n;

    vector<int> dp(n+1 , -1);

    dp[0] = 0;
    dp[1] = 1;  //getting this from the base case used above in recursion

    for(int i = 2 ; i <= n ;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[n];
    return 0;
}

//now the time complexity for the above code is O(n) as there can be seen a linear pattern forming
//and the space complexity is O(n) for the dp array and O(1) for the recursion stack
//so overall space complexity is O(n) + O(1) = O(n)

//or to even improve the complexities we dont even need the arryay as it takes up o(n) space
// we will simply use some variables to store the values 

int main(){
    int n;
    cout << "enter some number : ";
    cin >> n;

    int prev2 = 0;
    int prev1 = 1;

    for(int i =2 ; i <= n ; i++){
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    cout << prev1;
    return 0;
}

//This is how we will not always need the array and will actually optimize the code 
//Now the time complexity is O(n) and space complexity is O(1)
//This is the space optimization code and algo