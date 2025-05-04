#include <bits/stdc++.h>
using namespace std;
int getLongestSubarray_Hashing(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        //calculate the prefix sum till index i:
        sum += a[i];
        // if the sum = k, update the maxLen:
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }
        // calculate the sum of remaining part i.e. x-k:
        long long rem = sum - k;
        //Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        //Finally, update the map checking the conditions:
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}
int getLongestSubarray_Twoptr(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.
    int left = 0, right = 0; // 2 pointers
    long long sum = a[0];
    int maxLen = 0;
    while (right < n) {
        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }
        // if sum = k, update the maxLen i.e. answer:
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }
        // Move forward thw right pointer:
        right++;
        if (right < n) sum += a[right];
    }
    return maxLen;
}
int main()
{
    vector<int> a = {-2,1,-3,4,-1,2,1,-5,4};
    long long k = 6;
    int len1 = getLongestSubarray_Hashing(a, k);
    int len2 = getLongestSubarray_Twoptr(a, k);
    cout << "The length of the longest subarray is(Hashing): " << len1 << "\n";
    // cout << "The length of the longest subarray is(2-Pointer): " << len2 << "\n";
    return 0;
}


