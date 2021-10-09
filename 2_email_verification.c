// C program to check whether entered E-mail is valid or not
#include<stdio.h>
#include<string.h>
/*
must start with a letter (no numbers or symbols)
must be an @ somewhere in the string that is located BEFORE the dot
must be text after the @ symbol but BEFORE the dot
must be a dot
must be text after the dot
*/
int isvalid(char a[])
{
    int at_count =0;
    int dot_count=0;
    int l = strlen(a);
    if(l>320){
        return 0;
    }
    if(!((a[0]>='a' && a[0]<='z') ||(a[0]>='A' && a[0]<='Z') ))
            {
                return 0;
            }
    for(int i=0;i<l;i++)
    {
        if(a[i]=='@')
        {
            at_count++;
            if(at_count>1){
                return 0;
            }
             if(!((a[i+1]>='a' && a[i+1]<='z') ||(a[i+1]>='A' && a[i+1]<='Z') ))
            {
                return 0;
            }
        }
        if(a[i]=='.')
        {
            dot_count++;
            if(!((a[i+1]>='a' && a[i+1]<='z') ||(a[i+1]>='A' && a[i+1]<='Z') ))
            {
                return 0;
            }
        }
    }
    if(at_count==0)
    {
        return 0;
    }
    if(dot_count==0)
    {
        return 0;
    }

return 1;
}

int main()
{   
    char email[300];
    printf("Enter your E-mail\n");
    scanf("%s",email);

    if(isvalid(email)){
        printf("Email is Valid\n");
    }
    else{
        printf("Email is Invalid\n");
    }
    return 0;
}
