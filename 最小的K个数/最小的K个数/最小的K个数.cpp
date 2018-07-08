#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
	int partition(vector<int> &data, int start, int end)
	{
		int begin = start - 1;
		for (; start<end; start++)
		{
			if (data[start]<data[end])
			{
				begin++;
				if (begin != start)
				{
					swap(data[begin], data[start]);
				}
			}
		}
		begin++;
		swap(data[begin], data[end]);
		return begin;
	}

	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		int start = 0;
		int end = input.size() - 1;
		vector<int> ans;
		if (k == input.size())
			return input;
		if (k <= 0 || k>input.size() || input.size() == 0)
			return vector<int>();
		int index = partition(input, start, end);

		while (index != k-1)
		{
			if (index>k-1)
			{
				end = index - 1;
				index = partition(input, start, end);
			}
			else
			{
				start = index + 1;
				index = partition(input, start, end);
			}
		}
		for (int i = 0; i<=k-1; i++)
		{
			ans.push_back(input[i]);
		}
		return ans;
	}
};

int main()
{
	Solution so;
	vector<int> nums;
	nums.push_back(9);
	nums.push_back(5);
	nums.push_back(1);
	nums.push_back(6);
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(3);
	nums.push_back(8);
	vector<int> ans = so.GetLeastNumbers_Solution(nums,8);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	system("pause");
	return 0;

}