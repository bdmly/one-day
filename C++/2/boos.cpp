#define _CRT_SECURE_NO_WARNINGS 1
#include"boss.h"

//构造函数
Boss::Boss(int id, string name, int dId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_Deptid = dId;
}

//显示个人信息
void Boss::showinfo()
{
	cout << "职工编号:" << this->m_id
		<< "\t职工姓名:" << this->m_name
		<< "\t岗位:" << this->getDeptName() << endl;
}

//获取岗位名称
string Boss::getDeptName()
{
	return string("老板");
}