#include"WorkerManager.h"
#include"worker.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"
int main()
{
	WorkerManager wm;//����Աʵ����

	int choice = 0;//�洢�û�ѡ��

	while (true)
	{
		//��ӡ�˵�
		wm.Show_Menu();

		cout << "����������ѡ��: " << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://�˳��������
			wm.ExitSystem();
			break;
		case 1://����ְ����Ϣ
			wm.Add_Emp();
			break;
		case 2://��ʾְ����Ϣ
			wm.Show_Emp();
			break;
		case 3://ɾ����ְְ��
			wm.Del_Emp();
			break;
		case 4://�޸�ְ����Ϣ
			wm.Mod_Emp();
			break;
		case 5://����ְ����Ϣ
			wm.Find_emp();
			break;
		case 6://���ձ������
			wm.Sort_Emp();
			break;
		case 7://��������ĵ�
			wm.Clean_File();
			break;
		default:
			system("cls");//����
			break;
		}
	}
	system("pause");
	return 0;
}

