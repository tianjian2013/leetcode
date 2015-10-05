ow
#include "help.h"
/*
{
public:
    int val;
    TreeNode *left,right;
    TreeNode(int v):val(v),left(NULL),right(NULL){}
};*/


/*
vector<int> ret;
    int string2int(string str)
    {
      stringstream ss;
      int ret;
      ss<<str;
      ss>>ret;
      return ret;
    }
    vector<TreeNode *> make(int p,int q)
    {
        vector<TreeNode *> ret;
        if(p>q)
        {
            ret.push_back(NULL);
            return ret;
        }
        for(int i=p;i<=q;i++)
        {
            vector<TreeNode *> leftTrees=make(p,i-1);
            vector<TreeNode *> rightTrees=make(i+1,q);
            for(int m=0;m<leftTrees.size();m++)
            {
                for(int n=0;n<rightTrees.size();n++)
                {
                    TreeNode * node=new TreeNode(i);
                    node->left=leftTrees[m];
                    node->right=rightTrees[n];
                    ret.push_back(node);
                }
            }
        }
        return ret;
    }
    
    int  visit(TreeNode *node,vector <int> &nums,vector <char> &ops,int &index)
    {
        if(node==NULL)
        {
            return nums[index++];
        }
        int left=visit(node->left,nums,ops,index);
        int right=visit(node->right,nums,ops,index);
        switch (ops[node->val])
        {
            case '+':
                return left+right;
            case '-':
                return left-right;
            case '*':
                return left*right;
        }
        
    }
    vector<int> diffWaysToCompute(string input) {
      vector <int> nums;
      vector <char> ops;
      int pre=0;
      int p=1;
      int n=input.size();
      while(p<n)
      {
         if(input[p]>'9'||input[p]<'0')
         {
             ops.push_back(input[p]);
             nums.push_back(string2int (input.substr(pre,p-pre) ) );
             pre=p+1;
         }
         p++;
      }
      if(p>pre)
      {
             nums.push_back(string2int (input.substr(pre,p-pre) ) );
      }
      if(ops.empty())
      {
            ret.push_back(nums[0]);
            return ret;
      }
      vector<TreeNode *> trees=make(0,nums.size()-2);
      for(int i=0;i<trees.size();i++)
      {
          int index=0;
          ret.push_back(visit(trees[i],nums,ops,index));
      }
      return ret;
    }
*/ 

vector<int > make(int p,int q,vector <int> &nums,vector <char> &ops,int &index)
{
        vector<int > ret;
        if(p>q)
        {
            ret.push_back(nums[index++]);
            return ret;
        }
        for(int i=p;i<=q;i++)
        {
            vector<int> leftTrees=make(p,i-1);
            vector<int> rightTrees=make(i+1,q);
            for(int m=0;m<leftTrees.size();m++)
            {
                for(int n=0;n<rightTrees.size();n++)
                {
                    
                    int left=leftTrees[m];
                    int right=rightTrees[n];
                    //ret.push_back(node);
                    
                }
            }
        }
        return ret;
}

int main()
{
  string input("2*3-4*5");
  vector<int> ret = diffWaysToCompute( input) ;
  showvector(ret);
  return 0;
}
