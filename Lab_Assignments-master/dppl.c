#include <stdio.h>
#include <stdlib.h>

struct node
{

    int data;
    struct node *next;
};

struct node *insert(int value, struct node *root)
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
        struct node *tmp = NULL;
        tmp = root;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = temp;
    }
    return root;
}

void enumerate(struct node *root)
{
    struct node *tmp;
    tmp = root;
    for (int i = 0; tmp != NULL; i++)
    {
        printf("%d\t", tmp->data);
        tmp = tmp->next;
    }
}

int size(struct node *root)
{
    struct node *tmp;
    tmp = root;
    int cap = 0;
    for (int i = 0; tmp != NULL; i++)
    {
        cap++;
        tmp = tmp->next;
    }
    printf("\n%d\n", cap);
    return cap;
}

void delete (int value, struct node *root)
{
    struct node *tmp;
    tmp = root;

    if (root->data == value)
    {
        root = root->next;
    }
    else
    {
        for (int i = 0; tmp->next->data != value; i++)
        {

            tmp = tmp->next;
        }

        printf("Deleted: %d", tmp->next->data);
        tmp->next = tmp->next->next;
    }
}

struct node *build(int arr[], int n)
{

    struct node *temp = NULL;
    for (int i = 0; i < n; i++)
    {

        temp = insert(arr[i], temp);
    }
    printf("Created\n");
    enumerate(temp);
    return temp;
}

void is_empty(struct node *root)
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

int is_element_of(int value, struct node *root)
{

    struct node *temp = NULL;
    temp = root;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            printf("Element is present \n");
            return 1;
        }
        else
            temp = temp->next;
    }
    printf("Element is not present \n");
    return 0;
}

int is_element(int value, struct node *root)
{

    struct node *temp = NULL;
    temp = root;
    while (temp != NULL)
    {
        if (temp->data == value)
        {

            return 1;
        }
        else
            temp = temp->next;
    }

    return 0;
}

void union1(struct node *S, struct node *T)
{

    struct node *tmp = NULL;
    tmp = S;
    int k = size(S) + size(T);
    int *arr = malloc(k * sizeof(int));
    int count = 0;
    for (int i = 0; tmp != NULL; i++)
    {
        arr[i] = tmp->data;
        tmp = tmp->next;
        count++;
    }
    struct node *temp = NULL;

    temp = T;

    for (; temp != NULL;)
    {
        if (is_element(temp->data, S) == 0)
        {
            arr[count] = temp->data;
            count++;
        }
        temp = temp->next;
    }

    printf("Union : ");
    build(arr, count);
}

void intersection(struct node *S, struct node *T)
{

    int *arr = malloc(size(S) * sizeof(int));
    struct node *temp = S;
    int count = 0;
    while (temp != NULL)
    {

        if (is_element(temp->data, T) == 1)
        {
            arr[count] = temp->data;
            count++;
        }
        temp = temp->next;
    }
    printf("Intersection : ");
    build(arr, count);
}

void subset(struct node *S, struct node *T)
{

    int sizer = 0;
    struct node *tmp = NULL;

    tmp = S;
    while (tmp != NULL)
    {
        if (is_element(tmp->data, T) == 0)
        {
            printf("SubSet : Not A Subset");
            return;
        }
        else
        {

            tmp = tmp->next;
        }
    }
    printf("SubSet : It Is A Subset");
}

void diff(struct node *S, struct node *T)
{

    struct node *temp = NULL;
    struct node *ptr = NULL;
    int k = size(S);
    int *arr = malloc(k * sizeof(int));

    temp = S;

    for (; temp != NULL;)
    {
        if (is_element(temp->data, T) == 0)
        {
            ptr = insert(temp->data, ptr);
        }
        temp = temp->next;
    }

    printf("Diff : ");
    enumerate(ptr);
}

int main()
{
    struct node *root1 = NULL;

    root1 = insert(0, root1);
    root1 = insert(1, root1);
    root1 = insert(2, root1);
    root1 = insert(3, root1);
    root1 = insert(4, root1);
    root1 = insert(5, root1);
    enumerate(root1);
    // size(root1);
    // delete (2, root1);
    // printf("\n");
    // enumerate(root1);
    // printf("Hey");
    // enumerate(root1);
    // size(root1);
    // is_empty(root1);
    // is_element_of(1, root1);

    struct node *root2 = NULL;

    root2 = insert(0, root2);
    // root2 = insert(7, root2);
    root2 = insert(2, root2);
    // root2 = insert(8, root2);
    // root2 = insert(10, root2);
    // root2 = insert(3, root2);
    enumerate(root2);

    union1(root1, root2);
    intersection(root1, root2);
    subset(root1, root2);
    diff(root1, root2);
    // int arr[] = {0, 1, 2, 3, 4, 5, 6, 7};
    // struct node *ptr = NULL;
    // ptr = build(arr, 8);
    // is_element_of(8, ptr);
}