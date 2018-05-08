#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#endif
#include <math.h>
#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <cstring>
#include <fstream>
#include <GL/glew.h>
#include <gl\gl.h>
#include <gl\glext.h>
#include <gl\glaux.h>
#include <gl\glu.h>
#include <GL\glut.h>//-lglut
#include <assert.h>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <cstring>
#include <cmath>
#include <fstream>
#include <time.h>
#include <string.h>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <gl\glfw.h>
#include <vector>
//cmd line: -SDL_image 
//f>
#include <conio.h>
#include <new>
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
using namespace std;
bool keystates[256];
/*lists*/GLuint sun1=1,moon1=2;
double lefta,upb,downb,sunm;//direction. player/player rotate;
static double rota,rotb,rotx,roty;bool mstate=false;static int click=0;
static bool xp1=false,xn1=false,yp1=false,yn1=false;
bool ground=false;
static int mousex,mousey;int xprev=mousex/2;int yprev=mousey/2;
//time/direction
double milliseconds,seconds,minutes,hours,days,months,years,decades,centurys;
static int north,south,east,west;
//loops
int xloop,yloop,zloop;
static bool place=false;
static double a,b;
static double na,nb;static int place1=0;
//static bool mc=false;//
static double dist1,dist2,dist3,dist4;static double x,y,z,w=-5;static double downbw;static bool collision=false;
static int blockt=2;
//////////////////////////////////////////////////////////////////////////////////////
void mouseclick(int button,int state,int x,int y){
if(button==GLUT_LEFT_BUTTON){mstate=true;}
if(mstate==true){
if(button==GLUT_LEFT_BUTTON&&click==false){click=1;}
if(button==GLUT_RIGHT_BUTTON&&click==false){click=2;}
};
;}//end void;

void mousemovingpressed(int x, int y){
if (mstate==true){xprev=mousex/2;yprev=mousey/2;
if (rota>=90){rota=90;}
if (rota<=-90){rota=-90;}

if (x>=xprev){xp1=true;}
if (x<=xprev){xn1=true;}
if (y<=yprev){yn1=true;}
if (y>=yprev){yp1=true;}

if (mstate==true&&xp1==true){rotb+=4.5;roty=1;xp1=false;}//5orig;
if (mstate==true&&xn1==true){rotb-=4.5;roty=1;xn1=false;}
if (mstate==true&&yn1==true){rota-=4.5;rotx=1;yn1=false;}
if (mstate==true&&yp1==true){rota+=4.5;rotx=1;yp1=false;}
;;}
;}

void mousemoveunpressed(int x, int y){
if (mstate==true){xprev=mousex/2;yprev=mousey/2;
if (rota>=90){rota=90;}
if (rota<=-90){rota=-90;}

if (x>=xprev){xp1=true;}
if (x<=xprev){xn1=true;}
if (y<=yprev){yn1=true;}
if (y>=yprev){yp1=true;}

if (mstate==true&&xp1==true){rotb+=4.5;roty=1;xp1=false;}//5orig;
if (mstate==true&&xn1==true){rotb-=4.5;roty=1;xn1=false;}
if (mstate==true&&yn1==true){rota-=4.5;rotx=1;yn1=false;}
if (mstate==true&&yp1==true){rota+=4.5;rotx=1;yp1=false;}
;;}
;}

