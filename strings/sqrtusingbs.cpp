#include<iostream>
using namespace std;

long squareroot(long a) {
    long s = 0;
    long e = a;
    long mid;
    long ans = -1; // Initialize ans to a default value

    while (s <= e) {
        mid = s + (e - s) / 2; // Calculate mid correctly
        long sq = mid * mid;
        
        if (a == sq) {
            return mid;
        }
        
        if (a > sq) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    
    return ans;
}

int main() {
    long n;
    cout << "Enter a number: ";
    cin >> n;
    long sqr = squareroot(n);
    
    
    cout << "Square root: " << sqr << endl;

    
    return 0;
}
