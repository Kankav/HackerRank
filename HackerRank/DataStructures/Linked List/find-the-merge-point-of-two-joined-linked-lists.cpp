int findLen(SinglyLinkedListNode* head){

    int c=0;
    SinglyLinkedListNode* temp = head;
    while(temp!=nullptr){
        c++;
        temp=temp->next;
    }
    return c;
}

SinglyLinkedListNode* traverse(SinglyLinkedListNode* head, int len){

    while(len--){
        head=head->next;
    }

    return head;
}

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

    int len1 = findLen(head1);
    int len2 = findLen(head2);
    int diff = abs(len1-len2);

    if(len1 > len2){
        head1 = traverse(head1, diff);
    }else{
        head2 = traverse(head2, diff);
    }

    while(head1!=nullptr && head2!=nullptr && head1 != head2){

        head1=head1->next;
        head2=head2->next;

    }

    return head1->data;
}