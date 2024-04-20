#include <stdio.h>

void inplace_swape(int *x, int *y)
{
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

void reverse_array(int a[], int cnt)
{
    for (size_t first = 0, last = cnt - 1; first<last; first++, last--)
    {
        printf("first=%d, last=%d \n", first, last);
        inplace_swape(&a[first], &a[last]);
    }   
}

void output_array(int a[], int cnt)
{
    for (size_t i = 0; i < cnt; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int a = 5, b = 10;
    printf("a=%d, b=%d\n", a, b);    
    inplace_swape(&a, &b);
    printf("a=%d, b=%d\n", a, b); 

    int array_4[] = {1, 2, 3, 4};
    output_array(array_4, 4);
    reverse_array(array_4, 4);
    output_array(array_4, 4);

    int array_5[] = {1, 2, 3, 4, 5};
    output_array(array_5, 5);
    reverse_array(array_5, 5);
    output_array(array_5, 5);

    return 0;
}
