# CPP

**c++ 과제**

- c++98 standard 를 적용
- CPP02 부터 Orthodox Canonical Form 형식으로 디자인

# CPP00
## ex00

**[c++ 형식으로 출력해보기]**
- 실행 인자로 받은 문자열을 대문자로 바꿔 출력
  
  <img width="807" alt="스크린샷 2024-06-28 오전 9 23 05" src="https://github.com/seonjo1/CPP/assets/127729846/bb68532c-341c-406f-a4b8-49d9189d21ff">

## ex01

**[c++ 의 입출력 및 Manipulator 사용해보기]**

- 나만의 PhoneBook 만들기
  - PhoneBook 의 3가지 기능
    - **ADD**
      - ADD 입력
      - 추가할 연락처의 5가지 정보를 입력

        <img width="582" alt="스크린샷 2024-06-28 오전 9 29 02" src="https://github.com/seonjo1/CPP/assets/127729846/01433f7c-5ed4-4dcd-aef8-17336e452474">

    - **SEARCH**
      - SEARCH 입력
      - 보고싶은 연락처의 index 입력

        <img width="480" alt="스크린샷 2024-06-28 오전 9 30 29" src="https://github.com/seonjo1/CPP/assets/127729846/d348b240-355f-4d19-ad03-47418730a18a">

    - **EXIT**
      - EXIT 입력
      - PhonBook 종료

        <img width="459" alt="스크린샷 2024-06-28 오전 9 31 06" src="https://github.com/seonjo1/CPP/assets/127729846/67c7ba9c-a0fc-4824-8f73-d067675f56a2">


## ex02

**[.hpp 파일 보고 .cpp 파일 구현해보기]**

- 주어진 Account.hpp 와 test.cpp 을 보고 test.cpp 가 실행 될 수 있게 Account.cpp 작성
- 예금, 인출이 가능한 Account 클래스를 구현
- test.cpp 에서는 Account 벡터를 만들어 벡터를 순회하면 예금, 인출을 실행

# CPP01

## ex00

**[new, delete 써보기]**

- 생성자, 소멸자를 호출하면 문구를 출력하는 Zombie 클래스 생성
- stack 메모리에 생성되는 객체와 heap 메모리에 new 로 생성되는 객체 비교
  - heap 메모리에 생성되는 Zombie 객체는 delete 시 소멸자 호출
  - stack 메모리에 생성되는 Zombie 객체는 함수 scope 를 벗어날 시 소멸자 호출 


## ex01

**[new[], delete[] 써보기]**

- 객체의 배열을 heap 에 할당해주는 new[] 를 사용해 Zombie 객체 배열 생성
- new 와 new[], delete 와 delete[] 는 아예 다른 함수로 구분하여 사용해야 함
- new[] 로 생성한 객체 배열 내부 객체들은 기본 생성자로 초기화 됨
- 기본 생성자가 없으면 new[] 로 호출시 컴파일 오류 발생


## ex02

**[참조와 포인터 1]**

- 참조와 포인터의 차이
  - 변수의 참조와 포인터를 만들어 주소와, 값을 출력하여 둘의 차이점을 확인

    <img width="579" alt="image" src="https://github.com/seonjo1/CPP/assets/127729846/84c6c593-7898-42a3-8b2b-290befeb2c62">


## ex03

**[참조와 포인터 2]**

- 클래스의 멤버 변수가 포인터일때와 참조일때 차이
  - 멤버 변수가 포인터면 언제든 변경 가능
  - 멤버 변수가 참조면 초기화시 멤버 변수를 초기화 시켜줘야하고, 이후 변경 불가


## ex04

**[파일 입출력]**

```
./replace <file> <string1> <string2>
```
- 다음과 같이 실행되는 프로그램 구현
  - file 에 있는 string1 을 string2 로 치환한 file.replace 파일 생성
  - 즉 file 을 읽고 file.replace 에 씀
  - 프로그램 실행

    ```
    ./replace file a b
    ```

    <img width="267" alt="image" src="https://github.com/seonjo1/CPP/assets/127729846/b36a5e93-1ea0-4778-b6fa-ee13fa7cbee1">

    <img width="279" alt="image" src="https://github.com/seonjo1/CPP/assets/127729846/2824ea74-9a9f-46d1-beac-c3c85d1311f6">


## ex05

