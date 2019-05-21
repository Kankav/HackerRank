SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {

    SinglyLinkedListNode* temp = head;
    SinglyLinkedListNode* curr = head;   

    while(curr->next!=nullptr){

        int val = curr->data;

        temp = curr->next;

        while(temp!=nullptr && temp->data == val){
            temp=temp->next;
        }

        curr->next = temp;
        curr=curr->next;
        if(curr==nullptr)
            break;

    }

    return head;

}