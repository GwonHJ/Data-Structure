# Data-Structure(자료구조)

자료구조 과제

개발환경 : Visual Studio2010

개발언어 : C Language


## Why C?

1. C언어의 특징은?
    1. **C언어는 시스템 프로그래밍 언어이다.** 운영체제, 컴파일러, 편집기, 디버거 등 시스템 프로그램을 개발하는 도구
    2. **C언어는 함수 언어다.** 프로그램은 1개 이상의 함수 집합으로 구성된다. 작성된 함수는 분할해서 컴파일할 수 있으므로 쉽게 재사용할 수 있다.
    3. **C언어는 이식성이 강한 언어다.** 컴퓨터의 구조에 영향을 받지 않고 호환성을 유지한다. 이것이 가능한 이유는 모든 기계에서 동일하게 작동하는 다양한 표준 라이브러리가 제공되기 때문이다.
    4. 장점 : C로 짜여진 코드는 속도가 빠르고 바이너리 크기도 작아 속도가 다른 무엇보다 (심지어는 생산성보다도) 중요한 임베디드 혹은 모바일 계열, 또는 시스템 프로그래밍 등에서 주로 사용된다.

        ex) OS를 만든다면 아무리 생산성을 고려한다고 해도 시스템 제어 측면과 OS의 기능들 위에서 돌아가는 어플리케이션 때문에라도 속도라는 면은 중요하고, 그렇다고 속도를 높이기 위해 어셈블리어나 기계어로만 OS를 짜기에는 생산성이 매우 낮아지기 때문에, 타협점으로 C를 쓴다.

2. 포인터
    1. 일반 변수의 메모리 내 주소번지를 갖는 자료형이다. 변수명을 통하지 않고 사용하고자 하는 대상에 직접 접근할 수 있어서 프로그램이 간결하고 효율적으로 제어할 수 있다.
    2. 인자 전달 방법
        1. 인자를 값으로 전달(Call by value) : 함수가 호출되면 인자값을 스택으로 복사한다. → 함수에서 인자값을 바꿔도 메인에 영향을 끼치지 않음
        2. 인자를 주소로 전달(Call by reference) : 변수의 주소를 함수에 전달
    3. 포인터와 배열 관계 : 배열명은 그 자체로 해당 데이터가 있는 시작주소를 의미하는 포인터 상수

----------------------------------------------------------------------------
## Linked-list


LinkedList개념

링크드 리스트는 각 데이터들을 포인터로 연결하여 관리하는 구조이다.
노드 구조 : 데이터 영역 + 포인터 영역

1. 포인터 영역에는 다음에 올 데이터의 주소값이 들어온다 주로 링크라고 부르고 코딩할때는 next라고 한다.
2. 포인터는 하나 이상일 수 있다.
3. 마지막 데이터에는 포인터 영역어 NULL값이 들어가서 마지막 데이터임을 표시한다.

링크의 장점 : 추가, 삭제 용이


#### 링크 예제


예제 조건

    1. 차례대로 2개의 노드를 생성하여 데이터를 입력
    2. 2개의 노드를 링킹
    3. 링킹된 2개의 노드의 데이터의 링크를 따라가면 마지막 데이터까지 출력
    
linkheader.h

        해더함수를 저장할때는 확장자를 .h로 저장하고 소스파일 폴더가 아닌 헤더파일 폴더에 저장한다.
        노드를 생성하는 해더함수


linkmain.c
       
       2개의 노드 생성 및 데이터 입력하는 코드
      
코드 설명  

   linkmain.c
```c
	newData = (int*)malloc(sizeof(int));  // 포인터 변수는 항상 주소를 할당해주어야함. malloc은 동적할당
	*newData = 7;
	node = createNode(newData);
	newData = (int*)malloc(sizeof(int));    //노드를 두개 생성하기 때문에 두번의 동적할당이 필요
	*newData = 75;
	node->link = createNode(newData);       //노드의 링크가 가르키는 곳에 두번째 노드를 만든다
	nodeData = (int*)node->dataPtr;         //노드의 dataPtr의 값이 첫번째 node의 data
	printf("Data from node 1: %d\n", *nodeData);
	nodeData = (int*)node->link->dataPtr;   //노드의 link의 dataPtr값이 두번째 node의 data
	printf("Data from node 2: %d\n", *nodeData);
```
        
        
   linkheader.h
```c
	typedef struct node {
	void* dataPtr;
	struct node* link;
	} NODE; //node라는 구조체 생성, 타입명 NODE라고 설정.
	//node안에는 data값이 들어갈 dataPtr과 다음에 올 주소값이 들어갈 link가 있음.
	NODE* createNode(void* itemPtr) { 
            NODE* nodePtr;
            nodePtr = (NODE*)malloc(sizeof(NODE));
            nodePtr->dataPtr = itemPtr;             //dataPtr에 data값을 넣어줌
            nodePtr->link = NULL;                   //link에 NULL을 넣어줌
                                                    //초기값 설정 현재는 다음에 올 data가 없기 떄문에 NULL을 넣음
            return nodePtr; }
```



------------------------------------------------------------------------------------------    

## factorial구현

factorial.c

### 재귀함수 예제

재귀함수의 장점 : 코드의 가독성이 높아진다.

재귀함수의 단점 : 코드의 효율성이 떨어진다.


필수 조건

    1. 재귀함수를 이용할 것
    
    2. n보다 작은 값의 factorial을 모두 출력할것

실행화면

   ![factorial png](https://user-images.githubusercontent.com/44545584/48903235-44b8b800-ee9e-11e8-9437-4987ae9e3648.jpg)

코드설명

```c
#include<stdio.h>
#include<stdlib.h>

// recursion 방식의 factorial 구하기
int fact(int);//프로토타입선언

int main(void) {
	int n = 5;
	for (int i = 1; i <= n; i++) {
	if (i < n) {
		printf("%d != %d\n", i, fact(i));//1!~4!까지의 값 출력
	}
	else if(i==n)
		printf("fact(%d)= %d\n", n,fact(5));//5!의 값 출력
}
}

int fact(int n)
{
	if (n <= 1) return 1;
	else return n*fact(n - 1);
}// factorial 함수
```
