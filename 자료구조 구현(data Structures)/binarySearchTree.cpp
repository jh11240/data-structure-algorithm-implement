////////////////////////////////non-balanced version
#include<iostream>
using namespace std;

struct Node {
	int data;
	//부모 노드
	Node* parent;
	//왼쪽 자식 노드
	Node* leftChild;
	//오른쪽 자식 노드
	Node* rightChild;
};

class binarySearchTree {
private:
	Node* root;
public:
	binarySearchTree() {
		root = nullptr;
	}
	void insert(int elem);
	Node* find(int elem);
	void swap(Node* a, Node* b);
	void erase(int elem);
	void erase(Node* elem);
	void print(Node* node);
	Node* getRoot();

};
/// <summary>
/// BST에 새로운 원소 삽입
/// </summary>
/// <param name="elem(삽입할 원소)"></param>
void binarySearchTree::insert(int elem) {
	//새로 삽입할 노드
	Node* addNode = new Node;
	//맨처음 삽입이라면 루트에 넣어주기
	if (root == nullptr) {
		addNode->data = elem;
		addNode->parent = nullptr;
		addNode->leftChild = nullptr;
		addNode->rightChild = nullptr;
		root = addNode;
		return;
	}

	//현재 노드를 가리키는 노드(초기값 root노드)
	Node* curNode = root;
	while (1) {
		//인풋값이 현재 curNode가 가리키는 노드의 데이터값보다 작다면
		while (curNode->data > elem) {
			//curNode의 왼쪽자식이없다면 
			if (curNode->leftChild == nullptr) {
				//curNode의 왼쪽자식노드값 설정해주고 부모 자식값 다시설정
				addNode->data = elem;
				addNode->parent = curNode;
				addNode->leftChild = nullptr;
				addNode->rightChild = nullptr;
				curNode->leftChild = addNode;
				return;
			}
			//왼쪽 자식이 존재하면
			else {
				//curNode가 자신의 왼쪽 자식노드를 참조하게함
				curNode = curNode->leftChild;
			}
		}
		//인풋값이 curNode가 가리키는 노드의 데이터값보다 같거나 크면 
		while (curNode->data <= elem) {
			//오른쪽자식값이 없다면 해당 자식노드에 추가
			if (curNode->rightChild == nullptr) {
				addNode->data = elem;
				addNode->parent = curNode;
				addNode->leftChild = nullptr;
				addNode->rightChild = nullptr;
				curNode->rightChild = addNode;
				return;
			}
			//오른쪽 자식 존재하면 오른쪽 자식 노드 참조하게함
			else {
				curNode = curNode->rightChild;
			}
		}
	}

}

/// <summary>
/// 입력값을 찾는 함수
/// </summary>
/// <param name="elem(찾을 원소)"></param>
/// <returns>"원소 찾았다면 해당 원소 가리키는 포인터, 못 찾았다면 nullptr"</returns>
Node* binarySearchTree::find(int elem) {
	Node* curNode = root;
	//트리가 비어있다면 nullptr반환
	if (curNode == nullptr) {
		return nullptr;
	}
	while (1) {
		//현재 찾는값이 curNode가 가리키는 데이터값보다 작으면
		while (curNode->data > elem) {
			//왼쪽 자식노드로 
			curNode = curNode->leftChild;
		}
		//찾는 값이 curNode가 가리키는 데이터값보다 같거나 크면
		while (curNode->data <= elem) {
			//elem값을 찾았다면 해당 노드 반환
			if (curNode->data == elem) {
				return curNode;
			}
			//못찾았다면 오른쪽 노드로
			curNode = curNode->rightChild;
		}
		//curNode가 nullptr이라면 존재하지 않으므로
		if (curNode == nullptr) return nullptr;
	}
}

/// <summary>
/// 매개변수로 들어온 노드 두개 바꿔주는 함수
/// </summary>
/// <param name="a(노드 1)"></param>
/// <param name="b(노드 2)"></param>
void binarySearchTree::swap(Node* a, Node* b) {
	//swap용 임시 노드
	Node* tmp = new Node;
	//a의 부모 노드의 왼쪽자식이 a라면
	if (a->parent->leftChild == a) {
		//b로 연결
		a->parent->leftChild = b;
	}
	//a의 부모 노드의 오른쪽 자식이 b라면
	else {
		a->parent->rightChild = b;
	}

	//b의 부모 노드의 왼쪽 자식이 b라면
	if (b->parent->leftChild == b) {
		b->parent->leftChild = a;
	}
	//b의 부모 노드의 오른쪽 자식이 a라면
	else {
		b->parent->rightChild = a;
	}

	tmp->data = b->data;
	b->data = a->data;
	a->data = tmp->data;

	tmp->parent = b->parent;
	b->parent = a->parent;
	a->parent = tmp->parent;

	tmp->leftChild = b->leftChild;
	b->leftChild = a->leftChild;
	a->leftChild = tmp->leftChild;

	tmp->rightChild = b->rightChild;
	b->rightChild = a->rightChild;
	a->rightChild = tmp->rightChild;

	delete(tmp);
}

