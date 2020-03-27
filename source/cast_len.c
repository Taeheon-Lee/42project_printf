#include "../ft_printf.h"

long long int           cast_lli(t_printf f, long long int i)
{
    if (f.len == 1)
        return ((short)i);
    if (f.len == 2)
        return ((char)i);
    if (f.len == 3)
        return ((long int)i);
    if (f.con == 'p' || f.len == 4)
        return (i);
    return((int)i);
}

unsigned long long int  cast_ulli(t_printf f, unsigned long long i)
{
    if (f.con != 'U' &&f.len == 1)
        return ((unsigned short)i);
    if (f.con != 'U' &&f.len == 2)
        return ((unsigned char)i);
    if (f.con != 'U' &&f.len == 3)
        return ((unsigned long int)i);
    if (f.con == 'U' || f.len == 4)
        return (i);
    return((unsigned int)i);
}
