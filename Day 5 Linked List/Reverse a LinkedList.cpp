// Problem Link - https://www.codingninjas.com/codestudio/problems/799897?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    if(head==nullptr or head->next==nullptr)
        return head;
    LinkedListNode<int> * temp = head;
    LinkedListNode<int> * prev = temp;
    temp = temp->next;
    prev->next = nullptr;
    while(temp)
    {
        LinkedListNode<int> * nex = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nex;
    }
    return prev;
}