#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
typedef struct
   {
	   char number[20];
       char name[20];
       char sex[50];
       char name_of_book[100];
       struct readers *next;
   }readers;
   readers *rhead;
typedef struct
   {
	   char serial_number[20];
       char name[20];
       int num1, num2;               //1��������2���ڼ��ϵ���
       char productor[50];
       char name_of_reader[5][20];
       struct books *next;
   }books;
    books *bhead;
    FILE *fp1, *fp2;
    readers *rp1, *rp2;
    books *bp1, *bp2;
    int chushihua();
    int student();
    int administrator();
    int Bborrow();
    int Breturn();
    int Bsearch();
    int Bdelete();
    int Rdelete();
    int Badd();
    int Radd();
    int Brepair();
    int Rreapir();
    int main()
    {
        char ch;
        char putpassword[20] ,password[20] = "1718012";
        chushihua();
        printf("\n\t\t\t**********************��ӭʹ��ͼ���ϵͳ**********************\n");
        printf("\t\t\t*                          1.ѧ��ģ��                        *\n");
        printf("\t\t\t*                          2.����Ա                          *\n");
        printf("\t\t\t*                          0.�˳�                            *\n");
        printf("\t\t\t**************************************************************\n");
        printf("��ѡ��1/2/0��:");
        ch = getche();
        switch( ch )
        {
            case'1':student();
                //����ѧ��ģ��
            break;
            case'2':
                printf("\n���������룺");

                while(1)
                {
                    gets( putpassword );
                    if( ( strcmp( putpassword, password ) == 0 ) || ( strcmp( putpassword, "0" ) == 0 ) )
                        break;
                    else
                        printf("����������������룬������0���˳�");
                }
                if( ( strcmp( putpassword, password ) == 0 ) )
                {
                    administrator();//����Աģ��
                    break;
                }
                else
                break;
            case'0':
            break;
            default:printf("\n�������������ѡ��\n\n\n");
                break;
        }
        printf("\n�ټ����밴������˳���");
                getch();
        return 0;
   }


int student()
{
        char ch;
        printf("\n\t\t\t***************************ѧ������***************************\n");
        printf("\t\t\t*                           1.����                           *\n");
        printf("\t\t\t*                           2.����                           *\n");
        printf("\t\t\t*                           3.��ѯ                           *\n");
        printf("\t\t\t*                           0.�˳�                           *\n");
        printf("\t\t\t**************************************************************\n");
        printf("��ѡ��1/2/3/0��:");
        ch = getche();
        switch( ch )
        {
            case'1':Bborrow();
                //���ý���ģ��
            break;
            case'2':Breturn();
                //���û���ģ��
            break;
            case'3':Bsearch();
                //���ò�ѯģ��
            break;
            case'0':
            break;
            default:printf("\n�������������ѡ��\n\n\n");
                break;
        }
        return 1;
   }

