#include <iostream>
#include <cctype>
#include <cstring>
#include <windows.h>
#include <cstdio>
#include <fstream>
#include <string>
using namespace std;
class MyString {
	char* str;
public:
	MyString();
	MyString(int length, const char* gf);
	~MyString();
	void Set(int lenthstr);
	void Update();
	void Print();
	MyString(const MyString& obj);
};
MyString::MyString(const MyString& obj)
{
	str = new char[strlen(obj.str)+1];
	strcpy(str, obj.str);
	cout << "Сработал конструктор копирования!\n";
}
MyString::MyString() 
{
	cout << "Сработал конструктор по умолчанию!\n";
	str = new char[1];
	str[0] = '\0';
}
MyString::MyString(int length, const char* gf)
{
	cout << "Сработал конструктор с параметром!\n";
	str = new char[length];
	strcpy(str, gf);
}
MyString::~MyString()
{
	cout << "Сработал деструктор!\n";
	delete[] str;
}
void MyString::Set(int lenthstr)
{
	cout << "Сработал метод ввода строки!\n";
	delete[] str;
	str = new char[lenthstr];
	cout << "Введите строку, которую хотите изменить: ";
	cin.getline(str, lenthstr);
}
void MyString::Print() 
{
	cout << "Сработал метод вывода строки!\n";
	cout << "Введенная строка: ";
	cout << str << "\n";
}
void MyString::Update()
{
	cout << "Сработал метод изменения строки!\n";

	ofstream fout("Text.txt", ios_base::app);
	fout << "Исходная строка: " << str;
	string str1 = str;
	if (strlen(str) <= 5)
	{
		cout << "Строка слишком короткая!\n";
	}
	else if (str1.find(' ') == -1)
	{
		cout << "В строке нет пробелов!\n";
	}
	else
	{
		cout << "Искомая подстрока до первого пробела: ";
		fout << "\n" << "Измененная строка: ";
		for (int i = 0; i <= str1.find(' '); i++)
		{
			fout << str[i];
			cout << str[i];
		}
		cout << endl;
		fout << endl;
	}
	fout.close();
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	MyString a;
	a.Set(1024);
	a.Update();
	a.Print();
	
	
	
	
	
	
	MyString b(1024, "Строка, подлежащая изменению в конструкторе с параметром!");
	b.Update();
	b.Print();
}