#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <malloc.h>
using namespace std;
#define INF 65535   //����һ���������Ϊ����ֵ
#define MAX 23
static int c_number=13;
static int k=0;
static	int v=0,z=0,r=0,t=0;
typedef struct jl
{
	int c_cost;
	int c_time;
	int f_cost;
	int f_time;
}jl;
jl  m[20],x[20],n[20];
typedef int costAdj[MAX+1][MAX+1];//ͼ�ڽӾ����1��ʼ����
int Path[MAX+1][MAX+1];//ͼ�ڽӾ����1��ʼ����
typedef struct unDiGraph
{
	int numVerts; //���
	costAdj cost; //�ڽӾ���
}unDiGraph,*UNG; //ͼ�Ķ���
typedef struct c_edit
{
char a[10];
}c_edit;
c_edit add[10];
costAdj B,L;
int pr(int i,int j)
{
	int h=0;
if (j==0) {
	h=i;
}
else if (j==1)
{
	cin>>add[i].a;
}
	switch(h)//����switch��䡣
	{
	case(0):cout<<"";
	break;
	case(1) : cout<<"�ɶ�   ";
        break;
    case(2) : cout<<"����   ";
		break;
    case(3) : cout<<"ʯ��ׯ   ";
		break;
    case(4) : cout<<"֣��   ";
		break;
    case(5) : cout<<"�人   ";
		break;
    case(6) : cout<<"����   ";
		break;
    case(7) : cout<<"��ɳ   ";
		break;
    case(8) : cout<<"����   ";
		break;
    case(9) : cout<<"����   ";
		break;
    case(10) : cout<<"����   ";
		break;
	case(11) : cout<<"����   ";
		break;
    case(12) : cout<<"���   ";
		break;
    case(13) : cout<<"�Ϻ�   ";
		break;
	default:
				cout<<add[i-13].a;
	}
	return 1;
}
//��������б���Ӧ����
void  pri()
{
	int i;
	cout<<"  ���м������"<<endl<<endl<<endl;
    cout<<"  *********************************************************"<<endl;
    for (i=1;i<=c_number;i++)
	{
	cout<<i<<".";
	pr(i,0);
	}
	cout<<endl<<"  *********************************************************"<<endl<<endl<<endl<<endl<<endl<<endl;
}
//�����Ȩ(����)ͼ  �����׵�ַG��
unDiGraph *CreateCostG(int o)//�𳵵Ļ��ѵĴ����ͱ༭����
{
	unDiGraph *G;
	int i,j;
	int a=0,b=0,f,h=1;
	if(!(G=(unDiGraph *)malloc(sizeof(unDiGraph))))   //ΪG����洢�ռ䡣
	{
		return(NULL);
	}
	for(i=1;i<c_number+1;i++)
	{
		for(j=1;j<c_number+1;j++)
		{
			G->cost[i][j]=INF; //��ʼ��ʹG->cost[i][j]Ϊ���
		}
	}
	G->numVerts=c_number;
	G->cost[1][6]=G->cost[6][1]=96;
	G->cost[1][2]=G->cost[2][1]=84;
	G->cost[2][3]=G->cost[3][2]=51;
	G->cost[3][4]=G->cost[4][3]=53;
	G->cost[4][5]=G->cost[5][4]=40;
	G->cost[5][6]=G->cost[6][5]=90;
	G->cost[5][8]=G->cost[8][5]=67;
	G->cost[5][7]=G->cost[7][5]=67;
	G->cost[6][7]=G->cost[7][6]=60;
	G->cost[7][9]=G->cost[9][7]=25;
	G->cost[3][11]=G->cost[11][3]=69;
	G->cost[11][12]=G->cost[12][11]=13;
	G->cost[12][10]=G->cost[10][12]=67;
	G->cost[3][10]=G->cost[10][3]=34;
	G->cost[13][10]=G->cost[10][13]=65;
	G->cost[13][5]=G->cost[5][13]=118;
	if (o) {
		while(h==1)
		{
		v=v+1;
		pri();
		cout<<"�𳵻��Ѳ�ѯ"<<endl;
		cout<<"�����뿪ʼ���е����ִ���"<<endl;
		cin>>a;
		cout<<"�������β���е����ִ���"<<endl;
		cin>>b;
		cout<<"��������Ԥ������ػ��ѽ��"<<endl;
		cin>>m[v].c_cost;
		n[v].c_cost=a;
		x[v].c_cost=b;
		cout<<"��ѡ��"<<endl;
		cout<<"****************---------------------********************"<<endl;
		cout<<"1���������ĳ��з���"<<endl;
		cout<<"0:������һ���˵�"<<endl;
		cout<<"****************---------------------********************"<<endl;
		cin>>h;
		switch(h) {
		case 1:
			h=1;
			break;
		case 0:
			h=0;
			break;
		default:{
			cout<<"ѡ�����"<<endl;
		}
		}
		}
	}
f=v+1;
while (v--) {
	G->cost[n[v].c_cost][x[v].c_cost]=m[v].c_cost;
}
v=f;
	return(G);

}
//�����Ȩ(ʱ��)ͼ  �����׵�ַG��
unDiGraph *CreateTimeG(int o)//�𳵵�ʱ��Ĵ����ͱ༭����
{
	unDiGraph *G;
	int i,j;
		int a=0,b=0,f,h=1;
	if(!(G=(unDiGraph *)malloc(sizeof(unDiGraph))))   //ΪG����洢�ռ䡣
	{
		return(NULL);
	}
	for(i=1;i<c_number+1;i++)
	{
		for(j=1;j<c_number+1;j++)
		{
			G->cost[i][j]=INF;//��ʼ��ʹG->cost[i][j]Ϊ���
		}
	}
	G->numVerts=c_number;
	G->cost[1][6]=G->cost[6][1]=9;
	G->cost[1][2]=G->cost[2][1]=8;
	G->cost[2][3]=G->cost[3][2]=5;
	G->cost[3][4]=G->cost[4][3]=5;
	G->cost[4][5]=G->cost[5][4]=4;
	G->cost[5][6]=G->cost[6][5]=9;
	G->cost[5][7]=G->cost[7][5]=6;
	G->cost[5][8]=G->cost[8][5]=6;
	G->cost[6][7]=G->cost[7][6]=6;
	G->cost[7][9]=G->cost[9][7]=2;
	G->cost[3][11]=G->cost[11][3]=6;
	G->cost[11][12]=G->cost[12][11]=1;
	G->cost[12][10]=G->cost[10][12]=6;
	G->cost[3][10]=G->cost[10][3]=3;
	G->cost[13][10]=G->cost[10][13]=6;
	G->cost[13][5]=G->cost[5][13]=11;
		if (o) {
		while(h==1)
		{
		z=z+1;
		pri();
		cout<<"��ʱ��Ԥ��༭"<<endl;
		cout<<"�����뿪ʼ���е����ִ���"<<endl;
		cin>>a;
		cout<<"�������β���е����ִ���"<<endl;
		cin>>b;
		cout<<"�������������ʱ��"<<endl;
		cin>>m[z].c_time;
		n[z].c_time=a;
		x[z].c_time=b;
		cout<<"��ѡ��"<<endl;
		cout<<"****************---------------------********************"<<endl;
		cout<<"1���������ĳ���ʱ��"<<endl;
		cout<<"0:������һ���˵�"<<endl;
		cout<<"****************---------------------********************"<<endl;
		cin>>h;
		switch(h) {
		case 1:
			h=1;
			break;
		case 0:
			h=0;
			break;
		default:{
			cout<<"ѡ�����BUG������"<<endl;
		}
		}
		}
	}
f=z+1;
while (z--) {
	G->cost[n[z].c_time][x[z].c_time]=m[z].c_time;
}
z=f;
	return(G);
}
unDiGraph *CreateTimeF(int o)//�ɻ���ʱ��Ĵ����ͱ༭����
{
	unDiGraph *G;
	int i,j;
		int a=0,b=0,f,h=1;
	if(!(G=(unDiGraph *)malloc(sizeof(unDiGraph))))   //ΪG����洢�ռ䡣
	{
		return(NULL);
	}
	for(i=1;i<c_number+1;i++)
	{
		for(j=1;j<c_number+1;j++)
		{
			G->cost[i][j]=INF;//��ʼ��ʹG->cost[i][j]Ϊ���
		}
	}
	G->numVerts=c_number;
	G->cost[1][6]=G->cost[6][1]=3;
	G->cost[1][2]=G->cost[2][1]=2;
	G->cost[2][3]=G->cost[3][2]=1;
	G->cost[3][4]=G->cost[4][3]=2;
	G->cost[4][5]=G->cost[5][4]=4;
	G->cost[5][6]=G->cost[6][5]=3;
	G->cost[5][7]=G->cost[7][5]=6;
	G->cost[5][8]=G->cost[8][5]=6;
	G->cost[6][7]=G->cost[7][6]=6;
	G->cost[7][9]=G->cost[9][7]=2;
	G->cost[3][11]=G->cost[11][3]=6;
	G->cost[11][12]=G->cost[12][11]=1;
	G->cost[12][10]=G->cost[10][12]=2;
	G->cost[3][10]=G->cost[10][3]=3;
	G->cost[13][10]=G->cost[10][13]=6;
	G->cost[13][5]=G->cost[5][13]=1;
		if (o) {
		while(h==1)
		{
		t=t+1;
		pri();
		cout<<"�ɻ�ʱ��༭"<<endl;
		cout<<"�����뿪ʼ���е����ִ���"<<endl;
		cin>>a;
		cout<<"�������β���е����ִ���"<<endl;
		cin>>b;
		cout<<"�������������ʱ��"<<endl;
		cin>>m[t].f_time;
		n[t].f_time=a;
		x[t].f_time=b;
		cout<<"��ѡ��"<<endl;
		cout<<"****************------------------------*****************"<<endl;
		cout<<"1���������ĳ���ʱ��"<<endl;
		cout<<"0:������һ���˵�"<<endl;
		cout<<"****************------------------------*****************"<<endl;
		cin>>h;
		switch(h) {
		case 1:
			h=1;
			break;
		case 0:
			h=0;
			break;
		default:{
			cout<<"ѡ�����BUG������"<<endl;
		}
		}
		}
	}
f=t+1;
while (t--) {
	G->cost[n[t].f_time][x[t].f_time]=m[t].f_time;
}
t=f;
	return(G);
}
unDiGraph *CreateCostF(int o)//�ɻ����ѵĴ����ͱ༭����
{
	unDiGraph *G;
	int i,j;
	int a=0,b=0,f,h=1;
	if(!(G=(unDiGraph *)malloc(sizeof(unDiGraph))))   //ΪG����洢�ռ䡣
	{
		return(NULL);
	}
	for(i=1;i<c_number+1;i++)
	{
		for(j=1;j<c_number+1;j++)
		{
			G->cost[i][j]=INF; //��ʼ��ʹG->cost[i][j]Ϊ���
		}
	}
	G->numVerts=c_number;
	G->cost[1][6]=G->cost[6][1]=960;
	G->cost[1][2]=G->cost[2][1]=840;
	G->cost[2][3]=G->cost[3][2]=501;
	G->cost[3][4]=G->cost[4][3]=530;
	G->cost[4][5]=G->cost[5][4]=400;
	G->cost[5][6]=G->cost[6][5]=900;
	G->cost[5][8]=G->cost[8][5]=670;
	G->cost[5][7]=G->cost[7][5]=670;
	G->cost[6][7]=G->cost[7][6]=600;
	G->cost[7][9]=G->cost[9][7]=200;
	G->cost[3][11]=G->cost[11][3]=690;
	G->cost[11][12]=G->cost[12][11]=310;
	G->cost[12][10]=G->cost[10][12]=670;
	G->cost[3][10]=G->cost[10][3]=340;
	G->cost[13][10]=G->cost[10][13]=650;
	G->cost[13][5]=G->cost[5][13]=1180;
	if (o) {
		while(h==1)
		{
		r=r+1;
		pri();
		cout<<"�ɻ����ѱ༭"<<endl;
		cout<<"�����뿪ʼ���е����ִ���"<<endl;
		cin>>a;
		cout<<"�������β���е����ִ���"<<endl;
		cin>>b;
		cout<<"������������ػ���"<<endl;
		cin>>m[r].f_cost;
		n[r].f_cost=a;
		x[r].f_cost=b;
		cout<<"��ѡ��"<<endl;
		cout<<"***************-----------------------*******************"<<endl;
		cout<<"1���������ĳ��з���"<<endl;
		cout<<"0:������һ���˵�"<<endl;
		cout<<"***************-----------------------*******************"<<endl;
		cin>>h;
		switch(h) {
		case 1:
			h=1;
			break;
		case 0:
			h=0;
			break;
		default:{
			cout<<"ѡ�����BUG!!!"<<endl;
		}
		}
		}
	}
f=r+1;
while (r--) {
	G->cost[n[r].f_cost][x[r].f_cost]=m[r].f_cost;
}
r=f;
	return(G);

}
 //Floyed���� ��������������·����
void Floyed(unDiGraph *D,unDiGraph *M)
{

	int i,j,k,n;
	costAdj A,C;
	n=c_number;
       for(i=1;i<=n;i++)
	   {
		for(j=1;j<=n;j++)
		{A[i][j]=D->cost[i][j];//��ʼ������A��
			C[i][j]=M->cost[i][j];
		    Path[i][j]=-1; 	//��ʼ������p,   ��-1.
		}
	   }
	   for(k=1;k<=n;k++)  //kΪ�𲽼�����м���
	   {
	    for(i=1;i<=n;i++)   //iΪA���к�
		{
				for(j=1;j<=n;j++)
					if(A[i][k]+A[k][j]<A[i][j])
					{A[i][j]=A[i][k]+A[k][j];
						C[i][j]=C[i][k]+C[k][j];
					     Path[i][j]=k;//��i����k��j��i��jС������A[i][j]=A[i][k]+A[k][j]��
						 B[i][j]=A[i][j];
							L[i][j]=C[i][j];
                    }
					else{
						B[i][j]=A[i][j];
						L[i][j]=C[i][j];
					}
		}
		}//end-for
        cout<<"\n���·��Ϊ:  "<<endl;
}///end-Floyed
//Ϊ�����i��j�����·����ֻ��Ҫ�������µĹ��̣�
void prn_pass(int i,int j)
{
	if(Path[i][j]!=-1)
	{
		  prn_pass(i,Path[i][j]);//������·�����������е�
		  pr(Path[i][j],0);
	}
}
//������ʱ��·����
void time()
{
	int Bcity,Ecity;//��ʼ���к�����յ���к���
   int l,h=1;
do {
       pri();//��������б���Ӧ���롣
    cout<<"��������ʼ���к�Ŀ�ĳ��е����ִ��룬�м䲢�Կո������^*^��Χ(1-- "<<c_number<<")";
       cin>>Bcity;
		   cin>>Ecity;//������ʼ���к��յ���еĴ��롣
	    if (!((0<Bcity&&Bcity<c_number+1)&&(0<Ecity&&Ecity<c_number+1)&&Bcity!=Ecity))
	   {
		cout<<"\n������!!!  ����������ֺ�������1-"<<c_number<<"֮�䣬�������в������!!"<<endl;
	   }
		Floyed(CreateTimeG(0),CreateCostG(0));//����Floyed������
		pr(Bcity,0);// ��ʾ��ʼ���С�
                prn_pass(Bcity,Ecity);//����prn_pass��������ʾ���·�������ĳ��С�
		pr(Ecity,0);//��ʾ�յ���С�
		if (B[Bcity][Ecity]>5000||L[Bcity][Ecity]>10000) {
				cout<<"���ؼ仹û����·ͨ��"<<endl;
			}
		else
		{
		cout<<"�𳵻��Ľ����"<<L[Bcity][Ecity]<<"Ԫ"<<endl;
		cout<<"�𳵻���ʱ����"<<B[Bcity][Ecity]<<"Сʱ"<<endl;
		}
	        printf("\n\n 1.�������ٻ��Ѳ���\n 2.�������˵�\n ��ѡ��...");
	                  scanf("%d",&l); //����1��2ѡ���Ƿ������
	            h=l;
		 } while(h==1);
    printf("\n");
}
void f_time()
{
	int Bcity,Ecity;//��ʼ���к�����յ���к���
   int l,h=1;
do {
       pri();//��������б���Ӧ���롣
    cout<<"��������ʼ���к�Ŀ�ĳ��еĴ��룬�м��Կո����^*^����Χ(1-- "<<c_number<<")";
       cin>>Bcity;
		   cin>>Ecity;//������ʼ���к��յ���еĴ��롣
	    if (!((0<Bcity&&Bcity<c_number+1)&&(0<Ecity&&Ecity<c_number+1)&&Bcity!=Ecity))
	   {
		cout<<"\n����BUG!!! "<<endl;
	   }

		Floyed(CreateTimeF(0),CreateCostF(0));//����Floyed������
		pr(Bcity,0);// ��ʾ��ʼ���С�
                prn_pass(Bcity,Ecity);//����prn_pass��������ʾ���·�������ĳ��С�
		pr(Ecity,0);//��ʾ�յ���С�
		if (B[Bcity][Ecity]>5000||L[Bcity][Ecity]>10000) {
				cout<<"���ؼ仹û����·ͨ��"<<endl;
			}
		else
		{
		cout<<"�ɻ����Ľ����"<<L[Bcity][Ecity]<<"Ԫ"<<endl;
		cout<<"�ɻ�����ʱ����"<<B[Bcity][Ecity]<<"Сʱ"<<endl;
		}
	        printf("\n\n 1.�������ٻ��Ѳ���\n 2.�������˵�\n ��ѡ��...");
	                  scanf("%d",&l); //����1��2ѡ���Ƿ������
	            h=l;
		 } while(h==1);
    printf("\n");
}
//�����ٻ���·����
void money()
{    int Bcity,Ecity;//��ʼ���к�����յ���к���
    char l,h=1;
	/*unDiGraph *G;*/
do {

	pri();//��������б���Ӧ���롣
cout<<"��������ʼ���к�Ŀ�ĳ��еĴ��룬�м��Կո��������Χ(1-- "<<c_number<<")";
            cin>>Bcity;
			cin>>Ecity;//������ʼ���к��յ���еĴ��롣
			if (!((0<Bcity&&Bcity<c_number+1)&&(0<Ecity&&Ecity<c_number+1)&&Bcity!=Ecity))
			{
			cout<<"\n����BUG!!! "<<endl;   //�������

			}

			Floyed(CreateCostG(0),CreateTimeG(0));//����Floyed������
			pr(Bcity,0);//��ʾ��ʼ���С�
			prn_pass(Bcity,Ecity);//����prn_pass��������ʾ���·�������ĳ��С�
			pr(Ecity,0);//��ʾ�յ���С�
			if (B[Bcity][Ecity]>5000||L[Bcity][Ecity]>10000) {
				cout<<"���ؼ仹û����·ͨ��"<<endl;
			}
			else
			{
			cout<<"�𳵻��Ľ����"<<B[Bcity][Ecity]<<"Ԫ"<<endl;
			cout<<"�𳵻���ʱ��"<<L[Bcity][Ecity]<<"Сʱ"<<endl;
         }
	        printf("\n\n 1.�������ٻ��Ѳ���\n 2.�������˵�\n ��ѡ��...");
	                  scanf("%d",&l); //����1��2ѡ���Ƿ������
	            h=l;
		 } while(h==1);
    printf("\n");
}
//��ɻ������
void f_money()
{
	cout<<"1"<<endl;
	int Bcity,Ecity;//��ʼ���к�����յ���к���
    char l,h=1;
	/*unDiGraph *G;*/
do {
	cout<<"2"<<endl;
	pri();//��������б���Ӧ���롣
	cout<<"��������ʼ���к�Ŀ�ĳ��еĴ��룬�м��Կո����^*^����Χ(1-- "<<c_number<<")";
            cin>>Bcity;
			cin>>Ecity;//������ʼ���к��յ���еĴ��롣
			if (!((0<Bcity&&Bcity<c_number+1)&&(0<Ecity&&Ecity<c_number+1)&&Bcity!=Ecity))
			{
			cout<<"\n����BUG!!!  "<<endl;   //�������

			}
			Floyed(CreateCostF(0),CreateTimeF(0));//����Floyed������
			pr(Bcity,0);//��ʾ��ʼ���С�
			prn_pass(Bcity,Ecity);//����prn_pass��������ʾ���·�������ĳ��С�
			pr(Ecity,0);//��ʾ�յ���С�
			if (B[Bcity][Ecity]>5000||L[Bcity][Ecity]>10000) {
				cout<<"���ؼ仹û����·ͨ��"<<endl;
			}
			else{
			cout<<"�ɻ����Ľ����"<<B[Bcity][Ecity]<<"Ԫ"<<endl;
			cout<<"�ɻ�����ʱ��"<<L[Bcity][Ecity]<<"Сʱ"<<endl;
         }
	        printf("\n\n 1.�������ٻ��Ѳ���\n 2.�������˵�\n ��ѡ��...");
	                  scanf("%d",&l); //����1��2ѡ���Ƿ������
	            h=l;
		 } while(h==1);
    printf("\n");
}
void add_city()//�Գ��е�����
{
	static int i=1;
	int j;
	cout<<"��������Ҫ���ӵĳ��еĸ���"<<endl;
	cin>>j;
	for (i=1;i<=j;i++)
	{
		cout<<"��������Ҫ���ӵĳ�����"<<endl;
		pr(i,1);
		c_number=c_number+1;
	}
cout<<"�����������"<<endl;
}
void chose_money()//������Ǯ���㷨
{
	int h;
	cout<<"1:��"<<endl;
	cout<<"2:�ɻ�"<<endl;
	cout<<"��ѡ��"<<endl;
	cin>>h;
	if (h==1) {
		money();
	}
	else
	{
		f_money();
	}
}
void chose_time()//������ʱ����㷨
{
	int h;
	cout<<"1:��"<<endl;
	cout<<"2:�ɻ�"<<endl;
	cout<<"��ѡ��"<<endl;
	cin>>h;
	if (h==1) {
		time();
	}
	else
	{
		f_time();
	}
}
void edit_line()//���ӱ༭�𳵵ķ���
{
	CreateCostG(1);
}
void edit_hour()//���ӱ༭�𳵵�ʱ��
{
	CreateTimeG(1);
}
void edit_fline()//���ӱ༭�ɻ��ķ���
{
	CreateCostF(1);
}
void edit_fhour()//���ӱ༭�ɻ���ʱ��
{
	CreateTimeF(1);
}
void administrator()//����Ա����
{
	int h=1;
	while (h) {
	cout<<"************************************************************"<<endl;
	cout<<"1:���ӳ���"<<endl;
	cout<<"2:��ӻ�༭�𳵷���"<<endl;
	cout<<"3:��ӻ�༭��ʱ��"<<endl;
	cout<<"4:��ӻ�༭�ɻ�����"<<endl;
	cout<<"5:��ӻ�༭�ɻ�ʱ��"<<endl;
	cout<<"0:�������˵�"<<endl;
	cout<<"************************************************************"<<endl;
	cout<<"��ѡ��"<<endl;
	cin>>h;
	switch(h) {
case 1 :add_city();
	break;
case 2:	edit_line();
	break;
case 3:edit_hour();
	break;
case 4:edit_fline();
	break;
case 5:edit_fhour();
	break;
case 0:
	h=0;
	break;
default:
	{
		cout<<"ѡ�����"<<endl;
	}
}
}
}
//������
int main()
{
	//�˻��Ի��������ã�����ѡ������������ʼ���к�����յ���к��� ���㽫����������Ҫ��
	 //���ʱ����������õ����·���ĳ��к��� ���ռ��ɵó�������Щ����
	char n;
	int x;
	while(x!=0)
	{
    cout<<endl;
	cout<<"������ϣ����ѯ��������룬�㽫�õ���ѷ���!"<<endl;
	cout<<"         **********************��ͨ��ѯϵͳ**********************"<<endl;
	cout<<"         *                         ���˵�                       *"<<endl;
	cout<<"         *                1.�鿴����                            *"<<endl;
	cout<<"         *                2.ѡ�����ʱ��·��                    *"<<endl;
	cout<<"         *                3.ѡ�����Լ����·��                  *"<<endl;
	cout<<"         *                4.����Ա����                          *"<<endl;
	cout<<"         *                0.�˳�����                            *"<<endl;
	cout<<"         ********************************************************"<<endl;

    cout<<endl<<endl<<endl<<endl<<endl;
	cout<<"��ѡ��0-4��.....  ";//����ѡ��˵���
    cin>>n ;
	switch(n)//������Ϊ0-4������switch������ѡ��
		{
	case '1': pri();//�鿴����
		break;
	      case '2' : chose_time(); //������Ϊ1�������time������
		break;
		  case '3' : chose_money();//������Ϊ2�������money������
            break;
		  case '4':administrator();
			  break;
          case '0'://������Ϊ3����ȷ���˳���
			  x=0;
			break;
	    default :
			{
				cout<<endl<<"����BUG!!!����0-4֮��ѡ��!!"<<endl<<endl;   //�������
			}
        }//end-Switch
	}
	return 0;
}
