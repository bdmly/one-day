#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include"manager.h"

//���캯��
Manager::Manager(int id, string name, int dId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_Deptid = dId;
}

//��ʾ������Ϣ
void Manager::showinfo()
{
	cout << "ְ�����:" << this->m_id
		<< "\tְ������:" << this->m_name
		<< "\t��λ:" << this->getDeptName() << endl;
}

//��ȡ��λ����
string Manager::getDeptName()
{
	return string("����");
}