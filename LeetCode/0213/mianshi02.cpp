//面试题 02.02. 返回倒数第 k 个节点
//思路：借助双指针，可省去统计链表长度操作，算法流程为：

初始化双指针 pre , cur 都指向头节点 head ；
先令 cur 走 kk 步，此时 pre , cur 的距离为 kk ；
令 pre , cur 一起走，直到 cur 走过尾节点时跳出，此时 pre 指向「倒数第 kk 个节点」，返回之即可；


class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        ListNode *pre = head, *cur = head;
        for (int i = 0; i < k; i++)
            cur = cur->next;
        while (cur != nullptr) {
            pre = pre->next;
            cur = cur->next;
        }
        return pre->val;
    }
};
