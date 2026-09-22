#include <stdlib.h>
#include <stdio.h>
#include "task_16.h"
#include "C:\Users\niilo\Desktop\C-course\Programs\Assignments\useful_func\useful_funcs.h"

#include "C:\Users\niilo\Desktop\C-course\Programs\Assignments\useful_func\read_num.c"
#include "C:\Users\niilo\Desktop\C-course\Programs\Assignments\useful_func\read_string.c"
#define STR_LEN 20

int main(void) 
{
    const char *hello = "Enter a number\nOr\n'end' to stop\n";
    char *end_str = "end";
    char string_buf[STR_LEN];
    Node *head = NULL;
    Node **phead = &head;
    int num = 0;
    int *pnum = &num;
    int nc = 0; // node count
    bool end = false;
    while (!end) 
    {
        read_string(hello, string_buf,STR_LEN);
        end = check_str(string_buf, end_str);
        if (end) 
        {
            print_linked(phead);
            printf("Bye bye\n");
            free_linked(phead);
        }
        else 
        {
            bool parsed = parse_number(string_buf, pnum);
            if (!parsed) 
            {
                fprintf(stderr, "Input was not the right type (integer)\n");
            }
            else 
            {
                printf("Num: %d\nEnd: %d\n",num, end);
                Node *new_node = malloc(sizeof(Node));
                new_node->number = num;
                add_end(phead, new_node);
                nc++;
            }
        }
    }
    return 0;
}

// Adds a Node at the end of a linked list
void add_end(Node **phead, Node *item)
{
    if(*phead == NULL) 
    {   // empty list
        *phead = item;
    }
    else 
    {
        Node *curr = *phead;
        while (curr->next != NULL) 
    {
        curr = curr->next;
    }
        curr->next = item;
    }
    item->next = NULL;
}

// Adds a Node at the start of function
void add_start(Node **phead, Node *item)
{
    item->next = *phead;
    *phead = item;
}

// Removes a Node from a linked list with integer data
// Returns count of removed values
int remove_node(Node **phead, int *pnum)
{
    int count = 0;
    Node *curr = *phead;
    Node *prev = NULL;
    while (curr != NULL) 
    {
        if (curr->number == *pnum) 
        {
            if(prev == NULL) 
            {
            *phead = curr->next;
            free(curr);
            curr = *phead;
            }
            else 
            {
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
            }
            count++;    
            }
        else 
        {
        prev = curr;
        curr = curr->next;
        }
    }
    return count;
}

// Prints linked list
void print_linked(Node **phead) 
{
    Node *curr = *phead;
    while(curr != NULL) 
    {
        printf("Number %d\n", curr->number);
        curr = curr->next;
    }

}
// Frees a linked list from memory
// Takes a **pointer to the head of linked list
void free_linked(Node **phead) 
{
    Node *curr = *phead;
    while (curr != NULL) 
    {
        Node *next_node = curr->next;
        free(curr);
        curr = next_node;
    }
    *phead = NULL; 
} 