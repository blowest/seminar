# 🖥 NoSQL
## ⚖️ NoSQL이란?
* **Not Only SQL**의 약자로 기존 RDBMS 형태의 관계형 데이터베이스가 아닌 **다른형태의 데이터 저장기술**을 의미합니다.
* 기존의 관계형 데이터베이스보다 더 융통성 있는 데이터 모델을 사용하고 **데이터의 저장 및 검색을 위한 특화된 메커니즘을 제공**합니다.
* 초 고용량 데이터 처리 등 성능에 특화된 목적을 위해 비관계형 데이터 저장소에 **비구조적인 데이터**를 저장하기 위한 분산저장 시스템이라고 볼수 있습니다.

## 📖 CAP 이론
* 분산형 구조는 일관성(Consistency), 가용성(Availability), 분산 허용(Partitioning Tolerance)의 3가지 특징을 가지고 있습니다.
* CAP 이론은 이 중 2가지만 만족할 수 있다는 이론입니다. NoSQL은 대부분 이 CAP이론을 따르고 있습니다.
* 일반적으로 RDBMS는 일관성과 가용성을 만족합니다. NoSQL은 **가용성과 분산허용**을 만족하는 제품군과 **일관성과 분산허용**을 만족하는 제품군으로 나눌 수 있습니다.
### 1. 일관성(Consistency)
* 분산된 노드 중 어느 노드로 접근하더라도 데이터 값이 같아야 합니다.
### 2. 가용성(Availability)
* 클러스터링된 노드 중 하나 이상의 노드가 실패(Fail)하더라도 정상적으로 요청을 처리할 수 있는 기능을 제공합니다.
### 3. 분산허용? 네트워크 분할성?(Partitioning Tolerance)
* 클러스터링 노드 간에 통신하는 네트워크 장애가 나더라도 정상적으로 서비스를 수행합니다. 노드 간 물리적으로 전혀 다른 네트워크공간에 위치도 가능합니다.

## 🛠 저장방식에 따른 분류(데이터 모델 분류)
* NoSQL은 거대한 Map<String, Object>이라고 할 수 있습니다. 따라서 대부분 NoSQL은 Key/Value 개념을 지원합니다. 이 때 저장소는 RAM일 수도, 디스크일 수도 있습니다. 보통 데이터 모델(Key에 저장되는 값)에 따라 NoSQL을 분류합니다.
### 1. Key-Value Model
* 단순한 저장구조를 가지며, 복잡한 조회 연산을 지원하지 않습니다.
* 고속읽기와 쓰기에 최적화된 경우가 많습니다. Key에 대한 단위 연산이 빠른 것이지, 여러 Key에 대한 연산은 느릴 수 있습니다.
* 메모리를 저장소로 쓰는 경우, 아주 빠른 get과 put을 지원합니다.
-> ex)  Redis(In-memory), Oracle Coherence 등
### 2. Document Model
* Key/Value Store의 확장된 형태로, **Value에 Document라는 타입을 저장**합니다. Document는 구조화된 문서 데이터(XML, JSON, YAML 등)를 말합니다.
* 복잡한 데이터 구조를 표현가능합니다.
* Document id 또는 특정 속성값 기준으로 인덱스를 생성합니다. 이경우 해당 Key값의 range에 대한 효율적인 연산이 가능해 지므로 이에 대한 쿼리를 제공합니다. 따라서 Sorting, Join, Grouping 등이 가능해집니다.
* 쿼리 처리에 있어서 데이터를 파싱해서 연산을 해야하므로 overhead가 key-value 모델보다 큽니다. 큰 크기의 document를 다룰 때는 성능이 저하됩니다.
-> ex) MongoDB, CouchDB, Riak 등
### 3. Column Model
* Key-Value Model의 확장입니다.
* Value는 문자열이나 정수와 같은 원시 타입이 들어갈 수도 있고, 아래 사진처럼 또 다른 Key/Value형태가 들어갈 수도 있습니다. 이를 Column Family라고 하며, Key 안에 (Column, Value)조합으로 된 여러 개의 필드를 갖는 것을 말합니다.
![](img/Screen%20Shot%202021-04-21%20at%209.23.28%20PM.png)
-> ex) HBase, Cassandra, Hypertable 등

## 📚 Reference
* https://namu.wiki/w/NoSQL
* https://lygggg.github.io/blog/NoSql/
* https://jwprogramming.tistory.com/70
* https://gangnam-americano.tistory.com/30
* https://sjh836.tistory.com/97
* https://blog.voidmainvoid.net/231
* https://12bme.tistory.com/323