int Bborrow()     //����
{
    int i, count = 0;
    char inputname[100], bname[100], ch;
    fp1 = fopen( "readers.txt", "r" );
    fp2 = fopen( "books.txt", "r" );
    printf("\n\t\t\t************************��������������************************\t\t\n");
    printf("\t\t\t**************************************************************\n");
    printf( "\t\t\t\t\t\t    " );
    scanf("%s", inputname);
    while( rp1 != NULL )
	{
		if( strcmp( inputname, rp1 -> name ) == 0 )
		{
		    count ++;
		    break;
		}
		else
            rp1 = rp1 -> next;
        readers *rp1 = ( readers * )malloc( sizeof( readers ) );
   	}

   	if( count == 0 )
   		printf("ѧ����Ϣ������");
   	else
   	{
   	    count = 0;
   		if( strcmp( rp1 -> name_of_book, "NULL" ) != 0 )
   			printf( "������δ�������Ȼ���");

   		else
   		{
   			printf("\n\t\t\t***********************��������������***********************\t\t\n");
   			printf( "\t\t\t\t\t     " );
            scanf("%s", bname);
            while( bp1 != NULL )
			{
				if( strcmp( bname, bp1 -> name ) == 0 )
				{
                    count ++;
                    break;
				}
                else
                    bp1 = bp1 -> next;
   				books *b=( books * )malloc( sizeof( books ) );
   			}
            if( count == 0 )
   			printf("ͼ����Ϣ������");
            else
            	{
            		if( bp1 -> num2 == 0 )
                	printf("���ѽ���");
            		else
                	{
                     	printf( "\n%s ",bp1 -> serial_number );
                     	printf( "%s ",bp1 -> name );
                     	printf( "�ݲ�%d�� ",bp1 -> num1 );
                     	printf( "�ڼ���%d�� ",bp1 -> num2 );
                    	printf( "%s  �����ߣ�",bp1 -> productor );
                        for( i = 0; strcmp(bp1 -> name_of_reader[i] , "NULL") != 0; i ++)
                    		printf( "%s ",bp1 -> name_of_reader[i] );
                    	printf("\n\nȷ��Ҫ����  [Y->ȷ�ϣ��������������]\n");
                    	printf( "\n\t\t\t\t\t\t\t" );
                    	ch = getche();
                    	if( tolower( ch ) == 'y' )
                        {
                            printf("\n����ɹ���\n");
                            bp1-> num2 --;
                            strcpy( bp1 -> name_of_reader[i], rp1 -> name );
                            strcpy( rp1 ->name_of_book, bp1 ->name );
                            fclose(fp1);
                            fclose(fp2);
                            rp1 = rhead;
                            bp1 = bhead;
                            fp1 = fopen( "readers.txt", "w" );
                            fp2 = fopen( "books.txt", "w" );
                            while( rp1 != NULL )
                            {
                                fprintf( fp1, "%s %s %s %s\n", rp1 -> number, rp1 -> name, rp1 -> sex, rp1 -> name_of_book );
                                rp1 = rp1 -> next;
                            }
                            while( bp1 != NULL )
                            {
                                fprintf( fp2,"%s %s %d %d %s ", bp1 -> serial_number, bp1 -> name, bp1 -> num1, bp1 -> num2 , bp1 -> productor );
                                for ( i = 0; i < 5; i ++ )
                                    fprintf( fp2, "%s ", bp1 -> name_of_reader[i] );
                                fprintf( fp2, "\n");
                                bp1 = bp1 -> next;
                            }
                            free( rp1 );
                            rp1 = NULL;
                            free( bp1 );
                            bp1 = NULL;
                        }
                        else
                            printf("����ʧ��");
                	}
        		}
   		}
	}
	fclose(fp1);
	fclose(fp2);
	   return 1;
}

int Breturn()   //����
{
    int i, count = 0;
    char inputname[100], ch;
    fp1 = fopen( "readers.txt", "r" );
    fp2 = fopen( "books.txt", "r" );
    printf("\n\t\t\t************************��������������************************\t\t\n");
    printf("\t\t\t**************************************************************\n");
    printf( "\t\t\t\t\t\t    " );
    scanf("%s", inputname);
   while( rp1 != NULL )
	{
		if( strcmp( inputname, rp1 -> name ) == 0 )
		{
		    count ++;
		    break;
		}
		else
            rp1 = rp1 -> next;
   	}
   		//��ȡѧ����Ϣ

   	if( count == 0 )
   		printf("ѧ����Ϣ������");
   	else
   	{
   	    count = 0;
   		if( strcmp( rp1 -> name_of_book, "NULL" ) == 0 )
   			printf( "����δ����");

   		else
   		{
                printf( "�����������:  %s\n", rp1 -> name_of_book );
                printf("\nȷ��Ҫ����  [Y->ȷ�ϣ��������������]\n");
                printf( "\n\t\t\t\t\t\t\t" );
                ch = getche();
                if( tolower( ch ) == 'y' )
                {
                    printf("\n����ɹ���\n");
                    while( bp1 != NULL )
                    {
                        if( strcmp( rp1 -> name_of_book, bp1 -> name ) == 0)
                            break;
                        else
                            bp1 = bp1 -> next;
                            books *bp1 = ( books * )malloc( sizeof( books ) );
                    }
                    bp1 -> num2 ++;
                    for( i = 0; i <= 5; i ++ )
                    {
                        if ( strcmp( bp1 -> name_of_reader[i], inputname ) == 0 )
                        {
                            strcpy( bp1 -> name_of_reader[i], "NULL" );
                        }
                    }
                    strcpy( rp1 ->name_of_book, "NULL" );
                    fclose(fp1);
                    fclose(fp2);
                    rp1 = rhead;
                    bp1 = bhead;
                    fp1 = fopen( "readers.txt", "w" );
                    fp2 = fopen( "books.txt", "w" );
                    while( rp1 != NULL )
                    {
                        fprintf( fp1, "%s %s %s %s\n", rp1 -> number, rp1 -> name, rp1 -> sex, rp1 -> name_of_book );
                        rp1 = rp1 -> next;
                    }
                    while( bp1 != NULL )
                    {
                        fprintf( fp2,"%s %s %d %d %s ", bp1 -> serial_number, bp1 -> name, bp1 -> num1, bp1 -> num2 , bp1 -> productor );
                        for ( i = 0; i < 5; i ++ )
                            fprintf( fp2, "%s ", bp1 -> name_of_reader[i] );
                        fprintf( fp2, "\n");
                        bp1 = bp1 -> next;
                    }
                    free( rp1 );
                    rp1 = NULL;
                    free( bp1 );
                    bp1 = NULL;
                }
                else
                    printf("����ʧ��");

        }
   	}


    fclose(fp1);
	fclose(fp2);
    return 1;
}

