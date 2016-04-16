
// main.cpp
//Tests all functionality of the My_vec class.

#include <iostream>
#include <stdexcept>
#include "My_vec.h"
#include "My_vector.h"
using namespace std;

int main(){
try{
    // define an object v of My_vec type
		My_vec v;

		// insert 'B' at the rank 0 into the vector v
		v.insert_at_rank(0,'B');

		// use the overloaded operator << to display vector elements
		cout << v;

		// display the vector v size
		cout << v.get_size() << endl << endl;

		// insert 'A' at the rank 0 into the vector v
		v.insert_at_rank(0,'A');
		// use the overloaded operator << to display vector elements
		cout << v;

		// display the vector v size
		cout << v.get_size() << endl << endl;

		// insert 'D' at the rank 10 into the vector v
		v.insert_at_rank(10,'D');

		// use the overloaded operator << to display vector elements
		cout << v;

		// display the vector v size
		cout << v.get_size() << endl << endl;

		cout <<endl<<endl<<"removing at rank 2"<<endl<<endl;
		// remove a character at the rank 2 from the vector v
		v.remove_at_rank(2);
		// use the overloaded operator << to display vector elements
		cout<<v;

		// display the vector v size
		cout<<v.get_size()<<endl<<endl;

		// replace a character at the rank 2 by the character 'E'
		v.replace_at_rank(2,'E');
		// use the overloaded operator << to display vector elements
		cout<<v;

		// display the vector v size
		cout<<v.get_size()<<endl<<endl;

		// create a copy v1 of the vector v using a copy constructor
		My_vec v1(v);

		// use the overloaded operator << to display the vector v1
    cout<<endl<<endl<<"output v1"<<endl<<endl;
		cout<<v1;

		// replace a character at the rank 2 of the vector v1 with the character 'Y'
		v1.replace_at_rank(2,'Y');

		// use the overloaded operator << to display vector v1 elements
		cout<<endl<<endl<<"output v1, replace E with Y"<<endl<<endl;
		cout<<v1;

		// define an object v2 of My_vec type
		My_vec v2;

		// insert 'K' at the rank 0 into the vector v2
		v2.insert_at_rank(0,'K');

		// use the overloaded operator << to display vector elements
    cout<<endl<<endl<<"output v2"<<endl<<endl;
		cout<<v2;

		// display the vector v2 size
		cout<<v2.get_size()<<endl<<endl;

    // test the assignment operator and copy the vector v1 to v2
    v2 = v1;

		// use the overloaded operator << to display vector v2
    cout<<endl<<endl<<"v2 now equals v1"<<endl<<endl;
		cout<<v2;

		// display the vector v2 size
		cout<<v2.get_size()<<endl<<endl;

    // test the function find_max_index using v2
		cout << "max value index: "<<find_max_index(v2, v2.get_capacity())<<endl;

		// test the function sort_max using v2
		sort_max(v2);
		cout<<endl<<endl<<"list should be sorted by max to min"<<endl<<endl;
		cout<<v2;

		// replace in the vector v2 a character at the rank 14 with 'S'
		v2.replace_at_rank(14,'S');








		cout<<"Type: int"<<endl<<endl;
		My_vector<int>v3;
		v3.insert_at_rank(0,5);
		v3.insert_at_rank(0,1);
		v3.remove_at_rank(0);

		cout<<"size : "<<v3.get_size()<<endl;
		cout<<"max index: "<<find_max_index(v3,v3.get_size())<<endl;
		sort_max(v3);
		cout<<"sorting...\n";
		cout<<v3<<endl<<endl;

		cout<<"Type: char"<<endl<<endl;
		My_vector<char>v4;
		v4.insert_at_rank(0,'A');
		v4.insert_at_rank(0,'B');
		v4.remove_at_rank(0);

		cout<<"size : "<<v4.get_size()<<endl;
		sort_max(v4);
		cout<<"max index: "<<find_max_index(v4,v4.get_size())<<endl;
		cout<<"sorting...\n";
		cout<<v4<<endl<<endl;

		cout<<"Type: double"<<endl<<endl;
		My_vector<double>v5;
		v5.insert_at_rank(0,1.51);
		v5.insert_at_rank(0,1.5);
		v5.remove_at_rank(0);

		cout<<"size : "<<v5.get_size()<<endl;
		sort_max(v5);
		cout<<"max index: "<<find_max_index(v5,v5.get_size())<<endl;
		cout<<"sorting...\n";
		cout<<v5<<endl<<endl;

}

catch(exception &error){
	cerr << "Error: " << error.what() << endl;
}
}
