#include "which.h"

void free_array(char **str)
{
    int i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}

int count_words(char *str, char *c)
{
    int words = 0;
    char *word;
    word = strtok(str, c);
    while (word)
    {
        words++;
        word = strtok(NULL, c);
    }
    return words;
}

char **split(char *str, char *c)
{
    int i = 0;
    char *word;
    char *copy;
    copy = strdup(str);
    int size = count_words(copy, c);
    free(copy);
    char **words = (char **) malloc(sizeof(char *) * (size + 1));
    if (!words)
        return (NULL);
    word = strtok(str, c);
    while (word)
    {
        words[i] = word;
        i++;
        word = strtok(NULL, c);
    }
    free(word);
    words[size] = NULL;
    return words;
}

char *join(char *s1, char *s2)
{
    int size = strlen(s1) + strlen(s2);
    char *str = malloc(sizeof(char) * (size + 1));
    if (!str)
        return NULL;
    int i = 0;
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    int j = 0;
    while (s2[j])
    {
        str[i + j] = s2[j];
        j++;
    }
    str[i + j] = '\0';
    return (str);
}
char *is_file_in_path(char *file, char **dirs)
{
    struct stat st;
    int i = 0;
    while (dirs[i])
    {
        char *full_path = join(dirs[i], "/");
        full_path = join(full_path, file);
        if (stat(full_path, &st) == 0)
            return full_path;
        free(full_path);
        i++;
    }
    return 0;
}