#include <bits/stdc++.h>
using namespace std;
int longestSuccessiveElements(vector<int>&a) {
    int n = a.size();
    if (n == 0) return 0;
    int longest = 1;
    unordered_set<int> st;
    //put all the array elements into set:
    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
    }
    //Find the longest sequence:
    for (auto it : st) {
        //if 'it' is a starting number:
        /* If st.find(it - 1) returns the end() iterator, it means that it - 1 is not present in the    set. This indicates the potential start of a consecutive sequence.
        If st.find(it - 1) returns an iterator pointing to an element, it means that it - 1 exists in the set, and we continue searching for the next element in the sequence. */
        if (st.find(it - 1) == st.end()) {
            //find consecutive numbers:
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}
int main()
{
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}

