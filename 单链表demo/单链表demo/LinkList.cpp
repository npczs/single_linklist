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
	catch (const char* s)      //throw 抛出的异常必须处理，不然会中断程序
	{
		std::cout << s;
	}
	list.Insert(2, 8);
	list.Delete(4);
	list.PrintList();
	std::cout << list.Locate(3);//返回0表示没有这个值
	


	return 0;
}