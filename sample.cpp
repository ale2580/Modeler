// The sample model.  You should build a file
// very similar to this for when you make your model.
#include "modelerview.h"
#include "modelerapp.h"
#include "modelerdraw.h"
#include <FL/gl.h>
#include <math.h>
#include "modelerglobals.h"
#include <cstdio>
#include <iostream>
using namespace std;


double d = 0;
float dx = 0.1;


//typedef point Vector;
/*
void Normalize(point& V)
{
	GLdouble tmp = sqrt(V.x * V.x + V.y * V.y + V.z * V.z);
	V.x = V.x / tmp;
	V.y = V.y / tmp;
	V.z = V.z / tmp;
}
*/

/*
void icosahedron() {
	GLdouble phi = (1 + sqrt(5)) / 2;

	GLdouble vertices[12][4] =	{ 

		{0, 1, phi}, {0, -1, phi}, {0, 1, -phi}, {0, -1, -phi},
		{1, phi,0}, {-1, phi, 0}, {1, -phi, 0}, {-1, -phi, 0},
		{phi, 0, 1}, {-phi, 0, 1}, {phi, 0, -1}, {-phi, 0, -1}

		};
	
	
	int triangulation[20][3] = {
   {0,4,1}, {0,9,4}, {9,5,4}, {4,5,8}, {4,8,1},
   {8,10,1}, {8,3,10}, {5,3,8}, {5,2,3}, {2,7,3},
   {7,10,3}, {7,6,10}, {7,11,6}, {11,0,6}, {0,1,6},
   {6,1,10}, {9,0,11}, {9,11,2}, {9,2,5}, {7,2,11} };
	
	

	glBegin(GL_TRIANGLES);

	for (int i = 0; i < 20; i++) {
		GLdouble a = vertices[triangulation[i][0]][0];
		GLdouble b = vertices[triangulation[i][0]][1];
		GLdouble c = vertices[triangulation[i][0]][2];

		GLdouble a1 = vertices[triangulation[i][1]][0];
		GLdouble b1 = vertices[triangulation[i][1]][1];
		GLdouble c1 = vertices[triangulation[i][1]][2];

		GLdouble a2 = vertices[triangulation[i][2]][0];
		GLdouble b2 = vertices[triangulation[i][2]][1];
		GLdouble c2 = vertices[triangulation[i][2]][2];

		glVertex3d(a,b,c);
		glVertex3d(a1,b1,c1);
		glVertex3d(a2,b2,c2);
	}
	

		

	glEnd();
	


}
*/


