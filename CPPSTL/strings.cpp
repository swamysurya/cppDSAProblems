#include <iostream>
#include <string>

using namespace std;

int main(){
    string s = "Hello";
    cout << s << endl;

    // convert int to string
    string s2 = to_string(123);
    cout << s2 << endl;

    // convert string to int
    int i = stoi(s2);
    cout << i << endl;

    // char to int
    int j = s2[0] - '0';
    cout << j << endl;

    // convert '0' to int
    char ch = '2';
    int k = ch - '0';
    cout << k << endl;
    return 0;
}