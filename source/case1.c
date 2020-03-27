#include "../ft_printf.h"

t_printf    case_c(t_printf f, int c)
{
    if (f.con == 'Z')
    {
	f.flag_space = 0;
	f.flag_zero = 0;
    }
    f.val = ft_strnew(1);
    f.val[0] = c;
    return (f);
}

t_printf    case_s(t_printf f, char *s)
{
    int i;
    int length;

    if (s == NULL)
    {
        if (f.pre == -1)
            f.pre = 6;
        f.val = ft_strnew(f.pre);
        f.val = ft_strncpy(f.val, "(null)", f.pre);
    }
    else
    {
        length = ft_strlen(s) >= (size_t)f.pre ? (size_t)f.pre : ft_strlen(s);
        f.val = ft_strnew(length);
        i = 0;
        while (i < length)
        {
            f.val[i] = s[i];
            i++;
        }
    }
    return (f);
}

t_printf    case_d(t_printf f, long long int d)
{
    char    *temp;

    if (f.len == 6)
        f.len = 4;
    d = cast_lli(f, d);
    if (f.pre == 0 && d == 0)
        f.val = ft_strnew(0);
    else
    {
        if (d < 0)
        {
            d = -1 * d;
            f.sign = 1;
        }
        f = dtoa(f, d);
        if (f.pre != -1 && (int)ft_strlen(f.val) < f.pre)
        {
            temp = ft_strnew(f.pre - ft_strlen(f.val));
            temp = ft_memset(temp, '0', f.pre - ft_strlen(f.val));
            f.val = ft_strjoin(temp, f.val);
        }
    }
    return (f);
}

t_printf    case_u(t_printf f, unsigned long long int u)
{
    char    *temp;

    if (f.len == 6)
        f.len = 4;
    u = cast_ulli(f, u);
    if (f.pre == 0 && u == 0)
        f.val = ft_strnew(0);
    else
    {
        f = utoa(f, u);
        if (f.pre != -1 && (int)ft_strlen(f.val) < f.pre)
        {
            temp = ft_strnew(f.pre - ft_strlen(f.val));
            temp = ft_memset(temp, '0', f.pre - ft_strlen(f.val));
            f.val = ft_strjoin(temp, f.val);
        }
    }
    return (f);
}

t_printf case_o(t_printf f, unsigned long long int o)
{
    char    *temp;

    o = cast_ulli(f, o);
    if (f.pre == 0 && o == 0 && !f.flag_hash)
        f.val = ft_strnew(0);
    else
    {
        f = otoa(f, o);
        if (f.pre != -1 && (int)ft_strlen(f.val) < f.pre)
        {
            temp = ft_strnew(f.pre - ft_strlen(f.val));
            temp = ft_memset(temp, '0', f.pre - ft_strlen(f.val));
            f.val = ft_strjoin(temp, f.val);
        }
    }
    return (f);
}
