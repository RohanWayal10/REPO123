#include <GL/glut.h>
#include <iostream>
#include <cmath>

using namespace std;

int X1, Y1, X2, Y2;

int sign(int v)
{
if (v < 0) return -1;
if (v == 0) return 0;
return 1;
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0, 1.0, 1.0);

int dx = abs(X2 - X1);
int dy = abs(Y2 - Y1);
int x = X1;
int y = Y1;

int s1 = sign(X2 - X1);
int s2 = sign(Y2 - Y1);

int interchange = 0;
if (dy > dx)
{
int temp = dx;
dx = dy;
dy = temp;
interchange = 1;
}

int e = 2 * dy - dx;

glBegin(GL_POINTS);
for (int i = 0; i <= dx; i++)
{
glVertex2i(x, y);

while (e >= 0)
{
if (interchange)
x += s1;
else
y += s2;

e -= 2 * dx;
}

if (interchange)
y += s2;
else
x += s1;

e += 2 * dy;
}
glEnd();

glFlush();
}

void init()
{
glClearColor(0.0, 0.0, 0.0, 1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-100, 100, -100, 100);
}

int main(int argc, char** argv)
{
cout << "Enter x1 y1: ";
cin >> X1 >> Y1;
cout << "Enter x2 y2: ";
cin >> X2 >> Y2;

glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(200, 200);
glutInitWindowPosition(100, 100);
glutCreateWindow("Bresenham Line Drawing Algorithm");

init();
glutDisplayFunc(display);
glutMainLoop();

return 0;
}
