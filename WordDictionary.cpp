#include <iostream>
#include <vector>
using namespace std;

class node{
public :
bool end;
char val;
node(char k):val(k),end(false){}
vector <node*> next;
};
class WordDictionary {
node *root;



public:
    WordDictionary()
    {
       root=new node('#');
    }
    void add(node *p,string &s,int index)
    {
      if(index==s.size()) 
      {   
           p->end=true;
           return ;
      }
      int i=0;
      for(;i<p->next.size();i++)
      { 
         if(s[index]==p->next[i]->val) break;     
      }
      if(i<p->next.size())
      {
         add(p->next[i],s,index+1);
      }
      else
      {
          node *q=new node (s[index]) ;
           p->next.push_back(q);
           add(q,s,index+1);
      }
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        add(root,word,0);
    }

    bool se(node *p,string &s,int index)
    {
        if(index==s.size()) return p->end;
         int i=0;
         for(;i<p->next.size();i++)
         { 
           if(s[index]=='.'||s[index]==p->next[i]->val)  
           if(  se(p->next[i],s,index+1) ) return true;     
         }
         return false;
      
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
       return  se(root,word,0);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main()
{
WordDictionary sl;
sl.addWord("bad");
sl.addWord("dad");
sl.addWord("mad");
if ( sl.search("pad") ) cout<<"ok"<<endl;
else cout<<"no"<<endl;
if ( sl.search("bad") ) cout<<"ok"<<endl;
else cout<<"no"<<endl;
if ( sl.search(".ad") ) cout<<"ok"<<endl;
else cout<<"no"<<endl;
if ( sl.search("b..") ) cout<<"ok"<<endl;
else cout<<"no"<<endl;

}
