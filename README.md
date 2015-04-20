##Class SDAL

##Constructor/Destructor/Overloaded Operators

SDAL(): This is the default constructor this method is supposed to create an instance of the class SSLL at set head and tail index pointer to -1

SDAL(const SSLL& src): This is the method for the copy constructor. Head will be set to -1 and *this will be set to src will call the overloaded equals operator.

~SDAL(): This method calls the clear function

SDAL& operator=(const SDAL& src): This is the overloaded equals operator and instance of SDAL src will be passed into the function as const and will be used to set the current class instance to its values. If &src equals this checking for self-assignment then nothing is done and *this is returned. Otherwise, the clear method is called and the current class instance is cleared out and then each value in src is then set to the current class instance. Finally, *this is returned.

T& operator[](int i): This is the overloaded [] operator that will return the address of a value at a specific index int i. The first thing that this function should check is if the list is empty, if it is empty then an domain_error exception should be thrown. The next check should be if int i is equal to head index if so then return the head->data value. The next check if is int i is equal to the tail index, if so then return the tail->data value. For all other cases the function traverse the linked list to find the arrayIndexPosition index that matches int i, once the arrayIndexPosition is found the return the currentArrayIndexPosition->data value.

const T& operator[](int i): This is the overloaded [] operator that will return the address of a value at a specific index int I to an immutable const value. The first thing that this function should check is if the list is empty, if it is empty then a domain_error exception should be thrown. The next check should be if int i is equal to head index if so then return the head->data value. The next check if is int i is equal to the tail index, if so then return the tail->data value. For all other cases the function traverse the linked list to find the arrayIndexPosition index that matches int i, once the arrayIndexPosition is found the return the currentArrayIndexPosition- >data value.


##Member Functions

T replace(const T& element, int position): This function is used to replace a value in the list with the value element at position that are passed into the function. The first part of this function checks if the list is empty, if so then an domain_error exception is thrown. The second check is if the int position is outside the range of index values possible for negative values and values that are beyond the end of the max list index, if so then an out_of_range exception is thrown. The next check is if the value for position is equal to 0 or the head arrayIndexPosition, if so, the old value that is in head->data is saved and element is save into head->data then the old value is returned. The next check is if the value for position is equal to size()-1 or the tail

arrayIndexPosition, if so the old value that is in tail->data is saved and element is save into tail- >data then the old value is returned. For all other cases the linked list will be traverse until the arrayIndexPosition number matches position, once the arrayIndexPosition is found then the old value that is in the currentArrayIndexPosition is saved then replaced with element and the old value is returned.

void insert(const T& element, int position): This is the function used to insert an element in position passed into the function. The first check is to see if the list is empty if it is then element is placed in the first index of the list. The next check if position is outside the range of index values possible for negative values and values that are beyond the end of the max list index, if so then an domain_error exception is thrown. The next check is to see if position is equal to zero or the head arrayIndexPosition, if so, then push_front is called to put the element in the front of the list. The next check is to see if position is equal to size()-1 or the tail arrayIndexPosition, if so, then push_back is called to put the element in the back of the list. For all other cases the linked list will be traverse until the arrayIndexPosition number matches position, once the arrayIndexPosition is found a new arrayIndexPosition is created to contain element and the previousArrayIndexPosition->next will point the newArrayIndexPosition and newArrayIndexPosition->next will now point to currentArrayIndexPosition inserting the newArrayIndexPosition in between the two arrayIndexPositions all the elements in the list will be shifter to the right.

void push_front(const T& element): This function the used to add values to the front of the list the first check is to see if the list is empty, if so, then a new arrayIndexPosition is create with element and the head and tail is set to point to newArrayIndexPosition. If the list is not empty the then the new arrayIndexPosition that was created to contain element will be placed in the front of the list by setting the head pointer to point to newArrayIndexPosition and newArrayIndexPosition to point to the first element in the list all the elemnts in the list will be shifter to the right.

void push_back(const T& element): This function the used to add values to the back of the list the first check is to see if the list is empty, if so, then a new arrayIndexPosition is create with element and the head and tail is set to point to newArrayIndexPosition. If the list is not empty the then the new arrayIndexPosition that was created to contain element will be placed in the front of the list by setting the head pointer to point to newArrayIndexPosition and ++ArrayIndexPosition to point to the last element in the list.

T pop_front(): In this function the first element in the list will be removed from the front of the list and returned. The first check is to see if the list is empty, if so, throw an exception domain_error. For all other cases the arrayList[head] will be saved to element and returned and the arrayIndexPosition will be deleted from the list.

T pop_back(): In this function the first element in the list will be removed from the front of the list and returned. The first check is to see if the list is empty, if so, throw an exception domain_error. For all other cases the tail->data will be saved to element and returned and the arrayIndexPosition will be deleted from the list.

