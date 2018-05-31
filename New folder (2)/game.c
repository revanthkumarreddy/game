#include <GL/glut.h>

// CONSTANTS FOR BODY PROPORTIONS
#define TORSO_WIDTH 5
#define TORSO_HEIGHT 6
#define TORSO_DEPTH 3

#define NECK_WIDTH 1
#define NECK_HEIGHT 1
#define NECK_DEPTH 1

#define HEAD_WIDTH 3
#define HEAD_HEIGHT 2
#define HEAD_DEPTH 3

#define ARM_U_WIDTH 1
#define ARM_U_HEIGHT 2.5
#define ARM_U_DEPTH 1
#define ARM_L_WIDTH 1
#define ARM_L_HEIGHT 2.5
#define ARM_L_DEPTH 1

#define HAND_WIDTH 1
#define HAND_HEIGHT 0.5
#define HAND_DEPTH 1

#define LEG_U_WIDTH 1.5
#define LEG_U_HEIGHT 3
#define LEG_U_DEPTH 1
#define LEG_L_WIDTH 1.5
#define LEG_L_HEIGHT 3
#define LEG_L_DEPTH 1

#define FOOT_WIDTH 1
#define FOOT_HEIGHT 0.5
#define FOOT_DEPTH 1

float width = 500;
float height = 500;

float xt = 0, yt = 0, zt = 0, z1t = 0;
float t=zt;
int toggle = 1;
int type1 = 1, type2 = 1;
int solid = 1;

void head(void);
void init(void);
void display(void);
void reshape (int width, int height);
void keyboard(unsigned char, int, int);
void torso(void);
void arms(int type);
void lowers(int type); 

void torso() {
/* 
 * This function creates the torso of the robot 
 */
	glPushMatrix();
	glScalef(TORSO_WIDTH, TORSO_HEIGHT, 3);
	glColor3f(0.6,0.6,0.6);
	glutSolidCube(1.0);
	glPopMatrix();
}

void head() {
/* 
 * This function creates the head of the robot.
 * Head, Neck, Eyes, Mouth and Nose are drawn by this function. 
 */
	glPushMatrix();
	
	/* Neck */
	glTranslatef(0.0, TORSO_HEIGHT/2 + NECK_HEIGHT, TORSO_DEPTH/2);
	glScalef(NECK_WIDTH, NECK_HEIGHT, NECK_DEPTH);
	glColor3f(1,1,1);
	glutSolidCube(1.0);
	glPopMatrix();	

	/* Head */
	glPushMatrix();
	glTranslatef(0.0, TORSO_HEIGHT/2 + NECK_HEIGHT + HEAD_HEIGHT/2, TORSO_DEPTH/2);
	glScalef(HEAD_WIDTH, HEAD_HEIGHT, HEAD_DEPTH);
	glColor3f(1,1,0);
	glutSolidCube(1.0);
	
	glPopMatrix();

	/* Right Eye */
	glPushMatrix();
	glTranslatef(1, TORSO_HEIGHT/2 + NECK_HEIGHT + HEAD_HEIGHT*2/3, HEAD_DEPTH);
	glScalef(0.5, 0.5, 0);
	glColor3f(0.7,0.7,0.7);
	glutSolidCube(1.0);
	glPopMatrix();

	/* Left Eye */
	glPushMatrix();
	glTranslatef(-1, TORSO_HEIGHT/2 + NECK_HEIGHT + HEAD_HEIGHT*2/3, HEAD_DEPTH);
	glScalef(0.5, 0.5, 0);
	glColor3f(0.7,0.7,0.7);
	glutSolidCube(1.0);
	glPopMatrix();

	/* Mouth and Nose */

	glPushMatrix();
	glTranslatef(0, TORSO_HEIGHT/2 + NECK_HEIGHT + HEAD_HEIGHT/2 - 0.1, HEAD_DEPTH);
	glScalef(0.3, 0.3, 0);
	glColor3f(0,0,0);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, TORSO_HEIGHT/2 + NECK_HEIGHT + HEAD_HEIGHT/2 - 0.6, HEAD_DEPTH);
	glScalef(1.7, 0.3, 0);
	glColor3f(0,0,0);
	glutSolidCube(1.0);
	glPopMatrix();
	
}

