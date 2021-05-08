# Blocking vs Non-blocking / Synchronous vs Asynchronous

### Blocking vs Non-bloking
<br/>
<br/>

#### Blocking
* 요청한 작업을 마칠 때까지 계속 대기하며 제어권을 넘겨주지 않음
* return 값을 받아야 끝

#### Non-blocking
* 직접 제어할 수 없는 대상의 작업 처리여부에 상관 없음
* Thread 관점에서, 하나의 Thread가 여러 개의 IO처리가 가능

<br/>
<br/>

### Synchronous vs Asynchronous
<br/>
<br/>

#### Synchronous
* 작업 요청을 했을 때 요청의 결과값을 직접 받음
* 요청의 결과값이 return값과 동일
* 호출한 함수가 직접 완료를 신경씀
<p align="center"><img src=images/동기.png><p>
#### Asynchronous
* 작업 요청을 했을 때 요청의 결과값을 간접적으로 받음
* 요청의 결과값이 return값과 다를 수 있음
* 호출된 함수가 callback 함수를 통해 작업 완료를 신경씀
<p align="center"><img src=images/비동기.png><p>
<br/>
<br/>

### 두 개념의 차이는?
* Blocking/Non-blocking 에서는 호출된 함수가 바로 return 하느냐 마느냐 관점
* Synchronous/Asynchronous 에서는 호출된 함수의 작업 완료를 누가 신경쓰느냐 관점
<br/>
<br/>

### Blocking vs Non-blocking / Synchronous vs Asynchronous 조합
<br/>
<br/>
<p align="center"><img src=images/조합.png><p>
<br/>
<br/>
____

#### **Blocking + Synchronous**
결과가 처리되어 나올때까지 기다렸다가 return 값으로 결과 전달
#### **Non-blocking + Asynchronous**
작업 요청을 받아서 별도의 프로세서에서 진행하게 하고 바로 return함. <br/>
결과는 별도의 작업 후 간접적으로 callback

<p align="center"><img src=images/조합1.png><p>

____ 

#### **Non-blocking + Synchronous**
결과가 없다면 바로 return  
결과가 있으면 바로 결과를 return(계속 완료를 확인)

<p align="center"><img src=images/조합2.png><p>

___

#### **Blocking + Asynchronous**
호출되는 함수가 바로 return하지 않고, 호출하는 함수는 작업 완료 여부를 신경쓰지 않음  

<p align="center"><img src=images/조합3.png><p>






___
## Reference

* https://velog.io/@wonhee010/%EB%8F%99%EA%B8%B0vs%EB%B9%84%EB%8F%99%EA%B8%B0-feat.-blocking-vs-non-blocking
* https://velog.io/@codemcd/Sync-VS-Async-Blocking-VS-Non-Blocking-sak6d01fhx
