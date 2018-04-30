//#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
int value;
struct node *next;
struct node *prev;
} node;

typedef node* list;

int init(list *root)
{
	*root=NULL;
	return 1;
}

list find(list root, int value){
	while(root->value != value){
		root = root->next;
		if (root==NULL)
			return NULL;
	}
	return root;
}

int remove1(list *lst){
	if(*lst!=NULL){
		list del = *lst;
		if (((*lst)->prev!=NULL)&&((*lst)->next !=NULL)){
			(*lst)->prev->next=(*lst)->next;
			(*lst)->next->prev=(*lst)->prev;
		}
		if (((*lst)->prev==NULL)&&((*lst)->next!=NULL)){
			(*lst)->next->prev=NULL;
			(*lst)=(*lst)->next;
		}
		if (((*lst)->prev!=NULL)&&((*lst)->next==NULL)){
			(*lst)->prev->next=NULL;
		}
		free(del);
	}
	return 1;
}

int isEmpty(list root) {
	if (root) return 1;
		else return 0;
}

int destroy(list *root) {
	list next;
	while (*root != NULL) {
		next = *root;
        	*root = (*root)->next;
        	free(next);
	}  
    return 1;
}

int append(list *lst, int value) {
	if ((*lst) == NULL) {
        	list tmp = (list)malloc(sizeof(node));
        	tmp->next = NULL;
        	tmp->value = value;
        	tmp->prev = NULL;
        	*lst = tmp;
        	return 1;
    	}
	if ((*lst)->next == NULL) {
        	list tmp = (list)malloc(sizeof(node));
        	tmp->next = NULL;
        	tmp->value = value;
        	tmp->prev = *lst;
        	(*lst)->next = tmp;
        	return 1;
    	}
	else {
        	list tmp = (list)malloc(sizeof(node));
        	tmp->next = (*lst)->next;
        	tmp->value = value;
        	tmp->prev = *lst;
        	(*lst)->next->prev = tmp;
        	(*lst)->next = tmp;
        	return 1;
    	}
}

int prepend(list *lst, int value) {
	if ((*lst) == NULL) {
        	list tmp = (list)malloc(sizeof(node));
        	tmp->next = NULL;
        	tmp->value = value;
        	tmp->prev = NULL;
        	*lst = tmp;
        	return 1;
	}	
	if ((*lst)->prev == NULL) {
        	list tmp = (list)malloc(sizeof(node));
        	tmp->prev = NULL;
        	tmp->value = value;
        	tmp->next = *lst;
        	(*lst)->prev = tmp;
        	(*lst) = (*lst)->prev;
        	return 1;
	}
	else {
        	list tmp = (list)malloc(sizeof(node));
        	tmp->value = value;
        	tmp->prev = (*lst)->prev;
        	tmp->next = *lst;
        	(*lst)->prev->next = tmp;
        	(*lst)->prev = tmp;
        	return 1;
	}
}

int print(list *lst) {
	list temp = *lst;
	while (temp != NULL) {
        	printf("%d ", temp->value);
        	temp = temp->next;
	}
	printf("\n");
	return 1;
}

int main() {
	list head;
	init(&head);
	int i, x, n, k, m, a, b, c, d;
	scanf("%d", &n);
	if (n > 0) {
        	scanf("%d", &x);
        	append(&head, x);
    	}
	list temp = head;
	for (i = 1; i < n; i++) {
        	scanf("%d", &x);
        	append(&temp, x);
        	temp = temp->next;
    	}
	print(&head);
	scanf("%d", &k);
	if (k > n) 
		printf("Incorrect number inputted\n");
	else {
        if (k == 1) 
		remove1(&head);
        else {
            	list next = head;
        for (i = 1; i < k; i++) {
                next = next->next;
            }
        remove1(&next);
        }
    }
	print(&head);
	scanf("%d", &m);
	list del = find(head, m);
	if (del == head) 
		remove1(&head);
	else
 		remove1(&del);
	print(&head);
	scanf("%d%d", &a, &b);
	if (a > n) 
		printf("Incorrect number inputted\n");
	else {
        	list next = head;
        for (i = 1; i < a; i++) {
        	next = next->next;
        }
        append(&next, b);
    }
	print(&head);
	scanf("%d%d", &c, &d);
	if (c > n) 
		printf("Incorrect number inputted\n");
	if (c == 1) 
		prepend(&head, d);
	else {
        	list next = head;
        for (i = 1; i < c; i++) {
        	next = next->next;
        }
        prepend(&next, d);
    }
	print(&head);
return 0;
}