void arms(int type) {
/* 
 * This function creates the arms of the robot.
 * The arms are divided into 3 parts as shown in the scene graph.
 * There are 4 possible frames for the robot, which are drawn by 
 * this function depending on the value of the passed parameter.
 * @param type The frame type which has to be drawn.  
 */	
 
	/* DRAWING ON THE RIGHT SIDE */
	
	if (type == 0) {
		glPushMatrix();
		glTranslatef(TORSO_WIDTH/2 + ARM_U_WIDTH/2+1, TORSO_HEIGHT/2 - ARM_U_HEIGHT/2, TORSO_DEPTH/2);
		glRotatef(-20, 1, 0, 0);
		glScalef(ARM_U_WIDTH, ARM_U_HEIGHT, ARM_U_DEPTH);
		glColor3f(1,1,1);
		glutSolidCube(1.0);
		glPopMatrix();	
	
		glPushMatrix();
		glTranslatef(TORSO_WIDTH/2 + ARM_U_WIDTH/2+1, TORSO_HEIGHT/2 - ARM_U_HEIGHT - ARM_L_HEIGHT/2 + 1.5, TORSO_DEPTH/2);
		glRotatef(-60, 1, 0, 0);
		glScalef(ARM_L_WIDTH, ARM_L_HEIGHT, ARM_L_DEPTH);
		glColor3f(1,0,0);
		glutSolidCube(1.0);

		glPopMatrix();	
		
		glPushMatrix();
		glRotatef(-60, 1, 0, 0);
		glTranslatef(TORSO_WIDTH/2 + ARM_U_WIDTH/2+1, TORSO_HEIGHT/2 - ARM_U_HEIGHT - ARM_L_HEIGHT - HAND_HEIGHT/2+0.2, TORSO_DEPTH/2);
		glScalef(HAND_WIDTH, HAND_HEIGHT, HAND_DEPTH);
		glColor3f(0,1,0);
		glutSolidCube(1.0);
		glPopMatrix();	
		
	/* DRAWING ON THE LEFT SIDE */
		
		glPushMatrix();
		glTranslatef(-TORSO_WIDTH/2 - ARM_U_WIDTH/2-1, TORSO_HEIGHT/2 - ARM_U_HEIGHT/2, TORSO_DEPTH/2);
		glRotatef(20, 1, 0, 0);
		glScalef(ARM_U_WIDTH, ARM_U_HEIGHT, ARM_U_DEPTH);
		glColor3f(1,1,1);
		glutSolidCube(1.0);
		glPopMatrix();	
	
		glPushMatrix();
		glTranslatef(-TORSO_WIDTH/2 - ARM_U_WIDTH/2-1, TORSO_HEIGHT/2 - ARM_U_HEIGHT - ARM_L_HEIGHT/2, TORSO_DEPTH/2);
		glRotatef(-10, 1, 0, 0);
		glScalef(ARM_L_WIDTH, ARM_L_HEIGHT, ARM_L_DEPTH);
		glColor3f(1,0,0);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glRotatef(-10, 1, 0, 0);
		glTranslatef(-TORSO_WIDTH/2 - ARM_U_WIDTH/2-1, TORSO_HEIGHT/2 - ARM_U_HEIGHT - ARM_L_HEIGHT - HAND_HEIGHT/2, TORSO_DEPTH/2);
		glScalef(HAND_WIDTH, HAND_HEIGHT, HAND_DEPTH);
		glColor3f(0,1,0);
		glutSolidCube(1.0);
		glPopMatrix();
	}
	else if (type == 1 || type==3) {
	
	/* DRAWING ON THE RIGHT SIDE */
	
		glPushMatrix();
		glTranslatef(TORSO_WIDTH/2 + ARM_U_WIDTH/2+1, TORSO_HEIGHT/2 - ARM_U_HEIGHT/2, TORSO_DEPTH/2);
		glScalef(ARM_U_WIDTH, ARM_U_HEIGHT, ARM_U_DEPTH);
		glColor3f(1,1,1);
		glutSolidCube(1.0);
		glPopMatrix();	
	
		glPushMatrix();
		glTranslatef(TORSO_WIDTH/2 + ARM_U_WIDTH/2+1, TORSO_HEIGHT/2 - ARM_U_HEIGHT - ARM_L_HEIGHT/2, TORSO_DEPTH/2);
		glScalef(ARM_L_WIDTH, ARM_L_HEIGHT, ARM_L_DEPTH);
		glColor3f(1,0,0);
		glutSolidCube(1.0);
		glPopMatrix();	

		glPushMatrix();
		glTranslatef(TORSO_WIDTH/2 + ARM_U_WIDTH/2+1, TORSO_HEIGHT/2 - ARM_U_HEIGHT - ARM_L_HEIGHT - HAND_HEIGHT/2, TORSO_DEPTH/2);
		glScalef(HAND_WIDTH, HAND_HEIGHT, HAND_DEPTH);
		glColor3f(0,1,0);
		glutSolidCube(1.0);
		glPopMatrix();

	/* DRAWING ON THE LEFT SIDE */
	
		glPushMatrix();
		glTranslatef(-TORSO_WIDTH/2 - ARM_U_WIDTH/2-1, TORSO_HEIGHT/2 - ARM_U_HEIGHT/2, TORSO_DEPTH/2);
		glScalef(ARM_U_WIDTH, ARM_U_HEIGHT, ARM_U_DEPTH);
		glColor3f(1,1,1);
		glutSolidCube(1.0);
		glPopMatrix();	
	
		glPushMatrix();
		glTranslatef(-TORSO_WIDTH/2 - ARM_U_WIDTH/2-1, TORSO_HEIGHT/2 - ARM_U_HEIGHT - ARM_L_HEIGHT/2, TORSO_DEPTH/2);
		glScalef(ARM_L_WIDTH, ARM_L_HEIGHT, ARM_L_DEPTH);
		glColor3f(1,0,0);
		glutSolidCube(1.0);
		glPopMatrix();	

		glPushMatrix();
		glTranslatef(-TORSO_WIDTH/2 - ARM_U_WIDTH/2-1, TORSO_HEIGHT/2 - ARM_U_HEIGHT - ARM_L_HEIGHT - HAND_HEIGHT/2, TORSO_DEPTH/2);
		glScalef(HAND_WIDTH, HAND_HEIGHT, HAND_DEPTH);
		glColor3f(0,1,0);
		glutSolidCube(1.0);
		glPopMatrix();
	}
	else if (type == 2) {
		
		/* DRAWING ON THE RIGHT SIDE */
		
		glPushMatrix();
		glTranslatef(TORSO_WIDTH/2 + ARM_U_WIDTH/2+1, TORSO_HEIGHT/2 - ARM_U_HEIGHT/2, TORSO_DEPTH/2);
		glRotatef(20, 1, 0, 0);
		glScalef(ARM_U_WIDTH, ARM_U_HEIGHT, ARM_U_DEPTH);
		glColor3f(1,1,1);
		glutSolidCube(1.0);
		glPopMatrix();	
	
		glPushMatrix();
		glTranslatef(TORSO_WIDTH/2 + ARM_U_WIDTH/2+1, TORSO_HEIGHT/2 - ARM_U_HEIGHT - ARM_L_HEIGHT/2 + 1.5, TORSO_DEPTH/2);
		glRotatef(-10, 1, 0, 0);
		glScalef(ARM_L_WIDTH, ARM_L_HEIGHT, ARM_L_DEPTH);
		glColor3f(1,0,0);
		glutSolidCube(1.0);
		glPopMatrix();	

		glPushMatrix();
		glTranslatef(TORSO_WIDTH/2 + ARM_U_WIDTH/2+1, TORSO_HEIGHT/2 - ARM_U_HEIGHT - ARM_L_HEIGHT + 1.1 + HAND_HEIGHT/2, TORSO_DEPTH/2);
		glRotatef(-10, 1, 0, 0);
		glScalef(HAND_WIDTH, HAND_HEIGHT, HAND_DEPTH);
		glColor3f(0,1,0);
		glutSolidCube(1.0);
		glPopMatrix();

		/* DRAWING ON THE LEFT SIDE */
		
		glPushMatrix();
		glTranslatef(-TORSO_WIDTH/2 - ARM_U_WIDTH/2-1, TORSO_HEIGHT/2 - ARM_U_HEIGHT/2, TORSO_DEPTH/2);
		glRotatef(-20, 1, 0, 0);
		glScalef(ARM_U_WIDTH, ARM_U_HEIGHT, ARM_U_DEPTH);
		glColor3f(1,1,1);
		glutSolidCube(1.0);
		glPopMatrix();	
	
		glPushMatrix();
		glTranslatef(-TORSO_WIDTH/2 - ARM_U_WIDTH/2-1.1, TORSO_HEIGHT/2 - ARM_U_HEIGHT - ARM_L_HEIGHT/2 + 1.2, TORSO_DEPTH/2);
		glRotatef(-60, 1, 0, 0);
		glScalef(ARM_L_WIDTH, ARM_L_HEIGHT, ARM_L_DEPTH);
		glColor3f(1,0,0);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glRotatef(-60, 1, 0, 0);
		glTranslatef(-TORSO_WIDTH/2 - ARM_U_WIDTH/2-1, TORSO_HEIGHT/2 - ARM_U_HEIGHT - ARM_L_HEIGHT  + HAND_HEIGHT/2, TORSO_DEPTH/2);
		glScalef(HAND_WIDTH, HAND_HEIGHT, HAND_DEPTH);
		glColor3f(0,1,0);
		glutSolidCube(1.0);
		glPopMatrix();
	}	
}

