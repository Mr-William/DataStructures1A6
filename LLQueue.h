//*****************************************************************************************************
//
//		File:			LLQueue.h
//		
//		Student:		William Gibbs
//
//		Assignment:	 	Program  #6, QueueSimulation
//
//		Course Name:	Data Structures I 
//
//		Course Number:	COSC 3050 - 10
//
//		Due:			October 5, 2020 
//
//
//		This file containts the class definition for linked list implementation of a queue.		
//
//		Other files required: 
//			1.	Simulation.cpp - main driver program
//          2.  Node.h - This file contains the definition for node creation.
//			3.  Cashier.h - definition for Cashier structure.
//			4.  Customer.h - definition for Customer structure.
//			
//*****************************************************************************************************

#ifndef LLQUEUE_H
#define LLQUEUE_H

#include <new>
#include "Node.h"

//*****************************************************************************************************

template <typename T>
class LLQueue
{
private:
	Node<T>* front;
	Node<T>* rear;
public:
	LLQueue();
	~LLQueue();
	bool enqueue( const T& );
	bool dequeue( T& );
	bool peekFront( T& ) const;
	bool peekRear( T& ) const;
	bool isFull() const;
	bool isEmpty() const;
	int getSize() const;
};

//*****************************************************************************************************

template <typename T>
LLQueue<T> :: LLQueue()
{
	front = nullptr;
	rear = nullptr;
}

//*****************************************************************************************************

template <typename T>
LLQueue<T> :: ~LLQueue()
{
	Node<T>* pTemp = front;

	while ( pTemp != rear )
	{
		Node<T>* next = pTemp->next;
		delete pTemp;
		pTemp = next;
	}

	front = nullptr;
	rear = nullptr;
}

//*****************************************************************************************************

template <typename T>
bool LLQueue<T> :: enqueue( const T& dataIn )
{
	bool success = false;

	Node<T>* pNew = new Node<T>;

	pNew->data = dataIn;
	pNew->next = nullptr;

	if (front == nullptr)
	{
		front = pNew;
		rear = pNew;

		success = true;
	}
	else
	{
		rear->next = pNew;
		rear = pNew;
		rear->next = nullptr;

		success = true;
	}
	
	return success;
}

//*****************************************************************************************************

template <typename T>
bool LLQueue<T> :: dequeue( T& dataOut )
{
	bool success = true;

	if (front == nullptr)
		success = false;
	else
	{
		Node<T>* temp = front;

		dataOut = front->data;
		front = front->next;

		if (front == nullptr)
			rear = nullptr;
	}

	return success;
}

//*****************************************************************************************************

template <typename T>
bool LLQueue<T> :: peekFront( T& dataOut )const
{
	bool success = false;

	if ( front != nullptr )
	{
		dataOut = front->data;

		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename T>
bool LLQueue<T> :: peekRear( T& dataOut ) const
{
	bool success = false;

	if ( rear != nullptr )
	{
		dataOut = rear->data;

		success = true;
	}

	return success;
}

//*****************************************************************************************************

template <typename T>
bool LLQueue<T> :: isFull()const
{
	bool full = true;
	Node<T>* temp = new (nothrow) Node <T>;

	if ( temp != nullptr )
	{
		full = false;
		delete temp;
	}

	return full;
}

//*****************************************************************************************************

template <typename T>
bool LLQueue<T> :: isEmpty()const
{
	bool empty = true;

	if ( ( front != nullptr ) && ( rear != nullptr ) )
		empty = false;

	return empty;
}

//*****************************************************************************************************

template <typename T>
int LLQueue<T> :: getSize()const
{
	int count = 0;
	Node<T>* temp = front;

	while ( temp != nullptr )
	{
		temp = temp->next;
		count++;
	}

	return count;
}

//*****************************************************************************************************

#endif