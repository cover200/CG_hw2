#include <glut.h>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include <iostream>

#define PI 3.14159265358979323846
float rad = rad;

int x[25], y[25], size[25];
int r[28], g[28], b[28];
int count = 0;
int dx = 0, dy = 0;

float xplane;
float xcar[2];
float speed[3];
float window[2];

void init(void)
{
	glClearColor(0.2, 0.2, 0.3, 1.0);
	gluOrtho2D(-400, 400.0, -250.0, 250.0);
}
void setColor(float r, float g, float b) {
	glColor3f(r / 255, g / 255, b / 255);
}
void mountain(int x, int y) {
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 180; i += 1) {
		glVertex2f(90 * cos(i*rad) - x, 180 * sin(i*rad) - y);
	}
	glEnd();
}
void background() {
	glBegin(GL_POLYGON);		//ท้องฟ้า
	setColor(54, 232, 202);
	glVertex2f(-400, 250);
	glVertex2f(400, 250);
	setColor(54, 90, 232);
	glVertex2f(400, -20);
	glVertex2f(-400, -20);
	glEnd();

	setColor(15, 70, 0);
	mountain(170, 55);
	setColor(0, 51, 0);
	mountain(300, 30);

	glBegin(GL_POLYGON);		//หญ้า
	setColor(30, 225, 66);
	glVertex2f(-400, -20);
	glVertex2f(400, -20);
	setColor(12, 95, 29);
	glVertex2f(400, -140);
	glVertex2f(-400, -140);
	glEnd();
}
void house() {
	glBegin(GL_POLYGON);		//ผนัง
	setColor(255, 255, 121);
	glVertex2f(400, -120);
	glVertex2f(400, 10);
	setColor(255, 255, 153);
	glVertex2f(250, 10);
	glVertex2f(250, -120);
	glEnd();
	setColor(77, 38, 0);		//ประตู
	glBegin(GL_POLYGON);
	glVertex2f(270, -120);
	glVertex2f(270, -30);
	glVertex2f(320, -30);
	glVertex2f(320, -120);
	glEnd();
	setColor(102, 51, 0);
	for (int i = 0; i < 2; i++) {
		glBegin(GL_POLYGON);
		glVertex2f(280, -40 - i * 40);
		glVertex2f(310, -40 - i * 40);
		glVertex2f(310, -70 - i * 40);
		glVertex2f(280, -70 - i * 40);
		glEnd();
	}

	glBegin(GL_POLYGON);	//หลังคา
	setColor(255, 148, 77);
	glVertex2f(235, 10);
	glVertex2f(350, 105);
	setColor(255, 102, 0);
	glVertex2f(400, 63);
	setColor(230, 92, 0);
	glVertex2f(400, 10);
	glEnd();
}
void fence() {
	setColor(41, 39, 36);
	glBegin(GL_POLYGON);
	glVertex2f(-400, -170);
	glVertex2f(300, -170);
	glVertex2f(300, -100);
	glVertex2f(-400, -100);
	glEnd();

	setColor(111, 108, 103);
	for (int i = -90; i < -50; i += 15) {
		glBegin(GL_POLYGON);
		glVertex2f(-400, i);
		glVertex2f(300, i);
		glVertex2f(300, i + 3);
		glVertex2f(-400, i + 3);
		glEnd();
	}

	setColor(64, 61, 55);
	for (int i = 300; i >= -400; i -= 116) {
		glBegin(GL_POLYGON);
		glVertex2f(i, -100);
		glVertex2f(i, -50);
		glVertex2f(i - 20, -50);
		glVertex2f(i - 20, -100);
		glEnd();
	}

}
void leaf(int r, int i, int x, int y) {
	r = 2.67*r * cos(2 * i*rad);
	glVertex2f(r*cos(i*rad) + x, r*sin(i*rad) + y);

}
void circle(int r, int i, float x, int y) {
	glVertex2f(r*cos(i*rad) + x, r*sin(i*rad) + y);
}
void circle(int r1, int r2, int i, float x, int y) {
	glVertex2f(r1*cos(i*rad) + x, r2*sin(i*rad) + y);
}
void flower(int r, int x, int y) {
	if (count++ > 1500) {
		dx = rand() % 3 - 1;
		dy = rand() % 3 - 1;
		count = 0;
	}

	glBegin(GL_POLYGON);			//กลีบดอก
	for (int i = 0; i <= 46; i++)
		leaf(r, i, x + dx*5, y + dy*5);
	glEnd();
	glBegin(GL_POLYGON);
	for (int i = 0; i >= -46; i--)
		leaf(r, i, x + dx*5, y + dy*5);
	glEnd();

	glBegin(GL_POLYGON);
	for (int i = 45; i <= 91; i++)
		leaf(r, i, x + dx*5, y + dy*5);
	glEnd();
	glBegin(GL_POLYGON);
	for (int i = -45; i >= -91; i--)
		leaf(r, i, x + dx*5, y + dy*5);
	glEnd();

	glBegin(GL_POLYGON);
	for (int i = 90; i <= 136; i++)
		leaf(r, i, x + dx*5, y + dy*5);
	glEnd();
	glBegin(GL_POLYGON);
	for (int i = -90; i >= -136; i--)
		leaf(r, i, x + dx*5, y + dy*5);
	glEnd();
	
	glBegin(GL_POLYGON);
	for (int i = 135; i <= 181; i++)
		leaf(r, i, x + dx*5, y + dy*5);
	glEnd();
	glBegin(GL_POLYGON);
	for (int i = -135; i >= -181; i--)
		leaf(r, i, x + dx*5, y + dy*5);
	glEnd();

	setColor(255, 255, 0);				//กลางดอก
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 360; i += 5)
		circle(r, i, x + dx * 5, y + dy * 5);
	glEnd();
}
void car(float x, int y, int r, int g, int b, int window) {
	float xW = 30 * cos(window*rad) + x;
	float yW = 30 * sin(window*rad) + y;

	setColor(r, g, b);
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 360; i += 5)
		circle(80, i, x, y);
	glEnd();

	setColor(0, 0, 0);		//หน้าต่าง
	glLineWidth(3);
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 360; i += 5)
		circle(33, i, xW, yW);
	glEnd();
	setColor(128, 255, 229);
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 360; i += 5)
		circle(30, i, xW, yW);
	glEnd();

	setColor(0, 0, 0);
	for (int j = 0; j < 2; j++) {
		glBegin(GL_POLYGON);
		for (int i = 0; i <= 360; i += 5)
			circle(35, i, x-45 + j*90, y-65);
		glEnd();
	}

}
void plane() {

}
void draw() {
	background();
	for (int i = 0; i < 25; i++) {
		setColor(r[i], g[i], b[i]);
		flower(size[i], x[i], y[i]);
	}	//ดอกไม้
	house();
	fence();
	car(xcar[0], -120, r[25], g[25], b[25], window[0]);
	car(xcar[1], -150, r[26], g[26], b[26], window[1]);
	plane();
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	draw();
	glFlush();
	glutSwapBuffers();
}
void play(void) {
	for (int i = 0; i < 2; i++) {
		xcar[i] -= speed[i];
		window[i] += speed[i] * 2;
	}
	xplane -= speed[2];

	if (xcar[0] + 80 < -400) {
		xcar[0] = rand()%100+500;
		speed[0] = (rand() % 100 + 100) / 100.0;
		r[25] = rand() % 155 + 100;
		g[25] = rand() % 155 + 100;
		b[25] = rand() % 155 + 100;
	}
	if (xcar[1] + 125 < -400) {
		xcar[1] = rand() % 100 + 500;
		speed[1] = (rand() % 100 + 100) / 100.0;
		r[26] = rand() % 155 + 100;
		g[26] = rand() % 155 + 100;
		b[26] = rand() % 155 + 100;
	}
	if(xplane <)

	if (window[0] > 1080) window[0] = 0;
	if (window[1] > 1080) window[1] = 0;

	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(play);
		break;
	default:
		break;
	}
}


int main(int argc, char** argv)
{
	srand(time(NULL));
	for (int i = 0; i < 25; i++) {		//random ดอกไม้
		x[i] = rand() % 670 - 400;
		y[i] = rand() % 70 - 100;
		r[i] = rand() % 155 + 100;
		g[i] = rand() % 155 + 100;
		b[i] = rand() % 155 + 100;
		size[i] = rand() % 5 + 6;
	}
	for (int i = 0; i < 2; i++) {		//random รถ
		r[25+i] = rand() % 155 + 100;
		g[25+i] = rand() % 155 + 100;
		b[25+i] = rand() % 155 + 100;
		xcar[i] = rand() % 100 + 500;
		window[i] = rand() % 360;
		speed[i] = (rand() % 100 + 100) / 100.0;
	}

	r[27] = rand() % 105 + 150;
	g[27] = rand() % 155 + 100;
	b[27] = rand() % 100 + 50;
	xplane = rand() % 100 + 500;
	speed[2] = (rand() % 100 + 100) / 100.0;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(800, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Homework1");
	glutDisplayFunc(display);
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}