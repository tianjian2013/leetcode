#include "globe.h"

class Solution {
public:

    int ladderLength(string start, string end, set<string> &dict) {
 
	if (start.size() != end.size()) return 0;
if (start.empty() || end.empty()) return 0;
queue<string> next, current; // ��ǰ�㣬��һ��
set<string> visited; // ����
map<string, string > father;
int level = 0; // ���
bool found = false;
current.push(start);
while (!current.empty() && !found) {
++level;
while (!current.empty() && !found) {
const string str(current.front()); current.pop();
for (size_t i = 0; i < str.size(); ++i) {
string new_word(str);
for (char c = 'a'; c <= 'z'; c++) {
if (c == new_word[i]) continue;
swap(c, new_word[i]);
if (new_word == end) {
found = true; //�ҵ���
father[new_word] = str;
break;
}
if (dict.count(new_word) > 0
&& !visited.count(new_word)) {
next.push(new_word);
visited.insert(new_word);
father[new_word] = str;
}
swap(c, new_word[i]); // �ָ��õ���
}
}
}
swap(next, current); //!!! ������������
}
if (found) return level+1;
else return 0;
    }
};


void main()
{
	Solution sl;
	set<string>  sss;
	sss.insert("hot");
	sss.insert("dot");
	sss.insert("dog");

	int ret=sl.ladderLength("hot","dog",sss);
	cout<<ret;

}