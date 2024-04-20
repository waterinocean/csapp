
#include <stdio.h>

int main()
{
    printf("(500*400) * (300*200): %ld \n", (500*400) * (300*200));
    printf("((500*400) * 300) * 200: %ld \n", ((500*400) * 300) * 200);

    int i = 53191;
    short s = i;
    int y = s;
    printf("integer:%d, short:%d, re-integer:%d\n", i, s, y);
    return 0;
}