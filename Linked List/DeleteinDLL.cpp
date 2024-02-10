//Delete Head of DLL 
Node* deleteHead(Node* head){
    if(head == NULL || head->next==NULL) return NULL;
    
    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    free(prev);
    return head;
}

//Delete the tail of DLL
Node* deleteTail(Node* head){
    Node* tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    Node* prev = tail->back;
    tail->back = nullptr;
    prev->next = nullptr;
    free(tail);
    return head;
}

//Delete the kth node from DLL 
Node* deleteK(Node* head, int k){
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        if(count==k) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* front = temp->next;
    
    if(prev==NULL && front==NULL){
        free(temp);
        return NULL;
    }
    else if(prev==NULL){
        deleteHead(head);
        return;
    }
    else if(front==NULL){
        deleteTail(head);
        return;
    }
    else{
        prev->next = front;
        front->back = prev;
        temp->next = NULL;
        temp->back = null;
        free(temp);
        return;
    }
}