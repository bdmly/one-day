//��ͨԱ���ļ�
#include<iostream>
using namespace std;
#include"worker.h"

class Employee :public Worker
{
public:

	//���캯��
	Employee(int id, string name, int dId);

	//��ʾ������Ϣ
	virtual void showinfo();

	//��ȡ��λ����
	virtual string getDeptName();
};