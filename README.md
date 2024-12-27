# 입출력 시간 단축
```
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
```

## 자료구조, STL , 다시 볼만한 함수 사용법
  1. 정렬에 사용되는 <stronger>비교함수.</stronger>
  
  - sort(a,a+n,cmp) 이런 식으로 사용된다.
  - cmp 함수를 보면 <strong>bool cmp(int a,int b)</strong>  ==> <strong>a가 b 앞에 와야하면 True, 아니면 False</strong>
  - 비교함수는 우선순위 큐와 정렬에서 특정 비교가 있을 때 많이 사용된다.

  
## 커밋 규칙

[난이도] Title , 시간/공간 복잡도 (알고리즘 종류)

느낀점
