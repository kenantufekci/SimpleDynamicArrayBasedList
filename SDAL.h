////////////////////////////////////////////////////
//Author: Kenan Tarik Tufekci
//Date:   04/20/2015
//Title:  SDAL Header
///////////////////////////////////////////////////

#ifndef _SDAL_H_
#define _SDAL_H_
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <iterator>

namespace cop3530{
	template <typename T>
	class SDAL{
	private:
		int capacity;
		int tail;
		int head;
		T * arrayList;

	public:
		//--------------------------------------------------
		// Constructors/Destructor/Overloaded Operators
		//--------------------------------------------------
		SDAL(){	//This is the default constructor
			this->capacity = 50;
			this->tail = -1;
			this->head = -1;
			arrayList = new T[capacity];
		}

		//--------------------------------------------------
		SDAL(int capacity){	//This is the constructor to sets a capacity to the array
			this->capacity = capacity;
			this->tail = -1;
			this->head = -1;
			arrayList = new T[capacity];
		}

		//--------------------------------------------------
		SDAL(const SDAL &src){	//This is the copy constructor
			arrayList = new T[src.capacity];
   			capacity = src.capacity;
   			memcpy(arrayList, src.arrayList, sizeof(int) * capacity);
		}

		//--------------------------------------------------
		~SDAL(){	//This is the destructor
			clear();
		}

		//--------------------------------------------------
		SDAL& operator=(const SDAL &src){
			if(this == &src) return *this; // handling of self assignment, thanks for your advice, arul.
   			delete[] arrayList; // freeing previously used memory
   			arrayList = new T[src.capacity];
   			capacity = src.capacity;
   			memcpy(arrayList, src.arrayList, sizeof(int) * capacity);
   			return *this;
		}

		//--------------------------------------------------
		T& operator[](int i){	//This is the overloaded [] operator
			if (is_empty()){
				throw std::domain_error("The list is empty");
			}
			else if (i < 0 || i >=size()){
				throw std::out_of_range("Invalid Index");
			}
			else{
				T& element = arrayList[i];	//return the address of item at i in the list
				return element;
			}
		}

		//--------------------------------------------------
		T const& operator[](int i) const{	//This is the const overloaded [] operator
			if (is_empty()){
				throw std::domain_error("The list is empty");
			}
			else if (i < 0 || i >=size()){
				throw std::out_of_range("Invalid Index");
			}
			else{
				T const& element = arrayList[i];	//return the address of item at i in the list
				return element;
			}
		}

		//--------------------------------------------------
		// Member Functions
		//--------------------------------------------------
		T replace(const T& element, int position){	//This function is used to replace a value in the list
			T item;
			if (position >= capacity || position < 0){	//If the position value that is passed in is 
				throw std::out_of_range("Invalid index");	//out of range of the list throw exception
			}
			else if (is_empty()){	//If the list is empty throw an exception
				throw std::domain_error("List is empty");	//Throw exception
			}
			else{	//In all other cases
				item = arrayList[position];	//save the old value 
				arrayList[position] = element;	//insert elelemnt in the array[position]
				return item;	//return the old value
			}
		}

		//--------------------------------------------------
		void insert(const T& element, int position){	//This is the function used to insert an element in position
			if (position >= capacity || position < 0){	//If the position is outside the range
				throw std::out_of_range("Invalid input");	//of the start and end of the list throw exception
			}
			else if (is_empty()){	//If the list is empty the value is placed at the begining of the list
				push_back(element);
			}
			else if (position == head){	//If the position is at head then
				push_front(element);	//push_front the element
			}
			else if (position == tail){	//If the position is tail
				push_back(element);	//push back the element
			}
			else if (tail + 1 == capacity){ //If the array is full
				int newCapacity = capacity * 1.5;	//resize the array by 1.5
				T * newArrayList = new T[newCapacity];	//create a copy array to save all the old element
				for (int i = 0; i < position; ++i){ //copy all the old element into the new array
					newArrayList[i] = arrayList[i];
				}
				for (int i = position; i < capacity; ++i){ //copy all the elements after position
					newArrayList[i + 1] = arrayList[i];
				}
				++tail;	//increment the array tail by one
				newArrayList[position] = element;	//element is saved into the position of the new array
				this->capacity = newCapacity;	//capacity now equals newCapacity
				delete[] arrayList;	//delete the old array
				arrayList = newArrayList;	//arraylist now equals the newly created resized array
			}
			else{	//If the array is less than the capacity
				T * newArrayList = new T[capacity];	//Create a new copy array
				for (int i = 0; i < position; ++i){	//copy all the old element into the new array
					newArrayList[i] = arrayList[i];
				}
				for (int i = position; i <= tail; ++i){	//copy all the element after posititon
					newArrayList[i + 1] = arrayList[i];
				}
				++tail;	//Increment the array tail by one
				newArrayList[position] = element;	//element is saved into the position of the new array 
				delete[] arrayList;	//delete the old array
				arrayList = newArrayList;	//arraylist now equals the newly created array
			}
		}

