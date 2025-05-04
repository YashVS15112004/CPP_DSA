#include <bits/stdc++.h>
using namespace std;
// Comparator function to sort by the number of units in descending order
bool static cmp(vector<int> a, vector<int> b)
{
    return a[1] > b[1];  // Compare the second element (units per box)
}
// Function to calculate the maximum units that can be loaded onto the truck
int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    int n = boxTypes.size();
    // Sort boxTypes in descending order based on the number of units per box
    sort(boxTypes.begin(), boxTypes.end(), cmp);
    int ts = 0;  // Total boxes loaded
    int ans = 0; // Total units loaded
    for (int i = 0; i < n; i++) {
        if (ts + boxTypes[i][0] <= truckSize) {
            ts += boxTypes[i][0];  // Add all boxes of this type
            ans += (boxTypes[i][0] * boxTypes[i][1]);  // Add the corresponding units
        } else {
            // If there's not enough space for all boxes, take only the remaining space
            ans += ((truckSize - ts)*boxTypes[i][1]);
            break;  // No more space left, so we can stop
        }
    }
    return ans;  // Return the total number of units loaded onto the truck
}

int main() {
    // Test input
    vector<vector<int>> boxTypes = {{1, 3}, {2, 2}, {3, 1}};
    int truckSize = 4;
    // Call the function and print the result
    int result = maximumUnits(boxTypes, truckSize);
    cout << "Maximum units that can be loaded: " << result << endl;
    return 0;
}