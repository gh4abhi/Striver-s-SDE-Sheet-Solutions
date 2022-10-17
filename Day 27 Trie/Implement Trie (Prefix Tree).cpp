// Problem Link - https://www.codingninjas.com/codestudio/problems/implement-trie_631356?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#define ll int

struct node
{
    node* links[26];
    bool flag = false;
    
    bool containsKey(char ch)
    {
        return links[ch-'a']!=nullptr;
    }
    
    void put(char ch, node* cur)
    {
        links[ch-'a'] = cur;
    }
    
    node* get(char ch)
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
    node* root;
public:
    Trie() {
        root = new node();
    }
    
    void insert(string word) {
        node* cur = root;
        for(ll i=0;i<word.length();i++)
        {
            if(!cur->containsKey(word[i]))
                cur->put(word[i],new node());
            cur = cur->get(word[i]);
        }
        cur->setEnd();
    }
    
    bool search(string word) {
        node* cur = root;
        for(ll i=0;i<word.length();i++)
        {
            if(!cur->containsKey(word[i]))
                return false;
            cur = cur->get(word[i]);
        }
        return cur->isEnd();
    }
    
    bool startsWith(string prefix) {
        node* cur = root;
        for(ll i=0;i<prefix.length();i++)
        {
            if(!cur->containsKey(prefix[i]))
                return false;
            cur = cur->get(prefix[i]);
        }
        return true;        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */