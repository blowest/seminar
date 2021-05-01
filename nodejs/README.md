# Node js
## Node js란?
![node정의](https://perfectacle.github.io/images/what-is-node-js/01.png)

1. JavaScript 런타임
    
    Node는 JavaScript 런타임입니다.
    런타임이란 특정 언어로 만든 프로그램을 실행시킬 수 있는 환경을 말합니다. 기존의 JavaScript는 프로그램을 브라우저에서만 실행할 수 있었지만 Node를 통해 컴퓨터에서 실행할 수 있습니다.

2. Event - Driven(이벤트 기반)

    이벤트 기반(event-driven)이란 이벤트가 발생할 때 미리 지정해둔 작업을 수행하는 방식을 의미합니다. 즉, 이벤트 기반 시스템에서는 특정 이벤트가 발생할 때 무엇을 할지 미리 등록해두고, 이를 이벤트 리스너에 콜백 함수를 등록 합니다. 이후 이벤트가 발생하면 리스너에 등록해둔 콜백 함수를 호출하며 이벤트가 끝난 후 노드는 다음 이벤트가 발생할 때까지 대기합니다.

    이벤트 루프(event loop)는 여러 이벤트가 동시에 발생했을 때 어떤 순서로 콜백 함수를 호출할지 판단합니다. 노드는 이벤트가 종료될 때까지 이벤트 처리를 위한 작업을 반복 하므로 루프(loop)라고 부릅니다.

    - 이벤트 루프 : 이벤트 발생시 호출한 콜백 함수들을 관리 및 실행순서 결정
    - 태스크 큐 (콜백 큐) : 이벤트 발생 후 호출되어야 할 콜백 함수들이 기다리는 공간
    - 백그라운드 : 타이머나 I/O 작업 콜백 또는 이벤트 리스너들이 대기하는 곳

    ![이벤트기반](https://media.vlpt.us/images/kimkevin90/post/b5338968-d88a-40ca-a3db-e0c923cbbfb9/%EB%A3%A8%ED%94%84.png)

3. Non-blocking I/O 모델

   이벤트 루프를 잘 활용하면 오래 걸리는 작업을 효율적으로 처리할 수 있습니다. 작업에는 두가지 종류가 있는데, 동시에 실행될 수 있는 작업과 동시에 실행될 수 없는 작업입니다. 특히 파일 시스템 접근, 네트워크를 통한 요청 작업은 I/O의 일종이며 이러한 작업을 할 때 노드는 Non-blocking 방식으로 처리합니다. Non-blocking이란 이전 작업이 완료될 때까지 대기하지 않고 다음 작업을 수행하는 것을 의미합니다. 반대로 blocking은 이전 작업이 끝나야만 다음 작업을 수행합니다.

4. Node의 장단점
    
    - 장점
        - 멀티 스레드 방식에 비해 컴퓨터 자원을 적게 사용함
        - I/O 작업이 많은 서버로 적합
        - 멀티 스레드 방식보다 쉬움
        - 웹 서버가 내장되어 있음
        - 자바스크립트를 사용함
        - JSON 형식과 호환하기 쉬움
    - 단점
        - 싱글 스레드라서 CPU 코어를 하나만 사용함
        - CPU 작업이 많은 서버로는 부적합
        - 하나뿐인 스레드가 멈추지 않도록 관리해야 함
        - 서버 규모가 커졌을 때 서버를 관리하기 어려움

## npm이란?

npm은 Node Package Manager의 약자로 JavaScript를 위한 패키지 관리자입니다.

npm은 세계 최대의 소프트웨어 창고로 80만개가 넘는 코드 패키지를 가지고 있습니다. 

- npm은 소프트웨어를 다운로드하거나 설치하기 위해 사용되곤하는 CLI(Command Line Interface)를 사용합니다. 예를들어 npm init -y 을 통해 package.json 파일을 만들어 프로젝트를 시작할 수 있고, npm install <패키지 명> 으로 해당 프로젝트에서 패키지를 설치할 수도 있다.

- npm(Node Package Manager)은 처음에는 Node.js를 위한 패키지 매니저로 만들어졌기 때문에 이런 이름을 가지게 된 것입니다. 모든 npm 패키지들은 ```package.json``` 이라 불리는 파일안에 정의됩니다. ```package.json``` 의 내용은 항상 JSON으로 쓰여져야합니다. 적어도 두 개의 필드 name(프로젝트의 이름)과 version은 항상 존재해야 합니다.

- npm을 대체하기 위해 페이스북에서 yarn을 도입했습니다. yarn은 npm과 호환이 가능하고 리액트를 사용할 때도 좋다고합니다.

- 패키지 매니저가 하는 일

    - 패키지의 dependency 관리
    - 패키지의 보안관리 ㅡ 신뢰할 수 있고(authenticity), 손상되지 않음(integrity)을 보장
    - 여러 패키지를 기능에 따라 그룹으로 묶어 정리
    - 패키지 압축 해제
    - Software repository로부터 패키지를 찾고, 다운로드하고, 설치하고, 업데이트하는 역할


- Dependencies(의존성) 관리

    많은 패키지들은 다른 패키지가 설치되어 있어야만 제대로 동작합니다.
    
    이 경우에 기존 패키지를 제대로 동작시키기 위해 필요한 다른 패키지를 'dependency'라고 말합니다.

    따라서 패키지를 사용하고자 할 때 dependency에 해당되는 다른 패키지들을 전부 설치해줄 필요가 있습니다.

    하지만 그런 새로운 패키지(dependency)들을 설치하는 도중 이번엔 설치하고 있는 패키지의 dependency를 설치해야 하는 상황이 발생할 수 있습니다.

    즉, dependency의 dependency를 설치하는 경우가 생기며, 이런 상황이 끊임없이 이어질 경우 사용자가 수동으로 패키지를 관리하기가 불가능에 가까워집니다. 이런 상황을 dependency hell이라고 합니다.

    따라서 각각의 패키지가 자신의 dependency에 대한 정보를 가지게 한다면, 사용자가 사용하고자 하는 패키지의 dependency를 패키지 매니저를 통해 쉽게 설치하도록 도울 수 있습니다.

## NestJs란
Nest(Nestjs)는 nodejs의 서버 측 어플리케이션을 구축하기 위한 프레임 워크로, NodeJS 프레임워크인 Express나 Fastify 등의 API를 직접 사용할 수도 있으며 혹은 NestJS 에서 제공하는 추상화된 인터페이스를 이용할 수도 있습니다. 

Typescript 기반의 OOP(Object Oriented Programming), FP(Functional Programming), FRP(Functional Reactive Programming)를 지원합니다.

공식문서를 보면 Angular에 기반을 둔 프레임워크란 점을 알 수 있습니다.

NestJS는 효율적(efficient)이면서, 규모 가변성(scalable)을 지닌 NodeJS 프레임워크라고 합니다.

참고 - [NestJs API만들기](https://velog.io/@suasue/NestJS-%EC%B4%88%EA%B8%B0-%EC%84%B8%ED%8C%85)

TypeORM, GraphQL, crypto, 데코레이터(어노테이션)