// Problem Link - https://www.codingninjas.com/codestudio/problems/detect-the-first-node-of-the-loop_1112628?topList=striver-sde-sheet-problems&leftPanelTab=0

#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
        };

*****************************************************************/

Node *firstNode(Node *head)
{
    if(head==nullptr or head->next==nullptr)
        return nullptr;
    Node* fast = head;
    Node* slow = head;
    while(fast->next and fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast==slow)
        {
            fast = head;
            while(slow!=fast)
                slow = slow->next,fast = fast->next;
            return slow;
        }

    }
    return nullptr;
}