//Delete the last node of LL
Node *deleteLast(Node *head){
    if(head == nullptr || head->next==nullptr) return nullptr;

    Node* temp = head;
    while(temp->next->next != nullptr) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
    return head;
}

//Delete the head of LL
Node* deleteHead(Node* head){
    if(head == nullptr) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

//Delete Kth element of LL
Node* deleteK(Node* head, int k){
    if(head == nullptr) return head;
    if(k==1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int count = 0;
    Node* temp = head, prev = null;
    while(temp!=nullptr){
        count++;
        if(count == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}