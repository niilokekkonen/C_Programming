void read_string(const char *prompt, char *str, int str_len); 
bool remove_lf(char *str);
bool check_str(char *str, char *comparison); 
void clear_ib(void);
int read_number(const char *prompt);
bool remove_lf(char *str);
bool parse_number(char *input, int *pnum); 
bool read_range(int low, int high, int *pnum);
int generate_num(int range);