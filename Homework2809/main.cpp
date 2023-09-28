#include <iostream>
using namespace std;


struct Element
{
	char data;
	Element* Next;
};

class List
{
	Element* Head;
	Element* Tail;
	int Count;

public:
	List();
	~List();

	void Add(char data);
	void Del();
	void DelAll();

	void Print();

	int GetCount();

	void AddPosition(char UserData, int UserPos);
	void Del_Num(int i);
	int SearchPosition(char UserData);

};

List::List()
{
	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{
	DelAll();
}

int List::GetCount()
{
	return Count;
}



void List::Add(char data)
{
	Element* temp = new Element;
	temp->data = data;
	temp->Next = NULL;
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	else {
		Head = Tail = temp;
	}
}

void List::Del()
{
	Element* temp = Head;
	Head = Head->Next;
	delete temp;
}

void List::DelAll()
{
	while (Head != 0)
		Del();
}


void List::Del_Num(int i)
{
	Element* temp = Head;
	while (i > 2)
	{
		temp = temp->Next;
		i--;
	}
	Element* del = temp->Next;
	temp->Next = del->Next;
	delete del;

}

void List::AddPosition(char UserData, int UserPos)
{
	if (UserPos < 0 || UserPos > Count)
	{
		cout << "Unacceptable position" << endl;
		return;
	}
	else
	{
		if (UserPos == Count)
			Add(UserData);
		else if (UserPos == 1)
		{
			Element* newElem = new Element;
			newElem->data = UserData;
			newElem->Next = Head;
			Head = newElem;
			Count++;
		}
		else
		{
			Element* newElem = new Element;
			newElem->data = UserData;
			newElem->Next = NULL;

			int tempCount = 1;
			Element* temp = Head;

			while (tempCount != UserPos - 1)
			{
				temp = temp->Next;
				tempCount++;
			}
			newElem->Next = temp->Next;
			temp->Next = newElem;
			Count++;
		}
	}
}

void List::Print()
{
	Element* temp = Head;
	while (temp != 0)
	{
		cout << temp->data << " ";
		temp = temp->Next;
	}

	cout << "\n\n";
}


int List::SearchPosition(char UserData)
{
	Element* temp = Head;
	for (int i = 1; i != Count; i++)
	{
		if (temp->data == UserData)
			return i;
		else
			temp = temp->Next;
	}
	return NULL;
}


void main()
{

	List lst;

	char s[] = "Hello, World !!!\n";
	cout << s << "\n\n";
	int len = strlen(s);
	for (int i = 0; i < len; i++)
		lst.Add(s[i]);
	lst.Print();

	lst.Del_Num(5);
	lst.AddPosition('!', lst.GetCount());
	lst.Print();




}

