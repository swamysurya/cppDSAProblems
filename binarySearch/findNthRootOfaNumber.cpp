#include <iostream>
#include <cmath>
using namespace std;


// using brute force methods
// here we are using pow method
// where nth root of a m = pow(m,1/n);
int findNthRootOfaNumberBruteForce(int n, int m){
    double res = pow(m,1.0/n);
    int roundedRes = round(res);
    if (pow(roundedRes, n) == m){ // if powering that value returns exact value we can say its perfect integer
        return roundedRes;
    }else{
        return -1; // else return -1;
    }
}

// time complexcity = O(log n)
// space complexcity = O(1)


// nth root of M =>   x^n = m; using this for calculating pow mid value
int power(int mid, int n, int m){
    long long ans = 1;
    for(int i = 0; i < n; i++){ // multiplcation happen till n times
        ans *= mid;
        if (ans > m) return 1; // if this multiplication res exceeds the number left part of mid may contains result
    }
    if (ans == m) return 0; // if ans exactly equal to number m then that is the result
    else return -1; // other wise the number is in right part of the mid
}

int findNthRootOfaNumberBinarySearch(int n, int m){
    int low = 1, high = m;
    int mid;

    while (low <= high){
        mid = low + (high - low)/2;
        int res = power(mid,n,m);
        // based on res we move left and right
        if (res == 0) return mid; // return 0 means that will be answer
        if (res == 1) high = mid - 1; // move to left if multiplcation res exceeds the original number m
        else low = mid + 1; // move to right if multiplcation res is less than number
    }
    return 0;
}

// time complexcity = O(n log m)
// spcace complexcity = O(1)

int findNthRootOfaNumberNewtonsMethod(int n, int m){
    double x = m;
    double epsilon = 1e-9;

    while (true){
        double x_new = ((n-1)*x + (m/pow(x,n-1)))/n; // this is the formula for new find nth root of number it will keep doing unti;;
        if (abs(x_new - x) < epsilon) break; // abs value of differnece is less than epsilon
        x = x_new; // keep on update x
    }
    int root = round(x);
    return (pow(root, n) == m) ? root : -1;
}

// time complexcity = O(nloglogm)
// space complexcity = 0(1)




int main(){
    int n = 3, m = 64;
    int res = findNthRootOfaNumberNewtonsMethod(n,m);
    cout << "Nth root of number: "<< res << endl; 
    return 0;
}