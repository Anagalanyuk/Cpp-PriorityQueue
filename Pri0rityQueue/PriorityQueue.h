#pragma once

#include"Node.h"

template<typename T>
class PriorityQueue
{
public:
	PriorityQueue();
	PriorityQueue(const PriorityQueue& source);
	PriorityQueue(PriorityQueue&& source);
	~PriorityQueue();

	PriorityQueue& operator=(const PriorityQueue& right);
	PriorityQueue& operator=(PriorityQueue&& right);


	void Print();
	void Clear();
	T Dequeue();
	void Enqueue(const T item, const int priority);
	unsigned int GetSize() const;
	bool IsEmpty() const;
	T& Peek();
	const T& Peek() const;

private:
	Node<T>* root = nullptr;
	unsigned int m_size = 0;
};

template<typename T>
PriorityQueue<T>::PriorityQueue()
{
}

template<typename T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue& source)
{
	if (!source.IsEmpty())
	{
		Node<T>* node = source.root;
		while (node != nullptr)
		{
			this->Enqueue(node->m_value,node->m_priority);
			node = node->next;
		}
	}
}

template<typename T>
PriorityQueue<T>::PriorityQueue(PriorityQueue&& source) :
	root(source.root),
	m_size(source.m_size)
{
	source.root = nullptr;
	source.m_size = 0;
	//std::cout << "move";
}

template<typename T>
PriorityQueue<T>::~PriorityQueue()
{
	if (this->root != nullptr)
	{
		this->Clear();
	}
}


template<typename T>
PriorityQueue<T>& PriorityQueue<T>::operator=(const PriorityQueue& right)
{
	if (!this->IsEmpty())
	{
		this->Clear();
	}
		Node<T>* node = right.root;
		while (node != nullptr)
		{
			this->Enqueue(node->m_value,node->m_priority);
			node = node->next;
		}

	return *this;
}

template<typename T>
PriorityQueue<T>& PriorityQueue<T>::operator=(PriorityQueue&& right)
{
	if (!this->IsEmpty())
	{
		this->Clear();
	}
	root = right.root;
	m_size = right.m_size;
	right.root = nullptr;
	right.m_size = 0;
	//std::cout << "move";
	return *this;
}



template<typename T>
void PriorityQueue<T>::Print()
{
	if (root != nullptr)
	{
		Node<T>* node = root;
		{
			while (node != nullptr)
			{
				std::cout/* << "(p" << node->m_priority << ")"*/<< node->m_value << " ";
				node = node->next;
			}
		}
	}
}

template<typename T>
void PriorityQueue<T>::Clear()
{
	if (this->root != nullptr)
	{
		Node<T>* node = root->next;
		delete root;
	    root = nullptr;
		m_size -= 1;
		Node<T>* next = node;
		while (node != nullptr)
		{
			node = next->next;
			delete next;
			m_size -= 1;
			next = node;

		}
	}

}

template<typename T>
T PriorityQueue<T> ::Dequeue()
{
	T result;
	if (this->root != nullptr)
	{
		Node<T>* temp = root->next;
		if (!this->IsEmpty())
		{
			result = root->m_value;

			delete root;
			m_size -= 1;
			this->root = temp;
			if (root != nullptr)
			{
				root->previos = nullptr;
			}
		}
	}
	return result;
}

template<typename T>
void PriorityQueue<T>::Enqueue(const T item, const int priority)
{
	Node<T>* newNode = new Node<T>(item, priority);
	Node<T>* temp = this->root;

		if (root == nullptr)
		{
			root = newNode;
			m_size += 1;
		}
		else if (temp->m_priority < newNode->m_priority)
	    {
			root = newNode;
			newNode->next = temp;
			temp->previos = newNode;
		    m_size += 1;
	 	}
		else if (temp->m_priority == newNode->m_priority)
		{
			if (temp->next == nullptr)
			{
				temp->next = newNode;
				newNode->previos = temp;
				m_size += 1;
			}
			else
			{
				while (temp->next->m_priority == newNode->m_priority)
				{
					temp = temp->next;

					if (temp->next == nullptr)
					{
						break;
					}
				}
					if (temp->next != nullptr)
					{
						newNode->previos = temp;
						temp->next->previos = newNode;
						newNode->next = temp->next;
						temp->next = newNode;
						m_size += 1;
					}
					else
					{
						temp->next = newNode;
						newNode->previos = temp;
						m_size += 1;
					}
				}
		}
		else
		{
			if (temp->next != nullptr)
			{
				while (newNode->m_priority < temp->next->m_priority)
				{
					temp = temp->next;
					if (temp->next == nullptr)
					{
						break;
					}
				}
				if (temp->next != nullptr)
				{
					while (newNode->m_priority == temp->next->m_priority)
					{
						temp = temp->next;
						if (temp->next == nullptr)
						{
							break;
						}
					}
				}
			}
			if (temp->next != nullptr)
		    {
				temp->next->previos = newNode;
				newNode->next = temp->next;
				temp->next = newNode;
				newNode->previos = temp;
				m_size += 1;
			}
			else
			{
				temp->next = newNode;
				newNode->previos = temp;
				m_size += 1;
			}
		}
}

template<typename T>
unsigned int PriorityQueue<T>::GetSize()const
{
	return m_size;
}

template<typename T>
bool PriorityQueue<T>::IsEmpty() const
{
	bool result = true;
	if (m_size > 0)
	{
		result = false;
	}
	return result;
}

template<typename T>
T& PriorityQueue<T>::Peek()
{
	return root->m_value;
}

template<typename T>
const T& PriorityQueue<T>::Peek() const
{
	return root->m_value;
}
