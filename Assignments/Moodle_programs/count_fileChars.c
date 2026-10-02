#include <stdio.h>

int count_chars(const char *characters, FILE *file)
{
    if (characters == NULL || file == NULL)
    {
        return 0;
    }

    bool char_lookup[256] = { false };
    const char *p = characters;

    while (*p != '\0')
    {
        char_lookup[(unsigned char)*p] = true;
        p++;
    }

    int count = 0;
    char line[102];

    while (!feof(file))
    {
        if (fgets(line, sizeof(line), file) != NULL)
        {
            for (int i = 0; line[i] != '\0'; i++)
            {
                if (char_lookup[(unsigned char)line[i]])
                {
                    count++;
                }
            }
        }
    }

    return count;
}