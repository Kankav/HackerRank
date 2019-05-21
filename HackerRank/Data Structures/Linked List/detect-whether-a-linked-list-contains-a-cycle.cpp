bool has_cycle(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* temp = head;
    SinglyLinkedListNode* temp2 = head;

    while(temp!=nullptr && temp2!=nullptr){
        
        temp=temp->next;

        if(temp2->next==nullptr)
            return false;
            
        temp2=temp2->next->next;

        if(temp==temp2)
            return true;
    }
    return false;

}