void drawTorus(GLdouble r1, GLdouble r2, GLdouble step) {
	int arrsize = ((2 * 3.1415) / step) * ((2 * 3.1415) / step)+1;
	GLdouble v = 0;
	GLdouble u = 0;
	GLdouble x = 0; 
	GLdouble y = 0; 
	GLdouble z = 0;
	/*
	GLdouble* xar= new GLdouble[arrsize];
	GLdouble* yar = new GLdouble[arrsize];
	GLdouble* zar = new GLdouble[arrsize];
	*/
	int count = 0;


	//glBegin(GL_TRIANGLES);
	glBegin(GL_QUAD_STRIP);
	
	for (v = 0; v < 2 * 3.1415; v = v + step) {
		for (u = 0; u < 2 * 3.1415; u = u + step) {
			
			cout << cos(90) << " and: " << cos(3.1415) << endl;
			x = (r1 + r2 * cos(v)) * cos(u);
			y = (r1 + r2 * cos(v)) * sin(u);
			z = r2*sin(v);

			GLdouble x2 = (r1 + r2 * cos(v)) * cos(u+step);
			GLdouble y2 = (r1 + r2 * cos(v)) * sin(u+step);
			GLdouble z2 = r2 * sin(v);

			GLdouble x3 = (r1 + r2 * cos(v+step)) * cos(u);
			GLdouble y3 = (r1 + r2 * cos(v+step)) * sin(u);
			GLdouble z3 = r2 * sin(v+step);

			GLdouble x4 = (r1 + r2 * cos(v + step)) * cos(u+step);
			GLdouble y4 = (r1 + r2 * cos(v + step)) * sin(u+step);
			GLdouble z4 = r2 * sin(v + step);

			

			GLdouble bx = (x3 - x);
			GLdouble by = (y3 - y);
			GLdouble bz = (z3 - z);

			GLdouble ax = (x2 - x);
			GLdouble ay = (y2 - y);
			GLdouble az = (z2 - z);
			
			GLdouble crossX = (ay * bz - az * by);
			GLdouble crossY = (az * bx - ax * bz);
			GLdouble crossZ= (ax* by - ay * bx);
			GLdouble norm = sqrt(crossX * crossX + crossY * crossY + crossZ * crossZ);
			crossX = crossX / norm;
			crossY = crossY / norm;
			crossZ = crossZ / norm;
			GLfloat r = cos(u);
			GLfloat g = 0.2+cos(u)+sin(v);
			GLfloat b = 0.8+cos(v);
			if (r < 0.2) { r = 0.2; }
			setAmbientColor(0.1, 0.8, 0.6);
			setSpecularColor(0, 0, 0);
			setDiffuseColor(r, g, b);
			glNormal3d(crossX, crossY, crossZ);
			glVertex3d(x, y, z);
			glVertex3d(x2, y2, z2);
			glVertex3d(x3, y3, z3);
			glVertex3d(x4, y4, z4);
			glPushMatrix();
			glTranslated(x3, y3, z3);
			//drawSphere(0.1);
			glPopMatrix();
			
			//glVertex3d(x, y, z);
			//count++;
		}
		cout << "test" << endl;
	}
	glEnd();
	//sphere
	/*
	glBegin(GL_TRIANGLES);
	for (GLdouble i = 0; i < 2 * 3.1415; i = i + step) {
		for (GLdouble j = 0; j < 3.1415; j = j + step) {
		x = cos(i) * sin(j);
		y = sin(i) * sin(j);
		z = cos(j);

		GLdouble x2 = cos(i + step) * sin(j);
		GLdouble y2 = sin(i + step) * sin(j);
		GLdouble z2 = cos(j);

		GLdouble x3= cos(i ) * sin(j-step);
		GLdouble y3 = sin(i ) * sin(j-step);
		GLdouble z3 = cos(j-step);

		glVertex3d(x, y, z);
		glVertex3d(x2, y2, z2);
		glVertex3d(x3, y3, z3);
		glPushMatrix();
		glTranslated(x, y, z);
		//drawSphere(0.2);
		glPopMatrix();
		}
	}
	glEnd();
	*/

	
	
		
		

	
}

void drawMobius(GLdouble r, GLdouble step) {

	GLdouble x = 0;
	GLdouble z= 0;
	GLdouble rot = VAL(57);
	for (GLdouble i = step; i < 2*3.1415; i = i + step) {
		
		x = r*sin(i);
		z = r*cos(i);

		glPushMatrix();
		
		glTranslated(x, 0, z);
		setDiffuseColor(0.2, 0.5 + sin(i), 0.9);
		glRotated((i * 180) / 3.1415, 0, 1, 0);
		glRotated(VAL(56) *i+rot, 1, 0, 0);
		glTranslated(0, -1, 0);
		drawBox(0.1, 2, 0.1);
		glPopMatrix();
		//rot += 360*0.1;
	}


}


void drawOctahedron() {
	glBegin(GL_TRIANGLES);           
	
	

	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);

	

	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	

	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);

	// Left

	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);




	glVertex3f(0.0f, -3.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);



	glVertex3f(0.0f,- 3.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);



	glVertex3f(0.0f, -3.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);

	// Left

	glVertex3f(0.0f, -3.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);

	glEnd();   



}