void lowers(int type) {
/* 
 * This function creates the legs of the robot.
 * The legs are divided into 3 parts as shown in the scene graph.
 * There are 4 possible frames for the robot, which are drawn by 
 * this function depending on the value of the passed parameter.
 * @param type The frame type which has to be drawn.  
 */	
	if (type == 0) {
		
		/* DRAWING ON THE RIGHT SIDE */
		
		glPushMatrix();
		glColor3d(1,1,1);
		glTranslatef(TORSO_WIDTH/2 - LEG_U_WIDTH/2, -TORSO_HEIGHT/2 - LEG_U_HEIGHT/2, TORSO_DEPTH/2);
		glRotatef(0, 1, 0, 0);
		glScalef(LEG_U_WIDTH, ARM_U_HEIGHT, LEG_U_DEPTH);
		glColor3f(1,1,1);
		glutSolidCube(1.0);
		glPopMatrix();	
	
		glPushMatrix();
		glTranslatef(TORSO_WIDTH/2 - LEG_U_WIDTH/2, -TORSO_HEIGHT/2 - LEG_U_HEIGHT - LEG_L_HEIGHT/2+0.5, TORSO_DEPTH/2);
		glRotatef(2, 1, 0, 0);
		glScalef(LEG_L_WIDTH, LEG_L_HEIGHT, LEG_L_DEPTH);
		glColor3f(0,0,1);
		glutSolidCube(1.0);
		
		glScalef(FOOT_WIDTH, FOOT_HEIGHT, FOOT_DEPTH);
		glTranslatef(0, -LEG_L_HEIGHT/2-FOOT_HEIGHT/2, FOOT_DEPTH/2);
		glColor3f(0,1,0);
		glutSolidCube(1.0);
		glPopMatrix();	

		/* DRAWING ON THE LEFT SIDE */
		
		glPushMatrix();
		glTranslatef(-TORSO_WIDTH/2 + LEG_U_WIDTH/2, -TORSO_HEIGHT/2 - LEG_U_HEIGHT/2, TORSO_DEPTH/2);
		glRotatef(-20, 1, 0, 0);
		glScalef(LEG_U_WIDTH, ARM_U_HEIGHT, LEG_U_DEPTH);
		glColor3f(1,1,1);
		glutSolidCube(1.0);
		glPopMatrix();	
	
		glPushMatrix();
		glTranslatef(-TORSO_WIDTH/2 + LEG_U_WIDTH/2, -TORSO_HEIGHT/2 - LEG_U_HEIGHT - LEG_L_HEIGHT/2+0.5, TORSO_DEPTH/2);
		glRotatef(20, 1, 0, 0);
		glScalef(LEG_L_WIDTH, LEG_L_HEIGHT, LEG_L_DEPTH);
		glColor3f(0,0,1);
		glutSolidCube(1.0);
		
		glScalef(FOOT_WIDTH, FOOT_HEIGHT, FOOT_DEPTH);
		glTranslatef(0, -LEG_L_HEIGHT/2-FOOT_HEIGHT/2, FOOT_DEPTH/2);
		glColor3f(0,1,0);
		glutSolidCube(1.0);
		glPopMatrix();	
	}
	else if (type == 1 || type == 3) {
		
		/* DRAWING ON THE RIGHT SIDE */
		
		glPushMatrix();
		glTranslatef(TORSO_WIDTH/2 - LEG_U_WIDTH/2, -TORSO_HEIGHT/2 - LEG_U_HEIGHT/2, TORSO_DEPTH/2);
		glScalef(LEG_U_WIDTH, LEG_U_HEIGHT, LEG_U_DEPTH);
		glColor3f(1,1,1);
		glutSolidCube(1.0);
		glPopMatrix();	
	
		glPushMatrix();
		glTranslatef(TORSO_WIDTH/2 - LEG_U_WIDTH/2, -TORSO_HEIGHT/2 - LEG_U_HEIGHT - LEG_L_HEIGHT/2+0.5, TORSO_DEPTH/2);
		glScalef(LEG_L_WIDTH, LEG_L_HEIGHT, LEG_L_DEPTH);
		glColor3f(0,0,1);
		glutSolidCube(1.0);
		
		glScalef(FOOT_WIDTH, FOOT_HEIGHT, FOOT_DEPTH);
		glTranslatef(0, -LEG_L_HEIGHT/2-FOOT_HEIGHT/2, FOOT_DEPTH/2);
		glColor3f(0,1,0);
		glutSolidCube(1.0);
		glPopMatrix();	

		/* DRAWING ON THE LEFT SIDE */
		
		glPushMatrix();
		glTranslatef(-TORSO_WIDTH/2 + LEG_U_WIDTH/2, -TORSO_HEIGHT/2 - LEG_U_HEIGHT/2, TORSO_DEPTH/2);
		glScalef(LEG_U_WIDTH, ARM_U_HEIGHT, LEG_U_DEPTH);
		glColor3f(1,1,1);
		glutSolidCube(1.0);
		glPopMatrix();
	
		glPushMatrix();
		glTranslatef(-TORSO_WIDTH/2 + LEG_U_WIDTH/2, -TORSO_HEIGHT/2 - LEG_U_HEIGHT - LEG_L_HEIGHT/2+0.5, TORSO_DEPTH/2);
		glScalef(LEG_L_WIDTH, LEG_L_HEIGHT, LEG_L_DEPTH);
		glColor3f(0,0,1);
		glutSolidCube(1.0);
		
		glScalef(FOOT_WIDTH, FOOT_HEIGHT, FOOT_DEPTH);
		glTranslatef(0, -LEG_L_HEIGHT/2-FOOT_HEIGHT/2, FOOT_DEPTH/2);
		glColor3f(0,1,0);
		glutSolidCube(1.0);
		glPopMatrix();
	}
	else if (type == 2) {
	
		/* DRAWING ON THE RIGHT SIDE */
	
		glPushMatrix();
		glTranslatef(TORSO_WIDTH/2 - LEG_U_WIDTH/2, -TORSO_HEIGHT/2 - LEG_U_HEIGHT/2, TORSO_DEPTH/2);
		glRotatef(-20, 1, 0, 0);
		glScalef(LEG_U_WIDTH, LEG_U_HEIGHT, LEG_U_DEPTH);
		glColor3f(1,1,1);
		glutSolidCube(1.0);
		glPopMatrix();	
	
		glPushMatrix();
		glTranslatef(-TORSO_WIDTH/2 + LEG_U_WIDTH/2, -TORSO_HEIGHT/2 - LEG_U_HEIGHT - LEG_L_HEIGHT/2+0.5, TORSO_DEPTH/2);
		glRotatef(2, 1, 0, 0);
		glScalef(LEG_L_WIDTH, LEG_L_HEIGHT, LEG_L_DEPTH);
		glColor3f(0,0,1);
		glutSolidCube(1.0);

		glScalef(FOOT_WIDTH, FOOT_HEIGHT, FOOT_DEPTH);
		glTranslatef(0, -LEG_L_HEIGHT/2-FOOT_HEIGHT/2, FOOT_DEPTH/2);
		glColor3f(0,1,0);
		glutSolidCube(1.0);
		glPopMatrix();
		
		/* DRAWING ON THE LEFT SIDE */
		
		glPushMatrix();
		glTranslatef(-TORSO_WIDTH/2 + LEG_U_WIDTH/2, -TORSO_HEIGHT/2 - LEG_U_HEIGHT/2, TORSO_DEPTH/2);
		glRotatef(0, 1, 0, 0);
		glScalef(LEG_U_WIDTH, ARM_U_HEIGHT, LEG_U_DEPTH);
		glColor3f(1,1,1);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(TORSO_WIDTH/2 - LEG_U_WIDTH/2, -TORSO_HEIGHT/2 - LEG_U_HEIGHT - LEG_L_HEIGHT/2, TORSO_DEPTH/2);
		glRotatef(10, 1, 0, 0);
		glScalef(LEG_L_WIDTH, LEG_L_HEIGHT, LEG_L_DEPTH);
		glColor3f(0,0,1);
		glutSolidCube(1.0);

		glScalef(FOOT_WIDTH, FOOT_HEIGHT, FOOT_DEPTH);
		glTranslatef(0, -LEG_L_HEIGHT/2-FOOT_HEIGHT/2, FOOT_DEPTH/2);
		glColor3f(0,1,0);
		glutSolidCube(1.0);
		glPopMatrix();	
	}
	else if (type == 3) {
	
		/* DRAWING ON THE RIGHT SIDE */
	
		glPushMatrix();
		glTranslatef(TORSO_WIDTH/2 - LEG_U_WIDTH/2, -TORSO_HEIGHT/2 - LEG_U_HEIGHT/2, TORSO_DEPTH/2);
		glScalef(LEG_U_WIDTH, ARM_U_HEIGHT, LEG_U_DEPTH);
		glColor3f(1,1,1);
		glutSolidCube(1.0);
		glPopMatrix();	
	
		glPushMatrix();
		glTranslatef(TORSO_WIDTH/2 - LEG_U_WIDTH/2, -TORSO_HEIGHT/2 - LEG_U_HEIGHT - LEG_L_HEIGHT/2+0.5, TORSO_DEPTH/2);
		glScalef(LEG_L_WIDTH, LEG_L_HEIGHT, LEG_L_DEPTH);
		glColor3f(0,0,1);
		glutSolidCube(1.0);
		glPopMatrix();	
		
		/* DRAWING ON THE LEFT SIDE */
		
		glPushMatrix();
		glTranslatef(-TORSO_WIDTH/2 + LEG_U_WIDTH/2, -TORSO_HEIGHT/2 - LEG_U_HEIGHT/2, TORSO_DEPTH/2);
		glScalef(LEG_U_WIDTH, ARM_U_HEIGHT, LEG_U_DEPTH);
		glColor3f(1,1,1);
		glutSolidCube(1.0);
		glPopMatrix();	
	
		glPushMatrix();
		glTranslatef(-TORSO_WIDTH/2 + LEG_U_WIDTH/2, -TORSO_HEIGHT/2 - LEG_U_HEIGHT - LEG_L_HEIGHT/2+0.5, TORSO_DEPTH/2);
		glScalef(LEG_L_WIDTH, LEG_L_HEIGHT, LEG_L_DEPTH);
		glColor3f(0,0,1);
		glutSolidCube(1.0);
		glPopMatrix();	
	}
}

