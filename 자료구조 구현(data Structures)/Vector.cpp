#include<iostream>

using namespace std;

template <typename T>

class vector {											//벡터 구현
private:
	T * vec;
	int v_size;
	int v_capacity;
public:
	vector(const int& temp=10) {
		vec = new T[temp];
		v_size = 0;
		v_capacity = temp;
	}
	~vector() {
		delete[] vec;
	}
	vector& operator=(const vector& other) {			//=연산자일때 처리
		if (this != other) {							//이 벡터가 다른 벡터가 아닐 때
			if (v_capacity < other.v_capacity) {			//그리고 캐패시티도 다를 때
				delete[] vec;
				vec(other.v_capacity);
			}
		}
		v_size = other.v_size;
		for (int i = 0; i < other.v_size; i++) {
			vec[i] = other[i];
		}
	}
	T& operator[](int idx) {						 // []연산자일때 처리
		return vec[idx];
	}
	bool operator==(vector& other) {				//비교연산자 == 처리
		if (capacity != other.capacity)
			return false;
		for (int i = 0; i < v_size; i++) {
			if (vec[i] != other[i])
				return false;
		}
		return true;
	}
	bool operator!=(vector& other) {				//비교연산자 !=처리
		return (!(*this == other));
	}
	int size() {										//vector.size()
		return v_size;
	}
	int capacity() {									//vector.capacty()
		return v_capacity;
	}
	T& front() {									//vector.front() 맨 앞 원소 위치
		return vec[0];
	}
	T& back() {										//vector.back()
		return vec[v_size-1];
	}
	T* begin() {									//vector.begin()
		return vec;
	}
	T* end() {										//vector.end()
		return vec + v_size;
	}
	void push_back(const T& element) {				//vector.push_back()
		if (v_capacity <= v_size) {						//capacity가 size보다 작거나 클때 작업
			v_capacity *= 2;							//그냥 일단 2배곱해주는거로 설정
			T* tempArr = new T[v_capacity];
			for (int i = 0; i < v_size; i++) {
				tempArr[i] = vec[i];
			}
			delete[] vec;
			vec = tempArr;

		}
		vec[v_size++] = element;
		
	}
	void pop_back() {
		v_size = v_size > 0 ? v_size-1 : 0;				//사이즈만 줄이면 어차피 push때 vec[size]값에 넣으므로 
	}
	void resize(int n,T val=0){						//vector.resize()
		T* arr = new T[n];
		v_size = v_size > n ? n : v_size;
		v_capacity = n;
		for (int i = 0; i < v_size; i++) {			//arr배열에 vec배열값 복사해주고
			arr[i] = vec[i];
		}
		for (int i = v_size; i < v_capacity; i++) {		//만약 capacity가 size보다 더 커졌다면 커진만큼 추가된 원소들을 val값으로 초기화 시켜준다.
			arr[i] = val;
		}
		delete[] vec;
		vec = arr;
		v_size = n;
	}
	void reserve(int n) {
		if (n < v_capacity) return;
		T* arr = new T[n];
		for (int i = 0; i < v_size; i++) {
			arr[i] = vec[i];
		}
		delete[] vec;
		vec = arr;
		v_capacity = n;
	}
	void swap(vector& other) {
		swap(vec, other.vec);
		swap(v_size, other.v_size);
		swap(v_capacity,other.v_capacity);
	}

	
};

int main() {

}