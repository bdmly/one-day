//经理文件
#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class Boss:public Worker
{
public:

	//构造函数
	Boss(int id, string name, int dId);

	//显示个人信息
	virtual void showinfo();

	//获取岗位名称
	virtual string getDeptName();
};
