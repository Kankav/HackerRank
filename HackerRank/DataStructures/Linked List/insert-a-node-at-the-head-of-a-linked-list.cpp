SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {

    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    newNode->next=nullptr;

    if(llist == nullptr){
        llist = newNode;
        return llist;
    }
    
    newNode->next=llist;
    llist=newNode;
    return llist;	

}