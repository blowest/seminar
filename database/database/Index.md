# Index

## 인덱스란?
인덱스는 말 그대로 책의 맨 처음 또는 맨 마지막에 있는 색인이라고 할 수 있다.
* 데이터 - 책의 내용
* 레코드 주소 - 인덱스 목록에 있는 페이지 번호

DBMS 도 데이터 베이스 테이블의 모든 데이터를 검색해서 원하는 결과를 가져 오려면 시간이 많이 걸림
-> Column 값과 해당 레코드가 저장된 주소를 키와 값의 쌍으로 인덱스를 만들어 두는 것

DBMS 의 인덱스는 항상 정렬된 상태를 유지하기 때문에 원하는 값을 탐색하는데는 빠르지만, 새로운 값을 추가 / 삭제 / 수정 하는 경우에는 쿼리문 실행 속도 저하가 발생한다.
DBMS 에서 인덱스는 데이터의 저장 성능을 희생하고 그 대신 데이터의 읽기 속도를 높이는 기능
SELECT 쿼리 문장의 WHERE 조건절에 사용되는 Column 모두 인덱스로 생성하면 데이터 저장 성능이 오히려 떨어짐

## Index 자료구조

### B+-Tree 인덱스 알고리즘
일반적으로 사용되는 인덱스 알고리즘은 B+-Tree 알고리즘이다. B+-Tree 인덱스는 칼럼의 값을 변형하지 않고(사실 값의 앞부분만 잘라서 관리한다.), 원래의 값을 이용해 인덱싱하는 알고리즘이다.

1. B-Tree

