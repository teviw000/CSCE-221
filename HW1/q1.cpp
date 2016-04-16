// Kyle Loyka
// HOMEWORK 1; question 1

#include <iostream>
#include <string>
#include <stdexcept>
#include <stdlib.h>
#include <vector>
using namespace std;

struct data_set{
  int range;
  int answer;
  int guesses;
};

void print_vec(vector<data_set>d){
  for (int i = 0; i < d.size(); ++i){
    cout << "Range: "<< d[i].range << " True Answer: " << d[i].answer << " Guesses: " << d[i].guesses << endl;
  }
}

// this function is used for the program to simulate and test itself
string check(int answer, int number){

  // returns "FOUND" if answer is guessed
  if (answer == number) return "yes";

  //answer is smaller than guessed number
  else if (answer < number) return "lower";

  //answer is larger than guessed number
  else if (answer > number) return "higher";
  else {
    throw;
    return "ERROR";
  }
};


int comp_guess(int min, int max, data_set& dataset){
  try{

  // general case for computing midpoint
  int midpoint = (max-min)/2 + min;
  ++dataset.guesses;

  cout <<"\nDid you pick "<< midpoint << " ?\n";
  string reply;
  cin.clear();
  cin >> reply;

  // input handling
  if (reply!="yes" && reply!="higher" && reply!="lower")
    throw invalid_argument( "invalid input");
    if ( (reply=="higher")  && midpoint >=max)
    throw invalid_argument( "invalid input" );
  else if ( (reply=="lower") && midpoint <=min)
    throw invalid_argument( "invalid input" );

  // responding to reply from checking function
  if (reply == "yes"){
    cout << "answer is : "<< midpoint << endl;
    dataset.answer = midpoint;
   return midpoint;
  }
  else if (reply == "lower"){
    if ((midpoint-min)/2 < 1)
      midpoint = midpoint - 1;
    return comp_guess(min,midpoint,dataset);
  }
  else if (reply == "higher"){
    if ((max-midpoint)/2 < 1)
      midpoint = midpoint + 1;
    return comp_guess(midpoint,max,dataset);
  }

  }
  catch(exception &error){
     cerr << "Error: " << error.what() << endl;
   }


}

void human_guess(){
    int range = 1;
    cout <<"\nNow, the computer will pick a number, and the human must guess";
    cout <<"\nSet the range of numbers from 1:";
    cin >> range;
    if (range < 0 || 4097 < range)
      throw invalid_argument("invalid input");
    cout <<"\n\nGenerating random number...\n";

    int count = 0;
    int in;
    bool finished = false;
    int generated = 0;
    generated = rand() % range + 1;

    while (count < 6 && !finished){
      cout << 6-count << " tries left. "<< "Guess a number: ";
      cin >> in;
      ++count;
      if (in == generated){
        cout << "You guessed correct!\n";
        finished = true;
      }
      else if (count < 6){
        cout << "Nope! Guess again\n";
      }
      else cout <<"\nOut of tries. Better luck next time\nThe number was "<<generated<<endl;
    }

}

int main(){
  try{

  bool play = true;
  vector<data_set>data;
  int count = 0;

  while(play){
    cout<< "Set the range: ";
    int range = 1;
    cin >> range;

    data_set test;
    test.range = range;
    test.answer = 0;
    test.guesses = 0;
    data.push_back(test);

    if (range < 0 || 4097 < range)
      throw invalid_argument("invalid input");

    comp_guess(1,range,data[count]);
    ++count;

    cout << "Play again? (yes/no)"<<endl;
    string s;
    cin >> s;
    if(s == "yes") play = true;
    else if (s == "no") play = false;
    else play = false;
  }
    cout << "Collected Data::\n\n"<<endl;
    print_vec(data);
    cout <<"\n--------------------------------------------------\n";

    human_guess();

  }
  catch(exception &error){
     cerr << "Error: " << error.what() << endl;
   }

return 0;
}
