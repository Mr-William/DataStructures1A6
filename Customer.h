//*****************************************************************************************************
//
//		File:			Customer.h
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
//		This file containts the definition for Customer structure.		
//
//		Other files required: 
//			1.	Simulation.cpp - main driver program
//          2.  Node.h - This file contains the definition for node creation.
//			3.  Cashier.h - definition for Cashier structure.
//			4.  LLQueue.h - Class definition for linked list implementation of a queue.
//			
//*****************************************************************************************************

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "LLQUEUE.h"
#include "Node.h"

//*****************************************************************************************************

struct Customer
{
	int id;
	int arrivalTime;
	int serviceTime;

	Customer();

	friend ostream& operator << (ostream&, const Customer&);
	friend istream& operator >> (istream&, Customer&);
};

//*****************************************************************************************************

Customer :: Customer()
{
	id = 0;
	arrivalTime = 0;
	serviceTime = 0;
}

//*****************************************************************************************************

ostream& operator << (ostream& ostr, const Customer& cust)
{
	ostr << "Customer #" << cust.id << " has been enqueued.\n";

	return ostr;
}

//*****************************************************************************************************

istream& operator >> (istream& istr, Customer& cust)
{
	istr >> cust.id;
	istr >> cust.arrivalTime;
	istr >> cust.serviceTime;

	return istr;
}

//*****************************************************************************************************

#endif