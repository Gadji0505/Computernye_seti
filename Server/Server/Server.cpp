#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
struct Person
{
	char name[25]; //���
	int height; //����
	int weight; //���
}B;
int answer;
long size_pred;
int main()
{
	ifstream fR;
	ofstream fA;
	setlocale(LC_ALL, "rus");
	const char* nameR = "C:\\Users\\s0188265\\Desktop\\������������ ����\\Zapros_Client.txt";
	//���� �������� ��������
	const char* nameA = "C:\\Users\\s0188265\\Desktop\\������������ ����\\Zapros_Server.txt";
	//���� ������� �������
	cout << "server is working" << endl;
	// ��������� ���������
	fR.open(nameR, ios::binary);
	//�������� ����� REQUEST
	fR.seekg(0, ios::end);
	size_pred = fR.tellg();
	//��������� ������� ������� � ����� REQUEST
	fR.close();
	// ������ ������ �������
	while (true)
	{
		fR.open(nameR, ios::binary);
		//�������� ����� REQUEST
		fR.seekg(0, ios::end);
		//������� � ����� ����� REQUEST
		// ���� ����� ������� �� ��������? 
		while (size_pred >= fR.tellg())
		{
			Sleep(100); fR.seekg(0, ios::end);
		}
		// ������� ����� ������
		fR.seekg(size_pred, ios::beg);
		//������� � ������ ����������� �������
		fR.read((char*)&B, sizeof(B));
		//���������� ������ �������
		size_pred = fR.tellg();
		// �� ����� ������������ ������
		fR.close();

		cout << B.name << " " << B.height << " " << B.weight << endl;
		// ����������� ������� �����
		double IMT = B.weight / (0.01 * B.height)
			/ (0.01 * B.height);
		if (18.5 <= IMT && IMT < 25) answer = 1;
		if (18.5 > IMT) answer = 0;
		if (IMT >= 25)answer = 2;
		// �������� ������ �������
		fA.open(nameA, ios::binary | ios::app);
		//�������� ����� ANSWER
		fA.write((char*)&answer, sizeof(answer));
		//������ ������ �������
		fA.close();
	}
}