// 2. program to arrange linked list so that it has alternating high and low values. 
// every node of the list is higher than left and right node
// input: 1 2 3 4 5    output: 1 3 2 5 4 



#include <stdio.h>
#include <stdlib.h>
 
// A Linked List Node
struct Node
{
    int data;
    struct Node* next;
};
 
 struct Node *head=NULL,*temp=NULL,*p1=NULL;
 
 void add(int x) {
if(head==NULL) {
    struct Node *New=(struct Node *) malloc (sizeof(struct Node));
    head=New;
    New->data=x;
    New->next=NULL;
}

else {
    struct Node *New=(struct Node *) malloc (sizeof(struct Node));
    New->data=x;
    New->next=NULL;
    for(p1=head;p1->next!=NULL;p1=p1->next);
        p1->next=New;
}

}

 
// Helper function to print a given linked list
void printList()
{
    struct Node* ptr = head;
    
    while (ptr)
    {
        printf("%d —> ", ptr->data);
        ptr = ptr->next;
    }
 
    printf("null");
}
 
void swap(struct Node *first, struct Node *second)
{
    int temp = first->data;
    first->data = second->data;
    second->data = temp;
}
 
// Rearrange the linked list so that it has alternating high, low values
void rearrange()
{
    // empty list
    if (head == NULL) {
        return;
    }
 
    struct Node* prev = head;
    struct Node* curr = head->next;
 
    // start from the second node
    while (curr)
    {
        // if the previous node is greater than the current node, swap their values
        if (prev->data > curr->data) {
            swap(prev, curr);
        }
 
        // if the next node is greater than the current node, swap their values
        if (curr->next && curr->next->data > curr->data) {
            swap(curr->next, curr);
        }
 
        // update `prev` and `curr` node
        prev = curr->next;
 
        if (!curr->next) {
            break;
        }
 
        curr = curr->next->next;
    }
}
 
int main(void)
{
    // input keys
    int x,INT;
    printf("\n Enter the data in a list :> \n");
    while((x=getchar())!='\n'){
    INT = x-'0';
    add(INT);
    }
    
 
    rearrange();
    printList();
 
    return 0;
}
