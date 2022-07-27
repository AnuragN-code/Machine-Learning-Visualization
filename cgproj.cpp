#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<gl/glut.h>
#include<math.h>

#define PI 3.142
GLint m_viewport[4];
bool mButtonPressed = false;
float mouseX, mouseY;
GLfloat a = 0, b = 0, c = 0, d = 0, e = 0;
enum view { INTRO, MENU, INSTRUCTIONS, SCREEN1, SCREEN2, SCREEN3, SCREEN4, SCREEN5, SCREEN6, SCREEN7, SCREEN8 };
view viewPage = INTRO; // initial value
bool keyStates[256] = { false };

// to draw text
void displayRasterText(float x, float y, float z, const char* stringToDisplay)
{
    glRasterPos3f(x, y, z);
    for (const char* c = stringToDisplay; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}
//init method
void init()
{
    glClearColor(1, 1, 1, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1200, 1200, -700, 700);
    glMatrixMode(GL_MODELVIEW);
}


//key press operations defining
void keyOperations() {


    if (keyStates[13] == true && viewPage == INTRO ){
        viewPage = MENU;
        printf("enter key pressed\n");
    }
    if (keyStates['Q'] == true && viewPage == SCREEN1) {
        viewPage = SCREEN2;
        printf("Q key pressed\n");
    }
    if (keyStates['W'] == true && viewPage == SCREEN2) {
        viewPage = SCREEN3;
        printf("W key pressed\n");
    }
    if (keyStates['E'] == true && viewPage == SCREEN3) {
        viewPage = SCREEN4;
        printf("E key pressed\n");
    }
    if (keyStates['R'] == true && viewPage == SCREEN4) {
        viewPage = SCREEN6;
        printf("R key pressed\n");
    }
    if (keyStates['T'] == true && viewPage == SCREEN6) {
        viewPage = SCREEN5;
        printf("T key pressed\n");
    }
    if (keyStates['Y'] == true && viewPage == SCREEN5) {
        viewPage = MENU;
        printf("Y key pressed\n");
    }
    if (keyStates['U'] == true && viewPage == SCREEN7) {

        viewPage = SCREEN8;
        printf("U key pressed\n");
    }
}

//drawfilledelipse 
void drawFilledelipse(GLfloat x, GLfloat y, GLfloat xcenter, GLfloat ycenter) //circle drawing
{


    int i;
    int triangleAmount = 20; //# of triangles used to draw circle
    GLfloat twicePi = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + ((xcenter + 1) * cos(i * twicePi / triangleAmount)),
            y + ((ycenter - 1) * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();


}


//drawclouds
void drawClouds(int x, int y)
{


    glColor3f(255.0, 255.0, 255.0);
    drawFilledelipse(x, y, 80, 45);
    glColor3f(255.0, 255.0, 255.0);
    drawFilledelipse(x + 25, y + 15, 35, 35);
    glColor3f(255.0, 255.0, 255.0);
    drawFilledelipse(x + 25, y - 15, 35, 35);
    glColor3f(255.0, 255.0, 255.0);
    drawFilledelipse(x - 25, y - 15, 35, 35);
    glColor3f(255.0, 255.0, 255.0);
    drawFilledelipse(x - 25, y + 15, 35, 35);
}


//introscreen
void introScreen()
{
    glClear(GL_COLOR_BUFFER_BIT);


    glColor3f(1.0, 0, 0);
    displayRasterText(-450, 490, 0.0, "SAHYADRI COLLEGE OF ENGINEERING AND MANAGEMENT");

    glColor3f(1.0, 0, 0);
    displayRasterText(-225, 450, 0.0, "AN AUTONOMOUS INSTITUTE");

    glColor3f(0.59, 0.59, 0.59);
    displayRasterText(-450,380, 0.0, "DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");


    glColor3f(1.0, 0, 0);
    displayRasterText(-150, 250, 0.0, "A MINI PROJECT ON ");


    glColor3f(0.2, 0.5, 1.0);
    displayRasterText(-350, 200, 0.0, "      MACHINE LEARNING VISUALIZATION");


    glColor3f(1.0, 0, 0);
    displayRasterText(-800,-100 , 0.0, " CREATED BY");


    glColor3f(1.0, 0, 0);
    //displayRasterText(-800, -100, 0.0, " STUDENT NAMES");


    glColor3f(0, 0, 0);
    displayRasterText(-800, -200, 0.0, " ANURAG - 4SF19CS029");
    //displayRasterText(-800, -285, 0.0, " ");
    displayRasterText(-800, -285, 0.0, " SY BHARATH - 4SF19CS131");
    //displayRasterText(-800, -455, 0.0, " ");


    glColor3f(1.0, 0, 0);
    displayRasterText(500, -100, 0.0, "UNDER THE GUIDANCE OF");


    glColor3f(0, 0, 0);
    displayRasterText(500, -200, 0.0, "MS. MEGHA RANI");


    glColor3f(1.0, 0, 0);
    displayRasterText(-250, -400, 0.0, "    ACADEMIC YEAR 2020-2021");


    glColor3f(0, 0, 0);
    displayRasterText(-225, -550, 0.0, "    PRESS ENTER TO START");


    glFlush();
    glutSwapBuffers();
}


//menuscreen
void menuScreen()
{

    glClearColor(0.41, 0.63, 0.95, 0);
    glLineWidth(10);
    glColor3f(0.2, 0.5, 1.0);
    glBegin(GL_LINE_LOOP);               //BORDER
    glVertex2f(-750, -500);
    glVertex2f(-750, 550);
    glVertex2f(750, 550);
    glVertex2f(750, -500);
    glEnd();


    glColor3f(0.2, 0.5, 1.0);
    glBegin(GL_POLYGON);                                //BUILD POLYGON
    glVertex2f(-200, 300);
    glVertex2f(-200, 400);
    glVertex2f(200, 400);
    glVertex2f(200, 300);
    glEnd();

    glBegin(GL_POLYGON);                                //TEST MODEL POLYGON
    glVertex2f(-200, 100);
    glVertex2f(-200, 200);
    glVertex2f(200, 200);
    glVertex2f(200, 100);
    glEnd();

    glBegin(GL_POLYGON);                                //INSTRUCTIONS POLYGON
    glVertex2f(-200, -100);
    glVertex2f(-200, 0);
    glVertex2f(200, 0);
    glVertex2f(200, -100);
    glEnd();

    glBegin(GL_POLYGON);                                //QUIT POLYGON
    glVertex2f(-200, -300);
    glVertex2f(-200, -200);
    glVertex2f(200, -200);
    glVertex2f(200, -300);
    glEnd();


    if (mouseX >= -100 && mouseX <= 100 && mouseY >= 150 && mouseY <= 200) {
        glColor3f(0, 0, 1);
        if (mButtonPressed) {
            viewPage = SCREEN1;
            mButtonPressed = false;
        }
    }
    else
        glColor3f(1, 1, 1);


    displayRasterText(-100, 340, 0.4, "TRAIN MODEL"); // BUILD TEXT

    if (mouseX >= -100 && mouseX <= 100 && mouseY >= 30 && mouseY <= 80) {
        glColor3f(0, 0, 1);
        if (mButtonPressed) {
            viewPage = SCREEN7;


            mButtonPressed = false;
        }
    }
    else
        glColor3f(1, 1, 1);
    displayRasterText(-100, 145, 0.4, "TEST MODEL");


    if (mouseX >= -100 && mouseX <= 100 && mouseY >= -30 && mouseY <= 10) {
        glColor3f(0, 0, 1);
        if (mButtonPressed) {
            viewPage = INSTRUCTIONS;


            mButtonPressed = false;
        }
    }
    else
        glColor3f(1, 1, 1);
    displayRasterText(-120, -60, 0.4, "INSTRUCTIONS"); //INSTRUCTION TEXT

    
    if (mouseX >= -100 && mouseX <= 100 && mouseY >= -150 && mouseY <= -85) {
        glColor3f(0, 0, 1);
        if (mButtonPressed) {
            exit(0);
            mButtonPressed = false;
        }
    }
    else
        glColor3f(1, 1, 1);
    displayRasterText(-45, -255, 0.4, "QUIT"); //QUIT TEXT


    glutPostRedisplay();
}
//back button working
void backButton() {
    if (mouseX <= -450 && mouseX >= -500 && mouseY >= -275 && mouseY <= -250) {
        glColor3f(0, 0, 1);
        if (mButtonPressed) {
            viewPage = MENU;
            mButtonPressed = false;
            glutPostRedisplay();
        }
    }
    else glColor3f(1, 1, 1);
    displayRasterText(-1000, -550, 0, "Back");
}
//instructionscreen


void instructionScreen()
{
    glClearColor(0.41, 0.63, 0.95, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0, 0, 0);
    displayRasterText(-900, 600, 0.4, "INSTRUCTIONS");
    glColor3f(1, 1, 1);
    displayRasterText(-900, 400, 0.4, "Each page will have a key press to be done, follow the same!");
    glColor3f(1, 1, 1);
    displayRasterText(-900, 300, 0.4, "The keys are in the order Q, UP, LEFT, RIGHT, DOWN, W E R T Y ");
    glColor3f(1, 1, 1);
    displayRasterText(-900, 200, 0.4, "The keys are in the order  L, C, U");
    glColor3f(1, 1, 1);
    backButton();

}
void wheel(int x, int y)
{
    float th;
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    for (int i = 0; i < 360; i++)
    {
        th = i * (3.1416 / 180);
        glVertex2f(x + 30 * cos(th), y + 30 * sin(th));
    }

    glEnd();

}
void bwheel(int x, int y)
{
    float th;
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    for (int i = 0; i < 360; i++)
    {
        th = i * (3.1416 / 180);
        glVertex2f(x + 37 * cos(th), y + 40 * sin(th));
    }

    glEnd();

}
void whitewheel(int x, int y)
{
    float th;
    glBegin(GL_POLYGON);
    glColor3f(0.86, 0.86, 0.86);
    for (int i = 0; i < 360; i++)
    {
        th = i * (3.1416 / 180);
        glVertex2f(x + 15 * cos(th), y + 15 * sin(th));
    }

    glEnd();

}
void bwhitewheel(int x, int y)
{
    float th;
    glBegin(GL_POLYGON);
    glColor3f(0.86, 0.86, 0.86);
    for (int i = 0; i < 360; i++)
    {
        th = i * (3.1416 / 180);
        glVertex2f(x + 21 * cos(th), y + 21 * sin(th));
    }

    glEnd();

}
int state1 = 1;
float xd1 = 0, yd1 = 0;
float counter = 10, ycounter = 0, counter1 = 10, ycounter1 = 0, counter2 = 10, ycounter2 = 0;
float counter3 = 10, ycounter3 = 0;

void firstScreen() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.41, 0.63, 0.95,0);

 
    
    glBegin(GL_POLYGON);    //BACKGROUND COLORS
    glColor3f(0.4, 0.69, 0.86);
    glVertex2i(-1200, -700);
    glColor3f(0.94, 0.77, 1);
    glVertex2i(-1200, 700);
    glColor3f(0.94, 0.77, 1);
    glVertex2i(1200, 700);
    glColor3f(0.4, 0.69, 0.86);
    glVertex2i(1200, -700);
    glEnd();


    glColor3f(0.21, 0.34, 0.82);
    displayRasterText(-150, 550, 0.0, "DATA COLLECTION");

    glLoadIdentity();
    
    
    ycounter = ycounter - 0.35;
    if (ycounter < -450)
    {
        counter = counter + 1;
        ycounter = -450;
       if (counter >830)
        {
         counter = 830;
        }

    }
        glTranslated(counter, ycounter, 0);
    
    int shift = -100, shiftdown = 800;
    wheel(-870 + shift+xd1, -545 + shiftdown+yd1);  //wheel

    glColor3f(0.88, 0.88, 0.88); //Truck tail
    glBegin(GL_POLYGON);
    glVertex2f(-930 + shift+xd1, -550 + shiftdown+yd1);
    glVertex2f(-930 + shift+xd1, -400 + shiftdown+yd1);
    glVertex2f(-630 + shift+xd1, -400 + shiftdown+yd1);
    glVertex2f(-630 + shift+xd1, -550 + shiftdown+yd1);
    glEnd();                                     
                                                 
    glColor3f(0.8, 0.8, 0.8); //Truck tail   
    glBegin(GL_POLYGON);                         
    glVertex2f(-930 + shift+xd1, -550 + shiftdown+yd1);
    glVertex2f(-930 + shift+xd1, -400 + shiftdown+yd1);
    glVertex2f(-830 + shift+xd1, -400 + shiftdown+yd1);
    glVertex2f(-830 + shift+xd1, -550 + shiftdown+yd1);
    glEnd();

    glColor3f(0.43, 0.43, 0.43); //Truck tail
    glBegin(GL_POLYGON);
    glVertex2f(-930 + shift+xd1, -550 + shiftdown+yd1);
    glVertex2f(-930 + shift+xd1, -450 + shiftdown+yd1);
    glVertex2f(-830 + shift+xd1, -450 + shiftdown+yd1);
    glVertex2f(-830 + shift+xd1, -550 + shiftdown+yd1);
    glEnd();                                    
                                                
    glColor3f(1, 0.36, 0.07); //Truck head      
    glBegin(GL_POLYGON);                        
    glVertex2f(-630 + shift+xd1, -550 + shiftdown+yd1);
    glVertex2f(-630 + shift+xd1, -430 + shiftdown+yd1);
    glVertex2f(-570 + shift+xd1, -430 + shiftdown+yd1);
    glVertex2f(-530 + shift+xd1, -470 + shiftdown+yd1);
    glVertex2f(-530 + shift+xd1, -550 + shiftdown+yd1);
    glEnd();

    glColor3f(0.42, 0.7, 0.81); //Truck glass
    glBegin(GL_POLYGON);
    glVertex2f(-620 + shift+xd1, -500 + shiftdown+yd1);
    glVertex2f(-620 + shift+xd1, -445 + shiftdown+yd1);
    glVertex2f(-580 + shift+xd1, -445 + shiftdown+yd1);
    glVertex2f(-545 + shift+xd1, -480 + shiftdown+yd1);
    glVertex2f(-545 + shift+xd1, -500 + shiftdown+yd1);
    glEnd();

         wheel(-590 + shift+xd1, -553 + shiftdown+yd1);
    whitewheel(-590 + shift+xd1, -553 + shiftdown+yd1);
         wheel(-690 + shift+xd1, -553 + shiftdown+yd1);
    whitewheel(-690 + shift+xd1, -553 + shiftdown+yd1);
         wheel(-790 + shift+xd1, -553 + shiftdown+yd1);
    whitewheel(-790 + shift+xd1, -553 + shiftdown+yd1);

    glColor3f(0, 0.12, 0.7);
    displayRasterText(-770 + shift+xd1, -490 + shiftdown+yd1, 0.0, "TATA");
    
    glutPostRedisplay();
   
    glLoadIdentity();

    glLoadIdentity();
  
    ycounter1 = ycounter1 - 1;
    if (ycounter1 < -450)
    {
        
        counter1 = counter1 + 1;
        ycounter1 = -450;
        if (counter1 >330 )
        {
            counter1 = 330;
        }

    }
    glTranslated(counter1, ycounter1, 0);
    int shift2 = 400, shiftup2 = 550;
    int shift3 = 200, shiftup3 = 809;
    
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(-950 + shift2, -270 + shiftup2);
    glVertex2f(-955 + shift2, -240 + shiftup2);
    glVertex2f(-940 + shift2, -240 + shiftup2);
    glVertex2f(-940 + shift2, -270 + shiftup2);
    glEnd();
    glColor3f(0.58, 0.06, 0.03); //CAR
    glBegin(GL_POLYGON);
    glVertex2f(-930 + shift2, -300 + shiftup2);
    glVertex2f(-950 + shift2, -230 + shiftup2);
    glVertex2f(-800 + shift2, -230 + shiftup2);
    glVertex2f(-780 + shift2, -180 + shiftup2);
    glVertex2f(-660 + shift2, -180 + shiftup2);
    glVertex2f(-580 + shift2, -230 + shiftup2);
    glVertex2f(-500 + shift2, -230 + shiftup2);
    glVertex2f(-520 + shift2, -300 + shiftup2);
    glEnd();


    bwheel(-600 + shift2, -300 + shiftup2);
    bwhitewheel(-600 + shift2, -300 + shiftup2);
    bwheel(-860 + shift2, -300 + shiftup2);
    bwhitewheel(-860 + shift2, -300 + shiftup2);
    


    glColor3f(0.42, 0.7, 0.81); //car glass
    glBegin(GL_POLYGON);
    glVertex2f(-545 + shift3, -490 + shiftup3);
    glVertex2f(-545 + shift3, -445 + shiftup3);
    glVertex2f(-580 + shift3, -445 + shiftup3);
    glVertex2f(-620 + shift3, -480 + shiftup3);
    glVertex2f(-620 + shift3, -490 + shiftup3);
    glEnd();
    glLoadIdentity();
    glLoadIdentity();

    ycounter2 = ycounter2 - 1;
    if (ycounter2 < -470)
    {

        counter2 = counter2 - 0.5;
        ycounter2 = -470;
        if (counter2 < -200)
        {
            counter2 = -200;
        }

    }
    glTranslated(counter2, ycounter2, 0);
    int shift4 = 950, shiftdown4 = 800;
    wheel(-870 + shift4, -545 + shiftdown4);  //wheel

    glColor3f(1, 0.36, 0.071); //Truck tail
    glBegin(GL_POLYGON);
    glVertex2f(-930 + shift4, -550 + shiftdown4);
    glVertex2f(-930 + shift4, -400 + shiftdown4);
    glVertex2f(-630 + shift4, -400 + shiftdown4);
    glVertex2f(-630 + shift4, -550 + shiftdown4);
    glEnd();

    glColor3f(0.82, 0.29, 0.05); //Truck tail
    glBegin(GL_POLYGON);
    glVertex2f(-930 + shift4, -550 + shiftdown4);
    glVertex2f(-930 + shift4, -400 + shiftdown4);
    glVertex2f(-830 + shift4, -400 + shiftdown4);
    glVertex2f(-830 + shift4, -550 + shiftdown4);
    glEnd();

    glColor3f(0.43, 0.43, 0.43); //Truck tail
    glBegin(GL_POLYGON);
    glVertex2f(-930 + shift4, -550 + shiftdown4);
    glVertex2f(-930 + shift4, -450 + shiftdown4);
    glVertex2f(-830 + shift4, -450 + shiftdown4);
    glVertex2f(-830 + shift4, -550 + shiftdown4);
    glEnd();

    glColor3f(0.43, 0.43, 0.43); //Truck head
    glBegin(GL_POLYGON);
    glVertex2f(-630 + shift4, -550 + shiftdown4);
    glVertex2f(-630 + shift4, -430 + shiftdown4);
    glVertex2f(-570 + shift4, -430 + shiftdown4);
    glVertex2f(-530 + shift4, -470 + shiftdown4);
    glVertex2f(-530 + shift4, -550 + shiftdown4);
    glEnd();

    glColor3f(0.42, 0.7, 0.81); //Truck glass
    glBegin(GL_POLYGON);
    glVertex2f(-620 + shift4, -500 + shiftdown4);
    glVertex2f(-620 + shift4, -445 + shiftdown4);
    glVertex2f(-580 + shift4, -445 + shiftdown4);
    glVertex2f(-545 + shift4, -480 + shiftdown4);
    glVertex2f(-545 + shift4, -500 + shiftdown4);
    glEnd();

    wheel(-590 + shift4, -553 + shiftdown4);
    whitewheel(-590 + shift4, -553 + shiftdown4);
    wheel(-690 + shift4, -553 + shiftdown4);
    whitewheel(-690 + shift4, -553 + shiftdown4);
    wheel(-790 + shift4, -553 + shiftdown4);
    whitewheel(-790 + shift4, -553 + shiftdown4);

    glColor3f(1, 1, 1);
    displayRasterText(-790 + shift4, -490 + shiftdown4, 0.0, "EICHER");
    glLoadIdentity();

    glLoadIdentity();
    ycounter3 = ycounter3 - 0.35;
    if (ycounter3 < -450)
    {
        counter3 = counter3 - 1;
        ycounter3 = -450;
        if (counter3 < -740)
        {
            counter3 = -740;
        }

    }
    glTranslated(counter3, ycounter3, 0);
    int shift5 = 1480, shiftup5 = 550;
    glColor3f(1, 0.88, 0.38); //CAR
    glBegin(GL_POLYGON);
    glVertex2f(-930 + shift5, -300 + shiftup5);
    glVertex2f(-950 + shift5, -230 + shiftup5);
    glVertex2f(-800 + shift5, -230 + shiftup5);
    glVertex2f(-780 + shift5, -180 + shiftup5);
    glVertex2f(-660 + shift5, -180 + shiftup5);
    glVertex2f(-580 + shift5, -230 + shiftup5);
    glVertex2f(-500 + shift5, -230 + shiftup5);
    glVertex2f(-520 + shift5, -300 + shiftup5);
    glEnd();


    bwheel(-600 + shift5, -300 + shiftup5);
    bwhitewheel(-600 + shift5, -300 + shiftup5);
    bwheel(-860 + shift5, -300 + shiftup5);
    bwhitewheel(-860 + shift5, -300 + shiftup5);


    int shift6 = 1280, shiftup6 = 809;
    glColor3f(0.42, 0.7, 0.81); //car glass
    glBegin(GL_POLYGON);
    glVertex2f(-545 + shift6, -490 + shiftup6);
    glVertex2f(-545 + shift6, -445 + shiftup6);
    glVertex2f(-580 + shift6, -445 + shiftup6);
    glVertex2f(-620 + shift6, -480 + shiftup6);
    glVertex2f(-620 + shift6, -490 + shiftup6);
    glEnd();
    glLoadIdentity();

    int shift1=800,shiftup1=300;

    glColor3f(0.72, 0.59, 0.34); //FILE- OPEN
    glBegin(GL_POLYGON);
    glVertex2f(-1030+ shift1, -350 + shiftup1);
    glVertex2f(-1030+ shift1, -300 + shiftup1);
    glVertex2f(-805 + shift1, -300 + shiftup1);
    glVertex2f(-800 + shift1, -350 + shiftup1);
    glEnd();

    glColor3f(1, 0.8, 0.43); //FILE
    glBegin(GL_POLYGON);
    glVertex2f(-1030 + shift1, -630 + shiftup1);
    glVertex2f(-1030 + shift1, -350 + shiftup1);
    glVertex2f(-800 + shift1, -350 + shiftup1);
    glVertex2f(-800 + shift1, -320 + shiftup1);
    glVertex2f(-550 + shift1, -320 + shiftup1);
    glVertex2f(-550 + shift1, -350 + shiftup1);
    glVertex2f(-550 + shift1, -630+ shiftup1);
    glEnd();
    glColor3f(0.21, 0.34, 0.82); //FILE - BOTTOM
    glBegin(GL_POLYGON);
    glVertex2f(-890 + shift1, -598 + shiftup1);
    glVertex2f(-890 + shift1, -540 + shiftup1);
    glVertex2f(-690 + shift1, -540 + shiftup1);
    glVertex2f(-690 + shift1, -598 + shiftup1);
    glEnd();
    
    glColor3f(1,1,1);
    displayRasterText(-62, -370, 0.0, "VEHICLE");
    glColor3f(0.03, 0.15, 0.57);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(-860 + shift1, -260);
    glVertex2f(-720 + shift1, -260);
    glEnd();

    glColor3f(1.0, 0, 0);
    displayRasterText(-225, -450, 0.0, "PRESS KEY Q TO CONTINUE");
    glFlush();
    glutSwapBuffers();
}
int state = 1;
float xr = 0, yr = 0.0;
float xr1 = 0, yr1 = 0.0;
float xr2 = 0, yr2 = 0;
float xr3 = 0, yr3 = 0;
float xr4 = 0, yr4 = 0;
void aot3(int value) { //EICHER

    xr3 = xr3 + 7.0;

    if (xr3 < 500)
        yr3 = yr3 - 0.5;
    if (xr3 > 1500)
    {
        state = -1;
        switch (state)
        {
        case -1:

            xr3 = 1572;
            break;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(50, aot3, 0);
}
 void aot2(int value) { //CAR
     
        xr2 = xr2 + 7.0;
        
        if (xr2 < 500)
            yr2 = yr2 - 0.5;
        if (xr2 > 1500)
        {
            state = -1;
            switch (state)
            {
            case -1:

                xr2 = 1572;
                break;
            }
        }
        glutPostRedisplay();
        glutTimerFunc(50, aot2, 0);
}
 void aot(int value) { //TATA

     xr = xr + 7.0;

     if (xr <1500)
         yr = yr + 0.8;
     if (xr > 1500)
     {
         state = -1;
         switch (state)
         {
         case -1:

             xr = 1572;
             break;
         }
     }
     glutPostRedisplay();
     glutTimerFunc(50, aot, 0);
 }
 void aot1(int value) { //CAR

     xr4= xr4 + 7.0;
     
     if (xr4 < 500)
         yr4 = yr4 +0.5;
     if (xr4 >1500)
     {
         state = -1;
         switch (state)
         {
         case -1:
             
             xr4 = 1578;
             break;
         }
     }
     glutPostRedisplay();
     glutTimerFunc(50, aot1, 0);
 }
void specialkey(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP:  aot3(147);
        glutTimerFunc(1000 / 60, aot3, 0);
     //   if (xr1 > 500)
       //     yr1 = yr1 - 7.0;
        break;
    case GLUT_KEY_DOWN: aot1(147);
        glutTimerFunc(1000 / 60, aot1, 0);
        break;
        
    case GLUT_KEY_LEFT:
        
            aot(147);
            glutTimerFunc(1000 / 60, aot, 0);
        break;
    case GLUT_KEY_RIGHT:
        aot2(147);
        glutTimerFunc(1000 / 60, aot2, 0);
        break;
            
    }
}
void secondScreen()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.41, 0.63, 0.95, 0);

    glBegin(GL_POLYGON);    //BACKGROUND COLORS
    glColor3f(0.4, 0.69, 0.86);
    glVertex2i(-1200, -700);
    glColor3f(0.94, 0.77, 1);
    glVertex2i(-1200, 700);
    glColor3f(0.94, 0.77, 1);
    glVertex2i(1200, 700);
    glColor3f(0.4, 0.69, 0.86);
    glVertex2i(1200, -700);
    glEnd();

    //clouds
    drawClouds(550, 450);
    drawClouds(-350, 550);
    drawClouds(950, 450);
    drawClouds(-850, 550);
    glLineWidth(4);
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_LOOP);                                //Monitor line1
    glVertex2f(-200+20, 0);
    glVertex2f(-200+20, 350);
    glVertex2f(200+20, 350);
    glVertex2f(200+20, 0);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_LINES);                                //Monitor line1
    glVertex2f(-100, -20);
    glVertex2f(130, -20);
    glEnd();


    int shift = 050, shiftdown = 550;
    wheel(-870 + shift+xr, -545 + shiftdown + yr);  //wheel

    glColor3f(0.88, 0.88, 0.88); //Truck tail TATA
    glBegin(GL_POLYGON);
    glVertex2f(-930 + shift+xr, -550 + shiftdown + yr);
    glVertex2f(-930 + shift + xr, -400 + shiftdown + yr);
    glVertex2f(-630 + shift + xr, -400 + shiftdown + yr);
    glVertex2f(-630 + shift + xr, -550 + shiftdown + yr);
    glEnd();

    glColor3f(0.8, 0.8, 0.8); //Truck tail TATA
    glBegin(GL_POLYGON);
    glVertex2f(-930 + shift + xr, -550 + shiftdown+yr);
    glVertex2f(-930 + shift + xr, -400 + shiftdown + yr);
    glVertex2f(-830 + shift + xr, -400 + shiftdown + yr);
    glVertex2f(-830 + shift + xr, -550 + shiftdown + yr);
    glEnd();

    glColor3f(0.43, 0.43, 0.43); //Truck tail  TATA
    glBegin(GL_POLYGON);
    glVertex2f(-930 + shift + xr, -550 + shiftdown + yr);
    glVertex2f(-930 + shift + xr, -450 + shiftdown + yr);
    glVertex2f(-830 + shift + xr, -450 + shiftdown + yr);
    glVertex2f(-830 + shift + xr, -550 + shiftdown + yr);
    glEnd();

    glColor3f(1, 0.36, 0.07); //Truck head TATA
    glBegin(GL_POLYGON);
    glVertex2f(-630 + shift + xr, -550 + shiftdown + yr);
    glVertex2f(-630 + shift + xr, -430 + shiftdown + yr);
    glVertex2f(-570 + shift + xr, -430 + shiftdown + yr);
    glVertex2f(-530 + shift + xr, -470 + shiftdown + yr);
    glVertex2f(-530 + shift + xr, -550 + shiftdown + yr);
    glEnd();

    glColor3f(0.42, 0.7, 0.81); //Truck glass TATA
    glBegin(GL_POLYGON);
    glVertex2f(-620 + shift + xr, -500 + shiftdown + yr);
    glVertex2f(-620 + shift + xr, -445 + shiftdown + yr);
    glVertex2f(-580 + shift+xr, -445 + shiftdown + yr);
    glVertex2f(-545 + shift+xr, -480 + shiftdown + yr);
    glVertex2f(-545 + shift+xr, -500 + shiftdown + yr);
    glEnd();

    wheel(-590 + shift + xr, -553 + shiftdown + yr);
    whitewheel(-590 + shift + xr, -553 + shiftdown + yr);
    wheel(-690 + shift + xr, -553 + shiftdown + yr);
    whitewheel(-690 + shift + xr, -553 + shiftdown + yr);
    wheel(-790 + shift + xr, -553 + shiftdown + yr);
    whitewheel(-790 + shift + xr, -553 + shiftdown + yr);

    glColor3f(0, 0.12, 0.7);
    displayRasterText(-770 + shift + xr, -490 + shiftdown + yr, 0.0, "TATA");
 
 
    int shift4 = 35, shiftup4 = 70;
    int shift3 = -40, shiftup3 =330;
    int shift41 = 400, shiftup41 = 45;

    glColor3f(1, 1, 1);

    glBegin(GL_POLYGON);                            //CAR - HEADLIGHT
    glVertex2f(-950 + shift41 + xr2, -270 + shiftup41+yr2);
    glVertex2f(-945 + shift41 + xr2, -240 + shiftup41+yr2);
    glVertex2f(-930 + shift41 + xr2, -240 + shiftup41+yr2);
    glVertex2f(-940 + shift41 + xr2, -270 + shiftup41+yr2);
    glEnd();
 
    glColor3f(0.58, 0.06, 0.03); // RED - CAR
    glBegin(GL_POLYGON);
    glVertex2f(-930 + shift4+xr2,-300 + shiftup4+yr2);
    glVertex2f(-950 + shift4+xr2,-230 + shiftup4+yr2);
    glVertex2f(-800 + shift4+xr2,-230 + shiftup4+yr2);
    glVertex2f(-780 + shift4+xr2,-180 + shiftup4+yr2);
    glVertex2f(-670 + shift4+xr2,-180 + shiftup4+yr2);
    glVertex2f(-580 + shift4+xr2,-230 + shiftup4+yr2);
    glVertex2f(-500 + shift4+xr2,-230 + shiftup4+yr2);
    glVertex2f(-520 + shift4+xr2,-300 + shiftup4+yr2);
    glEnd();                   


         bwheel(-600 + shift4+xr2, -300 + shiftup4+yr2);
    bwhitewheel(-600 + shift4+xr2, -300 + shiftup4+yr2);
         bwheel(-860 + shift4+xr2, -300 + shiftup4+yr2);
    bwhitewheel(-860 + shift4+xr2, -300 + shiftup4+yr2);

    glColor3f(0.42, 0.7, 0.81); //car glass
    glBegin(GL_POLYGON);
    glVertex2f(-620 + shift3 + xr2, -490 + shiftup3+yr2);
    glVertex2f(-620 + shift3 + xr2, -450 + shiftup3+yr2);
    glVertex2f(-590 + shift3 + xr2, -450 + shiftup3+yr2);
    glVertex2f(-545 + shift3 + xr2, -477 + shiftup3+yr2);
    glVertex2f(-545 + shift3 + xr2, -490 + shiftup3+yr2);
    glEnd();

    int shift5 = 50, shiftdown5 = 790;
    wheel(-870 + shift5+xr3, -545 + shiftdown5 + yr3);  //wheel

    glColor3f(1, 0.36, 0.071); //Truck tail
    glBegin(GL_POLYGON);
        glVertex2f(-930 + shift5+xr3, -550 + shiftdown5+yr3);
    glVertex2f(-930 + shift5 + xr3, -400 + shiftdown5 + yr3);
    glVertex2f(-630 + shift5 + xr3, -400 + shiftdown5 + yr3);
    glVertex2f(-630 + shift5 + xr3, -550 + shiftdown5 + yr3);
    glEnd();

    glColor3f(0.82, 0.29, 0.05); //Truck tail
    glBegin(GL_POLYGON);
    glVertex2f(-930 + shift5 + xr3, -550 + shiftdown5 + yr3);
    glVertex2f(-930 + shift5 + xr3, -400 + shiftdown5 + yr3);
    glVertex2f(-830 + shift5 + xr3, -400 + shiftdown5 + yr3);
    glVertex2f(-830 + shift5 + xr3, -550 + shiftdown5 + yr3);
    glEnd();

    glColor3f(0.43, 0.43, 0.43); //Truck tail
    glBegin(GL_POLYGON);
    glVertex2f(-930 + shift5 + xr3, -550 + shiftdown5 + yr3);
    glVertex2f(-930 + shift5 + xr3, -450 + shiftdown5 + yr3);
    glVertex2f(-830 + shift5 + xr3, -450 + shiftdown5 + yr3);
    glVertex2f(-830 + shift5 + xr3, -550 + shiftdown5 + yr3);
    glEnd();

    glColor3f(0.43, 0.43, 0.43); //Truck head
    glBegin(GL_POLYGON);
    glVertex2f(-630 + shift5 + xr3, -550 + shiftdown5 + yr3);
    glVertex2f(-630 + shift5 + xr3, -430 + shiftdown5 + yr3);
    glVertex2f(-570 + shift5 + xr3, -430 + shiftdown5 + yr3);
    glVertex2f(-530 + shift5 + xr3, -470 + shiftdown5 + yr3);
    glVertex2f(-530 + shift5 + xr3, -550 + shiftdown5 + yr3);
    glEnd();                                             
                                                         
    glColor3f(0.42, 0.7, 0.81); //Truck glass            
    glBegin(GL_POLYGON);                                 
    glVertex2f(-620 + shift5 + xr3, -500 + shiftdown5 + yr3);
    glVertex2f(-620 + shift5 + xr3, -445 + shiftdown5 + yr3);
    glVertex2f(-580 + shift5 + xr3, -445 + shiftdown5 + yr3);
    glVertex2f(-545 + shift5 + xr3, -480 + shiftdown5 + yr3);
    glVertex2f(-545 + shift5 + xr3, -500 + shiftdown5 + yr3);
    glEnd();

         wheel(-590 + shift5 + xr3, -553 + shiftdown5 + yr3);
    whitewheel(-590 + shift5 + xr3, -553 + shiftdown5 + yr3);
         wheel(-690 + shift5 + xr3, -553 + shiftdown5 + yr3);
    whitewheel(-690 + shift5 + xr3, -553 + shiftdown5 + yr3);
         wheel(-790 + shift5 + xr3, -553 + shiftdown5 + yr3);
    whitewheel(-790 + shift5 + xr3, -553 + shiftdown5 + yr3);

    glColor3f(1, 1, 1);
    displayRasterText(-790 + shift5 + xr3, -490 + shiftdown5 + yr3, 0.0, "EICHER");


    int shift6 = 30, shiftup6 = -120;
    int h = 395, hup = -170;
    glColor3f(1, 1, 1);
    glPushMatrix();
    glRotatef(30, 0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-950 + h+xr4, -270 + hup+yr4);
    glVertex2f(-945 + h+xr4, -240 + hup+yr4);
    glVertex2f(-930 + h+xr4, -240 + hup+yr4);
    glVertex2f(-940 + h+xr4, -270 + hup+yr4);
    glEnd();
    glPopMatrix();
    glColor3f(1,1,0); //CAR-YELLOW
    glBegin(GL_POLYGON);
    glVertex2f(-930 + shift6+xr4, -300 + shiftup6+yr4);
    glVertex2f(-950 + shift6+xr4, -230 + shiftup6+yr4);
    glVertex2f(-800 + shift6+xr4, -230 + shiftup6+yr4);
    glVertex2f(-780 + shift6+xr4, -180 + shiftup6+yr4);
    glVertex2f(-670 + shift6+xr4, -180 + shiftup6+yr4);
    glVertex2f(-580 + shift6+xr4, -230 + shiftup6+yr4);
    glVertex2f(-500 + shift6+xr4, -230 + shiftup6+yr4);
    glVertex2f(-520 + shift6+xr4, -300 + shiftup6+yr4);
    glEnd();


         bwheel(-600 + shift6+xr4, -300 + shiftup6+yr4);
    bwhitewheel(-600 + shift6+xr4, -300 + shiftup6+yr4);
         bwheel(-860 + shift6+xr4,-300 + shiftup6+yr4);
    bwhitewheel(-860 + shift6+xr4, -300 + shiftup6+yr4);
                                              

    int shiftg = -45, shifg = 140;

    glColor3f(0.42, 0.7, 0.81); //car glass
    glBegin(GL_POLYGON);
    glVertex2f(-620 + shiftg+xr4, -490 + shifg+yr4);
    glVertex2f(-620 + shiftg+xr4, -450 + shifg+yr4);
    glVertex2f(-590 + shiftg+xr4, -450 + shifg+yr4);
    glVertex2f(-545 + shiftg+xr4, -477 + shifg+yr4);
    glVertex2f(-545 + shiftg+xr4, -490 + shifg+yr4);
    glEnd();

    int shift1 = 1680, shiftup1 = 200;

    glColor3f(0.72, 0.59, 0.34); //FILE- OPEN
    glBegin(GL_POLYGON);
    glVertex2f(-1020 + shift1, -350 + shiftup1);
    glVertex2f(-1020 + shift1, -300 + shiftup1);
    glVertex2f(-805 + shift1, -300 + shiftup1);
    glVertex2f(-800 + shift1, -350 + shiftup1);
    glEnd();

    glColor3f(1, 0.8, 0.43); //FILE
    glBegin(GL_POLYGON);
    glVertex2f(-1020 + shift1, -630 + shiftup1);
    glVertex2f(-1020 + shift1, -350 + shiftup1);
    glVertex2f(-840 + shift1, -350 + shiftup1);
    glVertex2f(-840 + shift1, -320 + shiftup1);
    glVertex2f(-575 + shift1, -320 + shiftup1);
    glVertex2f(-575 + shift1, -350 + shiftup1);
    glVertex2f(-575 + shift1, -630 + shiftup1);
    glEnd();
    glColor3f(0.21, 0.34, 0.82); //FILE - BOTTOM
    glBegin(GL_POLYGON);
    glVertex2f(-900 + shift1, -598 + shiftup1);
    glVertex2f(-900 + shift1, -540 + shiftup1);
    glVertex2f(-690 + shift1, -540 + shiftup1);
    glVertex2f(-690 + shift1, -598 + shiftup1);
    glEnd();

    int shift2 = 1650, shiftup2 = 750;

    glColor3f(0.72, 0.59, 0.34); //FILE- OPEN
    glBegin(GL_POLYGON);
    glVertex2f(-990 + shift2, -350 + shiftup2);
    glVertex2f(-990 + shift2, -300 + shiftup2);
    glVertex2f(-770 + shift2, -300 + shiftup2);
    glVertex2f(-770 + shift2, -350 + shiftup2);
    glEnd();

    glColor3f(1, 0.8, 0.43); //FILE
    glBegin(GL_POLYGON);
    glVertex2f(-990 + shift2, -630 + shiftup2);
    glVertex2f(-990 + shift2, -350 + shiftup2);
    glVertex2f(-810 + shift2, -350 + shiftup2);
    glVertex2f(-810 + shift2, -320 + shiftup2);
    glVertex2f(-540 + shift2, -320 + shiftup2);
    glVertex2f(-540 + shift2, -350 + shiftup2);
    glVertex2f(-540 + shift2, -630 + shiftup2);
    glEnd();
    glColor3f(0.21, 0.34, 0.82); //FILE - BOTTOM
    glBegin(GL_POLYGON);
    glVertex2f(-850 + shift2, -598 + shiftup2);
    glVertex2f(-850 + shift2, -540 + shiftup2);
    glVertex2f(-690 + shift2, -540 + shiftup2);
    glVertex2f(-690 + shift2, -598 + shiftup2);
    glEnd();

    glColor3f(0.21, 0.34, 0.82);
    displayRasterText(-185, 550, 0.0, "DATA PRE-PROCESSING");
    glColor3f(1.0, 0, 0);
    displayRasterText(-220, -600, 0.0, "PRESS KEY W TO CONTINUE");
    glColor3f(1, 0.8, 0.43);
    displayRasterText(850, 170, 0.0, " truck");
    glColor3f(1, 0.8, 0.43);
    displayRasterText(800, -380, 0.0, "     car");

    glFlush();
    glutSwapBuffers();
    glutPostRedisplay();
 

}



