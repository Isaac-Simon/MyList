
 struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
	
};

class Solution {
public:
	//递归写法
	//ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	//	if (l1 == nullptr)
	//	{
	//		return l2;
	//	}
	//	else if (l2 == nullptr)
	//	{
	//		return l1;
	//	}
	//	else
	//	{
	//		if (l1->val <= l2->val)
	//		{
	//			l1->next = mergeTwoLists(l1->next, l2);
	//			return l1;
	//		}
	//		else
	//		{
	//			l2->next = mergeTwoLists(l2->next, l1);
	//			return l2;
	//		}
	//	}
	//}
	//迭代写法
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		if (l1 == nullptr)
		{
			return l2;
		}
		else if (l2 == nullptr)
		{
			return l1;
		}
		ListNode* vRet = new ListNode(0);
		ListNode* ptrRet = vRet; //哨兵节点
		while (l1 != nullptr && l2!=nullptr)
		{
			if (l1->val <= l2->val)
			{
				ptrRet->next = l1;
				l1 = l1->next;
			}
			else
			{
				ptrRet->next = l2;
				l2 = l2->next;
			}
			ptrRet = ptrRet->next;;
		}
		if(l1 == nullptr)
		{
			ptrRet->next = l2;
		}
		if (l2 == nullptr)
		{
			ptrRet->next = l1;
		}
		auto p = vRet->next;
		delete vRet;
		return p;
	}
};