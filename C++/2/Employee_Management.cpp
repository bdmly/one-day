#include"WorkerManager.h"
#include"worker.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"
int main()
{
	WorkerManager wm;//管理员实例化

	int choice = 0;//存储用户选项

	while (true)
	{
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
			wm.Add_Emp();
			break;
		case 2://显示职工信息
			wm.Show_Emp();
			break;
		case 3://删除离职职工
			wm.Del_Emp();
			break;
		case 4://修改职工信息
			wm.Mod_Emp();
			break;
		case 5://查找职工信息
			wm.Find_emp();
			break;
		case 6://按照编号排序
			wm.Sort_Emp();
			break;
		case 7://清空所有文档
			wm.Clean_File();
			break;
		default:
			system("cls");//清屏
			break;
		}
	}
	system("pause");
	return 0;
}

