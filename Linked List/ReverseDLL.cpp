Node* reverseDLL(Node* head)
{   
    if(head==NULL || head->next==NULL) return head;
    Node* last = NULL;
    Node* current = head;
    while(current!=NULL){
        last = current->prev;
        current->prev = current->next;
        current->next = last;
        current = current->prev;
    }
    return (last->prev);
}