void Skeys (int key, int x, int y){//if(key==GLUT_KEY_LEFT){lefta+=.5;glutPostRedisplay();}
if (mstate==true){if (key==GLUT_KEY_UP){keystates[GLUT_KEY_UP]=true;}if (key==GLUT_KEY_LEFT){keystates[GLUT_KEY_LEFT]=true;}if (key==GLUT_KEY_DOWN){keystates[GLUT_KEY_DOWN]=true;}if (key==GLUT_KEY_RIGHT){keystates[GLUT_KEY_RIGHT]=true;}

if(keystates[GLUT_KEY_UP]==true){
    if (rotb==0||rotb==360){downb+=.5;lefta-=0;}if (rotb>0&&rotb<22.5){downb+=.4;lefta-=.1;}if (rotb>=22.5&&rotb<45){downb+=.3;lefta-=.2;}if (rotb>=45&&rotb<67.5){downb+=.2;lefta-=.3;}if (rotb>=67.5&&rotb<90){downb+=.1;lefta-=.4;}
if (rotb==90){downb-=.0;lefta-=.5;}if (rotb>90&&rotb<112.5){downb-=.1;lefta-=.4;}if (rotb>=112.5&&rotb<135){downb-=.2;lefta-=.3;}if (rotb>=135&&rotb<157.5){downb-=.3;lefta-=.2;}if (rotb>=157.5&&rotb<180){downb-=.4;lefta-=.1;}
if (rotb==180){downb-=.5;lefta+=.0;}if (rotb>180&&rotb<202.5){downb-=.4;lefta+=.1;}if (rotb>=202.5&&rotb<225){downb-=.3;lefta+=.2;}if (rotb>=225&&rotb<247.5){downb-=.2;lefta+=.3;}if (rotb>=247.5&&rotb<270){downb-=.1;lefta+=.4;}
if (rotb==270){downb+=.0;lefta+=.5;}if (rotb>270&&rotb<292.5){downb+=.1;lefta+=.4;}if (rotb>=292.5&&rotb<315){downb+=.2;lefta+=.3;}if (rotb>=315&&rotb<337.5){downb+=.3;lefta+=.2;}if (rotb>=337.5&&rotb<360){downb+=.4;lefta+=.1;}
glutPostRedisplay();}/////
if(keystates[GLUT_KEY_LEFT]==true){
    if (rotb==0||rotb==360){downb+=.0;lefta+=.5;}if (rotb>0&&rotb<22.5){downb+=.1;lefta+=.4;}if (rotb>=22.5&&rotb<45){downb+=.2;lefta+=.3;}if (rotb>=45&&rotb<67.5){downb+=.3;lefta+=.2;}if (rotb>=67.5&&rotb<90){downb+=.4;lefta+=.1;}
if (rotb==90){downb+=.5;lefta-=.0;}if (rotb>90&&rotb<112.5){downb+=.4;lefta-=.1;}if (rotb>=112.5&&rotb<135){downb+=.3;lefta-=.2;}if (rotb>=135&&rotb<157.5){downb+=.2;lefta-=.3;}if (rotb>=157.5&&rotb<180){downb+=.1;lefta-=.4;}
if (rotb==180){downb-=.0;lefta-=.5;}if (rotb>180&&rotb<202.5){downb-=.1;lefta-=.4;}if (rotb>=202.5&&rotb<225){downb-=.2;lefta-=.3;}if (rotb>=225&&rotb<247.5){downb-=.3;lefta-=.2;}if (rotb>=247.5&&rotb<270){downb-=.4;lefta-=.1;}
if (rotb==270){downb-=.5;lefta+=.0;}if (rotb>270&&rotb<292.5){downb-=.4;lefta+=.1;}if (rotb>=292.5&&rotb<315){downb-=.3;lefta+=.2;}if (rotb>=315&&rotb<337.5){downb-=.2;lefta+=.3;}if (rotb>=337.5&&rotb<360){downb-=.1;lefta+=.4;}
glutPostRedisplay();}/////
if(keystates[GLUT_KEY_RIGHT]==true){
    if (rotb==0||rotb==360){downb-=.0;lefta-=.5;}if (rotb>0&&rotb<22.5){downb-=.1;lefta-=.4;}if (rotb>=22.5&&rotb<45){downb-=.2;lefta-=.3;}if (rotb>=45&&rotb<67.5){downb-=.3;lefta-=.2;}if (rotb>=67.5&&rotb<90){downb-=.4;lefta-=.1;}
if (rotb==90){downb-=.5;lefta+=.0;}if (rotb>90&&rotb<112.5){downb-=.4;lefta+=.1;}if (rotb>=112.5&&rotb<135){downb-=.3;lefta+=.2;}if (rotb>=135&&rotb<157.5){downb-=.2;lefta+=.3;}if (rotb>=157.5&&rotb<180){downb-=.1;lefta+=.4;}
if (rotb==180){downb+=.0;lefta+=.5;}if (rotb>180&&rotb<202.5){downb+=.1;lefta+=.4;}if (rotb>=202.5&&rotb<225){downb+=.2;lefta+=.3;}if (rotb>=225&&rotb<247.5){downb+=.3;lefta+=.2;}if (rotb>=247.5&&rotb<270){downb+=.4;lefta+=.1;}
if (rotb==270){downb+=.5;lefta-=.0;}if (rotb>270&&rotb<292.5){downb+=.4;lefta-=.1;}if (rotb>=292.5&&rotb<315){downb+=.3;lefta-=.2;}if (rotb>=315&&rotb<337.5){downb+=.2;lefta-=.3;}if (rotb>=337.5&&rotb<360){downb+=.1;lefta-=.4;}
glutPostRedisplay();}/////      
if(keystates[GLUT_KEY_DOWN]==true){
    if (rotb==0||rotb==360){downb-=.5;lefta+=.0;}if (rotb>0&&rotb<22.5){downb-=.4;lefta+=.1;}if (rotb>=22.5&&rotb<45){downb-=.3;lefta+=.2;}if (rotb>=45&&rotb<67.5){downb-=.2;lefta+=.3;}if (rotb>=67.5&&rotb<90){downb-=.1;lefta+=.4;}
if (rotb==90){downb+=.0;lefta+=.5;}if (rotb>90&&rotb<112.5){downb+=.1;lefta+=.4;}if (rotb>=112.5&&rotb<135){downb+=.2;lefta+=.3;}if (rotb>=135&&rotb<157.5){downb+=.3;lefta+=.2;}if (rotb>=157.5&&rotb<180){downb+=.4;lefta+=.1;}
if (rotb==180){downb+=.5;lefta-=.0;}if (rotb>180&&rotb<202.5){downb+=.4;lefta-=.1;}if (rotb>=202.5&&rotb<225){downb+=.3;lefta-=.2;}if (rotb>=225&&rotb<247.5){downb+=.2;lefta-=.3;}if (rotb>=247.5&&rotb<270){downb+=.1;lefta-=.4;}
if (rotb==270){downb-=.0;lefta-=.5;}if (rotb>270&&rotb<292.5){downb-=.1;lefta-=.4;}if (rotb>=292.5&&rotb<315){downb-=.2;lefta-=.3;}if (rotb>=315&&rotb<337.5){downb-=.3;lefta-=.2;}if (rotb>=337.5&&rotb<360){downb-=.4;lefta-=.1;}
glutPostRedisplay();}/////

;}//end mstate true;
;} //END VOID;

void Skeysup(int key, int x, int y){
if (keystates[GLUT_KEY_UP]){keystates[GLUT_KEY_UP]=false;}
if (keystates[GLUT_KEY_LEFT]){keystates[GLUT_KEY_LEFT]=false;}
if (keystates[GLUT_KEY_RIGHT]){keystates[GLUT_KEY_RIGHT]=false;}
if (keystates[GLUT_KEY_DOWN]){keystates[GLUT_KEY_DOWN]=false;}
;}

