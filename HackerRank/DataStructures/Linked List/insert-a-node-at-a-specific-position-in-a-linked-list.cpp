SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {

    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);

    SinglyLinkedListNode* temp = head;

    if(position==0){
        newNode->next = head;
        head = newNode;
        return head;
    }

    
    while(--position){
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;

}