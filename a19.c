#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Author Name: Danny Ngo
//Date Created: 11/14/2024
//Purpose: This program should be able to print a list with length of range 25-75 numbers that are
//ranging from 0-100. It should then display the sum of each number in the list, how many elements are
//in each list, and the average of the list.

//The class Node, or the structure of the Node, with next being the pointer to the next address.
typedef struct Node {
    int data;
    struct Node* next;
} Node;

//The function createNode allows a new node to be produced after the last node.
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//The insertEnd function to insert a new node at the end of the list
void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

//The function sum allows for the calculation of each of the sum of the elements in the list
int sum(Node* head) {
    int total = 0;
    Node* temp = head;
    while (temp != NULL) {
        total += temp->data;
        temp = temp->next;
    }
    return total;
}

//The count function to count the number of nodes in the list
int count(Node* head) {
    int counter = 0;
    Node* temp = head;
    while (temp != NULL) {
        counter++;
        temp = temp->next;
    }
    return counter;
}

//The displayList that shows the list of random numbers that are projected because of
//the seed time.
void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(", ");
        }
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    Node* head = NULL;
    int numNodes;

    //Uses time as the seed for the random number generator
    srand(time(NULL));

    //Generates a random number between 25 and 75 for the number of nodes
    numNodes = 25 + rand() % 51;

    //Inserts random integers into the linked list
    for (int i = 0; i < numNodes; i++) {
        int randomValue = rand() % 101;
        insertEnd(&head, randomValue);
    }

    //Displays the list with the function
    printf("The list is: ");
    displayList(head);

    //Calculates the sum and count of the elements with their respective functions
    int totalSum = sum(head);
    int totalCount = count(head);

    //Calculates the average
    double average = totalCount > 0 ? (double)totalSum / totalCount : 0.0;

    //Output the results
    printf("Sum = %d\n", totalSum);
    printf("Count = %d\n", totalCount);
    printf("Average = %.2f\n", average);

    return 0;
}