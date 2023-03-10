#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
#define MAX 1000

//菜单
void showMenu()
{
	cout << "**********************" << endl;
	cout << "**** 1.添加联系人 ****" << endl;
	cout << "**** 2.显示联系人 ****" << endl;
	cout << "**** 3.删除联系人 ****" << endl;
	cout << "**** 4.查找联系人 ****" << endl;
	cout << "**** 5.修改联系人 ****" << endl;
	cout << "**** 6.清空联系人 ****" << endl;
	cout << "**** 0.退出通讯录 ****" << endl;
	cout << "**********************" << endl;

}
//联系人结构体
struct Person {
	string name;
	int sex;//1.男  2.女
	int age;
	string phone;//电话
	string addr;//住址
};

//通讯录结构体
struct Addressbooks
{
	//联系人数组
	struct Person personarray[MAX];
	//联系人个数
	int size;
};

//1.添加联系人
void addperson(Addressbooks* abs)
{
	if (abs->size == MAX)
	{
		cout << "通讯录已满" << endl;
		return;
	}
	else
	{
		cout << "请输入姓名:" << endl;
		string m_name;
		cin >> m_name;
		abs->personarray[abs->size].name = m_name;
		
		while (true)
		{
			cout << "请输入性别: 1.男 2.女" << endl;
			int m_sex;
			cin >> m_sex;
			if (m_sex == 1 || m_sex == 2)
			{
				abs->personarray[abs->size].sex = m_sex;
				break;
			}
			cout << "输入错误，请重新输入" << endl;
		}

		cout << "请输入年龄:" << endl;
		int m_age;
		cin >> m_age;
		abs->personarray[abs->size].age = m_age;

		cout << "请输入电话:" << endl;
		string m_phone;
		cin >> m_phone;
		abs->personarray[abs->size].phone = m_phone;

		cout << "请输入地址:" << endl;
		string m_addr;
		cin >> m_addr;
		abs->personarray[abs->size].addr = m_addr;

		//更新联系人个数
		abs->size++;

		cout << "添加成功" << endl;

		system("pause");//按任意键继续
		system("cls");//清屏

	}
}

//2.显示联系人
void showperson(Addressbooks * abs)
{
	if (abs->size == 0)
	{
		cout << "当前通讯录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->size; i++)
		{
			cout << "姓名: " << abs->personarray[i].name << "\t";
			cout << "性别: " << (abs->personarray[i].sex == 1 ? '男' : '女') << "\t";
			cout << "年龄: " << abs->personarray[i].age << "\t";
			cout << "电话: " << abs->personarray[i].phone << "\t";
			cout << "住址: " << abs->personarray[i].addr << endl;
		}
	}
	system("pause");//按任意键继续
	system("cls");//清屏
}

//监测联系人是否存在
//存在返回所在位置，不存在返回-1
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

//3.删除联系人
void deleteperson(Addressbooks* abs)
{
	cout << "请输入要删除的联系人:" << endl;
	string m_name;
	cin >> m_name;
	int ret=isexist(abs, m_name);
	if (ret != -1)
	{
		//删除操作
		for (int i = ret; i < abs->size; i++)
		{
			//数据前移
			abs->personarray[i] = abs->personarray[i + 1];
		}
		abs->size--;//联系人个数减1
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "没有此联系人" << endl;
	}

	system("pause");//按任意键继续
	system("cls");//清屏
}

//4.查找联系人
void findperson(Addressbooks* abs)
{
	cout << "请输入要查找的联系人:" << endl;
	string m_name;
	cin >> m_name;
	int ret = isexist(abs, m_name);
	if (ret != -1)
	{
		cout << "姓名: " << abs->personarray[ret].name << "\t";
		cout << "性别: " << (abs->personarray[ret].sex == 1 ? '男' : '女') << "\t";
		cout << "年龄: " << abs->personarray[ret].age << "\t";
	    cout << "电话: " << abs->personarray[ret].phone << "\t";
		cout << "住址: " << abs->personarray[ret].addr << endl;
	
		cout << "查找成功" << endl;
	}
	else
	{
		cout << "没有此联系人" << endl;
	}

	system("pause");//按任意键继续
	system("cls");//清屏
}

//5.修改联系人
void modifyperson(Addressbooks* abs)
{
	cout << "请输入要修改的联系人:" << endl;
	string m_name1;
	cin >> m_name1;
	int ret = isexist(abs, m_name1);
	if (ret != -1)
	{
		cout << "请输入姓名:" << endl;
		string m_name;
		cin >> m_name;
		abs->personarray[ret].name = m_name;

		while (true)
		{
			cout << "请输入性别: 1.男 2.女" << endl;
			int m_sex;
			cin >> m_sex;
			if (m_sex == 1 || m_sex == 2)
			{
				abs->personarray[ret].sex = m_sex;
				break;
			}
			cout << "输入错误，请重新输入" << endl;
		}

		cout << "请输入年龄:" << endl;
		int m_age;
		cin >> m_age;
		abs->personarray[ret].age = m_age;

		cout << "请输入电话:" << endl;
		string m_phone;
		cin >> m_phone;
		abs->personarray[ret].phone = m_phone;

		cout << "请输入地址:" << endl;
		string m_addr;
		cin >> m_addr;
		abs->personarray[ret].addr = m_addr;
		
		cout << "修改成功" << endl;
	}
	else
	{
		cout << "没有此联系人" << endl;
	}

	system("pause");//按任意键继续
	system("cls");//清屏
}

//6.清空联系人
void cleanperson(Addressbooks* abs)
{
	abs->size = 0;
	cout << "清空成功" << endl;

	system("pause");//按任意键继续
	system("cls");//清屏
}
int main()
{
	//创建通讯录
	struct Addressbooks abs;
	abs.size = 0;//初始化联系人个数
	while (1)
	{
		showMenu();
		int select;
		cin >> select;
		switch (select)
		{
		case 1://1.添加联系人
			addperson(&abs);
			break;
		case 2://2.显示联系人
			showperson(&abs);
			break;
		case 3://3.删除联系人
			deleteperson(&abs);
			break;
		case 4://4.查找联系人
			findperson(&abs);
			break;
		case 5://5.修改联系人
			modifyperson(&abs);
			break;
		case 6://6.清空联系人
			cleanperson(&abs);
			break;
		case 0://0.退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		}
	}



	system("pause");
	return 0;
}