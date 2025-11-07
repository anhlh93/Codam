#include <stdio.h>
#include <string.h>

// #1: Broken version
void *ft_memcpy_v1(void *dest, const void *src, size_t n)
{
    while (n >= 0)
    {
        ((char*)dest)[n] = ((char*)src)[n];
        n--;
    }
    return dest;
}

// #2: Correct version
void *ft_memcpy_v2(void *dest, const void *src, size_t n)
{
    size_t i = 0;
    while (i < n)
    {
        ((char*)dest)[i] = ((char*)src)[i];
        i++;
    }
    return dest;
}
// #3: My version
void *ft_memcpy_v3(void *dest, const void *src, size_t n)
{
    unsigned char *d = dest;
    const unsigned char *s = src;

    size_t i = 0;
    while (i < n)
    {
        d[i] = s[i];
        i++;
    }
    return dest; 
}



int main(void)
{
    char src[] = "HELLO";
    // char dest1[10] = {0};
    char dest2[10] = {0};
    char dest3[10] = {0};
    
    printf("Original: %s\n", src);
    
    // ft_memcpy_v1(dest1, src, 5);
    // printf("V1 Result: ");
    // for (int i = 0; i < 5; i++)
    //     printf("%c", dest1[i] ? dest1[i] : '?');
    printf("\n");
    
    ft_memcpy_v2(dest2, src, 5);
    printf("V2 Result: %s\n", dest2);

    ft_memcpy_v3(dest3, src, 5);
    printf("V3 Result: %s\n", dest3);
    
    return (0);
}