//Insert before head
Node* InsertHead(Node* head, int value){
    Node* newHead = new Node(val,head,nullptr);
    head->back = newHead;
    return newHead;
}

//Insert before tail
Node* InsertBeforeTail(Node* head, int value){
    Node* tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    Node* prev = tail->back;
    Node* newNode = new Node(10,tail,prev);
    prev->next = newNode;
    tail->back = newNode;
    return head;
}

//insert before Kth element
Node* InsertBeforeK(Node* head, int k, int value){
    if(k==1) InsertHead(head,value);
    
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        if(count==k) break;
        temp = temp->next;
    }
    Node* prev = tail->back;
    Node* newNode = new Node(10,tail,prev);
    prev->next = newNode;
    tail->back = newNode;
    return head;

}