void keyPressed (unsigned char key, int x, int y){int mod=glutGetModifiers();glutKeyboardFunc(keyPressed);//GLUT_ACTIVE_SHIFT GLUT_ACTIVE_CTRL GLUT_ACTIVE_ALT;
if(key=='i'){blockt=0;}
if(key=='o'){blockt=1;}
if(key=='p'){blockt=2;}
if(mstate==true){
if (key==32){keystates[32]=true;keystates[GLUT_ACTIVE_SHIFT]=true;;
if (mod!=GLUT_ACTIVE_SHIFT){upb-=.5;}
if (mod==GLUT_ACTIVE_SHIFT){upb+=.5;}
}}
/*if (key=='f'){sunm+=1;}if (key=='g'){sunm-=1;}*/if (key==27){mstate=false;}

//if (key=='p'){mc=true;}
;}

void keyup (unsigned char key, int x, int y){glutKeyboardUpFunc(keyup);
if(keystates[32]){keystates[32]=false;}if(keystates[GLUT_ACTIVE_SHIFT]){keystates[GLUT_ACTIVE_SHIFT]=false;}
;}
static double ax1=-1.0f/2,ay1=-1.0f/2,az1=-1.0f/2;
			static double bx1=1.0f/2,by1=-1.0f/2,bz1=-1.0f/2;
			static double cx1=1.0f/2,cy1=-1.0f/2,cz1=1.0f/2;
			static double dx1=-1.0f/2,dy1=-1.0f/2,dz1=1.0f/2;
static double ax2=-1.0f/2,ay2=-1.0f/2,az2=-1.0f/2;
			static double bx2=1.0f/2,by2=-1.0f/2,bz2=-1.0f/2;
			static double cx2=1.0f/2,cy2=-1.0f/2,cz2=1.0f/2;
			static double dx2=-1.0f/2,dy2=-1.0f/2,dz2=1.0f/2;
void BuildList(){
{glGenLists(sun1);glNewList(sun1,GL_COMPILE);
glBegin(GL_QUADS);glColor4f(1,1,0,1);//QUADS
			// Bottom Face
			//glNormal3f( 0.0f,-1.0f, 0.0f);
		/*	static double ax1=-1.0f/2,ay1=-1.0f/2,az1=-1.0f/2;
			static double bx1=1.0f/2,by1=-1.0f/2,bz1=-1.0f/2;
			static double cx1=1.0f/2,cy1=-1.0f/2,cz1=1.0f/2;
			static double dx1=-1.0f/2,dy1=-1.0f/2,dz1=1.0f/2;*/
			//glColor4f(1,2,4,.5);
			glVertex3f(ax1,ay1,az1);//a
			glVertex3f(bx1,by1,bz1);//b
			glVertex3f(cx1,cy1,cz1);//c
			glVertex3f(dx1,dy1,dz1);//d
			// Front Face
			//glNormal3f( 0.0f, 0.0f, 1.0f);
			glColor4f(1,0,1,1);glVertex3f(-1.0f/2, -1.0f/2,  1.0f/2);
			glVertex3f( 1.0f/2, -1.0f/2,  1.0f/2);
			glVertex3f( 1.0f/2,  1.0f/2,  1.0f/2);
			glVertex3f(-1.0f/2,  1.0f/2,  1.0f/2);
			// Back Face
			//glNormal3f( 0.0f, 0.0f,-1.0f);
			glColor4f(1,0,0,1);glVertex3f(-1.0f/2, -1.0f/2, -1.0f/2);
			glVertex3f(-1.0f/2,  1.0f/2, -1.0f/2);
			glVertex3f( 1.0f/2,  1.0f/2, -1.0f/2);
			glVertex3f( 1.0f/2, -1.0f/2, -1.0f/2);
			// Right face
			//glNormal3f( 1.0f, 0.0f, 0.0f);
		glColor4f(0,1,0,1);	glVertex3f( 1.0f/2, -1.0f/2, -1.0f/2);
			glVertex3f( 1.0f/2,  1.0f/2, -1.0f/2);
			glVertex3f( 1.0f/2,  1.0f/2,  1.0f/2);
			glVertex3f( 1.0f/2, -1.0f/2,  1.0f/2);
			// Left Face
			//glNormal3f(-1.0f, 0.0f, 0.0f);
		glColor4f(1,1,1,1);	glVertex3f(-1.0f/2, -1.0f/2, -1.0f/2);
			glVertex3f(-1.0f/2, -1.0f/2,  1.0f/2);
			glVertex3f(-1.0f/2,  1.0f/2,  1.0f/2);
			glVertex3f(-1.0f/2,  1.0f/2, -1.0f/2);
			// Top Face
			//glNormal3f( 0.0f, 1.0f, 0.0f);
		glColor4f(0,1,1,1);	glVertex3f(-1.0f/2,  1.0f/2, -1.0f/2);
			glVertex3f(-1.0f/2,  1.0f/2,  1.0f/2);
			glVertex3f( 1.0f/2,  1.0f/2,  1.0f/2);
			glVertex3f( 1.0f/2,  1.0f/2, -1.0f/2);
		glEnd();glEndList();
;}
{glGenLists(moon1);glNewList(moon1,GL_COMPILE);
glBegin(GL_POLYGON);glColor4f(.6,.2,.4,.1);
			// Bottom Face
			//glNormal3f( 0.0f,-1.0f, 0.0f);
			/*static double ax2=-1.0f/2,ay2=-1.0f/2,az2=-1.0f/2;
			static double bx2=1.0f/2,by2=-1.0f/2,bz2=-1.0f/2;
			static double cx2=1.0f/2,cy2=-1.0f/2,cz2=1.0f/2;
			static double dx2=-1.0f/2,dy2=-1.0f/2,dz2=1.0f/2;*/
			glVertex3f(ax2,ay2,az2);
			glVertex3f(bx2,by2,bz2);
			glVertex3f(cx2,cy2,cz2);
			glVertex3f(dx2,dy2,dz2);
			// Front Face
			//glNormal3f( 0.0f, 0.0f, 1.0f);
			glVertex3f(-1.0f/2, -1.0f/2,  1.0f/2);
			glVertex3f( 1.0f/2, -1.0f/2,  1.0f/2);
			glVertex3f( 1.0f/2,  1.0f/2,  1.0f/2);
			glVertex3f(-1.0f/2,  1.0f/2,  1.0f/2);
			// Back Face
			//glNormal3f( 0.0f, 0.0f,-1.0f);
			glVertex3f(-1.0f/2, -1.0f/2, -1.0f/2);
			glVertex3f(-1.0f/2,  1.0f/2, -1.0f/2);
			glVertex3f( 1.0f/2,  1.0f/2, -1.0f/2);
			glVertex3f( 1.0f/2, -1.0f/2, -1.0f/2);
			// Right face
			//glNormal3f( 1.0f, 0.0f, 0.0f);
			glVertex3f( 1.0f/2, -1.0f/2, -1.0f/2);
			glVertex3f( 1.0f/2,  1.0f/2, -1.0f/2);
			glVertex3f( 1.0f/2,  1.0f/2,  1.0f/2);
			glVertex3f( 1.0f/2, -1.0f/2,  1.0f/2);
			// Left Face
			//glNormal3f(-1.0f, 0.0f, 0.0f);
			glVertex3f(-1.0f/2, -1.0f/2, -1.0f/2);
			glVertex3f(-1.0f/2, -1.0f/2,  1.0f/2);
			glVertex3f(-1.0f/2,  1.0f/2,  1.0f/2);
			glVertex3f(-1.0f/2,  1.0f/2, -1.0f/2);
			// Top Face
			//glNormal3f( 0.0f, 1.0f, 0.0f);
			//glColor3f(2,3,0);
			glVertex3f(-1.0f/2,  1.0f/2, -1.0f/2);
			glVertex3f(-1.0f/2,  1.0f/2,  1.0f/2);
			glVertex3f( 1.0f/2,  1.0f/2,  1.0f/2);
			glVertex3f( 1.0f/2,  1.0f/2, -1.0f/2);
		glEnd();glEndList();
;}

;}//end void;

