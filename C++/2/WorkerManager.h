#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"
#pragma once
#include<fstream>

#define FILENAME "empFile.txt"

class WorkerManager//管理系统
{
public:
	WorkerManager();

	//菜单
	void Show_Menu();

	//退出
	void ExitSystem();
	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker** m_EmpArray;

	//增加职工
	void Add_Emp();

	//保存文件
	void save();

	//判断文件是否为空
	bool m_FileIsEmpty;

	//统计文件中人数
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	//显示员工
	void Show_Emp();

	//判断职工是否存在
	int IsExist(int id);

	//删除员工
	void Del_Emp();

	//修改职工
	void Mod_Emp();

	//查找职工
	void Find_emp();

	//按编号排序
	void Sort_Emp();

	//清空数据
	void Clean_File();

	~WorkerManager();
};