int Bsearch()
{
    int i, count = 0;
    char bname[100];
    char ch;
    fp2 = fopen( "books.txt", "r" );
    printf("\n\t\t\t**********************���������ѯ������**********************\t\t\n");
    printf( "\t\t\t\t\t     " );
    scanf("%s", bname);
    while( bp1 != NULL )
    {
       if( strcmp( bname, bp1 -> name ) == 0 )
        {
            count ++;
            break;
        }
        else
        bp1 = bp1 -> next;
    }

            	//����,��Ҫ�ýṹ�������еı�����������Ž��бȽ�
    if( count == 0 )
    printf("ͼ����Ϣ������");
                //�����ڣ������ж���ṹ����ʣ�������Ƿ�Ϊ0��
    else
    {
        printf( "%s ",bp1 -> serial_number );
        printf( "%s ",bp1 -> name );
        printf( "�ݲ�%d�� ",bp1 -> num1 );
        printf( "�ڼ���%d�� ",bp1 -> num2 );
        printf( "%s ",bp1 -> productor );
        printf("�����ߣ�");
        for( i = 0; i < 5; i ++)
            if( strcmp(bp1 -> name_of_reader[i] , "NULL") != 0 )
                printf( "%s ",bp1 -> name_of_reader[i] );
    }
	fclose(fp2);
    return 1;
}

int administrator()
{
        char ch;
        printf("\n\t\t\t**************************����Աģ��**************************\n");
        printf("\t\t\t*                         1.����ѧ����Ϣ                     *\n");
        printf("\t\t\t*                         2.�޸�ѧ����Ϣ                     *\n");
        printf("\t\t\t*                         3.ɾ��ѧ����Ϣ                     *\n");
        printf("\t\t\t*                         4.����ͼ����Ϣ                     *\n");
        printf("\t\t\t*                         5.�޸�ͼ����Ϣ                     *\n");
        printf("\t\t\t*                         6.ɾ��ͼ����Ϣ                     *\n");
        printf("\t\t\t*                         0.�˳�                             *\n");
        printf("\t\t\t**************************************************************\n");
        printf("��ѡ��1/2/3/4/5/6/0��:");
        ch = getche();
        switch( ch )
        {
            case'1':Radd();
            break;
            case'2':Rrepair();
            break;
            case'3':Rdelete();
            break;
            case'4':Badd();
            break;
            case'5':Brepair();
            break;
            case'6':Bdelete();
            break;
            case'0':
            break;
            default:printf("\n�������������ѡ��\n\n\n");
                break;
        }
        return 1;
   }

