#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<fstream>
#include<iomanip>
#include <conio.h>
using namespace std;

#define NN 100    
int nn = 0;       /*   nn对应实际职工人数   */
char zhiwu[8][10] = { "无职务","初级","行政八级","行政七级","行政六级","行政五级","行政四级","行政三级" };
int m_wu[8] = { 0,100,150,200,300,450,700,1100 };
char zhicheng[13][12] = { "无职称","初级初等","初级中等","初级高等","中级初等","中级中等","中级高等","副高级初等","副高级中等","副高级高等","高级初等","高级中等","高级高等" };
int m_cheng[13] = { 0,50,70,90,150,220,290,400,550,700,1200,2000,3000 };

class employee {
public:
	char code[8];/*工号*/
	char name[20];/*姓名*/
	float jiben;/*基本工资*/
	float jiang;/*奖金*/
	float kou;/*扣款*/
	char leibie[6];/*人员类别*/
	float mzwu;/*职务工资*/
	float mzcheng;/*职称工资*/
	float yingfa;/*应发工资*/
	float shifa;/*实发工资*/
	float shui;/*税款*/
}p[NN];

void Read_file();       /* -- 数据读入模块 -- */
void Append();          /* --  从键盘追加数据  -- */
void File_add();        /* --   从文件追加数据  -- */
float Get_v(char* num);
void Find();            /* --  查找模块   -- */
void Brow();            /* --  浏览模块   -- */
void Chng();            /* --   修改模块  -- */
void Calt();            /* --  计算模块   -- */
void Stcs();            /* --   统计模块   -- */
void Writ_file();       /* -- 数据保存模块 -- */
void menu();               /* -- 菜单 -- */

void main() {
	Read_file();//读工资信息文件
	menu();
	Writ_file();//写文件
}

void Read_file() {
	ifstream in("zgxx.txt");         /*读入文件*/
	if (in) {
		int zw = 0;                 /*初始化*/
		int zc = 0;                 /*初始化*/
		while (!in.eof()) {
			{
				in >> p[nn].code >> p[nn].name >> p[nn].jiben >> p[nn].jiang >> p[nn].kou >> p[nn].leibie >> zw >> zc;
				p[nn].mzwu = m_wu[zw];
				p[nn].mzcheng = m_cheng[zc];
				if (strcmp(p[nn].leibie, "行政") == 0) p[nn].mzcheng = 0.3 * p[nn].mzcheng;
				if (strcmp(p[nn].leibie, "技术") == 0) p[nn].mzwu = 0.3 * p[nn].mzwu;

				p[nn].yingfa = p[nn].jiben + p[nn].jiang + p[nn].mzwu + p[nn].mzcheng;/*应发工资的计算式*/

				if (p[nn].yingfa <= 2000)p[nn].shui = 0;
				else if (p[nn].yingfa <= 8000)p[nn].shui = (p[nn].yingfa - 2000) * 0.05;
				else p[nn].shui = 300 + (p[nn].yingfa - 8000) * 0.1;
				p[nn].shifa = p[nn].yingfa - p[nn].shui - p[nn].kou;
				nn++;
			}
		}
		nn--;
		in.close();
	}
}

void File_add() {
	int zw, zc;
	char fname[20];
	cout << "请输入含有要添加职工信息的数据文件名（包括拓展名）......" << endl;
	cin >> fname;
	ifstream in(fname);
	if (in) {
		while (!in.eof()) {
			{
				in >> p[nn].code >> p[nn].name >> p[nn].jiben >> p[nn].jiang >> p[nn].kou >> p[nn].leibie >> zw >> zc;

				ofstream outfile("zgxx.txt", ios::app);/*追加方式打开文件夹*/

				if (outfile) {
					outfile << p[nn].code << "   " << p[nn].name << "   " << p[nn].jiben << "   " << p[nn].jiang << "   " << p[nn].kou << "   " << p[nn].leibie << "   " << zw << "   " << zc << '\n';
					outfile.close();
					p[nn].mzwu = m_wu[zw];
					p[nn].mzcheng = m_cheng[zc];
					if (strcmp(p[nn].leibie, "行政") == 0) p[nn].mzcheng = 0.3 * p[nn].mzcheng;
					if (strcmp(p[nn].leibie, "技术") == 0) p[nn].mzwu = 0.3 * p[nn].mzwu;
					p[nn].yingfa = p[nn].jiben + p[nn].jiang + p[nn].mzwu + p[nn].mzcheng;
					if (p[nn].yingfa <= 2000)p[nn].shui = 0;
					else if (p[nn].yingfa <= 8000)p[nn].shui = (p[nn].yingfa - 2000) * 0.05;
					else p[nn].shui = 300 + (p[nn].yingfa - 8000) * 0.1;
					p[nn].shifa = p[nn].yingfa - p[nn].shui - p[nn].kou;
					nn++;
				}
			}
		}
		nn--;
		in.close();
	}
}//从文件中新增数据的方式

