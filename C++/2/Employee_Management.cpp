#include"WorkerManager.h"
#include"employee.h"
#include"worker.h"
int main()
{
	WorkerManager wm;//����Աʵ����

	int choice = 0;//�洢�û�ѡ��

	while (true)
	{
		//����
		Worker* a = NULL;
		a = new Employee(1, "zs", 2);
		a->showinfo();
		



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
			break;
		case 2://��ʾְ����Ϣ
			break;
		case 3://ɾ����ְְ��
			break;
		case 4://�޸�ְ����Ϣ
			break;
		case 5://����ְ����Ϣ
			break;
		case 6://���ձ������
			break;
		case 7://��������ĵ�
			break;
		default:
			system("cls");//����
			break;
		}
	}
	system("pause");
	return 0;
}

