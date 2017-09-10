

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

	bool checkMoreThanHalf(const vector<int>& data, int length, int number)  //����Ƿ���ڳ��ִ�������һ������� 
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
			if (data[index] < data[end])          //�����һ��Ԫ��Ϊ��׼����л��� 
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

		return curDivision;    //�ѻ�׼Ԫ�طŵ�����λ���ϣ����ҷ���������λ������ 
	}
	int MoreThanHalfNum_Solution(vector<int> numbers) {

		int length = numbers.size();
		int start = 0;
		int end = numbers.size() - 1;
		int middle = length >> 1;
		int index = Partition(numbers, length, start, end);   //������Partition��֪�����һ��Ԫ��Ϊ��׼Ԫ�� 
		while (index != middle)
		{
			if (index > middle)
			{
				end = index - 1;
				index = Partition(numbers, length, start, end); //���Ż�׼Ԫ��ǰ�沿��
			}
			else
			{
				start = index + 1;
				index = Partition(numbers, length, start, end); //���Ż�׼Ԫ�غ��沿�� 
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