#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get a positive integer input
int scan()
{
    int value;
    char ch;

    while (scanf("%d", &value) != 1 || value <= 0)
    {
        printf("Invalid input. Please enter a positive integer: ");
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
    }

    return value;
}

// Function to get a integer input
int scan2()
{
    int value;
    char ch;

    while (scanf("%d", &value) != 1)
    {
        printf("Invalid input. Please enter a integer: ");
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
    }

    return value;
}

// Function to perform linear search in the array
void linear_search(int *array, int size)
{
    int value, i, counter;

    int location[size];

    printf("Enter the value you want to search in the array\n");
    value = scan2();

    printf("\tThe Array is\n\n\t");
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);

    counter = 0;
    for (i = 0; i < size; i++)
    {
        if (array[i] == value) // main code of linear search
        {
            location[counter] = i + 1;
            counter += 1;
        }
    }

    if (counter != 0)
    {
        printf("\n\nThe Search was successful and the %d is found %d times in the array\n", value, counter);
        printf("at locations: ");
        for (i = 0; i < counter - 1; i++)
            printf("%d, ", location[i]);
        printf("%d\n", location[counter - 1]);
    }
    else
        printf("\n\nSearch was unsuccessful and the element is not present in the array\n");
}

int main()
{
    int size, choice, inner_choice, i;
    int *array = NULL;

    printf("This a program of linear search in an array\n");

    while (1)
    {
        printf("Press 1 for making a new array\n");
        printf("Press 2 for searching again the same array\n");
        printf("Press 3 for exit\n");
        choice = scan();
        switch (choice)
        {
        case 1:
        {
            // Code for creating a new array
            printf("how many elements you want in the array\n");
            size = scan();

            // Memory allocation for the array
            array = (int *)malloc(sizeof(int) * size);

            // Check if memory allocation is successful
            if (array == NULL)
            {
                printf("Memory allocation failed. Exiting \n");
                printf("Thank you %c", 2);
                return 1;
            }

            while (1)
            {
                printf("Press 1 for auto generated array\n");
                printf("Press 2 for Manually entering array elements\n");

                inner_choice = scan();

                if (inner_choice == 1)
                {
                    // Auto-generate array elements
                    srand(time(NULL));
                    for (int i = 0; i < size; i++)
                        array[i] = rand() % 100;
                    break;
                }
                else if (inner_choice == 2)
                {
                    // Manually enter array elements
                    for (i = 0; i < size; i++)
                    {
                        printf("Enter element number %d\n", i + 1);
                        array[i] = scan2();
                    }
                    break;
                }
                else
                    printf("Invalid option. Enter again\n");
            }
            // Perform linear search in the array
            linear_search(array, size);
        }
        break;

        case 2:
        {
            // Code for searching the existing array
            // Check if the array has been created
            if (array == NULL)
                printf("You have not created any array. Create a array first\n");
            else
                linear_search(array, size); // Perform linear search in the existing array
        }
        break;

        case 3:
        {
            // Code for exiting the program
            printf("Exiting\nThank you %c", 2);
            // Free the allocated memory
            free(array);
            exit(0);
        }

        default:
            // Code for handling invalid choices
            printf("Invalid choice enter again\n");
            break;
        }
    }

    return 0;
}
