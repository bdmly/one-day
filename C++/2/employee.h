//普通员工文件
#include<iostream>
using namespace std;
#include"worker.h"
#pragma once

class Employee :public Worker
{
public:

	//构造函数
	Employee(int id, string name, int dId);

	//显示个人信息
	virtual void showinfo();

	//获取岗位名称
	virtual string getDeptName();
};