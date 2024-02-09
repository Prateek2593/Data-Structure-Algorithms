Node* constructDLL(vector<int>& arr) {
    int n = arr.size();
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1;i<n;i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

