//分割链表：给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
//思路：双链表法 比x小的放在一个链表，比x大的放在一个链表 然后拼在一起
class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode dummyS = new ListNode(0);
        ListNode small = dummyS;
        ListNode dummyL = new ListNode(0);
        ListNode large = dummyL;
        while (head != null) {
            if (head.val < x) {
                small.next = head;
                small = small.next;
            } else {
                large.next = head;
                large = large.next;
            }
            head = head.next;
        }
        large.next = null;
        small.next = dummyL.next;
        return dummyS.next;
    }
}
