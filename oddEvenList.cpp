// 奇偶链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//输入 : 1->2->3->4->5->NULL
//输出 : 1->3->5->2->4->NULL
#include "ListCommon.h"

class SolutionOdd {
public:
	ListNode* oddEvenList(ListNode* head) {
		if (head == nullptr || head->next == nullptr || head->next->next ==nullptr) return head;
		ListNode* hHead = new ListNode(0);  //偶数节点链表头伪节点
		ListNode* pNow = hHead; //偶链表末节点指针
		ListNode* t = head;
		while (t != nullptr && t->next !=nullptr)
		{
			auto even = t->next;
			t->next = even->next;
			if (even->next != nullptr) //要移动的偶节点后面还有值
			{
				t = t->next; //总数为奇数
			}

			even->next = nullptr;
			pNow->next = even;
			pNow = pNow->next;
		}
		t->next = hHead->next;
		delete hHead;
		return head;
	}
};
//int main()
//{
//	std::vector<int> v = {1,2,3,4,5,6,7,8};
//	ListNode* head = inputList(v);
//	printLinkList(head);
//	Solution s;
//	auto r = s.oddEvenList(head);
//	printLinkList(r);
//}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