**[멤버 함수 포인터]**

- Harl 클래스의 debug(), info(), warning(), error() 멤버 함수들의 포인터로 배열을 생성
- string 배열 [ "DEBUG", "INFO", "WARNING", "ERROR"] 을 생성
- n 번째 string 배열의 요소와 일치하는 인자가 들어오면 n 번째 함수 포인터 배열의 함수를 실행하는 complain() 멤버 함수 생성
  <img width="940" alt="image" src="https://github.com/seonjo1/CPP/assets/127729846/f12195f7-fcf8-48a6-af69-89f1e20a2c0a">


## ex06

**[switch 문]**

- if 문 대신 switch 문 사용해 ex05 의 complain() 함수 사용

# CPP02

## ex00

**[고정 소수점 1]**

- 고정 소수점 클래스 Fixed 구현
- 값은 int 에 저장하고 int 의 하위 8bit 를 fractional bits (소수점 이하 부분을 나타내는 비트) 로 설정
- 고정 소수점은 값을 그대로 사용하되 정해진 bit 를 기준으로 앞을 정수부 뒤를 소수부로 읽는 방법이다.
- 부동 소수점은 정밀도가 높지고 더 큰 범위를 표현할 수 있지만 실수 연산이 부정확할 수 있고 연산이 오래걸린다
- 고정 소수점은 정밀도가 낮고 표현 범위가 작지만 연산이 정확하고 빠르다

## ex01

**[고정 소수점 2]**

- 고정 소수점 클래스 Fixed 에 기능 추가
- 생성자의 인자를 float, int로 받아 고정 소수점 int 로 저장
- 고정 소수점 int 값을 float, int 로 변환하여 반환
- int 와 고정 소수점 변환은 fractional bits 만큼의 비트 연산으로 가능
- float 과 고정 소수점 변환은 float 에 2^(fractional bits) 를 곱해줘 fractional bits 만큼 실수 값을 정수로 확대한 후 int 캐스팅을 통해 가능 

## ex02

**[연산자 오버로딩]**

- 고정 소수점 클래스 Fixed에 연산자 오버로딩 추가
- 비교 연산자, 이항 연산자, 단항 연산자 구현
- 전역 함수로 std::ostream 의 operator<< 연산자 오버로딩

## ex03

**[CCW]**

- 고정 소수점 클래스 Fixed 를 이용한 Point 클래스 생성
- Point 객체가 다른 Point 객체 3개로 만들어진 삼각형의 내부에 존재하는지 외부에 존재하는지 판단하는 bsp() 함수 생성
- CCW 를 이용하여 간단하게 해결

# CPP03

## ex00

**[구현]**

- 이후 ex01, ex02, ex03 을 위해 부모클래스 ClapTrap 작성
- 멤버 변수
  - Hit points, Energy points, Attack damage
- 멤버 함수
  - attack(), takeDamage(), beRepaired()

## ex01

**[상속1]**

- ClapTrap 을 상속받는 ScavTrap 자식클래스 생성
- 멤버 변수의 값이 ClapTrap 과 다름
- 가상 함수 추가
  - 소멸자
  - attack()
- 새로운 함수 추가
  - guardGate()
  
## ex02

**[상속2]**

- ClapTrap 을 상속받는 FragTrap 자식클래스 생성
- 멤버 변수의 값이 ClapTrap 과 다름
- 가상 함수 추가
  - 소멸자
- 새로운 함수 추가
  - highFivesGuys()

## ex03

**[다이아몬드 상속]**

- ScavTrap 과 FragTrap 을 상속받는 DiamondTrap 자식 클래스 생성
- ClapTrap 을 2번 상속받으므로 ClapTrap을 가상 상속하여 문제 해결

# CPP04

## ex00

**[다형성]**

- Animal 이라는 부모클래스와 Dog, Cat 이라는 자식 클래스들 생성
- makeSound() 함수를 가상함수로 구현
- Animal* 에 Dog*, Cat* 를 넣어서 makeSound() 를 실행
- Animal* 지만 실제 객체인 Dog 의 makeSound()와 Cat 의 makeSound() 가 실행됨
- 동적 바인딩을 통해 가능

## ex01

**[깊은 복사]**

