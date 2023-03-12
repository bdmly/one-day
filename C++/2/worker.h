#pragma once
#include<iostream>
using namespace std;
#include<string>


//职工抽象类
class Worker
{
public:

	//显示个人信息
	virtual void showinfo() = 0;

	//获取岗位名称
	virtual string getDeptName() = 0;

	int m_id;//职工编号

	string m_name;//职工姓名

	int m_Deptid;//部门编号
};
