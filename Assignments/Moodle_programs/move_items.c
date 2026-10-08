#include <stdio.h>
#define MAX_LEN 32 
#define TARGET_SIZE 4

typedef struct student 
{ 
    char name[MAX_LEN]; 
    int group; 
    int id; 
    struct student *next; 
} 
student;


int move(student **source, int group, student **target);

// Moves items from one linked list to another
// returns number of moved elements
int move(student **source, int group, student **target) 
{   
    int count = 0;
    student **ppsource = source;
    // While head pointer is not null
    while(*ppsource != NULL) 
    {
        // If head.group == group
        if((*ppsource)->group == group) 
        {   
            // saving the removable target
            student *node = *ppsource;
            // Moving source to the next in list
            *ppsource = node->next;
            
            // adding target to the beginning of target list
            node->next = *target;
            *target = node;
            count++;
        }
        else 
        {
            // If the group is not matched
            // Setting the head address to the next element of head
            ppsource = &(*ppsource)->next;
        }
    }
    return count;
}
    

