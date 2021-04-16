# Transaction

## Transaction이란?

```
Transaction이란 데이터베이스의 상태를 변환시키는 하나의 논리적 기능을 수행하기 위한 작업의 단위 또는 한꺼번에 모두 수행되어야 할 일련의 연산들을 의미
```

## Transaction의 특징

 - Transaction은 데이터베이스 시스템에서 병행 제어 및 회복 작업 시 처리되는 작업의 논리적 단위이다.
 - 사용자가 시스템에 대한 서비스 요구 시 시스템이 응답하기 위한 상태 변환 과정의 작업단위이다.
 - 하나의 transaction은 commit되거나 rollback된다.

## Transaction의 성질

 - Atomicity(원자성)
    - Transaction의 연산은 데이터베이스에 모두 반영되든지 아니면 전혀 반영되지 않아야 한다.
    - Transaction 내의 모든 명령은 반드시 완벽히 수행되어야 하며, 모두가 완벽히 수행되지 않고 어느 하나라도 오류가 발생하면 transaction 전부가 취소되어야 한다.
 - Consistency(일관성)
    - Transaction이 그 실행을 성공적으로 완료하면 언제나 일관성 있는 데이터베이스 상태로 변환한다.
    - 시스템이 가지고 있는 고정요소는 transaction 수행 전과 transaction 수행 완료 후의 상태가 같아야 한다.
 - Isolation(독립성, 격리성)
    - 둘 이상의 transaction이 동시에 병행 실행되는 경우 어느 하나의 transaction 실행중에 다른 transaction의 연산이 끼어들 수 없다.
    - 수행중인 transaction은 완전히 완료될 때까지 다른 transaction에서 수행 결과를 참조할 수 없다.
 - Durablility(영속성, 지속성)
    - 성공적으로 완료된 transaction의 결과는 시스템이 고장나더라도 영구적으로 반영되어야 한다.

## Transaction의 상태

![transaction status](../../image/transaction-status.png)

 - Active(활동) : transaction이 실행중인 상태
 - Failed(실패) : transaction 실행에 오류가 발생하여 중단된 상태
 - Aborted(철회) : transaction이 비정상적으로 종료되어 rollback연산을 수행한 상태
 - Partially Committed(부분 완료) : transaction의 마지막 연산까지 실행했지만, commit 연산이 실행되기 직전의 상태
 - Committed(완료) : transaction이 성공적으로 종료되어 commit 연산을 실행한 후의 상태