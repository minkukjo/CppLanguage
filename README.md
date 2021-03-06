# CppLanguage
C++ 공부 내용 정리 저장소

참고 : 뇌를 자극하는 C++ STL 저자 : 공동환

### struct와 class의 차이

struct는 멤버 접근 한정자를 지정하지않으면 struct는 public이 기본 속성이고 class는 private이 기본속성이다.

### 임시 객체

객체이름()으로 임시객체를 생성할 수 있다.
임시객체는 그 문장에서 생성되고 문장이 끝나면 소멸한다.

### 포인터 객체

```C++
Point* a1 = new Point(2,3); 
```

객체 포인터타입의 변수를 선언하고 new로 동적 할당.

객체 포인터타입 변수는 스택에 자리잡게 되고, new 연산을 통해 동적할당된 객체는 힙에 머무르게 됌.
이때 명시적으로 delete를 선언하여 객체 포인터타입 변수가 가르키는 동적객체를 메모리에서 제거해주지않으면 힙에 여전히 메모리가 잡게 됌. 
결과적으로 메모리 누수 발생.

### explicit 키워드

explicit 생성자는 명시적 호출만 가능하게끔 강제시키는 키워드.

### 타입변환연산자

```C++
operator A() { return A; }
operator int() { return 10; }
```

생성자,소멸자 처럼 타입을 선언하지않고
클래스안에 타입변환연산자 오버로딩을 사용하면 자신의 타입을 다른 타입으로 변환할 수 있다.

### 함수 호출 규약

함수 호출 규약은 함수 호출시 전달되는 인자의 순서나 함수가 종료될때 함수의 스택을 정리하는 시점을 약속해놓은 것. 
stdcall,cdecl,thiscall,fastcall등이 있다.
C++의 기본 함수 호출 규약은 cdecl이다.
멤버함수는 thiscall 이다. 그래서 정적 함수 포인터와 멤버함수 포인터를 각각 다르게 선언한다.

### 매크로와 인라인의 차이

- 매크로 함수 

#define으로 선언하며 컴파일이 되기전 전처리 되어지는 코드.

```C++
#define MUL(a,b) a*b
```

여기에 ```MUL(10+3, 20+2)```를 하면 ```13*22```가 되어 ```286```이 되어야 한다 생각하지만, 
실제로는 ```10+3*20+2```가 되어서 ```72```가 된다.
즉 매크로 함수는 단순 치환만 지원 해줌.

- 인라인 함수

매크로의 단점을 보완하기에 나온 함수. 

```C++
inline int func_mul(int a, int b)
{ 
  return a*b; 
} 
```

일반 함수와 크게 차이는 없지만  인라인이 가능하다면 치환을 하고 아니면 일반 함수처럼 취급. 
inline과 일반함수의 가장 큰 차이는 inline 함수는 스택으로 불리는 것이 아닌 ‘치환’되어 사용됨.
그렇기 때문에 inline 함수는 일바 함수보다 속도가 빠름.

### 함수 객체의 장점

함수객체는 일반 함수보다 함수 객체가 속도가 더 빠름. 
또한 함수의 주소를 전달하여 콜백하는 경우 함수 포인터는 인라인 될 수 없지만
함수 객체는 인라인 될 수 있고 컴파일러가 쉽게 최적화 가능함.


### 템플릿이란?

템플릿은 컴파일 단계에서 클라이언트의 입력 데이터에 맞춰서 타입을 지정해주는 형식이다.

- 함수 템플릿

```C++
template<typename T>
void Print(T a, T b)
{
	cout << a << "," << b << endl;
}
```

위와 같은 형식으로 선언한다.

- 클래스 템플릿

```C++
templete<typename T>
class Array
{
	… // 내용
}
```

위와같이 클래스를 템플릿화 하여 클래스타입을 컴파일 타임에 지정해줌.

- 함수 템플릿의 특수화

