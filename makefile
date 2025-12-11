testListArray: testListArray.cpp ListArray.h List.h
	g++ -o testListArray testListArray.cpp

testListLinked: testListLinked.cpp ListLinked.h Node.h List.h
	g++ -o testListLinked testListLinked.cpp

clean:
	rm -f testListArray testListLinked *.o *.gch

