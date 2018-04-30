#include <stdlib.h>
#include <stdio.h>

typedef struct node {
int value;
int key;
struct node *right;
struct node *left;
} node;

typedef struct queue {
        struct queue *next;
        struct queue *prev;
        struct node *point;
} queue;

queue *head=NULL;
queue *tail=NULL;

node *init()
{
node *tmp=malloc(sizeof(node));
tmp->key=-1;
tmp->value=0;
tmp->right=NULL;
tmp->left=NULL;
return tmp;
}

void vvod(node *root, int k, int data)
{
        if (root->key==-1)
        {
                root->key=k;
                root->value=data;
        }
        else
        {
                while (1)
                {
                        if (k>root->key)
                        {
                                if (root->right==NULL)
                                {
                                        node *tmp=init();
                                        root->right=tmp;
                                        tmp->key=k;
                                        tmp->value=data;
                                        break;
                                }
                                else
                                {
                                        root=root->right;
                                        continue;
                                }
                        }
                        else if (k<root->key)
                        {
                                if (root->left==NULL)
                                {
                                        node *tmp=init();
                                        root->left=tmp;
                                        tmp->key=k;
                                        tmp->value=data;
                                        break;
                                }
                                else
                                {
                                        root=root->left;
                                        continue;
                                }
                        }
                        else if (k==root->key)
                        {
                                root->value=data;
                                break;
                        }

                }
        }
}

int q_isEmpty()
{
        if ((head==NULL)&&(tail==NULL))
                return 1;
        else
                return 0;
}

void q_init (node *point)
{
        queue *tmp = malloc(sizeof(queue));
        tmp->point = point;
        tmp->next = NULL;
        head = tmp;
        tail = tmp;
}


void q_add(node *point)
{
        if (q_isEmpty()==1)
                q_init (point);
        else
        {
                queue *tmp = malloc(sizeof(queue));
                tmp->point=point;
                tmp->next=NULL;
                tail->next=tmp;
                tail=tmp;
        }
}

node *q_get_first()
{
        if (q_isEmpty()==0)
        {
                queue *tmp=head;
                return tmp->point;
        }
        else
        {
                printf("Очередь пуста!\n");
                return NULL;
        }
}

void q_destroy()
{
        if (q_isEmpty()==0)
        {
                queue *tmp=head;
                queue *temp=NULL;
                do{
                        temp=tmp->next;
                        free(tmp);
                        tmp=temp;
                }while (tmp!=NULL);
                head=NULL;
                tail=NULL;
        }
}

void q_remove_first()
{
        queue *tmp=head;
        int no_op=0;

        if (q_isEmpty()==1)
        {
                no_op = 1;
                printf("Очередь пуста!\n");
        }
        if (head==tail && no_op==0)
        {
                q_destroy();
                no_op=1;
        }

        if (no_op==0)
        {
                head=tmp->next;
                free(tmp);
                no_op=1;
        }
}


void width(node *root)
{
q_add(root);

        while (1)
        {
                if (root->left!=NULL)
                        q_add(root->left);

                if (root->right!=NULL)
                        q_add(root->right);

                printf ("%d ", root->value);
                q_remove_first();
                if (q_isEmpty()==1)
                        break;
                root=q_get_first();
        }
}



int main()
{
        int n,key,value;
        node *root1=init();
        scanf("%d", &n);
        for (int i=0; i<n;i++)
        {
                scanf("%d", &key);
                scanf("%d", &value);
                vvod(root1, key,value);
        }
        width(root1);
        printf("\n");
        return 0;
}

