void *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t i = 0;
    while (i < n)
    {
        ((char*)dest)[i] = ((char*)src)[i];
        i++;
    }
    return dest;
}
{
    unsigned char *d = dest;
    const unsigned char *s = src;

    if (d == s || n == 0)
        return dest;
    if (d < s)
    {
        size_t i = 0;
        while (i < n)
        {
                d[i] = s[i];
            i++;
        }
    }
    else // Copy backwards
    {
        size_t i = n;
        while (i > 0)
        {
                d[i - 1] = s[i - 1];
            i--;
        }
    }
    return dest;
}
