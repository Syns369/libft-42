#include"libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
    char    *tmp;
    tmp = malloc(sizeof(char) * n);
    ft_memcpy(tmp, src, n);
    ft_memcpy(dest, tmp, n);
    free(tmp);
    return (dest); 
}
