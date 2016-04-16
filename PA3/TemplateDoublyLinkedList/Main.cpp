// Kyle Loyka
// CSCE 221 - 505
// Assignment 3
//
// Main.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include "TemplateDoublyLinkedList.h"
#include "Record.h"
#include <string>
#include <vector>
using namespace std;

long int string_to_number(string text){
	stringstream ss(text);
	long int number;
	return ss >> number ? number : 0;
}

void read_file(vector<DoublyLinkedList<Record> >& phonebook){
	ifstream file;
	file.open("Phonebook.txt");

	string first,last,uin_string,phone_string,buf;
	long int uin,phone;

	while(!file.eof()){
		getline(file,last);
		getline(file,first);
		getline(file,uin_string);
		getline(file,phone_string);
		getline(file,buf);

		uin = string_to_number(uin_string);
		phone = string_to_number(phone_string);

		// make new node with data
		Record data(first,last,uin,phone);

		switch(last[0])
		{
			case 'A':
				phonebook[0].insertOrderly(data);
				break;
			case 'B':
				phonebook[1].insertOrderly(data);
				break;
			case 'C':
				phonebook[2].insertOrderly(data);
				break;
			case 'D':
				phonebook[3].insertOrderly(data);
				break;
			case 'E':
				phonebook[4].insertOrderly(data);
				break;
			case 'F':
				phonebook[5].insertOrderly(data);
				break;
			case 'G':
				phonebook[6].insertOrderly(data);
				break;
			case 'H':
				phonebook[7].insertOrderly(data);
				break;
			case 'I':
				phonebook[8].insertOrderly(data);
				break;
			case 'J':
				phonebook[9].insertOrderly(data);
				break;
			case 'K':
				phonebook[10].insertOrderly(data);
				break;
			case 'L':
				phonebook[11].insertOrderly(data);
				break;
			case 'M':
				phonebook[12].insertOrderly(data);
				break;
			case 'N':
				phonebook[13].insertOrderly(data);
				break;
			case 'O':
				phonebook[14].insertOrderly(data);
				break;
			case 'P':
				phonebook[15].insertOrderly(data);
				break;
			case 'Q':
				phonebook[16].insertOrderly(data);
				break;
			case 'R':
				phonebook[17].insertOrderly(data);
				break;
			case 'S':
				phonebook[18].insertOrderly(data);
				break;
			case 'T':
				phonebook[19].insertOrderly(data);
				break;
			case 'U':
				phonebook[20].insertOrderly(data);
				break;
			case 'V':
				phonebook[21].insertOrderly(data);
				break;
			case 'W':
				phonebook[22].insertOrderly(data);
				break;
			case 'X':
				phonebook[23].insertOrderly(data);
				break;
			case 'Y':
				phonebook[24].insertOrderly(data);
				break;
			case 'Z':
				phonebook[25].insertOrderly(data);
				break;
			default:
				cout <<"FILE READ ERROR\n";
				file.close();
				return;
		}
	}
		file.close();
}

void phonebook_dump(vector<DoublyLinkedList<Record> >& phonebook){
	for (int i = 0; i < 26; ++i){
		//cout <<"\n";
		cout << phonebook[i];
	}
}

void search_ll(DoublyLinkedList<Record>& dll,string last){
	if ( dll.isEmpty()){
		cout <<"Not Found\n";
		return;
	}

	//iterate through the list
	DListNode<Record>* p = dll.getFirst();
	while (p != dll.getLast()->getNext()){
		if( (p->getElem().get_last() == last) && (p->getNext()->getElem().get_last() != last)){
			cout <<"Found!\n";
			cout <<p->getElem();
			return;
		}
		else if((p->getElem().get_last() == last) && (p->getNext()->getElem().get_last() == last)){
			cout <<"Enter First Name\n";
			string first;
			cin >> first;
			while(p != dll.getLast()->getNext()){
				if((p->getElem().get_first() == first) && (p->getNext()->getElem().get_first() != first)){
					cout << "Found!\n";
					cout << p->getElem();
					return;
				}
				else if ((p->getElem().get_first() == first) && (p->getNext()->getElem().get_first() == first)){
					cout <<"Enter UIN\n";
					int uin;
					cin >> uin;
					while (p != dll.getLast()->getNext()){
						if ((p->getElem().get_uin() == uin)){
							cout << "Found!\n";
							cout << p->getElem();
							return;
						}
						p = p->getNext();
					}
					cout <<"Not Found\n";
					return;
				}
				p= p->getNext();
			}
			cout <<"Not Found\n";
			return;
		}
		p = p->getNext();
	}
	cout <<"Not Found\n";
	return;
}

void search_vec(vector<DoublyLinkedList<Record> >& phonebook){
	cout <<"Search:\n";
	cout <<"Enter Last Name, with a capital first letter\n";
	string last;
	cin >> last;

	switch(last[0])
	{
		case 'A':
			search_ll(phonebook[0],last);
			break;
		case 'B':
			search_ll(phonebook[1],last);
			break;
		case 'C':
			search_ll(phonebook[2],last);
			break;
		case 'D':
			search_ll(phonebook[3],last);
			break;
		case 'E':
			search_ll(phonebook[4],last);
			break;
		case 'F':
			search_ll(phonebook[5],last);
			break;
		case 'G':
			search_ll(phonebook[6],last);
			break;
		case 'H':
			search_ll(phonebook[7],last);
			break;
		case 'I':
			search_ll(phonebook[8],last);
			break;
		case 'J':
			search_ll(phonebook[9],last);
			break;
		case 'K':
			search_ll(phonebook[10],last);
			break;
		case 'L':
			search_ll(phonebook[11],last);
			break;
		case 'M':
			search_ll(phonebook[12],last);
			break;
		case 'N':
			search_ll(phonebook[13],last);
			break;
		case 'O':
			search_ll(phonebook[14],last);
			break;
		case 'P':
			search_ll(phonebook[15],last);
			break;
		case 'Q':
			search_ll(phonebook[16],last);
			break;
		case 'R':
			search_ll(phonebook[17],last);
			break;
		case 'S':
			search_ll(phonebook[18],last);
			break;
		case 'T':
			search_ll(phonebook[19],last);
			break;
		case 'U':
			search_ll(phonebook[20],last);
			break;
		case 'V':
			search_ll(phonebook[21],last);
			break;
		case 'W':
			search_ll(phonebook[22],last);
			break;
		case 'X':
			search_ll(phonebook[23],last);
			break;
		case 'Y':
			search_ll(phonebook[24],last);
			break;
		case 'Z':
			search_ll(phonebook[25],last);
			break;
		default:
			cout <<"INPUT ERROR\n";
			return;
	}

	return;
}

int main(){

	vector<DoublyLinkedList<Record> >phonebook;
	for (int i = 0; i < 26; ++i){
		DoublyLinkedList<Record> node;
		phonebook.push_back(node);
	}

	read_file(phonebook);

	char in = 'y';
	while (in == 'y'){
		search_vec(phonebook);
		cout <<"search again? (y/n) ";
		cin >> in;
	}

	in = 'n';
	cout <<"Dump phonebook?(y/n) ";
	cin >> in;
	if (in == 'y'){
		cout << "Dumping phonebook\n";
		cout << "------------------------------------\n";
		phonebook_dump(phonebook);
	}

return 0;
};
