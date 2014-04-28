all:Sample2

CC=gcc
FLAG= -g -Wall -O0

Sample2:Sample2.o Sample2.class
	${CC} -o $@ $< /usr/lib/jvm/java-7-openjdk-amd64/jre/lib/amd64/jamvm/libjvm.so

Sample2.o:Sample2.c
	${CC} -I/usr/lib/jvm/java-7-openjdk-amd64/include -c $<

Sample2.class:Sample2.java
	javac $<

.PHONY:
clean:
	rm -f *.class *.o *.so Sample2 sayHello