		//--------------------------------------------------
		void push_front(const T& element){	//Insert the value at the front of the list
			T * newArrayList;
			if (is_empty()){	//If the list is empty 
				arrayList[0] = element;	//The element is place in the first index of the array
				tail = 0;	//head now equals 0
				head = 0;	//tail now equals 0
			}
			else if (tail < capacity - 1){ //if the tail index is less than capacity
				newArrayList = new T[capacity];	//Create a new copy array
				for (int i = 0; i <= tail; ++i){	//copy all the old element into the new array
					newArrayList[i + 1] = arrayList[i];
				}
				++tail;	//Increment the array tail by one
				newArrayList[head] = element;	//The first index of the array now equals element
				delete[] arrayList;	//delete the old array
				arrayList = newArrayList;	//arraylist now equals the newly created array
			}
			else{	//If the array is full
				int newCapacity = capacity * 1.5;	//resize the array by 1.5
				T * newArrayList = new T[newCapacity];	//create a copy array to save all the old element
				for (int i = 0; i <= tail; ++i){	//copy all the old element into the new array
					newArrayList[i + 1] = arrayList[i];
				}
				++tail;	//Increment the array tail by one
				newArrayList[head] = element;	//element is saved into the first index of the new array 
				capacity = newCapacity;	//capacity now equals newCapacity
				delete[] arrayList;		//delete the old array
				arrayList = newArrayList;	//arraylist now equals the newly created resized array
			}
		}

		//--------------------------------------------------
		void push_back(const T& element){	//Insert the element at the back of the list
			if (is_empty()){	//If the list is empty
				arrayList[0] = element;	//The element is place in the first index of the array
				tail = 0;	//head now equals 0
				head = 0;	//tail now equals 0
			}
			else if (tail < capacity - 1){	 //if the tail index is less than capacity
				++tail;		//Increment the array tail by one
				arrayList[tail] = element;	//The first index of the array now equals element
			}
			else{	//If the array is full
				int newCapacity = capacity * 1.5;	//resize the array by 1.5
				T * newArrayList = new T[newCapacity];	//create a copy array to save all the old element
				for (int i = 0; i <= tail; ++i){	//copy all the old element into the new array
					newArrayList[i] = arrayList[i];
				}
				++tail;		//Increment the array tail by one
				newArrayList[tail] = element;	//element is saved into the first index of the new array
				capacity = newCapacity;	//capacity now equals newCapacity
				delete[] arrayList;	//delete the old array
				arrayList = newArrayList;	//arraylist now equals the newly created resized array
			}
		}

		//--------------------------------------------------
		T pop_front(){	//Remove the first element in the list and return the value
			T * newArrayList;
			T element = arrayList[head];

			if (is_empty()){	//If the list is empty
				throw std::domain_error("The list is empty");	//Throw an exception
			}
			else if (capacity >= 100 && size() < capacity / 2){ //If the array is large and unused
				int newCapacity = capacity / 2;	//Shrink the array by half
				newArrayList = new T[newCapacity];	//create a copy array to save all the old element
				for (int i = 0; i <= tail; ++i){	//copy all the old element into the new array
					newArrayList[i] = arrayList[i + 1];
				}
				--tail;	//Decrement the array tail by one
				delete[] arrayList;	//delete the old array
				capacity = newCapacity;	//capacity now equals newCapacity
				arrayList = newArrayList;	//arraylist now equals the newly created resized array
				return element;	//Return the old element
			}
			else{	//if the tail index is less than capacity
				newArrayList = new T[capacity];	//Create a new copy array
				for (int i = 0; i <= tail; ++i){	//copy all the old element into the new array
					newArrayList[i] = arrayList[i + 1];
				}
				--tail;	//Decrement the array tail by one
				delete[] arrayList;	//delete the old array
				arrayList = newArrayList;	//arraylist now equals the newly created resized array
				return element;	//Return the old element
			}
		}

		//--------------------------------------------------
		T pop_back(){	//Remove the first element in the list and return the value
			T element = arrayList[tail];
			if (is_empty()){	//If the list is empty
				throw std::domain_error("The list is empty");	//Throw an exception
			}
			else if (capacity >= 100 && size() < capacity / 2){	//If the array is large and unused
				int newCapacity = capacity / 2;	//Shrink the array by half
				T* newArrayList = new T[newCapacity];	//create a copy array to save all the old element
				for (int i = 0; i < tail; ++i){	//copy all the old element into the new array
					newArrayList[i] = arrayList[i];
				}
				--tail;	//Decrement the array tail by one
				delete[] arrayList;	//delete the old array
				capacity = newCapacity;		//capacity now equals newCapacity
				arrayList = newArrayList;	//arraylist now equals the newly created resized array
				return element;	//Return the old element
			}
			else{	//if the tail index is less than capacity
				--tail;	//Decrement the array tail by one
				return element;	//Return the old element
			}
		}