void MOON(){glLoadIdentity();//sun and moon rotations and translations work to camera movement of player.;
if(rotb<90||rotb>=270){glRotatef(rotb,0,roty,0);glRotatef(rota,rotx,0,0);}
if(rotb>=90&&rotb<270){glRotatef(rotb,0,roty,0);glRotatef(-rota,rotx,0,0);}
glRotatef(sunm,sunm,0,0);glTranslatef(0,0,90);
glCallList(moon1);;}//end void;
void SUN(){glLoadIdentity();//GLfloat lpo[]={0,90,sunm,1};glLightfv(GL_LIGHT0,GL_POSITION,lpo);
if(rotb<=90||rotb>270){glRotatef(rotb,0,roty,0);glRotatef(rota,rotx,0,0);}
if(rotb>90&&rotb<=270){glRotatef(rotb,0,roty,0);glRotatef(-rota,rotx,0,0);}
//cout<<"sunm: "<<sunm<<" rota: "<<rota<<" rotb: "<<rotb<<"\n";
glRotatef(sunm,sunm,0,0);glTranslatef(0,0,-90);//if (sunm>=360||sunm<=0){sunm=0;}//
glCallList(sun1);}
void nightday(){
//cout<<"rotb: "<<rotb<<" lefta: "<<lefta<<" downb: "<<downb<<" rota: "<<rota<<"\n";system("CLS");
;}//roty
//player pos;

void PLAYER(){/*glLoadIdentity();{glTranslatef(0,0,-3);
//double plv=(x,y,z);
glLoadIdentity();
glRotatef(rota,roty,0,0);glRotatef(rotb,0,roty,0);glTranslatef(2,2,0);
glCallList(1);//cout<<"x: "<<x<<" y: "<<y<<" z: "<<z<<"\n";
glTranslatef(x,y,z);//upb=move in y direction
}//glCallList(sun1);}*/
if (mstate==true){glLoadIdentity();glTranslatef(x,y,z-5);//glCallList(sun1);
/*glTranslatef(0,0,w);*/
glColor4f(0,1,1,1);
glBegin(GL_LINES);glVertex2f(-.1,0);glVertex2f(.1,0);glEnd();
glBegin(GL_LINES);glVertex2f(0,-.1);glVertex2f(0,.1);glEnd();

//x=-lefta,y=-upb,z=downb;cout<<"x: "<<x<<" y: "<<y<<" z: "<<z<<" w: "<<w<<"\n";
//glBegin(GL_LINES);glVertex3f(0,0,0);glVertex3f(0,0,w);glEnd();
;};}
unsigned char d11[256][128][16][128][16];
unsigned char d21[256][128][16][128][16];
unsigned char d31[256][128][16][128][16];
unsigned char d41[256][128][16][128][16];


unsigned const __int16 a1=20,a2=20,a3=20;
unsigned __int16 cMap[a1][a2][a3];

