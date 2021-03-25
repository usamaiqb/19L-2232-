
#include<stdio.h>
// #include<fstream>

int fsubstr(char str[], char substr[])
{
    int i = 0;
    int count = 0;
    while(str[i]!=0)
    {
        if(str[i] == substr[0])
        {
            int j = 1;
            while (str[i+j] == substr[j] && str[i+j] != 0 && substr[j] !=0)
                j++;
            if (substr[j] == 0)
                count++;
        }
        ++i;
    }
    return count;
}

int main(int argc, char *argv[])
{
    char filename[30];
    char substr[30];
    // printf("Enter Filename(including extension): ");
    // fgets(filename, sizeof(filename), stdin);
    // printf("%d", sizeof(filename));
    // printf("Enter Sub-string: ");
    // fgets(substr, sizeof(substr), stdin);
    FILE* fp;
    fp = fopen(argv[1], "r");
    char str[100];
    fgets(str, 100, fp);

    int a = fsubstr(str, argv[2]);
    printf("%d\n", a);

    fclose(fp);

    return 0;
}