		//--------------------------------------------------
		T remove(int position){	//Remove an element at position
			T * newArrayList;
			T element;
			int index = 0;
			if (is_empty()){	//If the list is empty 
				throw std::domain_error("The list is empty");	//Throw an exception
			}
			else if (position > tail || position < 0){	//If the position is outside the range of the list
				throw std::out_of_range("Invalid index");	//Throw an exception
			}
			else if (position == tail){	//If the position eqaul the tail
				return pop_back();	 //Pop back the element
			}
			else if (position == head){	//If the the position is 0
				return pop_front();	//Pop off the front element and return the value
			}
			else{	//If position is in between head and tail
					if(capacity >= 100 && size() < capacity/2){	//If the array is large and unused
						int newCapacity = capacity / 2;	//Shrink the array by half
						newArrayList = new T[newCapacity];	//create a copy array to save all the old element
						element = arrayList[position];	//save the old element
						for (int i = 0; i < position; ++i){	//copy all the old element into the new array to position
							newArrayList[i] = arrayList[i];
						}
						for (int i = position; i < tail; ++i){//copy all the old element into the new array after position
							newArrayList[i] = arrayList[i + 1];
						}
						--tail;	//Decrement the array tail by one
						delete[] arrayList;	//delete the old array
						capacity = newCapacity;	//capacity now equals newCapacity
						arrayList = newArrayList;	//arraylist now equals the newly created resized array
						return element;	//Return the old element
					}
					else{	//if the tail index is less than capacity
						newArrayList = new T[capacity];	//Create a new copy array
						element = arrayList[position];	//save the old element
						for (int i = 0; i < position; ++i){	//copy all the old element into the new array to position
							newArrayList[i] = arrayList[i];
						}
						for (int i = position; i < tail; ++i){	//copy all the old element into the new array after position
							newArrayList[i] = arrayList[i + 1];
						}
						--tail;	//Decrement the array tail by one
						delete[] arrayList;		//delete the old array
						arrayList = newArrayList;	//arraylist now equals the newly created resized array
						return element;	//Return the old element
					}
			}
		}

		//--------------------------------------------------
		T item_at(int position){	//Return the item in the list at position
			if (is_empty()){	//If the list is empty 
				throw std::domain_error("The list is empty");	//Throw an exception
			}
			else if (position > size() || position < 0){	//If the position is outside the range
				throw std::out_of_range("Invalid index");	//Throw an exception
			}
			else{	//If position is in between head and tail
				return arrayList[position];	//return the value
			}
		}

		//--------------------------------------------------
		bool is_empty() const{	//Check if the list is empty
			return (tail == -1);	//If tail points to -1 this means the list is empty
		}

		//--------------------------------------------------
		int size() const{	//Return the size of the linked list
			return (tail + 1);	//Return the value of tail plus one
		}

		//--------------------------------------------------
		void clear(){	//Deletes all the element and links in the list
			delete[] arrayList;	//delete the array
		}
	
		//--------------------------------------------------
		bool contains(const T& element, bool(*fptr)(const T& a, const T& b)) const{	//contains check is the vlaue is present
			for (int i = 0; i < size(); ++i){	//Traverse the list 
				if (fptr(arrayList[i], element)){	//if same char is a function pointer
					return true;	//If the values are the same return true
				}
			}
			return false;	//If the char are not the same return false
		}

		//--------------------------------------------------
		std::ostream& print(std::ostream& out) const{	//This function prints out the list
			if (is_empty()){	//If the list is empty print out empty list
				std::cout << "<Empty List>" << std::endl;
			}
			else{	//If the list is not empty
				out << "[";
				for (int i = 0; i <= tail; ++i){	//Traverse the list printing each index's data
					if (i == tail){
						std::cout << arrayList[i];	//If this is the last element in the list
					}
					else{
						std::cout << arrayList[i] << ", ";
					}
				}
				std::cout << "]\n";
			}
			return out;	//Return the final string for print
		}

		//--------------------------------------------------
		// SDAL_Iter CLass/ Const SDAL_Iter Class
		//--------------------------------------------------
		class SDAL_Iter : public std::iterator<std::forward_iterator_tag, T>{
			public:
				typedef T value_type;
				typedef std::ptrdiff_t difference_type;
				typedef T& reference;
				typedef T* pointer;
				typedef std::forward_iterator_tag iterator_category;
				typedef SDAL_Iter self_type;
				typedef SDAL_Iter& self_reference;