```C++
template<>
void Print(Point a)
{
  cout << " Print 특수화 버전: ";
  a.Print();
}
```

- 클래스 템플릿의 특수화

```C++
template<typename T>
class Array
{
   ... // 내용
}

template<>
class Array<string>
{
  ... // 내용
}

Array<string>은 Array 클래스를 특수화 한 것.
template의 타입 안에 typename이 빠진 것을 볼 수 있다.
string타입의 Array 클래스를 선언할 시 특수화된 템플릿의 클래스로 만들어 진다.
```

위와 같이 템플릿은 특수화하여 특정 타입을 지원하는 템플릿을 만들 수 있다. 


- 함수 템플릿의 특수화를 쓰면 안되는 이유

함수 템플릿은 오버로딩을 지원한다. 그러나 오버로딩의 우선순위는 

```
일반함수 -> 기본 함수 템플릿 -> 오버로드 해소 -> 특수화 함수 템플릿 
```

순으로 컴파일러가 판단한다. 

우선 컴파일러는 적절한 기본 템플릿을 찾고, 그 후 그 템플릿에 대한 적절한 특수화가 있다면 특수화를 선택한다는 의미이다. 

하지만 이는 템플릿에 대한 하나의 특수화를 작성했다해서 템플릿이 어떤 식으로든 변하는 것은 템플릿이라는 것의 고유한 의미와 적합하지 않다. 

때문에 우리는 기본 함수 템플릿을 커스텀하려면 차라리 일반 함수로 만드는 게 낫다.

그리고 오버로딩된 기본 템플릿 함수가 존재한다면 특수화를 안하는게 좋다.

특수화가 선택되는 과정은 일단 적절한 기본템플릿이 선택되면 그 다음 진행하기 때문이다.

결국 어떤 하나의 함수 템플릿에 대해 오버로딩을 제공한다면 특수화는 제공해선 안된다.

<u> 결론 : 함수 템플릿을 특수화 하느니 일반함수를 만들어 써라. 그게 속 편하다. <u>
	
함수 템플릿을 특수화하지 말아야 하는 이유 출처 : <https://wikidocs.net/652>

### 컨테이너 어댑터란?


다른 컨테이너의 인터페이스를 변경한 컨테이다.

STL에서는 stack,queue,priority_queue 세 가지 컨테인 어댑터가 존재한다.

stack은 LIFO(Last-In First-Out)

queue는 FIFO(First-In First-Out)

priority_queue는 원소를 우선순위에 따라 관리하는 큐.

priority_queue의 기본 정렬 기준은 less.



- Stack

Stack은 내부적으로 vector, list,deque를 이용해 구현 가능.

- Queue

Queue는 front기능을 수행해야 하므로, deque로만 구현 가능. 

왜냐하면 pop_front()를 해야하기 때문에 vector를 못씀.

- Priority Queue

Priority_queue는 vector를 사용하고 있고, deque로도 구현 가능. 

Priority_queue에서는 내부적으로 정렬을 수행하기때문에 항상 pop_back()을 수행하므로, 

pop_fornt()기능을 제공하지않는 vector도 사용 가능.



### String

String은 문자열만을 저장하기 위해 만들어진 컨테이너이기 때문에 STL에 포함되지 않는다.
이런 컨테이너를 유사 컨테이너라고 부른다.

String에서는 C, C++처럼 문자열에 ‘\0’를 포함해야하는 요구사항은 없다.
내부는 vector와 유사하다.
시퀀스 컨테이너이므로 반복자로 초기화 가능하다.


![kakaotalk_photo_2019-03-01-21-59-52](https://user-images.githubusercontent.com/43809168/53639720-5fed4d80-3c6d-11e9-83e7-cb7d19a01216.jpeg)


![kakaotalk_photo_2019-03-01-21-59-56](https://user-images.githubusercontent.com/43809168/53639748-6c71a600-3c6d-11e9-826a-dd7bf1e60abd.jpeg)
