// Kyle Loyka
// CSCE 221 - 505
// Assignment 3
//
// Record.h

#include <iostream>
#include <string>
using namespace std;

class Record{
	private:
		string first;
		string last;
		long int UIN;
		long int phone;
	public:
		Record(string f ="", string l="", long int u=0, long int p=0)
			: first(f), last(l), UIN(u), phone(p) {}
		string get_first() const {return first;}
		string get_last() const {return last;}
		long int get_uin() const {return UIN;}
		long int get_phone() const {return phone;}
};

ostream& operator<<(ostream& out, const Record& r){
	cout <<r.get_first() << " "<< r.get_last()<< endl;
	cout << "UIN:   "<< r.get_uin()<< endl;
	cout << "Phone: "<< r.get_phone() << endl;
	cout << endl;
	return out;
};

inline bool operator<(const Record& l, const Record& r){
	if ( l.get_last() < r.get_last() ){
		//cout << l.get_last() <<" < "<< r.get_last()<<endl;
		return true;
	}
	else if ( (l.get_last() == r.get_last() ) && (l.get_first() < r.get_first() ) ){
		//cout << l.get_first() <<" " << l.get_last() <<" < "<< r.get_first()<<" "<< r.get_last()<<endl;
		return true;
	}
	else if ( (l.get_last() == r.get_last() ) && (l.get_first() == r.get_first() ) && (l.get_uin() < r.get_uin() ) ){
		//cout << l.get_uin() <<" < "<< r.get_uin()<<endl;
		return true;
	}

	else return false;
};
