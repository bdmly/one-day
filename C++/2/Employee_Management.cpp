#include"WorkerManager.h"
#include"employee.h"
#include"worker.h"
int main()
{
	WorkerManager wm;//管理员实例化

	int choice = 0;//存储用户选项

	while (true)
	{
		//测试
		Worker* a = NULL;
		a = new Employee(1, "zs", 2);
		a->showinfo();
		



		//打印菜单
		wm.Show_Menu();

		cout << "请输入您的选择: " << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://退出管理程序
			wm.ExitSystem();
			break;
		case 1://增加职工信息
			break;
		case 2://显示职工信息
			break;
		case 3://删除离职职工
			break;
		case 4://修改职工信息
			break;
		case 5://查找职工信息
			break;
		case 6://按照编号排序
			break;
		case 7://清空所有文档
			break;
		default:
			system("cls");//清屏
			break;
		}
	}
	system("pause");
	return 0;
}

