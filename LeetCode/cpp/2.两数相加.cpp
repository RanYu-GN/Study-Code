// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem2.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        ListNode *cur = nullptr;
        ListNode *ans = nullptr;
        for (int sum = 0, val = 0; l1 != nullptr || l2 != nullptr; l1 = l1 == nullptr ? nullptr : l1->next, l2 = l2 == nullptr ? nullptr : l2->next)
        {
            sum = (l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val) + carry;
            val = sum % 10;
            carry = sum / 10;
            if (ans == nullptr)
            {
                ans = new ListNode(val);
                cur = ans;
            }
            else
            {
                cur->next = new ListNode(val);
                cur = cur->next;
            }
        }
        if (carry == 1)
        {
            cur->next = new ListNode(1);
        }
        return ans;
    }
};
// @lc code=end
