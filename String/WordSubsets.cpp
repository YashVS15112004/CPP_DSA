#include<bits/stdc++.h>
using namespace std;
vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) 
{
    int maxCount[26] = {0}; // To store the maximum frequency of each character needed

        // Calculate the maximum frequency of each character needed from words2
        for (const auto& word : words2) {
            int count[26] = {0}; // Frequency count for the current word in words2
            for (char ch : word) {
                count[ch - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                maxCount[i] = max(maxCount[i], count[i]);
            }
        }

        vector<string> result; // To store the universal words

        // Check each word in words1
        for (const auto& word : words1) {
            int count[26] = {0}; // Frequency count for the current word in words1
            for (char ch : word) {
                count[ch - 'a']++;
            }

            // Check if this word can cover all character requirements from words2
            bool isUniversal = true;
            for (int i = 0; i < 26; ++i) {
                if (count[i] < maxCount[i]) {
                    isUniversal = false;
                    break;
                }
            }

            if (isUniversal) {
                result.push_back(word);
            }
        }
        return result;
}
int main()
{
   vector<string> words1 = {"amazon","apple","facebook","google","leetcode"}, words2 = {"lo","eo"}; 
   vector<string> ans = wordSubsets(words1,words2);
   for(auto it:ans) cout<<it<<" ";
}