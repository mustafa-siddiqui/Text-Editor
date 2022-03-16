/** @file   stack.c
 *  @brief  An implementation of a stack of characters. The data
 *          structure follows the LIFO (Last In First Out) principle. 
 *          This file contains function declarations related to the
 *          stack data structure.
 *  @author Mustafa Siddiqui
 *  @date   01/13/2020
 */

#ifndef _STACK_H_
#define _STACK_H_

struct stackNode {
    char letter;
    struct stackNode* next;
} typedef Node;

/*
    Add a value to the top of stack.
    Returns pointer to top of stack.
*/
Node* push(Node* top, char letter);

/*
    Peek letter at the top of the stack.
    Returns value (char) of the top node of the stack.
*/
char peek(Node* top);

/*
    Delete a value from the top of stack.
    Returns pointer to top of stack.
*/
Node* pop(Node* top);

/*
    Search a value in the stack.
    Returns the position/index of the value in the stack if
    value is present in the stack and '-1' if value searched
    is not in stack.
*/
int search(Node* top, char letterToSearch);

/*
    Print all elements in the stack.
*/
void printStack(Node* top);

/*
    Free up allocated memory for all elements in the stack.
*/
void freeStack(Node* top);

#endif /* _STACK_H_ */
