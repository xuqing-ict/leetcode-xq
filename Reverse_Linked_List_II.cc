class Solution {
private:
    ListNode *reverse(ListNode *head)
    {
        ListNode dummy(0);
        while(head)
        {
            ListNode *tmp = head->next;
            head->next = dummy.next;
            dummy.next = head;
            head = tmp;
        }
        return dummy.next;
    }
    
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
       //illegal input 
       if(head == NULL || m >= n || m <= 0)return head;
       ListNode dummy(0);
       dummy.next = head;
       head = &dummy;
       int t = m;
       ListNode *tempPre = head;
       while(t--)
       {
           tempPre = head;
           head = head->next;
       }
       ListNode *revHead = tempPre->next, *tmp = revHead;
       tempPre->next = nullptr;
       t = n-m;
       while(t--)tmp = tmp->next;
       ListNode *right = tmp->next;
       tmp->next = nullptr;
       revHead = reverse(revHead);
       tempPre->next = revHead;
       while(revHead->next) revHead = revHead->next;
       revHead->next = right;
       return dummy.next;
    }
};