![B-Tree](https://user-images.githubusercontent.com/22471799/114188266-ef54a700-9983-11eb-87bf-aa92a10ae18c.png)


B-tree는 Binary Search Tree를 확장한 Tree로 각 Node는 여러개의 Key를 가질 수 있고, 여러개의 Child를 가질 수 있다.

또한 모든 Leaf Node는 동일한 Depth를 갖고 있다. Key는 B-tree 알고리즘에 따라 정렬되어 각 Node에 배치된다.

[그림 1]은 3 Order B-Tree를 나타내고 있다. 각 Node는 최대 2개의 Key를 가질 수 있고, 최대 3개의 Child를 가질 수 있다.

각 Node에는 여러개의 Key를 갖고 있고 각 Key에 대응하는 Data도 함께 갖고 있다.

하나의 Node에 여러개의 Key를 갖기 때문에 Block 단위로 Data를 Read/Write하는 Disk 환경에서는 Binary Search Tree보다 B-Tree를 이용하는 것이 유리하다.

2. B+ Tree

![B+Tree](https://user-images.githubusercontent.com/22471799/114188289-f4195b00-9983-11eb-96b3-5ebf87b929d9.png)

B+ Tree는 B-Tree를 개량한 Tree이다. B-tree처럼 모든 Leaf Node는 동일한 Depth를 갖는다.

B-Tree와의 가장 큰 차이점은 Inner Node에는 Key만 저장이 되고 Leaf Node에 Key와 Data를 함께 저장한다는 점이다.

Leaf Node에만 Data가 저장되기 때문에 Leaf Node간의 Pointer를 연결하여 B-Tree에 비하여 쉬운 순회가 가능하다.

[그림 2]는 4 Order B+ Tree를 나타내고 있다. Inner Node는 최대 2개의 Key를 갖을 수 있고 Leaf Node는 최대 3개의 Key/Value를 갖을 수 있다.

B+ Tree의 Inner Node는 Data가 없기 때문에 B-Tree의 Inner Node에 비하여 용량작다.

하나의 Disk Block에 더 많은 Inner Node를 배치 할 수 있게 되어, Key 탐색시 B-Tree에 비하여 상대적으로 적은 Disk Block만 읽어도 된다.

이러한 이점 때문에 B+ Tree는 Key 탐색시 B-Tree보다 좀더 나은 성능을 보여준다.
### Hash 인덱스 알고리즘
칼럼의 값으로 해시 값을 계산해서 인덱싱하는 알고리즘으로 매우 빠른 검색을 지원한다.
하지만 값을 변형해서 인덱싱하므로, 특정 문자로 시작하는 값으로 검색을 하는 전방 일치와 같이 값의 일부만으로 검색하고자 할 때는 해시 인덱스를 사용할 수 없다.
주로 메모리 기반의 데이터베이스에서 많이 사용한다.

### 왜 index 를 생성하는데 b-tree 를 사용하는가?
데이터에 접근하는 시간복잡도가 O(1)인 hash table 이 더 효율적일 것 같지만 SELECT 질의의 조건에는 부등호(<>) 연산도 포함이 된다.
Hash table 을 사용하게 된다면 등호(=) 연산이 아닌 부등호 연산의 경우에 문제가 발생한다.
동등 연산(==)에 특화된 Hash table은 데이터베이스의 자료구조로 적합하지 않다.


## Primary Index vs Secondary Index
클러스터(Cluster)란 여러 개를 하나로 묶는다는 의미로 주로 사용되는데, 클러스터드 인덱스도 크게 다르지 않다.

인덱스에서 클러스터드는 비슷한 것들을 묶어서 저장하는 형태로 구현되는데, 이는 주로 비슷한 값들을 동시에 조회하는 경우가 많다는 점에서 착안된 것이다.

여기서 비슷한 값들은 물리적으로 인접한 장소에 저장되어 있는 데이터들을 말한다.

클러스터드 인덱스는 테이블의 프라이머리 키에 대해서만 적용되는 내용이다. 즉 프라이머리 키 값이 비슷한 레코드끼리 묶어서 저장하는 것을 클러스터드 인덱스라고 표현한다.

클러스터드 인덱스에서는 프라이머리 키 값에 의해 레코드의 저장 위치가 결정되며 프라이머리 키 값이 변경되면 그 레코드의 물리적인 저장 위치 또한 변경되어야 한다.

그렇기 때문에 프라이머리 키를 신중하게 결정하고 클러스터드 인덱스를 사용해야 한다.

클러스터드 인덱스는 테이블 당 한 개만 생성할 수 있다. 프라이머리 키에 대해서만 적용되기 때문이다, 이에 반해 non 클러스터드 인덱스는 테이블 당 여러 개를 생성할 수 있다.


## Composite Index
인덱스로 설정하는 필드의 속성이 중요하다.

title, author 이 순서로 인덱스를 설정한다면 title 을 search 하는 경우, index 를 생성한 효과를 볼 수 있지만,

author 만으로 search 하는 경우, index 를 생성한 것이 소용이 없어진다.

따라서 SELECT 질의를 어떻게 할 것인가가 인덱스를 어떻게 생성할 것인가에 대해 많은 영향을 끼치게 된다.


## Index 의 성능과 고려해야할 사항
SELECT 쿼리의 성능을 월등히 향상시키는 INDEX 항상 좋은 것일까? 쿼리문의 성능을 향상시킨다는데, 모든 컬럼에 INDEX 를 생성해두면 빨라지지 않을까?

결론부터 말하자면 그렇지 않다. 우선, 첫번째 이유는 INDEX 를 생성하게 되면 INSERT, DELETE, UPDATE 쿼리문을 실행할 때 별도의 과정이 추가적으로 발생한다.

INSERT 의 경우 INDEX 에 대한 데이터도 추가해야 하므로 그만큼 성능에 손실이 따른다.

DELETE 의 경우 INDEX 에 존재하는 값은 삭제하지 않고 사용 안한다는 표시로 남게 된다. 즉 row 의 수는 그대로인 것이다. 이 작업이 반복되면 어떻게 될까?

실제 데이터는 10 만건인데 데이터가 100 만건 있는 결과를 낳을 수도 있는 것이다. 이렇게 되면 인덱스는 더 이상 제 역할을 못하게 되는 것이다.

UPDATE 의 경우는 INSERT 의 경우, DELETE 의 경우의 문제점을 동시에 수반한다. 이전 데이터가 삭제되고 그 자리에 새 데이터가 들어오는 개념이기 때문이다.

즉 변경 전 데이터는 삭제되지 않고 insert 로 인한 split 도 발생하게 된다.

하지만 더 중요한 것은 컬럼을 이루고 있는 데이터의 형식에 따라서 인덱스의 성능이 악영향을 미칠 수 있다는 것이다.

즉, 데이터의 형식에 따라 인덱스를 만들면 효율적이고 만들면 비효율적은 데이터의 형식이 존재한다는 것이다. 어떤 경우에 그럴까?

**이름**, **나이**, **성별** 세 가지의 필드를 갖고 있는 테이블을 생각해보자.

이름은 온갖 경우의 수가 존재할 것이며 나이는 INT 타입을 갖을 것이고, 성별은 남, 녀 두 가지 경우에 대해서만 데이터가 존재할 것임을 쉽게 예측할 수 있다.

이 경우 어떤 컬럼에 대해서 인덱스를 생성하는 것이 효율적일까? 결론부터 말하자면 이름에 대해서만 인덱스를 생성하면 효율적이다.

왜 성별이나 나이는 인덱스를 생성하면 비효율적일까? 10000 레코드에 해당하는 테이블에 대해서 2000 단위로 성별에 인덱스를 생성했다고 가정하자.

값의 range 가 적은 성별은 인덱스를 읽고 다시 한 번 디스크 I/O 가 발생하기 때문에 그 만큼 비효율적인 것이다.