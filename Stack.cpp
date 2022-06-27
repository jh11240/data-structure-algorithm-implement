#include<iostream>

using namespace std;

template <typename T>

class stack {
private:
	T* arr;								//스택 원소 넣는 배열
	int s_size;							//스택의 사이즈
	int topCursor;						//스택의 top가리키는 커서						

public:
	stack() {							//초기화
		s_size = 0;
		arr = new T[10'000];
		topCursor= 0;
	}
	~stack() {
		delete[] arr;
	}

	void push(T elem){						//원소 넣기
		arr[topCursor] = elem;
		topCursor++;

	}
	void pop(T elem){						//원소 빼기
		if (s_size!=0) {					//비어있지 않을 때
			arr[topCursor-1] = 0;
			topCursor--;
		}
		else {
			cout << "스택이 비어있습니다." << '\n';
		}
	}
	T top(){								//스택의 top 값(먼저 빠짐)
		return arr[topCursor-1];
	}

	bool empty(){							//스택이 비어있는지 여부
		if (s_size==0)
			return true;
		else 
			return false;
	}
	int size(){								//큐의 크기
		return s_size;
	}
};
