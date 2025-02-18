#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Recursively checks if a string can become palindrome by swapping one pair of characters.
 * @param v input string
 * @param i current index
 * @param n length of the string
 * @param ops if an operation (swap) has been done
 * @return true if the string can become a palindrome, false otherwise
 */
bool checkBecamePalindrome(vector<char>& v, int i, int n, bool& ops){
        // base case till the middle of the string
        if (i >= n/2) return true;
        // if the characters at the current index are not equal
        if (v[i] != v[n-i-1]){
            // if an operation has not been done yet
           if (!ops){
               // swap the characters
               // find the character at the right index
               char target = v[n-i-1];
               // find the index of the target character
               // i is the current left index in the recursion.
               // We need to search for a matching character (target = v[n-i-1]) to swap with v[i].
               // v.begin() + i + 1 ensures we search to the right of i, avoiding redundant checks.
               auto it = find(v.begin()+i+1,v.begin()+n-i,target);
                // if the target character is found
                // if it 
               if (it != v.begin()+n-i-1){
                   iter_swap(v.begin()+i, it);
                   ops = true;
               // if the target character is not found
               }else{
                   return false;
               }
            // if an operation has been done already 
           }else{
               return false;
           }
        }
        // recursively check the next pair of characters
        return checkBecamePalindrome(v, i+1,n,ops);
    }
bool canBecomePalindrome(string s) {
    int strLen = s.size();
    int i = 0;
    bool operationDone = false;
    vector<char> vecString;
    for (char k: s) vecString.push_back(k);
    return checkBecamePalindrome(vecString,i,strLen,operationDone);
}

int main(){
    string s = "abca";
    cout << canBecomePalindrome(s) << endl;
    return 0;
}