- Brain 클래스 추가
- ex00 의 Cat 과 Dog 에 멤버 변수 Brain* 추가
- Cat 과 Dog 의 복사 함수가 호출되면 Brain* 의 깊은 복사 실행
- 깊은 복사이므로 포인터 자체를 복사하는 것이 아닌 새로운 Brain 을 생성하여 내부 값을 복사
- 소멸자를 통해 memory leak 방지

## ex02

**[추상 클래스]**

- Animal 클래스의 makeSound() 를 순수 가상함수로 만들어 추상 클래스로 변경
- Animal 은 더이상 객체를 생성할 수 없음 (객체 생성시 컴파일 오류)

## ex03

**[인터페이스]**

- c++ 에서 공식적으로 인터페이스를 지원하지는 않음
- 멤버 변수 없이 순수 가상함수만으로 구현된 클래스를 인터페이스로 보고 있음
- 구현을 상속시키는 용도

- 추상 클래스와 인터페이스를 이용해 다음 클래스들을 구현
  - ICharacter (캐릭터 인터페이스)
    - Chracter (ICharacter 를 상속 받는 캐릭터 클래스)
  - AMateria (스킬 추상 클래스)
    - Cure (AMateria 를 상속 받는 치유 스킬)
    - Ice (AMateria 를 상속 받는 얼음 스킬)
  - IMateriaSource (스킬생성기 인터페이스)
    - MateriaSource (IMateriaSource 를 상속 받는 스킬생성기)
  
# CPP05

## ex00

**[Exception 1]**

- Bureaucrat 클래스 구현
  - 멤버 변수
    ```c++
    std::string name
    int grade
    ```
  - 멤버 함수
    ```c++
    void incrementGrade();
    void decrementGrade();
    ```
  - 예외 클래스 구현
    - grade 가 1 보다 작아지는 경우 GradeTooHighException 예외 발생
    - grade 가 150 보다 커지는 경우 GradeTooLowException 예외 발생

## ex01

**[Exception 2]**

- Form 클래스 구현
  - 서명하고 실행할 수 있는 클래스
  - 서명과 실행에 필요한 grade 가 정해진다.
  - ex00과 같이 서명이나 실행하려는 Bureaucrat 의 등급이 Form의 그것보다 낮으면 예외를 발생시킨다.
  - 이미 서명이 된 Form 에 서명하려고 해도 예외를 발생시킨다.

## ex02

**[Exception & 다형성 1]**

- Form 클래스를 추상 클래스인 AForm 으로 변경
- AForm 을 상속받는 클래스 PresidentialPardonForm, RobotomyRequestForm, ShrubberyCreationForm 3개를 구현
  - PresidentialPardonForm
    - 서명이 됐다면 실행시 대통령 사면을 받았다는 문구 출력
  - RobotomyRequestForm
    - 서명이 됐다면 실행시 50% 확률로 로봇화 성공, 실패 문구를 출력
  - ShrubberyCreationForm
    - 서명이 됐다면 실행시 file 에 분재 ascii art 를 그림
- ex01 과 같이 사인이 안 됐거나 등급이 낮으면 예외를 뱉는다.
- AForm 추상 클래스를 사용하여 어떤 종류의 Form 이든 AForm* 에 넣어 다형성을 이용한 서명, 실행이 가능

## ex03

**[Exception & 다형성 2]**

- AForm* 를 생성하는 Intern 클래스 생성
- 다형성을 이용해 PresidentialPardonForm, RobotomyRequestForm, ShrubberyCreationForm 3개의 포인터중 요청받은 1개를 AForm* 에 넣어 반환

# CPP06

## ex00

**[static_cast]**

- 인자를 1개 받아 static cast 를 통하여 해당 인자를 char, int, float, double 로 변환해 출력해주는 프로그램
  
  <img width="629" alt="image" src="https://github.com/seonjo1/CPP/assets/127729846/a2903f64-ec1c-4eff-986a-5548400e8c9d">

- 오버플로우가 나거나 표현이 불가능한 경우 오류 출력
- 컴파일 타임에 캐스팅이 되는 static_cast 를 이용

## ex01

**[reinterpret_cast]**

- Serializer 클래스 구현
  - Data 구조체의 포인터를 uintptr_t 로 변환해주는 serialize() 함수
  - uintptr_t 를 Data 구조체의 포인터로 변환해주는 deserialize() 함수
  - 포인터의 형변환이 가능한 reinterpret_cast 이용

