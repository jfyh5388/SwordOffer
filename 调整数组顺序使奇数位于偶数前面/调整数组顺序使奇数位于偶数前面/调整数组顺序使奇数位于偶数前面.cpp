#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int count=0,i=0;
        int len=array.size();
        for(count;count<len;count++)
        {
            if(array[i]%2==0)
            {
                array.push_back(array[i]);
                array.erase(array.begin()+i);                                
            }
            else
                i++;
        }
    }
};
int main()
{
	Solution so;
	vector<int> a;
	a.push_back(2);
	a.push_back(4);
	a.push_back(1);
	a.push_back(6);
	a.push_back(9);
	so.reOrderArray(a);
	for(auto it=a.begin();it!=a.end();it++)
		cout<<*it<<endl;
	return 0;
}