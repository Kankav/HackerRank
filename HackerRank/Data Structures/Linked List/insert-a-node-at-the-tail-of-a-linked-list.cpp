SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {

    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    newNode->next=nullptr;

    if(head == nullptr){
        head = newNode;
        return head;
    }
    
    SinglyLinkedListNode* temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }

    temp->next = newNode;
    return head;

}