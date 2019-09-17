SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {

    SinglyLinkedListNode* curr = head;
    SinglyLinkedListNode* temp,prev;

    while(curr->next !=nullptr){

        nextt = curr->next;
        
        curr->next = prev;

        prev = curr;

        curr = nextt;       

    }

    head->next=nullptr;
    return curr;

}