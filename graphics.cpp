#ifndef included
#define included
#include "graphics.h"
#endif

void reshape(int w, int h) {  // служебная функция
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display() {  // функция отрисовки
    glClear(GL_COLOR_BUFFER_BIT);
    Expression* suma = new Sin(new Variable('x'));
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(0, HT / 2);
    glVertex2i(WD, HT / 2);
    glVertex2i(WD / 2, 0);
    glVertex2i(WD / 2, HT);
    glVertex2i(WD / 2 + t_c, HT / 2 + 5);
    glVertex2i(WD / 2 + t_c, HT / 2 - 5);
    glVertex2i(WD / 2 + 5, HT / 2 + t_c);
    glVertex2i(WD / 2 - 5, HT / 2 + t_c);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0, 1.0, 0);
    int x, y;
    Expression* e = suma;
    e->print();
    for (int x1 = WD * (-1) / 2; x1 < WD / 2; x1 += 10) {
        x = x1 + WD / 2;
        y = HT / 2 + t_c * e->graf(x1);
        glVertex2i(x, y);
    }
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(
        GLUT_DOUBLE |
        GLUT_RGB); /*Включаем двойную буферизацию и четырехкомпонентный цвет*/

    glutInitWindowSize(WD, HT);
    glutCreateWindow("OpenGL Graphick Function");

    glutReshapeFunc(reshape);
    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
