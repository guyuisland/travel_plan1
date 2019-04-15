#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<vector>
#include"imfo.h"
using namespace std;
imfo::imfo(float p, int d_time, int a_time, string num,int type)
{
	departure[0] = '\0';
	arrival[0] = '\0';
	price = p;
	departure_time = d_time;
	arrival_time = a_time;
	number = num;
	//cout << "����" << endl;
}
imfo::imfo(const imfo &imfo_copied)
{
	strcpy_s(departure, imfo_copied.departure);
	strcpy_s(arrival, imfo_copied.arrival);
	price = imfo_copied.price;
	departure_time = imfo_copied.departure_time;
	arrival_time = imfo_copied.arrival_time;
	number = imfo_copied.number;
	type = imfo_copied.type;
	//cout << "����" << endl;
}
imfo::~imfo()
{
	//cout << "����" << endl;
}
void imfo::print()
{
	cout << departure << " " << arrival << " " << price << endl;
	cout << departure_time << endl;
	cout << arrival_time << endl;
	cout << number << endl;
}
void imfo::Set_price(float money)
{
	price = money;
}
void imfo::Set_departure_time(int time)
{
	departure_time = time;
}
void imfo::Set_arrival_time(int time)
{
	arrival_time = time;
}
void imfo::Set_number(string num)
{
	number = num;
}
void imfo::Set_departure(char *copied)
{
	strcpy_s(departure, copied);
}
void imfo::Set_arrvial(char *copied)
{
	strcpy_s(arrival, copied);
}
void imfo::nametonum(int &x, int &y)
{
	if (strcmp(departure,"��ɳ")==0)
	{
		x = 0;
	}
	if (strcmp(departure,"����")==0)
	{
		x = 1;
	}
	if (strcmp(departure,"����")==0)
	{
		x = 2;
	}
	if (strcmp(departure,"ʯ��ׯ")==0)
	{
		x = 3;
	}
	if (strcmp(departure,"����")==0)
	{
		x = 4;
	}
	if (strcmp(departure,"����") == 0)
	{
		x = 5;
	}
	if (strcmp(departure,"����") == 0)
	{
		x = 6;
	}
	if (strcmp(departure,"�ϲ�") == 0)
	{
		x = 7;
	}
	if (strcmp(departure,"�人") == 0)
	{
		x = 8;
	}
	if (strcmp(departure,"����") == 0)
	{
		x = 9;
	}
	if (strcmp(departure,"����") == 0)
	{
		x = 10;
	}
	if (strcmp(departure,"����") == 0)
	{
		x = 11;
	}
	if (strcmp(arrival, "��ɳ") == 0)
	{
		y = 0;
	}
	if (strcmp(arrival, "����") == 0)
	{
		y = 1;
	}
	if (strcmp(arrival, "����") == 0)
	{
		y = 2;
	}
	if (strcmp(arrival, "ʯ��ׯ") == 0)
	{
		y = 3;
	}
	if (strcmp(arrival, "����") == 0)
	{
		y = 4;
	}
	if (strcmp(arrival, "����") == 0)
	{
		y = 5;
	}
	if (strcmp(arrival, "����") == 0)
	{
		y = 6;
	}
	if (strcmp(arrival, "�ϲ�") == 0)
	{
		y = 7;
	}
	if (strcmp(arrival, "�人") == 0)
	{
		y = 8;
	}
	if (strcmp(arrival, "����") == 0)
	{
		y = 9;
	}
	if (strcmp(arrival, "����") == 0)
	{
		y = 10;
	}
	if (strcmp(arrival, "����") == 0)
	{
		y = 11;
	}
}
void imfo::Set_type(int travel_type)
{
	type = travel_type;
}
void imfo::printout()
{
	switch (type)
	{
	case 1:cout << "������ʿ";
		break;
	case 2:cout << "�����ɻ�";
		break;
	case 3:cout << "�����г�";
	default:
		break;
	}
	cout << number <<"\t";
	cout << "��" << departure_time << "���" << departure << "���� ";
	cout << arrival_time << "�㵽��" << arrival << endl;
}
float imfo::Get_price(){
	return price;
}
int imfo::Get_departure_time(){
	return departure_time;
}
int imfo::Get_arrival_time() {
	return arrival_time;
}
string imfo::Get_number() {
	return number;
}