void WORLDMAIN(){
int o=-1,h=-1;//,maxha=0;//,heighta[99999999];
static vector<int>xx(99999);xx.resize(xloop*yloop*zloop);
static vector<int>yy(99999);
static vector<int>hl(99999);
static vector<int>zz(99999);//copy(yy.begin(),yy.end(),xx.begin());//if(o>80){yy[o]=0;}  xx.insert (xx.begin(), o,o+7);

static vector<int>lef(9991);
//static vector<vector<int> >xyz(9991,1);
static bool p1=false;static double height;double maxh=4;static double randm;int cs=20;//16
static bool pass=0;
for (xloop=0;xloop<cs;xloop++){
for (zloop=0;zloop<cs;zloop++){//if(randm<cs*cs*cs){height=rand()%3+0;randm+=1;o+=1;yy[o]=height;cout<<yy[o];}
//if(randm<cs*cs*cs){;;;;height=rand()%3+0;randm+=1;o+=1;yy[o]=height;}


//for (yloop=0;yloop<cs;yloop++){
 //  if(zz[o]==0&&xx[o]==0){h=h+1;}//cout<<"h: "<<h<<" o: "<<o<<" xx[o]: "<<xx[o]<<" zz[o]: "<<zz[o]<<" yy[o]: "<<yy[o]<<" ";
//cout<<"h:"<<h<<" xloop:"<<xloop<<" zloop:"<<zloop<<" yloop:"<<yloop<<" cs^2:"<<cs*cs<<" height:"<<height<<" o:"<<o<<" xx[o]:"<<xx[o]<<" zz[o]:"<<zz[o]<<" yy[o]:"<<yy[o]<<"\n";//
//}
     //////////////////////xyz[xx[0]][yy[0]][zz[0]]=1;
//cout<<xyz[xx[0]][yy[0]][zz[0]]<<"\n";
//xx[o]=xloop;zz[o]=zloop;
//cout<<"o count: "<<o<<": Height: "<<height<<" yy[0,1,2,3]: "<<yy[0]<<" "<<yy[15]<<" xx[o]: "<<xx[o]<<" zz[o]: "<<zz[o]<<"\n";

//height=(1/3)*-(xloop)*+sin(45)-(zloop)*+cos(90)/2;
//height=sqrt(99)-(xloop/16)-(zloop/8);
////////////////////////////////if(xloop>3&&xloop<13&&zloop>3&zloop<13){height=4+(cos(zloop)+sin(zloop/2)+cos(xloop));}
//height=(cbrt(xloop)/6)+3+(sin(xloop))+(sin(zloop))+(cos(zloop))+(cos(xloop));

//height=sqrt((xloop-cs)*(zloop-cs) + (yloop-cs)*(yloop-cs) + (yloop-cs/2)*(zloop-cs/2));
//height=cbrt(273)+(sqrt(sin(zloop)+(xloop/2)+cos(xloop)/5));
//cout<<"height: "<<height<<"\n";
//height=cbrt(sin(xloop))+sqrt(cos(yloop*yloop));
//height=sqrt((xloop-cs/2)*(xloop-cs/2)+(xloop-cs/2)*(xloop-cs/2)+(zloop-cs)*(xloop-cs));
//height=cbrt((sin)(xloop*zloop)*(xloop) + (xloop-yy[1])*(zloop-yy[1]/2));
//height=sqrt((xloop-cs/2)*(xloop-cs/2) + (yloop-cs/2)*(yloop-cs/2) + (zloop-cs/2)*(zloop-cs/2));

for (yloop=0;yloop<cs;yloop++) {//cs//height
height=16;

glLoadIdentity();glRotatef(rota,roty,0,0);glRotatef(rotb,0,roty,0);glTranslatef(xloop,yloop,zloop);glTranslatef(lefta,upb,downb);
//if (cMap[xloop][yloop][zloop]==1&&yloop<=height||cMap[xloop][yloop][zloop]==2&&yloop<=height){glCallList(1);}
//if (cMap[xloop][yloop][zloop]==1&&yloop>height||cMap[xloop][yloop][zloop]==2&&yloop>height||cMap[xloop][yloop][zloop]==3&&yloop>height){glCallList(3);}
//if (cMap[xloop][yloop][zloop]==2){glCallList(0);}4
//if(height>9){height=0;}

if(!pass/*&&cMap[xloop][yloop][zloop]==0*/){//cMap[xloop][yloop][zloop]=rand()%3+0;;
    {// if (sqrt((float) (xloop-cs/2)*(xloop-cs/2) + (yloop-cs/2)*(yloop-cs/2) + (zloop-cs/2)*(zloop-cs/2)) <=cs/2){
if (yloop<height&&cMap[xloop][yloop][zloop]!=65535){cMap[xloop][yloop][zloop]=1;}
if (yloop>height&&cMap[xloop][yloop][zloop]!=65535){cMap[xloop][yloop][zloop]=0;}
if (yloop<=height&&yloop>height-1&&cMap[xloop][yloop][zloop]!=65535){cMap[xloop][yloop][zloop]=2;}
    }   
//{if(cMap[xloop][yloop][zloop]!=1000000){
//    cMap[xloop][yloop][zloop]=1;}}

static int countz=-1,dir;static double wx[10],wy[10],wz[10];static int de=0;//wx[0]=-cs/2;wy[0]=-cs/2;wz[0]=-cs/2;     
while(countz<15000/*25000*/){//cout<<height<<"::";//(countz<600/*&&wx[0]<height*/){//&&cMap[(GLint)-wx[0]][(GLint)-wy[0]][(GLint)-wz[0]]==0||countz<10&&cMap[xloop][yloop][zloop]==2){
while(countz==-1){wx[0]=cs/2;wy[0]=cs/2;wz[0]=cs/2;countz=0;break;}
           de=0;dir=rand()%6+1;//cout<<countz<<" ";
//cout<<countz<<"\n";
    int a,b,c;a=rand()%19+1;b=rand()%19+1;c=rand()%19+1;
    
        if(dir==1){wx[0]-=1;}
        if(dir==2){wx[0]+=1;} 
        if(dir==3){wy[0]-=1;}
        if(dir==4){wy[0]+=1;} 
        if(dir==5){wz[0]-=1;} 
        if(dir==6){wz[0]+=1;} 
//cout<<"x: "<<wx[0]<<" y: "<<wy[0]<<" z: "<<wz[0]<<"\n";  
if(-wx[0]>=0&&wx[0]>-20&&-wy[0]>0&&wy[0]>-20&&-wz[0]>=0&&wz[0]>-20&&-wy[0]<=(GLint)height-5&&cMap[(GLint)-wx[0]][(GLint)-wy[0]+1][(GLint)-wz[0]]==0){
if(dir==1){wx[0]-=1;}
if(dir==2){wx[0]+=1;} 
if(dir==3){wy[0]-=1;}
if(dir==4){wy[0]+=1;} 
if(dir==5){wz[0]-=1;} 
if(dir==6){wz[0]+=1;} 
if(-wx[0]>=0&&wx[0]>-20&&-wy[0]>0&&wy[0]>-20&&-wz[0]>=0&&wz[0]>-20&&-wy[0]<=(GLint)height-5&&cMap[(GLint)-wx[0]][(GLint)-wy[0]+1][(GLint)-wz[0]]==0){
de=1;}
;}  
//if(-wx[0]>=0&&wx[0]>-20&&-wy[0]>0&&wy[0]>-20&&-wz[0]>=0&&wz[0]>-20&&-wy[0]<=(GLint)height-5)
//{cMap[(GLint)-wx[0]][(GLint)-wy[0]][(GLint)-wz[0]]=0;countz+=1;}    
else if(de!=1&&-wx[0]>=0&&wx[0]>-20&&-wy[0]>0&&wy[0]>-20&&-wz[0]>=0&&wz[0]>-20&&-wy[0]<=(GLint)height-5&&cMap[(GLint)-wx[0]][(GLint)-wy[0]+1][(GLint)-wz[0]]!=0)
{cMap[(GLint)-wx[0]][(GLint)-wy[0]+1][(GLint)-wz[0]]=0;countz+=1;
//cMap[(GLint)-wx[0]+20][(GLint)-wy[0]+1][(GLint)-wz[0]+20]=0;
}
//////else{wx[0]-1*rand()%(20+0);wy[0]=-1*rand()%(20+0);wz[0]=-1*rand()%(20+0);countz+=1;}
else{wx[0]=-10;wy[0]=-10;wz[0]=-10;countz+=1;}//cout<<"Out of range! ";countz+=1;}
        //if(-wx[0]>0||-wx[0]<(-9)||-wy[0]>0||-wy[0]<(-9)||-wz[0]>0||-wz[0]<(-9))//if(wx[0]<0||wx[0]>-9||wy[0]<0||wy[0]>-9||wz[0]<0||wz[0]>(-9))
        //        {wx[0]=cs/2*-1;wy[0]=cs/2*-1;wz[0]=cs/2*-1;} 
        //cout<<"dir: "<<dir<<" countz: "<<countz<<" wx,wy,wz:[0] "<<wx[0]<<wy[0]<<wz[0]<<" a,b,c: "<<a<<","<<b<<","<<c<<"\n";        
        ;
break;}//add more random directions and add more noise to move randomly;
        //if(cMap[xloop][yloop][zloop]==1000000){cMap[xloop][yloop][zloop]=0;}


    
}
//
    if (cMap[xloop][yloop][zloop]==1){glCallList(1);}
    if (cMap[xloop][yloop][zloop]==2){glCallList(2);}
    if (cMap[xloop][yloop][zloop]==0){glCallList(0);}

/*if (cMap[xloop][yloop][zloop]==1&&yloop!=8) {glCallList(1);}
if (cMap[xloop][yloop][zloop]==2) {glCallList(2);}
if (cMap[xloop][yloop][zloop]==1&&yloop==8){cMap[xloop][8][zloop]=0;}//glCallList(0);}
//if(yloop==cs-2){glCallList(0);}
else{glCallList(0);}*/
};}};pass=1;

/*if (cMap[xloop][yloop][zloop]==1) {glCallList(1);}
if (cMap[xloop][yloop][zloop]==2) {glCallList(2);}
else{glCallList(0);}*/
//if(yloop>0){glCallList(1);}//else{glCallList(2);}

/*{
for (xloop=0;xloop<cs;xloop++){
for (yloop=0;yloop<1;yloop++){
for (zloop=0;zloop<cs;zloop++){
glLoadIdentity();glRotatef(rota,roty,0,0);glRotatef(rotb,0,roty,0);glTranslatef(xloop,yloop,zloop);glTranslatef(lefta,upb,downb);
glCallList(2);
}}};}*/
//if (o<1000){o+=1;if(maxha<1000){first[o]=rand()%256+0;maxha+=1;}}
//cout<<" o: "<<o<<" first[0]: "<<first[0]<<" first[1]: "<<first[1]<<"\n";
//////////////////////////////
//if(maxha!=1000){heighta[o]=rand()%256+0;maxha+=1;o+=1;}
//cout<<"heighta[0]: "<<heighta[0]<<" heighta[1]: "<<heighta[1]<<" heighta[100]: "<<heighta[100]<<"\n";




/*static bool p1=false;static int height;int maxh=3;static int randm;
for (xloop=0;xloop<10;xloop++){
for (zloop=0;zloop<10;zloop++){
if (randm<xloop*zloop){height=rand()%maxh+1;randm+=1;}//cout<<"Height: "<<height<<" ";}
for (yloop=0;yloop<height;yloop++){
glLoadIdentity();glRotatef(rota,roty,0,0);glRotatef(rotb,0,roty,0);glTranslatef(lefta,upb,downb);glTranslatef(xloop,yloop,zloop);
if(yloop==height-1){glCallList(1);}else if (yloop==0){glCallList(1);}else{glCallList(2);p1=true;}
;}}};*/
//why does mw not work for the down arrow if the mc value changes by 1?
//system("cls,color 1a");//cout<<"rotb: "<<rotb<<" mb: "<<mb<<" st2: "<<st2<<" st3: "<<st3<<" | mc: "<<mc<<" st5: "<<st5<<" st6: "<<st6<<" | mw: "<<mw<<" st1: "<<st1<<" st4: "<<st4<<"\n";
//cout<<" mb: "<<mb<<" mc: "<<mc<<" mw: "<<mw<<" cMap[mb,lfa][mc,upb][mw,dwb]: "<<cMap[mb][mc][mw]<<" lfa "<<lefta<<" upb "<<upb<<" dwb "<<downb<<"\n";
//if(cMap[mb][mc][mw]>0&&lefta<=0&&upb<=0&&downb<0&&lefta>-10&&upb>-10&&downb>-10){cout<<"Collision is true!\n";}
if(lefta<=0&&upb<=0&&downb<=0&&lefta>-20&&upb>-20&&downb>-20){
if(click==1&&cMap[(GLint)-lefta][(GLint)-upb][(GLint)-downb]!=0){cMap[(GLint)-lefta][(GLint)-upb][(GLint)-downb]=0;glCallList(0);}
//cout<<rotb;
while(click==2&&cMap[(GLint)-lefta][(GLint)-upb][(GLint)-downb]==0){
if(rotb>270&&cMap[(GLint)-lefta][(GLint)-upb][(GLint)-downb]==0){cMap[(GLint)-lefta][(GLint)-upb][(GLint)-downb]=blockt;break;}
if(rotb<270&&cMap[(GLint)-lefta-1][(GLint)-upb][(GLint)-downb]==0||rotb>90&&cMap[(GLint)-lefta+1][(GLint)-upb][(GLint)-downb]==0){cMap[(GLint)-lefta-1][(GLint)-upb][(GLint)-downb]=blockt;break;}
break;}
;};;//cout<<cMap[(GLint)-lefta][(GLint)-upb][(GLint)-downb]<<" ";
click=0;
//if(cMap[(GLint)-lefta][(GLint)-upb][(GLint)-downb]>0&&lefta<1&&upb<1&&downb<1&&lefta>-20&&upb>-20&&downb>-20){;}//cout<<" Collision is true!\n";}
//else{upb+=.025;}//cout<<" Collision is false!\n";}


//cout<<"\nyy[0]: "<<yy[0]<<"\n";
///*orig*/if(upb<.5&&upb>-.5&&lefta<.5&&lefta>-.5&&downb<.5&&downb>-.5&&cMap[ma][mb][mc]>0){cout<<"Collision with object: "<<cMap[ma][mb][mc]<<" is true!\n";}
//if(upb<.5&&upb>-.5&&lefta<.5&&lefta>-.5&&downb<.5&&downb>-.5&&cMap[mw][mb][mc]>0){cout<<"Collision with object: "<<cMap[mw][mb][mc]<<" is true!\n";}
//if(upb<.5&&upb>-.5&&lefta<.5&&lefta>-.5&&downb<.5&&downb>-.5&&cMap[mb][mc][mw]>0){cout<<"Collision with object: "<<cMap[mb][mc][mw]<<" is true!\n";}
//if(upb<.5&&upb>-.5&&lefta<mb&&lefta>-mb&&downb<.5&&downb>-.5&&cMap[mb][mc][mw]>0){cout<<"Collision with object: "<<cMap[mb][mc][mw]<<" is true!\n";}
//else{cout<<"Collision is false;\n";}
//make 6 doubles; and increase/decrease as ,lefta,downb changes;3 more doubles for cMap to increase/decrease accordingly;
/*dist1=sqrt(((lefta-x)*(lefta-x))+((upb-y)*(upb-y))+((downb-z)*(downb-z)));//dist bet objects.
dist2=(sqrt((lefta-x)*(lefta-x)));//distx;x
dist3=(sqrt((upb-y)*(upb-y)));//disty;y
dist4=(sqrt((downb-z)*(downb-z)));//distz;z
*///if (dist2<1.1&&dist3<1.1&&dist4<1.1){cout<<"Collision! ";}
//if (dist2<xloop&&dist3<yloop&&dist4<zloop&&lefta<=.5&&upb<=.5&&downb<=.5){collision=true;cout<<collision;}
//if (dist2<=xloop&&dist3<=cMap[xloop][yloop][zloop]&&dist4<=zloop&&lefta<=.5&&upb<=.5&&downb<=.5){collision=true;cout<<collision;}
//?if(lefta<=.5&&lefta>=-.5&&downb<=.5&&downb>=-.5&&upb<=.5&&upb>=-height){cout<<"col; "<<height;}

//else{collision=false;upb+=.1;cout<<yy[4]<<" yy: ";}
//cout<<"Collision? "<<collision<<"\n";
/*cout<<"Dist1: "<<dist1<<" Dist2: "<<dist2<<" Dist3: "<<dist3<<" Dist4: "<<dist4<<"\n";
cout<<"Lefta: "<<lefta<<" Upb: "<<upb<<" Downb: "<<downb<<"\n";
cout<<"Rotx: "<<rotx<<" Roty: "<<roty<<" Rota: "<<rota<<" Rotb: "<<rotb<<"\n";
cout<<"Xloop: "<<xloop<<" Yloop: "<<yloop<<" Zloop: "<<zloop<<"\n";
cout<<"X: "<<x<<" Y: "<<y<<" Z: "<<z;
/**///if (collision==false){upb+=.01;}
//if(mc==true){cout<<" mc: "<<mc<<"\n";}
;}