## ex02

**[dynamic_cast]**

- 부모 클래스 Base 생성
  - 자식 클래스 A, B, C 생성

- func 클래스 구현
  - Base* 에 A*, B*, C* 중 1개를 랜덤으로 넣어 반환하는 generate() 구현
  - Base* 를 인자로 받아 내부에 A*, B*, C* 중 뭐가 들어있는지 알려주는 identify(Base* p) 구현
  - Base& 를 인자로 받아 내부에 A&, B&, C& 중 뭐가 들어있는지 알려주는 identify(Base& p) 구현

- dynamic_cast 로 identify() 함수를 구현
- dynamic_cast 는 런타임에 타입 변환을 해주는 캐스팅으로, 캐스팅이 실패했을때 패턴이 포인터일때랑 참조일때가 다름 



>```c++
>void identify(Base* p);
>```
>  - Base* 를 dynamic_cast 를 이용해 A*, B*, C* 로 변환해보며 캐스팅이 성공한 타입이 내부에 있는 것을 확인
>  - dynamic_cast 로 포인터 캐스팅을 할때 실패하면 NULL 을 반환하므로 이를 이용해 구현


>```c++
>void identify(Base& p);
>```
>  - Base& 를 dynamic_cast 를 이용해 A&, B&, C& 로 변환해보며 캐스팅이 성공한 타입이 내부에 있는 것을 확인
>  - dynamic_cast 로 참조 캐스팅을 할때 실패하면 예외를 발생시키므로 이를 이용해 구현


# CPP07

## ex00

**[함수 템플릿]**

- whatever.hpp 에 어떤 매개변수든 받을 수 있는 함수 템플릿 작성

  >  ```c++
  >  T& min(T& a, T& b);
  >  ```
  >   - a 와 b 중 < 연산의 결과가 더 작은 값 반환
       
  >  ```c++
  >  T& max(T& a, T& b);
  >  ```
  >   - a 와 b 중 < 연산의 결과가 더 큰 값 반환
      
  >  ```c++
  >  void swap(T& a, T& b);
  >  ```
  >   - a 와 b 의 값 교환

## ex01

**[함수 포인터를 매개변수로 받는 함수 템플릿]**

- iter.hpp 에 함수 포인터를 매개변수로 받는 함수 템플릿 작성

  >```c++
  > void iter(const T* arr, int len, void (*f)(T&));
  >```
  >  - 길이가 len 인 T 타입 배열 arr 의 요소들에 함수 f 적용

## ex02

**[클래스 템플릿]**

- 클래스 템플릿 Array<T> 작성
  - 생성자로 들어온 매개변수 n 만큼의 고정 크기를 갖는 배열 생성
  - [] 연산자 구현 (접근 범위 밖으로 벗어나면 예외 발생)
  - size() 구현

# CPP08

## ex00

**[algorithm 함수 1]**

- algorithm 에 있는 함수를 사용하여 다음 함수를 구현하라
  
  > ```c++
  > int easyfind(const T& container, int num);
  > ```
  >  - std::find 를 통해 container 에 num 이 있는지 확인하고 idx 반환
  >  - 못 찾으면 -1 반환

## ex01

**[algorithm 함수 2]**

- Span 클래스 구현
  - unsigned int 를 저장하는 벡터를 멤버 변수로 가짐
  - 벡터는 최대 maxSize 만큼의 요소를 가질 수 있음
  - 각 인접한 요소간의 차이를 span 이라함
    - sSpan
      - 벡터 내에서 가장 작은 span
    - lSpan
      - 벡터 내에서 가장 큰 span
    - span 예시
      ```
      vector 가 { 2, 6, 1, 3, 3} 인 경우
      
      sSpan 은 3 과 3 의 차이인 0 이다.
      lSpan 은 6 과 1 의 차이인 5 이다.
      ```
  - Span 의 멤버 함수
    > ```c++
    >  void addNumber(int num);
    > ```
    >  - num 1개를 벡터에 추가

    > ```c++
    >   void addNumbers(int num, unsigned int length);
    > ```
    > - num 을 length 개 벡터에 추가

    - 벡터에 값을 삽입할때 algorithm 함수인 insert() 사용

## ex02

**[iterator]**

- c++ 의 stack 컨테이너는 iterator 를 제공하지 않는다
- iterator 를 제공하는 stack 을 구현해보자

