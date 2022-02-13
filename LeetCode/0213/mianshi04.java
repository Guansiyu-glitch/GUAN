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
