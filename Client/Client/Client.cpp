#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
// ��������� ������ ������� �������
struct Person
{
	char name[25]; //���
	int height; //����
	int weight; //���
} A;
void main()
{
	setlocale(LC_ALL, "rus");
	const char* nameR = "C:\\Users\\s0188265\\Desktop\\������������ ����\\Zapros_Client.txt";
	//���� ��� �������� ��������
	const char* nameA = "C:\\Users\\s0188265\\Desktop\\������������ ����\\Zapros_Server.txt";
	//���� ��� ������� �������
	ofstream f_REQ;
	ifstream f_ANS;
	long pred_size;
	int answer;
	while (true)
	{
		// �������� ������ �� ������� �������
		cout << "������� ������: ������� ���� ���" << endl;
		cin >> A.name >> A.height >> A.weight;
		f_REQ.open(nameR, ios::app | ios::binary);
		//�������� ����� REQUEST 
		f_REQ.write((char*)&A, sizeof(A));
		//������ ������� � ���� REQUEST
		f_REQ.close();
		// �������� ����� �� �������?
		f_ANS.open(nameA, ios::binary);
		//�������� ����� ANSWER
		f_ANS.seekg(0, ios::end);
		//������� � ����� ����� ANSWER
		pred_size = f_ANS.tellg();
		while (pred_size >= f_ANS.tellg())
		{
			Sleep(100);
			// ���� � ��������� � ����� ����� ANSWER
			f_ANS.seekg(0, ios::end);
		}
		// ��������� ������ �� �������
		f_ANS.seekg(pred_size, ios::beg);
		// �� ������ ������ ������
		f_ANS.read((char*)&answer, sizeof(answer));
		//���������� ������
		f_ANS.close();
		// ����������� ������
		switch (answer) {
		case 0: {cout << "���������� ����\n"; break; }
		case 1: {cout << "����� ����\n"; break; }
		case 2: {cout << "������� ����\n"; break; }
		}
	}
}