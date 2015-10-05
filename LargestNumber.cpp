#include "help.h"

    bool pre(int num1, int num2)
    {
	if (num1 == 0)
        {
            return false;
        }
        if (num2 ==0)
        {
            return true;
        }
        stringstream ss1,ss2;
        ss1<<num1;
        ss2<<num2;
        string str1,str2;
        ss1>>str1;
        ss2>>str2;
        string s1 = str1 + str2;
        string s2 = str2 + str1;
       // int n1 = atoi(s1.c_str());
        //int n2 = atoi(s2.c_str());
	int n = s1.size();
	for (int i = 0; i < n; i++)
	{
		if (s1[i] > s2[i])
		{
			return true;
		}
		else if (s1[i] < s2[i])
		{
			return false;
		}
	}
	return false;
        //return n1 > n2;
    }
    void adjust(vector<int>& nums, int len, int index)
    {
        int next = 2 * index + 1;
        while (next < len)
        {
            if (next + 1 < len && pre(nums[next], nums[next + 1]))
            {
                next++;
            }
            if (!pre(nums[index] , nums[next]))
            {
                break;
            }
            else
            {
                swap(nums[index], nums[next]);
                index = next;
                next = 2 * index + 1;
            }
        }    
    }
    void heapSort(vector<int>& nums)
    {
        int n = nums.size();
        for (int i = 0; i < n/2; i++)
        {
            adjust(nums, n, i);
        }
        for (int i = n - 1; i > 0; i--)
        {
            swap(nums[0], nums[i]);
            adjust(nums, i, 0);
        } 
    }
    string largestNumber(vector<int>& nums) {
        heapSort(nums);
        string ret;
        for (int i = 0; i < nums.size(); i++)
        {
            stringstream ss;
            ss << nums[i];
            string str;
            ss >> str;
            ret += str;
        }
        return ret;
    }

int main()
{
	int n;
	cin >> n;
	vector<int> input;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >>k;
		input.push_back(k);
	}
	string ret = largestNumber(input);
	cout << ret << endl;
}
