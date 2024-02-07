//Insert at the last node of LL
Node *InsertLast(Node *head, int val){
    if(head == nullptr) return new Node(val);
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
    return head;
}

//Insert at the head of LL
Node* InsertHead(Node* head, int val){
    Node* temp = new Node(val,head);
    return temp;
}

//Insert at Kth position of LL
Node* InsertatK(Node* head,int val, int k){
    if(head == nullptr){
        if(k==1) return new Node(val);
        else return nullptr;
    }
    
    if(k==1){
        Node* temp = new Node(val,head);
        return temp;
    }
    
    int count = 0;
    Node* temp = head;
    while(temp!=nullptr){
        count++;
        if(count==k-1){
            Node* newNode = new Node(val,temp->next);
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }
}