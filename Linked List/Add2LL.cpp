Node *addTwoNumbers(Node *num1, Node *num2){
    Node* dummy = new Node(-1);
    Node* current = dummy;
    Node* t1 = num1;
    Node* t2 = num2;
    int carry = 0;
    while(t1!=NULL || t2!=NULL){
        int sum = carry;
        if(t1){
            sum += t1->data;
            t1 = t1->next;
        } 
        if(t2){
            sum += t2->data;
            t2 = t2->next;
        } 
        Node* newNode = new Node(sum%10);
        carry = sum/10;

        current->next = newNode;
        current = current->next; 
    }
    if(carry){
        Node* newNode = new Node(carry);
        current->next = newNode;
    }
    return dummy->next;
}
