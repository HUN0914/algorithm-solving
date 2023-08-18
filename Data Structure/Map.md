### Map 이란?



key와 value 값으로 이루어진 자료구조 
(set과 비슷하지만, set은 key값이 없다.)

Map 같은 경우에는 key값이 중복될 수 없다.




---------------------


# Map 선언하기 ( C++ )

map의 기본 구조는 map<key type, value type> 변수명(이름) 

------------------------

# Map 명령어

[특정 위치의 요소 삭제]

ex)
m.erase(m.begin()+2);

[key값 기준으로 요소 삭제]

ex)
m.erase("Alice"); <-key값이 string으로 선언되었을 경우, 이와 같이 m.erase에 *key* 값을 넣으면 그 key값이 삭제가 가능하다.


[map 찾기]

iterator을 굳이 사용할 필요는 없다.

	if (mapset.find("Alice") != mapset.end()) 
	{
		cout << "find" << endl;
	}
	else {
		cout << "not find" << endl;
	}

[map 삽입]

m.insert({"Alice", 100});

key값, value 값 순으로 입력 (대괄호)
