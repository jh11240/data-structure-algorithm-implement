#include<iostream>
#include<vector>
using namespace std;

template <typename T >	

class priority_queue {				//max_heap기준
private:
	int p_size;
	vector<T> v;
public:
	priority_queue(){
		p_size = 0;
		v.push_back(0);			//우선순위큐는 루트노드를 1로잡는다.
	}
	void push(const T& elem) {
		v.push_back(elem);						//벡터에 값 푸시

		if (empty()) {						//루트에 이미 0넣었으므로 
			p_size++;
			return;
		}

		int idx = v.size() -1,parent=0,child=0;	//idx는 방금 들어온 값의 인덱스, 부모노드, 자식 노드
		while (idx > 1) {						//idx가 루트보다 위 일때
			child = idx;						//자식노드에 idx
			parent = idx / 2;					//부모 노드에 idx/2
			if (v[parent] < v[child]) {			//parent가 자식노드보다 작으면 바꾸기
				swap(v[parent], v[child]);
				idx = parent;					//idx에 parent값 넣어주고 while문 반복
			}
			else
				break;							//parent가 자식보다 크면 냅두기
		}
		p_size++;

	}
	void heapify(const int& idx) {					//pop후 제자리값 찾아가게 하기
		int curIdx = idx;
		int left = 2 * idx;
		int right = 2 * idx+1;

		if (left <= v.size() - 1 && v[curIdx] <= v[left]) {					//curIdx가 left보다 작으면 curidx=left
			curIdx = left;
		}
		if (right <= v.size() - 1 && v[curIdx]<= v[right] ) {					//curidx가 left보다 크면 curidx일거고, left보다 작으면 left값이다
												//이상태로 right와 비교하면 curidx와 left,right 다 비교된것.
			curIdx = right;
		}
		if (curIdx != idx) {					//curidx가 idx와 같지 않다면 변경 됬으므로
			swap(v[curIdx], v[idx]);
			heapify(curIdx);
		}

	}
	void pop() {
		if (empty()) {
			cout << "우선순위 큐 비어있음";
			return;
		}
		swap(v[1], v[v.size() - 1]);			//제일큰값 마지막값과 바꿔준후
		v.pop_back();							//마지막값 배출
		heapify(1);
		p_size--;
	}
	T top()
	{
		return v[1];
	}
	int size()
	{
		return p_size;
	}
	bool empty()
	{
		if (p_size) return false;
		else return true;
	}
	void print() {
		cout << "우선순위 큐의 원소들: ";
		for (int i = 1; i < v.size(); i++) {
			cout << v[i]<<" ";
		}
		cout << '\n';
	}
};

int main() {
	priority_queue<int> pq;

	pq.push(1);
	pq.push(2);
	pq.push(3);
	pq.push(4);
	pq.push(5);
	cout << pq.top()<<'\n';

	pq.print();

	pq.pop();
	cout << pq.top()<<'\n';
	pq.pop();
	cout << pq.top() << '\n';
	pq.pop();
	cout << pq.top() << '\n';

	pq.print();
}