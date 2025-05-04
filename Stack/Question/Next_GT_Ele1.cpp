#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector < int > nextGreaterElements(vector < int > & nums) {
      int n = nums.size();
      vector < int > nge(n,0);
      stack < int > st;
      for (int i = 2 * n - 1; i >= 0; i--) { //Circular Array -> Traverse twice;Inserting the elements of the array A at the end of A
        while (!st.empty() && st.top() <= nums[i % n]) {
          st.pop();
        }
        if (i < n) {
          if (!st.empty()) nge[i] = st.top();
          else nge[i] = -1;
        }
        st.push(nums[i % n]);
      }
      return nge;
    }
};
int main() {
  Solution obj;
  vector < int > v {5,7,1,2,6,0};
  vector < int > res = obj.nextGreaterElements(v);
  cout << "The next greater elements are" << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
}