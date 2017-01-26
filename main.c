#include <stdio.h>
#include <stdlib.h>

void swap(int* x,int* y);

int main(void)
{

    // initialize
    int r, c;
    scanf("%d%d", &r, &c);
    int *matrix;
    matrix = (int*)malloc(r * c * sizeof(int));
    for (int i = 0; i < r * c; i++)
    {
        matrix[i] = i+1;
    }
          
    // print original
    for (int i = 0; i < r * c; i++)
    {
        if (i % c == 0)
        {
            printf("\n");
        }
        printf("%d\t", matrix[i]);
    }
    printf("\n");

    // evaluate
    int x;
    for (int i = 0; i < r * c; i++)
    {
        x = (i + (r * c - 1) * (i % r)) / r;
        while (x < i)
        {
            x = (x + (r * c - 1) * (x % r)) / r;
        }
        swap(&matrix[i], &matrix[x]);
    }
     
    // alternative
    /*
    int x;
    for (int i = 0; i < r * c - 1; i++)
    {
        x = (i * c) % (r * c - 1);
        while (x < i)
        {
            x = (x * c) % (r * c - 1);
        }
        swap(&matrix[i], &matrix[x]);
    }
    */

    // print transpose
    for (int i = 0; i < r * c; i++)
    {
        if (i % r == 0)
        {
            printf("\n");
        }
        printf("%d\t", matrix[i]);
    }
    printf("\n");

    system("PAUSE");
    return 0;
}

void swap(int* x, int* y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
