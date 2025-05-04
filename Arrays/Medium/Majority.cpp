#include<bits/stdc++.h>
using namespace std;
int better(vector<int> v)
{
    //size of the given array:
    int n = v.size();
    //declaring a map:
    map<int, int> mpp;
    //storing the elements with its occurnce:
    for (int i = 0; i < n; i++) {
        mpp[v[i]]++;
    }
    //searching for the majority element:
    for (auto it : mpp) {
        if (it.second > (n / 2)) {
            return it.first;
        }
    }
    return -1;
}
int opt(vector<int> v)
{
    //size of the given array:
    int n = v.size();
    int cnt = 0; // count
    int el; // Element
    //applying the algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            cnt = 1;
            el = v[i];
        }
        else if (el == v[i]) cnt++;
        else cnt--;
    }
    //checking if the stored element
    // is the majority element:
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el) cnt1++;
    }

    if (cnt1 > (n / 2)) return el;
    return -1;
}
int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = opt(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}
