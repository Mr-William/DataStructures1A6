//*****************************************************************************************************
//
//		File:			Simulation.cpp
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
//			1.	Customer.h - definition for Customer structure.
//          2.  Node.h - This file contains the definition for node creation.
//			3.  Cashier.h - definition for Cashier structure.
//			4.  LLQueue.h - Class definition for linked list implementation of a queue.
//			
//*****************************************************************************************************

#include <iostream>
#include <fstream>
#include <new>

using namespace std;

#include "LLQueue.h"
#include "Customer.h"
#include "Cashier.h"

//*****************************************************************************************************

void fillCustQueue(ifstream&, LLQueue<Customer>&, Customer&, int);
void processCust(LLQueue<Customer>&, Cashier[], const int);
bool isDone(Cashier[], LLQueue<Customer>&);

//*****************************************************************************************************

int main()
{
	const int NUM_CASHIERS = 3;
	LLQueue<Customer> custList;
	Customer custIn,
			 custOut;
	Customer custArr[50];
	Cashier serv[NUM_CASHIERS];
	int currentTime = 0,
		i = 0;
	ifstream custData;

	custData.open("customerList.txt");

	while (custData.is_open())
	{
		cout << "\nTime = " << currentTime << endl;
		
		for (int j = 0; j < i; j++)
		{
			if (custArr[j].arrivalTime == currentTime)
			{
				if (!custList.enqueue(custArr[j]))
					cout << "Error placing customer into queue.\n";
				else
				{
					cout << custArr[j];
					i--;
				}
			}
		}
		fillCustQueue(custData, custList, custIn, currentTime);
		if (custIn.arrivalTime != currentTime)
		{
			custArr[i] = custIn;
			i++;
		}
		
		processCust(custList, serv, currentTime);
		
		currentTime++;

		if (isDone(serv, custList))
			custData.close();
	}

	return 0;
}

//*****************************************************************************************************

void fillCustQueue(ifstream& data, LLQueue<Customer>& list, Customer& customerIn, int currTime)
{
	do
	{
		data >> customerIn;

		if (customerIn.arrivalTime == currTime)
		{
			if (!list.enqueue(customerIn))
				cout << "Error adding customer to queue.\n";
			else
				cout << customerIn;
		}
	} while ( (customerIn.arrivalTime == currTime) && (!data.eof()) );
}

//*****************************************************************************************************

void processCust(LLQueue<Customer>& custList, Cashier serv[], const int currTime)
{
	Customer c;
	
	for (int j = 0; j < 3; j++)
	{
		if ((serv[j].busy) && (serv[j].endTime == currTime))
			serv[j] = Cashier();
		
		if (serv[j].busy)
			cout << "Cashier #" << j + 1 << " is currently " << serv[j];

		if ( (!serv[j].busy) && (custList.dequeue(c)) )
		{
			serv[j].custID = c.id;
			serv[j].endTime = currTime + c.serviceTime;
			serv[j].busy = 1;

			cout << "Cashier #" << j + 1 << " has started " << serv[j];
		}

		if (serv[j].busy == 0)
			cout << "Cashier #" << j + 1 << " is not busy.\n";
	}
}

//*****************************************************************************************************

bool isDone(Cashier serv[], LLQueue<Customer>& custList)
{
	bool done = true;

	for (int j = 0; j < 3; j++)
	{
		if (serv[j].busy == 1)
			done = false;
	}

	if (done == true && custList.isEmpty())
		done = true;

	return done;
}

//*****************************************************************************************************

/*


Time = 0
Customer #1 has been enqueued.
Customer #2 has been enqueued.
Cashier #1 has started serving customer #1 until time:  7
Cashier #2 has started serving customer #2 until time:  3
Cashier #3 is not busy.

Time = 1
Customer #3 has been enqueued.
Cashier #1 is currently serving customer #1 until time:  7
Cashier #2 is currently serving customer #2 until time:  3
Cashier #3 has started serving customer #3 until time:  3

Time = 2
Cashier #1 is currently serving customer #1 until time:  7
Cashier #2 is currently serving customer #2 until time:  3
Cashier #3 is currently serving customer #3 until time:  3

Time = 3
Customer #4 has been enqueued.
Customer #5 has been enqueued.
Cashier #1 is currently serving customer #1 until time:  7
Cashier #2 has started serving customer #4 until time:  4
Cashier #3 has started serving customer #5 until time:  7

Time = 4
Cashier #1 is currently serving customer #1 until time:  7
Cashier #2 is not busy.
Cashier #3 is currently serving customer #5 until time:  7

Time = 5
Cashier #1 is currently serving customer #1 until time:  7
Cashier #2 is not busy.
Cashier #3 is currently serving customer #5 until time:  7

Time = 6
Cashier #1 is currently serving customer #1 until time:  7
Cashier #2 is not busy.
Cashier #3 is currently serving customer #5 until time:  7

Time = 7
Cashier #1 is not busy.
Cashier #2 is not busy.
Cashier #3 is not busy.

D:\OneDrive\Desktop\Webster\FA2020\DataStructures\DataStructures I\Week6\Simulation\Debug\Simulation.exe (process 29820) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .


*/