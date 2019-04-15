#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<vector>
#include"imfo.h"
#include"demand.h"

using namespace std;
vector<vector<vector<imfo> > > coach(12, vector<vector<imfo> >(12, vector<imfo>(0)));
vector<vector<vector<imfo> > > air(12, vector<vector<imfo> >(12, vector<imfo>(0)));
vector<vector<vector<imfo> > > train(12, vector<vector<imfo> >(12, vector<imfo>(0)));





void input(imfo i,int select);
void Iniarray();
int main(void)
{
	Iniarray();


	/*int i = 9, j = 10;
	for (vector<imfo>::iterator iter = train[i][j].begin();iter != train[i][j].end();++iter)
	{
		iter->print(); //使用 * 访问迭代器所指向的元素
	}*/
	//coach[1][2][0].printout();
	
	demand client;
	client.least_money();
//	client.least_time();
	system("pause");
	return 0;
}
void Iniarray()
{
	int m = 0, plus = 0;
	//vector<vector<vector<imfo> > > coach(12, vector<vector<imfo> >(12,vector<imfo>(0)));
	ifstream srcFile("bus.txt", ios::in);
	if (!srcFile)
	{
		cout << "erro" << endl;

	}
	string str = "not";
	char c = '\t', ch;
	char p[30] = "hello";
	float tmpprice;
	imfo i;
	while (1)
	{
		srcFile.getline(p, 30, '\t');
		i.Set_departure(p);
		srcFile.getline(p, 30, '\t');
		i.Set_arrvial(p);
		srcFile >> tmpprice;
		i.Set_price(tmpprice);
		srcFile >> m;
		i.Set_departure_time(m);
		srcFile >> ch;
		srcFile >> m;//读入minute
		srcFile >> ch;//读入hour
		if (ch == '(')
		{
			srcFile >> ch;
			srcFile >> plus;
			plus = plus * 24;
			srcFile >> ch;
		}
		else
		{
			srcFile.seekg(-1, ios::cur);
			plus = 0;
		}
		srcFile >> m;//读入hour
		i.Set_arrival_time(m + plus);
		srcFile >> ch;
		srcFile >> m;//读入minute
		srcFile >> str;
		i.Set_number(str);
		input(i,1);
		if (srcFile >> c)
		{
			srcFile.seekg(-1, ios::cur);
		}
		else
		{
			break;
		}
	}
	i.print();
	srcFile.close();
	m = 0;plus = 0;
	ifstream airFile("airplane.txt", ios::in);
	while (1)
	{
		airFile.getline(p, 30, '\t');
		i.Set_departure(p);
		airFile.getline(p, 30, '\t');
		i.Set_arrvial(p);
		airFile >> tmpprice;
		i.Set_price(tmpprice);
		airFile >> m;
		i.Set_departure_time(m);
		airFile >> ch;
		airFile >> m;//读入minute
		airFile >> ch;//读入hour
		if (ch == '(')
		{
			airFile >> ch;
			airFile >> plus;
			airFile >> ch;
			plus = plus * 24;
		}
		else
		{
			airFile.seekg(-1, ios::cur);
			plus = 0;
		}
		airFile >> m;//读入hour
		i.Set_arrival_time(m + plus);
		airFile >> ch;
		airFile >> m;//读入minute
		airFile >> str;
		i.Set_number(str);
		input(i,2);
		if (airFile >> c)
		{
			airFile.seekg(-1, ios::cur);
		}
		else
		{
			break;
		}
	}
	i.print();
	airFile.close();
	plus = 0;m = 0;
	/*ifstream trainFile("bustest.txt", ios::in);
	if (!trainFile)
	{
		cout << "无法打开列车文件" << endl;

	}
	while (1)
	{
		trainFile.getline(p, 30, '\t');
		i.Set_departure(p);
		trainFile.getline(p, 30, '\t');
		i.Set_arrvial(p);
		trainFile >> tmpprice;
		i.Set_price(tmpprice);
		trainFile >> m;
		i.Set_departure_time(m);
		trainFile >> ch;
		trainFile >> m;//读入minute
		trainFile >> ch;//读入hour
		if (ch == '(')
		{
			trainFile >> ch;
			trainFile >> plus;
			trainFile >> ch;
			plus = plus * 24;
		}
		else
		{
			trainFile.seekg(-1, ios::cur);
			plus = 0;
		}
		trainFile >> m;//读入hour
		i.Set_arrival_time(m + plus);
		trainFile >> ch;
		trainFile >> m;//读入minute
		trainFile >> str;
		i.Set_number(str);
		input(i, 3);
		if (trainFile >> c)
		{
			trainFile.seekg(-1, ios::cur);
		}
		else
		{
			break;
		}
	}
	i.print();
	trainFile.close();*/
	return ;
}

void input(imfo i,int select)
{
	int x=0, y=0;//标记所处位置下标
	i.Set_type(select);//标记交通工具类型
	i.nametonum(x, y);
	switch (select)
	{
	case 1:coach[x][y].push_back(i);
		break;
	case 2:air[x][y].push_back(i);
		break;
	case 3:train[x][y].push_back(i);
	default:
		break;
	}	
	return;
}
/*void output(string outinfo[])
{
	int size = outinfo->size();
	vector<imfo> output;
	for (int i = 0;i < outinfo->size();i++)
	{
		output.push_back(discover(outinfo[i]));
	}
	for (int i = 0;i < outinfo->size();i++)
	{
		cout << "第" << i << "步:";
		output[i].printout();
	}
}*/