# CPP
c++ 을 10 가지 주제로 나눠 공부
- c++98 standard 를 적용
- Orthodox Canonical Form 형식으로 디자인

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

**[참조와 포인터]**

- 참조와 포인터의 차이
  - 변수의 참조와 포인터를 만들어 주소와, 값을 출력하여 둘의 차이점을 확인
    


## ex03

## ex04

## ex05

## ex06


## CPP02

## CPP03

## CPP04

## CPP05

## CPP06

## CPP07

## CPP08

## CPP09
