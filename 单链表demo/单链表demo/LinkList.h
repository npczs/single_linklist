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
	LinkList(); //����������
	LinkList(ElemType a[], int n);  //�вι�������
	~LinkList();//��������
	void PrintList(); //�������
	int Length();  //���ر�
	ElemType Get(int i);//��λ����
	int Locate(ElemType x);//��ֵ����
	void Insert(int i, ElemType x);//�����i������
	ElemType Delete(int i);//ɾ����i������
private:
	Node<ElemType>* first; //ͷָ�룬�ڹ��캯����ָ��ͷ���
};


/*�����յĵ�����*/
template <class ElemType>
 LinkList<ElemType>::LinkList()
{
	 first = new Node< ElemType>;
	 first->next = NULL;
}
 /*�вδ���������β�巨��*/
 template <class ElemType>
 LinkList<ElemType>::LinkList(ElemType a[], int n)
 {
	 Node<ElemType>*rear,*s;
	 first = new Node< ElemType>;/*����ͷ�ڵ㣬ͷָ��ָ��ͷ���*/
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

 /*ͷ�巨������˳����������෴*/
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

 /*�������*/
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
 /*���*/
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
 /*��λ����*/
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
		 throw "��������"; 
 }
 /*��ֵ����*/
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
 /*�ڵ�iλ����x*/
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
		 throw "��������";
	 }

 }
 /*ɾ����iλ����*/
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