void drawMouthPiece(double r1,double r2, double r3) {
	setDiffuseColor(0.3, 0, 0.7);
	glPushMatrix();

	glTranslated(1, 2, 0);
	glRotated(r3, 0, 1, 0);
	glRotated(90, 1, 0, 0);
	glTranslated(-1.5, 0, 0);
	drawSphere(0.2);

	glRotated(r1, 0.0, 0.0, 1.0);
	//glTranslated(0, 0.0, 0.0);
	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glScaled(1.0, 1.0, 1.0);
	drawCylinder(0.8, 0.2, 0.2);
	//drawBox(1, 1, 1);
	glPopMatrix();

	glTranslated(0.8, 0.0, 0.0);
	drawSphere(0.2);
	glRotated(r2, 0.0, 0.0, 1.0);
	glTranslated(0, 0.0, 0.0);
	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glScaled(1.0, 1.0, 1.0);
	drawCylinder(1, 0.2, 0.01);
	glPopMatrix();
	/*
	glTranslated(5.0, 0.0, 0.0);
	drawSphere(0.2);
	glRotated(v6, 0.0, 0.0, 1.0);
	glTranslated(0, 0.0, 0.0);
	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glScaled(1.0, 1.0, 1.0);
	drawCylinder(5, 0.2, 0.01);
	glPopMatrix();
	*/
	glPopMatrix();


}
void drawLeg(double vrot, double v5, double v6, double v8) {
	
	//setSpecularColor(0.1,0.1, 0.1);
	//setAmbientColor(0.1, 0.1, 0.1);
	//setDiffuseColor(0, 0, 0);
	
	glPushMatrix();
	if (ModelerApplication::Instance()->GetControlValue(47) < 3) {
		glTranslated(1, 2, 0);
		glRotated(v8, 0, 1, 0);

		glTranslated(-1.5, 0, 0);
		setDiffuseColor(COLOR_RED);
		drawSphere(0.2);

		glRotated(vrot, 0.0, 0.0, 1.0);
		//glTranslated(0, 0.0, 0.0);
		glPushMatrix();
		glRotated(90, 0, 1, 0);
		glScaled(1.0, 1.0, 1.0);
		setDiffuseColor(0.3, 0, 0.7);
		drawCylinder(3, 0.2, 0.4);
		//drawBox(1, 1, 1);
		glPopMatrix();

	}

	if (ModelerApplication::Instance()->GetControlValue(47) < 2) {

		glTranslated(3.0, 0.0, 0.0);
		setDiffuseColor(COLOR_RED);
		drawSphere(0.4);
		glRotated(v5, 0.0, 0.0, 1.0);
		glTranslated(0, 0.0, 0.0);
		glPushMatrix();
		glRotated(90, 0, 1, 0);
		glScaled(1.0, 1.0, 1.0);
		setDiffuseColor(0.3, 0, 0.7);
		drawCylinder(5, 0.4, 0.2);
		glPopMatrix();

	}

	if (ModelerApplication::Instance()->GetControlValue(47) == 0) {
		glTranslated(5.0, 0.0, 0.0);
		setDiffuseColor(COLOR_RED);
		drawSphere(0.2);
		glRotated(v6, 0.0, 0.0, 1.0);
		glTranslated(0, 0.0, 0.0);
		glPushMatrix();
		glRotated(90, 0, 1, 0);
		glScaled(1.0, 1.0, 1.0);
		setDiffuseColor(0.3, 0, 0.7);
		drawCylinder(5, 0.2, 0.01);
		glPopMatrix();
	}
	glPopMatrix();
	

}

