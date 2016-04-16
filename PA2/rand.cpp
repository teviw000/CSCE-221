// // Evelyn Merizalde
// // Kyle Loyka
//
// #include <iostream>
// #include <fstream>
// #include <math.h>
// #include <time.h>
// #include <vector>
// #include <ctime>
// #include <cstdlib>
//
// using namespace std;
//
//
//
// int get_random(int min, int max){
//
// 	int range = max- min +1;
//
// 	return(rand()%range +min);
// }
//
//
// int main(){
//
// 	// generating random sets
//
// 	srand ( time(0) );
// 	vector<int>v;
// 	for(int i =0 ; i< 100000; i++)
// 	{
// 		v.push_back(get_random(0, 100000));
// 	}
//
// 	// making different sized random set files
// 	ofstream myfile;
// 	myfile.open ("rand10^2.txt");
//   myfile << 100 << endl;
// 	for( int i = 0; i < 100; i++ ){
// 		myfile <<v[i]<<endl;
// 	}
//   myfile.close();
//
// 	myfile.open ("rand10^3.txt");
//   myfile << 1000 << endl;
// 	for( int i = 0; i < 1000; i++ ){
// 		myfile <<v[i]<<endl;
// 	}
// 	myfile.close();
//
// 	myfile.open ("rand10^4.txt");
//   myfile << 10000 << endl;
// 	for( int i = 0; i < 10000; i++ ){
// 		myfile <<v[i]<<endl;
// 	}
//   myfile.close();
//
// 	myfile.open ("rand10^5.txt");
//   myfile << 100000 << endl;
// 	for( int i = 0; i < 100000; i++ ){
// 		myfile <<v[i]<<endl;
// 	}
//   myfile.close();
// 	// --------------------------------------------
//
//
// 	// making increasing order integer sets
// 	myfile.open ("incr10^2.txt");
//   myfile << 100 << endl;
// 	for( int i = 0; i < 100; i++ ){
// 		myfile <<i << endl;
// 	}
// 	myfile.close();
//
// 	myfile.open ("incr10^3.txt");
//   myfile << 1000 << endl;
// 	for( int i = 0; i < 1000; i++ ){
// 		myfile << i <<endl;
// 	}
// 	myfile.close();
//
// 	myfile.open ("incr10^4.txt");
//   myfile << 10000 << endl;
// 	for( int i = 0; i < 10000; i++ ){
// 		myfile << i <<endl;
// 	}
// 	myfile.close();
//
// 	myfile.open ("incr10^5.txt");
//   myfile << 100000 << endl;
// 	for( int i = 0; i < 100000; i++ ){
// 		myfile << i <<endl;
// 	}
// 	myfile.close();
// 	// --------------------------------------------
//
//
// 	// making decreasing order integer sets
// 	myfile.open ("decr10^2.txt");
//   myfile << 100 << endl;
// 	for( int i = 100; i > 0; --i ){
// 		myfile << i << endl;
// 	}
// 	myfile.close();
//
// 	myfile.open ("decr10^3.txt");
//   myfile << 1000 << endl;
// 	for( int i = 1000; i > 0; --i ){
// 		myfile << i <<endl;
// 	}
// 	myfile.close();
//
// 	myfile.open ("decr10^4.txt");
//   myfile << 10000 << endl;
// 	for( int i = 10000; i > 0; --i ){
// 		myfile << i <<endl;
// 	}
// 	myfile.close();
//
// 	myfile.open ("decr10^5.txt");
//   myfile << 100000 << endl;
// 	for( int i = 100000; i > 0; --i ){
// 		myfile << i <<endl;
// 	}
// 	myfile.close();
// 	// --------------------------------------------
//
// return 0;
//
//
// }
