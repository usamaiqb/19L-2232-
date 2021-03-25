
#include<stdio.h>
// #include<fstream>

int length(char str[])
{
    int count = 0;
    while (str[count]!=0)
        count++;
    return count;
}

void reverse(char str[], int len)
{
    char word[30];
    for (int index = 0; index < len; ++index)
    {
        int count = 0;
        for (int i = index; str[i] != ' ' && i < len; ++i)
            count++;
        for (int i = 0; i < count; ++i)
        {
            if (str[index+count - i - 1] != 'a' && str[index+count - i - 1] != 'e' && str[index+count - i - 1] != 'i' && str[index+count - i - 1] != 'o' && str[index+count - i - 1] != 'u'){
                word[index+i] = str[len - i - 1];
                count++;
            }
        }

        int j = 0;
        for (int i = 0; j < count; ++i)
        {
            if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u'){
                str[i] = word[i];
                ++j;
            }
        }
        index = index + count++;
    }
}

int main()
{
    FILE* fp;
    fp = fopen("b.txt", "r");
    char str[100];
    fgets(str, 100, fp);
    fclose(fp);

    int len = length(str);
    str[len] = 0;
    reverse(str, len);

    FILE* fp1;
    fp1 = fopen("b.txt", "w");
    fprintf(fp1, "%s", str);
    fclose(fp1);
    

    return 0;
}