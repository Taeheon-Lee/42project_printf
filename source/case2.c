#include "../ft_printf.h"

t_printf    case_x(t_printf f, unsigned long long int x)
{
    char *temp;

    if (f.len == 6)
        f.len = 4;
    if (f.con == 'p')
    {
        f.len = 4;
        f.flag_hash = 1;
    }
    x = cast_ulli(f, x);
    if (f.pre == 0 && x == 0)
        f.val = ft_strnew(0);
    else
    {
        f = xtoa(f, x);
        if (f.pre != -1 && (int)ft_strlen(f.val) < f.pre)
        {
            temp = ft_strnew(f.pre - ft_strlen(f.val));
            temp = ft_memset(temp, '0', f.pre - ft_strlen(f.val));
            f.val = ft_strjoin(temp, f.val);
        }
    }
    return (f);
}

t_printf    case_f(t_printf f, double fl)
{
    if (fl < 0)
    {
        fl = -1 * fl;
        f.sign = 1;
    }
    if (f.pre == -1)
        f.pre = 6;
    f = ftoa(f, fl);
    return (f);
}

t_printf    case_lf(t_printf f, long double lf)
{
    if (lf < 0)
    {
        lf = -1 * lf;
        f.sign = 1;
    }
    if (f.pre == -1)
        f.pre = 6;
    f = ftoa(f, lf);
    return (f);
}
