/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(head==NULL||k==0){
        return head;
    }
    int n=0;
    struct ListNode* last=head;
    while(last->next!=NULL){
        n++;
        last=last->next;
    }
    n++;
    last->next=head;
    int rotate=(n-(k%n));
    for(int i=0;i<rotate;i++){
        head=head->next;
    }
    struct ListNode* ptr1=head;
    while(ptr1->next!=head){
        ptr1=ptr1->next;
    }
    ptr1->next=NULL;
    return head;
}
