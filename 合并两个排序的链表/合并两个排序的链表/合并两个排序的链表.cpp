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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
       ListNode *pNode1=pHead1;
        ListNode *pNode2=pHead2;
        ListNode *tail=(ListNode *)malloc(sizeof(ListNode));
		ListNode *node;
        ListNode *head=NULL;
        if(pHead1==NULL)
			return pHead2;
		if(pHead2==NULL)
			return pHead1;
        while(pNode1!=NULL&&pNode2!=NULL)
        {            
			node=(ListNode *)malloc(sizeof(ListNode));
            if(pNode1->val<pNode2->val)
            {				
				node->val=pNode1->val;
				if(head==NULL)
				{
					head=node;								
				}
				else
				{
					tail->next=node;				
				}
				tail=node;		
				pNode1=pNode1->next;
            }
            else
            {               	
                node->val=pNode2->val;
				if(head==NULL)
				{
					head=node;								
				}
				else
				{
					tail->next=node;				
				}
				tail=node;		
				pNode2=pNode2->next;
            }
        }
        if(pNode1==NULL)
        {
			while(pNode2)
			{
				node=(ListNode *)malloc(sizeof(ListNode));
				node->val=pNode2->val;
				tail->next=node;
				tail=node;
				pNode2=pNode2->next;
			}
			tail->next=NULL;
			return head;
        }
        else
    	{
			while(pNode1)
			{
				node=(ListNode *)malloc(sizeof(ListNode));
				node->val=pNode1->val;
				tail->next=node;
				tail=node;
				pNode1=pNode1->next;
			}
			tail->next=NULL;
			return head;
        }      
    }    
};
int main()
{
	Solution so;
	struct ListNode* ph1_1=(ListNode *)malloc(sizeof(ListNode));
	struct ListNode* ph1_2=(ListNode *)malloc(sizeof(ListNode));
	struct ListNode* ph1_3=(ListNode *)malloc(sizeof(ListNode));
	struct ListNode* ph1_0=ph1_1;	
	struct ListNode* ph2_1=(ListNode *)malloc(sizeof(ListNode));
	struct ListNode* ph2_2=(ListNode *)malloc(sizeof(ListNode));
	struct ListNode* ph2_3=(ListNode *)malloc(sizeof(ListNode));
	struct ListNode* ph2_0=ph2_1;
	ph1_1->val=1;
	ph1_2->val=3;
	ph1_3->val=5;
	ph2_1->val=2;
	ph2_2->val=4;
	ph2_3->val=6;
	ph1_1->next=ph1_2;
	ph1_2->next=ph1_3;
	ph1_3->next=NULL;
	ph2_1->next=ph2_2;
	ph2_2->next=ph2_3;
	ph2_3->next=NULL;
	struct ListNode* ans=so.Merge(ph1_0,ph2_0);
	ListNode *mid;
	while(ans)
	{
		mid=ans;
		cout<<ans->val;
		ans=ans->next;
		free(mid);
	}
	free(ph1_1);
	free(ph1_2);
	free(ph1_3);
	free(ph2_1);
	free(ph2_2);
	free(ph2_3);
	return 0;
}