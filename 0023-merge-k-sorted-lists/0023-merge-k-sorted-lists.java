// Definition for singly-linked list.
// public class ListNode {
//     int val;
//     ListNode next;
//     ListNode() {}
//     ListNode(int val) { this.val = val; }
//     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
// }

import java.util.*;

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        }
        
        // Min-heap based on node values
        PriorityQueue<ListNode> pq = new PriorityQueue<>(
            Comparator.comparingInt(n -> n.val)
        );
        
        // Add the head of each non-null list to the heap
        for (ListNode node : lists) {
            if (node != null) {
                pq.offer(node);
            }
        }
        
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;
        
        // Process nodes from heap
        while (!pq.isEmpty()) {
            ListNode min = pq.poll();
            tail.next = min;
            tail = min;
            
            // Add next node from the same list if exists
            if (min.next != null) {
                pq.offer(min.next);
            }
        }
        
        return dummy.next;
    }
}