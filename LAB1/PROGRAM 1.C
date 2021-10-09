// 1. program that recursively checks if the linked list of characters is palindrome or not.


#include<stdio.h>
#include<stdlib.h>

struct node{
char ch;
struct node *next;
};

int count=0;
struct node *head=NULL;

struct node *p1=NULL;
void addnode(char ch) {
if(head==NULL) {
    struct node *New=(struct node *) malloc (sizeof(struct node));
    head=New;
    New->ch=ch;
    New->next=NULL;
}

else {
    struct node *New=(struct node *) malloc (sizeof(struct node));
    New->ch=ch;
    New->next=NULL;
    for(p1=head;p1->next!=NULL;p1=p1->next);
        p1->next=New;
}
count++;
}

int palindrome(){
    char arr[count];
    int i=0;
    p1=head;
    
    while(p1!=NULL){
      arr[i]=p1->ch;
      printf("\t %c ",p1->ch);
      i++;
      p1=p1->next;
    }
    
        printf("\n printing array values: \t");
        for(i=0;i<count;i++){
            printf("%c ",arr[i]);
        }
        p1=head;
        int k=count-1;
        int c=0;
    while(p1!=NULL&&k>=0&&c<=count){
        if(p1->ch==arr[k]){
            c++;
            p1=p1->next;
            k--;
        }
        else
        return 0;
        
    } 
    
    if(c==count){
        return 1;
    }
    else return 0;
    
}
void main() {
    char character,frm,to;
    printf("\nEnter the characters \t");
    while((character=getchar())!='\n')
        addnode(character);
    for(p1=head;p1!=NULL;p1=p1->next)
        printf("\n%c",p1->ch);

int ispalin=palindrome();    
if(ispalin){
    printf("\n\n entered characters are palindrome");
    
}
else
printf("\n\n Entered characters are not palindrome");
}