void timerCB(int millisec){glutPostRedisplay();}
void display (void) {glLoadIdentity();
time_t timea;struct tm * timeinfo;time ( &timea );timeinfo = localtime ( &timea );//Sleep(1);//seconds=timeinfo->tm_sec;
if (mstate==true){glutSetCursor(GLUT_CURSOR_NONE);glutWarpPointer(xprev,yprev);}

//add speed to this: from +-= 1,1,1,1;
//cout<<"rota: "<<rota<<" rotb: "<<rotb<<"\nlefta: "<<lefta<<" upb: "<<upb<<" downb: "<<downb<<"\nxloop: "<<xloop<<" yloop: "<<yloop<<" zloop:"<<zloop;system("CLS");
if (rotb>360){rotb=0;}
if (rotb<0){rotb=360;}
if (mstate==false){glutSetCursor(GLUT_CURSOR_LEFT_ARROW);

;}

{//light

/*glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
GLfloat amb[]={.2,.2,.2,1};
GLfloat dif[]={.8,.8,.8,1};
GLfloat spe[]={1.,1.,1.,1};
glLightfv(GL_LIGHT0,GL_AMBIENT,amb);
glLightfv(GL_LIGHT0,GL_DIFFUSE,dif);
glLightfv(GL_LIGHT0,GL_SPECULAR,spe);
GLfloat lpo[]={0,0,90,1};glLightfv(GL_LIGHT0,GL_POSITION,lpo);*/
}//light
//http://www.youtube.com/watch?v=g_0yV7jZvGg
glEnable(GL_TEXTURE_3D);
glEnable(GL_CULL_FACE);//glCullFace(GL_FRONT);
glEnable(GL_NORMALIZE);
glEnable(GL_POLYGON_OFFSET_FILL);
glEnable(GL_COLOR_MATERIAL);
glEnable(GL_BLEND);glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
glEnable(GL_DEPTH_TEST);


glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);glClearColor(0,0,0,1)/*.2,.3,.7,.1*/;
glDepthFunc(GL_GEQUAL);glClearDepth(0);//seconds=seconds+.05;cout<<"seconds: "<<seconds<<" minutes: "<<minutes<<"hours: "<<hours<<"\n";

