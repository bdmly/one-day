#define _CRT_SECURE_NO_WARNINGS 1
#include"boss.h"

//���캯��
Boss::Boss(int id, string name, int dId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_Deptid = dId;
}

//��ʾ������Ϣ
void Boss::showinfo()
{
	cout << "ְ�����:" << this->m_id
		<< "\tְ������:" << this->m_name
		<< "\t��λ:" << this->getDeptName() << endl;
}

//��ȡ��λ����
string Boss::getDeptName()
{
	return string("�ϰ�");
}