//�����õ�ͷ�ļ�
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
//���ҽṹ��
typedef struct
   {
	   char number[20];
	   char name[20];
       char password[50];
       char telenumber[15];
       char name_of_goods[5][100];
       struct seller *next;
   }seller;
seller *shead;//ͷָ��
//��ҽṹ��
typedef struct
    {
        char name[20];
        char number[20];
        char password[50];
        struct buyer *next;
    }buyer;
buyer *bhead;//ͷָ��
//��Ʒ�ṹ��
typedef struct
   {
       char name[100];
       char label[50];
       char wanted;
       char tele_of_seller[15];
       int price;
       struct goods *next;
    }goods;
goods *ghead;//ͷָ��
//ȫ�ֱ���
FILE *fp1, *fp2, *fp3;
seller *sp1, *sp2;
buyer *bp1, *bp2;
goods *gp1, *gp2;
//��������
int chushihua();
void buy();
void sell();
void choose_of_sellers();
void choose_of_buyers();
void registerbuyer();
void registerseller();
int loginbuyer();
int loginseller();
void add_goods_of_seller();
void revise_of_sellers();
void revise_of_buyers();
void search_of_sellers();
void search_of_buyers();
int delete_of_goods();
void change_info_of_goods( int sh );
void fprintf_of_sellers();
void fprintf_of_buyers();
void fprintf_of_goods();
//����������
int main()
{
    char ch;
    chushihua();
    while(1)
    {
        printf("\n\t\t\t**********************��ӭʹ��������ֽ���ϵͳ**********************\n");
        printf("\t\t\t                          1.�������                        \n");
        printf("\t\t\t                          2.��������                          \n");
        printf("\t\t\t                          0.�˳�                            \n");
        printf("\t\t\t**************************************************************\n");
        printf("��ѡ��1/2/0��:\n");
        ch = getche();
        switch( ch )
        {
        case'1':buy();//�������ģ��
                fprintf_of_buyers();//�˳�ʱ������Ϣд��buyers.txt�ı�
                fprintf_of_goods();//�˳�ʱ������Ϣд��goods.txt�ı�
                continue;
        case'2':sell();//��������ģ��
                fprintf_of_sellers();//�˳�ʱ������Ϣд��sellers.txt�ı�
                fprintf_of_goods();//�˳�ʱ������Ϣд��goods.txt�ı�
                continue;
        default:printf("�ټ����밴������˳���\n");
                return 0;
        }
    }
}
void buy()//����˺Ź���
{
	    printf("\n\t\t\t**********************���ϵͳ�˺Ž��棺**********************\n");
        printf("\t\t\t                          1.ע��                       \n");
        printf("\t\t\t                          2.��½                          \n");
        printf("\t\t\t                          0.�˳�                            \n");
        printf("\t\t\t**************************************************************\n");
        int ch;
       while(1)
	    {
            printf("��ѡ��\n");
            scanf("%d",&ch);
            if(ch==1)
        	{
        		registerbuyer();//���ע�ắ��
			}
            else if (ch==2)
			{
				if(loginbuyer()==0)
					{
						choose_of_buyers();//���ϵͳ��ѡ�����
						break;
					}
				else
					{
						printf("��½ʧ�ܣ������˻��������벻ƥ��\n");
						continue;
					}
			}
            else
                break;
		}
}
void sell()//�����˺Ź���
{
	    printf("\n\t\t\t**********************����ϵͳ�˺Ž��棺**********************\n");
        printf("\t\t\t                          1.ע��                       \n");
        printf("\t\t\t                          2.��½                          \n");
        printf("\t\t\t                          0.�˳�                            \n");
        printf("\t\t\t**************************************************************\n");
        int ch;
       while(1)
	    {
		printf("��ѡ��\n");
        scanf("%d",&ch);
        if(ch==1)
        	{
        		registerseller();//����ע�ắ��
        		break;
			}
		else if (ch==2)
			{
				if(loginseller()==0)
					{
						choose_of_sellers();//����ϵͳѡ�����
						break;
					}
				else
					{
						printf("��½ʧ�ܣ������˻��������벻ƥ��\n");
						continue;
					}
			}
		else
			break;
		}
}
void choose_of_sellers()//���ҹ��ܺ���ѡ��
{
    int ch;
        while(1)
        {
            printf("\n\t\t\t**********************����ϵͳ��**********************\n");
            printf("\t\t\t                          1.����                       \n");
            printf("\t\t\t                          2.�޸�                          \n");
            printf("\t\t\t                          3.��ѯ                          \n");
            printf("\t\t\t                          4.ɾ��                          \n");
            printf("\t\t\t                          0.�˳�                            \n");
            printf("\t\t\t**************************************************************\n");
            scanf("%d",&ch);
        	if(ch==1)
        		{
        			add_goods_of_seller();//������Ʒ
        			continue;
				}
			else if(ch==2)
				{
					revise_of_sellers();//�޸����һ���������Ʒ����Ϣ
                    continue;
				}
			else if( ch == 3 )
                {
                    search_of_sellers();//���Ҳ�ѯ�Լ���������Ʒ
                    continue;
                }
            else if( ch == 4 )
                {
                    delete_of_goods();//ɾ����Ʒ
                    continue;
                }
            else
				break;
		}

}
void choose_of_buyers()//��ҹ��ܺ���ѡ��
{
		int ch;
        while(1)
        {
            printf("\n\t\t\t**********************���ϵͳ��**********************\n");
            printf("\t\t\t                          1.��ѯ                       \n");
            printf("\t\t\t                          2.�޸�                          \n");
            printf("\t\t\t                          0.�˳�                            \n");
            printf("\t\t\t**************************************************************\n");
            scanf("%d",&ch);
        	if(ch==1)
        		{
        			search_of_buyers();//��Ҳ�ѯ�ض���ǩ����Ʒ
        			continue;
				}
			else if(ch==2)
				{
					revise_of_buyers();//�޸�����˺ŵ���Ϣ
					continue;
				}
            else
				break;
		}
}
int chushihua()//��txt�ı��ｫ���ݵ�����Ϊ����
{
    int i;
    fp1 = fopen("sellers.txt", "r");
    fp2 = fopen("buyers.txt", "r");
    fp3 = fopen("goods.txt", "r");
    if ( ( fp1 == NULL ) || ( fp2 == NULL ) || ( fp3 == NULL ) )
    {
        printf("δ�ܳ�ʼ����Ϣ");
        fclose( fp1 );
        fclose( fp2 );
        fclose( fp3 );
        return 0;
    }
    else
    {
//sellers.txt
        sp1 = ( seller *)malloc( sizeof(seller) );
        shead = sp1;
         while( !feof(fp1) )
        {
            fscanf( fp1,"%s %s %s %s", sp1 -> number, sp1 -> name, sp1 -> password, sp1 ->telenumber );
            for ( i = 0; i < 5; i ++ )
                fscanf( fp1, "%s", sp1 -> name_of_goods[i] );
            sp2 = sp1;
            sp1 = ( seller *)malloc( sizeof(seller) );
            sp2 -> next = sp1;
        }
        sp2 -> next = NULL;
        sp2 = NULL;
        free( sp1 );
        sp1 = shead;
//buyers.txt
        bp1 = ( buyer *)malloc( sizeof(buyer) );
        bhead = bp1;
         while( fscanf( fp2,"%s", bp1 -> number) != EOF)
        {
            fscanf( fp2,"%s %s ", bp1 -> name, bp1 -> password );
            bp2 = bp1;
            bp1 = ( buyer *)malloc( sizeof(buyer) );
            bp2 -> next = bp1;
        }
        bp2 -> next = NULL;
        bp2 = NULL;
        free( bp1 );
        bp1 = bhead;
//goods.txt
        gp1 = ( goods *)malloc( sizeof(goods) );
        ghead = gp1;
         while( fscanf( fp3,"%s", gp1 -> name) != EOF)
        {
            fscanf( fp3,"%s %c %s %d", gp1 -> label, &(gp1 -> wanted), gp1 -> tele_of_seller, &(gp1 -> price) );
            gp2 = gp1;
            gp1 = ( goods *)malloc( sizeof(goods) );
            gp2 -> next = gp1;
        }
        gp2 -> next = NULL;
        gp2 = NULL;
        free( gp1 );
        gp1 = ghead;
    }

    fclose( fp1 );
    fclose( fp2 );
    fclose( fp3 );
    return 0;
}
void registerbuyer()//���ע�ắ��
{
    chushihua();
    char ch = 'y';
    bp1 = bhead;
    while( bp1 -> next != NULL )
        bp1  = bp1 -> next;
    while( tolower(ch) =='y' )
    {
        bp2 = ( struct buyer *) malloc (sizeof(buyer));
        printf("\n�밴���¸�ʽ���룺\n");
        printf("������");
        getchar();
        gets( bp2 -> name );
        printf("ѧ�ţ�");
        gets( bp2 -> number );
        printf("���룺");
        gets( bp2 -> password );
        bp2 -> next = NULL;
        printf("\n ��ȷ����������[y/Y],�����������������");
        ch = getche();
        if( tolower(ch) == 'y' )
        {
            bp1 -> next = bp2;
            bp1 = bp2;
            bp2 = NULL;
            fp2 = fopen("buyers.txt", "w");
            bp1 = bhead;
            while( bp1 != NULL )
            {
                fprintf( fp2,"%s %s %s ", bp1 -> number, bp1 -> name, bp1 -> password );
                fprintf( fp2, "\n");
                bp1 = bp1 -> next;
            }
            free( bp1 );
            bp1 = NULL;
            printf("\nע����Ϣ�ɹ�����......�����������......");
            getch();
            putch( '\n' );
            break;
        }
        else
        {
            printf("\nע��ʧ�ܣ�����......�����������......");
            getch();
            putch( '\n' );
        }

    }
        bp1 = NULL;
        fclose( fp2 );
        return 0;
}
void registerseller()//����ע�ắ��
{
    chushihua();
    int i;
    char ch = 'y';
    sp1 = shead;
    while( sp1 -> next != NULL )
        sp1  = sp1 -> next;
    while( tolower(ch) =='y' )
    {
        sp2 = ( struct seller *) malloc (sizeof(seller));
        printf("\n�밴���¸�ʽ���룺\n");
        printf("ѧ�ţ�");
        getchar();
        gets( sp2 -> number );
        printf("������");
        gets( sp2 -> name );
        printf("���룺");
        gets( sp2 -> password );
        printf("�ֻ��ţ�");
        gets( sp2 -> telenumber );
        for ( i = 0; i < 5; i ++ )
            strcpy( sp2 -> name_of_goods[i] , "NULL" );
        sp2 -> next = NULL;
        printf("\n��ȷ����������[y/Y],�����������������");
        ch = getche();
        if( tolower(ch) == 'y' )
        {
            sp1 -> next = sp2;
            sp1 = sp2;
            sp2 = NULL;
            fp1 = fopen("sellers.txt", "w");
                sp1 = shead;
                while( sp1 != NULL )
                {
                    fprintf( fp1, "%s %s %s %s ", sp1 -> number, sp1 -> name, sp1 -> password, sp1 -> telenumber );
                    for ( i = 0; i < 5; i ++ )
                        fprintf( fp1, "%s ", sp1 -> name_of_goods[i] );
                    fprintf( fp1, "\n");
                    sp1 = sp1 -> next;
                }
                free( sp1 );
                fclose( fp1 );
            printf("\nע��ɹ�����......�����������......");
            getch();
            ch = 'a';
            putch( '\n' );
        }
        else
        {
            printf("\nע��ʧ�ܣ�����......�����������......");
            getch();
            ch = 'a';
            putch( '\n' );
        }

    }

}
int loginbuyer()//��ҵ�½����
{
	chushihua();
	int count=0;char name1[20];char password1[50];
	getchar();
	printf("\n�����������˻�����\n");
	gets(name1);
	buyer *a=bhead;
    while( a != NULL )
        {
            if( strcmp( name1, a -> name ) == 0)
                {
                    count ++;
                    break;
                }
            else
                a = a -> next;
        }
    if(count==0)
	{
		printf("��½ʧ�ܣ������˻�������\n");
		return 1;
	}
    printf("�������������룺\n");
    scanf("%s",password1);
    if( strcmp( password1, a -> password ) == 0)
    	{
    		printf("��½�ɹ���\n");
    		bp1 = a;
    		return 0;
		}
	else
		{
			printf("��½ʧ�ܣ������˻������벻ƥ��\n");
    		return 1;
    	}
}
int loginseller()//���ҵ�½����
{
	chushihua();
	int count=0;char name1[20];char password1[50];
	getchar();
	printf("\n�����������˻�����\n");
	gets(name1);
	seller *a=shead;
    while( a != NULL )
        {
            if( strcmp( name1, a -> name ) == 0)
                {
                    count ++;
                    break;
                }
            else
                a = a -> next;
        }
    if(count==0)
	{
		printf("��½ʧ�ܣ������˻�������\n");
		return 1;
	}
    printf("�������������룺\n");
    scanf("%s",password1);
    if( strcmp( password1, a -> password ) == 0)
    	{
    		printf("��½�ɹ���\n");
    		sp1 = a;
    		return 0;
		}
	else
		{
			printf("��½ʧ�ܣ������˻������벻ƥ��\n");
    		return 1;
    	}
}
void add_goods_of_seller()//���������Ʒ
{
	int ch,i;
	FILE *fp;
	goods *gp3;
	goods *g666=ghead;
	fp = fopen("goods.txt", "a");
	gp3 = ( goods *)malloc( sizeof(goods) );
	while(1){
	printf("������������Ʒ����Ϣ��\n");
	printf("��Ʒ�����֣�\n");
	scanf("%s",gp3->name);
	printf("��ѡ�����б�ǩ�е�һ����\n");
	printf("1.���ðٻ� 2.���ӻ�е 3.��ʷ�伮\n");
	scanf("%d",&ch);
	if(ch!=1&&ch!=2&&ch!=3)
		{
			printf("������� ����������\n");
			continue;
		}
	else
		{
			if(ch==1)
				strcpy (gp3->label,"���ðٻ�");
			else {
			if(ch==2)
				strcpy (gp3->label,"���ӻ�е");
			else
				strcpy (gp3->label,"��ʷ�伮");
				}
		}
	printf("��������Ʒ�۸�\n");
	scanf("%d",&gp3->price);
	gp3->wanted='N';
	strcpy( gp3 -> tele_of_seller, sp1 -> telenumber);
	for(i=0;i<5;i++)
	 {
		 if(strcmp(sp1->name_of_goods[i],"NULL")==0)
	 		{
	 			strcpy(sp1->name_of_goods[i],gp3->name);
	 			break;
            }
	 }

	if(i==5)
	 	{
	 		printf("�����˺���ӵ�е���Ʒ����" );
		 }
	else{	 
	fprintf(fp,"%s %s %c %s %d\n",gp3->name,gp3->label,gp3->wanted,gp3->tele_of_seller,gp3->price);//׷����goods.txt
	while(g666->next!=NULL)
	{
		g666=g666->next;
    }
	 g666->next=gp3;
	 gp3->next=NULL;} 
	fclose(fp);
	free(gp3); 
    break;

} 
}
void revise_of_sellers()//�����޸���Ʒ
{

    char newnumber[20], newname[20], newpassword[50], newtelenumber[15];
    char ch;
    int i, sh;
    while(1)
    {
        printf("\n����ԭʼ��Ϣ�ǣ�\n");
        printf(" %s %s %s %s\n", sp1 -> number, sp1 -> name, sp1 -> password, sp1 -> telenumber );
        for ( i = 0; i < 5; i ++ )
            printf( "%s ", sp1 -> name_of_goods[i] );
        printf("1.ѧ��  2.����  3.����  4.�绰����  5.��Ʒ\n");
        printf("��ѡ��");
        ch = getche();
        switch( ch )
        {
            case'1':printf("\n�������µ���Ϣ���س���������");
                    scanf( "%s", newnumber );
                    printf("�Ƿ�ȷ�ϣ�[y/n]");
                    ch = getche();
                    if( tolower(ch) == 'y')
                        strcpy( sp1 -> number, newnumber );
                    break;

            case'2':printf("\n�������µ���Ϣ���س���������");
                    scanf( "%s", newname );
                    printf("�Ƿ�ȷ�ϣ�[y/n]");
                    ch = getche();
                    if( tolower(ch) == 'y')
                        strcpy( sp1 -> name, newname );
                    break;

            case'3':printf("\n�������µ���Ϣ���س���������");
                    scanf( "%s", newpassword );
                    printf("�Ƿ�ȷ�ϣ�[y/n]");
                    ch = getche();
                    if( tolower(ch) == 'y')
                        strcpy( sp1 -> password, newpassword );
                    break;

            case'4':printf("\n�������µ���Ϣ���س���������");
                    scanf( "%s", newtelenumber );
                    printf("�Ƿ�ȷ�ϣ�[y/n]");
                    ch = getche();
                    if( tolower(ch) == 'y')
                    {
                        gp1 = ghead;
                        while( gp1 != NULL )
                        {
                            if( strcmp( gp1 -> tele_of_seller, sp1 -> telenumber ) == 0)
                                strcpy( gp1 -> tele_of_seller, newtelenumber );
                            gp1 = gp1 -> next;
                        }
                        strcpy( sp1 -> telenumber, newtelenumber );
                    }
                    break;
            case'5':printf("\n��ѡ��Ҫ�޸ĵ���Ʒ��ţ��س���������");
                    scanf( "%d", &sh );
                    change_info_of_goods( sh );
                    break;
            default: printf("\n����������������룺\n");
                    break;
            }
            printf("\n�����ٴ�ȷ��[y/n]");
            ch = getche();
            if( tolower(ch) == 'y')
            {
                printf("\n�޸ĳɹ���\n");
                printf("\n���޸ĺ����Ϣ�ǣ�\n");
                printf("%s %s %s %s ", sp1 -> number, sp1 -> name, sp1 -> password , sp1 -> telenumber );
                for ( i = 0; i < 5; i ++ )
                    printf( "%s ", sp1 -> name_of_goods[i] );
            }
            else
            {
                printf("\n�޸�ʧ�ܡ�\n");
            }
            break;
        }
}
void revise_of_buyers( )//����޸ĸ�����Ϣ
{

    char newnumber[20], newname[20],newpassword[50];
    char ch;
    int count = 0, i;

    while(1)
    {
        printf("\n����ԭʼ��Ϣ�ǣ�\n");
        printf(" %s %s %s\n", bp1 -> number, bp1 -> name, bp1 -> password );
        printf("1.ѧ��  2.����  3.����  \n");
        printf("��ѡ��");
        ch = getche();
        switch( ch )
        {
            case'1':printf("\n�������µ���Ϣ���س���������");
                    scanf( "%s", newnumber );
                    printf("�Ƿ�ȷ�ϣ�[y/n]");
                    ch = getche();
                    if( tolower(ch) == 'y')
                        strcpy( bp1 -> number, newnumber );
                    break;
            case'2':printf("\n�������µ���Ϣ���س���������");
                    scanf( "%s", newname );
                    printf("�Ƿ�ȷ�ϣ�[y/n]");
                    ch = getche();
                    if( tolower(ch) == 'y')
                        strcpy( bp1 -> name, newname );
                    break;

            case'3':printf("\n�������µ���Ϣ���س���������");
                    scanf( "%s", newpassword );
                    printf("�Ƿ�ȷ�ϣ�[y/n]");
                    ch = getche();
                    if( tolower(ch) == 'y')
                        strcpy( bp1 -> password, newpassword );
                    break;
            default: printf("\n����������������룺\n");
                    break;
        }
        if( tolower(ch) == 'y')
        {
            printf("\n�޸ĳɹ���\n");
            printf("\n���޸ĺ����Ϣ�ǣ�\n");
            printf(" %s %s %s", bp1 -> number, bp1 -> name, bp1 -> password );
        }
        else
        {
            printf("\n�޸�ʧ�ܡ�\n");
        }
        break;
    }
}
void search_of_sellers()//���Ҳ�ѯ�Լ���������Ʒ
{
	int flag=0;
	char *s0=sp1->name_of_goods[0];
	char *s1=sp1->name_of_goods[1];
	char *s2=sp1->name_of_goods[2];
	char *s3=sp1->name_of_goods[3];
	char *s4=sp1->name_of_goods[4];
	goods *g1=ghead;
	while(g1->next!=NULL)
		{
			if(strcmp(g1->name,s0)==0||strcmp(g1->name,s1)==0||strcmp(g1->name,s2)==0||strcmp(g1->name,s3)==0||strcmp(g1->name,s4)==0)
				{
					printf("��Ʒ����Ϊ��\t");
					printf("%s\n",g1->name);
					printf("��Ʒ������ǩΪ��\t");
					printf("%s\n",g1->label);
					printf("��Ʒ�Ƿ�������Ҫ��\t");
					printf("%c\n",g1->wanted);
					printf("��Ʒ�����绰Ϊ��\t");
					printf("%s\n",g1->tele_of_seller);
					printf("��Ʒ�ļ۸�Ϊ��\t");
					printf("%d\n\n",g1->price);
					g1=g1->next;
					flag=1;
				}
			else
				g1=g1->next;

		}
	if(strcmp(g1->name,s0)==0||strcmp(g1->name,s1)==0||strcmp(g1->name,s2)==0||strcmp(g1->name,s3)==0||strcmp(g1->name,s4)==0)
				{
					printf("��Ʒ����Ϊ��\t\t");
					printf("%s\n",g1->name);
					printf("��Ʒ������ǩΪ��\t");
					printf("%s\n",g1->label);
					printf("��Ʒ�Ƿ�������Ҫ��\t");
					printf("%c\n",g1->wanted);
					printf("��Ʒ�����绰Ϊ��\t");
					printf("%s\n",g1->tele_of_seller);
					printf("��Ʒ�ļ۸�Ϊ��\t\t");
					printf("%d\n\n",g1->price);
					g1=g1->next;
					flag=1;
				}
	if(flag==0)
			{
				printf("�����������е���Ʒ\n");
			}
}
void search_of_buyers()//��Ҳ�ѯ��Ʒ
{
	int flag1=0,flag2=0,flag3=0;
	goods *a=ghead;
	printf("����Ҫ�������͵���Ʒ��\n");
	printf("1.���ðٻ� 2.���ӻ�е 3.��ʷ�伮\n");
	int ch;
	scanf("%d",&ch);
	if(ch==1)
		{
			while(a->next!=NULL)
				{
					if(strcmp("���ðٻ�",a->label)==0)
						{
							printf("��Ʒ����:%s\n",a->name);
							printf("��Ʒ��ǩ:%s\n",a->label);
							printf("�Ƿ�������Ҫ����Ʒ:%c\n",a->wanted);
							printf("���ҵ绰Ϊ��%s\n",a->tele_of_seller);
							printf("��Ʒ�۸�:%d\n\n",a->price);
							a=a->next;
							flag1=1;
						}
					else
						a=a->next;
				}
					if(strcmp("���ðٻ�",a->label)==0)
						{
							printf("��Ʒ����:%s\n",a->name);
							printf("��Ʒ��ǩ:%s\n",a->label);
							printf("�Ƿ�������Ҫ����Ʒ:%c\n",a->wanted);
							printf("���ҵ绰Ϊ��%s\n",a->tele_of_seller);
							printf("��Ʒ�۸�:%d\n\n",a->price);
							flag1=1;
						}
					if(flag1==0)
						printf("�����ðٻ������Ʒ\n");
		}
	else if(ch==2)
		{
			while(a->next!=NULL)
				{
					if(strcmp("������е",a->label)==0)
						{
							printf("��Ʒ����:%s\n",a->name);
							printf("��Ʒ��ǩ:%s\n",a->label);
							printf("�Ƿ�������Ҫ����Ʒ:%c\n",a->wanted);
							printf("���ҵ绰Ϊ��%s\n",a->tele_of_seller);
							printf("��Ʒ�۸�:%d\n\n",a->price);
							a=a->next;
							flag2=1;
						}
					else
						a=a->next;
				}
					if(strcmp("���ӻ�е",a->label)==0)
						{
							printf("��Ʒ����:%s\n",a->name);
							printf("��Ʒ��ǩ:%s\n",a->label);
							printf("�Ƿ�������Ҫ����Ʒ:%c\n",a->wanted);
							printf("���ҵ绰Ϊ��%s\n",a->tele_of_seller);
							printf("��Ʒ�۸�:%d\n\n",a->price);
							flag2=1;
						}
					if(flag2==0)
						printf("�޵��ӻ�е�����Ʒ\n");
		}
	else if(ch==3)
		{
			while(a->next!=NULL)
				{
					if(strcmp("��ʷ�伮",a->label)==0)
						{
							printf("��Ʒ����:%s\n",a->name);
							printf("��Ʒ��ǩ:%s\n",a->label);
							printf("�Ƿ�������Ҫ����Ʒ:%c\n",a->wanted);
							printf("���ҵ绰Ϊ��%s\n",a->tele_of_seller);
							printf("��Ʒ�۸�:%d\n\n",a->price);
							a=a->next;
							flag3=1;
						}
					else
						a=a->next;
				}
					if(strcmp("��ʷ�伮",a->label)==0)
						{
							printf("��Ʒ����:%s\n",a->name);
							printf("��Ʒ��ǩ:%s\n",a->label);
							printf("�Ƿ�������Ҫ����Ʒ:%c\n",a->wanted);
							printf("���ҵ绰Ϊ��%s\n",a->tele_of_seller);
							printf("��Ʒ�۸�:%d\n\n",a->price);
							flag3=1;
						}
					if(flag3==0)
						printf("�޾�ʷ�伮�����Ʒ\n");
		}
	else
		printf("�޴˱�ǩ����Ʒ\n");
}
int delete_of_goods( )//����ɾ���Լ���������Ʒ
{
    int i;
    char name[100];
    char ch;
    while( 1 )
    {
        printf("\n�������ɾ����Ʒ�����֣����س���ȷ�ϣ���");
        getchar();
        gets( name );
        gp1 = ghead;
        gp2 = NULL;

        while( gp1 != NULL )
        {
            if( (strcmp( gp1 -> name, name ) == 0) && (strcmp( gp1 -> tele_of_seller, sp1 -> telenumber ) == 0) )
            {
                printf( "\n��Ҫɾ������Ʒ���ǣ�%s\n", gp1 -> name );
                printf("�����ٴ�ȷ��[y/Y]:");
                ch = getche();
                if( tolower(ch) == 'y' )
                {
                    if( gp1 == ghead )
                        ghead = ghead -> next;
                    else
                        gp2 -> next = gp1 -> next;
                    for( i = 0; i < 5; i ++ )
                        if( strcmp( sp1 -> name_of_goods[i], gp1 -> name ) == 0 )
                            strcpy( sp1 -> name_of_goods[i], "NULL" );
                    printf("ɾ���ɹ���");
                    break;
                }
            }
            else
            {
                gp2 = gp1;
                gp1 = gp1 -> next;
            }
        }

        if( gp1 == NULL)
        {
            printf("\n��������Ҫɾ������Ϣ���밴���������......\n");
            getch();
        }
        break;
    }
    return 1;
}
void change_info_of_goods( int sh )//������Ʒ��Ϣ
{
    char ch, newname[100], newlabel[50];
    int newprice, i;
    gp1 = ghead;
    printf("%s", sp1 -> name_of_goods[sh-1]);
    while( gp1 != NULL )
        {
            if( (strcmp( sp1 -> name_of_goods[sh-1], gp1 -> name ) == 0) && (strcmp( sp1 -> telenumber, gp1 -> tele_of_seller ) == 0) )
                break;
            else
                gp1 = gp1 -> next;
        }
    while(1)
    {
        printf("\n��ѡ������Ҫ�޸ĵ���Ϣ��\n");
        printf("1.����  2.��ǩ  3.�۸�  \n");
        printf("��ѡ��");
        ch = getche();
        switch( ch )
        {
            case'1':getchar();
                    printf("\n�������µ���Ϣ���س���������");
                    gets( newname );
                    printf("�Ƿ�ȷ�ϣ�[y/n]");
                    ch = getche();
                    if( tolower(ch) == 'y')
                        strcpy( gp1 -> name, newname );
                        strcpy( sp1 -> name_of_goods[sh-1], newname );
                    break;

            case'2':getchar();
                    printf("\n�������µ���Ϣ���س���������");
                    gets( newlabel );
                    printf("�Ƿ�ȷ�ϣ�[y/n]");
                    ch = getche();
                    if( tolower(ch) == 'y')
                        strcpy( gp1 -> label, newlabel );
                    break;

            case'3':getchar();
                    printf("\n�������µ���Ϣ���س���������");
                    scanf( "%d", &( newprice ) );
                    printf("�Ƿ�ȷ�ϣ�[y/n]");
                    ch = getche();
                    if( tolower(ch) == 'y')
                        gp1 -> price = newprice;
                    break;
            default: printf("\n����������������룺\n");
                    break;
        }
        break;
    }
}
void fprintf_of_sellers()//����Ϣд��sellers.txt
{
    int i;
    fp1 = fopen("sellers.txt", "w");
    sp1 = shead;
    while( sp1 != NULL )
    {
        fprintf( fp1, "%s %s %s %s ", sp1 -> number, sp1 -> name, sp1 -> password, sp1 -> telenumber );
        for ( i = 0; i < 5; i ++ )
            fprintf( fp1, "%s ", sp1 -> name_of_goods[i] );
        fprintf( fp1, "\n");
        sp1 = sp1 -> next;
    }
    fclose( fp1 );
    free( sp1 );
}
void fprintf_of_buyers()//����Ϣд��buyers.txt
{
    fp2 = fopen("buyers.txt", "w");
    bp1 = bhead;
    while( bp1 != NULL )
    {
        fprintf( fp2, "%s %s %s\n", bp1 -> number, bp1 -> name, bp1 -> password );
        bp1 = bp1 -> next;
    }
    fclose( fp2 );
    free( bp1 );
}
void fprintf_of_goods()//����Ϣд��goods.txt
{
    fp3 = fopen("goods.txt", "w");
    gp1 = ghead;
    while( gp1 != NULL )
    {
        fprintf( fp3, "%s %s %c %s %d\n", gp1 -> name, gp1 -> label, gp1 -> wanted, gp1 -> tele_of_seller, gp1 -> price );
        gp1 = gp1 -> next;
    }
    fclose( fp3 );
    free( gp1 );
}
