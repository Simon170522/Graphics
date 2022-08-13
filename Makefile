all:
	g++ expression_classes.cpp graphics.cpp -o graphics -lGL -lGLU -lglut
clean:
	rm -rf *.o graphics