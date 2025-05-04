#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// brute force apporach 
double medianOfTwoSortedArray(vector<int> arr1, vector<int> arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();

    arr1.insert(arr1.end(), arr2.begin(), arr2.end()); //O(n2)
    sort(arr1.begin(), arr1.end()); // O(n log n)
    
    int n = arr1.size();

    if (n%2 == 1) return arr1[n/2];
    else return (double) ((arr1[n/2] + arr1[n/2 - 1])/2.0);
}

// time complexcity O(n + n log n) = O(n log n) where n = n1+n2

    




int main(){
    // vector<int> arr1 = {1,2,3,4,5};
    // vector<int> arr2 = {3,6,9,12,15,18,21};

    vector<int> arr1 = {4, 8, 9, 11, 16,22,25,31};
    vector<int> arr2 = {11, 18, 28, 38, 40, 53, 62,63,71,74};
    
    double res = medianOfTwoSortedArray(arr1, arr2);
    cout << res << endl;
    return 0;
}