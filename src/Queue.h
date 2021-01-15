/*Function templates are special functions that can operate 
with generic types. This allows us to create a function 
template whose functionality can be adapted to more than 
one type or class without repeating the entire code for each type.*/

/*To use this function template we use the following format for the function call:

function_name <type> (parameters);
*/
#include "fstream"
using namespace std;
extern ofstream output;

template<typename T>
class Queue {
	public:
	Queue();
	~Queue();
	bool isEmpty() const;
	int size() const;
	//Enqueue: Items are added to the back of the queue
	void enqueue(const T& newItem);
	//Dequeue: Items are removed from the front of the queue
	void dequeue() ;
	//Get Front: Take a look at the first item
	void getFront(T& queueTop) const;
	T peek() const;
	void print();

	private:
	struct QueueNode {
		T item;
		QueueNode *next;
		};
	int _size;
	/* to avoid the traversal to the last node, 
	 an additional pointer to the last node is defined*/
	QueueNode *_lastNode;
    QueueNode *_firstNode;

};

template<typename T>
Queue<T>::Queue() {
    _size = 0;
    _lastNode = nullptr;

}

template<typename T>
Queue<T>::~Queue() {


    while(isEmpty()){
        QueueNode *tmp = _lastNode;
        delete _lastNode;
        _lastNode = tmp;

    }
    _lastNode = nullptr;

}

template<typename T>
bool Queue<T>::isEmpty() const {
    return _size == 0;
}

template<typename T>
int Queue<T>::size() const {
    return _size;
}

template<typename T>
void Queue<T>::enqueue(const T &newItem) {
    if(isEmpty()){
        QueueNode *tmp = new QueueNode;

        tmp->item = newItem;
        tmp->next = tmp;
        _lastNode = tmp;
        _firstNode = tmp;
    }
    else{
        QueueNode *tmp = new QueueNode;

        tmp->next = _lastNode->next;
        tmp->item = newItem;
        _lastNode->next = tmp;
        _lastNode = tmp;
    }
    _size++;
}

template<typename T>
void Queue<T>::dequeue() {
    if(isEmpty()){
        cout<< "error";
    }
    else if(_size == 1){
        QueueNode* firstNode = _lastNode->next;
        _lastNode = nullptr;
        delete firstNode;

    }
    else{
        QueueNode* firstNode = _lastNode->next;
        _lastNode->next = firstNode->next;
        delete firstNode;
    }
    _size--;

}


template<typename T>
void Queue<T>::getFront(T &queueTop) const {
    if (isEmpty())
        throw string("Queue is empty");
    else
        queueTop = _lastNode->next->item;

}

template<typename T>
T Queue<T>::peek() const {
    if(isEmpty())
        return nullptr;
    else
        return _lastNode->next->item;

}

template<typename T>
void Queue<T>::print() {

    if(!isEmpty()){
        QueueNode *temp = _lastNode->next;
        int i =0;
        while(i<_size){
            output<< temp->item <<endl;
            temp = temp->next;
            i++;
        }
    }
}


