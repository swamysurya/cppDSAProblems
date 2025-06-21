#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// optimal approach with hasmap
int subArraySum(vector<int> arr, int k)
{
    int cnt = 0;
    int prefixSum = 0;
    unordered_map<int, int> map;
    map[0] = 1;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];
        if (map.find(prefixSum - k) != map.end()) // for find O(1);
        {
            cnt += map[prefixSum - k];
        }
        map[prefixSum]++;
    }
    return cnt;
}

// time complexcity: O(n)
// space complexcity: O(n) for map

int main()
{
    vector<int> arr = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    int k = 3;
    int res = subArraySum(arr, k);
    cout << res << endl;

    return 0;
}