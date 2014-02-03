/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

Focus: 1. PriorityQueue usage. import java.util.PriorityQueue
	2. PriorityQueue<T> heap = new PriorityQueue<T>(arrlist.size(), comp)
	   Comparator<T> comp = new Comparator<T>() {
		int comparator(T o1, T o2) {
			...
			}
		}
	    heap.add(v) heap.peek(v) (vs c++ heap.top()), heap.poll() (vs c++ heap.pop()), heap.isEmpty()
	3. Algorithm. Maintain one heap and choose one and only one element from each list.
	4. Then get least one from heap, refill from that list. <Tip>: The next element

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode mergeKLists(ArrayList<ListNode> lists) {
        if (lists == null || lists.isEmpty()) {
            return null;
        }  
        
        Comparator<ListNode> comp = new Comparator<ListNode>() {
            public int compare(ListNode o1, ListNode o2) {
                if (o1.val < o2.val) {
                    return -1;
                } else if (o1.val > o2.val) {
                    return 1;
                } else {
                    return 0;
                }
            }
        } ;
        
        PriorityQueue<ListNode> heap = new PriorityQueue<ListNode>(lists.size(), comp);
        for (ListNode node: lists) {
            if (node != null) {
                heap.add(node);
            }
        }
        
        ListNode head = null;
        ListNode curr = null;
        
        while (!heap.isEmpty()) {
            if (head == null) {
                head = heap.peek();
                curr = heap.poll();
            } else {
                curr.next = heap.poll();
                curr = curr.next;
            }
            
            //refill one
            if (curr.next != null) {
                heap.add(curr.next);
            }
        }
        
        return head;
    }
}
