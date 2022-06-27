#include<iostream>

using namespace std;

template <typename T>

class List {
private:
	struct Node {									//노드다
		T data;
		Node* prev;
		Node* next;
	};

public:
	int l_size;
	Node* head;
	Node* tail;

	class iterator {								//iterator구현
		Node* iter;
	public:
		iterator() {
			iter = new Node;
		}
		iterator(Node* node) : iter(node) {};		//초기화

		iterator& operator++() {					//++오퍼레이터 오버라이딩
			iter= iter->next;
			return *this;
		}

		iterator& operator--() {						//--오퍼레이터	오버라이딩
			iter= iter->prev;
			return *this;
		}

		T operator*() {									//*오퍼레이터 오버라이딩(값 가져오기)
			return iter->data;
		}

		bool operator !=(const iterator& other) {		//!= 오퍼레이터
			return iter != other.iter;
		}

		bool operator ==(const iterator& other) {		//== 오퍼레이터
			return iter== other.iter;
		}
		Node* operator&() {								//erase나 insert에서 iterator넘어갈때 iter값 넘겨주려고 사용
			return iter;
		}
	};

	List() {								//생성자 (초기화)
		head = new Node();
		tail = new Node();
		head->data = -1;
		tail->data = -1;
		head->next = tail;
		head->prev = head;
		tail->prev = head;
		tail->next = tail;
		l_size = 0;
	}

	
	T front() {								//맨 앞 데이터 return
		if (!empty())
			return head->next->data;
		else
			return -1;
	}
	T back() {								//맨 뒤 데이터 return
		if (!empty())
			return tail->prev->data;
		else
			return -1;

	}
	void push_back(T input) {				//맨 뒤에 노드 삽입
		Node* temp=new Node();
		temp->data = input;
		temp->prev = tail->prev;
		temp->next = tail;
		tail->prev->next = temp;	
		tail->prev = temp;
		l_size++;

	}
	void pop_back() {						//맨 뒤 노드 삭제
		if (empty()) {
			cout << "pop_back 불가!"<<'\n';
			return;
		}
		Node* temp = tail->prev;
		temp->prev->next=tail;
		tail->prev = temp->prev;
		delete temp;
		l_size--;
	}
	void push_front(T input) {				//맨 앞에 노드 삽입
		Node* temp=new Node();
		temp->data = input;
		temp->prev = head;
		temp->next = head->next;
		head->next->prev = temp;
		head->next = temp;
		l_size++;
	}
	void pop_front() {						//맨 앞 노드 삭제
		if (empty()) {
			cout << "pop_front 불가!" << '\n';
			return;
		}
		Node* temp = head->next;
		temp->next->prev = head;
		head->next = temp->next;
		l_size--;
		delete temp;
	}

	void Clear() {							//전부 해제
		Node* temp=head;
		Node* delnode = new Node();
		while (temp != tail) {
			delnode = temp;
			temp = temp->next;
			delete(delnode);
		}
		delete(tail);
		
	}

	void insert(iterator pos, T input) {	//pos좌측에 새로 input값 가지는 노드 생성
		Node* node = &pos;
		Node* preNode = node->prev;
		Node* temp= new Node();
		temp->data = input;
		temp->prev = preNode;
		temp->next = node;
		preNode->next = temp;
		node->prev = temp;

		l_size++;
	}
	iterator erase(iterator pos) {			//건네받은 iterator값 삭제하고 그다읍값 반환
		Node* node = &pos;
		Node* preNode = node->prev;
		Node* nextNode = node->next;
		preNode->next = nextNode;
		nextNode->prev = preNode;
		delete node;
		l_size--;

		return iterator(nextNode);
	}
	iterator begin() {						//맨 앞 원소 가리키는 iterator 반환
		return iterator(head->next);
	}
	iterator end() {						//맨 뒤 tail노드 가리키는 iterator 반환
		return iterator(tail);
	}

	int size() {							//사ㅏ이즈 반환
		return l_size;
	}
	bool empty() {							//비어있는지 체크
		if (l_size) return false;
		else return true;
	}

};