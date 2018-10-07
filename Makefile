.PHONY:w1
w1:1st
	@echo "build week1"

.PHONY:w2
w2:2nd
	@echo "build week2"
	
1st:clean
	g++ -o 1st.exe 1stweekworks.cc -DW1_4 -lstdc++

2nd:clean
	g++ -o 2nd.exe 2ndweekworks.cc -DW2_4 -lstdc++
	
3rd:clean
	g++ -o 3rd.exe 3rdweekworks.cc -DW3_4 -lstdc++
	
4th:clean
	g++ -o 4th.exe 4thweekworks.cc -DW4_5 -lstdc++
	
test:clean
	g++ -o test.exe test.cc -lstdc++
	
clean:
	rm -f *.exe