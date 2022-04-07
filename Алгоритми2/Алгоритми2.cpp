
#include <iostream>
using namespace std;

template <typename T>
class LIST
{
public:
	LIST();
	~LIST();

private:
	template <typename T>
	struct NODE
	{
	public:
		NODE* pNext;
		T data;
		NODE(T data = T(), NODE* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;

		}
	};
	int Size;
	NODE<T>* head;
public:
	
	//видаляє перший обєкт в списку
	void pop_front();

	//добавляэ елемент в кынець списку
	void push_back(T data);

	//очиска списку
	void clear();

	//створює порожній список
	void MAKENULL();

	//повертає кінець списку
	NODE<T>* END()
	{
		NODE<T>* current = this->head;
		while (current != nullptr)
		{
			current = current->pNext;
		}
		return current;
	}

	//повертає початок списку
	NODE<T>* FIRST()
	{
		return head;
	}

	//додає елемент до списку в задану позицію
	void INSERT(T data, int index);

	//видаляє елемент з списку
	void DELETE(int index);

	//знаходить позицію елементу в списку
	void LOCATE(T data);
	
	//друкує всі елементи списку
	void PRINTLIST();
	
	//повертає значення елементу списку
	void RETRIEVE(int index);
	
	//повертає вказівник на наступний елемент списку
	NODE<T>* NEXT(int index)
	{
		int counter = 0;
		NODE<T>* current = this->head;
		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->pNext;
			}
			current = current->pNext;
			counter++;
		}
	}

	//кілікість елементів у списку
	int GetSize()
	{
		return Size;
	}
	T& operator[](const int index);

};
template <typename T>
LIST<T>::LIST()
{
	Size = 0;
	head = nullptr;

}

template <typename T>
LIST<T>::~LIST()
{
	clear();
}

template<typename T>
void LIST<T>::pop_front()
{
	NODE<T> *temp=head;
	head = head->pNext;
	delete temp;
	Size--;
}

template <typename T>
void LIST<T>:: push_back(T data)
{
	if (head == nullptr)
	{
		head = new NODE<T>(data);
	}
	else
	{
		NODE<T>* current = this->head;
		while (current->pNext !=nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new NODE<T>(data);
	}
	Size++;

}

template<typename T>
void LIST<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename T>
void LIST<T>::INSERT(T data, int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		NODE<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		NODE<T>* newNODE = new NODE<T>(data, previous->pNext);

		previous->pNext = newNODE;

		Size++;
	}
}

template<typename T>
void LIST<T>::DELETE(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		NODE<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}


		NODE<T>* toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;
	}
}

template<typename T>
void LIST<T>::LOCATE(T data)
{
	int counter=0;
	NODE<T>* current = *this->head;
	while (current != nullptr)
	{
		if (current->data == data)
		{
			return counter;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void LIST<T>::PRINTLIST()
{
	int value = Size;
	NODE<T>* current = this->head;
	while (value)
	{
		cout << current->data << " ";
		current = current->pNext;
		value--;
	}
	cout << endl;
}

template<typename T>
void LIST<T>::RETRIEVE(int index)
{
	int counter = 0;
	NODE<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current ->pNext;
		counter++;
	}
}


template<typename T>
void LIST<T>::MAKENULL()
{
	head = nullptr;
}


template<typename T>
T& LIST<T>::operator[](const int index)
{
	int counter = 0;
	NODE<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

int main()
{
	setlocale(LC_ALL, "ukr");
	LIST<int>lst;

	lst.push_back(5);
	lst.push_back(10);
	lst.push_back(22);
	lst.PRINTLIST();

	
	
	return 0;
}

