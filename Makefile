.PHONY:all
all:1st
	@echo "build all"

1st:clean
	g++ -o 1st.exe 1stweekworks.cc -DW1_4 -lstdc++
	
tst:clean
	g++ -o tst.exe test.cc -lstdc++
	
clean:
	rm -f *.exe