void thirdScreen() {

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0, 0);
    displayRasterText(-950, 500, 0.0, "DATA COLLECTION IS THE PROCESS OF GATHERING AND MEASURING INFORMATION .");


    glColor3f(1.0, 0, 0);
    displayRasterText(-950, 400, 0.0, "TO DEVELOP PRACTICAL AI AND MACHINE LEARNING APPLICATIONS, COLLECTION OF DATA IS THE BASIC STEP.");

    glColor3f(1.0, 0, 0);
    displayRasterText(-950, 150, 0.0, "DATA  PREPROCESSING  IS  A  TECHNIQUE  USED  TO  CONVERT   RAW  DATA  INTO A  CLEAN  DATA SET, IT IS A");

    glColor3f(1.0, 0, 0);
    displayRasterText(-950, 50, 0.0, "STEP  IN THE  DATA  MINING  AND  DATA  ANALYSIS  PROCESS  THAT  TAKES  RAW  DATA AND  TRANSFORMS IT");
    glColor3f(1.0, 0, 0);
    displayRasterText(-950, -50, 0.0, "INTO  A  FORMAT  THAT  CAN BE  UNDERSTOOD  AND  ANALYZED  BY  COMPUTERS");
    glColor3f(1.0, 0, 0);
    displayRasterText(-275, -550, 0.0, "PRESS KEY E TO CONTINUE");


    glFlush();
    glutSwapBuffers();




}
void bigwheel(int x,int y) {
    float th;
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    for (int i = 0; i < 360; i++)
    {
        th = i * (3.1416 / 180);
        glVertex2f(x + 75 * cos(th), y + 75 * sin(th));
    }

    glEnd();

}
void fwhitewheel(int x, int y)
{
    float th;
    glBegin(GL_POLYGON);
    glColor3f(0.86, 0.86, 0.86);
    for (int i = 0; i < 360; i++)
    {
        th = i * (3.1416 / 180);
        glVertex2f(x + 30 * cos(th), y + 30 * sin(th));
    }

    glEnd();

}

