#include"WorkerManager.h"

WorkerManager::WorkerManager()
{
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		//��ʼ������
		this->m_EmpNum = 0;

		this->m_EmpArray = NULL;

		this->m_FileIsEmpty = true;

		ifs.close();
		return;
	}
	//2.�ļ����ڣ���������
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		//��ʼ������
		this->m_EmpNum = 0;

		this->m_EmpArray = NULL;

		this->m_FileIsEmpty = true;

		ifs.close();
		return;
	}
	//3.�ļ����ڣ���������
	else{
		int num = this->get_EmpNum();
		cout << "ְ������Ϊ:" << num << endl;
		this->m_EmpNum = num;

		//���ٿռ�
		this->m_EmpArray = new Worker * [this->m_EmpNum];
		this->init_Emp();

	/*	for (int i = 0; i < this->m_EmpNum; i++)
		{
			cout << "ְ�����:" << this->m_EmpArray[i]->m_id
				<< "\tְ������:" << this->m_EmpArray[i]->m_name
				<< "\t��λ:" << this->m_EmpArray[i]->getDeptName() << endl;
		}*/
		ifs.close();
		return;
	}

}

void WorkerManager::Show_Menu()
{
	cout << "**********************************" << endl;
	cout << "******  ��ӭʹ��ְ������ϵͳ�� ***" << endl;
	cout << "********** 0.�˳�������� ********" << endl;
	cout << "********** 1.����ְ����Ϣ ********" << endl;
	cout << "********** 2.��ʾְ����Ϣ ********" << endl;
	cout << "********** 3.ɾ����ְְ�� ********" << endl;
	cout << "********** 4.�޸�ְ����Ϣ ********" << endl;
	cout << "********** 5.����ְ����Ϣ ********" << endl;
	cout << "********** 6.���ձ������ ********" << endl;
	cout << "********** 7.��������ĵ� ********" << endl;
	cout << "**********************************" << endl;

}

void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp()
{
	cout << "���������ְ������:" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//�¿ռ��С
		int newSize = this->m_EmpNum + addNum;
		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		//��ԭ���ռ����ݿ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//���������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dselect;

			cout << "�������" << i + 1 << "��ְ���ı��" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "��ְ��������" << endl;
			cin >> name;
			cout << "��ѡ���ְ���ĸ�λ" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
			//�������ݱ���������
			newSpace[this->m_EmpNum + i] = worker;

		}
		//�ͷ�ԭ�еĿռ�
		delete[] this->m_EmpArray;

		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;

		//�����ļ�Ϊ����Ϊ��
		this->m_FileIsEmpty = false;

		//����ְ������
		this->m_EmpNum = newSize;

		//
		cout << "��ӳɹ�" << endl;

		this->save();//��������
	}
	else
	{
		cout << "������������" << endl;
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


//��ʾԱ��
void WorkerManager::Show_Emp()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ��" << endl;

	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showinfo();

		}
	}
	//����
	system("pause");
	system("cls");

}

//�ж�ְ���Ƿ����
int WorkerManager::IsExist(int id)
{
	int index = -1;

	for (int i = 0; i < m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_id == id)
		{
			//�ҵ�Ա��
			index = i;
			break;
		}
	}
	return index;
}

//ɾ��Ա��
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "���ݼ�¼Ϊ��" << endl;
	}
	else
	{
		cout << "������Ҫɾ���ĵ�ְ�����:" << endl;
		int id;
		cin >> id;
		int index = this->IsExist(id);

		if (index != -1)
		{
			//ְ�����ڣ���ʼɾ��
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				//����Ǩ��
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];

			}
			this->m_EmpNum --;
			//����ͬ�����µ��ļ���
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "ְ��������" << endl;
		}
	}
	//����
	system("pause");
	system("cls");
}

//�޸�ְ��
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "���ݼ�¼Ϊ��" << endl;
	}
	else
	{
		cout << "������Ҫ�޸ĵ�ְ�����:" << endl;
		int id;
		cin >> id;
		int index = this->IsExist(id);

		if (index != -1)
		{
			//ְ�����ڣ���ʼ�޸�
			delete this->m_EmpArray[index];

			int newId;
			string newName;
			int dSelect = 0;

			cout << "���ҵ�:" << id << "��ְ�����������µ�ְ�����:" << endl;
			cin >> newId;
			cout << "�������µ�����:" << endl;
			cin >> newName;
			cout << "�������µĸ�λ:" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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

			//��������
			this->m_EmpArray[index] = worker;
			//����ͬ�����µ��ļ���
			this->save();
			cout << "�޸ĳɹ�" << endl;
		}
		else
		{
			cout << "ְ��������" << endl;
		}
	}
		//����
		system("pause");
		system("cls");
}


//����ְ��
void WorkerManager::Find_emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "���ݼ�¼Ϊ��" << endl;
	}
	else
	{
		cout << "������Ҫ���ҵķ���: " << endl;
		cout << "1.��ְ����Ų���  " << endl;
		cout << "2.��ְ����������  " << endl;

		int select;
		cin >> select;
		
		if (select == 1)
		{
			int id;
			cout << "������Ҫ���ҵ�ְ�����:" << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ����:" << endl;
				this->m_EmpArray[ret]->showinfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else if (select == 2)
		{
			cout << "������Ҫ���ҵ�ְ������:" << endl;
			string name;
			cin >> name;

			bool flag = false;
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_name == name)
				{
					cout << "���ҳɹ�����ְ����Ϣ����:" << endl;
					this->m_EmpArray[i]->showinfo();
					flag = true;
				}

			}
			if (flag)
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else
		{
			cout << "�����ѡ������" << endl;
		}

	}
	
	//����
	system("pause");
	system("cls");
}

void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "���ݼ�¼Ϊ��" << endl;
		//����
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ķ�ʽ: " << endl;
		cout << "1.����  " << endl;
		cout << "2.����  " << endl;

		int select;
		cin >> select;

		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;//������� ����Сֵ�±�
			for (int j = i + 1; j < m_EmpNum; j++)
			{
				if (select == 1)//����
				{
					if (this->m_EmpArray[minOrMax]->m_id > this->m_EmpArray[j]->m_id)
					{
						minOrMax = j;
					}
				}
				else//����
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
		cout << "����ɹ��������Ľ��Ϊ:" << endl;
		this->save();//�����ļ�
		this->Show_Emp();
	}
}

void WorkerManager::Clean_File()
{
	cout << "ȷ�����? " << endl;
	cout << "1.ȷ��  " << endl;
	cout << "2.����  " << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);//ɾ���ļ������´���
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
		cout << "��ճɹ�" << endl;
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

