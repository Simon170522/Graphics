#include <iostream>
#include <cmath>
#if defined(linux) || defined(_WIN32)
#include <GL/glut.h>
#else
#include <GLUT/GLUT.h>
#endif
#define WD 800
#define HT 600
using namespace std;

void reshape(int w, int h);
void display();