void fourthScreen()
{
    //sky background
    glColor3f(0.4, 0.7, 1);
    glBegin(GL_POLYGON);
    glVertex2i(-1200, 700);
    glVertex2i(1200, 700);
    glVertex2i(1200, -700);
    glVertex2i(-1200, -700);
    glEnd();


    //clouds
    drawClouds(550, 450);
    drawClouds(-350, 550);
    drawClouds(950, 450);
    drawClouds(-850, 550);


    int shift4 = 350, shiftdown4 = 650;
    wheel(-870 + shift4, -545 + shiftdown4);  //wheel

    glColor3f(1, 0.36, 0.071); //Truck MAIN CONTAINER
    glBegin(GL_POLYGON);
    glVertex2f(-930+shift4 , -550 + shiftdown4);
    glVertex2f(-930 + shift4, -400 + shiftdown4);
    glVertex2f(-630 + shift4, -400 + shiftdown4);
    glVertex2f(-630 + shift4, -550 + shiftdown4);
    glEnd();

    glColor3f(0.82, 0.29, 0.05); //Truck tail dark orange
    glBegin(GL_POLYGON);
    glVertex2f(-930 + shift4, -550 + shiftdown4);
    glVertex2f(-930 + shift4, -400 + shiftdown4);
    glVertex2f(-830 + shift4, -400 + shiftdown4);
    glVertex2f(-830 + shift4, -550 + shiftdown4);
    glEnd();

    glColor3f(0.43, 0.43, 0.43); //Truck tail GREY
    glBegin(GL_POLYGON);
    glVertex2f(-930 + shift4, -550 + shiftdown4);
    glVertex2f(-930 + shift4, -450 + shiftdown4);
    glVertex2f(-830 + shift4, -450 + shiftdown4);
    glVertex2f(-830 + shift4, -550 + shiftdown4);
    glEnd();

    glColor3f(0.43, 0.43, 0.43); //Truck head
    glBegin(GL_POLYGON);
    glVertex2f(-630 + shift4, -550 + shiftdown4);
    glVertex2f(-630 + shift4, -430 + shiftdown4);
    glVertex2f(-570 + shift4, -430 + shiftdown4);
    glVertex2f(-530 + shift4, -470 + shiftdown4);
    glVertex2f(-530 + shift4, -550 + shiftdown4);
    glEnd();

    glColor3f(0.42, 0.7, 0.81); //Truck glass
    glBegin(GL_POLYGON);
    glVertex2f(-620 + shift4, -500 + shiftdown4);
    glVertex2f(-620 + shift4, -445 + shiftdown4);
    glVertex2f(-580 + shift4, -445 + shiftdown4);
    glVertex2f(-545 + shift4, -480 + shiftdown4);
    glVertex2f(-545 + shift4, -500 + shiftdown4);
    glEnd();

    wheel(-590 + shift4, -553 + shiftdown4);
    whitewheel(-590 + shift4, -553 + shiftdown4);
    wheel(-690 + shift4, -553 + shiftdown4);
    whitewheel(-690 + shift4, -553 + shiftdown4);
    wheel(-790 + shift4, -553 + shiftdown4);
    whitewheel(-790 + shift4, -553 + shiftdown4);

    glColor3f(1, 1, 1);
    displayRasterText(-790 + shift4, -490 + shiftdown4, 0.0, "EICHER");

    int shead = 900, headd = 750;
    glColor3f(0.43, 0.43, 0.43); //Truck head
    glBegin(GL_POLYGON);
    glVertex2f(-630 + shead, -550 + headd);
    glVertex2f(-630 + shead, -430 + headd);
    glVertex2f(-570 + shead, -430 + headd);
    glVertex2f(-530 + shead, -470 + headd);
    glVertex2f(-530 + shead, -550 + headd);
    glEnd();

    glColor3f(0.42, 0.7, 0.81); //Truck glass
    glBegin(GL_POLYGON);
    glVertex2f(-620 + shead, -500 + headd);
    glVertex2f(-620 + shead, -445 + headd);
    glVertex2f(-580 + shead, -445 + headd);
    glVertex2f(-545 + shead, -480 + headd);
    glVertex2f(-545 + shead, -500 + headd);
    glEnd();

    glColor3f(1, 0.36, 0.071); //Truck MAIN CONTAINER
    glBegin(GL_POLYGON);
    glVertex2f(-930 + shead+300, -550 + headd-200);
    glVertex2f(-930 + shead+300, -400 + headd-200);
    glVertex2f(-630 + shead+300, -400 + headd-200);
    glVertex2f(-630 + shead+300, -550 + headd-200);
    glEnd();
    glColor3f(0.82, 0.29, 0.05); //Truck tail dark orange
    glBegin(GL_POLYGON);
    glVertex2f(-930 + shead+300, -550 + headd-200);
    glVertex2f(-930 + shead+300, -400 + headd-200);
    glVertex2f(-830 + shead+300, -400 + headd-200);
    glVertex2f(-830 + shead+300, -550 + headd-200);
    glEnd();

    glColor3f(0.43, 0.43, 0.43); //Truck tail GREY
    glBegin(GL_POLYGON);
    glVertex2f(-930 + shead + 300, -550 + headd - 200);
    glVertex2f(-930 + shead + 300, -450 + headd - 200);
    glVertex2f(-830 + shead + 300, -450 + headd - 200);
    glVertex2f(-830 + shead + 300, -550 + headd-200);
    glEnd();
    glColor3f(1, 1, 1);
    displayRasterText(-790 + shead+300, -490 + headd-200, 0.0, "EICHER");

    glColor3f(1,1,1); //     ARROW MARK
    glBegin(GL_POLYGON);
    glVertex2f(-980 + shead , -620 + headd );
    glVertex2f(-980 + shead , -570 + headd );
    glVertex2f(-810 + shead, -570 + headd);
    glVertex2f(-810 + shead, -620 + headd);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(-810 + shead, -640 + headd);
    glVertex2f(-810 + shead, -550 + headd);
    glVertex2f(-760 + shead, -595 + headd);
    glEnd();
   
    bigwheel(-870 + shead+500, -545 + headd+50);  //wheel
    fwhitewheel(-600 + shead+230, -300 + headd-195);

    int shift42 = 35, shiftup42 = 70;
    int shift31 = -40, shiftup31 = 330;
    int shift43 = 400, shiftup43 = 45;

    int shead2 =280, headd2 = -100;
    glColor3f(1, 1, 1);

    glBegin(GL_POLYGON);                            //CAR - HEADLIGHT
    glVertex2f(-950 + shift43+ shead2, -270 + shiftup43+headd2);
    glVertex2f(-945 + shift43+shead2, -240 +  shiftup43+headd2);
    glVertex2f(-930 + shift43+ shead2, -240 + shiftup43+headd2);
    glVertex2f(-940 + shift43+ shead2, -270 + shiftup43+headd2);
    glEnd();

    glColor3f(0.58, 0.06, 0.03); // RED - CAR
    glBegin(GL_POLYGON);
    glVertex2f(-930 + shift42 + shead2, -300 +shiftup42+headd2);
    glVertex2f(-950 + shift42+ shead2 ,-230 + shiftup42+headd2);
    glVertex2f(-800 + shift42+ shead2 ,-230 + shiftup42+headd2);
    glVertex2f(-780 + shift42+ shead2 ,-180 + shiftup42+headd2);
    glVertex2f(-670 + shift42+ shead2 ,-180 + shiftup42+headd2);
    glVertex2f(-580 + shift42+ shead2 ,-230 + shiftup42+headd2);
    glVertex2f(-500 + shift42+ shead2 ,-230 + shiftup42+headd2);
    glVertex2f(-520 + shift42+ shead2 ,-300 + shiftup42+headd2);
    glEnd();


    bwheel(-600 + shift42+shead2, -300 + shiftup42+headd2);
    bwhitewheel(-600 + shift42 + shead2, -300 + shiftup42 + headd2);
    bwheel(-860 + shift42 + shead2, -300 + shiftup42 + headd2);
    bwhitewheel(-860 + shift42 + shead2, -300 + shiftup42+headd2);




    glColor3f(0.42, 0.7, 0.81); //car glass
    glBegin(GL_POLYGON);
    glVertex2f(-620 + shift31+shead2, -490 + shiftup31+headd2);
    glVertex2f(-620 + shift31+shead2, -450 + shiftup31+headd2);
    glVertex2f(-590 + shift31+shead2, -450 + shiftup31+headd2);
    glVertex2f(-545 + shift31+shead2, -477 + shiftup31+headd2);
    glVertex2f(-545 + shift31+shead2, -490 + shiftup31+headd2);
    glEnd();                                         


    glColor3f(1, 1, 1); //     ARROW MARK
    glBegin(GL_POLYGON);
    glVertex2f(-980 + shead, -620 + headd-430);
    glVertex2f(-980 + shead, -570 + headd-430);
    glVertex2f(-810 + shead, -570 + headd-430);
    glVertex2f(-810 + shead, -620 + headd-430);
    glEnd();                              
    glBegin(GL_TRIANGLES);                
    glVertex2f(-810 + shead, -640 + headd-430);
    glVertex2f(-810 + shead, -550 + headd-430);
    glVertex2f(-760 + shead, -595 + headd-430);
    glEnd();

    glColor3f(0.58, 0.06, 0.03); // RED - CAR - BODY
    glBegin(GL_POLYGON);
    glVertex2f(-930 + shift42 + shead2+900, -300 + shiftup42 + headd2-0);
    glVertex2f(-950 + shift42 + shead2+900, -230 + shiftup42 + headd2-0);
    glVertex2f(-800 + shift42 + shead2+900, -230 + shiftup42 + headd2-0);
    glVertex2f(-780 + shift42 + shead2+900, -180 + shiftup42 + headd2-0);
    glVertex2f(-670 + shift42 + shead2+900, -180 + shiftup42 + headd2-0);
    glVertex2f(-580 + shift42 + shead2+900, -230 + shiftup42 + headd2-0);
    glVertex2f(-500 + shift42 + shead2+900, -230 + shiftup42 + headd2-0);
    glVertex2f(-520 + shift42 + shead2+900, -300 + shiftup42 + headd2-0);
    glEnd();

    glColor3f(0.58, 0.06, 0.03); //Truck head
    glBegin(GL_POLYGON);
    glVertex2f(-630 + shead2+630, -550 + headd2+180);
    glVertex2f(-630 + shead2+630, -430 + headd2+180);
    glVertex2f(-570 + shead2+630, -430 + headd2+180);
    glVertex2f(-530 + shead2+630, -470 + headd2+180);
    glVertex2f(-530 + shead2+630, -550 + headd2+180);
    glEnd();
    glColor3f(0.42, 0.7, 0.81); //car glass
    glBegin(GL_POLYGON);
    glVertex2f(-620 + shift31 + shead2+670, -490 + shiftup31 + headd2-150);
    glVertex2f(-620 + shift31 + shead2+670, -450 + shiftup31 + headd2-150);
    glVertex2f(-570 + shift31 + shead2+670, -450 + shiftup31 + headd2-150);
    glVertex2f(-545 + shift31 + shead2+670, -477 + shiftup31 + headd2-150);
    glVertex2f(-545 + shift31 + shead2+670, -490 + shiftup31 + headd2-150);
    glEnd();
         bwheel(-600 +1080, -300-130);
    bwhitewheel(-600 +1080, -300-130);
    

    glColor3f(1.0, 0, 0);
    displayRasterText(-185, 550, 0.0, " FEATURE EXTRACTION");
    glColor3f(1.0, 0, 0);
    displayRasterText(-200, -600, 0.0, "PRESS KEY R TO CONTINUE");
    glFlush();



}
float spin = 0.0;
void spinDisplay(void)
{
    spin = spin +0.12;
    
    if (spin > 360.0)
        spin = spin - 360.0;
    glutPostRedisplay();
}

