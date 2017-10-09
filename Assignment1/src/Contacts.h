/*
 * Contacts.h
 *
 *  Created on: Oct 4, 2017
 *      Author: beverlyackah
 */

#ifndef CONTACTS_H_
#define CONTACTS_H_



#include <iostream>
#include <sstream>
using namespace std;

class Contacts {
private:
	int infoContact;
	string firstname;
	string lastname;
public:
	Contacts();
	Contacts( string firstname, string lastname,int infoContact);
	string getDetails();
	string getName();
	int getNumber();
	friend void printContacts(Contacts contact);
	Contacts& operator=(const Contacts &rhs);
	virtual ~Contacts();
};

#endif /* CONTACTS_H_ */
