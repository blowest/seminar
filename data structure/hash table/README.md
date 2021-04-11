# 🖥 Hash Table
## 📖 Hash Table 이란
![hash_table](../../image/hash_table.png)

*  해시 테이블은 **(Key, Value)쌍으로 데이터를 저장**하는 자료구조중 하나
* 내부적으로 **배열(Bucket)**을 사용하여 데이터를 저장하기 때문에 빠른 검색속도를 제공
* 해시 테이블은 각각의 Key값에 **hash function**을 적용해 배열의 고유한 index를 활용해 값을 Bucket에 저장하거나 검색
* Hash function을 사용하는데 **추가적인 연산이 필요**
* **Hash table의 크기가 유한**적이고 hash function의 특성상 **hash collision**이 발생할 수 밖에 없음
* 충돌이 없거나 적으면 𝑂(1)의 상수 시간에 가까워지고, 충돌이 발생하면 할수록 성능은 점점 𝑂(n)에 가까워짐


## 📖 Hash Function
* Hash function은 **임의의 길이를 갖는 메시지를 입력**받아 **고정된 길이의 해시값을 출력**하는 함수
* 암호 알고리즘에는 키가 사용되지만, hash function은 키를 사용하지 않으므로 같은 입력에 항상 같은 출력이 나옴
* 입력 값의 아주 일부만 변경되어도 전혀 다른 결과 값을 출력(눈사태 효과 - avalanche effect) -> 메시지의 오류나 변조를 탐지할 수 있는 무결성을 제공하기 위해 사용

## 💻 Implement Simple Hash Table 
```cpp
// HashTable.class

#include <iostream>

#define HASH_MAX 13
#define A 1
#define B 5
using namespace std;

class HashTable {

    int hashTable[HASH_MAX];

public:

    // Constructor
    HashTable() {
    }

private:

    int strLen(char *input) {
        int cnt = 0;
        while (input[cnt] != '\0') cnt++;

        return cnt;
    }

    int split(char *str) {
        int ret = 0;

        int len = strLen(str);
        for (int i = 0; i < len; i++) ret += str[i] - '0';

        return ret;
    }

    int getIndex(char key[]) {
        return (A * split(key) + B) % HASH_MAX; // Hash function => H(x) = (A * x +B) mod HASH_MAX
    }

public:

    bool add(char key[], int value) {
        int index = getIndex(key); // Bucket index

        if (!hashTable[index]) {
            hashTable[index] = value;
            return true;
        }

        else {
           return false;
        }
    }

    int getValue(char key[]) {
        int index = getIndex(key);

        return hashTable[index];
    }

};

```

```cpp
#include "HashTable.cpp"
#include <iostream>

using namespace std;

int main() {
    // Hash Table
    HashTable hashTable = HashTable();

    char key[7] = {'B', 'L', 'o', 'w', 'e', 's', 't'};
    int value = 155;

    cout << "Add key and value to hash table\n\n";
    cout << "Key:" <<(string)key << '\n' << "Value: " << value << '\n\n';
    if (hashTable.add(key, value)) cout << "Success" << "\n\n";
    else cout << "Fail" << "\n\n";

    cout << "Key:" <<(string)key << '\n' << "Value: " << value << '\n';
    if (hashTable.add(key, value)) cout << "Success" << "\n\n";
    else cout << "Fail" << "\n\n";

    cout << "Get value by key\n\n";
    cout << "Key:" <<(string)key << '\n';
    cout << hashTable.getValue(key) << '\n';
}
```

```
> Add key and value to hash table
>
> Key:BLowest
> Value: 1552570Success
>
> Key:BLowest
> Value: 155
> Fail
>
> Get value by key
>
> Key:BLowest
> 155
```

## 📖 Problems
1. 해시 충돌(Hash Collision): 해싱된 키(Hash Key)가 중복되어 해당 버킷(Bucket)에 이미 레코드가 존재하는 현상을 말함
2. 오버플로우(Overflow): 해시 충돌(Hash Collision)이 버킷(Bucket)에 할당된 슬롯(Slot) 수보다 많이 발생하면 더 이상 버킷에 값을 넣을 수 없는 현상
3. 클러스터링(Clustering): 연속된 레코드(Bucket)에 데이터가 몰리는 현상)

## 📖 Resolve Collision
만약 위의 그림에서 **John Smith를 해시 함수를 돌려 나온 값과 Lisa Smith를 해시함수를 돌려나온 값이 동일(Collsion or Confilct)** 하다면?

### 🛠 분리 연결법(Separate Chaining)
![seperate_chaining](../../image/seperate_chaning.png)

