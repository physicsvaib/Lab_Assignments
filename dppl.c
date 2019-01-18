#include <stdio.h>
#include <stdlib.h>

struct node
{

    int data;
    struct node *next;
};

struct node *root = NULL;

void insert(int value)
{

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;

    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        temp->next = root;
        root = temp;
    }
}

void enumerate()
{
    struct node *tmp;
    tmp = root;
    for (int i = 0; tmp != NULL; i++)
    {
        printf("%d", tmp->data);
        tmp = tmp->next;
    }
}

void size()
{
    struct node *tmp;
    tmp = root;
    int cap = 0;
    for (int i = 0; tmp != NULL; i++)
    {
        cap++;
        tmp = tmp->next;
    }
    printf("\n%d", cap);
}
void delete (int value)
{ // TODO Fix Delete for unknown values
    struct node *tmp;
    tmp = root;
    int countPosition = 0;
    for (int i = 0; tmp->next->data != value && tmp->next != NULL; i++)
    {
        countPosition++;
        tmp = tmp->next;
    }
    if (tmp->next->data == value)
    {
        printf("I Am Here");
        tmp->next = tmp->next->next;
    }
    else
    {
        printf("Not Found");
    }
}

void is_empty()
{
    if (root == NULL)
    {
        printf("Yes This Is Empty");
    }
    else
    {
        printf("Not Empty");
    }
}

void is_element_of(int value)
{
    struct node *tmp;
    tmp = root;
    int countele;
    for (int i = 0; tmp->data != value && tmp->next != NULL; i++)
    {
        countele++;
        tmp = tmp->next;
    }
    if (tmp->data == value)
    {
        printf("\nElement found at %d", countele);
    }
    else
    {
        printf("Not Found");
    }
}

int main()
{
    insert(0);
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    enumerate();
    size();
    delete (0);
    is_element_of(2);
    enumerate();
    is_element_of(7);
    size();
    is_empty();
}