**MutantStack 클래스 구현**

- stack 컨테이너를 상속하여 기능을 가져옴
- stack 은 내부적으로 deque 를 이용해 구현되어 있으므로 deque 의 iterator 를 가져와 사용하면 됨
  - stack 은 deque 에서 queue 의 기능과 iterator 등을 빼고 사용함

> ```c++
> iterator begin();
> ```
> - deque 의 iterator 의 begin() 함수 사용
  
> ```c++
> iterator end();
> ```
> - deque 의 iterator 의 end() 함수 사용

# CPP09

## ex00

**[map 컨테이너]**

- BitcoinExchange 클래스 구현
  - 입력으로 date 와 value 가 적혀있는 파일을 받음

    ```
    <input.txt>
    
    date | value
    2011-01-03 | 3
    2011-01-03 | 2
    2011-01-03 | 1  
    2011-01-03 | 1.2
    2011-01-09 | 1
    ```
  
  - data.csv 파일에 date 에 해당하는 exchange_rate 정보가 존재

    ```
    <data.csv>
    
    date,exchange_rate
    2009-01-02,0
    ...
    2011-01-01,0.3
    2011-01-04,0.3
    2011-01-07,0.32
    2011-01-10,0.33
    2011-01-13,0.42
    ...
    ```
  
  - data.csv 의 정보를 참고해 입력으로 들어온 date 에 맞는 exchange_rate 를 찾아 value 를 곱해 출력

    <img width="601" alt="image" src="https://github.com/seonjo1/CPP/assets/127729846/9a623eb0-4066-407c-8ef2-0ee430c45ba7">
    
    - date 에 해당하는 exchange_rate 이 없으면 이전 날짜의 exchange_rate 사용

  - 입력 파일 오류
    - value 는 양수이며 0 이상 1000 이하의 float 값이어야함
    - date | value 형식을 지켜야함
    - date 는 날짜 형식을 지켜야함
    - date 는 없는 날을 나타내면 안 됨
    - data.csv의 가장 빠른 날 보다 빠른 날이면 안 됨

      <img width="619" alt="image" src="https://github.com/seonjo1/CPP/assets/127729846/0118fcc8-95a1-42ec-aec5-ec47375f6db4">

  - data.csv 의 정보를 다루기위해 map 컨테이너 사용
    - date 를 key 로 exchange_rate 를 value 로 map 을 사용
    - map 컨테이너의 upper_bound() 함수를 이용해 date 에 해당하는 exchange_rate 를 찾음
    - map 은 검색의 시간 복잡도가 O(1) 이므로 BitcoinExchange 클래스에 효율적임
    
## ex01

**[stack 컨테이너]**

- RPN 클래스 구현
  - RPN 은 Reverse Polish Notation 의 약자로 후위 표기법이라고 불림
  - 연산자를 연산 대상 뒤에 쓰는 표기법
  - 다음 규칙대로 계산이 진행됨
    - 맨앞에 있는 연산자부터 순서대로 연산을 진행
    - 연산자 앞의 2개의 수를 피연산자로 연산 진행
    - 연산을 다 진행했을때 1개의 수만 남으면 정상적인 연산 완료
  - 만약 위 규칙대로 진행되다 문제가 발생하거나 결과가 여러개 남으면 오류
  - 예시
    ```
    <연산식>
    1 3 5 + + 3 /

    <첫번째 연산자인 + 연산 후>
    1 8 + 3 /

    <두번째 연산자인 + 연산 후>
    9 3 /

    < 마지막 연산자인 / 연산 후>
    3
    
    ```
  - 입력은 한자리 수 양수와 + - / * 만 가능하다
  - 형식에 맞게 입력해야한다
  - 0 으로 나누는 경우 예외 처리

- 실제 실행 결과
    
    <img width="728" alt="image" src="https://github.com/seonjo1/CPP/assets/127729846/67d88d7f-fd17-4524-ba3e-ef7fb86203ca">

- Stack 사용 이유
  - Stack 으로 입력받은 숫자를 저장해놨다 꺼내쓰면 구현이 쉬움
  - 연산할때 stack 에서 2개의 수를 꺼내고 연산 결과를 다시 stack 에 넣어 사용하는 방식
    

## ex02

**[vector, list 컨테이너]**





