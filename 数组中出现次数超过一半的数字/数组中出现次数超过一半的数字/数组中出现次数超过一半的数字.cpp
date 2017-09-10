

#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;
class Solution {
public:
	bool g_bInputInvalid = false;

	bool ChecInvalidArray(int * numbers, int length)
	{
		g_bInputInvalid = false;
		if (numbers == NULL&&length <= 0)
			g_bInputInvalid = true;
		return g_bInputInvalid;
	}

	bool checkMoreThanHalf(const vector<int>& data, int length, int number)  //检查是否存在出现次数超过一半的数字 
	{
		int times = 0;
		for (int i = 0; i < length; i++)
		{
			if (data[i] == number)
				times++;
		}

		bool isMoreThanHalf = true;
		if (times * 2 <= length)
		{
			g_bInputInvalid = true;
			isMoreThanHalf = false;
		}
		return isMoreThanHalf;
	}
	int Partition(vector<int>& data, int length, int start, int end)
	{
		if (data.size() == 0 || length <= 0 || start < 0 || end >= length)
		{
			//throw new std::exception("Invalid Parameters"); 
			return -1;
		}

		int curDivision = start - 1;

		for (int index = start; index < end; ++index)
		{
			if (data[index] < data[end])          //以最后一个元素为基准点进行划分 
			{
				++curDivision;
				if (curDivision != index)
				{
				std:swap(data[index], data[curDivision]);
				}
			}
		}

		++curDivision;

		std::swap(data[curDivision], data[end]);

		return curDivision;    //把基准元素放到最终位置上，并且返回其最终位置索引 
	}
	int MoreThanHalfNum_Solution(vector<int> numbers) {

		int length = numbers.size();
		int start = 0;
		int end = numbers.size() - 1;
		int middle = length >> 1;
		int index = Partition(numbers, length, start, end);   //由上述Partition可知以最后一个元素为基准元素 
		while (index != middle)
		{
			if (index > middle)
			{
				end = index - 1;
				index = Partition(numbers, length, start, end); //先排基准元素前面部分
			}
			else
			{
				start = index + 1;
				index = Partition(numbers, length, start, end); //后排基准元素后面部分 
			}
		}
		int result = numbers[middle];
		if (!checkMoreThanHalf(numbers, length, numbers[index]))
			result = 0;
		else
			result = numbers[middle];
		return result;
	}

};

int main()
{
	vector<int> nums;
	nums.push_back(21);
	nums.push_back(34);
	nums.push_back(21);
	nums.push_back(21);
	nums.push_back(20);
	nums.push_back(2);
	nums.push_back(21);
	nums.push_back(21);
	nums.push_back(6);
	Solution so;
	cout << so.MoreThanHalfNum_Solution(nums);
	//for (int i = 0; i < nums.size(); i++)
	//	cout << nums[i] << " ";
	system("pause");
	return 0;
}