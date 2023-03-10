#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
#define MAX 1000

//�˵�
void showMenu()
{
	cout << "**********************" << endl;
	cout << "**** 1.�����ϵ�� ****" << endl;
	cout << "**** 2.��ʾ��ϵ�� ****" << endl;
	cout << "**** 3.ɾ����ϵ�� ****" << endl;
	cout << "**** 4.������ϵ�� ****" << endl;
	cout << "**** 5.�޸���ϵ�� ****" << endl;
	cout << "**** 6.�����ϵ�� ****" << endl;
	cout << "**** 0.�˳�ͨѶ¼ ****" << endl;
	cout << "**********************" << endl;

}
//��ϵ�˽ṹ��
struct Person {
	string name;
	int sex;//1.��  2.Ů
	int age;
	string phone;//�绰
	string addr;//סַ
};

//ͨѶ¼�ṹ��
struct Addressbooks
{
	//��ϵ������
	struct Person personarray[MAX];
	//��ϵ�˸���
	int size;
};

//1.�����ϵ��
void addperson(Addressbooks* abs)
{
	if (abs->size == MAX)
	{
		cout << "ͨѶ¼����" << endl;
		return;
	}
	else
	{
		cout << "����������:" << endl;
		string m_name;
		cin >> m_name;
		abs->personarray[abs->size].name = m_name;
		
		while (true)
		{
			cout << "�������Ա�: 1.�� 2.Ů" << endl;
			int m_sex;
			cin >> m_sex;
			if (m_sex == 1 || m_sex == 2)
			{
				abs->personarray[abs->size].sex = m_sex;
				break;
			}
			cout << "�����������������" << endl;
		}

		cout << "����������:" << endl;
		int m_age;
		cin >> m_age;
		abs->personarray[abs->size].age = m_age;

		cout << "������绰:" << endl;
		string m_phone;
		cin >> m_phone;
		abs->personarray[abs->size].phone = m_phone;

		cout << "�������ַ:" << endl;
		string m_addr;
		cin >> m_addr;
		abs->personarray[abs->size].addr = m_addr;

		//������ϵ�˸���
		abs->size++;

		cout << "��ӳɹ�" << endl;

		system("pause");//�����������
		system("cls");//����

	}
}

//2.��ʾ��ϵ��
void showperson(Addressbooks * abs)
{
	if (abs->size == 0)
	{
		cout << "��ǰͨѶ¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->size; i++)
		{
			cout << "����: " << abs->personarray[i].name << "\t";
			cout << "�Ա�: " << (abs->personarray[i].sex == 1 ? '��' : 'Ů') << "\t";
			cout << "����: " << abs->personarray[i].age << "\t";
			cout << "�绰: " << abs->personarray[i].phone << "\t";
			cout << "סַ: " << abs->personarray[i].addr << endl;
		}
	}
	system("pause");//�����������
	system("cls");//����
}

//�����ϵ���Ƿ����
//���ڷ�������λ�ã������ڷ���-1
int isexist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->size; i++)
	{
		if (abs->personarray[i].name == name)
		{
			return i;
		}
	}
	return -1;
}

//3.ɾ����ϵ��
void deleteperson(Addressbooks* abs)
{
	cout << "������Ҫɾ������ϵ��:" << endl;
	string m_name;
	cin >> m_name;
	int ret=isexist(abs, m_name);
	if (ret != -1)
	{
		//ɾ������
		for (int i = ret; i < abs->size; i++)
		{
			//����ǰ��
			abs->personarray[i] = abs->personarray[i + 1];
		}
		abs->size--;//��ϵ�˸�����1
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "û�д���ϵ��" << endl;
	}

	system("pause");//�����������
	system("cls");//����
}

//4.������ϵ��
void findperson(Addressbooks* abs)
{
	cout << "������Ҫ���ҵ���ϵ��:" << endl;
	string m_name;
	cin >> m_name;
	int ret = isexist(abs, m_name);
	if (ret != -1)
	{
		cout << "����: " << abs->personarray[ret].name << "\t";
		cout << "�Ա�: " << (abs->personarray[ret].sex == 1 ? '��' : 'Ů') << "\t";
		cout << "����: " << abs->personarray[ret].age << "\t";
	    cout << "�绰: " << abs->personarray[ret].phone << "\t";
		cout << "סַ: " << abs->personarray[ret].addr << endl;
	
		cout << "���ҳɹ�" << endl;
	}
	else
	{
		cout << "û�д���ϵ��" << endl;
	}

	system("pause");//�����������
	system("cls");//����
}

//5.�޸���ϵ��
void modifyperson(Addressbooks* abs)
{
	cout << "������Ҫ�޸ĵ���ϵ��:" << endl;
	string m_name1;
	cin >> m_name1;
	int ret = isexist(abs, m_name1);
	if (ret != -1)
	{
		cout << "����������:" << endl;
		string m_name;
		cin >> m_name;
		abs->personarray[ret].name = m_name;

		while (true)
		{
			cout << "�������Ա�: 1.�� 2.Ů" << endl;
			int m_sex;
			cin >> m_sex;
			if (m_sex == 1 || m_sex == 2)
			{
				abs->personarray[ret].sex = m_sex;
				break;
			}
			cout << "�����������������" << endl;
		}

		cout << "����������:" << endl;
		int m_age;
		cin >> m_age;
		abs->personarray[ret].age = m_age;

		cout << "������绰:" << endl;
		string m_phone;
		cin >> m_phone;
		abs->personarray[ret].phone = m_phone;

		cout << "�������ַ:" << endl;
		string m_addr;
		cin >> m_addr;
		abs->personarray[ret].addr = m_addr;
		
		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "û�д���ϵ��" << endl;
	}

	system("pause");//�����������
	system("cls");//����
}

//6.�����ϵ��
void cleanperson(Addressbooks* abs)
{
	abs->size = 0;
	cout << "��ճɹ�" << endl;

	system("pause");//�����������
	system("cls");//����
}
int main()
{
	//����ͨѶ¼
	struct Addressbooks abs;
	abs.size = 0;//��ʼ����ϵ�˸���
	while (1)
	{
		showMenu();
		int select;
		cin >> select;
		switch (select)
		{
		case 1://1.�����ϵ��
			addperson(&abs);
			break;
		case 2://2.��ʾ��ϵ��
			showperson(&abs);
			break;
		case 3://3.ɾ����ϵ��
			deleteperson(&abs);
			break;
		case 4://4.������ϵ��
			findperson(&abs);
			break;
		case 5://5.�޸���ϵ��
			modifyperson(&abs);
			break;
		case 6://6.�����ϵ��
			cleanperson(&abs);
			break;
		case 0://0.�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		}
	}



	system("pause");
	return 0;
}