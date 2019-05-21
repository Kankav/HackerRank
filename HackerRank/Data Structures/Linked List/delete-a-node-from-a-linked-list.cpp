SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {

    if(position==0){
        head=head->next;
        return head;
    }

    SinglyLinkedListNode* temp=head;

    while(--position){
        temp=temp->next;
    }

    temp->next = temp->next->next;
    return head;

}