import csv

f = open("buksam.csv", 'r')
rd = csv.reader(f)
#List를 딕셔너리로 선언
List = {}
for line in rd :
    try : #주류 값을 int형으로 변환했을 때, 오류가 날경우
        주류 = int(line[11])
    except: #해당 상황 제외
        continue
    try : #딕셔너리 값이 존재한다면 +1
        List[주류] = List[주류]+1
    except : #위에서 딕셔러니 값이 없는 상황이라면 해당 값을 1로 만듦
        List[주류] = 1
#딕셔러니 key값들에 따라서 sorting(list형태로 변환됨)
List = sorted(List.items())
#List에는 (key, value) 형태로 리스트로 되어있으니, 각각 List에서 뽑아서 출력
for key,value in List:
    print(key, ':', value)
f.close()