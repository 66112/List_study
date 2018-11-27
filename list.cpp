#include <iostream>
#include <list>
#include <vector>

using namespace std;
class Date
{
private:
	int _year;
	int _month;
	int _day;
public:
	Date(int year = 1990, int month = 1, int day = 1)
		:_year(year), _month(month), _day(day)
	{
		cout << "Date(int ,int ,int): " << this << endl;
	}
	Date(const Date& d)
		:_year(d._year), _month(d._month), _day(d._day)
	{
		cout << "Date(const Date& d): " << this << endl;
	}
};
template<class T>
void Print(const T &l) 
{
	T::const_iterator it = l.cbegin();
	while (it != l.cend())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}
void ListTest1()
{
	list<int> l1;
	list<int> l2(4, 100);
	list<int> l3(l2.begin(), l2.end());     //������
	list<int> l4(l3);

	Print(l1);
	Print(l2);
	Print(l3);
	Print(l4);
}

void ListTest2()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l1(arr, arr + sizeof(arr) / sizeof(int));
	Print(l1);
	l1.front() = 10;       //���ص�һ���ڵ������
	l1.back() = 10;
	Print(l1);
	const list<int> l2(l1);   
	Print(l2);
	//l2.push_back(11);     //���ܲ��룬l2�����޸�  
}
void ListTest3()
{
	int arr[] = { 1, 2, 3 };
	list<int> l1(2, 100);
	l1.push_back(99);
	l1.push_front(99);
	Print(l1);
	l1.emplace_back(91);
	auto pos = l1.insert(--l1.end(), 18);       //��posλ��ǰ�߲���18,����ָ��18�ĵ�����
	l1.insert(l1.begin(),2, 20);   //��posλ��ǰ�����4��20
	l1.insert(l1.begin(), arr, arr + 3);   //��posλ��ǰ���룬��������[arr,arr+3)������
	Print(l1);
	//////////////////////////////
	pos = ++l1.begin();
	pos = l1.erase(--l1.end());           //������һ��λ�õĵ�����
	//cout << *pos << endl;
	Print(l1);
	l1.erase(++l1.begin(), l1.end());     //ɾ��list��[l1.begin(),l1.end())���������
	Print(l1);
	//l1.resize();
}

void ListTest4()
{
	list<Date> l1;
	Date d(2018, 1, 1);
	l1.push_back(d);     //�������һ�ο�������
	//l1.push_back(1990, 2, 14);  //���Ϸ�
	l1.emplace_back(1997, 1, 1);    //ֱ�ӹ���
	l1.emplace_front(1999, 6, 11);
}

void ListTest5()
{
	vector<int> v{ 10, 10, 10 };
	list<int> l1{ 1, 2, 3, 4 };
	list<int> l2(v.begin(), v.end());
	l1.resize(2);
	l1.resize(10, 5);
	l1.swap(l2);       //����l1��l2
	Print(l1);
	Print(l2);
//	Print(v);
}
int main()
{
	//ListTest1();
	//ListTest2();
	//ListTest3();
	//ListTest4();
	ListTest5();
	return 0;
}