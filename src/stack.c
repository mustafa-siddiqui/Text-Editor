/** @file   stack.c
 *  @brief  An implementation of a stack of characters in C. The data
 *          structure follows the LIFO (Last In First Out) principle.
 *          Definitions of functions defined in stack.h
 *  @author Mustafa Siddiqui
 *  @date   01/13/2020
 */

#include <stdio.h>
#include <stdlib.h>
//-//
#include "../inc/stack.h"

/* Push node to top of stack */
Node* push(Node* top, char letter) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->letter = letter;
    newNode->next = top;

    return newNode;
}

/* Return node value from top of stack without deleting it. */
char peak(Node* top) {
    return top->letter;
}   

/* Delete node from top of stack. */
Node* pop(Node* top) {
    Node* temp = top;
    Node* newTop = temp->next;

    // free node
    free(temp);

    return newTop;
}

/* Search value in stack. */
int search(Node* top, char letterToSearch) {
    Node* currentNode = top;

    // iterate through stack until value is found or till end of list while
    // keeping track of how many iterations made
    int index = 0;
    while (currentNode->letter != letterToSearch) {
        currentNode = currentNode->next;
        index++;

        if (currentNode == NULL) {
            // value not found, return -1
            return -1;
        }
    }

    return index;
}

/* Print elements stored in stack. */
void printStack(Node* top) {
    Node* currentNode = top;

    // iterate through stack
    while (currentNode->next != NULL) {
        printf("%c", currentNode->letter);
        currentNode = currentNode->next;
    }

    // print last element in stack
    printf("%c\n", currentNode->letter);
}

/* Free up allocated memory. */
void freeStack(Node* top) {
    Node* currentNode = top;
    Node* previousNode = NULL;

    // iterate through stack and free up nodes as we go
    while (currentNode != NULL) {
        previousNode = currentNode;
        currentNode = currentNode->next;

        free(previousNode);
    }
}
