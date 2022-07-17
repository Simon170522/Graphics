all:
	g++ graphics.cpp -o graphics -lGL -lGLU -lglut
clean:
	rm -rf *.o graphics