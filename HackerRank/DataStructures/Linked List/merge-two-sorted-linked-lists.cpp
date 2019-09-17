SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

    SinglyLinkedListNode* head;
    SinglyLinkedListNode* temp;
    SinglyLinkedListNode* next1 = head1;
    SinglyLinkedListNode* next2 = head2;    

    if(next1->data <= next2->data){
        head = head1;
        next1 = next1->next;
    }else{
        head = head2;
        next2 = next2->next;
    }
    temp = head;

    while(next1!=nullptr ||  next2!=nullptr){

        if(next1==nullptr){
            while(next2!=nullptr){
                temp->next = next2;
                next2 = next2->next;
                temp = temp->next;
            }
            break;
        }

        else if(next2==nullptr){
            while(next1!=nullptr){
                temp->next = next1;
                next1 = next1->next;
                temp = temp->next;
            }
            break;
        }

        if(next1->data <= next2->data){
            temp->next = next1;
            next1 = next1->next;
        }else{
            temp->next = next2;
            next2 = next2->next;            
        }

        temp=temp->next;

    }

    return head;

}
