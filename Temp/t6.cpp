#include<bits/stdc++.h>
using namespace std;
class Node
{
    Node *links[26];
    bool flag = false;
    public:
    bool searchKey(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    void insert(char ch,Node *node)
    {
        links[ch-'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch-'a'];
    }
    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }
};
class Trie
{
    Node *root;
    public:
    Trie()
    {
        root = new Node();
    }
    void insert(string s)
    {
        Node *node = root;
        for(int i=0;i<s.size();i++)
        {
            if(!node->searchKey(s[i]))
            {
                node->insert(s[i],new Node());
            }
            node = node->get(s[i]);
        }
        node->setEnd();
    }
    bool search(string s)
    {
        Node *node = root;
        for(int i=0;i<s.size();i++)
        {
            if(!node->searchKey(s[i])) return false;
            node = node->get(s[i]);
        }
        return node->isEnd();
    }
    bool startsWith(string s)
    {
        Node *node = root;
        for(int i=0;i<s.size();i++)
        {
            if(!node->searchKey(s[i])) return false;
            node = node->get(s[i]);
        }
        return true;
    }
};