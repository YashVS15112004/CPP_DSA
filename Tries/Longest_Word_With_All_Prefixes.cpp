#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
    Node* links[26];
    int flags[26] = {0};
    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    void setEnd(char ch) {
        flags[ch-'a'] = 1;
    }
};
class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }
    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd(word[word.length()-1]);
    }
    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (node->containsKey(word[i]) && node->links[word[i]-'a']->flags[word[i]-'a']==1) {
                node = node->get(word[i]);
            }
            else return false;
        }
        return (node->flags[word[word.size()-1]-'a']==1)?true:false;
    }
};
string completeString(int n, vector<string> &a)
{
    Trie trie;
    int mxl = 0;
    string ans = "";
    for(int i=0;i<n;i++) trie.insert(a[i]);
    for(int i=0;i<n;i++)
    {
        if(trie.search(a[i])) 
        {
            if(ans.size()<a[i].size()) ans = a[i];
            else if(ans.size()==a[i].size()) ans = min(ans,a[i]);
        }
    }
    return (ans.size()==0)?"None":ans;
}
int main() {
    int n = 5;
    vector<string> a = {"g","a","ak","szhkb","hy"};
    cout<<completeString(n,a);
    return 0;
}
                            
                        