void display(void) {
/* 
 * This function is called to draw contents on the display window.
 */		
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	/* For switching between Solid and WireFrame mode */
	if(!solid)
		glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
	else
		glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );

	gluLookAt(0, 5, 25, 0, 0, 0, 0, 1, 0);

	/* Drawing floor Surface */
	glPushMatrix();	
	
	glColor3f(0,0.4,0);
	glBegin(GL_POLYGON);
	glVertex3f(15.0, -1.5*TORSO_HEIGHT, 15.0);
	glVertex3f(15.0, -1.5*TORSO_HEIGHT, -15.0);
	glVertex3f(-15.0, -1.5*TORSO_HEIGHT, -15.0);
	glVertex3f(-15.0, -1.5*TORSO_HEIGHT, 15.0);
	glEnd();
	
	glPopMatrix();

	/* Drawing Robot 1*/
	if(toggle)
		zt = t;

	glPushMatrix();
	
	glTranslated(xt-5, yt, zt);
	torso();		// draw torso
	head();			// draw head

	/* Changing type1 here gives different postures */
	arms(type1);		// draw arms
	lowers(type1);		// draw legs
	
	glPopMatrix();


	/* Drawing Robot 2 */
	if(!toggle)
		z1t = t;

	glPushMatrix();
	
	glTranslated(xt+5, yt, z1t);
	torso();			// draw torso
	head();				// draw head
	
	/* Changing type1 here gives different postures */
	arms(type2);		// draw arms
	lowers(type2);		// draw legs
	
	glPopMatrix();

	/* Drawing other background objects*/

	/* toruses */
	if (toggle==0) {
		glColor3f(1,0,0);
	}
	else {
		glColor3f(0,1,0);
	}
	glPushMatrix();		
	glTranslatef(13.0, -1*TORSO_HEIGHT+2 , 13.0);	
	glutSolidTorus(0.8, 2, 10, 20);
	glPopMatrix();

	if (toggle==1) {
		glColor3f(1,0,0);
	}
	else {
		glColor3f(0,1,0);
	}
	glPushMatrix();		
	glTranslatef(-13.0, -1*TORSO_HEIGHT+2 , 13.0);	
	glutSolidTorus(0.8, 2, 10, 20);
	glPopMatrix();

	/* spheres */
	glColor3f(0.0, 1.0, 1.0);
	for(int i=-15; i<15; i+=3){
		glPushMatrix();		
		glTranslatef(0.0, -1*TORSO_HEIGHT , i);
		glutSolidSphere( 1.0, 10.0, 10.0);
		glPopMatrix();
	}
	
	glutSwapBuffers();
}

