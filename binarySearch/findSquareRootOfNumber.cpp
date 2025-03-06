#include <iostream>
using namespace std;

// find square root of number using binary search
int finSquareRootOfNumber(int n){
    int low = 0, high = n;
    long long mid; // to control overflow
    int ans = -1;

    while (low <= high){
        mid = low + (high - low)/2;
        if (mid * mid <= n){
            ans = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return ans;
}

int finSquareRootOfNumberBruteForce(int n){
    int ans = -1;

    for (long long i = 0; i <= n; i++){
        if (i*i <= n){
            ans = i;
        }else{
            break;
        }
    }
    return ans;
}

int main(){
    long long n = 36122134411231;
    int res = finSquareRootOfNumber(n);
    cout << "square-root of number " << res << endl;
}