/// <summary>
/// BST에서 매개변수값 제거하는 함수
/// </summary>
/// <param name="elem(지울 원소)"></param>
void binarySearchTree::erase(int elem) {
	Node* delNode = find(elem);
	//BST에 해당 원소 없다면 바로 종료
	if (delNode == nullptr) {
		return;
	}
	//해당 원소가 리프 노드라면 
	if (delNode->leftChild == nullptr && delNode->rightChild == nullptr) {
		//해당 원소의 부모노드에서 해당 원소 제거
		if (delNode->parent->leftChild == delNode) delNode->parent->leftChild = nullptr;
		else delNode->parent->rightChild = nullptr;
	}
	//해당원소가 오른쪽 자식만 있을 때
	else if (delNode->leftChild == nullptr) {
		//만약 del노드가 del의 부모노드의 왼쪽자식이라면
		if (delNode->parent->leftChild == delNode) {
			delNode->parent->leftChild = delNode->rightChild;
		}
		//del노드가 부모노드의 오른쪽자식이라면
		else {
			delNode->parent->rightChild = delNode->rightChild;
		}
		//해당원소의 오른쪽자식의 부모노드를 해당원소의 부모노드로 설정
		delNode->rightChild->parent = delNode->parent;
	}
	//해당원소가 왼쪽 자식만 있을 때
	else if (delNode->rightChild == nullptr) {
		//del노드가 부모 노드의 왼쪽자식이라면
		if (delNode->parent->leftChild == delNode) {
			//부모노드의 왼쪽 자식을 해당원소의 왼쪽 자식으로 설정
			delNode->parent->leftChild = delNode->leftChild;
		}
		else {
			delNode->parent->rightChild = delNode->leftChild;
		}
		//해당원소의 왼쪽자식의 부모노드를 해당원소의 부모노드로 설정
		delNode->leftChild->parent = delNode->parent;
	}
	//해당 원소가 두 자식 다 있을 때 오른쪽 서브트리에서 제일 작은값과 교체
	else {
		//오른쪽 서브트리의 루르노드부터 시작해서
		Node* curNode = delNode->rightChild;
		//오른쪽 서브트리의 제일 작은 노드까지 
		while (curNode->leftChild != nullptr) {
			curNode = curNode->leftChild;
		}
		//두 노드를 바꿔주고
		swap(curNode, delNode);
		//해당 원소의 부모노드에서 해당 원소 제거
		if (delNode->parent->leftChild == delNode) delNode->parent->leftChild = nullptr;
		else delNode->parent->rightChild = nullptr;
	}
	delete(delNode);
}
/// <summary>
/// 매개변수로 들어온 노드 포인터가 가리키는 노드 제거
/// </summary>
/// <param name="elem"></param>
void binarySearchTree::erase(Node* node) {
	//해당 원소가 리프 노드라면 
	if (node->leftChild == nullptr && node->rightChild == nullptr) {
		//해당 원소의 부모노드에서 해당 원소 제거
		if (node->parent->leftChild == node) node->parent->leftChild = nullptr;
		else node->parent->rightChild = nullptr;
	}
	//해당원소가 오른쪽 자식만 있을 때
	else if (node->leftChild == nullptr) {
		//만약 del노드가 del의 부모노드의 왼쪽자식이라면
		if (node->parent->leftChild == node) {
			node->parent->leftChild = node->rightChild;
		}
		//del노드가 부모노드의 오른쪽자식이라면
		else {
			node->parent->rightChild = node->rightChild;
		}
		//해당원소의 오른쪽자식의 부모노드를 해당원소의 부모노드로 설정
		node->rightChild->parent = node->parent;
	}
	//해당원소가 왼쪽 자식만 있을 때
	else if (node->rightChild == nullptr) {
		//del노드가 부모 노드의 왼쪽자식이라면
		if (node->parent->leftChild == node) {
			//부모노드의 왼쪽 자식을 해당원소의 왼쪽 자식으로 설정
			node->parent->leftChild = node->leftChild;
		}
		else {
			node->parent->rightChild = node->leftChild;
		}
		//해당원소의 왼쪽자식의 부모노드를 해당원소의 부모노드로 설정
		node->leftChild->parent = node->parent;
	}
	//해당 원소가 두 자식 다 있을 때 오른쪽 서브트리에서 제일 작은값과 교체
	else {
		//오른쪽 서브트리의 루르노드부터 시작해서
		Node* curNode = node->rightChild;
		//오른쪽 서브트리의 제일 작은 노드까지 
		while (curNode->leftChild != nullptr) {
			curNode = curNode->leftChild;
		}
		//두 노드를 바꿔주고
		swap(curNode, node);
		//해당 원소의 부모노드에서 해당 원소 제거
		if (node->parent->leftChild == node) node->parent->leftChild = nullptr;
		else node->parent->rightChild = nullptr;
	}
	delete(node);
}

/// <summary>
/// inorder 방식으로 순회하며 크기대로 출력
/// </summary>
/// <param name="root값 넣어주면 됨"></param>
void binarySearchTree::print(Node* node) {
	if (node == nullptr) return;

	print(node->leftChild);
	cout << node->data;
	print(node->rightChild);
}

/// <summary>
/// root노드 포인터 반환해주는 함수
/// </summary>
/// <returns>루트 노드</returns>
Node* binarySearchTree::getRoot() {
	return root;
}


int main() {
	binarySearchTree* bst=new binarySearchTree();
	bst->insert(5);
	bst->insert(2);
	bst->insert(3);
	bst->insert(4);
	bst->insert(1);
	bst->insert(6);
	bst->insert(7);
	
	bst->print(bst->getRoot());
	cout << '\n';

	bst->erase(3);
	bst->print(bst->getRoot());

	cout << '\n';
	bst->insert(3);
	bst->print(bst->getRoot());
	cout << '\n';
	bst->insert(3);
	bst->print(bst->getRoot());
	cout << '\n';

	bst->erase(bst->find(3));
	bst->print(bst->getRoot());
	cout << '\n';

	cout<<bst->find(3)->data;


}