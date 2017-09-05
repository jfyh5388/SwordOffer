#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
       if(rotateArray[0]<rotateArray[rotateArray.size()-1])
           return rotateArray[0];
       int i1=0,i2=rotateArray.size()-1;
       int mid=0;
       while((i2-i1)!=1)
       {
           mid=(i1+i2)/2;
           if(rotateArray[mid]>rotateArray[0])
               i1=mid;
           else if(rotateArray[mid]<rotateArray[0])
               i2=mid;
           else 
           {
               int min=rotateArray[i1];
               i1++;
               while(i1<i2)
               {
                   if(min>rotateArray[i1])
                       min=rotateArray[i1];
                   i1++;
               }
               return min;
           }
       }
       return rotateArray[i2];
    }
};
int main()
{
	Solution so;
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(0);
	vec.push_back(1);
	cout<<so.minNumberInRotateArray(vec)<<endl;
	return 0;
}