#define ARR_LEN 40


typedef struct menu_item_ {
 char name[50];
 double price;
} menu_item;

bool read_data(const char *filename, int *linecount, menu_item struct_arr[ARR_LEN]); 
bool split_string(char mark, char *str, char *number, int number_size); 
void print_struct(menu_item struct_arr[ARR_LEN], int *ec); 