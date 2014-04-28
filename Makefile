all:Sample2.o
	gcc -o Sample2 $^ /usr/lib/jvm/java-7-openjdk-amd64/jre/lib/amd64/jamvm/libjvm.so -g
Sample2:Sample2.c
	gcc -c $^ -I/usr/lib/jvm/java-7-openjdk-amd64/include HelloWorld.c -g

clean:
	rm -f *.class *.o Sample2 sayHello *.so
