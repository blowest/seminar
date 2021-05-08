# REST API
## Advent
* **프론트엔드Front-End와 백엔드Back-End가 분리되기 시작**
	* 새로운 서비스 개발을 위해 개발작업 진행
	* JSON 형태로 데이터를 제공하는 API를 제공하자고 동의
	* RequestMethod(HTTP: GET, POST, PUT, DELETE)와 URL을 이용한 정의
	* View 영역이 포함되지 않은 서버사이드Server-side 개발을 진행
* **멀티플랫폼에 대한 지원을 위해 서비스 자원에 대한 아키텍처를 세우고 이용하는 방법을 모색**
	* 웹 + 모바일 웹
	* 아이폰, 안드로이드
* **OPEN API**
	* 웹 2.0 시대 이후 다양한 매시업Mashup 서비스들이 출현할 수 있었던 밑바탕에는 깔끔하게 정리된 REST API 덕분이 아닐까?

## Definition
* Representational State Transfer
* 자원의 이름(자원의 표현)으로 구분하여 해당 자원의 상태(정보)를 주고 받는 모든 것을 의미
* 즉, **자원(resource)의 표현(representation)**에 의한 **상태 전달**
	* 자원
		* 해당 소프트웨어가 관리하는 모든 것 -> ex) 문서, 그림, 데이터, 해당 소프트웨어 자체 등...
	* 자원의 표현
		* 그 자원을 표현하기 위한 이름 -> ex) DB의 학생 정보가 자원일 때, 'students'를 자원의 표현으로 정함
	* 상태(정보) 전달
		* 데이터가  요청되어지는 시점에서 자원의 상태(정보)를 전달한다.
		* JSON 혹은 XML를 통해 데이터를 주고 받는 것이 일반적이다.
* REST API는 네트워크 상에서 Client와 Server사이의 통신 방식 중 하나이다.
	
## Pros & Cons
### Pros
* REST API는 기본적으로 웹이 기존 기술과 HTTP 프로토콜을 그대로 활용하기 때문에 웹의 장점을 최대한 활용할 수 있는 아키텍처 스타일이다.
* HTTP 프로토콜 인프라를 그대로 사용하므로 REST API 사용을 위한 별도의 인프라를 구축할 필요 없다.
* HTTP 표준 프로토콜에 따르는 모든 플랫폼에서 사용이 가능하다.
* REST API 메시지가 의도하는 바를 명확하게 나타내므로 의도하는 바를 쉽게 파악할 수 있다.
* 여러가지 서비스 디자인에서 생길 수 있는 문제를 최소화 한다.
* 서버와 클라이언트의 역할을 명확하게 분리한다.
### Cons
* 표준 규약이 없다
* 안티패턴으로 설계될 가능성이 높다
	* HTTP Method의 잘못된 사용 -> Delete를 하는데 POST사용
	* HTTP Response code를 2, 3개만 활용 -> error를 피하기위해 한번 감싸는 행위, 불필요한 약속발생
* RDBMS의 표현에 적합하지 않다.

## Components
1. 자원(Resource): URI
	* 모든 자원에 고유한 ID가 존재, 이 자원은 Server에 존대
	* 자원을 구별하는 ID는 `/groups/:groups_id`같은 HTTP URI다
	* Client는 URI를 이용해서 자원을 지정하고 자원의 상태(정보)에 대한 조작을 Server에 요청한다
2. 행위(Verb): HTTP Method
	* HTTP 프로토콜의 Method를 사용
	* HTTP 프로토콜은 `GET`, `POST`, `PUT`, `DELETE`와 같은 메서드를 제공
3. 표현(Representational of Resource)
	* Client가 자원의 상태(정보)에 대한 조작을 요청하면 Server는 이에 적절한 응답을 보냄
	* REST에서 하나의 자원은 JSON, XML, TEXT, RSS등 여러 형태의 Representation으로 나타내어 질 수 있다.
	* JSON 혹은 XML을 통해 데이터를 주고 받는 것이 일반적이다.

## Features
1. Server-Client(서버-클라이언트 구조)
2. Stateless(무상태)
3. Cacheable(캐시 처리 가능)
4. Layered System(계층화)
5. Code-On-Demand(optional)
6. Uniform Interface(인터페이스 일관성)

## Example
1. [HTTP Request Methods](https://developer.mozilla.org/en-US/docs/Web/HTTP/Methods)
![](img/Screen%20Shot%202021-05-08%20at%2012.08.23%20AM.png)

2.   [HTTP Response Status Code](https://developer.mozilla.org/en-US/docs/Web/HTTP/Status)
![](img/Screen%20Shot%202021-05-08%20at%2012.09.36%20AM.png)
![](img/Screen%20Shot%202021-05-08%20at%2012.09.52%20AM.png)

## Reference
* https://velog.io/@jch9537/URI-URL
* https://gmlwjd9405.github.io/2018/09/21/rest-and-restful.html
* https://round-round.tistory.com/entry/REST-API%EC%9D%98-%EB%8B%A8%EC%A0%90-3%EA%B0%80%EC%A7%80
* https://meetup.toast.com/posts/92
* http://recordingbetter.com/drf/2017/07/11/REST%EC%9D%98-%ED%83%84%EC%83%9D-%EB%B0%B0%EA%B2%BD









