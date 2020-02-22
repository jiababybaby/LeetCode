#include <iostream>
using namespace std;

//����ṹ��
struct ListNode{
	int val;
	ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1=1;//��¼l1�ĳ���
        int len2=1;//��¼l2�ĳ���
        ListNode* p=l1;
        ListNode* q=l2;
        while(p->next!=NULL)//��ȡl1�ĳ���
        {
            len1++;
            p=p->next;
        }
        while(q->next!=NULL)//��ȡl2�ĳ���
        {
            len2++;
            q=q->next;
        }
        if(len1>len2)//l1�ϳ�����l2ĩβ����
        {
            for(int i=1;i<=len1-len2;i++)
            {
                q->next=new ListNode(0);
                q=q->next;
            }
        }
        else//l2�ϳ�����l1ĩβ����
        {
            for(int i=1;i<=len2-len1;i++)
            {
                p->next=new ListNode(0);
                p=p->next;
            }
        }
        p=l1;
        q=l2;
        bool count=false;//��¼��λ
        ListNode* l3=new ListNode(-1);//��Ž��������
        ListNode* w=l3;//l3���ƶ�ָ��
        int i=0;//��¼��ӽ��
        while(p!=NULL&&q!=NULL)
        {
            i=count+p->val+q->val;
            w->next=new ListNode(i%10);
            count=i>=10?true:false;
            w=w->next;
            p=p->next;
            q=q->next;
        }
        if(count)//������н�λ
        {
            w->next=new ListNode(1);
            w=w->next;
        }
        return l3->next; 
    }
};