void fifthScreen() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //sky background
    glColor3f(0.4, 0.7, 1);
    glBegin(GL_POLYGON);
    glVertex2i(-1200, 700);
    glVertex2i(1200, 700);
    glVertex2i(1200, -700);
    glVertex2i(-1200, -700);
    glEnd();

    drawClouds(550, 450);
    drawClouds(-350, 550);
    drawClouds(950, 450);
    drawClouds(-850, 550);
    
    glLoadIdentity();
    int shift45 = 350, shiftdown45 = 650;
    glRotatef(spin, 0.0, 0.0, 0);
    glTranslatef(400, 0, -1);
    wheel(-870 + shift45, -545 + shiftdown45);  //wheel
   

    glColor3f(1, 0.36, 0.071); //Truck MAIN CONTAINER
    glBegin(GL_POLYGON);
    glVertex2f(-930 + shift45, -550 + shiftdown45);
    glVertex2f(-930 + shift45, -400 + shiftdown45);
    glVertex2f(-630 + shift45, -400 + shiftdown45);
    glVertex2f(-630 + shift45, -550 + shiftdown45);
    glEnd();

    glColor3f(0.82, 0.29, 0.05); //Truck tail dark orange
    glBegin(GL_POLYGON);
    glVertex2f(-930 + shift45, -550 + shiftdown45);
    glVertex2f(-930 + shift45, -400 + shiftdown45);
    glVertex2f(-830 + shift45, -400 + shiftdown45);
    glVertex2f(-830 + shift45, -550 + shiftdown45);
    glEnd();

    glColor3f(0.43, 0.43, 0.43); //Truck tail GREY
    glBegin(GL_POLYGON);
    glVertex2f(-930 + shift45, -550 + shiftdown45);
    glVertex2f(-930 + shift45, -450 + shiftdown45);
    glVertex2f(-830 + shift45, -450 + shiftdown45);
    glVertex2f(-830 + shift45, -550 + shiftdown45);
    glEnd();

    glColor3f(0.43, 0.43, 0.43); //Truck head
    glBegin(GL_POLYGON);
    glVertex2f(-630 + shift45, -550 + shiftdown45);
    glVertex2f(-630 + shift45, -430 + shiftdown45);
    glVertex2f(-570 + shift45, -430 + shiftdown45);
    glVertex2f(-530 + shift45, -470 + shiftdown45);
    glVertex2f(-530 + shift45, -550 + shiftdown45);
    glEnd();

    glColor3f(0.42, 0.7, 0.81); //Truck glass
    glBegin(GL_POLYGON);
    glVertex2f(-620 + shift45, -500 + shiftdown45);
    glVertex2f(-620 + shift45, -445 + shiftdown45);
    glVertex2f(-580 + shift45, -445 + shiftdown45);
    glVertex2f(-545 + shift45, -480 + shiftdown45);
    glVertex2f(-545 + shift45, -500 + shiftdown45);
    glEnd();

         wheel(-590 + shift45, -553 + shiftdown45);
    whitewheel(-590 + shift45, -553 + shiftdown45);
         wheel(-690 + shift45, -553 + shiftdown45);
    whitewheel(-690 + shift45, -553 + shiftdown45);
         wheel(-790 + shift45, -553 + shiftdown45);
    whitewheel(-790 + shift45, -553 + shiftdown45);
    glLoadIdentity();
   


  

    int shead5 = 300, head5 = 750;


    glLoadIdentity();
    glRotatef(spin-200,0,0,1);
    glColor3f(0.43, 0.43, 0.43); //Truck head
    glBegin(GL_POLYGON);
    glVertex2f(-630 + shead5, -550 + head5);
    glVertex2f(-630 + shead5, -430 + head5);
    glVertex2f(-570 + shead5, -430 + head5);
    glVertex2f(-530 + shead5, -470 + head5);
    glVertex2f(-530 + shead5, -550 + head5);
    glEnd();            
    

    glColor3f(0.42, 0.7, 0.81); //Truck glass
    glBegin(GL_POLYGON);
    glVertex2f(-620 + shead5, -500 + head5);
    glVertex2f(-620 + shead5, -445 + head5);
    glVertex2f(-580 + shead5, -445 + head5);
    glVertex2f(-545 + shead5, -480 + head5);
    glVertex2f(-545 + shead5, -500 + head5);
    glEnd();

 
  
    
    int shift425 = 35, shiftup425 = 70;
    int shift315 = -40, shiftup315 = 330;
    int shift435 = 400, shiftup435 = 45;

    int shead2 = 280, headd2 = -200;
    glColor3f(1, 1, 1);
    glLoadIdentity();
    glRotatef(spin+500, 0, 0, 0);
    glTranslatef(0, 0, 1);
    
    glBegin(GL_POLYGON);                            //CAR - HEADLIGHT
    glVertex2f(-950 + shift435 + shead2, -270 + shiftup435 + headd2);
    glVertex2f(-945 + shift435 + shead2, -240 + shiftup435 + headd2);
    glVertex2f(-930 + shift435 + shead2, -240 + shiftup435 + headd2);
    glVertex2f(-940 + shift435 + shead2, -270 + shiftup435 + headd2);
    glEnd();

    glColor3f(0.58, 0.06, 0.03); // RED - CAR
    glBegin(GL_POLYGON);
    glVertex2f(-930 + shift425 + shead2, -300 + shiftup425 + headd2);
    glVertex2f(-950 + shift425 + shead2, -230 + shiftup425 + headd2);
    glVertex2f(-800 + shift425 + shead2, -230 + shiftup425 + headd2);
    glVertex2f(-780 + shift425 + shead2, -180 + shiftup425 + headd2);
    glVertex2f(-670 + shift425 + shead2, -180 + shiftup425 + headd2);
    glVertex2f(-580 + shift425 + shead2, -230 + shiftup425 + headd2);
    glVertex2f(-500 + shift425 + shead2, -230 + shiftup425 + headd2);
    glVertex2f(-520 + shift425 + shead2, -300 + shiftup425 + headd2);
    glEnd();


         bwheel(-600 + shift425 + shead2, -300 + shiftup425 + headd2);
    bwhitewheel(-600 + shift425 + shead2, -300 + shiftup425 + headd2);
         bwheel(-860 + shift425 + shead2, -300 + shiftup425 + headd2);
    bwhitewheel(-860 + shift425 + shead2, -300 + shiftup425 + headd2);




    glColor3f(0.42, 0.7, 0.81); //car glass
    glBegin(GL_POLYGON);
    glVertex2f(-620 + shift315 + shead2, -490 + shiftup315 + headd2);
    glVertex2f(-620 + shift315 + shead2, -450 + shiftup315 + headd2);
    glVertex2f(-590 + shift315 + shead2, -450 + shiftup315 + headd2);
    glVertex2f(-545 + shift315 + shead2, -477 + shiftup315 + headd2);
    glVertex2f(-545 + shift315 + shead2, -490 + shiftup315 + headd2);
    glEnd();

    bigwheel(-870 + shead5 + 500, -545 + head5 + 50);  //wheel
    fwhitewheel(-600 + shead5 + 230, -300 + head5 - 195);
    glLoadIdentity();
   

    glLoadIdentity();
    glRotatef(spin-500.0, 0, 0,-100);
    glTranslatef(300, 465, 0);
    bwheel(-600 + shift425 + shead2, -300 + shiftup425 + headd2);
    bwhitewheel(-600 + shift425 + shead2, -300 + shiftup425+ headd2);
    bwheel(-860 + shift425 + shead2, -300 + shiftup425 + headd2);
    bwhitewheel(-860 + shift425 + shead2, -300 + shiftup425 + headd2);
    glLoadIdentity();

    glLoadIdentity();
    glColor3f(0.58, 0.06, 0.03); //CAR door
    glRotatef(spin+102, 0.0, 0.0, -100);
    glTranslatef(-200, 200, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-630 + shead2 + 630, -550 + headd2 + 180);
    glVertex2f(-630 + shead2 + 630, -430 + headd2 + 180);
    glVertex2f(-570 + shead2 + 630, -430 + headd2 + 180);
    glVertex2f(-530 + shead2 + 630, -470 + headd2 + 180);
    glVertex2f(-530 + shead2 + 630, -550 + headd2 + 180);
    glEnd();
    
    glColor3f(0.42, 0.7, 0.81); //car glass
    glBegin(GL_POLYGON);
    glVertex2f(-620 + shift315 + shead2 + 670, -490 + shiftup315 + headd2 - 150);
    glVertex2f(-620 + shift315 + shead2 + 670, -450 + shiftup315 + headd2 - 150);
    glVertex2f(-570 + shift315 + shead2 + 670, -450 + shiftup315 + headd2 - 150);
    glVertex2f(-545 + shift315 + shead2 + 670, -477 + shiftup315 + headd2 - 150);
    glVertex2f(-545 + shift315 + shead2 + 670, -490 + shiftup315 + headd2 - 150);
    glEnd();
    glLoadIdentity();
   


   

    glColor3f(0.21, 0.34, 0.82);
    displayRasterText(-60, 550, 0.0, "TRAINING");
    glColor3f(1.0, 0, 0);
    displayRasterText(-250, -550, 0.0, "PRESS KEY Y TO RETURN TO MENU");


}
float disx = 0.0, disy = 0.0, disx2 = 0, disy2 = 0.0, time = 0.0, time2 = 0.0;

