#include <map>
#include <iostream>
#include <solstd.h>
#include <stdarg.h>

std::string fstring(const char *fmt, ...)
{
    va_list vl;
    int i = 0;
    va_start(vl, fmt);

    std::string cpy(fmt);

    std::map<std::string, int> mapping;
    mapping["%s"] = F_STR;
    mapping["%d"] = F_INT32;
    mapping["%f"] = F_DOUB;

    int ovrs = 0;
    while (i < cpy.length())
    {
        if (cpy[i] != '%')
        {
            i++;
            continue;
        }
        std::string p_c = cpy.substr(i, 2);
        std::string s;

        switch (mapping[p_c])
        {
            case F_STR:
                s = va_arg(vl, char*);
                break;
            case F_INT32:
                s = std::to_string(va_arg(vl, int));
                break;
            case F_DOUB:
                s = std::to_string(va_arg(vl, double));
                break;
            default: 
                std::cout << "continue" << std::endl;
                i++;
                continue;
        }
        
        cpy.replace(i, 2, s);
        i += ovrs + 1;
    }
    va_end(vl);
    return cpy;
}