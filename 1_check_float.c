// C PROGRAM TO CHECK WHETHER GIVEN NUMBER IS VALID FLOATING POINT NUMBER OR NOT

#include <stdio.h>
#include <string.h>
int check_float(char *s)
{
    int dot_count = 0;
    int e_count = 0;
    int i = 0;
    while (s[i] != '\0')
    {
        // Ignore spaces                    // '55.7 5 6'   >>>> valid
        if (s[i] == ' ')
        {
            i++;
            continue;
        }
        //if only one character is present than it must be digit      // '9' >>> valid // '+' invalid 
        if (strlen(s) == 1 && !(s[0] >= '0' && s[0] <= '9'))
        {
            return 0;
        }

        //  can not have two dot                  // '33.56.7' >>> invalid
        if (s[i] == '.')
        {
            dot_count++;
            if (dot_count > 1)
            {
                return 0;
            }
            // dot must occur earliar than 'e'   // '34.65e+4'  >>> valid '34e+5.7' >>> invalid
            if (e_count==1)
            {
                return 0;
            }
        }
        //  dot can not be at last               // '5.' >>>> invalid
        if (s[i] == '.' && s[i + 1] == '\0')
        {
            return 0;
        }
        // OPERETION ON e
        if (s[i] == 'e')
        {
            e_count++;
            // must have only one 'e'              // '5e+7e7' >>> invalid
            if (e_count > 1)
            {
                return 0;
            }
            // must have (+,- or (0-9) after 'e')         // '7.5e' >> invalid  ' 75e+7' >>> valid 
            if ((s[i + 1] != '+' && s[i + 1] != '-') && !(s[i + 1] >= '0' && s[i + 1] <= '9'))
            {
                return 0;
            }
            // digit must occur just before 'e'     // '+e' , 'e+7' >>>> invalid    // '5e+7' >>valid
            if (!(s[i - 1] >= '0' && s[i - 1] <= '9'))
            {
                return 0;
            }
        }

        // '+' and '-' must come before number           // '5.7+' >> invalid    '5.7+3' >>> valid
        if ((s[i] == '+' || s[i] == '-') && !(s[i + 1] >= '0' && s[i + 1] <= '9'))
        {
            return 0;
        }

        // only have { +,-,.,e,(0-9)}       // ' 56@7.8' >>> invalid  
        if (s[i] != '+' && s[i] != '-' && s[i] != '0' && s[i] != '1' && s[i] != '2' && s[i] != '3' && s[i] != '4' && s[i] != '5' && s[i] != '6' && s[i] != '7' && s[i] != '8' && s[i] != '9' && s[i] != '.' && s[i] != 'e')
        {
            return 0;
        }
        i++;
    }
    if(dot_count==0 && e_count==0)         // '6764' >>> invalid
    {
        return 0;
    }
    return 1;
}
int main()
{
    char str[100];
    scanf("%s", str);
    if (check_float(str) == 1)
    {
        printf("valid\n");
    }
    else
    {
        printf("invalid\n");
    }
    return 0;
}