//============================================================================
// Name        : Assignment 1 - Phonebook Application Program
// Author      : Beverly Ackah
// Version     : September 2017
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "contacts.h"
#include <fstream>
using namespace std;

int size = 0;
int capacity = 300;

Contacts* contactData ;//= new Contacts [capacity];


void expandArray(){
	//cout<<"Expanding "<<endl;
	capacity *= 2;
	Contacts* resize_arr = new Contacts[capacity];
	for(int i = 0; i<size; i++)
		resize_arr[i] = contactData[i];
	contactData = resize_arr;
	delete [] resize_arr;
}

void loadData(string data){
	ifstream input;
	ifstream linein;
	string contactDetails[3];
	input.open(data);

	if(!input.is_open()){
		return ;
	}
	string line, first, last;
	int number;
	int i =0;
	while(input){

		getline(input,line, ' ');

		if(input && line != ""){

			first = line;
			getline(input,line, ' ');
			last = line;
			getline(input,line);
			number = stoi(line);
			Contacts newContact(first,last,number);
			// newContact.getDetails();
			if(size == capacity){
				expandArray();
			}

			contactData[size] = newContact;
			size++;
			line="";
		}

	}
}

int main() {
	contactData = new Contacts[capacity];
	cout << "*** My Phonebook Application ***" << endl;
	loadData("phonebook.txt");
	char operation=' ';

	do{
		cout << "Please choose an operation:" << endl;
		cout << " A(Add) | S(Search) | D(Delete) | L(List) | Q(Quit): " << endl;
		cin>>operation;
		switch(operation){
		case 'A' :{
			string firstname, lastname;
			int number;
			cout<<"Enter a first and last name"<<endl;
			cin>>firstname;
			cin>>lastname;
			cout<<"Enter a number"<<endl;
			cin>>number;
			cin.clear();
			Contacts contact(firstname,lastname,number);
			cout<<"Contact successfully added!"<<endl; //cout<<"Your name is "<<firstname<<" And "<<lastname<<endl;
			contactData[size] = contact;
			size +=1;

			break;
		}
		case 'S':{
			string name;
			int number;
			bool found = false;
			cout<<"Enter a name"<<endl;
			cin.ignore();
             getline(cin, name);
			for(int i =0; i< size; i++){
				if(contactData[i].getName() == name){
					found = true;
					cout<<"Phone : "<<contactData[i].getNumber()<<endl;
				}
			}
			if(!found){
				cout<<"Contact was not found in the system"<<endl;
			}
			break;
		}
		case 'D':{
						string name;
						bool found = false;
						cout<<"Enter a name"<<endl;
						cin.ignore();
                         getline(cin, name);
						for(int i =0; i< size; i++){
							if(contactData[i].getName() == name){
								found = true;
								for(int j = i; j < size-1 ; j++){
									contactData[i] = contactData[i+1];
								}
								size -=1;
								break;
							}
						}
						if(!found){
							cout<<"Contact was not found in the system"<<endl;
						}
						else{
							cout<<"Contact was successfully deleted"<<endl;
						}
						break;
		}
		case 'L':{
			for(int i =0; i< size; i++){
				printContacts(contactData[i]);
			}
		}
		default:break;
		}



	} while(operation != 'Q'); //whats going to be the condition?

	cout<<"Thank you for using the system"<<endl;


	return 0;
}
