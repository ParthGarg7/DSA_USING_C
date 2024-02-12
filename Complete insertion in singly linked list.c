#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head, *new_node, *temp;

// for making sure the node number taken is valid
int node_number(int num)
{
    int value;
    char ch;

    while (scanf("%d", &value) != 1 || value < 0 || value >= num)
    {
        printf("Enter a valid node number\n");
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
    }

    while ((ch = getchar()) != '\n' && ch != EOF)
        ;

    return value;
}

int scan()
{
    int value;
    char ch;

    while (scanf("%d", &value) != 1)
    {
        printf("Invalid input.Enter a integer: ");
        while ((ch = getchar() != '\n' && ch != EOF))
            ;
    }

    while ((ch = getchar() != '\n' && ch != EOF))
        ;

    return value;
}

int main()
{
    int counter, switch_ch, value, count;

    counter = 0;

    printf("This is a program of Insertion in the linked list\n");

    while (1)
    {

        printf("There are currently %d node in the list\n", counter);
        printf("This is the Current list\n");
        temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }

        printf("\nPress 0 for exit");
        printf("\nPress 1 for insertion at the starting of the list");
        printf("\nPress 2 for insertion at the ending of the list");
        printf("\nPress 3 for insertion after particular node of the list");
        printf("\nPress 4 for insertion after particular value in the list\n");

        switch_ch = scan();

        switch (switch_ch)
        {

        case 0:
        {
            // for printing the linked list
            printf("\n\n\tThis is the Final list\n\t");
            temp = head;
            while (temp != NULL)
            {
                printf("%d ", temp->data);
                temp = temp->next;
            }

            // Free the allocated memory for each node
            temp = head;
            while (temp != NULL)
            {
                struct node *next_node = temp->next;
                free(temp);
                temp = next_node;
            }

            exit(0);
        }
        break;

        case 1:
        {
            printf("Enter the number you want to insert in the node\n");
            value = scan();

            new_node = (struct node *)malloc(sizeof(struct node));
            counter++;

            new_node->data = value;
            new_node->next = NULL;

            if (new_node == NULL)
            {
                printf("Memory is full\n");
                return 1;
            }
            else if (head == NULL)
            {
                head = new_node;
                temp = head;
            }
            else
            {
                new_node->next = head;
                head = new_node;
            }
        }
        break;

        case 2:
        {
            printf("Enter the number you want to insert in the node\n");
            value = scan();

            new_node = (struct node *)malloc(sizeof(struct node));
            counter++;

            new_node->data = value;
            new_node->next = NULL;

            if (new_node == NULL)
            {
                printf("Memory is full\n");
                return 1;
            }
            else if (head == NULL)
            {
                head = new_node;
                temp = head;
            }
            else
            {
                // Traverse to the end of the list
                temp = head;
                while (temp->next != NULL)
                    temp = temp->next;

                // Link the new node to the end of the list
                temp->next = new_node;
            }
        }
        break;

        case 3:
        {
            // allocating memory to new node
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->next = NULL;

            printf("Enter the value you want to insert\n");
            value = scan();

            // assigning data in new node
            new_node->data = value;
            counter++;

            printf("\n\nnode %d is created\n", counter);

            // if allocation is fail
            if (new_node == NULL)
            {
                printf("Memory is full\ncan not insert\n");
                return 1;
            }
            // creation of new node
            else if (head == NULL)
            {
                head = new_node;
                temp = head;
            }
            else
            {
                printf("After which node you want to insert the new node\n");
                count = node_number(counter);

                temp = head;
                for (int i = 1; i < count; i++)
                    temp = temp->next;

                new_node->next = temp->next;
                temp->next = new_node;
            }
        }
        break;

        case 4:
        {
            // allocating memory to new node
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->next = NULL;

            printf("Enter the value you want to insert\n");
            value = scan();

            // assigning data in new node
            new_node->data = value;
            counter++;

            printf("\n\nnode %d is created\n", counter);

            // if allocation is fail
            if (new_node == NULL)
            {
                printf("Memory is full\ncan not insert\n");
                return 1;
            }
            // creation of new node
            else if (head == NULL)
            {
                head = new_node;
                temp = head;
            }
            else
            {
                printf("Enter the value after which you want insert the new node\n");
                count = scan();

                temp = head;
                while (temp != NULL)
                {
                    if (temp->data == count)
                        break;

                    temp = temp->next;
                }

                if (temp == NULL)
                {
                    printf("%d is not present in the list\n", count);
                }
                else
                {
                    new_node->next = temp->next;
                    temp->next = new_node;
                }
            }
        }
        break;

        default:
        {
            printf("Invalid input\nEnter a number from the options below\n");
        }
        break;
        }
    }

    return 0;
}