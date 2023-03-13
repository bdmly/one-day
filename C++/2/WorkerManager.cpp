#include"WorkerManager.h"

WorkerManager::WorkerManager()
{
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		//初始化属性
		this->m_EmpNum = 0;

		this->m_EmpArray = NULL;

		this->m_FileIsEmpty = true;

		ifs.close();
		return;
	}
	//2.文件存在，但无数据
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		//初始化属性
		this->m_EmpNum = 0;

		this->m_EmpArray = NULL;

		this->m_FileIsEmpty = true;

		ifs.close();
		return;
	}
	//3.文件存在，且有数据
	else{
		int num = this->get_EmpNum();
		cout << "职工人数为:" << num << endl;
		this->m_EmpNum = num;

		//开辟空间
		this->m_EmpArray = new Worker * [this->m_EmpNum];
		this->init_Emp();

	/*	for (int i = 0; i < this->m_EmpNum; i++)
		{
			cout << "职工编号:" << this->m_EmpArray[i]->m_id
				<< "\t职工姓名:" << this->m_EmpArray[i]->m_name
				<< "\t岗位:" << this->m_EmpArray[i]->getDeptName() << endl;
		}*/
		ifs.close();
		return;
	}

}

void WorkerManager::Show_Menu()
{
	cout << "**********************************" << endl;
	cout << "******  欢迎使用职工管理系统！ ***" << endl;
	cout << "********** 0.退出管理程序 ********" << endl;
	cout << "********** 1.增加职工信息 ********" << endl;
	cout << "********** 2.显示职工信息 ********" << endl;
	cout << "********** 3.删除离职职工 ********" << endl;
	cout << "********** 4.修改职工信息 ********" << endl;
	cout << "********** 5.查找职工信息 ********" << endl;
	cout << "********** 6.按照编号排序 ********" << endl;
	cout << "********** 7.清空所有文档 ********" << endl;
	cout << "**********************************" << endl;

}

void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工人数:" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//新空间大小
		int newSize = this->m_EmpNum + addNum;
		//开辟新空间
		Worker** newSpace = new Worker * [newSize];

		//将原来空间内容拷贝
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dselect;

			cout << "请输入第" << i + 1 << "个职工的编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个职工的姓名" << endl;
			cin >> name;
			cout << "请选择该职工的岗位" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dselect;

			Worker* worker = NULL;
			switch (dselect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			}
			//将新数据保存至数组
			newSpace[this->m_EmpNum + i] = worker;

		}
		//释放原有的空间
		delete[] this->m_EmpArray;

		//更改新空间的指向
		this->m_EmpArray = newSpace;

		//更新文件为：不为空
		this->m_FileIsEmpty = false;

		//更新职工人数
		this->m_EmpNum = newSize;

		//
		cout << "添加成功" << endl;

		this->save();//保存数据
	}
	else
	{
		cout << "输入数据有误" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_id << "  "
			<< this->m_EmpArray[i]->m_name << "  "
			<< this->m_EmpArray[i]->m_Deptid << endl;
	}

	//
	ofs.close();

}
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	return num;
}

void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;

		if (dId == 1)
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)
		{
			worker = new Manager(id, name, dId);
		}
		else
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}


//显示员工
void WorkerManager::Show_Emp()
{
	//判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或文件为空" << endl;

	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showinfo();

		}
	}
	//清屏
	system("pause");
	system("cls");

}

//判断职工是否存在
int WorkerManager::IsExist(int id)
{
	int index = -1;

	for (int i = 0; i < m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_id == id)
		{
			//找到员工
			index = i;
			break;
		}
	}
	return index;
}

//删除员工
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "数据记录为空" << endl;
	}
	else
	{
		cout << "请输入要删除的的职工编号:" << endl;
		int id;
		cin >> id;
		int index = this->IsExist(id);

		if (index != -1)
		{
			//职工存在，开始删除
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				//数据迁移
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];

			}
			this->m_EmpNum --;
			//数据同步更新到文件中
			this->save();
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "职工不存在" << endl;
		}
	}
	//清屏
	system("pause");
	system("cls");
}

//修改职工
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "数据记录为空" << endl;
	}
	else
	{
		cout << "请输入要修改的职工编号:" << endl;
		int id;
		cin >> id;
		int index = this->IsExist(id);

		if (index != -1)
		{
			//职工存在，开始修改
			delete this->m_EmpArray[index];

			int newId;
			string newName;
			int dSelect = 0;

			cout << "查找到:" << id << "号职工，请输入新的职工编号:" << endl;
			cin >> newId;
			cout << "请输入新的姓名:" << endl;
			cin >> newName;
			cout << "请输入新的岗位:" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}

			//更新数组
			this->m_EmpArray[index] = worker;
			//数据同步更新到文件中
			this->save();
			cout << "修改成功" << endl;
		}
		else
		{
			cout << "职工不存在" << endl;
		}
	}
		//清屏
		system("pause");
		system("cls");
}


//查找职工
void WorkerManager::Find_emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "数据记录为空" << endl;
	}
	else
	{
		cout << "请输入要查找的方法: " << endl;
		cout << "1.按职工编号查找  " << endl;
		cout << "2.按职工姓名查找  " << endl;

		int select;
		cin >> select;
		
		if (select == 1)
		{
			int id;
			cout << "请输入要查找的职工编号:" << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功，该职工信息如下:" << endl;
				this->m_EmpArray[ret]->showinfo();
			}
			else
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else if (select == 2)
		{
			cout << "请输入要查找的职工姓名:" << endl;
			string name;
			cin >> name;

			bool flag = false;
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_name == name)
				{
					cout << "查找成功，该职工信息如下:" << endl;
					this->m_EmpArray[i]->showinfo();
					flag = true;
				}

			}
			if (flag)
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else
		{
			cout << "输入的选项有误！" << endl;
		}

	}
	
	//清屏
	system("pause");
	system("cls");
}

void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "数据记录为空" << endl;
		//清屏
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序的方式: " << endl;
		cout << "1.升序  " << endl;
		cout << "2.降序  " << endl;

		int select;
		cin >> select;

		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;//声明最大 或，最小值下标
			for (int j = i + 1; j < m_EmpNum; j++)
			{
				if (select == 1)//升序
				{
					if (this->m_EmpArray[minOrMax]->m_id > this->m_EmpArray[j]->m_id)
					{
						minOrMax = j;
					}
				}
				else//降序
				{
					if (this->m_EmpArray[minOrMax]->m_id < this->m_EmpArray[j]->m_id)
					{
						minOrMax = j;
					}
				}

			}
			
			if (i!=minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}

		}
		cout << "排序成功，排序后的结果为:" << endl;
		this->save();//更新文件
		this->Show_Emp();
	}
}

void WorkerManager::Clean_File()
{
	cout << "确定清空? " << endl;
	cout << "1.确定  " << endl;
	cout << "2.返回  " << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);//删除文件后重新创建
		ofs.close();
		
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete [] this->m_EmpArray;
		this->m_EmpArray = NULL;

	}

}

