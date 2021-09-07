#include "ListCommon.h"

//第一个节点是头节点
ListNode* inputList(std::vector<int> v)
{
	ListNode* vHead = new ListNode(0);
	auto ptr = vHead;
	for (auto it = v.begin(); it != v.end(); ++it)
	{
		ListNode* node = new ListNode(*it);
		ptr->next = node;
		ptr = node;
	}
	auto ret = vHead->next;
	delete vHead;
	return ret;
}
//伪头节点
ListNode* inputListV(std::vector<int> v)
{
	ListNode* vHead = new ListNode(0);
	auto ptr = vHead;
	for (auto it = v.begin(); it != v.end(); ++it)
	{
		ListNode* node = new ListNode(*it);
		ptr->next = node;
		ptr = node;
	}
	return vHead;
}

void printLinkListV(ListNode* vhead)
{
	auto t = vhead->next;
	while (t != nullptr)
	{
		std::cout << t->val << " ";
		t = t->next;
	}
	std::cout << std::endl;
}

void printLinkList(ListNode* head)
{
	auto t = head;
	while (t != nullptr)
	{
		std::cout << t->val << " ";
		t = t->next;
	}
	std::cout << std::endl;
}