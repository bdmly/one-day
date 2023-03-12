#define _CRT_SECURE_NO_WARNINGS 1
#include"employee.h"

//构造函数
Employee::Employee(int id, string name, int dId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_Deptid = dId;
}

//显示个人信息
void Employee::showinfo()
{
	cout << "职工编号:" << this->m_id
		<< "\t职工姓名:" << this->m_name
		<< "\t岗位:" << this->getDeptName() << endl;
}

//获取岗位名称
string Employee::getDeptName()
{
	return string("员工");
 }