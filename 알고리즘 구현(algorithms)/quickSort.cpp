#include<iostream>

using namespace std;
int ex[6] = {3,8,7,0,1,6 };

void quicksort(int* arr,int* end) {		//시작 주소, 끝 다음 주소
	if (arr == end) return;				//arr+1했을때 end와 같다면 return
	int pivot = 0;						//pivot값 맨 처음값으로 둠
	int frontCursor = 1;				//pivot다음 커서
	int backCursor = (end - arr)-1;		//arr배열의 맨 마지막 요소 가리키는 커서

	while (frontCursor<=backCursor) {

		while (frontCursor<(end-arr)-1 && arr[frontCursor] < arr[pivot]) frontCursor++;		//pivot값보다 큰값나올때까지 frontcursor ++
		while (backCursor !=0 && arr[backCursor] >= arr[pivot]) backCursor--;				//pivot값보다 작은값나올때까지 backcursor--

		if (frontCursor >= backCursor) {													//만약 frontcursor와 backcursor 교차하거나 값이 같으면 
																							// ( 맨 처음값이 제일큰값이면 두 커서값이 같다 )

			swap(arr[pivot], arr[backCursor]);												// pivot값과 backcursor값 바꾸기
																							//재귀가 다끝나면 빠져나오기
		}
		else 
			swap(arr[frontCursor], arr[backCursor]);										//아니라면 frontcursor값과 backcursor값 변경해주기
	}
	quicksort(arr , arr+backCursor);														// 맨처음 pivot값은 제일 작은값으로 고정되었으므로 그다음 값부터 다시 반복
	quicksort(arr + backCursor+1, end);														// 맨처음 pivot값은 제일 작은값으로 고정되었으므로 그다음 값부터 다시 반복
}

int main() {
	quicksort(ex, ex + 6);
	for (int i = 0; i < 6; i++) {
		cout << ex[i] << " ";
	}
}