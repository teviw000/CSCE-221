/*My_vec.h
Your name
Header file for a vector data structure.
*/
#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <ostream>
#include <typeinfo>
using namespace std;

template <typename T>
class My_vector {

	//member variables
	int size, capacity;
	T *ptr = NULL;

public:
	//member functions
	// My_vector(){};
	//~My_vector();
	//My_vector<T>(const My_vector<T>& vec);
	//My_vector<T>& operator=(const My_vector<T>& vec);
	// int get_size() const;
	// int get_capacity() const;
	// T& operator[](int i) const;
	// T& operator[](int i);
	// bool is_empty() const;
	// T& elem_at_rank(int r) const;
	// void insert_at_rank(int r, const T& elem);
	// void replace_at_rank(int r, const T& elem);
	// void remove_at_rank(int r);

	My_vector(){
	    size = 0;
	    capacity = 0;
	    ptr = NULL;
	  }

	~My_vector(){
	      delete[] ptr;
	  }


	My_vector(const My_vector<T>& vec){
	  *this = vec;
	}

	int get_size() const{
	  return size;
	}

	My_vector<T>& operator=(const My_vector<T>& vec){
	  size = vec.get_size();
	  capacity = vec.get_capacity();
	  if( ptr != NULL) delete[] ptr;
	  ptr = new T[capacity];
	  for (int i = 0; i < vec.get_capacity(); ++i){
	    ptr[i] = '\0';
	  }
	  for(int i = 0; i < vec.get_capacity(); ++i){
	    ptr[i] = vec[i];
	  }
	  return *this;
	}

	int get_capacity() const{
	  return capacity;
	}

	T& operator[](int i){
	  if( i > (capacity-1) )
	  {
	      cout << "Index out of bounds" <<endl;
	  }
	  return this->ptr[i];
	}

	T& operator[](int i) const{
	  if( i > (capacity-1) )
	  {
	      cout << "Index out of bounds" <<endl;
	  }
	  return this->ptr[i];
	}

	bool is_empty() const{
	  if(size == 0) return true;
	  else return false;
	}

	T& elem_at_rank(int r) const{
	  return ptr[r];
	}

	void insert_at_rank(int r, const T& elem){
	  int old_capacity = capacity;
	  T *temp;

	  if (capacity == 0)
	  {
	    size = 1;
	    capacity = 1;
	    ptr = new T[size];
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

	    temp = new T[capacity];
	    for (int i = 0; i < capacity; ++i){
	      temp[i] = '\0';
	    }
	    ++size;
	    for (int i = 0; i < old_capacity; ++i){
	      temp[i] = ptr[i];
	    }
	    delete[] ptr;
	    ptr = new T[capacity];
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

	void replace_at_rank(int r, const T& elem){
	  for (int i = 0; i < capacity; ++i){
	    if (i == r) {
	      if (elem == '\0' & ptr[i] != '\0') --size;
	      if (elem != '\0' & ptr[i] == '\0') ++size;
	      ptr[i] = elem;
	    }
	  }
	}

	void remove_at_rank(int r){
	  T *temp = new T[capacity];
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
	    ptr = new T[capacity];
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

};
	template <typename T>
	ostream& operator<<(ostream& out, const My_vector<T>& vec){
	  for (int i = 0; i < vec.get_capacity(); ++i){
			cout << "Index: "<< i << "   " << "Value: "<< vec[i] << endl;
		}
		return out;
	};

	template <typename T>
	int find_max_index(const My_vector<T>& v,int size){


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

	template <typename T>
	void sort_max(My_vector<T>& vec){

		My_vector<T> temp;
		for (int i = 0; i < vec.get_capacity(); ++i){
			temp.insert_at_rank(0,'\0');
		}
		My_vector<T> temp2 = vec;

		for (int i = 0; i < temp.get_capacity(); ++i){
			int index=0;
			index = find_max_index(temp2,temp2.get_capacity());
			temp.replace_at_rank(i,temp2[index]);
			temp2.remove_at_rank(index);
		}
		vec = temp;
	}

	#endif
