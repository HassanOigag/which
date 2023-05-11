#include "which.h"

int main(int argc, char **argv)
{
    char *path;
    if (argc == 1)
    {
        printf("Usage: ./_which file1 file 2 . . .");
        return (1);
    }
    path = getenv("PATH");
    char **dirs = split(path, ":");
    int i = 1;
    while (argv[i])
    {
        char *file = is_file_in_path(argv[i], dirs);
        if (!file)
            printf("%s not found\n", argv[i]);
        else
            printf("%s\n", file);
        free(file);
        i++;
    }
    free(dirs);
    return 0;
}