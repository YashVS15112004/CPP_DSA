#include<bits/stdc++.h>
using namespace std;
class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }

    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};
int main()
{
    vector<int> nums = {4, 5, 8, 2};
    KthLargest *kthLargest = new KthLargest(3, nums);
    cout<<kthLargest->add(3)<<endl; // return 4
    cout<<kthLargest->add(5)<<endl; // return 5
    cout<<kthLargest->add(10)<<endl; // return 5
    cout<<kthLargest->add(9)<<endl; // return 8
    cout<<kthLargest->add(4)<<endl; // return 8
}