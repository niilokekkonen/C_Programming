typedef struct Node {
 int number;
 struct Node *next;
} Node;


void add_end(Node **phead, Node *item);
void add_start(Node **phead, Node *item);
int remove_node(Node **phead, int *pnum);
void print_linked(Node **phead);
void free_linked(Node **phead); 