int Radd()
{
    int add_flag;
    char ch;
    rp1 = rhead;
    while( rp1 -> next != NULL )
        rp1  = rp1 -> next;
    ch = 'y';
    while( tolower(ch) =='y' )
    {
        rp2 = ( struct readers *) malloc (sizeof(readers));
        printf("\n\t\t\t\t\t\t����ѧ����Ϣ");
        printf("\n�밴���¸�ʽ���룺\n");
        printf("ѧ�ţ�");
        gets( rp2 -> number );
        printf("������");
        gets( rp2 -> name );
        printf("�Ա�");
        gets( rp2 -> sex );
        rp2 -> next = NULL;
        strcpy( rp2 -> name_of_book, "NULL" );
        printf("\n��ȷ����������[y/Y],�����������������\n");
        ch = getche();
        if( tolower(ch) == 'y' )
        {
            rp1 ->next = rp2;
            rp1 = rp2;
            rp2 = NULL;
            fp1 = fopen("readers.txt", "w");
            rp1 = rhead;
            while( rp1 != NULL )
            {
                fprintf( fp1, "%s %s %s %s\n", rp1 -> number, rp1 -> name, rp1 -> sex, rp1 -> name_of_book );
                rp1 = rp1 -> next;
            }
            fclose( fp1 );
            printf("\n����ѧ����Ϣ�ɹ�����......�����������......");
            getch();
            putch( '\n' );
            add_flag = 1;
        }
        else
        {
            printf("\nδ������ѧ����Ϣ������......�����������......");
            getch();
            putch( '\n' );
            add_flag = 2;
        }
        printf("\n�Ƿ�������һ��ѧ����Ϣ��������ӣ�����[y/Y]������������˳�����Աϵͳ");
        ch = getch();
        }
        rp1 = NULL;
        return add_flag;
}

int Rrepair()
{
    int count = 0, i;
    char ch, stu_name[20], newnumber[20], newname[100], newsex[50];
    chushihua();
    fp1 = fopen( "readers.txt", "r" );
    printf("\n��������޸�ѧ�������֣����س���ȷ�ϣ���\n\t\t\t\t\t\t");
    gets(stu_name);
    while( rp1 != NULL )
        {
            if( strcmp(  stu_name, rp1 -> name ) == 0)
                {
                    count ++;
                    break;
                }
            else
                rp1 = rp1 -> next;
                readers *rp1 = ( readers * )malloc( sizeof( readers ) );
        }


   	if( count == 0 )
   		printf("ѧ����Ϣ������");
    else
        while(1)
        {
            printf("\n��Ҫ�޸ĵ�ѧ����ԭʼ��Ϣ�ǣ�\n");
            printf("%s\t%s\t%s\t%s", rp1 -> number, rp1 -> name, rp1 -> sex, rp1 -> name_of_book );
            printf("\n1.ѧ��  2.����  3.�Ա�  \n");
            printf("��ѡ��");
            ch = getche();
            switch( ch )
            {
                case'1':printf("\n�������µ���Ϣ���س���������");
                        gets( newnumber );
                        printf("�Ƿ�ȷ�ϣ�[y/n]");
                        ch = getche();
                        if( tolower(ch) == 'y')
                            strcpy( rp1 -> number, newnumber );
                        break;
                case'2':printf("\n�������µ���Ϣ���س���������");
                        gets( newname );
                        printf("�Ƿ�ȷ�ϣ�[y/n]");
                        ch = getche();
                        if( tolower(ch) == 'y')
                            strcpy( rp1 -> name, newname );
                        break;

                case'3':printf("\n�������µ���Ϣ���س���������");
                        gets( newsex );
                        printf("�Ƿ�ȷ�ϣ�[y/n]");
                        ch = getche();
                        if( tolower(ch) == 'y')
                            strcpy( rp1 -> sex, newsex );
                        break;
                default: printf("\n����������������룺\n");
                break;
            }
            if( tolower(ch) == 'y')
            {
                printf("\n�޸ĳɹ���\n");
                printf("\n���޸ĺ��ѧ������Ϣ�ǣ�\n");
                printf(" %s %s %s %s", rp1 -> number, rp1 -> name, rp1 -> sex, rp1 -> name_of_book );
                fp1 = fopen("readers.txt", "w");
                rp1 = rhead;
                while( rp1 != NULL )
                {
                    fprintf( fp1, "%s %s %s %s\n", rp1 -> number, rp1 -> name, rp1 -> sex, rp1 -> name_of_book );
                    rp1 = rp1 -> next;

                }
                fclose( fp1 );

            }
            else
            {
                printf("\n\n�޸�ʧ�ܡ�\n");
            }

            break;
        }
        return 1;
    }

