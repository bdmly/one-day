//�����ļ�
#include<iostream>
using namespace std;
#include"worker.h"
#pragma once

class Manager:public Worker
{
public:

	//���캯��
	Manager(int id, string name, int dId);

	//��ʾ������Ϣ
	virtual void showinfo();

	//��ȡ��λ����
	virtual string getDeptName();
};