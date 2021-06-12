# 폼 만들기

## **&#60;form&#62;**

폼을 만들 때 쓰는 기본 태그  
서버에 넘겨줄 데이터들의 묶음을 폼 이라고 한다.  

```HTML
<form [속성="속성 값"]> 여러 폼 요소 </form>
```

|파일형식|설명|
|---|:---|
|method|사용자가 입력한 내용들을 서버 쪽 프로그램으로 어떻게 넘겨줄지 지정합니다.(get, post, etc...)|
|name|폼의 이름을 지정합니다. 한 문서 안에 여러 개의 &#60;form&#62; 태그가 있을 경우, 폼들을 구분하기 위해 사용합니다.|
|action|&#60;form&#62; 태그 안의 내용들을 처리해 줄 서버 상의 프로그램을 지정합니다.|
|target|&#60;action&#62; 태그에서 지정한 스크립트 파일을 현재 창이 아닌 다른 위치에 열도록 지정합니다.|
|autocomplete|자동완성기능. default는 "on"이다.|

---

## **&#60;label&#62;**

폼 요소에 레이블을 붙이기 위한 태그  

```HTML
<label [속성="속성 값"]> 레이블 <input ... > </label>
```
```HTML
<label for="id이름">
    <input id="id이름" [속성="속성 값"]>
</label>
```

### 라디오 버튼과 체크박스에서의 &#60;label&#62;사용

라디오 버튼이나 체크박스의 경우 &#60;label&#62; 태그를 사용하면 체크박스를 클릭할 필요없이 텍스트를 클릭해도 선택이 된다.  

```HTML
<ul>
    <li>
        <label><input type="radio" name="이름1", value="값1">선택1</label>
    </li>
    <li>
        <label><input type="radio" name="이름2", value="값2">선택2</label>
    </li>
    <li>
        <label><input type="radio" name="이름3", value="값3">선택3</label>
    </li>
```

---

## **&#60;fieldset&#62;, &#60;legend&#62;**

하나의 폼 안에서 여러 구역을 나누어 표시할 때 쓰는 태그  
&#60;legend&#62; 태그는 &#60;fieldset&#62; 태그 내에서 사용되며 fieldset의 제목을 표시하는 태그이다.  

```HTML
<fieldset [속성="속성 값"]> ... </fieldset>
```