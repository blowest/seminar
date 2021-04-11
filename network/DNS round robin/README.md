# DNS round robin
## DNS 기본내용
- DNS(Domain Name System) 은 사람이 읽을 수 있는 도메인 이름(예 : www.amazon.com) 을 머신이 읽을 수 있는 IP주소(예: 192.0.2.44) 로 변환합니다. 

- 스마트폰이나 노트북, 서버와 같은 모든 인터넷상의 컴퓨터는 숫자를 이용해 서로를 찾고 통신합니다. 이런 숫자를 **IP 주소**라고 합니다. 웹 브라우저를 열고 웹사이트를 방문하기 위해서는 이 IP주소를 기억해 입력할 필요가 없습니다. 그 대신 example.com 과 같은 **도메인 이름** 을 입력해도 원하는 웹 사이트로 갈 수 있습니다. 

- DNS 서버에 도메인 이름에 대한 요청을 보내는 것을 **쿼리**라고 한다.

## Domain 구조
- 인터넷상에서 사용되는 도메인은 전 세계적으로 고유하게 존재하는 이름입니다.
- 정해진 규칙 및 체계에 따라야 하며, 임의로 변경되거나 생성될 수 없습니다.

![Domain 구조](https://t1.daumcdn.net/cfile/tistory/997DA9405BDFB7B71E)

## DNS 서비스 유형
- 신뢰할 수 있는 DNS
    - 개발자가 퍼블릭 DNS 이름을 관리하는 데 사용하는 업데이트 메커니즘을 제공하며, 이를 통해 DNS 쿼리에 응답하여 도메인 이름을 IP 주소로 변환합니다.
    - 신뢰할 수 있는 DNS는 도메인에 대해 최종 권한이 있으며 재귀적 DNS 서버에 IP 주소 정보가 담긴 답을 제공할 책임이 있습니다.

- 재귀적 DNS
    - 보통 클라이언트는 신뢰할 수 있는 DNS 서비스에 직접 쿼리를 수행하지 않고, 해석기 또는 재귀적 DNS 서비스라고 알려진 다른 유형의 DNS 서비스에 연결하는 경우가 일반적입니다.
    - DNS 레코드를 소유하고 있지 않지만 사용자를 대신해서 DNS 정보를 가져올 수 있는 중간자의 역할을 합니다.
    - 일정 기간 동안 캐시된 또는 저장된 DNS 레퍼런스를 가지고 있는 경우, 소스 또는 IP 정보를 제공하여 DNS 쿼리에 답을 하거나, 해당 정보를 찾기 위해 쿼리를 하나 이상의 신뢰할 수 있는 DNS 서버에 전달합니다.

## DNS 동작원리
![DNS 동작원리](https://t1.daumcdn.net/cfile/tistory/99C16C455BDFBB2A23)
1. 웹 브라우저에 www.naver.com을 입력하면 먼저 Local DNS에게 "www.naver.com"이라는 hostname에 대한 IP 주소를 질의하여  Local DNS에 없으면 다른 DNS name 서버 정보를 받음(Root DNS 정보 전달 받음)

2. Root DNS 서버에 "www.naver.com" 질의

3. Root DNS 서버로 부터 "com 도메인"을 관리하는 TLD (Top-Level Domain) 이름 서버 정보 전달 받음

4. TLD에 "www.naver.com" 질의

5. TLD에서 "naver.com" 관리하는 DNS 서버정보 전달

6. "naver.com" 도메인을 관리하는 DNS 서버에 "www.naver.com" 호스트네임에 대한 IP 주소 질의

7. Local DNS 서버에게 "www.naver.com에 대한 IP 주소는 222.122.195.6" 응답 

8. Local DNS는 www.naver.com에 대한 IP 주소를 캐싱을 하고 IP 주소 정보 전달 

이와 같이 Local DNS 서버가 여러 DNS 서버를 차례대로 (Root DNS 서버 -> com DNS 서버 -> naver.com DNS 서버) 물어봐서 그 답을 찾는 과정을 **Recursive Query**라고 부릅니다.

## DNS round robin
DNS round robin 은 별도의 소프트웨어 혹은 하드웨어 로드밸런싱(load balancing) 장비를 사용하지 않고, DNS만을 이용하여 도메인 레코드를 조회하는 시점에서 트래픽을 분산시키는 방법입니다.

## DNS round robin의 원리
웹 서버의 경우 웹 서비스를 담당할 여러대의 웹 서버는 각각 자신의 공인 IP주소를 가지고 있습니다. 웹 사이트에 접속을 원하는 사용자가 해당 도메인 주소를 브라우저에 입력하면, DNS는 도메인 정보를 조회하는데, 이때 IP주소를 여러 대의 서버 IP주소 리스트 중에서 round robin 형태로 랜덤하게 하나 혹은 여러개를 선택하여 다시 사용자에게 알려줍니다.

결과적으로 하나의 웹사이트에 접속하는 다수의 사용자는 실제로는 복수의 웹 서버에 나뉘어 접속하게 되면서 자연스럽게 서버의 부하가 분산되는 방식입니다.

![round robin](https://t1.daumcdn.net/cfile/tistory/2413C14E590B4F8A3A)

## DNS round robin 장단점
### 장점
- 비용적인 부담이 줄어듬
- 중간 장비 없이도 서비스 가능
### 단점
- 서버의 수 만큼 공인 IP주소가 필요함
- 부하의 분산이 고르지 않음(캐싱주기)
- 서버에 이상이 있는경우에도 이상이 있는 서버로 부하를 분산 *(health check를 하지 않는다.)*

## DNS round robin의 단점을 보완하는 알고리즘들
- Weighted round robin (WRR)

각각의 웹 서버에 가중치를 가미해서 분산 비율을 변경합니다.  가중치가 큰 서버일수록 자주 선택되므로 처리능력이 높은 서버는 가중치를 높게 설정하는 것이 좋습니다.
- Least connection

접속 클라이언트 수가 가장 적은 서버를 선택합니다. 로드밸런싱에서 실시간으로 connection 수를 관리하거나 각 서버에서 주기적으로 알려주는 것이 필요합니다.


## Reference
1. [DNS 동작원리](https://ijbgo.tistory.com/27) 
2. [What is DNS?](https://aws.amazon.com/ko/route53/what-is-dns/)
3. [네임(DNS)서버의 도메인을 이용한 DNS 라운드 로빈](https://server-talk.tistory.com/121)
4. [라운드 로빈 DNS를 이용한 로드밸런싱](https://m.blog.naver.com/sehyunfa/221691155719)

#BLowest/seminar