int Rdelete()
{
    char ch,stu_name[10];
    int delete_flag, count = 0;
    ch = 'y';
    while( tolower(ch) == 'y' )
    {
        printf("\n�������ɾ��ѧ�������֣����س���ȷ�ϣ���");
        gets(stu_name);
        rp1 = rhead;
        rp2 = NULL;
        while( rp1 != NULL )
        {
            if( strcmp( rp1 -> name, stu_name ) )
            {
                rp2 = rp1;
                rp1 = rp1 -> next;
                count ++;
            }
            else
            {
                printf( "\n��Ҫɾ����ѧ�������ǣ�%s\n", rp1 -> name );
                printf("\n�����ٴ�ȷ��[y/Y]:");
                ch = getche();
                if( tolower(ch) == 'y' )
                {
                    if( count == 0 )
                        rp1 = rp1 -> next;
                    else
                        rp2 -> next = rp1 -> next;
                    printf("\n\nɾ���ɹ���\n");
                    delete_flag = 3;
                    break;
                }
                else
                {
                    printf("\n\nɾ��ʧ�ܣ�\n");
                    delete_flag = 4;
                    break;
                }
            }
        }
        if( rp1 == NULL)
        {
            printf("\n��������Ҫɾ������Ϣ���밴���������......\n");
            delete_flag = 5;
            getch();
        }
        printf("\n�Ƿ����ɾ����һ��ѧ����Ϣ[y/Y],��ɾ��������������˳�����Աϵͳ......\n");
        ch = getche();
    }
    fp1 = fopen("readers.txt", "w");
    if( count != 0 )
        rp1 = rhead;
    while( rp1 != NULL )
    {
        fprintf( fp1, "%s %s %s %s\n", rp1 -> number, rp1 -> name, rp1 -> sex, rp1 -> name_of_book );
        rp1 = rp1 -> next;     //д�����ļ���ȥ
    }
    fclose( fp1 );
    return delete_flag;
}

int Badd()
{
    int i;
    char ch;
    bp1 = bhead;
    while( bp1 -> next != NULL )
        bp1  = bp1 -> next;
    ch = 'y';
    while( tolower(ch) =='y' )
    {
        bp2 = ( struct books *) malloc (sizeof(books));
        printf("\n\t\t\t\t\t\t����ͼ����Ϣ");
        printf("\n�밴���¸�ʽ���룺\n");
        printf("��ţ�");
        gets( bp2 -> serial_number );
        printf("������");
        gets( bp2 -> name );
        printf("�����磺");
        gets( bp2 -> productor );
        printf("������");
        scanf( "%d", &( bp2 -> num1 ) );
        bp2 -> num2 = bp2 -> num1;
        for ( i = 0; i < 5; i ++ )
            strcpy( bp2 -> name_of_reader[i] , "NULL" );
        bp2 -> next = NULL;
        printf("\n ��ȷ����������[y/Y],�����������������");
        ch = getche();
        if( tolower(ch) == 'y' )
        {
            bp1 -> next = bp2;
            bp1 = bp2;
            bp2 = NULL;
            fp2 = fopen("books.txt", "w");
            bp1 = bhead;
            while( bp1 != NULL )
            {
                fprintf( fp2,"%s %s %d %d %s ", bp1 -> serial_number, bp1 -> name, bp1 -> num1, bp1 -> num2 , bp1 -> productor );
                for ( i = 0; i < 5; i ++ )
                    fprintf( fp2, "%s ", bp1 -> name_of_reader[i] );
                fprintf( fp2, "\n");
                bp1 = bp1 -> next;
                }    //д��ȥ֮��������
                free( bp1 );
                bp1 = NULL;
            printf("\n\n׷��ͼ����Ϣ�ɹ�����......�����������......");
            getch();
            putch( '\n' );

        }
        else
        {
            printf("\n\nδ��׷��ͼ����Ϣ������......�����������......");
            getch();
            putch( '\n' );
        }
        printf("\n�Ƿ�������һ��ͼ����Ϣ��������ӣ�����[y/Y]������������˳�����Աϵͳ......");
        ch = getch();
        }
        bp1 = NULL;
        fclose( fp2 );
        return 1;
}

