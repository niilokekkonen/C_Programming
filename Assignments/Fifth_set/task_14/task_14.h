#define LINE_LEN 80

bool read_text(const char *filename, int *linecount,char (*str_arr)[LINE_LEN]); 
bool write_text(const char *filename, int *linecount, char (*str_arr)[LINE_LEN]);
void str_to_upper(char *str);