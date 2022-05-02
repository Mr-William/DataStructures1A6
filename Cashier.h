//*****************************************************************************************************
//
//		File:			Cashier.h
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
//		This file containts the definition for Cashier structure.		
//
//		Other files required: 
//			1.	Simulation.cpp - main driver program
//          2.  Node.h - This file contains the definition for node creation.
//			3.  Customer.h - definition for Customer structure.
//			4.  LLQueue.h - Class definition for linked list implementation of a queue.
//			
//*****************************************************************************************************

#ifndef CASHIER_H
#define CASHIER_H

#include "LLQueue.h"
#include "Node.h"

//*****************************************************************************************************

struct Cashier
{
	int custID;
	int endTime;
	bool busy;

	Cashier();
};

//*****************************************************************************************************

Cashier :: Cashier()
{
	custID = 0;
	endTime = 0;
	busy = 0;
}

//*****************************************************************************************************

ostream& operator << (ostream& ostr, const Cashier& serv)
{
	ostr << "serving customer #" << serv.custID 
		 << " until time:  " << serv.endTime << endl;

	return ostr;
}

//*****************************************************************************************************

istream& operator >> (istream& istr, Cashier& serv)
{
	istr >> serv.custID;
	istr >> serv.endTime;

	return istr;
}

//*****************************************************************************************************

#endif