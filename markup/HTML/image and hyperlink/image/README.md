# 이미지

|파일형식|설명|
|---|:---|
|GIF(Graphic InterchangeForm)|표시할 수 있는 색상 수가 최대 256가지뿐이지만 다른 이미지 파일 형식에 비해 파일 크기가 작기 때문에 아이콘이나 불릿 등 작은 이미지에 주로 사용합니다. 투명한 배경이나 움직이는 이미지를 만들 수 있다는 장점이 있습니다.|
|JPG/JPEG(Joint Photographic Experts Group)|사진을 위해 개발된 형식으로 GIF보다 다양한 색상과 명암을 표현할 수 있습니다. 저장을 반복하다 보면 화질이 떨어질 수도 있습니다.|
|PNG(Portable Network Graphics)|투명 배경을 만들면서 다양한 색상도 표현할 수 있으며 네트워크용으로 개발되었기 때문에 최근 많이 사용합니다.|

---

## **&#60;img&#62;**

이미지를 삽입하는 태그  
`src` 속성을 채워넣어 이미지를 설정할 수 있습니다.  

```HTML
<img src="경로" [속성="값"]>
```

|속성|내용|
|---|:---|
|src|이미지가 위치한 경로|
|alt|화면낭독기에서 화면을 낭독해주는 속성. 화면을 불러오다 인터넷환경문제로 인한 로딩실패 시에 이미지옆에 뜨는 텍스트이기도 함.|
|width|사진의 너비를 설정|
|height|사진의 높이를 설정|

---

## **&#60;figure&#62;, &#60;figcaption&#62;**

이미지에 설명 글을 붙이는 태그  
&#60;figure&#62;는 멀티미디어 파일을 비롯해 사진이나 표 소스 코드 등 웹 문서 안에서 한 단위가 되는 요소를 묶는 태그이다.  
&#60;figcaption&#62;은 &#60;figure&#62;태그 내의 미디어 설명글을 넣기위한 태그이다.  

```HTML
<figure> 요소 </figure>
<figcaption> 설명 글 </figcaption>
```