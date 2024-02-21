#include <stdio.h>
#include <stdlib.h>

// creation of structure of singular linked list
struct node
{
    int data;
    struct node *next;
} *head, *new_node, *temp;

int Node_Counter;

// for taking a integer value as input
int ScanInput()
{
    int value;
    char ch;

    while (scanf("%d", &value) != 1)
    {
        printf("Invalid input. Please enter a integer: ");
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
    }

    while ((ch = getchar()) != '\n' && ch != EOF)
        ;

    return value;
}

void Print_List()
{
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void Free_list()
{
    temp = head;
    while (temp != NULL)
    {
        new_node = temp->next;
        free(temp);
        temp = new_node;
    }
}

int Dynamic_List()
{
    char choice1;

    head = NULL;
    temp = head;

    Node_Counter = 0;

    // infinite loop which will break when user wants
    while (1)
    {
        printf("There are currently %d node in the list\n", Node_Counter);

        // for printing the current status of the list
        printf("\tHere is the current list\n\t");
        Print_List();

        // Giving user choice to insert
        printf("\nDo you want to insert a node?\n");
        printf("Press y/Y for YES and N/n for NO\n");
        scanf(" %c", &choice1);

        if (choice1 == 'Y' || choice1 == 'y')
        {
            // Allocating memory to the new node
            new_node = (struct node *)malloc(sizeof(struct node));

            Node_Counter += 1;
            printf("\n\nnode %d is created\n", Node_Counter);

            // Checking of memory allocation
            if (new_node == NULL)
            {
                printf("Memory is full can't insert\nThank you");
                return 1;
            }

            // taking the data from the user
            printf("Enter the data you want to enter in the node %d\n", Node_Counter);

            // assigning values in the node
            new_node->data = ScanInput();
            new_node->next = NULL;

            if (head == NULL)
            {
                head = new_node;
                temp = head;
            }
            else
            {
                // Traverse to the end of the list
                temp = head;
                while (temp->next != NULL) // method 2
                    temp = temp->next;     // temp->next = newnode;
                                           // temp = newnode

                // Link the new node to the end of the list
                temp->next = new_node;
            }
        }
        else if (choice1 == 'N' || choice1 == 'n')
            break;
        else
            printf("Invalid option\nEnter From the option below\n");
    }
}

int Static_List()
{
    int ListSize;
    char choice1;

    head = NULL;
    temp = head;

    Node_Counter = 0;

    printf("Enter the size of the list\n");
    ListSize = ScanInput();

    for (int i = 0; i < ListSize; i++)
    {

        printf("There are currently %d node in the list\n", Node_Counter);

        // for printing the current status of the list
        printf("\tHere is the current list\n\t");
        Print_List();

        // Allocating memory to the new node
        new_node = (struct node *)malloc(sizeof(struct node));

        Node_Counter += 1;
        printf("\n\nnode %d is created\n", Node_Counter);

        // Checking of memory allocation
        if (new_node == NULL)
        {
            printf("Memory is full can't insert\nThank you");
            return 1;
        }

        // taking the data from the user
        printf("Enter the data you want to enter in the node %d\n", Node_Counter);

        // assigning values in the node
        new_node->data = ScanInput();
        new_node->next = NULL;

        if (head == NULL)
        {
            head = new_node;
            temp = head;
        }
        else
        {
            // Traverse to the end of the list
            temp = head;
            while (temp->next != NULL) // method 2
                temp = temp->next;     // temp->next = newnode;
                                       // temp = newnode

            // Link the new node to the end of the list
            temp->next = new_node;
        }
    }
}

// Program for insertion at end in the linked list
void main()
{
    // Variables used in different part of code
    int choice1;

    head = NULL;
    temp = head;

    printf("Hi this is a program of Insertion of node in the ending of the singular linked list\n\n");

    while (1)
    {
        printf("\nPress 0 for exit\n");
        printf("Press 1 for new Static size list\n");
        printf("Press 2 for new Dynamic size list\n");

        choice1 = ScanInput();

        switch (choice1)
        {
        case 0:
        {
            // Printing a message on the end of the program
            printf("Exiting Thank you %c",2);
            exit(0);
        }
        break;

        case 1:
        {
            Static_List();

            // for printing the final linked list
            printf("\n\tHere is the final list\n\t");
            Print_List();

            // Free the allocated memory for each node
            Free_list();
        }
        break;

        case 2:
        {
            Dynamic_List();

            // for printing the final linked list
            printf("\n\tHere is the final list\n\t");
            Print_List();

            // Free the allocated memory for each node
            Free_list();
        }
        break;

        default:
        {
            printf("Invalid Option\nEnter form the option below\n");
        }
        break;
        }
    }
}