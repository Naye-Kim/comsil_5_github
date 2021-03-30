#include "LinkedList.h"


//1. 템플릿 클래스로 확장해야함
//2. Stack형식으로 Delete 함수 재정의해야함
//주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함

//LinkedList class를 상속받음
template <class T>
class Stack : public LinkedList<T> {
	public:
		bool Delete (T &element){
			//first가 0이면 false반환
			if(this->first == 0) return false;

			//stack은 맨 앞(first가 가리키는 노드) 삭제

			element = this->first->data;
			//element는 삭제할 data값을 갖게 한다.
			Node<T> *temp = this->first;
			delete temp;
			//기존의 first를 delete
			this->first = this->first->link;
			//first가 그 다음 노드를 가리킴
			this->current_size--;


			return true;
			}
};