BuildList();//lists
glPushMatrix(); MOON(); glPopMatrix();
glPushMatrix(); SUN();
/////////
/*if (sunm>325){
glEnable(GL_LIGHTING);glEnable(GL_LIGHT0);glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);
GLfloat amb[]={.2,.2,.2,1};GLfloat dif[]={.8,.8,.8,1};GLfloat spe[]={1.,1.,1.,1};
glLightfv(GL_LIGHT0,GL_AMBIENT,amb);glLightfv(GL_LIGHT0,GL_DIFFUSE,dif);glLightfv(GL_LIGHT0,GL_SPECULAR,spe);//add sunm ifs
GLfloat lpo[]={0,0,0,0};glLightfv(GL_LIGHT0,GL_POSITION,lpo);}
/////////////////////////////
if (sunm<=325){
glEnable(GL_LIGHTING);glEnable(GL_LIGHT0);
glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);
GLfloat amb[]={.2,.2,.2,1};
GLfloat dif[]={.8,.8,.8,1};
GLfloat spe[]={.8,.8,.8,1};//1,1,1,1;
glLightfv(GL_LIGHT0,GL_AMBIENT,amb);
glLightfv(GL_LIGHT0,GL_DIFFUSE,dif);
glLightfv(GL_LIGHT0,GL_SPECULAR,spe);//add sunm ifs GLfloat lpo[]={0,0,sunm/2,1};
GLfloat lpo[]={sunm,sunm,sunm+45,1};glLightfv(GL_LIGHT0,GL_POSITION,lpo);//cout<<"lpo: "<<lpo<<" amb: "<<amb<<" dif: "<<dif<<" spe: "<<spe<<"\n";/*rota*/ 
//////////////////////}
//cout<<sunm;system("CLS");
//;}
glPopMatrix();
WORLDMAIN(); 
glPushMatrix(); nightday(); glPopMatrix();
glPushMatrix(); PLAYER();glPopMatrix();
glutTimerFunc(10, timerCB,10);
glutSwapBuffers();

;}

void reshape(int w,int h){mousex=w;mousey=h;
glMatrixMode(GL_PROJECTION);glLoadIdentity();
glViewport(0,0,w,h);gluPerspective(65.5f,(GLfloat)w/(GLfloat)h,0.0f,90.0f);//45
//gluLookAt (lefta, 1.0f, downb, lefta+lx, 1.0f, lefta+lz, 0.0f, 1.0f, 0.0f);
glMatrixMode(GL_MODELVIEW);glLoadIdentity();
;}

int main (int argc, char **argv) {
    srand(time(0));
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowSize (500,500);
    glutInitWindowPosition (100,100);
    glutCreateWindow ("...");
    glutDisplayFunc (display);
    glutIdleFunc (display);
    glutReshapeFunc (reshape);
    glutMotionFunc(mousemovingpressed);
    glutPassiveMotionFunc(mousemoveunpressed);
    glutKeyboardFunc(keyPressed);
    glutKeyboardUpFunc(keyup);
    glutSpecialFunc(Skeys);
    glutSpecialUpFunc(Skeysup);
    glutMouseFunc(mouseclick);
    glutMainLoop();
    return 0;
;}
