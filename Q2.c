
#include<stdio.h>

void add_student()
{
    FILE* fp;
    fp = fopen("student.txt", "a+");
    char str[100];
    printf("Enter Name: ");
    fgets(str, sizeof(str), stdin);
    fgets(str, sizeof(str), stdin);
    fprintf(fp, "%s", str);
    printf("Enter Roll Num: ");
    fgets(str, sizeof(str), stdin);
    fprintf(fp, "%s", str);
    printf("Enter E-mail: ");
    fgets(str, sizeof(str), stdin);
    fprintf(fp, "%s", str);

    fclose(fp);
}

void read_student()
{
    FILE* fp;
    fp = fopen("student.txt", "r");
    int key;
    printf("Enter Number:");
    scanf("%d", &key);
    char name[30], rollnum[10], email[40];
    for (int i = 0; i <= key; ++i)
    {
        fgets(name, 30, fp);
        fgets(rollnum, 10, fp);
        fgets(email, 40, fp);
    }
    printf("Name: %s", name);
    printf("Roll Number: %s", rollnum);
    printf("E-mail: %s", email);

    fclose(fp);
}

void delete_student()
{
    FILE* fp;
    fp = fopen("student.txt", "r");
    FILE *fp1;
    fp1 = fopen("temp.txt", "w");
    fp1 = fopen("temp.txt", "w");
    int key;
    printf("Enter Number:");
    scanf("%d", &key);
    char name[30], rollnum[10], email[40];
    int i = 0;
    while (fgets(name,30,fp)!=0)
    {
        fgets(rollnum, 10, fp);
        fgets(email, 40, fp);        
        if(i!=key)
        {
            fprintf(fp1, "%s", name);
            fprintf(fp1, "%s", rollnum);
            fprintf(fp1, "%s", email);
        }
        ++i;
    }

    fclose(fp);
    fclose(fp1);

    FILE* _fp;
    _fp = fopen("temp.txt", "w");
    FILE *_fp1;
    _fp1 = fopen("student.txt", "r");
    // int i = 0;
    while (fgets(name,30,_fp)!=0)
    {
        fgets(rollnum, 10, _fp);
        fgets(email, 40, _fp); 
        fprintf(_fp1, "%s", name);
        fprintf(_fp1, "%s", rollnum);
        fprintf(_fp1, "%s", email);
    }

    fclose(_fp);
    fclose(_fp1);
}

int main()
{
    FILE* fp;
    fp = fopen("student.txt", "w");
    char str[100];
    fgets(str, 100, fp);

    fprintf(fp, "%s", "Usama Iqbal\n");
    fprintf(fp, "%s", "19L-2232\n");
    fprintf(fp, "%s", "l192232@lhr.nu.edu.pk\n");

    fprintf(fp, "%s", "Hassan Ali\n");
    fprintf(fp, "%s", "19L-4321\n");
    fprintf(fp, "%s", "l194321@lhr.nu.edu.pk\n");

    fprintf(fp, "%s", "Ayesha Khan\n");
    fprintf(fp, "%s", "19L-1111\n");
    fprintf(fp, "%s", "l191111@lhr.nu.edu.pk\n");

    fclose(fp);

    int key = -1;
    while(key != 0)
    {
        printf("Enter 1 to to add student\n 2 to read student\n 3 to delete student\n 0 to exit\n:");
        scanf("%d", &key);
        if(key == 1)
            add_student();
        else if(key == 2)
            read_student();
        else if(key == 3)
            delete_student();
    }

    return 0;
}