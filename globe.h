#include <iostream>
#include <vector>
#include <opencv2\opencv.hpp>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;
using namespace cv;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

 void showvector(vector<int>  input);