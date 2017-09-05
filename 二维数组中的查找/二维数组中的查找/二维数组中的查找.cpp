#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
		int row=array.size();
		int col=array[0].size();
		int i=0,j=0;
		int ans=0;
		for(i=0,j=col-1;i<row&&j>=0;)
		{
			if(target==array[i][j])
			{
				ans=1;
				break;
			}
			else if(target>array[i][j])
			{
				i=i+1;
			}
			else if(target<array[i][j])
			{
				j=j-1;
			}
		}
		return ans;        
    }
};
int main()
{
	  vector <   vector <int>   >   array(3); 
            for(int   i=0;i <3;i++) 
                array[i].resize(3);//设置数组的大小3X3 
                  //现在你可以和使用数组一样使用这个vector 
			array[0][0]=1;
			array[0][1]=3;
			array[0][2]=5;
			array[1][0]=2;
			array[1][1]=4;
			array[1][2]=6;
			array[2][0]=3;
			array[2][1]=7;
			array[2][2]=9;
	Solution so;
	cout<<so.Find(8,array);
	return 0;
}