#ifndef LISTCOMMON_H
#define LISTCOMMON_H

#include <iostream>
#include <set>
#include <vector>
#include <unordered_set>

using namespace std;

struct ListNode { 
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}

};
//第一个节点是头节点
ListNode* inputList(std::vector<int> v);
void printLinkList(ListNode* head);
//伪头节点
ListNode* inputListV(std::vector<int> v);
void printLinkListV(ListNode* vhead);



#endif