/***************************从键盘追加一个职工的信息*****************************/
void Append() {
	int z1, z2, i;
	fflush(stdin);
	cout << "请输入你想输入员工的基本信息" << endl;
	cout << "工号" << endl;
	cin >> p[nn].code;
	cout << "姓名" << endl;
	cin >> p[nn].name;
	cout << "基本工资" << endl;
	cin >> p[nn].jiben;
	cout << "奖金" << endl;
	cin >> p[nn].jiang;
	cout << "扣款" << endl;
	cin >> p[nn].kou;

	do {
		cout << "请输入人员类别代码1或2 :1-行政人员，2-技术人员" << endl;
		cin >> z1;
		if (z1 == 1)strcpy(p[nn].leibie, "行政");
		else if (z1 == 2)strcpy(p[nn].leibie, "技术");
	} while (z1 < 1 || z1>2);
	do {
		cout << "请输入0-7表示职务" << endl;
		for (i = 0; i < 4; i++) {
			cout << i << zhiwu[i];
		}
		cout << "" << endl;
		for (i = 4; i < 8; i++) {
			cout << i << zhiwu[i];
		}
		cout << " " << endl;
		cin >> z1;
		fflush(stdin);
	} while (z1 > 7 || z1 < 0);
	p[nn].mzwu = m_wu[z1];

	do {
		cout << " 请输入数字 0 到 12 表示职称" << endl;
		for (i = 0; i < 4; i++)
			cout << i << zhicheng[i] << endl;
		for (i = 4; i < 8; i++)
			cout << i << zhicheng[i] << endl;
		for (i = 8; i < 13; i++)
			cout << i << zhicheng[i] << endl;
		cout << " " << endl;
		cin >> z2;
		fflush(stdin);
	} while (z2 > 12 || z2 < 0);

	p[nn].mzcheng = m_cheng[z2];

	if (strcmp(p[nn].leibie, "行政") == 0) p[nn].mzcheng = 0.3 * p[nn].mzcheng;
	if (strcmp(p[nn].leibie, "技术") == 0) p[nn].mzwu = 0.3 * p[nn].mzwu;
	p[nn].yingfa = p[nn].jiben + p[nn].jiang + p[nn].mzwu + p[nn].mzcheng;
	if (p[nn].yingfa <= 2000)p[nn].shui = 0;
	else if (p[nn].yingfa <= 8000)p[nn].shui = (p[nn].yingfa - 2000) * 0.05;
	else p[nn].shui = 300 + (p[nn].yingfa - 8000) * 0.1;
	p[nn].shifa = p[nn].yingfa - p[nn].shui - p[nn].kou;
	i = nn;
	nn++;
	cout << "新增加职工的相关信息如下:" << endl;
	cout << "  工号   姓名  基本工资  奖金    类别    扣款   职  务   职  称" << endl;;
	cout << "   " << p[i].code << "   " << p[i].name << "   " << p[i].jiben << "   " << p[i].jiang << "   " << p[i].leibie << "   " << p[i].kou << "   " << zhiwu[z1] << "   " << zhicheng[z2];

	ofstream outfile("zgxx.txt", ios::app);/*以追加方式打开*/

	if (outfile) {
		outfile << '\n' << p[i].code << "   " << p[i].name << "   " << p[i].jiben << "   " << p[i].jiang << "   " << p[i].kou << "   " << p[i].leibie << "   " << z1 << "   " << z2 << endl;
	}
	outfile.close();
}

void Chng() {
	char str[20];
	char num[10], c1;
	float value;
	int i, k = -1, fd = 0;
	fflush(stdin);
	cout << "请输入你想修改数据职工的工号或者姓名" << endl;
	cin >> str;
	for (i = 0; i <= nn; i++)
		if ((strcmp(p[i].code, str)) == 0 || (strcmp(p[i].name, str) == 0)) {
			fd = 1;
			k = i;
			break;
		}
	if (k == -1)cout << "对不起，没有找到此人，请核对后在输入";
	else {
		cout << "原始数据如下" << endl;
		cout << "工号" << " " << "姓名" << endl;
		cout << p[i].code << "" << p[i].name << endl;
		cout << "原基本工资为" << p[i].jiben << "请输入新值，不改则按回车" << endl;
		fgets(num, 19, stdin);
		c1 = num[0];
		if (isxdigit(c1))
			p[i].jiben = Get_v(num);
		cout << "原奖金为" << p[i].jiang << "请输入新值不改则按回车" << endl;
		fgets(num, 19, stdin);
		c1 = num[0];
		if (isxdigit(c1))
			p[i].jiang = Get_v(num);
		cout << "原扣款为" << p[i].kou << "请输入新值不改则按回车" << endl;
		fgets(num, 19, stdin);
		c1 = num[0];
		if (isxdigit(c1))
			p[i].kou = Get_v(num);
		cout << "修改后的基本信息如下" << endl;
		cout << "  工号   姓名  基本工资  奖金  类别      扣款" << endl;;
		cout << "   " << p[i].code << "   " << p[i].name << "   " << p[i].jiben << "   " << p[i].jiang << "   " << p[i].leibie << "   " << p[i].kou;
		p[i].yingfa = p[i].jiben + p[i].jiang + p[i].mzwu + p[i].mzcheng;
		if (p[i].yingfa <= 2000)p[i].shui = 0;
		else if (p[i].yingfa <= 8000)p[i].shui = (p[i].yingfa - 2000) * 0.05;
		else p[i].shui = 300 + (p[i].yingfa - 8000) * 0.1;
		p[i].shifa = p[i].yingfa - p[i].shui - p[i].kou;
	}

}
float Get_v(char* num)
{
	char* c = num;
	float value = 0, f;
	while (*c >= '0' && *c <= '9')
	{
		value = value * 10 + (*c - 48); c++;
	}
	if (*c == '.')
	{
		c++;
		f = 10;
		while (*c)
		{
			value = value + (*c - 48) / f; f *= 10; c++;
		}
	}
	return value;
}