int Brepair()
{
    int count = 0, i;
    char ch, book_name[20], newserial_number[20], newname[100], newproductor[50];
    int newnum1;
    chushihua();
    fp2 = fopen( "books.txt", "r" );

    printf("\n��������޸�������������س���ȷ�ϣ���");
    gets(book_name);
    while( bp1 != NULL )
        {
            if( strcmp(  book_name, bp1 -> name ) == 0)
                {
                    count ++;
                    break;
                }
            else
                bp1 = bp1 -> next;
                books *bp1 = ( books * )malloc( sizeof( books ) );
        }

   		//��ȡ�����Ϣ

   	if( count == 0 )
   		printf("\nͼ����Ϣ������");
    else
        while(1)
        {
            printf("\n��Ҫ�޸ĵ����ԭʼ��Ϣ�ǣ�\n");
            printf("%s\t%s\t�ݲ�%d��\t�ڼ���%d��\t%s\t\n",bp1 -> serial_number, bp1 -> name, bp1 -> num1, bp1 -> num2, bp1 -> productor );
            printf("\n�����������޸���Ӧ��Ϣ��\n");
            printf("1.���  2.����  3.�ݲ���  4.������  \n");
            printf("��ѡ��");
            ch = getche();
            switch( ch )
            {
                case'1':printf("\n�������µ���Ϣ���س���������");
                        gets( newserial_number );
                        printf("\n�Ƿ�ȷ�ϣ�[y/n]");
                        ch = getche();
                        if( tolower(ch) == 'y')
                            strcpy( bp1 -> serial_number, newserial_number );
                        break;
                case'2':printf("\n�������µ���Ϣ���س���������");
                        gets( newname );
                        printf("\n�Ƿ�ȷ�ϣ�[y/n]");
                        ch = getche();
                        if( tolower(ch) == 'y')
                            strcpy( bp1 -> name, newname );
                        break;
                case'3':printf("\n�������µ���Ϣ���س���������");
                        scanf( "%d", &( newnum1 ) );
                        printf("\n�Ƿ�ȷ�ϣ�[y/n]");
                        ch = getche();
                        if( tolower(ch) == 'y')
                            bp1 -> num1 = newnum1;
                        break;
                case'4':printf("\n�������µ���Ϣ���س���������");
                        gets( newproductor );
                        printf("\n�Ƿ�ȷ�ϣ�[y/n]");
                        ch = getche();
                        if( tolower(ch) == 'y')
                            strcpy( bp1 -> productor, newproductor );
                        break;
                default: printf("\n����������������룺\n");
                break;
            }
            if( tolower(ch) == 'y')
            {
                printf("\n�޸ĳɹ���\n");
                printf("\n���޸ĺ��ͼ�����Ϣ�ǣ�\n");
                printf("%s\t%s\t�ݲ�%d��\t%s\t\n",bp1 -> serial_number, bp1 -> name, bp1 -> num1, bp1 -> productor );
                fp2 = fopen("books.txt", "w");
                bp1 = bhead;
                while( bp1 != NULL )
                    {
                        fprintf( fp2,"%s %s %d %d %s ", bp1 -> serial_number, bp1 -> name, bp1 -> num1, bp1 -> num2 , bp1 -> productor );
                        for ( i = 0; i < 5; i ++ )
                            fprintf( fp2, "%s ", bp1 -> name_of_reader[i] );
                        fprintf( fp2, "\n");
                        bp1 = bp1 -> next;
                    }
                      //������ʾ����Ļ�ϣ�����д�����ļ���
            fclose( fp2 );
            }
            else
            {
                printf("\n\n�޸�ʧ�ܡ�\n");
            }
            break;
        }

        return 1;
    }

