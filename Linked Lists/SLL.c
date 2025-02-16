#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    int data;
    struct Node *next;
}*head, *tail;

void init()
{
    head = tail = NULL;
}

struct Node *createNode()
{
    return ((struct Node *)malloc(sizeof(struct Node)));
}

void create(int A[], int n)
{
    struct Node *ptr;
    int i;
    for (i=0; i<n; i++)
    {
        ptr = createNode();
        ptr->data = A[i];
        ptr->next = NULL;
        if (head == NULL)
            head = tail = ptr;
        else
        {
            tail->next = ptr;
            tail = ptr;
        }
    }
}

struct Node *search(int key)
{
    struct Node *ptr;
    for (ptr=head; ptr!=NULL; ptr=ptr->next)
    {
        if (ptr->data == key)
            return ptr;
    }
    return NULL;
}

void insert(int key)
{
    struct Node *ptr1, *ptr2, *newNode;
    if (key < head->data)
    {
        newNode = createNode();
        newNode->data = key;
        newNode->next = head;
        head = newNode;
    }
    else
    {
        ptr1 = head;
        ptr2 = ptr1->next;
        while ((key>ptr2->data))
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            if (ptr2==NULL)
                break;
        }
        newNode = createNode();
        newNode->data = key;
        newNode->next = ptr2;
        ptr1->next = newNode;
    }
}

void delete(int pos)
{
    struct Node *temp, *temp1;
    temp = head;
    if (pos==1)
    {
        head=head->next;
        free(temp);
    }
    else
    {
        int i;
        for (i=2; i<pos; i++)
            temp = temp->next;
        temp1 = temp->next;
        temp->next = temp->next->next;
        free(temp1);
    }
}

void traverse()
{
    struct Node *ptr;
    printf("\n Linked List is : \n");
    for (ptr=head; ptr; ptr=ptr->next)
    {
        printf("|%d|%p|-> ",ptr->data, ptr->next);
    }
}

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* next = NULL;
    while (head != NULL) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    head = prev;
    return head;
}

int main()
{
    init();
    int A[] = {2, 6, 11, 14, 17};
    int n = sizeof(A)/sizeof(int);
    create(A, n);
    printf("\n Head Address is : %p",head);
    traverse();
    insert(19);traverse();
    insert(1);traverse();
    insert(12);traverse();
    delete(1);traverse();
    delete(3);traverse();
    delete(6);traverse();

    int key = 2;
    if (search(key))
    {
        printf("\nElement %d found in the list", key);
    }
    else
    {
        printf("\nElement %d not found in the list", key);
    }
    head=reverseList(head); traverse();
}


