#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//-----------------------------------------------------------------
void sayHii()
{
    printf("Hii there! from EasyC Team");
}
// -----------------------------------------------------------------------

//============================================================Array start============================================================

void insertAtBeginning_int(int arr[], int *size, int elem)
{
    for (int i = *size; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[0] = elem;
    (*size)++;
}
void insertAtBeginning_float(float arr[], int *size, float elem)
{

    for (int i = *size; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[0] = elem;
    (*size)++;
}
void insertAtBeginning_char(char str[], char ch)
{
    int len = strlen(str);

    for (int i = len; i >= 0; i--)
    {
        str[i + 1] = str[i];
    }

    str[0] = ch;
}

void insertAtEnd_int(int arr[], int *size, int elem)
{
    arr[*size] = elem;
    (*size)++;
}

void insertAtEnd_float(float arr[], int *size, float elem)
{
    arr[*size] = elem;
    (*size)++;
}

void insertAtEnd_char(char **str, char c)
{

    int newLength = strlen(*str) + 1;

    char *newStr = (char *)malloc(newLength * sizeof(char));
    if (newStr == NULL)
    {
        printf("Memory allocation failed. Exiting...\n");
        exit(1);
    }

    strcpy(newStr, *str);

    newStr[newLength - 1] = c;
    newStr[newLength] = '\0';

    free(*str);
    *str = newStr;
}

void insertAtIndex_int(int **arr, int *size, int elem, int index)
{

    if (index < 0 || index > *size)
    {
        printf("Invalid index. Cannot insert element.\n");
        return;
    }

    int newSize = *size + 1;
    int *newArr = (int *)malloc(newSize * sizeof(int));
    if (newArr == NULL)
    {
        printf("Memory allocation failed. Exiting...\n");
        exit(1);
    }

    for (int i = 0; i < index; i++)
    {
        newArr[i] = (*arr)[i];
    }

    newArr[index] = elem;

    for (int i = index; i < *size; i++)
    {
        newArr[i + 1] = (*arr)[i];
    }

    *size = newSize;
    free(*arr);
    *arr = newArr;
}

void insertAtIndex_float(float **arr, int *size, float elem, int index)
{
    if (index < 0 || index > *size)
    {
        printf("Invalid index. Cannot insert element.\n");
        return;
    }

    int newSize = *size + 1;
    float *newArr = (float *)malloc(newSize * sizeof(float));
    if (newArr == NULL)
    {
        printf("Memory allocation failed. Exiting...\n");
        exit(1);
    }

    for (int i = 0; i < index; i++)
    {
        newArr[i] = (*arr)[i];
    }

    newArr[index] = elem;

    for (int i = index; i < *size; i++)
    {
        newArr[i + 1] = (*arr)[i];
    }

    *size = newSize;
    free(*arr);
    *arr = newArr;
}

void insertAtIndex_char(char **str, char c, int index)
{

    int len = strlen(*str);
    if (index < 0 || index > len)
    {
        printf("Invalid index. Cannot insert character.\n");
        return;
    }

    char *newStr = (char *)malloc((len + 2) * sizeof(char));
    if (newStr == NULL)
    {
        printf("Memory allocation failed. Exiting...\n");
        exit(1);
    }

    strncpy(newStr, *str, index);

    newStr[index] = c;

    strcpy(newStr + index + 1, *str + index);

    free(*str);
    *str = newStr;
}

// ---------<Insertion />---------

// ---------<deletion>---------

void deleteFromBeginning_int(int arr[], int *size)
{
    if (*size <= 0)
    {
        printf("Array is empty. Cannot delete.\n");
        return;
    }

    for (int i = 0; i < *size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    (*size)--;
}
void deleteFromBeginning_float(float arr[], int *size)
{
    if (*size <= 0)
    {
        printf("Array is empty. Cannot delete.\n");
        return;
    }

    for (int i = 0; i < *size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    (*size)--;
}
void deleteFromBeginning_char(char *str)
{
    if (str[0] == '\0')
    {
        printf("String is empty. Cannot delete.\n");
        return;
    }

    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = str[i + 1];
    }
}

void deleteFromEnd_int(int arr[], int *size)
{
    if (*size <= 0)
    {
        printf("Array is empty. Cannot delete.\n");
        return;
    }

    (*size)--;
}
void deleteFromEnd_float(float arr[], int *size)
{
    if (*size <= 0)
    {
        printf("Array is empty. Cannot delete.\n");
        return;
    }

    (*size)--;
}
void deleteFromEnd_char(char *str)
{
    int len = strlen(str);
    if (len <= 0)
    {
        printf("String is empty. Cannot delete.\n");
        return;
    }

    str[len - 1] = '\0';
}

void deleteFromIndex_int(int arr[], int *size, int index)
{
    if (index < 0 || index >= *size)
    {
        printf("Invalid index. Cannot delete.\n");
        return;
    }

    for (int i = index; i < *size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    (*size)--;
}
void deleteFromIndex_float(float arr[], int *size, int index)
{
    if (index < 0 || index >= *size)
    {
        printf("Invalid index. Cannot delete.\n");
        return;
    }

    // Shift elements to the left
    for (int i = index; i < *size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    (*size)--;
}
void deleteFromIndex_char(char *str, int index)
{
    int len = strlen(str);
    if (index < 0 || index >= len)
    {
        printf("Invalid index. Cannot delete.\n");
        return;
    }

    for (int i = index; i < len; i++)
    {
        str[i] = str[i + 1];
    }
}

// ---------<deletion />---------

// ---------<searching>---------

int search_int_fn(int arr[], int low, int high, int x)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            return search_int_fn(arr, mid + 1, high, x);
        else
            return search_int_fn(arr, low, mid - 1, x);
    }

    return -1;
}

int search_int(int arr[], int valueToFind, int size)
{
    int value = search_int_fn(arr, 0, size - 1, valueToFind);
    return value;
}

int search_float_fn(float arr[], int low, int high, float x)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            return search_float_fn(arr, mid + 1, high, x);
        else
            return search_float_fn(arr, low, mid - 1, x);
    }

    return -1;
}

int search_float(float arr[], float valueToFind, int size)
{
    int value = search_float_fn(arr, 0, size - 1, valueToFind);
    return value;
}

int search_char(char arr[], char target, int size)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        // Check if the target is present at mid
        if (arr[mid] == target)
        {
            return mid;
        }

        // If target is greater, ignore the left half
        if (arr[mid] < target)
        {
            left = mid + 1;
        }
        // If target is smaller, ignore the right half
        else
        {
            right = mid - 1;
        }
    }

    // Target is not present in array
    return -1;
}

