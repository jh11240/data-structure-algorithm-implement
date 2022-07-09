#include<iostream>

using namespace std;
int ex[4] = {3,8,0,7};
int* arrTemp;
void merge(int* arr,int start, int end);

void partition(int*arr, int start, int end)
{
	if (start>=end) return;
	int mid =( end + start )/2;			//중간값으로 자름
	partition(arr,start, mid);			//중간값기준으로 왼쪽으로 나누고
	partition(arr,mid+1,end);			//중간값기준으로 오른쪽으로 나누고
	merge(arr,start, end);				//첫값과 중간값넣어주기
}
void merge(int* arr,int start, int end) {

	int firstCursor= start;								//start부터 end까지 범위를 mid기준으로 두그룹으로 나눈뒤 앞 그룹의 커서
	int mid = (end + start ) / 2;
	int  secondCursor= mid+1;							//뒷 그룹의 커서
	int k = start;										//임시배열인 arrTemp의 커서

	while (firstCursor<=mid && secondCursor<=end) {		//firstCursor<mid를 해버리면 예를들어 0이랑 1일때 mid값 0 이라서 그냥 통과됨
		if (arr[firstCursor] > arr[secondCursor]) {		//앞 그룹의 커서값이 뒷 그룹 커서값보다 크다면 
			arrTemp[k] = arr[secondCursor];				//뒷 그룹 커서값을 임시배열 arrTemp에 저장후 
			k++;										//임시배열 커서값++
			secondCursor++;								//두번째 그룹 커서값++
		}
		else {										
			arrTemp[k] = arr[firstCursor];				//앞그룹 커서값 임시배열에 저장
			k++;										//임시배열 커서값++
			firstCursor++;								//앞그룹 커서값 ++
		}
	}
	if (firstCursor > mid) {							//만약 두 그룹중에 앞그룹으로 다 채워져있다면
		while (k <= end ) {
			arrTemp[k] = arr[secondCursor];				//뒷그룹은 어차피 정렬된상태이므로 다 넣어줌
			k++;
			secondCursor++;
		}
	}
	else {												//만약 두 그룹중에 뒷그룹으로 다 채워져 있다면
		while (k <= end) {
			arrTemp[k] = arr[firstCursor];				//앞그룹은 다 정렬된상태이므로 순서대로 다 넣어줌
			k++;
			firstCursor++;
		}
	}
	for (int i = start; i <= end ;i++) {
		arr[i] = arrTemp[i];							//임시배열값 실제 배열에 넣어주기
	}	
}

void mergesort(int* arr,int* end) {		//시작 주소, 끝 다음 주소
	arrTemp = new int[end - arr-1];
	partition(arr, 0, end-arr-1);
}

int main() {
	mergesort(ex, ex + 4);
	for (int i = 0; i < 4; i++) {
		cout << ex[i] << " ";
	}
}