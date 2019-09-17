void reverse_util(SinglyLinkedListNode* head) {

    if(head->next == nullptr)
        return;

    reverse_util(head->next);
    head->next->next = head;

}

SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {

    SinglyLinkedListNode* tail = head;
    while(tail->next!=nullptr)
        tail=tail->next;
    reverse_util(head);
    head->next=nullptr;
    return tail;

}