#ifndef MY_VEC_CPP
#define MY_VEC_CPP

#include "My_vec.h"

#include <iostream>
#include <string>


using namespace std;


My_vec::My_vec(){
    size = 0;
    capacity = 0;
    ptr = NULL;
  }
My_vec::~My_vec(){
      delete[] ptr;
  }
My_vec::My_vec(const My_vec& vec){
  *this = vec;
}
int My_vec::get_size() const{
  return size;
}
My_vec& My_vec::operator=(const My_vec& vec){
  size = vec.get_size();
  capacity = vec.get_capacity();
  if( ptr != NULL) delete[] ptr;
  ptr = new char[capacity];
  for (int i = 0; i < vec.get_capacity(); ++i){
    ptr[i] = '\0';
  }
  for(int i = 0; i < vec.get_capacity(); ++i){
    ptr[i] = vec[i];
  }
  return *this;
}
int My_vec::get_capacity() const{
  return capacity;
}
char& My_vec::operator[](int i){
  if( i > (capacity-1) )
  {
      cout << "Index out of bounds" <<endl;
  }
  return this->ptr[i];
}
char& My_vec::operator[](int i) const{
  if( i > (capacity-1) )
  {
      cout << "Index out of bounds" <<endl;
  }
  return this->ptr[i];
}
bool My_vec::is_empty() const{
  if(size == 0) return true;
  else return false;
}
char& My_vec::elem_at_rank(int r) const{
  return ptr[r];
}
void My_vec::insert_at_rank(int r, const char& elem){
  int old_capacity = capacity;
  char *temp;

  if (capacity == 0)
  {
    size = 1;
    capacity = 1;
    ptr = new char[size];
    ptr[0] = elem;
    return;
  }

  else{

    if ( (size+1) > capacity ) //resize
    {
      capacity = 2 * capacity;
    }

    if (r > capacity)
    {
      while (r > capacity)
      {
        capacity = 2 * capacity;
      }

    }

    temp = new char[capacity];
    for (int i = 0; i < capacity; ++i){
      temp[i] = '\0';
    }
    ++size;
    for (int i = 0; i < old_capacity; ++i){
      temp[i] = ptr[i];
    }
    delete[] ptr;
    ptr = new char[capacity];
    bool replaced = false;
    for (int i = 0; i < capacity; ++i){

      bool cont = true;

      if (i == r){
        ptr[i] = elem;
        replaced = true;
        cont = false;
      }
      if (cont){
        ptr[i] = temp[i];
      }
      if (cont & replaced){
        ptr[i] = temp[i-1];
      }


    }

  delete[] temp;


  }




}
void My_vec::replace_at_rank(int r, const char& elem){
  for (int i = 0; i < capacity; ++i){
    if (i == r) {
      if (elem == '\0' & ptr[i] != '\0') --size;
      if (elem != '\0' & ptr[i] == '\0') ++size;
      ptr[i] = elem;
    }
  }
}
void My_vec::remove_at_rank(int r){
  char *temp = new char[capacity];
  for (int i = 0; i < capacity; ++i){
    temp[i] = ptr[i];
  }
  bool no_resize = false;
  for (int i = capacity/2; i < capacity; ++i){
    if (ptr[i] !='\0') no_resize = true;
  }

  //check if need to resize

  if( ((size-1) <= capacity/2) & (!no_resize) ){
    capacity = capacity/2;
    delete[] ptr;
    ptr = new char[capacity];
    bool removed = false;

    for (int i = 0; i < capacity; ++i){
      if (i == r){
        if (ptr[i] !='\0') --size;
        ptr[i] = temp[i+1];
        removed = true;

      }
      else{
        if (!removed){
          ptr[i] = temp[i];
        }
        if (removed){
          ptr[i] = temp[i+1];
        }
      }
    }
  }

  //no resizing
  else{

    bool removed = false;

    for (int i = 0; i < capacity; ++i){
      if (i == r){
        if (ptr[i] !='\0') --size;
        ptr[i] = temp[i+1];
        removed = true;

      }
      else{
        if (!removed){
          ptr[i] = temp[i];
        }
        if (removed){
          ptr[i] = temp[i+1];
        }
      }
    }
  }
}

ostream& operator<<(ostream& out, const My_vec& vec){
    for (int i = 0; i < vec.get_capacity(); ++i){
      cout << "Index: "<< i << "   " << "Value: "<< vec[i] << endl;
    }
    return out;
}


int find_max_index(const My_vec& v, int size){
  char max = '\0';
  int max_index = 0;
  for (int i = 0; i < size; ++i){
    if (max<v[i]){
      max = v[i];
      max_index = i;
    }
  }
  return max_index;
}

void sort_max(My_vec& vec){



  My_vec temp;
  for (int i = 0; i < vec.get_capacity(); ++i){
    temp.insert_at_rank(0,'\0');
  }
  My_vec temp2 = vec;

  for (int i = 0; i < temp.get_capacity(); ++i){
    int index=0;
    index = find_max_index(temp2,temp2.get_capacity());
    temp.replace_at_rank(i,temp2[index]);
    temp2.remove_at_rank(index);
  }
  vec = temp;
}



#endif
