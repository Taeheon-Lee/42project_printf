#include "../ft_printf.h"

t_printf    set_len(t_printf f, const char *s)
{
    if (s[f.loc] == 'h')
    {
        if (s[f.loc + 1] == 'h')
        {
            f.len = f.len < 2 ? 2 : f.len;
            f.loc++;
        }
        else
            f.len = f.len < 1 ? 1 : f.len;
    }
    if (s[f.loc] == 'l')
    {
        if (s[f.loc + 1] == 'l')
        {
            f.len = f.len < 4 ? 4 : f.len;
            f.loc++;
        }
        else
            f.len = f.len < 3 ? 3 : f.len;
    }
    if (s[f.loc] == 'L')
        f.len = f.len < 5 ? 5 : f.len;
    if (s[f.loc] == 'z' || s[f.loc] == 'j')
        f.len = f.len < 6 ? 6 : f.len;
    return (f);
}

t_printf    set_pre(t_printf f, const char *s)
{
    int result;

    result = 0;
    f.loc++;
    while (s[f.loc] >= '0' && s[f.loc] <= '9')
    {
        result = result * 10 + s[f.loc] - '0';
        f.loc++;
    }
    f.pre = result;
    f.loc--;
    return (f);
}

t_printf    set_wid(t_printf f, const char *s)
{
    int result;

    result = 0;
    if (s[f.loc - 1] != 0 && s[f.loc - 1] == '.')
        return (f);
    while (s[f.loc] >= '0' && s[f.loc] <= '9')
    {
        result = result * 10 + s[f.loc] - '0';
        f.loc++;
    }
    f.wid = result;
    f.loc--;
    return (f);
}

t_printf    set_flag(t_printf f, char c)
{
    if (c == '-')
        f.flag_minus = 1;
    if (c == '+')
        f.flag_plus = 1;
    if (c == ' ')
        f.flag_space = 1;
    if (c == '0')
        f.flag_zero = 1;
    if (c == '#')
        f.flag_hash = 1;
    return (f);
}

char        set_con(char c)
{
    if (c == 'd' || c == 'D' || c == 'i' || c == 'u' || c == 'U' || 
    c == 'x' || c == 'X' || c == 'p' || c == 'o' || c == 'O' || 
    c == 'f' || c == 'F' || c == 'c' || c == 'C' || c == '%' || 
    c == 'Z' || c == 's' || c == 'S')
        return (c);
    return (0);
}
