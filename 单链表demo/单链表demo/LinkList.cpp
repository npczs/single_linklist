#include"LinkList.h"

int main()
{
	int a[5] = { 1,2,3,4,5 };
	LinkList<int> list(a, 5);
	list.PrintList();
	std::cout << list.Length();
	try                             
	{
		std::cout << list.Get(5);
	}
	catch (const char* s)      //throw �׳����쳣���봦����Ȼ���жϳ���
	{
		std::cout << s;
	}
	list.Insert(2, 8);
	list.Delete(4);
	list.PrintList();
	std::cout << list.Locate(3);//����0��ʾû�����ֵ
	


	return 0;
}