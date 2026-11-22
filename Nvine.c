#include <stdio.h>
#include <string.h>

int main()
{
    int n, m, i, j;
    char text[100], pattern[50];

    printf("Enter text: ");
    scanf("%s", text);
    printf("\nEnter the pattern: ");
    scanf("%s", pattern);

    n = strlen(text);
    m = strlen(pattern);

    for (i = 0; i <= n - m; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (text[i + j] != pattern[j])
            {
                break;
            }
        }
        if (j == m)
        {
            printf("Pattern found at index %d\n", i);
        }
    }
    return 0;
}