int Bdelete()
{
    char ch,book_name[100];
    int i, delete_flag, count = 0;
    ch = 'y';
    while( tolower(ch) == 'y' )
    {
        printf("\n\n�������ɾ��������������س���ȷ�ϣ���");
        gets(book_name);
        bp1 =bhead;
        bp2 = NULL;
        while( bp1 != NULL )
        {
            if( strcmp( bp1 -> name, book_name ) )
            {
                bp2 = bp1;
                bp1 = bp1 -> next;
                count ++;
            }
            else
            {
                printf( "\n��Ҫɾ�������ǣ�%s\n", bp1 -> name );
                printf("\n�����ٴ�ȷ��[y/Y]:");
                ch = getche();
                if( tolower(ch) == 'y' )
                {
                    printf("\n\nɾ���ɹ���");
                    if( count != 0 )
                        bp2 -> next = bp1 -> next;
                    else
                        bp1 = bp1 -> next;
                    delete_flag = 3;
                    break;
                }
                else
                {
                    printf("\n\nɾ��ʧ�ܣ�");
                    delete_flag = 4;
                    break;
                }
            }
        }
        if( bp1 == NULL)
        {
            printf("\n��������Ҫɾ������Ϣ���밴���������......\n");
            delete_flag = 5;
            getch();
        }
        printf("\n\n�Ƿ����ɾ����һ��ͼ����Ϣ[y/Y],��ɾ��������������˳�����Աϵͳ......\n");
        ch = getche();
    }
    fp2 = fopen("books.txt", "w");
    if( count != 0 )
        bp1 = bhead;
    while( bp1 != NULL )
    {
        fprintf( fp2,"%s %s %d %d %s ", bp1 -> serial_number, bp1 -> name, bp1 -> num1, bp1 -> num2 , bp1 -> productor );
        for ( i = 0; i < 5; i ++ )
            fprintf( fp2, "%s ", bp1 -> name_of_reader[i] );
        fprintf( fp2, "\n");
        bp1 = bp1 -> next;
    }
        free( bp1 );
        bp1 = NULL;
    fclose( fp2 );
    return delete_flag;
}

int chushihua()
{
    int i;
    fp1 = fopen("readers.txt", "r");
    fp2 = fopen("books.txt", "r");
    if ( ( fp1 == NULL ) || ( fp2 == NULL ) )
    {
        printf("δ�ܳ�ʼ����Ϣ");
        fclose( fp1 );
        fclose( fp2 );
        return 0;
    }
    else
    {
        rp1 = ( readers *)malloc( sizeof(readers) );
        rhead = rp1;
         while( !feof(fp1) )
        {
            fscanf( fp1,"%s %s %s %s", rp1 -> number, rp1 -> name, rp1 -> sex, rp1 -> name_of_book );
            rp2 = rp1;
            rp1 = ( readers *)malloc( sizeof(readers) );
            rp2 -> next = rp1;
        }
        rp1 -> next = NULL;
        rp2 = NULL;
        free( rp1 );
        rp1 = NULL;
        rp1 = rhead;

        bp1 = ( books *)malloc( sizeof(books) );
        bhead = bp1;
         while( fscanf( fp2,"%s", bp1 -> serial_number) != EOF)
        {
            fscanf( fp2,"%s %d %d %s ", bp1 -> name, &(bp1 -> num1), &(bp1 -> num2), bp1 -> productor );
            for ( i = 0; i < 5; i ++ )
                fscanf( fp2, "%s", bp1 -> name_of_reader[i] );
            bp2 = bp1;
            bp1 = ( books *)malloc( sizeof(books) );
            bp2 -> next = bp1;
        }
        bp1 -> next = NULL;
        bp2 = NULL;
        free( bp1 );
        bp1 = NULL;
        bp1 = bhead;
    }

    fclose( fp1 );
    fclose( fp2 );
    return 1;
}

