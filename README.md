# Backjoon_algorithm
백준 알고리즘 연습
## 자료구조, STL
<ol> 
  1. 정렬에 사용되는 <stronger>비교함수.</stronger>
  
  - sort(a,a+n,cmp) 이런 식으로 사용된다.
  - cmp 함수를 보면 <strong>bool cmp(int a,int b)</strong>  ==> <strong>a가 b 앞에 와야하면 True, 아니면 False</strong>
  - 비교함수는 우선순위 큐와 정렬에서 특정 비교가 있을 때 많이 사용된다.
</ol>


## 알고리즘
<ol>
  1. <strong>Dynamic Programming</strong>

  - 해결법
  <ol>
    1. 함수 이름 정의하기
    2. <strong>점화식 찾기<strong> , 초깃값 설정
    3. 메모이제이션
  </ol>
  - <strong>이미 계산한 값을 배열, 변수에 저장하고 다음에 계산해야 할 때 값을 찾아 쓴다.</strong>
</ol>
