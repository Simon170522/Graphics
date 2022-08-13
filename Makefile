all:
	g++ -c expression_classes.cpp
	g++ -c graphics.cpp
	g++ expression_classes.o graphics.o -o graphics -lGL -lGLU -lglut
test:
	g++ -c expression_classes.cpp
	g++ -c tests.cpp
	g++ expression_classes.o tests.o -o test -lgtest -lpthread
clean:
	rm -rf *.o graphics test 