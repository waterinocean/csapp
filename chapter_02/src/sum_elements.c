
#include <stdio.h>

float sum_elements(float a[], unsigned length)
{
    float result = 0.0;
    for (int i = 0; i < length; i++)
    {
        result += a[i];
    }
    return result;
}

int main()
{
    float a[3] = {1.0, 2.0, 3.0};
    printf("sum: %f\n", sum_elements(a, 0));
    return 0;
}
