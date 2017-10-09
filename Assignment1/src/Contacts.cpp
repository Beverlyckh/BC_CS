/*
 * Contacts.cpp
 *
 *  Created on: Oct 4, 2017
 *      Author: beverlyackah
 */

#include "Contacts.h"

Contacts::Contacts() {
	// TODO Auto-generated constructor stub

}

Contacts::Contacts( string firstname, string lastname,int infoContact){
   this->firstname = firstname;
   this->lastname = lastname;
   this->infoContact = infoContact;
}

string Contacts::getDetails() {
	// TODO Auto-generated destructor stub
	cout<<this->firstname<<" "<<this->lastname<<" "<<this->infoContact<<endl;
}

Contacts& Contacts::operator=(const Contacts &rhs){
	if( this != &rhs){
		firstname = rhs.firstname;
		lastname = rhs.lastname;
		infoContact = rhs.infoContact;
	}
	return *this;
}

void printContacts(Contacts contact){
	cout<<contact.firstname<<" "<<contact.lastname<<" "<<contact.infoContact<<endl;
}
int Contacts::getNumber(){
	return infoContact;
}
string Contacts::getName(){
	stringstream ss;
	ss<<firstname<<" "<<lastname;
	return ss.str();
}
Contacts::~Contacts() {
	// TODO Auto-generated destructor stub
}