			private:
				value_type* here;	//Saves the passed in array pointer to arrayList
			
			public:
				//--------------------------------------------------
				explicit SDAL_Iter(value_type *start) : here(start) {}  //This is the constructor that sets arrayList node to start of list

				//--------------------------------------------------
				SDAL_Iter(const SDAL_Iter& src) : here(src.here) {}    //This is the copy constructor

				//--------------------------------------------------
				reference operator*() const {	//This is the *overloaded operator that derefences iterators data value
					if (here == NULL) throw std::domain_error("Location is NULL");
					return *here;
				}

				//--------------------------------------------------
				pointer operator->() const {   //This is the ->overloaded operator that grants access to memeber functions
					if (here == NULL) throw std::domain_error("Location is NULL");
					return &here;
				}

				//--------------------------------------------------
				self_reference operator=(const SDAL_Iter& src) {    //This is =overloaded operator to copy contents
					this->here = src.here;
					return *this;
				}

				//--------------------------------------------------
				self_reference operator++() {   //This is ++overloaded operator preincrements iterator
					++here;
					return *this;
				}

				//--------------------------------------------------
				self_type operator++(int) {   //This is ++overloaded operator postincrements iterator
					self_type temp(*this);
					++(*this);
					return temp;
				}

				//--------------------------------------------------
				bool operator==(const SDAL_Iter& rhs) const {     //This is ==overloaded operator that checks two iterators for equality
					return (this->here == rhs.here);
				}

				//--------------------------------------------------
				bool operator!=(const SDAL_Iter& rhs) const {   //This is !=overloaded operator that checks two iterators for inequality
					return (this->here != rhs.here);
				}
		}; // end SDAL_Iter

		//--------------------------------------------------
		// Const SDAL_Iter Class
		//--------------------------------------------------
		class Const_SDAL_Iter : public std::iterator<std::forward_iterator_tag, T>{
		public:
			typedef T value_type;
			typedef std::ptrdiff_t difference_type;
			typedef const T& reference;
			typedef const T* pointer;
			typedef std::forward_iterator_tag iterator_category;
			typedef Const_SDAL_Iter self_type;
			typedef Const_SDAL_Iter& self_reference;

		private:               
			const value_type* here;	//Saves the passed in array pointer to arrayList

		public:
			//--------------------------------------------------
			explicit Const_SDAL_Iter(value_type *start) : here(start) {}      //This is the constructor that sets arrayList node to start of list

			//--------------------------------------------------
			Const_SDAL_Iter(const Const_SDAL_Iter& src) : here(src.here) {}     //This is the copy constructor

			//--------------------------------------------------
			reference operator*() const {     //This is the *overloaded operator that derefences iterators data value
				if (here == NULL) throw std::domain_error("Location is NULL");
				return *here;
			}

			//--------------------------------------------------
			pointer operator->() const {    //This is the ->overloaded operator that grants access to memeber functions
				if (here == NULL) throw std::domain_error("Location is NULL");
				return &here;
			}

			//--------------------------------------------------
			self_reference operator=(const SDAL_Iter& src) {     //This is =overloaded operator to copy contents
				this->here = src.here;
				return *this;
			}

			//--------------------------------------------------
			self_reference operator++() {   //This is ++overloaded operator preincrements iterator
				++here;
				return *this;
			}

			//--------------------------------------------------
			self_type operator++(int) {    //This is ++overloaded operator preincrements iterator
				self_type temp(*this);
				++(*this);
				return temp;
			}

			//--------------------------------------------------
			bool operator==(const Const_SDAL_Iter& rhs) const {      //This is ==overloaded operator that checks two iterators for equality
				return (this->here == rhs.here);
			}

			//--------------------------------------------------
			bool operator!=(const Const_SDAL_Iter& rhs) const {      //This is !=overloaded operator that checks two iterators for inequality
				return (this->here != rhs.here);
			}
		}; // end Const_SDAL_Iter

		typedef std::size_t size_type;
		typedef T value_type;
		typedef SDAL_Iter iterator;
		typedef Const_SDAL_Iter const_iterator;

		iterator begin() { return SDAL_Iter(&arrayList[head]); } //This returns the iterator's pointer to start of the list
		iterator end() { return SDAL_Iter(&arrayList[tail + 1]); } //This returns the iterator's pointer to end of the list
		const_iterator begin() const { return Const_SDAL_Iter(&arrayList[head]); } //This returns the const iterator's pointer to start of the list
		const_iterator end() const { return Const_SDAL_Iter(&arrayList[tail + 1]); } //This returns the const iterator's pointer to end of the list

	}; //end of class SDAL
}// end namespace cop3530
#endif // _SDAL_H_


