//*****************************************************************************************************
//
//		File:			Node.h
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
//		This file contains the definition for node creation.
//
//		Other files required: 
//			1.	Simulation.cpp - main driver program
//          2.  Customer.h - definition for Customer structure.
//			3.  Cashier.h - definition for Cashier structure.
//			4.  LLQueue.h - Class definition for linked list implementation of a queue.
//			
//*****************************************************************************************************

#ifndef NODE_H
#define NODE_H

//*****************************************************************************************************

template <typename TYPE>
struct Node
{
	TYPE data;
	Node <TYPE>* next;
	Node();
	Node(TYPE d, Node<TYPE>* n = nullptr);
};

//*****************************************************************************************************

template <typename TYPE>
Node <TYPE> ::Node()
{
	TYPE data;
	next = nullptr;
}

//*****************************************************************************************************

template <typename TYPE>
Node <TYPE> ::Node(TYPE d, Node <TYPE>* n)
{
	data = d;
	next = n;
}

//*****************************************************************************************************

#endif