/************************计算模块**************************/
void Calt() {
	float tax = 0, prize = 0;
	int i;
	for (i = 0; i < nn; i++)
	{
		tax += p[i].shui;
		prize += p[i].jiang;
	}
	system("cls");
	cout << "总人数为" << nn << "共缴纳税金" << tax << "奖金总额" << prize << endl;
}
/*******************************统计模块*********************************/
void Stcs()
{
	float x1, x2;
	int i, m = 0;
	cout << "请输入要统计人数的基本工资范围" << endl;
	cout << " 基本工资起点值（含）：";
	cin >> x1;
	cout << " 基本工资终点值（含）：";
	cin >> x2;
	for (i = 0; i < nn; i++)
		if (p[i].jiben >= x1 && p[i].jiben <= x2)  m++;
	system("cls");
	cout << "本单位总人数为 ：" << nn << "人" << endl;
	cout << " 基本工资不低于" << x1 << "元，且不高于" << x2 << "元的人数为" << m << "人" << endl;
	cout << "所占比例" << (float)m * 100 / nn << "%" << endl;
}
/********************保存数据模块************************/
void Writ_file() {
	ofstream out("GZ.txt");
	if (out)
	{
		out << "工号" << setw(10) << "姓名" << setw(10) << "基本工资" << setw(10) << "奖金" << setw(10) << "扣除" << setw(10) << "类别" << setw(10) << "职务工资" << setw(10) << "职称工资" << setw(10) << "应发工资" << setw(10) << "实发工资" << setw(10) << "税款";
		for (int i = 0; i < nn; i++) {
			out << '\n' << setw(10) << p[i].code << setw(10) << p[i].name << setw(10) << p[i].jiben << setw(10) << p[i].jiang << setw(10) << p[i].kou << setw(10) << p[i].leibie << setw(10) << p[i].mzwu << setw(10) << p[i].mzcheng << setw(10) << p[i].yingfa << setw(10) << p[i].shifa << setw(10) << p[i].shui;
		}
		out.close();
	}
}
void Find() {
	char str[20];
	int i, k = -1, fd = 0;
	fflush(stdin);
	cout << "请输入你要查询的员工的工号或者姓名" << endl;
	cin >> str;
	for (i = 0; i <= nn; i++)
		if ((strcmp(p[i].code, str)) == 0 || (strcmp(p[i].name, str) == 0)) {
			fd = 1;
			k = i;
			break;
		}
	if (k == -1)cout << "对不起，没有找到此人，请核对后在输入";
	else {
		cout << "  工号   姓名  基本工资  奖金   类别      扣款    实发工资" << endl;;
		cout << "   " << p[i].code << "   " << p[i].name << "   " << p[i].jiben << "   " << p[i].jiang << "   " << p[i].leibie << "   " << p[i].kou << "   " << p[i].shifa;
	}
}
void Brow() {
	cout << "  工号   姓名  基本工资  奖金   类别      扣款    实发工资" << endl;
	for (int i = 0; i < nn; i++)
		cout << "   " << p[i].code << "   " << p[i].name << "   " << p[i].jiben << "   " << p[i].jiang << "   " << p[i].leibie << "   " << p[i].kou << "   " << p[i].shifa << endl;
}

void menu()
{
	int y = 1;
	while (y) {
		system("cls");
		cout << "\n\n\n\n";
		cout << "                    *************************************\n";
		cout << "                                工资管理系统\n";
		cout << "                    *                                   *\n";
		cout << "                    *   1: 浏览            2: 计算      *\n";
		cout << "                    *                                   *\n";
		cout << "                    *   3: 统计            4: 查询      *\n";
		cout << "                    *                                   *\n";
		cout << "                    *   5: 添加            6:从文件添加 *\n";
		cout << "                    *                                   *\n";
		cout << "                    *   7. 修改            8. 退出      *\n";
		cout << "                    *                                   *\n";
		cout << "                    *************************************\n";
		cout << "\n\n                            请选择功能序号: ";
		cin >> y;
		switch (y) {
		case 1:Brow(); break;
		case 2:Calt(); break;
		case 3:Stcs(); break;
		case 4:Find(); break;
		case 5:Append(); break;
		case 6:File_add(); break;
		case 7:Chng(); break;
		case 8:y = 0; break;
		}
		cout << "\n\n 按任意键继续\n";
		_getch();
	}
}/**************** 菜单 ****************/