void dance(double x) {
	double Y = (x - 0) / (1 - 0) * (3 - 0) + 0;
	double Z = (x - 0) / (1 - 0) * (-2 - (2)) + 2;
	double root = (x - 0) / (1 - 0) * (135 - (180)) + 180;
	double mid = (x - 0) / (1 - 0) * (80 - (14)) + 14;
	double end = (x - 0) / (1 - 0) * (70 - (30)) + 30;

	double rootR = (x - 0) / (1 - 0) * (180 - (135)) + 135;
	double midR = (x - 0) / (1 - 0) * (14 - (80)) + 80;
	double endR = (x - 0) / (1 - 0) * (30 - (70)) + 70;






	ModelerApplication::Instance()->SetControlValue(ZPOS, Z);
	//left1
	ModelerApplication::Instance()->SetControlValue(21, root);
	ModelerApplication::Instance()->SetControlValue(22, mid);
	ModelerApplication::Instance()->SetControlValue(23, end);
	//left2
	ModelerApplication::Instance()->SetControlValue(25, root);
	ModelerApplication::Instance()->SetControlValue(26, mid);
	ModelerApplication::Instance()->SetControlValue(27, end);
	//left3
	ModelerApplication::Instance()->SetControlValue(29, root);
	ModelerApplication::Instance()->SetControlValue(30, mid);
	ModelerApplication::Instance()->SetControlValue(31, end);
	//left4
	ModelerApplication::Instance()->SetControlValue(33, root);
	ModelerApplication::Instance()->SetControlValue(34, mid);
	ModelerApplication::Instance()->SetControlValue(35, end);

	//right4
	ModelerApplication::Instance()->SetControlValue(ROTATE, rootR);
	ModelerApplication::Instance()->SetControlValue(5, midR);
	ModelerApplication::Instance()->SetControlValue(6, endR);

	//right3
	ModelerApplication::Instance()->SetControlValue(9, rootR);
	ModelerApplication::Instance()->SetControlValue(10, midR);
	ModelerApplication::Instance()->SetControlValue(11, endR);

	//right3
	ModelerApplication::Instance()->SetControlValue(13, rootR);
	ModelerApplication::Instance()->SetControlValue(14, midR);
	ModelerApplication::Instance()->SetControlValue(15, endR);

	//right3
	ModelerApplication::Instance()->SetControlValue(17, rootR);
	ModelerApplication::Instance()->SetControlValue(18, midR);
	ModelerApplication::Instance()->SetControlValue(19, endR);
	//ModelerApplication::Instance()->SetControlValue(ZPOS, Z);
	//double root = (x - 0) / (1 - 0) * (5 - 0) + 0;
}


// To make a SampleModel, we inherit off of ModelerView
class SampleModel : public ModelerView 
{
public:
    SampleModel(int x, int y, int w, int h, char *label) 
        : ModelerView(x,y,w,h,label) { }

    virtual void draw();
};

// We need to make a creator function, mostly because of
// nasty API stuff that we'd rather stay away from.
ModelerView* createSampleModel(int x, int y, int w, int h, char *label)
{ 
    return new SampleModel(x,y,w,h,label); 
}

