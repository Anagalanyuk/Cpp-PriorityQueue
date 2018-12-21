#pragma once

template<typename T>
class PriorityQueue;

template<typename T>
class Node
{
	friend class PriorityQueue<T>;

public:
	Node(const T value, int priority);
	~Node();
private:
	Node<T>* next = nullptr;
	Node<T>* previos = nullptr;
	T m_value;
	unsigned int m_priority = 1;
};

template<typename T>
Node<T>::Node(const T value, int priority):
	m_value(value),
	m_priority(priority)
{
	//std::cout << "\nconstructor";
}

template<typename T>
Node<T>::~Node()
{
	//std::cout << "\ndestructor";
}