void move1(int value) { //TRUCK

    disx = disx + 7.0;

    
    if (disx > 830)
        time = time + 1;
   
    
    if (time > 100)
        disx = 8120;

    
    if (disx > 830)
    {

        state = -1;
        switch (state)
        {
        case -1:

            disx = 830;

            break;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(50, move1, 0);
}

void move2(int value) { //CAR

    disx2 = disx2 - 7.0;
    if (disx2 < -810)
        time2 = time2 + 1;

    if (time2 > 100)
        disx2 = 8120;
    if (disx2 < -810)
    {
        state = -1;
        switch (state)
        {
        case -1:

            disx2 = -810;
            break;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(50, move2, 0);
}
void keyb(unsigned char key, int x, int y) {
    switch (key) {
        
    case 'L': 
        time2 = 0;
        move1(147);
        glutTimerFunc(1000 / 60, move1, 0);
        
        break;
    case 'C':
        time = 0;
        move2(147);
        glutTimerFunc(1000 / 60, move2, 0);
        break;
    case 'U':
        viewPage = MENU;
    }
}
void sixthScreen()
{

    glBegin(GL_POLYGON);    //BACKGROUND COLORS
    glColor3f(0.4, 0.69, 0.86);
    glVertex2i(-1200, -700);
    glColor3f(0.94, 0.77, 1);
    glVertex2i(-1200, 700);
    glColor3f(0.94, 0.77, 1);
    glVertex2i(1200, 700);
    glColor3f(0.4, 0.69, 0.86);
    glVertex2i(1200, -700);
    glEnd();
 
    int shift = -100, shiftdown = 650;
    wheel(-870 + shift + disx, -545 + shiftdown + disy);  //wheel

    glColor3f(0.88, 0.88, 0.88); //Truck tail
    glBegin(GL_POLYGON);
    glVertex2f(-930 + shift + disx, -550 + shiftdown + disy);
    glVertex2f(-930 + shift + disx, -400 + shiftdown + disy);
    glVertex2f(-630 + shift + disx, -400 + shiftdown + disy);
    glVertex2f(-630 + shift + disx, -550 + shiftdown + disy);
    glEnd();

    glColor3f(0.8, 0.8, 0.8 ); //Truck tail   
    glBegin(GL_POLYGON);
    glVertex2f(-930 + shift + disx, -550 + shiftdown + disy);
    glVertex2f(-930 + shift + disx, -400 + shiftdown + disy);
    glVertex2f(-830 + shift + disx, -400 + shiftdown + disy);
    glVertex2f(-830 + shift + disx, -550 + shiftdown + disy);
    glEnd();

    glColor3f(0.43, 0.43, 0.43); //Truck tail
    glBegin(GL_POLYGON);
    glVertex2f(-930 + shift +disx, -550 + shiftdown + disy);
    glVertex2f(-930 + shift +disx, -450 + shiftdown + disy);
    glVertex2f(-830 + shift +disx, -450 + shiftdown + disy);
    glVertex2f(-830 + shift +disx, -550 + shiftdown + disy);
    glEnd();

    glColor3f(1, 0.36, 0.07); //Truck head      
    glBegin(GL_POLYGON);
    glVertex2f(-630 + shift + disx, -550 + shiftdown + disy);
    glVertex2f(-630 + shift + disx, -430 + shiftdown + disy);
    glVertex2f(-570 + shift + disx, -430 + shiftdown + disy);
    glVertex2f(-530 + shift + disx, -470 + shiftdown + disy);
    glVertex2f(-530 + shift + disx, -550 + shiftdown + disy);
    glEnd();                                          
                                                      
    glColor3f(0.42, 0.7, 0.81); //Truck glass         
    glBegin(GL_POLYGON);                              
    glVertex2f(-620 + shift + disx, -500 + shiftdown + disy);
    glVertex2f(-620 + shift + disx, -445 + shiftdown + disy);
    glVertex2f(-580 + shift + disx, -445 + shiftdown + disy);
    glVertex2f(-545 + shift + disx, -480 + shiftdown + disy);
    glVertex2f(-545 + shift + disx, -500 + shiftdown + disy);
    glEnd();                                          
                                                      
         wheel(-590 + shift + disx, -553 + shiftdown + disy);
    whitewheel(-590 + shift + disx, -553 + shiftdown + disy);
         wheel(-690 + shift + disx, -553 + shiftdown + disy);
    whitewheel(-690 + shift + disx, -553 + shiftdown + disy);
         wheel(-790 + shift + disx, -553 + shiftdown + disy);
    whitewheel(-790 + shift + disx, -553 + shiftdown + disy);

   
    int shift2 = 1530, shiftup2 = 400;
    int shift3 = 1330, shiftup3 = 659;

    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2f(-950 + shift2+disx2, -270 + shiftup2+disy2);
    glVertex2f(-955 + shift2+disx2, -240 + shiftup2+disy2);
    glVertex2f(-940 + shift2+disx2, -240 + shiftup2+disy2);
    glVertex2f(-940 + shift2+disx2, -270 + shiftup2+disy2);
    glEnd();
    glColor3f(0.58, 0.06, 0.03); //CAR
    glBegin(GL_POLYGON);
    glVertex2f(-930 + shift2+disx2, -300 + shiftup2+disy2);
    glVertex2f(-950 + shift2+disx2, -230 + shiftup2+disy2);
    glVertex2f(-800 + shift2+disx2, -230 + shiftup2+disy2);
    glVertex2f(-780 + shift2+disx2, -180 + shiftup2+disy2);
    glVertex2f(-660 + shift2+disx2, -180 + shiftup2+disy2);
    glVertex2f(-580 + shift2+disx2, -230 + shiftup2+disy2);
    glVertex2f(-500 + shift2+disx2, -230 + shiftup2+disy2);
    glVertex2f(-520 + shift2+disx2, -300 + shiftup2+disy2);
    glEnd();


         bwheel(-600 + shift2+disx2, -300 + shiftup2+disy2);
    bwhitewheel(-600 + shift2+disx2, -300 + shiftup2+disy2);
         bwheel(-860 + shift2+disx2, -300 + shiftup2+disy2);
    bwhitewheel(-860 + shift2+disx2, -300 + shiftup2+disy2);



    glColor3f(0.42, 0.7, 0.81); //car glass
    glBegin(GL_POLYGON);
    glVertex2f(-545 + shift3+disx2, -490 + shiftup3+disy2);
    glVertex2f(-545 + shift3+disx2, -445 + shiftup3+disy2);
    glVertex2f(-580 + shift3+disx2, -445 + shiftup3+disy2);
    glVertex2f(-620 + shift3+disx2, -480 + shiftup3+disy2);
    glVertex2f(-620 + shift3+disx2, -490 + shiftup3+disy2);
    glEnd();
    
    int sh = -60;
    glLineWidth(2);
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2i(-100 - 90 + sh, 0);
    glVertex2i(-100 - 90 + sh, 300 + 30);
    glVertex2i(300  + sh, 300 + 30);
    glVertex2i(300  + sh, 0);
    glEnd();
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_LINE_LOOP);
    glVertex2i(-90 - 90 + sh, 10);
    glVertex2i(-90 - 90 + sh, 290 + 30);
    glVertex2i(290  + sh, 290 + 30);
    glVertex2i(290  + sh, 10);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.69, 0.86);
    glVertex2i(-90 - 90 + sh, 10);
  
    glVertex2i(-90 - 90 + sh, 290 + 30);
    
    glVertex2i(290 + sh, 290 + 30);
    glColor3f(0.4, 0.69, 0.86);
    glVertex2i(290 + sh, 10);
    glEnd();

    drawClouds(300, 500);
    drawClouds(-350, 450);
    drawClouds(950, 500);
    drawClouds(-850, 550);

    glColor3f(1.0, 0, 0);
    displayRasterText(-1100, 300, 0.0, "Press L to predict the below input");


    glColor3f(1.0, 0, 0);
    displayRasterText(530, 300, 0.0, "Press C to predict the below input");

    if (disx >820 ||disx2<-805)
    {
        glColor3f(1.0, 0, 0);
        displayRasterText(-85, -200, 0.0, "Processing...");

       
    }
    if (time > 100.0 && time2==0.0)
    {
        glColor3f(0.4, 0.69, 0.86);
        glBegin(GL_POLYGON);
        glVertex2i(-120, -215);
        glVertex2i(-120,-150);
        glVertex2i(120,-150);
        glVertex2i(120,-215);
        glEnd();
        glColor3f(1.0, 1, 1);
        displayRasterText(-100, -200, 0.0, "This is a truck");
    }
     if (time2 > 100.0 )
    {
        glColor3f(0.4, 0.69, 0.86);
        glBegin(GL_POLYGON);
        glVertex2i(-120, -215);
        glVertex2i(-120, -150);
        glVertex2i(120, -150);
        glVertex2i(120, -215);
        glEnd();
        glColor3f(1.0, 1, 1);
        displayRasterText(-100, -200, 0.0, "This is a CAR");
    }
     glColor3f(1,0,0);
     displayRasterText(-80, 550, 0.0, "TESTING");
     glColor3f(1, 0, 0);
     displayRasterText(-170, -500, 0.0, "PRESS U FOR MENU");
     glutKeyboardFunc(keyb);
}

void seventhScreen() {

    //sky background
    glColor3f(0.4, 0.7, 1);
    glBegin(GL_POLYGON);
    glVertex2i(-1200, 700);
    glVertex2i(1200, 700);
    glVertex2i(1200, -700);
    glVertex2i(-1200, -700);
    glEnd();

    glColor3f(1.0, 0, 0);
    displayRasterText(-850, 550, 0.0, "A training model is a dataset that is used to train an ML algorithm. It consists of the sample output data and   ");
    glColor3f(1.0, 0, 0);
    displayRasterText(-850, 500, 0.0, "the corresponding sets of input data that have an influence on the output.");
    glColor3f(1.0, 0, 0);
    displayRasterText(-850, 350, 0.0, "3 steps to training a machine learning model:");
    glColor3f(1.0, 0, 0);
    displayRasterText(-850, 270, 0.0, "Step 1: Begin with existing data");
    glColor3f(1.0, 0, 0);
    displayRasterText(-850, 200, 0.0, "Step 2: Analyze data to identify patterns");
    glColor3f(1.0, 0, 0);
    displayRasterText(-850, 130, 0.0, "Step 3: Make predictions.");
    glColor3f(1.0, 0, 0);
    displayRasterText(-850, 150, 0.0, "");
    glColor3f(1.0, 0, 0);
    glColor3f(1.0, 0, 0);
    displayRasterText(-250, -550, 0.0, "PRESS KEY T TO CONTINUE ");

}

//main display function
void display()
{
    keyOperations();
    glClear(GL_COLOR_BUFFER_BIT);

    switch (viewPage)
    {
    case INTRO:
        introScreen();
        break;
    case MENU:
        menuScreen();
        break;
    case INSTRUCTIONS:
        instructionScreen();
        break;
    case SCREEN1:
        firstScreen();
        break;
    case SCREEN2:
        secondScreen();
        break;
    case SCREEN3:
        thirdScreen();
        break;
    case SCREEN4:
        fourthScreen();
        break;
    case SCREEN5:
        fifthScreen();
        break;
    case SCREEN6:
        seventhScreen();
        break;
    case SCREEN7:
        sixthScreen();
        break;
    case SCREEN8:
        menuScreen();
        break;
    }
    glFlush();
    glLoadIdentity();
    glutSwapBuffers();
}


// inbuilt functions//
void passiveMotionFunc(int x, int y) {


    mouseX = float(x) / (m_viewport[2] / 1200.0) - 600.0;
    mouseY = -(float(y) / (m_viewport[3] / 700.0) - 350.0);
    glutPostRedisplay();
}


void mouseClick(int buttonPressed, int state, int x, int y) {


    if (buttonPressed == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        mButtonPressed = true;
    else
        mButtonPressed = false;
    glutPostRedisplay();
}


void keyPressed(unsigned char key, int x, int y)
{
    keyStates[key] = true;
    glutPostRedisplay();
}


void keyReleased(unsigned char key, int x, int y)
{
    keyStates[key] = false;
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowPosition(100, 50);
    glutInitWindowSize(1300.0, 700.0);
    glutCreateWindow("VISUALIZATION OF MACHINE LEARNING");
    glutKeyboardFunc(keyPressed);
    glutKeyboardUpFunc(keyReleased);
    glutMouseFunc(mouseClick);
    glutPassiveMotionFunc(passiveMotionFunc);
    glGetIntegerv(GL_VIEWPORT, m_viewport);
    glutDisplayFunc(display);
    glutIdleFunc(spinDisplay);
    glutSpecialFunc(specialkey);
    
    init();
    glutMainLoop();
}