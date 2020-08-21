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
    void mergeLists(ListNode *l1, ListNode *l2)
    {
        //Now , here we have to derive the logic for
        //merging the first half and second half of the linked list.
        while (l1 != NULL)
        {
            ListNode *l1_next = l1->next;
            ListNode *l2_next = l2->next;

            l1->next = l2;

            if (l1_next == NULL)
            {
                break;
            }

            l2->next = l1_next;
            l1 = l1_next;
            l2 = l2_next;
        }
    }

    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *current_node = head;

        while (current_node != NULL)
        {
            //Now , Here we are drawing that logic for the reversal of the linked list:
            ListNode *next_node = current_node->next;
            current_node->next = prev;
            prev = current_node;
            current_node = next_node;
        }

        return prev;
    }

    void reorderList(ListNode *head)
    {
        //Base Case For The Problem :
        if (head == NULL || head->next == NULL)
            return;
        ListNode *l1 = head;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = NULL;

        //Now , Understanding this Part Of The Stuff is Really Important
        while (fast != NULL && fast->next != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = NULL;

        //Reversal Of The Second Half Of the Linked List
        ListNode *l2 = reverse(slow);

        //Now , we have to merge both the first half and the second half of the linked list;

        mergeLists(l1, l2);
    }
};