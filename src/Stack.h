/*Function templates are special functions that can operate 
with generic types. This allows us to create a function 
template whose functionality can be adapted to more than 
one type or class without repeating the entire code for each type.*/

/*To use this function template we use the following format for the function call:

function_name <type> (parameters);

*/
#include "iostream"
#include "string"
#include "fstream"
using namespace std;
extern ofstream output;
template <typename T>
class Stack{
	public:
	Stack();
    ~Stack();
	bool isEmpty() const;
	int size() const;
	T top();
	//Push: Place item on top of the stack
	void push(const T& newItem);
	//Top: Take a look at the topmost item without removing it
	void getTop(const T& stackTop) const;
	//Pop: Remove item from the top of the stack
	void pop();


    void print();

	private:
	struct ListNode {
		T item;
		ListNode* next;
		};

	ListNode* _head;
public:
    ListNode *getHead() const;

private:
    int _size;

};

// default constructor
template<typename T>
Stack<T>::Stack() {
    _head = nullptr;
    _size = 0;
}

//default destructor
template<typename T>
Stack<T>::~Stack() {
    while(_head != nullptr) {
        ListNode *tmp = _head;
        _head = _head->next;
        delete tmp;
    }
    delete _head;
}

template<typename T>
bool Stack<T>::isEmpty() const {
    return _size == 0;
}

template<typename T>
int Stack<T>::size() const {
    return _size;
}

template<typename T>
void Stack<T>::push(const T &newItem) {
    ListNode* newNode = new ListNode;
    newNode->item = newItem;
    newNode->next = _head;
    _head = newNode;
    _size++;
}

template<typename T>
void Stack<T>::getTop(const T &stackTop) const {
    if (isEmpty())
        throw string("Stack is empty on top()");
    else {
        stackTop = _head->item;
    }
}


template<typename T>
void Stack<T>::pop() {
    if (isEmpty())
        throw string("Stack is empty on pop()");
    else{
        ListNode* tmp = _head;
        _head = _head->next;
        delete tmp;
        tmp = NULL;
        _size--;
    }
}

template<typename T>
void Stack<T>::print() {
    if( !isEmpty()){
        ListNode *tmp = _head;
        while (tmp) {
            output << tmp->item << endl;
            tmp = tmp->next;
        }
    }
}

template<typename T>
T Stack<T>::top() {
    return _head->item;
}






	
	
