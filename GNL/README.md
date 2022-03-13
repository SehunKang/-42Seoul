# GNL - Get Next Line
```c
int get_next_line(int fd, char **line)
```
위 함수를 만드는 프로젝트이다.  
파일디스크립터로부터 한 줄을 읽고 반환하는 함수이다.
매개변수 : fd = file descripter의 값, line = 문자열을 담는 변수  
리턴값 : 1 = 한 라인을 읽음, 0 = EOF를 만남(끝까지 읽음), -1 = 에러  
사용 가능한 외부함수 : read, malloc, free  

## 프로젝트의 목적
read, open함수를 을 활용한 파일 디스크립터에 대한 이해, static 변수에 대한 이해, eof를 통한 문자열 처리에 대한 이해를 요구하는 프로젝트인것 같다.

비고 : 디버깅 용 printf가 있는 걸 보니 제출 파일은 아닌것 같다.
