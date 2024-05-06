/*Approach-1 (Using stack):
Time Complexity (T.C): O(n)
Space Complexity (S.C): O(n)
This approach utilizes a stack to store the nodes in reverse order based on their values. It then iterates through the stack, constructing a new linked list with nodes having non-decreasing values. It has a moderate space complexity due to the stack usage.
*/
ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        ListNode* temp = head;
        while (temp != NULL) {
            st.push(temp);
            temp = temp->next;
        }
        temp = st.top();
        st.pop();
        int maxNode = temp->val;
        ListNode* result = new ListNode(temp->val);
        while (!st.empty()) {
            temp = st.top();
            st.pop();
            if(temp->val < maxNode){
                continue;
            }else{
                ListNode* newNode = new ListNode(temp->val);
                newNode->next = result;
                result = newNode;
                maxNode = temp->val;
            }
        }
        return result;
}

/*Approach-2 (Using Recursion):
Time Complexity (T.C): O(n)
Space Complexity (S.C): O(n) due to system stack usage
This approach leverages recursion to traverse the linked list in reverse order. It compares each node with its next node and adjusts the pointers accordingly to create the resulting list. The space complexity is determined by the system stack due to recursive calls.
*/
ListNode* removeNodes(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* nextNode = removeNodes(head->next);
        if(head->val < nextNode->val){
            delete head;
            return nextNode;
        }
        head->next = nextNode;
        return head;
}

/*Approach-3 (Using reverse):
Time Complexity (T.C): O(n)
Space Complexity (S.C): O(1)
This approach involves reversing the linked list and then iterating through it to identify and remove nodes with values less than the maximum encountered so far. It modifies the original list in place, resulting in constant space complexity.
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }
    ListNode* removeNodes(ListNode* head) {
        head = reverseList(head);
        int maxNode = -1;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL){
            maxNode = max(maxNode, curr->val);

            if(curr->val < maxNode){
                prev->next = curr->next;
                ListNode* temp = curr;
                curr = curr->next;
                delete(temp);
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        return reverseList(head);
    }
};