void keyboard (unsigned char key, int x, int y) {
/*
 * This function is used to handle keyboard events.
 * This function deals with events that are triggered
 * when either of the keys [W,F,B,T,Q] are pressed.
 */
	switch (key) {
	case 'w': 
		if (solid == 0) {
			solid=1;
		}
		else{
			solid=0;
		}
		break;
	case 'f':	if(t == 13)
					t += 0.0;
				else
					t += 0.5;
		if (toggle) {
			type1 = (type1 + 1) % 4;
		}
		else {
			type2 = (type2 + 1) % 4;
		}
		break;
	case 'b':	if(t == -15)
					t -=0.0;
				else
					t -= 0.5;
		if (toggle) {
			type1 = (type1 - 1);
			if(type1 < 0)
				type1 = 3;
		}
		else {
			type2 = (type2 - 1);
			if(type2 < 0)
				type2 = 3;
		}
		break;
	case 't':	if(toggle)
				{
					toggle = 0;
					t = z1t;
				}
				else
				{
					toggle = 1; 
					t = zt;
				}
		break;
	case 'q': exit(0); 
		break;
	}
	glutPostRedisplay();
}

void reshape(int w, int h) {
/* 
 * This function handles the aspect ratio of the window.
 */
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(100.0, (GLfloat) w / (GLfloat) h, 0.5, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void init (void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH|GLUT_DOUBLE);
	glutInitWindowSize(width, height);
	glutCreateWindow("------------- BOT WALK -------------");
	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}