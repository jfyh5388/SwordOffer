#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
		int rows=matrix.size();
        int cols=matrix[0].size();
		int endx,endy;
        vector<int> ans;
        for(int i=0;i*2<rows&&i*2<cols;i++)
        {
            endx=cols-i;
			endy=rows-i;
            for(int n=i;n<endx;n++)
            {
                cout<<matrix[i][n]; 
                ans.push_back(matrix[i][n]);
            }			
			if(i<endy-1)
			{
				for(int n=i+1;n<endy;n++)
				{
					cout<<matrix[n][endx-1];
					ans.push_back(matrix[n][endx-1]);
				}
			}
			if(i<endy-1&&i<endx-1)
			{
				for(int n=endx-2;n>=i;n--)
				{
					cout<<matrix[endy-1][n];
            		ans.push_back(matrix[endy-1][n]);
				}
			}
			if(i<endy-2&&i<endx-1)
			{
				for(int n=endy-2;n>i;n--)
				{
					cout<<matrix[n][i];
            		ans.push_back(matrix[n][i]);
				}     
			}
        }
        return ans;
    }
};
int main()
{
	vector<vector<int> > numin(5);
	for(int i=0;i<5;i++) {
        numin[i].resize(1);
    }
	int num=1;
	for(int i=0;i<5;i++)
		for(int j=0;j<1;j++)
		{
			numin[i][j]=num;
			num++;
		}
	Solution so;
	vector<int> ansmain=so.printMatrix(numin);
	return 0;
}