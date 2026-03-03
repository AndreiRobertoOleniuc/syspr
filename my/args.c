#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("Number of arguments: %d\n", argc);
    for (int i = 0; i < argc; i++)
    {
        if(i != 0) {
            for (char *p = argv[i]; *p != '\0'; p++) {
                if (*p < 'a' || *p > 'z') {
                    printf("Invalid argument: %s\n", argv[i]);
                    return 1;
                }
            }
        }
        printf("Argument %d: %s\n", i, argv[i]);
    }
    return 0;
}