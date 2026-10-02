#define LINE_LEN 100
bool read_text(const char *filename, int *linecount,char (*str_arr)[LINE_LEN]);
bool nmea_checksum(char(*str_arr)[LINE_LEN], int linecount);
