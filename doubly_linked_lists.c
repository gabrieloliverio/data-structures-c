#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *start = NULL;
struct node *create_list(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
struct node *sort(struct node *);

int main()
{
    int option;

    do
    {
        system("clear");
        printf("\n******************************************************************");
        printf("\n1. Create");
        printf("\n2. Display");
        printf("\n3. Add node at the beggining");
        printf("\n4. Add node at the end");
        printf("\n5. Add before a given node");
        printf("\n6. Add after a given node");
        printf("\n7. Delete node from the beggining");
        printf("\n8. Delete node from the end");
        printf("\n9. Delete a given node");
        printf("\n10. Delete a node after a given node");
        printf("\n11. Delete the entire list");
        printf("\n12. Sort the list");
        printf("\n13. Exit");
        printf("\n>>> ");
        scanf("%d", &option);
        system("clear");

        switch (option)
        {
        case 1:
            start = create_list(start);
            break;
        case 2:
            start = display(start);
            break;
        case 3:
            start = insert_beg(start);
            break;
        case 4:
            start = insert_end(start);
            break;
        case 5:
            start = insert_before(start);
            break;
        case 6:
            start = insert_after(start);
            break;
        case 7:
            start = delete_beg(start);
            break;
        case 8:
            start = delete_end(start);
            break;
        case 9:
            start = delete_node(start);
            break;
        case 10:
            start = delete_after(start);
            break;
        case 11:
            start = delete_list(start);
            break;
        case 12:
            start = sort(start);
            break;
        default:
            break;
        }
    } while (option != 13);
}

struct node *create_list(struct node *start)
{
    struct node *new_node, *ptr, *preptr;
    int num;

    printf("\nEnter -1 to end...");

    printf("\n>>> ");
    scanf("%d", &num);
    system("clear");

    while (num != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;

        if (start == NULL)
        {
            new_node->next = NULL;
            new_node->prev = NULL;
            start = new_node;
        }
        else
        {
            ptr = start;
            preptr = start;

            while (ptr->next != NULL)
            {
                preptr = ptr;
                ptr = ptr->next;
            }

            ptr->next = new_node;
            ptr->prev = preptr;
            new_node->next = NULL;
        }

        printf("\n>>> ");
        scanf("%d", &num);
        system("clear");
    }

    return start;
}

struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;

    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }

    printf("\nPress any key to go back to the main menu...");
    getchar();
    getchar();

    return start;
}

struct node *insert_beg(struct node *start)
{
    int num;
    struct node *new_node, *ptr;

    printf("\nEnter the new node: ");
    scanf("%d", &num);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = start;
    start = new_node;

    printf("\nNode inserted.\n\nPress any key to go back to the main menu...");
    getchar();
    getchar();
                
    return start;
}

struct node *insert_end(struct node *start)
{
    int num;
    struct node *new_node, *ptr;

    printf("\nEnter the new node: ");
    scanf("%d", &num);

    new_node = (struct node *)malloc(sizeof(struct node));
    ptr = start;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    new_node->data = num;
    new_node->next = NULL;
    ptr->next = new_node;

    printf("\nNode inserted.\n\nPress any key to go back to the main menu...");
    getchar();
    getchar();

    return start;
}

struct node *insert_before(struct node *start)
{
    int num, before;
    struct node *new_node, *ptr, *preptr;

    printf("\nEnter the new node: ");
    scanf("%d", &num);

    printf("\nEnter the value of the node before: ");
    scanf("%d", &before);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    ptr = start;
    preptr = start;

    while (ptr->data != before)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    preptr->next = new_node;
    new_node->next = ptr;

    printf("\nNode inserted.\n\nPress any key to go back to the main menu...");
    getchar();
    getchar();

    return start;
}

struct node *insert_after(struct node *start)
{
    int num, after;
    struct node *new_node, *ptr, *preptr;

    printf("\nEnter the new node: ");
    scanf("%d", &num);

    printf("\nEnter the value of the node after: ");
    scanf("%d", &after);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    ptr = start;
    preptr = start;

    while (preptr->data != after)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    preptr->next = new_node;
    new_node->next = ptr;

    printf("\nNode inserted...\n\n");
    display(start);

    return start;
}

struct node *delete_beg(struct node *start)
{
    struct node *ptr;

    ptr = start;
    start = start->next;
    free(ptr);

    printf("\nNode deleted...\n\n");

    return start;
}

struct node *delete_end(struct node *start)
{
    struct node *ptr, *preptr;

    ptr = start;
    preptr = ptr;
    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    preptr->next = NULL;
    free(ptr);

    printf("\nNode deleted...\n\n");
    display(start);

    return start;
}

struct node *delete_after(struct node *start)
{
    struct node *ptr, *preptr;
    int num;

    printf("\nEnter the node value: ");
    scanf("%d", &num);

    ptr = start;
    preptr = ptr;

    while (preptr->data != num)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    preptr->next = ptr->next;
    free(ptr);

    printf("\nNode deleted...\n\n");
    display(start);

    return start;
}

struct node *delete_node(struct node *start)
{
    int val;
    struct node *ptr, *preptr;

    ptr = start;
    preptr = ptr;

    printf("\nEnter the node to be deleted: ");
    scanf("%d", &val);

    if (ptr->data == val)
    {
        start = delete_beg(start);
        display(start);
        return start;
    }
    else
    {
        while (ptr->data != val)
        {
            preptr = ptr;
            ptr = ptr->next;
        }

        preptr->next = ptr->next;
        free(ptr);
    }

    printf("\nNode deleted...\n\n");
    display(start);

    return start;
}

struct node *delete_list(struct node *start)
{
    struct node *ptr;

    ptr = start;

    if (start == NULL)
    {
        printf("List already empty. Press any key to go back to the main menu...");
        getchar();
        getchar();

        return start;
    }

    while (ptr != NULL)
    {
        start = delete_beg(start);
        ptr = start;
    }

    display(start);

    return start;
}

struct node *sort(struct node *start)
{
    struct node *ptr1, *ptr2;
    int temp;

    ptr1 = start;

    while (ptr1->next != NULL)
    {
        ptr2 = ptr1->next;

        while (ptr2->next != NULL)
        {
            if (ptr1->data > ptr2->data)
            {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }

            ptr2 = ptr2->next;
        }

        ptr1 = ptr1->next;
    }

    display(start);

    return start;
}