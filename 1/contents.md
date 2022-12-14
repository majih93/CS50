# C

source code
컴퓨터는 소스코드를 알아듣지 못한다.
컴퓨터는 binary 만 해석할 수 있음(0과 1의 조합으로 이루어진 정보) 컴퓨터가 해석할 수 있는 것이 machine code

사람은 source code 를 쓰고, 컴퓨터는 machine code 를 실행함 -> 어? 그러면 뭔가 해석이나 변환의 과정이 필요하겠군?

컴퓨터는 데이터 뿐만 아니라, 지시사항도 해석할 수 있어야한다.

데이터와, 데이터를 처리하는 방법에 대한 정보를 통해 우리가 원하는 결과를 return 해주는 것.

그럼 source code 를 입력받아서 machine code 를 반환하는 도구는 무엇일까?

-> `컴파일러 compiler` 가 바로 이 역할을 수행하는 프로그램이다.

## 좋은 코드의 척도

코드는 단순히 작성한다고 되는 것이 아니다.

좋은 코드를 작성하는 것 또한 굉장히 중요한 문제이고, 이는 다음 세 가지 정도의 척도로 판단해볼 수 있다.

**correctness**

당연히 올바른 코드를 작성해야지 원하는 결과를 얻을 것이다.

가장 중요한 목표이다.

**design**

보다 주관적인 부분일 수 있다.

코드를 어떤 디자인패턴으로 설계하는지에 따라 유지보수 가능성이나 안정성 등을 높일 수 있음

**style**

컴퓨터는 사람이 작성한 코드의 가독성 등을 전혀 신경쓰지 않지만, 컴퓨터가 코드를 쓰는게 아니고서야 사람이 보고 수정하고 써야하기 때문에 가독성을 고려해야한다.

## C 언어로 hello world 출력하는 프로그램 만들어보기

`hello.c` 파일에 대해 `make hello` 라는 명령어를 수행하면 컴파일된 `hello` 파일이 생성되고, 이 파일을 실행하면 결과를 얻을 수 있음

```c
// 자동으로 코드가 컬러로 분류되어 있다. -> syntax highlighting

#include <stdio.h> // header file 을 import 하는 코드.

int main(void) // -> 일단, 그냥 여기에 있어야한다고만 알고 있자.
{
  // printf 는 console.log 와 비슷하다.
  // c 에서 text 를 입력할 때는 "" 로 감싸주어야 한다.
  // \n 의 의미는? -> creates a new line -> 임의로 새 줄에다가 text type 코드를 막 작성하면 안됨 줄바꿈 처리를 해주어야한다.
    printf("hello, world"); // ; 이 없으면 오류가 발생함. JavaScript랑은 조금 다르네?
}
```

header file? -> 과거에는 효율성을 고려해서 필요한 것들만 가져다가 사용하기 위해서 이렇게 분리해서 가져다가쓰는 형태로 사용됨
header file 은 특정 라이브러리/모듈에 대해서 정보를 담고 있다.

컴파일러한테 이렇게 말하는 것하고 같다.

`야, 나 stdio 라이브러리에서 가져다가 쓸 기능 있음.`

근데 어떤 라이브러리에 어떤 기능이 있는지 어떻게 알 수 있음? -> 이를 위해서 공식문서라는 것이 존재한다.

강의를 위해서 `cs50.h` 라는 라이브러리가 존재함 -> 몇 가지 기능(함수)가 포함되어 있다.

## compare.c

`=` 표시는 할당을 의미한다. 그렇기 때문에 비교할 때는 `==` 등 다른 기호를 사용해야함

조건문은 잘 고려해서 작성해야한다. 더 효율적으로 모든 경우를 처리할 수 있는 조건이 있는지 잘 생각해보자.

## agree.c

## Loops, Variables

반복문의 의미 - 불필요한 작업 반복 줄이고, `single source of truth` 를 더 가능케 함

보통의 경우, 0 에서 시작해서 ++ 하는 방식이 많이 사용됨(vs -- 하는 방식)

```c
#import <stdbool.h> // true/false 값을 활용하려면 이 라이브러리를 도입하거나, 해당 라이브러리를 도입하고 있는 라이브러리를 도입해야함
// 뭔가 계속 반복하고 싶을 때

while (true) // while 문은 bool 로 평가되는 식을 받는데, true로 평가되는 식은 끝날 조건이 없다.
{
  // logic
}

while(1) // 보통 0 은 false, 1 은 true 로 생각된다. 하지만 요즘은 대체적으로 명확하게 true 로 쓰는 듯
{
  // logic
}
```

혹시나 infinite loop 이 발생해서 끊어야 하는 경우, `ctrl+c` 명령어를 통해 끊을 수 있음

<br>

---

<br>

## Command line interface - CLI

리눅스란?

- 운영체제
- 서버에서 많이 사용됨
- macos, windows 의 alternative
- provides the user both a GUI and a `CLI`

리눅스는 특히 CLI 로 잘 알려져있음

리눅스 명령어

`ls` - lists all of the files in the current folder

`cd` - `change directory (to)`

`cp` - `copy a file`

`mv` - rename a file -> `mv currentFileName newFileName` 형태로 사용 or move a file

`mkdir` - `make a directory`

`rm` - `remove a file`

`rmdir` - `remove a directory`

<br>

---

<br>

## mario

실수할 가능성을 줄이는 코드는 좋은 디자인패턴이다...

**- Have to change something in more than one place - BAD!!**
**- copy, paste - BAD!!!**

심플한 법칙들인데, 쉽지 않고 생각을 많이 해야한다. 생각을 하면서 코드를 짜야함

반대로 말하면, 실수할 가능성이 존재하는 코드는 좋지 못한 코드.

코드를 짤 때, 이렇게 코드를 짜면 나중에 다른 사람이 코드를 수정할 때 뭔가 놓치는 부분은 없을지에 대해서 고민하면서 좋은 코드를 작성해보자. -> Apple Watch app 을 만들때, screenSize 등을 고려해서 UI 를 구성할거면 최대한 한 군데서 해당 값을 관리하는 형태로 짠다던지 하는 방식이겠지?
