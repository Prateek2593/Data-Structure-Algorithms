Node* removeKthNode(Node* head, int n)
{
    Node* fast = head;
    Node* slow = head;
    for(int i=0;i<n;i++) fast = fast->next;
    if(fast == NULL) return head->next;
    while(fast->next!=NULL){
        slow = slow->next;
        fast = fast->next;
    }
    Node* delNode = slow->next;
    slow->next = slow->next->next;
    delete(delNode);
    return head;
}