// ---------<searching />---------

// ---------<print>---------

void printArr_int(int arr[], int size)
{
    printf("Array elements: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printArr_float(float arr[], int size)
{
    printf("Array elements: ");
    for (int i = 0; i < size; i++)
    {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}
void printArr_char(char arr[], int size)
{
    printf("Array elements: ");
    for (int i = 0; i < size; i++)
    {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

// ---------<print />---------

// ---------<sorting>---------

// int------------
void swap_int(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition_int(int arr[], int low, int high)
{
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1;       // Index of smaller element

    for (int j = low; j < high; j++)
    {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            i++;
            swap_int(&arr[i], &arr[j]);
        }
    }
    swap_int(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort_int(int arr[], int low, int high)
{
    if (low < high)
    {
        // Partition the array into two parts
        int pi = partition_int(arr, low, high);

        // Recursively sort the two parts
        quicksort_int(arr, low, pi - 1);
        quicksort_int(arr, pi + 1, high);
    }
}

void sort_int(int arr[], int size)
{
    quicksort_int(arr, 0, size - 1);
}
// int------------

// float---------
void swap_float(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

int partition_float(float arr[], int low, int high)
{
    float pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1;         // Index of smaller element

    for (int j = low; j < high; j++)
    {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            i++;
            swap_float(&arr[i], &arr[j]);
        }
    }
    swap_float(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort_float(float arr[], int low, int high)
{
    if (low < high)
    {
        // Partition the array into two parts
        int pi = partition_float(arr, low, high);

        // Recursively sort the two parts
        quicksort_float(arr, low, pi - 1);
        quicksort_float(arr, pi + 1, high);
    }
}

void sort_float(float arr[], int size)
{
    quicksort_float(arr, 0, size - 1);
}
// float---------

// sort----------
void swap_char(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

int partition_char(char arr[], int low, int high)
{
    char pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1;        // Index of smaller element

    for (int j = low; j < high; j++)
    {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            i++;
            swap_char(&arr[i], &arr[j]);
        }
    }
    swap_char(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort_char(char arr[], int low, int high)
{
    if (low < high)
    {
        // Partition the array into two parts
        int pi = partition_char(arr, low, high);

        // Recursively sort the two parts
        quicksort_char(arr, low, pi - 1);
        quicksort_char(arr, pi + 1, high);
    }
}

void sort_char(char arr[], int size)
{
    quicksort_char(arr, 0, size - 1);
}
// sort----------

// ---------<sorting />---------

//============================================================Array End============================================================

//============================================================Stack Start============================================================

//-----------<Linked List based>-----------------

// Define the structure of a node
typedef struct StackNode_LLR
{
    int data;
    struct StackNode_LLR *next;
} StackNode_LLR;

// Define the structure of the stack
typedef struct
{
    StackNode_LLR *top;
} Stack_LLR;

// Function to create a new node
StackNode_LLR *createNode_LLR(int data)
{
    StackNode_LLR *newNode = (StackNode_LLR *)malloc(sizeof(StackNode_LLR));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the stack
Stack_LLR *createStack_LLR()
{
    Stack_LLR *stack = (Stack_LLR *)malloc(sizeof(Stack_LLR));
    if (stack == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    stack->top = NULL;
    return stack;
}

// Function to check if the stack is empty
int isEmpty_LLR(Stack_LLR *stack)
{
    return (stack->top == NULL);
}

// Function to push an element onto the stack
void push_LLR(Stack_LLR *stack, int data)
{
    StackNode_LLR *newNode = createNode_LLR(data);
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Pushed: %d\n", data);
}

// Function to pop an element from the stack
int pop_LLR(Stack_LLR *stack)
{
    if (isEmpty_LLR(stack))
    {
        printf("Stack is empty\n");
        exit(1);
    }
    int data = stack->top->data;
    StackNode_LLR *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    printf("Popped: %d\n", data);
    return data;
}

// Function to peek at the top element of the stack
int peek_LLR(Stack_LLR *stack)
{
    if (isEmpty_LLR(stack))
    {
        printf("Stack is empty\n");
        exit(1);
    }
    return stack->top->data;
}

// Function to print the stack
void printStack_LLR(Stack_LLR *stack)
{
    if (isEmpty_LLR(stack))
    {
        printf("Stack is empty\n");
        return;
    }
    StackNode_LLR *current = stack->top;
    printf("Stack elements: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
//-----------<Linked List based />-----------------

//-----------<array based>-----------------

// Define the structure of the stack
typedef struct
{
    int top;
    int *array;
    int size;
} Stack_AR;

// Function to initialize the stack
Stack_AR *createStack_AR(int size)
{
    Stack_AR *stack = (Stack_AR *)malloc(sizeof(Stack_AR));
    if (stack == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    stack->top = -1;                                  // Initialize top to -1 (empty stack)
    stack->size = size;                               // Set the size of the stack
    stack->array = (int *)malloc(size * sizeof(int)); // Allocate memory for the stack array
    if (stack->array == NULL)
    {
        printf("Memory allocation failed\n");
        free(stack);
        exit(1);
    }
    return stack;
}

// Function to check if the stack is empty
int isEmpty_AR(Stack_AR *stack)
{
    return (stack->top == -1);
}

// Function to check if the stack is full
int isFull_AR(Stack_AR *stack)
{
    return (stack->top == stack->size - 1);
}

// Function to push an element onto the stack
void push_AR(Stack_AR *stack, int data)
{
    if (isFull_AR(stack))
    {
        printf("Stack overflow\n");
        exit(1);
    }
    stack->array[++stack->top] = data;
    printf("Pushed: %d\n", data);
}

// Function to pop an element from the stack
int pop_AR(Stack_AR *stack)
{
    if (isEmpty_AR(stack))
    {
        printf("Stack underflow\n");
        exit(1);
    }
    int data = stack->array[stack->top--];
    printf("Popped: %d\n", data);
    return data;
}

// Function to peek at the top element of the stack
int peek_AR(Stack_AR *stack)
{
    if (isEmpty_AR(stack))
    {
        printf("Stack is empty\n");
        exit(1);
    }
    return stack->array[stack->top];
}

// Function to print the stack
void printStack_AR(Stack_AR *stack)
{
    if (isEmpty_AR(stack))
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++)
    {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

//-----------<array based />-----------------

//============================================================Stack End============================================================

//============================================================Linkedlist Start============================================================

typedef struct LinkedList_S
{
    int data;
    struct LinkedList_S *next;
} LinkedList_S;

LinkedList_S *createNode_S(int data)
{
    LinkedList_S *newNode = (LinkedList_S *)malloc(sizeof(LinkedList_S));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning_S(LinkedList_S **head_ref, int new_data)
{
    LinkedList_S *new_node = createNode_S(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void insertAtEnd_S(LinkedList_S **head_ref, int new_data)
{
    LinkedList_S *new_node = createNode_S(new_data);

    if (*head_ref == NULL)
    {
        (*head_ref) = new_node;
        return;
    }

    LinkedList_S *last = *head_ref;
    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;
}

void insertAtIndex_S(LinkedList_S **head_ref, int data, int index)
{
    if (index < 0)
    {
        printf("Invalid index\n");
        return;
    }

    LinkedList_S *new_node = createNode_S(data);

    if (index == 0)
    {
        insertAtBeginning_S(head_ref, data);
        return;
    }

    LinkedList_S *temp = *head_ref;
    for (int i = 0; i < index - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Invalid index\n");
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

void deleteAtBeginning_S(LinkedList_S **head_ref)
{
    if (*head_ref == NULL)
    {
        printf("List is empty\n");
        return;
    }

    LinkedList_S *temp = *head_ref;

    (*head_ref) = temp->next;

    free(temp);
}

void deleteAtEnd_S(LinkedList_S **head_ref)
{
    if (*head_ref == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if ((*head_ref)->next == NULL)
    {
        free(*head_ref);
        *head_ref = NULL;
        return;
    }

    LinkedList_S *temp = *head_ref;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next);

    temp->next = NULL;
}

bool search_S(LinkedList_S *head, int key)
{
    LinkedList_S *current = head;
    while (current != NULL)
    {
        if (current->data == key)
        {
            return true; // Element found
        }
        current = current->next;
    }
    return false; // Element not found
}

LinkedList_S *initializeList_S()
{
    return NULL;
}

void printList_S(LinkedList_S *head)
{
    if (head != NULL)
    {
        printf("Head: %d\n", head->data);
    }

    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int getLength_S(LinkedList_S *head)
{
    int count = 0;
    LinkedList_S *current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

typedef struct LinkedList_D
{
    int data;
    struct LinkedList_D *next;
    struct LinkedList_D *prev;
} LinkedList_D;

LinkedList_D *createNode_D(int data)
{
    LinkedList_D *newNode = (LinkedList_D *)malloc(sizeof(LinkedList_D));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtBeginning_D(LinkedList_D **head_ref, int new_data)
{
    LinkedList_D *new_node = createNode_D(new_data);
    new_node->next = (*head_ref);
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}

void insertAtEnd_D(LinkedList_D **head_ref, int new_data)
{
    LinkedList_D *new_node = createNode_D(new_data);
    LinkedList_D *last = *head_ref;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    new_node->prev = last;
}

void insertAtIndex_D(LinkedList_D **head_ref, int data, int index)
{
    if (index < 0)
    {
        printf("Invalid index\n");
        return;
    }
    LinkedList_D *new_node = createNode_D(data);
    if (index == 0)
    {
        insertAtBeginning_D(head_ref, data);
        return;
    }
    LinkedList_D *temp = *head_ref;
    for (int i = 0; temp != NULL && i < index - 1; i++)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("Invalid index\n");
        return;
    }
    new_node->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = new_node;
    temp->next = new_node;
    new_node->prev = temp;
}

void deleteAtBeginning_D(LinkedList_D **head_ref)
{
    if (*head_ref == NULL)
    {
        printf("List is empty\n");
        return;
    }
    LinkedList_D *temp = *head_ref;
    *head_ref = temp->next;
    if (*head_ref != NULL)
        (*head_ref)->prev = NULL;
    free(temp);
}

void deleteAtEnd_D(LinkedList_D **head_ref)
{
    if (*head_ref == NULL)
    {
        printf("List is empty\n");
        return;
    }
    LinkedList_D *temp = *head_ref;
    while (temp->next != NULL)
        temp = temp->next;
    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        *head_ref = NULL;
    free(temp);
}

void deleteAtIndex_D(LinkedList_D **head_ref, int index)
{
    if (*head_ref == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (index < 0)
    {
        printf("Invalid index\n");
        return;
    }
    if (index == 0)
    {
        deleteAtBeginning_D(head_ref);
        return;
    }
    LinkedList_D *current = *head_ref;
    int i = 0;
    while (current != NULL && i < index)
    {
        current = current->next;
        i++;
    }
    if (current == NULL)
    {
        printf("Invalid index\n");
        return;
    }
    if (current->next != NULL)
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    else
    {
        current->prev->next = NULL;
    }
    free(current);
}

bool search_D(LinkedList_D *head, int key)
{
    LinkedList_D *current = head;
    while (current != NULL)
    {
        if (current->data == key)
            return true; // Element found
        current = current->next;
    }
    return false; // Element not found
}

LinkedList_D *initializeList_D()
{
    return NULL;
}

void printList_D(LinkedList_D *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

typedef struct LinkedList_C
{
    int data;
    struct LinkedList_C *next;
} LinkedList_C;

LinkedList_C *createNode_C(int data)
{
    LinkedList_C *newNode = (LinkedList_C *)malloc(sizeof(LinkedList_C));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning_C(LinkedList_C **head_ref, int new_data)
{
    LinkedList_C *new_node = createNode_C(new_data);
    if (*head_ref == NULL)
    {
        new_node->next = new_node; // Point to itself for circularity
    }
    else
    {
        new_node->next = (*head_ref)->next;
    }
    (*head_ref) = new_node;
}

void insertAtEnd_C(LinkedList_C **head_ref, int new_data)
{
    LinkedList_C *new_node = createNode_C(new_data);
    if (*head_ref == NULL)
    {
        new_node->next = new_node; // Point to itself for circularity
        (*head_ref) = new_node;
    }
    else
    {
        new_node->next = (*head_ref)->next;
        (*head_ref)->next = new_node;
        (*head_ref) = new_node;
    }
}

void insertAtIndex_C(LinkedList_C **head_ref, int data, int index)
{
    if (index < 0)
    {
        printf("Invalid index\n");
        return;
    }
    if (index == 0)
    {
        insertAtBeginning_C(head_ref, data);
        return;
    }
    LinkedList_C *new_node = createNode_C(data);
    LinkedList_C *temp = *head_ref;
    for (int i = 0; i < index - 1 && temp->next != (*head_ref); i++)
    {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void deleteAtBeginning_C(LinkedList_C **head_ref)
{
    if (*head_ref == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if ((*head_ref)->next == *head_ref)
    {
        free(*head_ref);
        *head_ref = NULL;
        return;
    }
    LinkedList_C *temp = (*head_ref)->next;
    (*head_ref)->next = temp->next;
    free(temp);
}

void deleteAtEnd_C(LinkedList_C **head_ref)
{
    if (*head_ref == NULL)
    {
        printf("List is empty\n");
        return;
    }
    LinkedList_C *current = *head_ref;
    LinkedList_C *prev = NULL;
    while (current->next != (*head_ref))
    {
        prev = current;
        current = current->next;
    }
    if (prev == NULL)
    {
        free(current);
        *head_ref = NULL;
    }
    else
    {
        prev->next = (*head_ref);
        free(current);
    }
}

bool search_C(LinkedList_C *head, int key)
{
    LinkedList_C *current = head;
    do
    {
        if (current->data == key)
            return true; // Element found
        current = current->next;
    } while (current != head);
    return false; // Element not found
}

LinkedList_C *initializeList_C()
{
    return NULL;
}

void printList_C(LinkedList_C *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    LinkedList_C *current = head;
    do
    {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

//============================================================Linkedlist End============================================================

//============================================================queue Start============================================================
// Define the structure of a node
typedef struct Node_LLR {
    int data;
    struct Node_LLR* next;
} Node_LLR;

// Define the structure of the queue
typedef struct {
    Node_LLR* front;
    Node_LLR* rear;
} Queue_LLR;

// Function to create a new node
Node_LLR* createNodeQueue(int data) {
    Node_LLR* newNode = (Node_LLR*)malloc(sizeof(Node_LLR));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the queue
Queue_LLR* createQueue_LLR() {
    Queue_LLR* queue = (Queue_LLR*)malloc(sizeof(Queue_LLR));
    if (queue == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isQueueEmpty_LLR(Queue_LLR* queue) {
    return (queue->front == NULL);
}

// Function to add an element to the queue
void enqueue_LLR(Queue_LLR* queue, int data) {
    Node_LLR* newNode = createNodeQueue(data);
    if (isQueueEmpty_LLR(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Enqueued: %d\n", data);
}

// Function to remove an element from the queue
int dequeue_LLR(Queue_LLR* queue) {
    if (isQueueEmpty_LLR(queue)) {
        printf("Queue is empty\n");
        exit(1);
    }
    int data = queue->front->data;
    Node_LLR* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    printf("Dequeued: %d\n", data);
    return data;
}

// Function to get the first element of the queue
int firstElement_LLR(Queue_LLR* queue) {
    if (isQueueEmpty_LLR(queue)) {
        printf("Queue is empty\n");
        exit(1);
    }
    return queue->front->data;
}

// Function to print the queue
void printQueue_LLR(Queue_LLR* queue) {
    if (isQueueEmpty_LLR(queue)) {
        printf("Queue is empty\n");
        return;
    }
    Node_LLR* current = queue->front;
    printf("Queue elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

//----------<array based queue/>------------
typedef struct {
    int front, rear, size;
    unsigned capacity;
    int* array;
} Queue_AR;

// Function to create a queue of given capacity
Queue_AR* createQueue_AR(unsigned capacity) {
    Queue_AR* queue = (Queue_AR*) malloc(sizeof(Queue_AR));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1; // This is important, see the enqueue
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

// Queue is full when size becomes equal to the capacity
int isQueueFull_AR(Queue_AR* queue) {
    return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
int isQueueEmpty_AR(Queue_AR* queue) {
    return (queue->size == 0);
}

// Function to add an item to the queue
void enqueue_AR(Queue_AR* queue, int item) {
    if (isQueueFull_AR(queue)) {
        printf("Queue is full\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("Enqueued: %d\n", item);
}

// Function to remove an item from queue
int dequeue_AR(Queue_AR* queue) {
    if (isQueueEmpty_AR(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    printf("Dequeued: %d\n", item);
    return item;
}

// Function to get front of queue
int front_AR(Queue_AR* queue) {
    if (isQueueEmpty_AR(queue)) {
        return -1;
    }
    return queue->array[queue->front];
}

// Function to print the queue
void printQueue_AR(Queue_AR* queue) {
    if (isQueueEmpty_AR(queue)) {
        printf("Queue is empty\n");
        return;
    }
    int i;
    for (i = 0; i < queue->size; i++) {
        int index = (queue->front + i) % queue->capacity;
        printf("%d ", queue->array[index]);
    }
    printf("\n");
}
//----------<array based queue/>------------
//============================================================queue End============================================================
