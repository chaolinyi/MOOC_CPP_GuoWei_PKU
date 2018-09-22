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
	
tst:clean
	g++ -o tst.exe test.cc -lstdc++
	
clean:
	rm -f *.exe