// We are going to override (is that the right word?) the draw()
// method of ModelerView to draw out SampleModel
void SampleModel::draw()
{
	// This call takes care of a lot of the nasty projection 
	// matrix stuff.  Unless you want to fudge directly with the 
	// projection matrix, don't bother with this ...
	ModelerView::draw();



	if (ModelerApplication::Instance()->animating()) {
		
		dance(d);
		d += dx;
			if (d > 1 || d == 0) { dx = -dx; }
			cout << d << endl;
	}
	
	//guides
		/*
		// draw the floor
		setAmbientColor(.1f,.1f,.1f);
		setDiffuseColor(COLOR_RED);
		glPushMatrix();
		glTranslated(-5,0,-5);
		drawBox(10,0.01f,10);
		glPopMatrix();

		//draw axes
		//z
		setAmbientColor(.1f, .1f, .1f);
		setDiffuseColor(COLOR_RED);
		glPushMatrix();
		glTranslated(-5, 0, -5);
		drawBox(1, 10, 1);
		glPopMatrix();
		//x
		setAmbientColor(.1f, .1f, .1f);
		setDiffuseColor(COLOR_BLUE);
		glPushMatrix();
		glTranslated(-5, 0, -5);
		drawBox(10, 1, 1);
		glPopMatrix();

		//y
		setAmbientColor(.1f, .1f, .1f);
		setDiffuseColor(COLOR_GREEN);
		glPushMatrix();
		glTranslated(-5, 0, -5);
		drawBox(1, 1, 10);
		glPopMatrix();
		///////

	*/
//	if (ModelerApplication::Instance()->GetControlValue(45)) { dance(VAL(44)); }

	if (ModelerApplication::Instance()->GetControlValue(46)) { 
	
		glEnable(GL_LIGHT0);
		GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
		GLfloat light_diffuse[] = { .3, 0, 0, 1 };
		GLfloat light_specular[] = { 1.0, 1.0, 1.0, .1 };
		GLfloat light_position[] = { 0, -1, 0, 0.0 };

		glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
		glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
		glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	
	}
	
glPushMatrix();
glTranslated(VAL(XPOS), VAL(YPOS), VAL(ZPOS));
glScaled(VAL(37), VAL(37), VAL(37));
glRotated(VAL(HEIGHT), 1.0, 0, 0);
setSpecularColor(0.5, 0, 0);

if (ModelerApplication::Instance()->GetControlValue(59)) { drawOctahedron(); }

if (ModelerApplication::Instance()->GetControlValue(49)) { drawTorus(VAL(50), VAL(51), VAL(52)); }
if (ModelerApplication::Instance()->GetControlValue(58)) { drawMobius(VAL(54), VAL(55)); }
//leg

	/*
	glTranslated(-1, 2, 0);
	glScaled(2, 1.6, 2);
	drawSphere(1);
	glTranslated(1, -2, 0);
	glScaled(1, 1, 1);
	*/
//body
if (ModelerApplication::Instance()->GetControlValue(48)) {

	setDiffuseColor(0.3, 0, 0.7);
	setSpecularColor(0, 0, 0);
	setAmbientColor(0, 0, 0);


	glPushMatrix();
	glTranslated(0, 2, 0);
	drawSphere(0.1);
	glRotated(VAL(7), 0, 0, 1.0);
	glScaled(2.3, 1.8, 2.2);
	glTranslated(-1, 0, 0);
	drawSphere(1.0);
	glPopMatrix();

	//head
	glPushMatrix();
	
	glTranslated(1, 2, 0);
	
	glScaled(1.7, 1.2, 1.5);
	drawSphere(1.0);
	
	glPushMatrix();
	glTranslated(-1.5, -2, 0);
	//glRotated(90, 0, 0, 1);
	//glScaled(0.5, 0.5, 0.5);
	drawMouthPiece(VAL(40)+VAL(53), VAL(38), VAL(39));
	drawMouthPiece(VAL(43) -VAL(53), VAL(41), VAL(42));
	glPopMatrix();

	//mid eyes
	setDiffuseColor(1, 0.7, 0);
	glTranslated(0.8, 0.5, 0.2);
	glScaled(0.8, 1.2, 1);
	drawSphere(0.18);
	glTranslated(0, 0, -0.4);
	drawSphere(0.18);
	//sideEyes
	glTranslated(-0.1, 0.1, -0.3);
	//glScaled(0.8, 1.2, 1);
	drawSphere(0.1);
	glTranslated(0, 0, 1);
	drawSphere(0.1);
	glPopMatrix();
	//leg
	drawLeg(VAL(ROTATE), VAL(5), VAL(6), VAL(8));
	drawLeg(VAL(9), VAL(10), VAL(11), VAL(12));
	drawLeg(VAL(13), VAL(14), VAL(15), VAL(16));
	drawLeg(VAL(17), VAL(18), VAL(19), VAL(20));
	drawLeg(VAL(21), VAL(22), VAL(23), VAL(24));
	drawLeg(VAL(25), VAL(26), VAL(27), VAL(28));
	drawLeg(VAL(29), VAL(30), VAL(31), VAL(32));
	drawLeg(VAL(33), VAL(34), VAL(35), VAL(36));
	
	//end leg

	//mouth parts
	
	glPopMatrix();


	//draw spider
	/*
	setAmbientColor(.1f, .1f, .1f);
	setDiffuseColor(COLOR_GREEN);
	glPushMatrix();
	glTranslated(0, 0, 0);


		glPushMatrix();

		glTranslated(-1, 2, 0);
		glScaled(1, 0.8, 1);
		drawSphere(0.8);
		glTranslated(1, -2, 0);
		glScaled(1, 1, 1);

		glTranslated(-2, 3, 0);
		glRotated(-70, 0, 0, 1.0);
		glScaled(1.5, 1.2, 0.8);
		drawSphere(1.0);
		glPopMatrix();


	glPopMatrix();
	*/

	/*
	// draw the sample model
	setAmbientColor(.1f,.1f,.1f);
	setDiffuseColor(COLOR_GREEN);
	glPushMatrix();
	glTranslated(VAL(XPOS), VAL(YPOS), VAL(ZPOS));

		glPushMatrix();
		glTranslated(-1.5, 0, -2);
		glScaled(3, 1, 4);
		drawBox(1,1,1);
		glPopMatrix();



		// draw cannon
		glPushMatrix();
		glRotated(VAL(ROTATE), 0.0, 1.0, 0.0);
		glRotated(-90, 1.0, 0.0, 0.0);
		drawCylinder(VAL(HEIGHT), 0.1, 0.1);

		glTranslated(0.0, 0.0, VAL(HEIGHT));
		drawCylinder(1, 1.0, 0.9);

		glTranslated(0.0, 0.0, 0.5);
		glRotated(90, 1.0, 0.0, 0.0);
		drawCylinder(4, 0.1, 0.2);
		glPopMatrix();

	glPopMatrix();

	*/
}
}

