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

class WorkerManager//����ϵͳ
{
public:
	WorkerManager();

	//�˵�
	void Show_Menu();

	//�˳�
	void ExitSystem();
	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker** m_EmpArray;

	//����ְ��
	void Add_Emp();

	//�����ļ�
	void save();

	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

	//ͳ���ļ�������
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//��ʾԱ��
	void Show_Emp();

	//�ж�ְ���Ƿ����
	int IsExist(int id);

	//ɾ��Ա��
	void Del_Emp();

	//�޸�ְ��
	void Mod_Emp();

	//����ְ��
	void Find_emp();

	//���������
	void Sort_Emp();

	//�������
	void Clean_File();

	~WorkerManager();
};