T remove(): In this function the element in the list will be removed from the position of the list and returned. The first check is to see if the list is empty, if so, throw an exception domain_error. The second check is if the position that was passed in is an invalid index, if so, throw the exception out_of_range. For all other cases the currentArrayIndexPosition->data will be saved to element and returned and the arrayIndexPosition will be deleted from the list.

T item_at(): In this function the element in the list located at position will be returned by value. The first check is to see if the list is empty, if so, throw an exception domain_error. The second check is if the position that was passed in is an invalid index, if so, throw the exception out_of_range. If position equals 0 then the value from head->data is returned. If position equal siz() – 1, then the value from tail->data is returned. For all other cases the list is traversed and the currentArrayIndexPosition->data will be saved to element and returned.

T is_empty(): This function return if tail == -1 if this is true then the list is empty else the list has element.

T size(): In this function the number of element is the list will be returned. A currentArrayIndexPosition pointer will point to the head of the list and then the list will be traversed and till -1 is reached meaning the end of the list is reached. An int counter will be incremented every time a arrayIndexPosition is traversed the counter will be incremented and then when the end of list is reach the counter is returned.

T clear(): In this function all the dynamically allocated pointers and arrayIndexPositions will be deleted. A arrayIndexPosition pointer is set to head and the list will be traversed deleting every arrayIndexPosition along the way until the end of the list is reached.

bool conatins(const T& element, bool(*ftpr)(const T& a, const T& b)) const():: In this function that take in a T element and a function pointer to a function that compare element of type T and returns true if they are equal or false if not. The list will start from the beginning and search every element in the list if one of the element in the list match the item that was passed into the function then true is returned. If the end of the list is reached without a match then false is returned.

std::ostream& print(std::ostream& out) const: In this function all the element will be printed to the console. If the list is empty then <Empty List> will be printed, else the list will start from the beginning and print eer element out [1, 2, 3, ...] until the end of the list.

## SDAL_Iter Class 

Class SDAL_Iter : public std::iterator<std::forward_iterator_tag, T> Explicit SDAL_Iter(ArrayIndexPosition* start): This is the constructor for the iterator that takes in a arrayIndexPosition and set is to the class variable here.

SDAL_Iter(const SDAL_Iter& src): This is the copy constructor for the iterator that takes in an object of type SDAL_Iter src and then copies all the data to the current class.
￼
reference operator*() const: This is the * overloaded operator and when called dereferences the item and returns the value at that position in the list.

pointer operator->() const: This is the -> overloaded operator that grants access to the elements functions and values.

self_references operator=(const SDAL_Iter& src): This is the is the = overloaded operator that is used to set two instances of SDAL_Iter to each other. This function is called form the copy constructor.

self_reference operator++(): This is the ++ overloaded operator that is used to increment the location in the list the item instance is point to ++here then return *this.

self_type operator++(int): This is the ++ overloaded operator that is used to increment the location in the list the item instance is point to.

bool operator==( const SDAL_Iter& src): This is the == overloaded operator that is used to compare two arrayIndexPositions of similar types to see if they are equal, is so, then true is returned, if not, false is returned.

bool operator!=( const SDAL_Iter& src): This is the == overloaded operator that is used to compare two arrayIndexPositions of similar types to see if they are not equal, is so, then true is returned, if not, false is returned.

## Const SDAL_Iter Class 

Class Const_SDAL_Iter : public std::iterator<std::forward_iterator_tag, T> Explicit Const_SDAL_Iter(ArrayIndexPosition* start): This is the constructor for the iterator that takes in a arrayIndexPosition and set is to the class variable here.

Const_SSLL_Iter(const SDAL_Iter& src): This is the copy constructor for the iterator that takes in an object of type SDAL_Iter src and then copies all the data to the current class.

reference operator*() const: This is the * overloaded operator and when called dereferences the item and returns the value at that position in the list.

pointer operator->() const: This is the -> overloaded operator that grants access to the elements functions and values.

self_references operator=(const Const_SDAL_Iter& src): This is the is the = overloaded operator that is used to set two instances of SDAL_Iter to each other. This function is called form the copy constructor.

self_reference operator++(): This is the ++ overloaded operator that is used to increment the location in the list the item instance is point to ++here then return *this.
￼
self_type operator++(int): This is the ++ overloaded operator that is used to increment the location in the list the item instance is point to.

bool operator==( const Const_SDAL_Iter& rhs): This is the == overloaded operator that is used to compare two arrayIndexPositions of similar types to see if they are equal, is so, then true is returned, if not, false is returned.

bool operator!=( const Const_SDAL_Iter& rhs): This is the == overloaded operator that is used to compare two arrayIndexPositions of similar types to see if they are not equal, is so, then true is returned, if not, false is returned.