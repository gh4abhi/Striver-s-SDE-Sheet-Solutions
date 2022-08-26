// Problem Link - https://www.codingninjas.com/codestudio/problems/implement-trie_631356?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#define ll int

/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

struct Node
{
    Node* links[26];
    bool flag = false;
    
    bool containsKey(char ch)
    {
        return links[ch-'a'] != nullptr;
    }
    
    void put(char ch, Node* node)
    {
        links[ch-'a'] = node;
    }
    
    Node* get(char ch)
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

class Trie {

private:
    
    Node* root;
    
public:

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = root;
        for(auto i:word)
        {
            if(!node->containsKey(i))
                node->put(i,new Node());
            node = node->get(i);
        }
        node->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node = root;
        for(auto i:word)
        {
            if(!node->containsKey(i))
                return false;
            node = node->get(i);
        }
        return node->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* node = root;
        for(auto i:prefix)
        {
            if(!node->containsKey(i))
                return false;
            node = node->get(i);
        }
        return true;
    }
};