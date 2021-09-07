// 移除链表元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "ListCommon.h"

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		auto hHead = new ListNode(0);
		hHead->next = head;
		auto t = hHead;
		while (t->next != nullptr)
		{
			if (t->next->val == val)
			{
				auto del = t->next;
				t->next = t->next->next;
				delete del;
				continue;
			}
			t = t->next;
		}
		return hHead->next;
	}
};