int main()
{
	// Initialize the controls
	// Constructor is ModelerControl(name, minimumvalue, maximumvalue, 
	// stepsize, defaultvalue)
	ModelerControl controls[NUMCONTROLS + 4+4+8+4+12+1+3+3+1+1+1+1+2+3+1+2+1+1+1+1];
	controls[XPOS] = ModelerControl("X Position", -5, 5, 0.1f, 0);
	controls[YPOS] = ModelerControl("Y Position", 0, 5, 0.1f, 0);
	controls[ZPOS] = ModelerControl("Z Position", -5, 5, 0.1f, 0);
	controls[HEIGHT] = ModelerControl("MODEL Rotate", 0, 360, 1, 0);
	controls[7] = ModelerControl("BodyRotate", -60, 10, 1, -30);
	
	controls[ROTATE] = ModelerControl("legRootJoint(Right4)", 100, 250, 1, 118);
	controls[5] = ModelerControl("legMidJoint(Right4)", 0, 135, 1, 63);
	controls[6] = ModelerControl("legEndJoint(Right4)", 0, 135, 1, 90);
	controls[8] = ModelerControl("legRotate(Right4)", 50, 70, 1, 60);

	controls[9] = ModelerControl("legRootJoint(Right3)", 100, 250, 1, 125);
	controls[10] = ModelerControl("legMidJoint(Right3)", 0, 135, 1, 70);
	controls[11] = ModelerControl("legEndJoint(Right3)", 0, 135, 1, 30);
	controls[12] = ModelerControl("legRotate(Right3)", 75, 95, 1, 85);

	controls[13] = ModelerControl("legRootJoint(Right2)", 100, 250, 1, 120);
	controls[14] = ModelerControl("legMidJoint(Right2)", 0, 135, 1, 65);
	controls[15] = ModelerControl("legEndJoint(Right2)", 0, 135, 1, 55);
	controls[16] = ModelerControl("legRotate(Right2)", 100, 120, 1, 110);

	controls[17] = ModelerControl("legRootJoint(Right1)", 120, 250, 1, 120);
	controls[18] = ModelerControl("legMidJoint(Right1)", 0, 135, 1, 90);
	controls[19] = ModelerControl("legEndJoint(Right1)", 0, 135, 1, 50);
	controls[20] = ModelerControl("legRotate(Right1)", 120, 140, 1, 130);
	//LEFT LEGS
	controls[25] = ModelerControl("legRootJoint(4Left)", 100,250, 1, 118);
	controls[26] = ModelerControl("legMidJoint(Left4)", 0, 135, 1, 63);
	controls[27] = ModelerControl("legEndJoint(Left4)", 0, 135, 1, 90);
	controls[28] = ModelerControl("legRotate(Left4)", -70, -50, 1, -60);

	controls[29] = ModelerControl("legRootJoint(Left3)", 100, 250, 1, 125);
	controls[30] = ModelerControl("legMidJoint(Left3)", 0, 135, 1, 70);
	controls[31] = ModelerControl("legEndJoint(Left3)", 0, 135, 1, 30);
	controls[32] = ModelerControl("legRotate(Left3)", -95, -75, 1, -85);

	controls[33] = ModelerControl("legRootJoint(Left2)", 100, 250, 1, 120);
	controls[34] = ModelerControl("legMidJoint(Left2)", 0, 135, 1, 65);
	controls[35] = ModelerControl("legEndJoint(Left2)", 0, 135, 1, 55);
	controls[36] = ModelerControl("legRotate(Left2)", -120, -100, 1, -110);

	controls[21] = ModelerControl("legRootJoint(Left1)", 100, 250, 1, 120);
	controls[22] = ModelerControl("legMidJoint(Left1)", 0, 135, 1, 90);
	controls[23] = ModelerControl("legEndJoint(Left1)", 0, 135, 1, 50);
	controls[24] = ModelerControl("legRotate(Left1)", -140, -120, 1, -130);
	
	//global SCALE
	controls[37] = ModelerControl("MODEL SCALE", -1, 2, 0.1, 1);

	//mouth control
	controls[38] = ModelerControl("MouthENDJoint(Left)", -135, 0, 1, -65);
	controls[39] = ModelerControl("MouthWidth(Left)", 150, 170, 1, 156);
	controls[40] = ModelerControl("LEFT BITE", 135, 200, 1, 172);

	controls[41] = ModelerControl("MouthENDJoint(Right)", 0, 135, 1, 65);
	controls[42] = ModelerControl("MouthWidth(Right)", 180, 200, 1, 196);
	controls[43] = ModelerControl("RIGHT BITE", 135, 200, 1, 172);

	//animation slider
	controls[44] = ModelerControl("NULL", 0, 1, 0.05, 0);
	controls[45] = ModelerControl("NULL", 0, 1, 1, 0);

	controls[46] = ModelerControl("lightingTYPE", 0, 1, 1, 0);

	controls[47] = ModelerControl("LevelsOfDetail", 0, 4, 1, 0);

	controls[48] = ModelerControl("Hide/Show Spider", 0, 1, 1, 1);

	controls[49] = ModelerControl("Hide/Show TORUS", 0, 1, 1, 0);
	controls[50] = ModelerControl("TORUS RADIUS 1", 0, 6, 0.2, 4);
	controls[51] = ModelerControl("TORUS RADIUS 2", 0, 6, 0.2, 3);
	controls[52] = ModelerControl("TORUS STEP SIZE", 0.3, 1, 0.1, 0.5);

	controls[53] = ModelerControl("BITE CONTROL", 0, 65, 1,0);

	controls[54] = ModelerControl("Strip radius", 0, 5, 0.1, 2);
	controls[55] = ModelerControl("Strip step", 0.01, 1, 0.01, 0.01);
	controls[56] = ModelerControl("Strip WINDING NUMBER", 0, 360, 57, 57);
	controls[57] = ModelerControl("Strip ROTATE", 0, 360, 1, 0);
	controls[58] = ModelerControl("Strip SHOW/HIDE", 0, 1, 1, 0);
	
	controls[59] = ModelerControl("OCTAHEDRON show/hide", 0, 1, 1, 0);

    ModelerApplication::Instance()->Init(&createSampleModel, controls, NUMCONTROLS+4+4+8+4+12+1+3+3+1+1+1+1+2+3+1+2+1+1+1+1);
    return ModelerApplication::Instance()->Run();
}
