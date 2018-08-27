#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef char LinkType;
typedef struct LinkNode{
	LinkType data;
	struct LinkNode* next;
}LinkNode;

void LinkCreate(LinkNode** head){
	*head=NULL;
}
LinkNode* LinkNodeCreate(LinkType data){
	LinkNode* ret=(LinkNode*)malloc(sizeof(LinkNode));
	ret->data=data;
	ret->next=NULL;
}
void LinkDestory(LinkNode* head){
	LinkNode* p=head;
	while(head!=NULL){
		p=head;
		head=head->next;
		free(p);
	}
}
void LinkPrint(LinkNode* head){
	while(head!=NULL){
		printf("[data:%c] |",head->data);
		printf("next[");
		if(head->next!=NULL){
			printf("%-4c|",head->next->data);
		}
		else printf("NULL|");
		printf("%p]",head->next);
	
	
		printf("\n");
		head=head->next;
	}
	printf("\n\n");
}

LinkNode* Merge(LinkNode* pHead1, LinkNode* pHead2)
{
	LinkNode* ret=NULL;
	LinkNode* tail=NULL;
	if(pHead1==NULL&&pHead2==NULL){
		return NULL;
	}
	while(pHead1!=NULL && pHead2!=NULL){
		if(ret==NULL){
			tail=(LinkNode* )malloc(sizeof(LinkNode));
			ret=tail;
		}
		else{
			tail->next=(LinkNode* )malloc(sizeof(LinkNode));
			tail=tail->next;
		}
		if(pHead1->data < pHead2->data){
			tail->data=pHead1->data;
			pHead1=pHead1->next;
		}
		else {
			tail->data=pHead2->data;
			pHead2=pHead2->next;
		}	
	}
	
	while(pHead1!=NULL){
		if(ret==NULL){
			tail=(LinkNode* )malloc(sizeof(LinkNode));
			ret=tail;
		}
		else{
			tail->next=(LinkNode* )malloc(sizeof(LinkNode));
			tail=tail->next;
		}
		tail->data=pHead1->data;
		pHead1=pHead1->next;
	}
	while(pHead2!=NULL){
		if(ret==NULL){
			tail=(LinkNode* )malloc(sizeof(LinkNode));
			ret=tail;
		}
		else{
			tail->next=(LinkNode* )malloc(sizeof(LinkNode));
			tail=tail->next;
		}
		tail->data=pHead2->data;
		pHead2=pHead2->next;
	}
	tail->next=NULL;
	return ret;
}
/*
void Test(){
	LinkNode* head;
	LinkNode* p;
	LinkCreate(&head);
	head=LinkNodeCreate('a');
	head->next=LinkNodeCreate('b');
	p=head->next;
	p->random=NULL;//b->random=NULL
	p->next=LinkNodeCreate('c');	
	p=p->next;	
	p->random=head->next;//c->random=b
	head->random=p;//a->random=c
	p->next=LinkNodeCreate('d');
	p=p->next;
	p->next=NULL;	
	p->random=head;//d->random=a
	LinkPrint(head);
	
	LinkNode* ret=Copy(head);
	LinkPrint(ret);
	LinkDestory(ret);
	LinkDestory(head);
}
*/
void Test2(){
	LinkNode* head;
	LinkNode* p,*q;
	LinkCreate(&head);
	head=LinkNodeCreate('c');
	p=head;
	p->next=LinkNodeCreate('c');
	p=p->next;
	p->next=LinkNodeCreate('c');
	p=p->next;
	p->next=LinkNodeCreate('d');
	p=p->next;
	p->next=LinkNodeCreate('g');
	p=p->next;
	p->next=NULL;
	LinkPrint(head);
	LinkNode* head2;
	LinkCreate(&head2);
	head2=LinkNodeCreate('a');
	p=head2;
	p->next=LinkNodeCreate('b');
	p=p->next;
	p->next=LinkNodeCreate('e');
	p=p->next;
	p->next=LinkNodeCreate('f');
	p=p->next;
	p->next=LinkNodeCreate('g');
	p=p->next;
	p->next=NULL;	
	LinkPrint(head2);
	LinkNode* ret=Merge(head,head2);
	LinkPrint(ret);
	LinkDestory(ret);
	LinkDestory(head);
	LinkDestory(head2);
}
int main(int argc, char *argv[]) {
	Test2();
	return 0;
}
