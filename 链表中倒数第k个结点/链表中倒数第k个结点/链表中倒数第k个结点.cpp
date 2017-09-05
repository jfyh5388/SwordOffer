#include<iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    	unsigned int j=1;
        ListNode *p1=pListHead;
        ListNode *p2=pListHead;
        if(pListHead==NULL||k==0)
            return NULL;
        for(j=1;j<k;j++)
        {
            if(p2->next==NULL)
                return NULL;
            else                
            	p2=p2->next;
        }
        while(p2->next!=NULL)
        {
            p1=p1->next;
            p2=p2->next;
        }
        return p1;
        
    }
};
int main()
{ 
	struct ListNode* head=(ListNode *)malloc(sizeof(ListNode));
	struct ListNode* data1=(ListNode *)malloc(sizeof(ListNode));
	struct ListNode* data2=(ListNode *)malloc(sizeof(ListNode));
	struct ListNode* data3=(ListNode *)malloc(sizeof(ListNode));
	struct ListNode* data4=(ListNode *)malloc(sizeof(ListNode));
	struct ListNode* data5=(ListNode *)malloc(sizeof(ListNode));
	struct ListNode* data6=(ListNode *)malloc(sizeof(ListNode));
	Solution so;
	head->val=0;	
	data1->val=1;
	data2->val=2;
	data3->val=3;
	data4->val=4;
	data5->val=5;
	head->next=data1;
	data1->next=data2;
	data2->next=data3;
	data3->next=data4;
	data4->next=data5;
	data5->next=data6;
	data6->next=NULL;
	cout<<so.FindKthToTail(head,6)->val<<endl;
	return 0;
}