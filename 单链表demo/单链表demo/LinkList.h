#include <stdio.h>
#include<iostream>
#include <cstring>

template <class ElemType>
struct Node
{
	ElemType data;
	Node<ElemType>* next;
};
template <class ElemType>
class LinkList
{
public:
	LinkList(); //构建空链表
	LinkList(ElemType a[], int n);  //有参构建链表
	~LinkList();//析构函数
	void PrintList(); //遍历输出
	int Length();  //返回表长
	ElemType Get(int i);//按位查找
	int Locate(ElemType x);//按值查找
	void Insert(int i, ElemType x);//插入第i个数据
	ElemType Delete(int i);//删除第i个数据
private:
	Node<ElemType>* first; //头指针，在构造函数里指向头结点
};


/*创建空的单链表*/
template <class ElemType>
 LinkList<ElemType>::LinkList()
{
	 first = new Node< ElemType>;
	 first->next = NULL;
}
 /*有参创建单链表（尾插法）*/
 template <class ElemType>
 LinkList<ElemType>::LinkList(ElemType a[], int n)
 {
	 Node<ElemType>*rear,*s;
	 first = new Node< ElemType>;/*创建头节点，头指针指向头结点*/
	 rear = first;
	 for (int i = 0; i < n; i++)
	 {
		 s = new Node<ElemType>;
		 s->data = a[i];
		 rear->next = s;
		 rear = s;
	 }
	 rear->next = NULL;

 }

 /*头插法，链表顺序会与数组相反*/
 /*template <class ElemType>
 LinkList<ElemType>::LinkList(ElemType a[], int n)
 {
	 Node<ElemType>* s;
	 first = new Node<ElemType>;
	 first->next = NULL;
	 for (int i = 0; i < n; i++)
	 {
		 s = new Node< ElemType>;
		 s->data = a[i];
		 s->next = first->next;
		 first->next = s;
	 }
 }*/

 template <class ElemType>
 LinkList<ElemType>::~LinkList()
 {
	 Node<ElemType>* p;
	 while(first != NULL)
	 {
		 p = first;
		 first = first->next;
		 delete p;
	 }
 }

 /*遍历输出*/
 template<class ElemType>
 void LinkList<ElemType>::PrintList()
 {
	 Node<ElemType>* p;
	 p = first->next;
	 while(p!=NULL)
	 {
		 std::cout << p->data << ',';
		 p = p->next;
	 }
 }
 /*求表长*/
 template <class ElemType>
 int LinkList<ElemType>::Length()
 {
	 Node<ElemType>* p;
	 p = first->next;
	 int count = 0;
	 while (p!=NULL)
	 {
		 count++;
		 p = p->next;
	 }
	 return count;
 }
 /*按位查找*/
 template <class ElemType>
 ElemType LinkList<ElemType>::Get(int i)
 {
	 Node<ElemType>* p;
	 p = first->next;
	 int count = 1;
	 while (p!=NULL&&count<i)
	 {
		 p = p->next;
		 count++;
	 }
	 if (p != NULL)
		 return p->data;
	 else
		 throw "参数错误"; 
 }
 /*按值查找*/
 template <class ElemType>
 int LinkList<ElemType>::Locate(ElemType x)
 {
	 Node<ElemType>* p;
	 p = first->next;
	 int count = 1;
	 while (p != NULL)
	 {
		 if (p->data == x)
			 return count;
		 p = p->next;
		 count++;
	 }
	 return 0;
 }
 /*在第i位插入x*/
 template<class ElemType>
 void LinkList<ElemType>::Insert(int i, ElemType x)
 {
	 Node<ElemType>* p;
	 p = first;
	 int count = 0;
	 while (p != NULL && count < i-1)
	 {
		 p = p->next;
		 count++;
	 }
	 if (p != NULL&&i>0)
	 {
		 Node<ElemType>* s;
		 s = new Node<ElemType>;
		 s->data = x;
		 s->next = p->next;
		 p->next = s;
	 }
	 else
	 {
		 throw "参数错误";
	 }

 }
 /*删除第i位数据*/
 template<class ElemType>
 ElemType LinkList<ElemType>::Delete(int i)
 {
	 Node<ElemType>* p;
	 p = first;
	 int count = 0;
	 while(p != NULL && count < i - 1)
	 {
		 p = p->next;
		 count++;
	 }

	 if (p != NULL && p->next != NULL)
	 {
		 Node<ElemType>* q;
		 q = p->next;
		 p->next = q->next;
		 ElemType x;
		 x = q->data;
		 return x;
	 }
 }





