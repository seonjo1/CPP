# CPP

**c++ 과제**

- c++98 standard 를 적용
- CPP02 부터 Orthodox Canonical Form 형식으로 디자인

## CPP00
### ex00

**[c++ 형식으로 출력해보기]**
- 실행 인자로 받은 문자열을 대문자로 바꿔 출력
  
  <img width="807" alt="스크린샷 2024-06-28 오전 9 23 05" src="https://github.com/seonjo1/CPP/assets/127729846/bb68532c-341c-406f-a4b8-49d9189d21ff">

### ex01

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


### ex02

**[.hpp 파일 보고 .cpp 파일 구현해보기]**

- 주어진 Account.hpp 와 test.cpp 을 보고 test.cpp 가 실행 될 수 있게 Account.cpp 작성
- 예금, 인출이 가능한 Account 클래스를 구현
- test.cpp 에서는 Account 벡터를 만들어 벡터를 순회하면 예금, 인출을 실행

## CPP01

### ex00

**[new, delete 써보기]**

- 생성자, 소멸자를 호출하면 문구를 출력하는 Zombie 클래스 생성
- stack 메모리에 생성되는 객체와 heap 메모리에 new 로 생성되는 객체 비교
  - heap 메모리에 생성되는 Zombie 객체는 delete 시 소멸자 호출
  - stack 메모리에 생성되는 Zombie 객체는 함수 scope 를 벗어날 시 소멸자 호출 


### ex01

**[new[], delete[] 써보기]**

- 객체의 배열을 heap 에 할당해주는 new[] 를 사용해 Zombie 객체 배열 생성
- new 와 new[], delete 와 delete[] 는 아예 다른 함수로 구분하여 사용해야 함
- new[] 로 생성한 객체 배열 내부 객체들은 기본 생성자로 초기화 됨
- 기본 생성자가 없으면 new[] 로 호출시 컴파일 오류 발생


### ex02

**[참조와 포인터 1]**

- 참조와 포인터의 차이
  - 변수의 참조와 포인터를 만들어 주소와, 값을 출력하여 둘의 차이점을 확인

    <img width="579" alt="image" src="https://github.com/seonjo1/CPP/assets/127729846/84c6c593-7898-42a3-8b2b-290befeb2c62">


### ex03

**[참조와 포인터 2]**

- 클래스의 멤버 변수가 포인터일때와 참조일때 차이
  - 멤버 변수가 포인터면 언제든 변경 가능
  - 멤버 변수가 참조면 초기화시 멤버 변수를 초기화 시켜줘야하고, 이후 변경 불가


### ex04

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


### ex05

**[멤버 함수 포인터]**

- Harl 클래스의 debug(), info(), warning(), error() 멤버 함수들의 포인터로 배열을 생성
- string 배열 [ "DEBUG", "INFO", "WARNING", "ERROR"] 을 생성
- n 번째 string 배열의 요소와 일치하는 인자가 들어오면 n 번째 함수 포인터 배열의 함수를 실행하는 complain() 멤버 함수 생성
  <img width="940" alt="image" src="https://github.com/seonjo1/CPP/assets/127729846/f12195f7-fcf8-48a6-af69-89f1e20a2c0a">


### ex06

**[switch 문]**

- if 문 대신 switch 문 사용해 ex05 의 complain() 함수 사용

## CPP02

### ex00

**[고정 소수점 1]**

- 고정 소수점 클래스 Fixed 구현
- 값은 int 에 저장하고 int 의 하위 8bit 를 fractional bits (소수점 이하 부분을 나타내는 비트) 로 설정
- 고정 소수점은 값을 그대로 사용하되 정해진 bit 를 기준으로 앞을 정수부 뒤를 소수부로 읽는 방법이다.
- 부동 소수점은 정밀도가 높지고 더 큰 범위를 표현할 수 있지만 실수 연산이 부정확할 수 있고 연산이 오래걸린다
- 고정 소수점은 정밀도가 낮고 표현 범위가 작지만 연산이 정확하고 빠르다

### ex01

**[고정 소수점 2]**

- 고정 소수점 클래스 Fixed 에 기능 추가
- 생성자의 인자를 float, int로 받아 고정 소수점 int 로 저장
- 고정 소수점 int 값을 float, int 로 변환하여 반환
- int 와 고정 소수점 변환은 fractional bits 만큼의 비트 연산으로 가능
- float 과 고정 소수점 변환은 float 에 2^(fractional bits) 를 곱해줘 fractional bits 만큼 실수 값을 정수로 확대한 후 int 캐스팅을 통해 가능 

### ex02

**[연산자 오버로딩]**

- 고정 소수점 클래스 Fixed에 연산자 오버로딩 추가
- 비교 연산자, 이항 연산자, 단항 연산자 구현
- 전역 함수로 std::ostream 의 operator<< 연산자 오버로딩

### ex03

**[CCW]**

- 고정 소수점 클래스 Fixed 를 이용한 Point 클래스 생성
- Point 객체가 다른 Point 객체 3개로 만들어진 삼각형의 내부에 존재하는지 외부에 존재하는지 판단하는 bsp() 함수 생성
- CCW 를 이용하여 간단하게 해결

## CPP03

### ex00

**[구현]**

- 이후 ex01, ex02, ex03 을 위해 부모클래스 ClapTrap 작성
- 멤버 변수
  - Hit points, Energy points, Attack damage
- 멤버 함수
  - attack(), takeDamage(), beRepaired()

### ex01

**[상속1]**

- ClapTrap 을 상속받는 ScavTrap 자식클래스 생성
- 멤버 변수의 값이 ClapTrap 과 다름
- 가상 함수 추가
  - 소멸자
  - attack()
- 새로운 함수 추가
  - guardGate()
  
### ex02

**[상속2]**

- ClapTrap 을 상속받는 FragTrap 자식클래스 생성
- 멤버 변수의 값이 ClapTrap 과 다름
- 가상 함수 추가
  - 소멸자
- 새로운 함수 추가
  - highFivesGuys()

### ex03

**[다이아몬드 상속]**

- ScavTrap 과 FragTrap 을 상속받는 DiamondTrap 자식 클래스 생성
- ClapTrap 을 2번 상속받으므로 ClapTrap을 가상 상속하여 문제 해결

## CPP04

### ex00

**[다형성]**

- Animal 이라는 부모클래스와 Dog, Cat 이라는 자식 클래스들 생성
- makeSound() 함수를 가상함수로 구현
- Animal* 에 Dog*, Cat* 를 넣어서 makeSound() 를 실행
- Animal* 지만 실제 객체인 Dog 의 makeSound()와 Cat 의 makeSound() 가 실행됨
- 동적 바인딩을 통해 가능

### ex01

**[깊은 복사]**

- Brain 클래스 추가
- ex00 의 Cat 과 Dog 에 멤버 변수 Brain* 추가
- Cat 과 Dog 의 복사 함수가 호출되면 Brain* 의 깊은 복사 실행
- 깊은 복사이므로 포인터 자체를 복사하는 것이 아닌 새로운 Brain 을 생성하여 내부 값을 복사
- 소멸자를 통해 memory leak 방지

### ex02

**[추상 클래스]**

- Animal 클래스의 makeSound() 를 순수 가상함수로 만들어 추상 클래스로 변경
- Animal 은 더이상 객체를 생성할 수 없음 (객체 생성시 컴파일 오류)

### ex03

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
  
## CPP05

## CPP06

## CPP07

## CPP08

## CPP09
