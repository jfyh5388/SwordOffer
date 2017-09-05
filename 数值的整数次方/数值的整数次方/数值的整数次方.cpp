#include<iostream>
using namespace std;
//int zeroerror;
class zeroerror{};
class Solution {
public:
    double Power(double base, int exponent) {
    	double ans=1;
        int exp=0;
        int expzheng=0;
		int count=base;
        if(exponent<0)
		{
			if(base>=0&&base<2e-15||base<=0&&base>-2e-15)
				throw zeroerror();
            expzheng=-exponent;
		}
        else
            expzheng=exponent;
        while(expzheng)
		{
			if(expzheng&1)
				ans*=count;
			count*=count;
			expzheng>>=1;
		}
        if(exponent<0)
            ans=1/ans;
        return ans;
    }
};
int main()
{
	Solution so;
	double ba=2;
	int mi=6;
	try
	{
		cout<<so.Power(ba,mi)<<endl;
	}
	catch (zeroerror)
	{
		cout<<"invalid input"<<endl;
	}
	return 0;
}