int searchInLinkedList(Node<int> *head, int k) {
    Node<int>* temp = head;
    while(temp!=nullptr){
        if(temp->data == k){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int length(Node *head)
{
	int count = 0;
    Node* temp = head;
    while(temp!=nullptr){
        count++;
        temp = temp->next;
    }
    return count;
}