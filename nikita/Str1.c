//C:\Users\Public\Progs\Progs\Str1\List.txt
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct cntry
{
       char country[30];
       char tovar[30];
       int k;
};

typedef struct cntry DataType;

struct node
{
       DataType data;
       struct node * next;
};

typedef struct node * list;

DataType input_country (void);
list read_file (char * filename);
list new_node (list, DataType);
int write_file (char * filename, list);
void delete_list (list);
void show (list);
void search (list begin);
list delete_node (list);

int main (void)
{
    setlocale (LC_ALL, "Russian");
    char file[50];
    char menu;
    list countries = NULL;
    puts ("������� ��� �����");
    gets (file);
    countries = read_file (file);
//������ �� ����� ����������� � ������, �� ����� ��������� ���� � ����������� ��� ������� ����������
    do
    {
       system ("CLS");
       puts ("1. �������� ������");
       puts ("2. �������� ������");
       puts ("3. ����� �����, � ������� �������������� ������ �����");
       puts ("4. ��������");
       puts ("5. �����");
       menu = getchar();
       getchar();
       switch (menu)
       {
              case '1': countries = new_node (countries, input_country());
              break;
              case '2': show (countries);
              break;
              case '3': search (countries);
              break;
              case '4': countries = delete_node (countries);
       }
    }
    while (menu!='5');
    if (write_file (file, countries))
        puts ("���� ��������");
//��� ������ ���� ����������������
    else
    	puts ("���� �� ��������");
//����� - ��������������� ���������
    delete_list (countries);
//��������� � �������� ������ ������ ���������
    return 0;
}

DataType input_country (void)
{
//���������� ������ ��� ����� ������
    DataType country;
    puts ("������");
    gets (country.country);
    puts ("�����");
    gets (country.tovar);
    puts ("���-�� �������������� �������");
    scanf ("%d", &country.k);
	getchar();
    return country;
}

list new_node (list begin, DataType cntry)
{
//�������� ����� ������
    list temp = (list) malloc (sizeof(struct node));
//��������� ������ ��� ����� ���� ������ �� ��������� ����������
    temp->data = cntry;
//������ � ����� �������� ����������� � ���� ������ ������ ����
    temp->next = begin;
//"������" � ��� ������������ ������
    return temp;
}

list read_file (char * filename)
{
//������� ���������� ������ �� ����� � ������
    FILE * f;
    DataType country;
    list begin = NULL, cur;
    if ((f = fopen (filename, "rb")) == NULL)
    {
        perror ("������ �������� �����");
        getchar();
        return begin;
    }
    if (fread(&country, sizeof(country), 1, f))
        begin = new_node (NULL, country);
//���� ���� �� ������, ��������� ������ ���� ������
    else
        return NULL;
//����� ������������ ������� ��������
    cur = begin;
    while (fread(&country, sizeof(country), 1, f))
    {
        cur->next = new_node (NULL, country);
//�� ��� ���, ���� ���� �� ������, ��������� ����� ���� ������
        cur = cur->next;
//��������� "������"
	}
    fclose(f);
    return begin;
//������������ ����������� ������
}

void delete_list (list begin)
{
//�������� ������
    list temp = begin;
    while (temp)
    {
        begin = temp->next;
//���� ������ ��������� ���������������
        free (temp);
        temp = begin;
    }
}

int write_file (char * filename, list begin)
{
//������ ������ � ����
    FILE * f;
    if ((f = fopen (filename, "wb")) == NULL)
    {
        perror ("������ �������� �����");
        getchar();
        return 0;
    }
    while (begin)
    {
        if (fwrite (&begin->data, sizeof(DataType), 1, f))
            begin = begin->next;
//�� ��� ���, ���� ����, ��� ����������, ������ �� ��������� ������ ����������� � ����
        else
        	return 0;
    }
    return 1;
}

void print_data (struct cntry cntry)
{
    printf ("������ : %s\n����� : %s\n���-�� : %d\n",
            cntry.country, cntry.tovar, cntry.k);
}

void show (list cur)
{
//������� ������ ����������
     int k = 0;
     system ("CLS");
     if (cur == NULL)
     {
//���� ������ ������, ��������� ��������������� ���������
          puts ("������ ����");
          getchar();
          return;
     }
     puts ("|  N |          ������                 |    �����   |   ���-��   |");
     puts ("------------------------------------------------------------------");
     while (cur)
     {
        printf ("|%3d | %-31s |%11s |%11d |\n", ++k,
                 cur->data.country, cur->data.tovar, cur->data.k);
        cur = cur->next;
     }
     puts ("------------------------------------------------------------------");
     getchar();
}

void search (list cur)
{
//����� ����������� ������
     char tovar [20];
     int k = 0;
     DataType country;
     system ("CLS");
     if (cur == NULL)
//���� ������ ���� ��������� ��������������� ���������
     {
	    puts ("������ ����");
	    getchar();
	    return;
     }
     puts ("����� ����� ����������?");
     scanf ("%s", &tovar);
     getchar();
     while (cur)
//�� ��� ��� ���� � ������ ���� �������� ���� �����
     {
        if (strcmp (cur->data.tovar, tovar) == 0)
        {
           k++;
           country = cur->data;
           print_data (country);
           printf ("\n");
//��������������� ������� ������ ��������� �� �����
        }
        cur = cur->next;
     }
     if (k == 0)
     {
         printf ("����� �� ������");
//���� ����� ������� ��� ��������� ��������������� ���������
     }
     getchar();
 }

list delete_node (list begin) /*�������� ������� ��������*/
{
     struct node * temp;
     if (begin) /*���� ������ �� ����*/
     {
           temp = begin;
           begin = begin->next; /*������������ ��������� �� ��������� �������*/
           free (temp); /*������ �������*/
           puts ("�������");
           getchar();
     }
     return begin;
}
