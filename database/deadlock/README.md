# 교착상태

### 교착상태(DeadLock)란?
- 복수의 프로세스가 기능하지 못한 상태를 무한정 기다리고 있는 상태
- 두 개 이상의 프로세스가 하나의 자원을 공유하여 사용하고 있을 때 서로가 사용할 자원을 요구하지만 요구를 영원히 들어줄 수 없는 상태

![교착상태](https://img1.daumcdn.net/thumb/R800x0/?scode=mtistory2&fname=https%3A%2F%2Ft1.daumcdn.net%2Fcfile%2Ftistory%2F26444B4858FAF76031)  
<br/>
<br/>
  

## &#10146; Bridge Crossing Example

<p align="center"><img src="https://www.massey.ac.nz/~mjjohnso/notes/59305/mod7d1.gif"></p>
<br/>

### 교착상태의 필요조건
1. 상호배제(Mutual Exclusion)  
 최소한 하나의 자원을 점유한 채, 현재 다른 프로세스에 의해 점유된 자원을 추가로 얻기 위해 대기하고 있어야만 한다.(비공유)

2. 점유하며 대기(Hold-and-Wait)  
프로세스는 최소한 하나의 점유한 채, 현재 다른 프로세스에 의해 점유된 자원을 추가로 얻기 위해 대기하고 있어야 한다.

3. 비선점(No-Preemption)  
자원들을 선점할 수 없어야 한다. 즉, 자원이 강제적으로 방출될 수 없고, 점유하고 있는 프로세스가 태스크를 종료한 후 프로세스에 의해 자발적으로만 방출될 수 있다.

4. **순환대기(Circular-Wait)**  
각 프로세스가 꼬리를 물며 자원을 점유하고 있어야 한다.
![순환대기](https://4.bp.blogspot.com/-8QcCWBZpkxE/WPyqwK8T5KI/AAAAAAAABIw/0xudTPUh514WIEhkSEhuvGZK4GSchzz6gCLcB/s1600/deadlock03.png)
<br/>
<br/>

### 교착상태 해결 방안
1. 교착상태 예방 
    * 상호배제 부정 (자원 공유 가능)
    * 점유대기 부정 (시스템 효율, 비용, 기아상태 등의 많은 문제점 발생)
    * 비선점 부정 (가장 현실적이고 실현가능함)
    * 순환대기 부정 (자원에 고유한 번호 할당, 선형화)
2. 교착상태 회피
    * 자원할당 알고리즘
    * 은행원 알고리즘
3. 교착상태 발견
    * 자원과 프로스세들을 인접행렬로 표현
4. 교착상태 무시
    * 교착상태가 드물게 발생하는 시스템
<br/>
<br/>
<br/>

### 교착상태의 빈도를 줄이기 위해
1. 인덱스를 설정한다. 인덱스가 없으면 LOCK이 걸리는 범위가 훨씬 넓어지기 때문에 교착상태가 발생하기 쉬워진다.
2. 자원들을 한쪽으로 사용한다. A와 B라는 테이블이 있다면 모든 세션에서 A->B 순서로 사용하도록 한다.
3. 트랜잭션은 가급적 짧게 만든다.
4. 테이블의 크기를 작게 쪼갠다.(정규화)
<br/>
<br/>
<br/>


___
## Reference
* https://blog.naver.com/dktmrorl/222287365901
* https://www.youtube.com/watch?v=ofCwGdzKeHY&t=418s