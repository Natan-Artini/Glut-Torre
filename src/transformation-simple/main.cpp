/**
 * Simple demonstration of transformations.
 */

#include <GL/glut.h>
#include <GL/gl.h>

void renderCoordinateAxis()
{
	// X axis - green color
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
		// Left side, negative X
		glVertex2f(-1.0, 0.0);
		glVertex2f(0.0, 0.0);

		// Right side, positive X
		glVertex2f(0.0, 0.0);
		glVertex2f(1.0, 0.0);
	glEnd();

	// Y axis - blue color
	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
		// Top side, positive Y
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, 1.0);

		// Bottom side, negative Y
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, -1.0);
	glEnd();
}

float rotate = 0.0f;
float direct = 0.005f;
float X = 0.0f;
float scale = 0.005f;
float Y = 1.0f;

void display()
{
	// Clear the screen painting it all with the white color
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	// Inform OpenGL we want to make changes to the modelview matrix
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	// Render the X and Y axis to guide ourselves.
	renderCoordinateAxis();

	// Render a red square
	glColor3f(1, 0, 0);
	
	glLoadIdentity();
	
	if(X > 0.9 || X < -0.9){
		direct = direct * -1.0;
	}
	X = X + direct;
	
	glTranslatef(X, 0, 0);

	rotate += 1;
	glRotatef(rotate, 0.0f, 0.0f, 1.0f);

	if(Y > 1.4 || Y < 1.0){
		scale = scale * -1.0;
	}
	Y = Y + scale;
	glScaled(Y, Y, 1.0);

	glRectf(-0.1f, 0.1f, 0.1f, -0.1f);

	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == 27) {
		// ESC key
		exit(0);
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Transformation - Simple");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutKeyboardFunc(keyboard);

	glutMainLoop();
	return 0;
}