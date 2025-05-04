#include<bits/stdc++.h>
using namespace std;
class MedianFinder {
    priority_queue<int, vector<int>, less<int>> smallHeap; 
    priority_queue<int, vector<int>, greater<int>> largeHeap;

public:
    MedianFinder() {}

    void addNum(int num) {
        smallHeap.push(num);
        if (!largeHeap.empty() && smallHeap.top() > largeHeap.top()) {
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        if (smallHeap.size() > largeHeap.size() + 1) {
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        if (largeHeap.size() > smallHeap.size() + 1) {
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }

    double findMedian() {
        if (smallHeap.size() == largeHeap.size()) {
            return (largeHeap.top() + smallHeap.top()) / 2.0;
        } else if (smallHeap.size() > largeHeap.size()) {
            return smallHeap.top();
        } else {
            return largeHeap.top();
        }
    }
};
int main()
{
    MedianFinder *medianFinder = new MedianFinder();
    medianFinder->addNum(1);    // arr = [1]
    medianFinder->addNum(2);    // arr = [1, 2]
    cout<<medianFinder->findMedian()<<endl; // return 1.5 (i.e., (1 + 2) / 2)
    medianFinder->addNum(3);    // arr[1, 2, 3]
    cout<<medianFinder->findMedian()<<endl; // return 2.0
}