* 한 버킷당 들어갈 수 있는 엔트리 수의 제한을 두지 않음으로써 모든 자료를 해시 테이블에 담는 것
* 해당 버킷에 데이터기 이미 있다면 **노드를 추가하여 다음 노드를 가리키는 방식(Linked List)**
* 위 그림 처럼 Linked List로 저장해 둘 경우 최근 데이터는 연결리스트의 head에 추가([이 경우  𝑂(1), tail에 저장할 경우  𝑂(𝑛)이 됨](https://ratsgo.github.io/data%20structure&algorithm/2017/09/30/list/))
* 데이터의 주소값(Index)이 바뀌지 않음
* **부하율(Load Factor, 전체 버킷에서 사용중인 버킷의 비율)**이 100%에 가까울 수록 삽입, 삭제, 검색의 효율이 비약적으로 낮아짐(일반적으로 80%로 제한)
* 구현하기 간단하고 기본적이 자료구조로 이루어져 있음
* 테이블의 높은 부하율(Load Factor)이 예상되거나, 데이터가 크거나, 데이터의 길이가 가변일때 성능이 좋아짐
* JDK 1.8(Java 8)에서는 슬롯의 갯수가 8개 이하일 경우 연결리스트(Linked List)를 사용하며 그 이상의 경우는 트리(Tree)구조를 사용하여 검색의 효율을 높임

### 🛠 개방 주소법(Open Addressing)
* 충돌이 발생했을 경우 Linked List와 같은 추가적인 메모리를 사용하지 않고 **hash table의 빈 bucket을 이용하는 방법**
* 충돌이 발생하면 다른 버킷(Bucket)에 저장하기 때문에 데이터의 주소값(Index)이 바뀜
* 삽입시 메모리 할당 오버헤드([Overhead](https://se-sik.tistory.com/21)) 가 없으며, 메모리 할당자가 없이도 구현 가능
* 선형 검색법(Linear Probing)에서 Separate Chaining보다 뛰어난 [참조 지역성](https://anyflow.net/311#:~:text=%EB%8F%99%EC%9D%BC%ED%95%9C%20%EA%B0%92%20%EB%98%90%EB%8A%94%20%ED%95%B4%EB%8B%B9%20%EA%B0%92,%2C%20%EC%88%9C%EC%B0%A8(sequential)%20%EC%A7%80%EC%97%AD%EC%84%B1.)(Locality of reference, 하나의 자원에 여러번 접근하는 프로세스)을 가짐
* 포인터(Pointer)를 사용하지 않음으로써 [직렬화](https://weicomes.tistory.com/63)(Serialization)가 용이
* 테이블에 모두 저장될 수 있고, 캐시라인에 적합할 수 있을 정도로 **데이터의 크기가 작을수록 성능이 좋음**
* 삭제할 경우 충돌(Collision)에 의해 뒤에 저장된 데이터가 검색되지 않을 수 있어 이를 방지하기 위해 삭제한 위치에 **Dummy Node를 삽입**함
* 개방 주소법에는 4가지 방법이 있음
	1. 선형 검색(탐사)법 (Linear Probing) -> 충돌 발생시 새로운 *키(Key)*를 저장할 기억공간을 찾기 위해 충돌이 일어난 그 위치에서 선형적으로 검색하여 첫 번째 빈 영역에 저장하는 방법
![linear_probing](../../image/linear_probing.png)
	2. 2차 검색(탐사)법 (Quadratic probing) -> 원래 저장할 위치로 부터 1, 4, 9, 16 ... 과 같이 떨어진 영역을 차례대로 검색하여 첫번째 빈영역에 키를 저장하는 방법
![quadratic_probing](../../image/quadratic_probing.png)
	3. 이중 해싱(Double Hashing) -> 하나의 해시 함수(Hash function)에서 충돌이 발생하면 2차 해시 함수를 이용해 검색 이동거리를 얻는 방법
![double_hashing](../../image/double_hashing.png)
	4. 무작위 검색법 -> 충돌을 유발하는 키(Key)를 저장할 수 있는 가용 공간을 찾을 때까지 난수 계산 프로그램을 실행하여 해시 테이블(Hash Table)의 주소 값(Index)를 결정하는 방법
	
## ⚓️ Resizing
* 해시 버킷의 개수가 적다면 메모리 사용을 아낄 수 있지만 **해시 충돌로 인해 성능상 손실이 발생**
* Hash Table은 Key-Value 쌍 데이터 개수가 **일정 개수 이상**이되면 버킷의 개수를 두배로 늘림
* 이렇게 늘리면 해시 충돌로 인한 성능 손실 문제를 어느정도 해결 가능
* 해시 버킷 크기를 두 배로 확장하는 임계점은 전체 데이터 개수가 해시 버킷 개수의 **75%**(0.75 -> Load Factor)가 될때임

## ⚙️ Reference
1. https://steemit.com/kr/@yahweh87/2
2. [자료구조 해시테이블(HashTable)이란? - MangKyu's Diary](https://mangkyu.tistory.com/102)
3. [자료구조 Hash Table (해시 테이블) 이란?](https://k39335.tistory.com/18)
4. [해시 테이블(Hash Table)](https://dev-kani.tistory.com/1)
5. [캐싱(caching)이란 :: Net-Gate](https://net-gate.tistory.com/11)
6. https://www.crocus.co.kr/1147

#blowest/seminar
