#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <malloc.h>
using namespace std;
#define INF 65535   //定义一个最大数定为无穷值
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
typedef int costAdj[MAX+1][MAX+1];//图邻接矩阵从1开始记数
int Path[MAX+1][MAX+1];//图邻接矩阵从1开始记数
typedef struct unDiGraph
{
	int numVerts; //结点
	costAdj cost; //邻接矩阵
}unDiGraph,*UNG; //图的定义
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
	switch(h)//运用switch语句。
	{
	case(0):cout<<"";
	break;
	case(1) : cout<<"成都   ";
        break;
    case(2) : cout<<"兰州   ";
		break;
    case(3) : cout<<"石家庄   ";
		break;
    case(4) : cout<<"郑州   ";
		break;
    case(5) : cout<<"武汉   ";
		break;
    case(6) : cout<<"贵阳   ";
		break;
    case(7) : cout<<"长沙   ";
		break;
    case(8) : cout<<"广州   ";
		break;
    case(9) : cout<<"南宁   ";
		break;
    case(10) : cout<<"济南   ";
		break;
	case(11) : cout<<"北京   ";
		break;
    case(12) : cout<<"天津   ";
		break;
    case(13) : cout<<"上海   ";
		break;
	default:
				cout<<add[i-13].a;
	}
	return 1;
}
//输出城市列表及相应代码
void  pri()
{
	int i;
	cout<<"  城市及其代码"<<endl<<endl<<endl;
    cout<<"  *********************************************************"<<endl;
    for (i=1;i<=c_number;i++)
	{
	cout<<i<<".";
	pr(i,0);
	}
	cout<<endl<<"  *********************************************************"<<endl<<endl<<endl<<endl<<endl<<endl;
}
//构造带权(费用)图  返回首地址G：
unDiGraph *CreateCostG(int o)//火车的花费的存贮和编辑功能
{
	unDiGraph *G;
	int i,j;
	int a=0,b=0,f,h=1;
	if(!(G=(unDiGraph *)malloc(sizeof(unDiGraph))))   //为G分配存储空间。
	{
		return(NULL);
	}
	for(i=1;i<c_number+1;i++)
	{
		for(j=1;j<c_number+1;j++)
		{
			G->cost[i][j]=INF; //初始化使G->cost[i][j]为无穷。
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
		cout<<"火车花费查询"<<endl;
		cout<<"请输入开始城市的数字代码"<<endl;
		cin>>a;
		cout<<"请输入结尾城市的数字代码"<<endl;
		cin>>b;
		cout<<"请输入你预算的两地花费金额"<<endl;
		cin>>m[v].c_cost;
		n[v].c_cost=a;
		x[v].c_cost=b;
		cout<<"请选择"<<endl;
		cout<<"****************---------------------********************"<<endl;
		cout<<"1：继续更改城市费用"<<endl;
		cout<<"0:返回上一级菜单"<<endl;
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
			cout<<"选择出错"<<endl;
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
//构造带权(时间)图  返回首地址G：
unDiGraph *CreateTimeG(int o)//火车的时间的存贮和编辑功能
{
	unDiGraph *G;
	int i,j;
		int a=0,b=0,f,h=1;
	if(!(G=(unDiGraph *)malloc(sizeof(unDiGraph))))   //为G分配存储空间。
	{
		return(NULL);
	}
	for(i=1;i<c_number+1;i++)
	{
		for(j=1;j<c_number+1;j++)
		{
			G->cost[i][j]=INF;//初始化使G->cost[i][j]为无穷。
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
		cout<<"火车时间预算编辑"<<endl;
		cout<<"请输入开始城市的数字代码"<<endl;
		cin>>a;
		cout<<"请输入结尾城市的数字代码"<<endl;
		cin>>b;
		cout<<"请输入你的两地时间"<<endl;
		cin>>m[z].c_time;
		n[z].c_time=a;
		x[z].c_time=b;
		cout<<"请选择"<<endl;
		cout<<"****************---------------------********************"<<endl;
		cout<<"1：继续更改城市时间"<<endl;
		cout<<"0:返回上一级菜单"<<endl;
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
			cout<<"选择出现BUG！！！"<<endl;
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
unDiGraph *CreateTimeF(int o)//飞机的时间的存贮和编辑功能
{
	unDiGraph *G;
	int i,j;
		int a=0,b=0,f,h=1;
	if(!(G=(unDiGraph *)malloc(sizeof(unDiGraph))))   //为G分配存储空间。
	{
		return(NULL);
	}
	for(i=1;i<c_number+1;i++)
	{
		for(j=1;j<c_number+1;j++)
		{
			G->cost[i][j]=INF;//初始化使G->cost[i][j]为无穷。
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
		cout<<"飞机时间编辑"<<endl;
		cout<<"请输入开始城市的数字代码"<<endl;
		cin>>a;
		cout<<"请输入结尾城市的数字代码"<<endl;
		cin>>b;
		cout<<"请输入你的两地时间"<<endl;
		cin>>m[t].f_time;
		n[t].f_time=a;
		x[t].f_time=b;
		cout<<"请选择"<<endl;
		cout<<"****************------------------------*****************"<<endl;
		cout<<"1：继续更改城市时间"<<endl;
		cout<<"0:返回上一级菜单"<<endl;
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
			cout<<"选择出现BUG！！！"<<endl;
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
unDiGraph *CreateCostF(int o)//飞机花费的存贮和编辑功能
{
	unDiGraph *G;
	int i,j;
	int a=0,b=0,f,h=1;
	if(!(G=(unDiGraph *)malloc(sizeof(unDiGraph))))   //为G分配存储空间。
	{
		return(NULL);
	}
	for(i=1;i<c_number+1;i++)
	{
		for(j=1;j<c_number+1;j++)
		{
			G->cost[i][j]=INF; //初始化使G->cost[i][j]为无穷。
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
		cout<<"飞机花费编辑"<<endl;
		cout<<"请输入开始城市的数字代码"<<endl;
		cin>>a;
		cout<<"请输入结尾城市的数字代码"<<endl;
		cin>>b;
		cout<<"请输入你的两地花费"<<endl;
		cin>>m[r].f_cost;
		n[r].f_cost=a;
		x[r].f_cost=b;
		cout<<"请选择"<<endl;
		cout<<"***************-----------------------*******************"<<endl;
		cout<<"1：继续更改城市费用"<<endl;
		cout<<"0:返回上一级菜单"<<endl;
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
			cout<<"选择出现BUG!!!"<<endl;
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
 //Floyed函数 求任意两点的最短路径：
void Floyed(unDiGraph *D,unDiGraph *M)
{

	int i,j,k,n;
	costAdj A,C;
	n=c_number;
       for(i=1;i<=n;i++)
	   {
		for(j=1;j<=n;j++)
		{A[i][j]=D->cost[i][j];//初始化矩阵A。
			C[i][j]=M->cost[i][j];
		    Path[i][j]=-1; 	//初始化矩阵p,   置-1.
		}
	   }
	   for(k=1;k<=n;k++)  //k为逐步加入的中间结点
	   {
	    for(i=1;i<=n;i++)   //i为A中行号
		{
				for(j=1;j<=n;j++)
					if(A[i][k]+A[k][j]<A[i][j])
					{A[i][j]=A[i][k]+A[k][j];
						C[i][j]=C[i][k]+C[k][j];
					     Path[i][j]=k;//若i经过k到j比i到j小，则令A[i][j]=A[i][k]+A[k][j]。
						 B[i][j]=A[i][j];
							L[i][j]=C[i][j];
                    }
					else{
						B[i][j]=A[i][j];
						L[i][j]=C[i][j];
					}
		}
		}//end-for
        cout<<"\n最短路径为:  "<<endl;
}///end-Floyed
//为了求从i到j的最短路径，只需要调用如下的过程：
void prn_pass(int i,int j)
{
	if(Path[i][j]!=-1)
	{
		  prn_pass(i,Path[i][j]);//输出最短路径经过的所有点
		  pr(Path[i][j],0);
	}
}
//求最少时间路径。
void time()
{
	int Bcity,Ecity;//起始成市号码和终点城市号码
   int l,h=1;
do {
       pri();//输出城市列表及相应代码。
    cout<<"请输入起始城市和目的城市的数字代码，中间并以空格隔开，^*^范围(1-- "<<c_number<<")";
       cin>>Bcity;
		   cin>>Ecity;//输入起始城市和终点城市的代码。
	    if (!((0<Bcity&&Bcity<c_number+1)&&(0<Ecity&&Ecity<c_number+1)&&Bcity!=Ecity))
	   {
		cout<<"\n出错啦!!!  输入城市数字号码请在1-"<<c_number<<"之间，且两城市不能相等!!"<<endl;
	   }
		Floyed(CreateTimeG(0),CreateCostG(0));//调用Floyed函数。
		pr(Bcity,0);// 显示起始城市。
                prn_pass(Bcity,Ecity);//调用prn_pass函数，显示最短路径经过的城市。
		pr(Ecity,0);//显示终点城市。
		if (B[Bcity][Ecity]>5000||L[Bcity][Ecity]>10000) {
				cout<<"两地间还没有线路通过"<<endl;
			}
		else
		{
		cout<<"火车花的金额是"<<L[Bcity][Ecity]<<"元"<<endl;
		cout<<"火车花的时间是"<<B[Bcity][Ecity]<<"小时"<<endl;
		}
	        printf("\n\n 1.继续最少花费查找\n 2.返回主菜单\n 清选择...");
	                  scanf("%d",&l); //输入1或2选择是否继续。
	            h=l;
		 } while(h==1);
    printf("\n");
}
void f_time()
{
	int Bcity,Ecity;//起始成市号码和终点城市号码
   int l,h=1;
do {
       pri();//输出城市列表及相应代码。
    cout<<"请输入起始城市和目的城市的代码，中间以空格隔开^*^，范围(1-- "<<c_number<<")";
       cin>>Bcity;
		   cin>>Ecity;//输入起始城市和终点城市的代码。
	    if (!((0<Bcity&&Bcity<c_number+1)&&(0<Ecity&&Ecity<c_number+1)&&Bcity!=Ecity))
	   {
		cout<<"\n出现BUG!!! "<<endl;
	   }

		Floyed(CreateTimeF(0),CreateCostF(0));//调用Floyed函数。
		pr(Bcity,0);// 显示起始城市。
                prn_pass(Bcity,Ecity);//调用prn_pass函数，显示最短路径经过的城市。
		pr(Ecity,0);//显示终点城市。
		if (B[Bcity][Ecity]>5000||L[Bcity][Ecity]>10000) {
				cout<<"两地间还没有线路通过"<<endl;
			}
		else
		{
		cout<<"飞机花的金额是"<<L[Bcity][Ecity]<<"元"<<endl;
		cout<<"飞机花的时间是"<<B[Bcity][Ecity]<<"小时"<<endl;
		}
	        printf("\n\n 1.继续最少花费查找\n 2.返回主菜单\n 清选择...");
	                  scanf("%d",&l); //输入1或2选择是否继续。
	            h=l;
		 } while(h==1);
    printf("\n");
}
//求最少花费路径。
void money()
{    int Bcity,Ecity;//起始成市号码和终点城市号码
    char l,h=1;
	/*unDiGraph *G;*/
do {

	pri();//输出城市列表及相应代码。
cout<<"请输入起始城市和目的城市的代码，中间以空格隔开，范围(1-- "<<c_number<<")";
            cin>>Bcity;
			cin>>Ecity;//输入起始城市和终点城市的代码。
			if (!((0<Bcity&&Bcity<c_number+1)&&(0<Ecity&&Ecity<c_number+1)&&Bcity!=Ecity))
			{
			cout<<"\n出现BUG!!! "<<endl;   //输入出错

			}

			Floyed(CreateCostG(0),CreateTimeG(0));//调用Floyed函数。
			pr(Bcity,0);//显示起始城市。
			prn_pass(Bcity,Ecity);//调用prn_pass函数，显示最短路径经过的城市。
			pr(Ecity,0);//显示终点城市。
			if (B[Bcity][Ecity]>5000||L[Bcity][Ecity]>10000) {
				cout<<"两地间还没有线路通过"<<endl;
			}
			else
			{
			cout<<"火车花的金额是"<<B[Bcity][Ecity]<<"元"<<endl;
			cout<<"火车花的时间"<<L[Bcity][Ecity]<<"小时"<<endl;
         }
	        printf("\n\n 1.继续最少花费查找\n 2.返回主菜单\n 清选择...");
	                  scanf("%d",&l); //输入1或2选择是否继续。
	            h=l;
		 } while(h==1);
    printf("\n");
}
//求飞机的情况
void f_money()
{
	cout<<"1"<<endl;
	int Bcity,Ecity;//起始成市号码和终点城市号码
    char l,h=1;
	/*unDiGraph *G;*/
do {
	cout<<"2"<<endl;
	pri();//输出城市列表及相应代码。
	cout<<"请输入起始城市和目的城市的代码，中间以空格隔开^*^，范围(1-- "<<c_number<<")";
            cin>>Bcity;
			cin>>Ecity;//输入起始城市和终点城市的代码。
			if (!((0<Bcity&&Bcity<c_number+1)&&(0<Ecity&&Ecity<c_number+1)&&Bcity!=Ecity))
			{
			cout<<"\n出现BUG!!!  "<<endl;   //输入出错

			}
			Floyed(CreateCostF(0),CreateTimeF(0));//调用Floyed函数。
			pr(Bcity,0);//显示起始城市。
			prn_pass(Bcity,Ecity);//调用prn_pass函数，显示最短路径经过的城市。
			pr(Ecity,0);//显示终点城市。
			if (B[Bcity][Ecity]>5000||L[Bcity][Ecity]>10000) {
				cout<<"两地间还没有线路通过"<<endl;
			}
			else{
			cout<<"飞机花的金额是"<<B[Bcity][Ecity]<<"元"<<endl;
			cout<<"飞机花的时间"<<L[Bcity][Ecity]<<"小时"<<endl;
         }
	        printf("\n\n 1.继续最少花费查找\n 2.返回主菜单\n 清选择...");
	                  scanf("%d",&l); //输入1或2选择是否继续。
	            h=l;
		 } while(h==1);
    printf("\n");
}
void add_city()//对城市的增加
{
	static int i=1;
	int j;
	cout<<"请输入你要增加的城市的个数"<<endl;
	cin>>j;
	for (i=1;i<=j;i++)
	{
		cout<<"请输入你要增加的城市名"<<endl;
		pr(i,1);
		c_number=c_number+1;
	}
cout<<"城市增加完毕"<<endl;
}
void chose_money()//花最少钱的算法
{
	int h;
	cout<<"1:火车"<<endl;
	cout<<"2:飞机"<<endl;
	cout<<"请选择："<<endl;
	cin>>h;
	if (h==1) {
		money();
	}
	else
	{
		f_money();
	}
}
void chose_time()//花最少时间的算法
{
	int h;
	cout<<"1:火车"<<endl;
	cout<<"2:飞机"<<endl;
	cout<<"请选择："<<endl;
	cin>>h;
	if (h==1) {
		time();
	}
	else
	{
		f_time();
	}
}
void edit_line()//增加编辑火车的费用
{
	CreateCostG(1);
}
void edit_hour()//增加编辑火车的时间
{
	CreateTimeG(1);
}
void edit_fline()//增加编辑飞机的费用
{
	CreateCostF(1);
}
void edit_fhour()//增加编辑飞机的时间
{
	CreateTimeF(1);
}
void administrator()//管理员功能
{
	int h=1;
	while (h) {
	cout<<"************************************************************"<<endl;
	cout<<"1:增加城市"<<endl;
	cout<<"2:添加或编辑火车费用"<<endl;
	cout<<"3:添加或编辑火车时间"<<endl;
	cout<<"4:添加或编辑飞机费用"<<endl;
	cout<<"5:添加或编辑飞机时间"<<endl;
	cout<<"0:返回主菜单"<<endl;
	cout<<"************************************************************"<<endl;
	cout<<"请选择"<<endl;
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
		cout<<"选择出错！"<<endl;
	}
}
}
}
//主函数
int main()
{
	//人机对话界面设置，输入选项，再输入你的起始成市号码和终点城市号码 ，你将被给出你所要的
	 //最短时间或最消费用的最佳路径的城市号码 对照即可得出经过哪些城市
	char n;
	int x;
	while(x!=0)
	{
    cout<<endl;
	cout<<"输入你希望查询的种类代码，你将得到最佳方案!"<<endl;
	cout<<"         **********************交通咨询系统**********************"<<endl;
	cout<<"         *                         主菜单                       *"<<endl;
	cout<<"         *                1.查看城市                            *"<<endl;
	cout<<"         *                2.选择最短时间路线                    *"<<endl;
	cout<<"         *                3.选择最节约费用路线                  *"<<endl;
	cout<<"         *                4.管理员程序                          *"<<endl;
	cout<<"         *                0.退出程序                            *"<<endl;
	cout<<"         ********************************************************"<<endl;

    cout<<endl<<endl<<endl<<endl<<endl;
	cout<<"请选择（0-4）.....  ";//输入选择菜单。
    cin>>n ;
	switch(n)//当输入为0-4，则用switch语句进行选择。
		{
	case '1': pri();//查看城市
		break;
	      case '2' : chose_time(); //当输入为1，则调用time函数。
		break;
		  case '3' : chose_money();//当输入为2，则调用money函数。
            break;
		  case '4':administrator();
			  break;
          case '0'://当输入为3。则确认退出。
			  x=0;
			break;
	    default :
			{
				cout<<endl<<"出现BUG!!!请在0-4之间选择!!"<<endl<<endl;   //输入出错
			}
        }//end-Switch
	}
	return 0;
}
