#include "globe.h"

class TrieNode {
public:
    // Initialize your data structure here.
    char val;
    bool end;
    vector <TrieNode *> next;
    TrieNode() {
     val='0';
     end=false;
    }
    TrieNode(char k) {
     val=k;
     end=false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    void insert2(string &s,int n,TrieNode* p)
    {
        //if(n==s.size() ) return ;
        int i=0;
        while(i<p->next.size() )
        {
            if(s[n]==p->next[i]->val)
              break;
              i++;
        }
        
        if(i<p->next.size())
        {
           if(  n==s.size()-1 ) 
           {
            p->next[i]->end=true;
            return ;
           }
           
           else insert2(s,n+1,p->next[i]);
        }
        else
        {
            TrieNode* newnode=new TrieNode(s[n]);
            p->next.push_back(newnode);
            if(  n==s.size()-1 ) 
                newnode->end=true;
            else
            insert2(s,n+1,newnode);
        }
        
    }
    // Inserts a word into the trie.
    void insert(string s) {
        insert2(s,0,root);
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode* p=root;
        int n=0;
        while(p)
        {
            if(n==key.size() ) return p->end;
            int i=0;
            for(;i<p->next.size();i++)
            {
                if(key[n]==p->next[i]->val)
                {
                   
                    n++;
                    break;
                }
            }
            if(i==p->next.size() )  return false;
              p=p->next[i];
        }
        return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* p=root;
        int n=0;
        while(p)
        {
            if(n==prefix.size() ) return true;
            int i=0;
            for(;i<p->next.size();i++)
            {
                if(prefix[n]==p->next[i]->val)
                {
                   
                    n++;
                    break;
                }
            }
            if(i==p->next.size() )  return false;
              p=p->next[i];
        }
        return false;
    }

private:
    TrieNode* root;
};

void main()
{
	 Trie trie;
	 trie.insert("a");
	
	 trie.search("a");

}
// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");