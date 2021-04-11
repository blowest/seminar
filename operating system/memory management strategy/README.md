# 메모리 관리 전략
## 배경
- 주기억장치에 다수의 프로세스를 적재하기 위하여 운영체제와 하드웨어에 의해 수행되는 작업
- 많은 프로세스를 메모리에 적재할 수 있도록 메모리를 효과적으로 할당해야 합니다. -> 제한된 메모리의 효율적인 사용(할당)
- 효율적인 참조(논리-물리 주소 할당)

## 메모리 관리 기법
- 고정 분할 기법(fixed partitioning)
- 동적 분할 기법(dynamic partitioning)
- **paging** 
- **segmentation**

### 1. 고정 분할 기법 (Fixed Partitioning)
![고정균등분할](https://img1.daumcdn.net/thumb/R800x0/?scode=mtistory2&fname=https%3A%2F%2Ft1.daumcdn.net%2Fcfile%2Ftistory%2F21784E495392ECF305)
![교정비균등분할](https://img1.daumcdn.net/thumb/R720x0.q80/?scode=mtistory2&fname=http%3A%2F%2Fcfile1.uf.tistory.com%2Fimage%2F236D0D4C5392ED032ACE64)

- 주기억장치를 겹치지 않는 영역(partitions)들의 집합으로 분할하여 할당하고 관리하는 기법입니다.
- partition은 동일한 크기를 가지거나 다른 크기를 가질 수 있습니다.
- **내부 단편화** : 적재하고 남은 공간
- **외부 단편화** : 작은 크기의 단편들이 생성되어 큰 프로그램을 배치하지 못합니다.

### 2. 동적 분할 기법 (Dynamic Partitioning)
- 주기억장치를 각각 다른 크기와 수의 partition으로 분할하는 기법 
- 각 프로세스에게 필요한 만큼의 메모리 공간을 할당해줍니다.
- 주기억장치가 서로 다른 크기의 partition으로 분할됩니다.

![동적분할기법](https://img1.daumcdn.net/thumb/R720x0.q80/?scode=mtistory2&fname=http%3A%2F%2Fcfile1.uf.tistory.com%2Fimage%2F240F55455392F87337EB1D)

- 외부 단편화 문제가 발생
- **압축(compaction)** 이 필요 -> 너무 오래 걸리는 작업이라 압축의 횟수를 줄여야 합니다.

![동적분할 배치 알고리즘](https://img1.daumcdn.net/thumb/R800x0/?scode=mtistory2&fname=https%3A%2F%2Ft1.daumcdn.net%2Fcfile%2Ftistory%2F2451F54653930B5E0A)

- 동적 분할 배치 알고리즘
    - Best-fit -> 더 작은 내부 단편화를 발생시킵니다.
    - First-fit
    - Next-fit
    - Worst-fit

#### 주소의 종류
- 물리적 주소(physical address) : 실제 주기억장치의 물리적인 위치
- 논리적 주소(logical address) : 물리적 주소와 독립적으로 프로그램을 컴파일할 때 메모리 참조를 논리적 주소로 생성합니다. 

![메모리 주소](https://t1.daumcdn.net/cfile/tistory/273CC43F5293F9C207)

- base register : 프로세스 시작의 물리적 주소
- bound(limit) register : 프로세스의 마지막 물리적 주소

### 3. 페이징 기법(paging)
- 주기억장치를 동일한 크기의 **프레임(frames)** 으로 분할
- 각 프로세스는 프레임과 동일한 크기의 **페이지(pages)** 로 분할
- 프로세스 페이지를 사용 가능한 주기억장치 프레임에 할당
- 하나의 프로세스가 주기억장치의 연속된 위치에 할당될 필요가 없습니다.
- 외부 단편화가 발생하지 않고 각 프로세스의 마지막 페이지에서만 내부 단편화가 발생할 수 있습니다.

![페이징 기법](https://lh3.googleusercontent.com/proxy/8IdmUZ9LFups_luy2IVZuadaOWQhhXsDhsJyCqhNhmXpez-0Fl3wcq2iB7WxZqeHiFmZuC5CUsqocZ2Yx_VZNJHyHSIHDEJEIpBCC7rWEtd03ckR)

- 논리적 주소는 **페이지 번호(page number)** 와 페이지 안에서의 **상대위치(offset)** 로 구성 되어있습니다.
- page table을 이용하여 프레임 번호를 찾고 상대위치와 합쳐 물리적 주소로 변환합니다.
- 공유 페이지가 가능합니다.

![공유 페이지](https://yangjaeleeblog.files.wordpress.com/2017/05/k-1303.jpg?w=730)

### 4. 세그멘테이션 기법(segmentation)

- 각 프로그램을 기능적인 단위(segments)로 나누는 방법

![세그먼트](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQICYRURNwYWeIgK7Hn-G8x8TWzkwXQIVKCQw&usqp=CAU)

- 프로세스를 주기억장치에 적재할 때 세그먼트 단위로 메모리를 할당합니다.
- 내부단편화가 없습니다.

![세그먼트 기법](https://user-images.githubusercontent.com/37871541/78534732-e20f5480-7825-11ea-975f-c4cd252fccfc.png)

- 논리적 주소는 **세그먼트 번호** 와 **상대위치(offset)** 로 구성되어 있습니다.
- segment table은 limit과 base로 구성 되어있습니다.
- base와 offset을 더하여 물리주소로 변환합니다.

## paging VS segmentation

|항목|paging|segmentation|
|------|---|----|
|할당 단위|크기 고정|크기 가변|
|적재 단위|프로그램 일부 적재|프로그램 전체 적재|
|장점|- 외부 단편화 없음</br>  - 교체시간 짧음|- 내부 단편화 최소화</br> - 코드, 데이터 공유 용이|
|단점|- 스레싱 문제 심각</br> - 내부 단편화 발생</br> - 코드, 데이터 공유논란|- 외부단편화 심각</br> - 메인 메모리 커야함</br> - 교체시간 길어짐|

## Reference
1. [메모리 관리 전략](https://dduddublog.tistory.com/32?category=801842)
2. [분산 메모리 할당 기법](http://blog.skby.net/%EB%B6%84%EC%82%B0-%EB%A9%94%EB%AA%A8%EB%A6%AC-%ED%95%A0%EB%8B%B9-%EA%B8%B0%EB%B2%95/)
3. [Memory Management Strategy](https://dheldh77.tistory.com/entry/%EC%9A%B4%EC%98%81%EC%B2%B4%EC%A0%9C%EB%A9%94%EB%AA%A8%EB%A6%AC-%EA%B4%80%EB%A6%AC-%EC%A0%84%EB%9E%B5Memory-Management-Strategy)
