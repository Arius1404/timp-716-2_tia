#include <stdio.h>
#include <stdlib.h>
#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY   -102

typedef struct node {
    int value;
    struct node *next;
} node;
typedef node* list;

int init(list *root){                       
    *root = NULL;
    return 1;
}

int push(list *head, int value){            
    list tmp=malloc(sizeof(node));
    if(tmp==NULL) exit(STACK_OVERFLOW);
    tmp->next=*head;
    tmp->value=value;
    *head = tmp;
    return 1;
}

list find(list root, int value) {           
    while (root->value != value) {
        root = root->next;
        if (root == NULL) return NULL;
    }
    return root;
}


int pop(node **head) {
    node *out;
    int value;
    if (*head == NULL) {
        exit(STACK_UNDERFLOW);
    }
    out = *head;
    *head = (*head)->next;
    value = out->value;
    free(out);
    return value;
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
    int x, n, m, k;

    scanf("%d", &n);
    if (n > 0) {
        for(int i=0;i<n;i++)
        {
            scanf("%d", &x);
            push(&head, x);
        }
    }
    print(&head);
    scanf("%d",&m);
    list del = find(head, m);
    if (del!= NULL)
        printf("value has been found\n");
    else
        printf("value has not been found\n");
    print(&head);
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        pop(&head);
    }
    print(&head);
    destroy(&head);
    print(&head);
    system("pause");
    return 0;
}

