#include<iostream>

using namespace std;
//												//첫번째 방법 그냥 일반 배열로 구현 단점은 pop하면 앞의 메모리가 낭비
//struct queue {
//
//	int q[10001] = { 0, };
//	int first;
//	int last;
//
//	void init() {				//구조체 변수는 선언 동시에 안하는 듯 c에선 오류남 ㅋㅋ
//		first = 0;
//		last = 0;
//	}
//	void push(int data) {
//		q[last] = data;
//		last++;
//	}
//	void pop() {
//		if (first == last) {
//			cout << "-1";
//			return;
//		}
//		first++;
//
//	}
//	int front() {
//		if (empty()) {
//			return -1;
//		}
//		return q[first];
//	}
//	int back() {
//		if (empty()) {
//			return -1;
//		}
//		return q[last - 1];
//	}
//
//	int size() {
//		return last - first;
//	}
//	int empty() {
//		return last > first ? 0 : 1;
//	}
//};
//
//void input(queue *q) {
//	string command = " ";
//	int temp=0;
//	q->init();
//	while (1) {
//		cin >> command;
//		if (command == "push") {
//			cin >> temp;
//			q->push(temp);
//		}
//		else if (command == "pop")
//		{
//			q->pop();
//		}
//		else if (command == "front")
//		{
//			temp = q->front();
//			cout << temp<<'\n';
//		}
//		else if (command == "back")
//		{
//			temp = q->back();
//			cout << temp<<'\n';
//		}
//		else if (command == "size")
//		{
//			temp = q->size();
//			cout << temp<<'\n';
//		}
//		else if (command == "empty")
//		{
//			temp = q->empty();
//			cout << temp<<'\n';
//		}
//	}
//	
//
//}
//
//int main() {
//	queue q;
//	input(&q);
//}
//											//두번째 방법 연결리스트 이용 
//											//노드랑 리스트 따로 구조체 만드는거랑 한구조체에 prev next data size다 넣는 거 차이점은 
//											//리스트엔 헤드노드와 테일노드 값이 저장되어있지만 이 구조체는 그냥 prev next data size만 있어서 
//											//리스트는 리스트를 넣어주면 헤드 테일값이 저장되서 바로 사용하면 되지만 이 큐는 head를 넣어줘야한다
//											//이거 prev랑 next가 무조건 처음과 끝을 가리키게 만든거 별로 안좋은듯
//
////struct queue {
////	queue* prev;
////	queue* next;
////	int __size;
////	int _data;
////	queue* init(queue* head) {
////		head = new queue();
////		head->prev = head;
////		head->next = head;
////		head->__size = 0;
////		head->_data = -1;
////		return head;
////	}
////	void _push(queue* head, int data) {
////		queue* tmp;
////		tmp = new queue();
////		tmp->_data = data;
////
////		if (head->__size == 0) { // 빔
////			tmp->prev = head;
////			head->next = tmp;
////		}
////		else { // 이전에 들어왔어서 비어있지 않음
////			queue* last = head->prev;
////			tmp->prev = head->prev;
////			last->next = tmp;
////		}
////		tmp->next = head;
////		head->prev = tmp;
////		head->__size += 1;
////	}
////	int _pop(queue* head) {
////		if (head->__size == 0) {
////			return -1;
////		}
////		int result = head->next->_data;
////		queue* erase = head->next;
////		head->next = head->next->next;
////		head->next->prev = head;
////		free(erase);
////		head->__size -= 1;
////		return result;
////	}
////	int _size(queue* head) {
////		return head->__size;
////	}
////	int _empty(queue* head) {
////		return (head->__size == 0);
////	}
////	int _front(queue* head) {
////		if (_empty(head)) {
////			return -1;
////		}
////		int result = head->next->_data;
////		return result;
////	}
////	int _back(queue* head) {
////		if (_empty(head)) {
////			return -1;
////		}
////		int result = head->prev->_data;
////		return result;
////	}
////};
//
//struct Node {
//	Node* prev;
//	Node* next;
//	int data;
//};
//struct Queue {
//	Node* head;
//	Node* tail;
//	int data;
//	int size;
//
//	void init() {
//		head = new Node;
//		tail= new Node;
//		head->prev = head;
//		head->next = tail;
//		tail->prev = head;
//		tail->next = tail;
//		head->data = -1;
//		tail->data = -1;
//		size = 0;
//	}
//	void push(int data) {
//		Node* newnode = new Node;
//		newnode->data = data;
//		newnode->next = head->next;
//		newnode->prev = head;
//		head->next->prev = newnode;
//		head->next = newnode;
//		size++;
//	}
//	void pop() {
//		Node* delnode = new Node;
//		delnode = tail->prev;
//		delnode->prev->next = tail;
//		tail->prev = delnode->prev;
//		delete(delnode);
//		delnode = nullptr;
//		size--;
//	}
//	int front() 
//	{
//		if (size == 0) {
//			return -1;
//		}
//		return head->next->data;
//	}
//	int back() 
//	{
//		if (size == 0)
//			return -1;
//		return tail->prev->data;
//	}
//	int size() 
//	{
//		return size;
//	}
//	int empty()
//	{
//		return size > 0 ? 0 : 1;
//	}
//};
								//세번째 방법 클래스 템플릿 이용 기본적으론 배열이용 

template<typename T>

class queue {
private:
	T data[10001];
	int front;
	int back;
public:
	queue() {
		front = -1;
		back = -1;

	}
	~queue() {

	}
	void push(T inputdata) {
		this->data[this->back + 1] = inputdata;
		this->back += 1;
		return;
	}
	void pop() {
		T res = this->data[this->front + 1];
		this->front += 1;
		return res;
	}
	int size() {
		return this->back - this->front;
	}
	bool empty() {
		return this->size() == 0 ? true : false;
	}
	T front() {
		T res = this->data[this->front + 1];
		return res;
	}
	T back() {
		T res = this->data[this->back];
		return res;
	}
}

