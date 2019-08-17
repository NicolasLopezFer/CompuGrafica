//  introOpenGL.cpp
//  Creado por Andrea Rueda, 01/2018
//

#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <cstdlib>
#include <time.h>
#define  RAND_MAX 1

void myInit (void)
{

    glClearColor(1.0,1.0,1.0,1.0);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(0, 360, 0, 600);
    //glOrtho(0, 640, 0, 480, 1.0, -1.0);

}

void pintar(int x0, int y0,int xf,int yf)
{
    for(int i = x0; i<=xf; i++)
    {
        for(int j = y0; j<yf; j++)
        {
            glVertex2i(i,j);
        }
    }
}
void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    //Colores
    //glColor3f(0.9,0.89,0.87);
    glColor3f(1.0,0,0);
    glBegin(GL_POINTS);
    glPointSize(27.0);
      glVertex2i(180,140);
    glEnd();


    //BORDE ---------------------------------------------------
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POINTS);
//-----------------------------------Primera linea curva de abajo hacia arriba
pintar(111,35,129,39);
  pintar(96,38,111,42);
  pintar(87,41,105,45);
  pintar(78,44,93,48);
  pintar(72,47,87,51);
  pintar(63,50,78,54);
  pintar(60,53,66,57);
  pintar(54,56,62,60);
  pintar(51,59,54,63);
  pintar(47,62,54,66);
  pintar(42,65,51,69);
  pintar(39,68,45,72);
  pintar(36,71,42,75);
  pintar(35,71,39,78);
  pintar(33,77,36,90);
  pintar(30,77,33,111);
  pintar(27,90,30,123);

    for(int j = 129; j<210; j++)
    {
        for(int i = 33; i<39; i++)
        {
            glVertex2i(j,i);
        }
    }
//---------------------------------------------------------------------------
    for(int i = 210; i<213; i++)
    {
        for(int j = 33; j<42; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 213; i<228; i++)
    {
        for(int j = 36; j<42; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 228; i<231; i++)
    {
        for(int j = 36; j<45; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 231; i<243; i++)
    {
        for(int j = 39; j<45; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 243; i<246; i++)
    {
        for(int j = 39; j<48; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 246; i<255; i++)
    {
        for(int j = 42; j<48; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 255; i<258; i++)
    {
        for(int j = 42; j<51; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 258; i<267; i++)
    {
        for(int j = 45; j<51; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 267; i<270; i++)
    {
        for(int j = 45; j<54; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 270; i<273; i++)
    {
        for(int j = 48; j<54; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 273; i<276; i++)
    {
        for(int j = 48; j<57; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 276; i<282; i++)
    {
        for(int j = 51; j<57; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i =282 ; i<288; i++)
    {
        for(int j = 54; j<60; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 288; i<294; i++)
    {
        for(int j = 57; j<63; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 294; i<297; i++)
    {
        for(int j = 60; j<66; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 297; i<300; i++)
    {
        for(int j = 63; j<69; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 300; i<306; i++)
    {
        for(int j = 66; j<72; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 306; i<309; i++)
    {
        for(int j = 69; j<75; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 309; i<312; i++)
    {
        for(int j = 72; j<81; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 312; i<315; i++)
    {
        for(int j = 78; j<87; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 315; i<318; i++)
    {
        for(int j = 81; j<96; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 318; i<321; i++)
    {
        for(int j = 90; j<174; j++)
        {
            glVertex2i(i,j);
        }
    }
    for(int i = 321; i<323; i++)
    {
        for(int j = 150; j<219; j++)
        {
            glVertex2i(i,j);
        }
    }
//---------------------------------------------- lineas curvas de los lados (las lineas mas largas)
    for(int i = 322; i<325; i++)
    {
        for(int j = 219; j<420; j++)
        {
            glVertex2i(i,j);
        }
    }
    pintar(24,102,27,192);
    pintar(21,136,24,303);
//---------------------------------------------------
    pintar(315,411,325,420);
    pintar(312,408,315,414);
    pintar(306,405,312,411);
    pintar(303,402,309,408);
    pintar(300,399,303,405);
    pintar(297,396,300,402);
    pintar(294,393,297,399);
    pintar(288,390,294,396);
    pintar(282,384,288,393);
    pintar(279,381,282,387);
    pintar(273,378,279,384);
    pintar(270,375,273,381);
    pintar(267,372,270,378);
    pintar(261,369,267,375);
    pintar(258,366,264,372);
    pintar(252,363,258,369);
    pintar(249,360,255,366);
    pintar(243,357,249,363);
    pintar(240,354,246,360);
    pintar(234,351,240,357);
    pintar(228,348,234,354);
    pintar(225,345,231,351);
    pintar(222,342,225,348);
    pintar(216,339,222,345);
    pintar(210,336,216,342);
    pintar(204,333,210,339);
    pintar(198,330,207,336);
    pintar(192,327,201,333);
    pintar(186,324,192,330);
    pintar(180,321,186,327);

    pintar(168,318,180,324);//Centro


    pintar(160,321,168,327);
    pintar(154,324,160,330);
    pintar(145,327,154,333);
    pintar(139,330,145,336);
    pintar(133,333,139,339);
    pintar(127,336,133,342);
    pintar(121,339,127,345);
    pintar(115,342,121,348);
    pintar(109,345,115,351);
    pintar(103,348,109,354);
    pintar(100,351,103,357);
    pintar(94,353,100,359);
    pintar(91,356,94,362);
    pintar(85,359,91,365);
    pintar(82,362,85,368);
    pintar(76,365,82,371);
    pintar(73,368,79,374);
    pintar(67,371,73,377);
    pintar(64,374,67,380);
    pintar(59,377,64,383);
    pintar(57,380,59,386);
    pintar(52,383,57,389);
    pintar(50,386,52,392);
    pintar(48,389,50,395);
    pintar(43,392,48,398);
    pintar(41,395,43,401);
    pintar(36,398,41,404);
    pintar(34,401,36,407);
    pintar(32,404,34,410);
    pintar(27,407,32,414);
    pintar(21,410,27,420);

//--------------------------------











//--------------------------------------------------
    for(int i = 312; i<318; i++)
    {
        for(int j = 114; j<120; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 309; i<312; i++)
    {
        for(int j = 111; j<117; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 306; i<309; i++)
    {
        for(int j = 111; j<114; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 303; i<306; i++)
    {
        for(int j = 108; j<114; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 300; i<303; i++)
    {
        for(int j = 105; j<111; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 294; i<300; i++)
    {
        for(int j = 105; j<108; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 291; i<294; i++)
    {
        for(int j = 102; j<108; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 288; i<291; i++)
    {
        for(int j = 102; j<105; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 285; i<288; i++)
    {
        for(int j = 99; j<105; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 279; i<285; i++)
    {
        for(int j = 99; j<102; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 276; i<279; i++)
    {
        for(int j = 96; j<102; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 267; i<276; i++)
    {
        for(int j = 96; j<99; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 264; i<267; i++)
    {
        for(int j = 93; j<99; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 252; i<264; i++)
    {
        for(int j = 93; j<96; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 249; i<252; i++)
    {
        for(int j = 87; j<96; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 237; i<249; i++)
    {
        for(int j = 87; j<93; j++)
        {
            glVertex2i(i,j);
        }
    }

    for(int i = 234; i<237; i++)
    {
        for(int j = 84; j<93; j++)
        {
            glVertex2i(i,j);
        }
    }
//---------------------------------------------------- linea curva debajo de BEER
    for(int i = 125; i<234; i++)
    {
        for(int j = 84; j<90; j++)
        {
            glVertex2i(i,j);
        }
    }
    pintar(111,87,125,93);
    pintar(86,90,114,96);
    pintar(79,96,89,102);
    pintar(66,99,79,105);
    pintar(60,105,69,108);
    pintar(50,108,63,111);
    pintar(42,111,53,114);
    pintar(36,114,45,117);
    pintar(30,117,39,120);
    pintar(27,117,33,123);
//-----------------------------------------------------


    //LETRAS-------------------------------------------

    //LETRA B
    pintar(90,114,99,150);
    pintar(99,141,105,147);
    pintar(105,138,114,147);
    pintar(114,129,117,144);
    pintar(117,132,120,141);
    pintar(108,111,114,147);
    pintar(105,123,108,135);
    pintar(99,126,105,132);
    pintar(114,111,117,126);
    pintar(117,114,120,126);
    pintar(105,111,108,120);
    pintar(99,111,105,117);

    //LETRAS E
    pintar(138,108,147,144);
    pintar(147,135,162,144);
    pintar(147,120,159,129);
    pintar(147,108,162,114);

    pintar(183,108,192,144);
    pintar(192,135,207,144);
    pintar(192,120,204,129);
    pintar(192,108,207,114);

    //LETRA R
    pintar(231,111,243,147);
    pintar(243,141,261,147);
    pintar(261,135,264,144);
    pintar(249,138,261,141);
    pintar(252,135,261,138);
    pintar(246,132,261,135);
    pintar(243,123,255,132);
    pintar(249,120,267,123);
    pintar(255,123,258,129);
    pintar(258,123,264,126);
    pintar(252,117,267,120);
    pintar(258,114,264,117);

    //LETRA D
    pintar(69,162,75,348);
    pintar(66,315,69,348);
    pintar(75,162,84,345);
    pintar(84,165,90,342);
    pintar(90,165,93,249);
    pintar(90,309,105,312);
    pintar(90,318,93,339);
    pintar(93,315,96,339);
    pintar(96,315,99,336);
    pintar(99,312,105,333);
    pintar(105,303,108,330);
    pintar(108,297,111,327);
    pintar(111,291,114,324);
    pintar(114,282,117,321);
    pintar(117,273,120,318);
    pintar(93,168,96,198);
    pintar(96,171,99,201);
    pintar(99,171,102,204);
    pintar(102,174,105,207);
    pintar(105,177,108,210);
    pintar(108,177,111,216);
    pintar(111,183,114,222);
    pintar(114,186,117,234);
    pintar(117,189,120,243);
    pintar(120,192,123,315);
    pintar(123,198,126,312);
    pintar(126,204,129,309);
    pintar(129,207,132,303);
    pintar(132,213,135,297);
    pintar(135,219,138,291);
    pintar(138,234,141,282);
    pintar(141,249,144,270);

    //LETRA U
    pintar(147,207,150,249);
    pintar(150,201,153,252);
    pintar(153,194,162,252);
    pintar(159,191,183,194);
    pintar(162,194,165,249);
    pintar(165,194,171,219);
    pintar(171,194,174,246);
    pintar(174,194,183,252);
    pintar(183,198,186,252);
    pintar(186,204,189,252);
    pintar(189,210,192,249);

    //LETRA F
    pintar(189,180,192,189);
    pintar(192,171,204,192);
    pintar(198,165,204,171);
    pintar(198,224,201,231);
    pintar(201,213,207,234);
    pintar(207,216,210,237);
    pintar(210,219,213,237);
    pintar(204,162,207,189);
    pintar(207,162,210,186);
    pintar(210,162,213,195);
    pintar(213,162,216,330);
    pintar(216,162,219,333);
    pintar(219,162,222,336);
    pintar(222,165,228,339);
    pintar(228,171,231,339);
    pintar(231,177,234,336);
    pintar(234,177,237,180);
    pintar(234,228,237,270);
    pintar(234,309,237,336);
    pintar(237,177,240,192);
    pintar(237,228,240,249);
    pintar(237,306,240,333);
    pintar(240,174,243,195);
    pintar(240,231,243,252);
    pintar(240,306,243,333);
    pintar(243,168,246,195);
    pintar(243,231,246,252);
    pintar(243,306,246,330);
    pintar(246,168,249,195);
    pintar(246,234,249,255);
    pintar(246,309,249,321);
    pintar(249,165,252,195);
    pintar(249,234,252,255);
    pintar(249,312,252,318);
    pintar(252,165,255,192);
    pintar(252,237,255,318);
    pintar(255,165,258,336);
    pintar(258,165,261,339);
    pintar(261,165,264,342);
    pintar(264,165,267,345);
    pintar(267,171,270,348);
    pintar(270,180,273,348);
    pintar(273,243,276,264);
    pintar(273,321,276,348);
    pintar(276,243,279,267);
    pintar(276,318,279,345);
    pintar(279,246,285,267);
    pintar(285,249,288,267);
    pintar(279,318,282,345);
    pintar(282,318,285,342);
    pintar(285,321,288,339);
    pintar(288,324,291,330);

    //CUADRADO LETRAS
    pintar(129,306,216,309);
    pintar(150,303,174,306);
    pintar(204,309,213,312);
    pintar(57,315,66,318);
    pintar(48,318,63,321);
    pintar(51,189,54,321);
    pintar(48,300,51,321);
    pintar(54,186,57,192);
    pintar(57,186,66,189);
    pintar(63,183,69,186);
    pintar(108,177,117,180);
    pintar(108,174,150,177);
    pintar(132,171,195,174);
    pintar(180,174,195,177);
    pintar(270,186,285,189);
    pintar(276,189,291,192);
    pintar(288,192,297,195);
    pintar(291,195,294,207);
    pintar(294,195,297,333);
    pintar(297,234,300,333);
    pintar(291,327,294,330);

    //-------------------------------------------------


    //DONDE SE ABRE
    pintar(105,507,231,510);
    pintar(213,510,255,513);
    pintar(243,513,267,516);
    pintar(261,516,279,519);
    pintar(270,519,285,522);
    pintar(279,522,288,525);
    pintar(285,525,291,528);
    pintar(288,528,294,531);
    pintar(288,531,294,534);
    pintar(285,534,291,537);
    pintar(267,522,276,525);
    pintar(258,525,273,528);
    pintar(249,528,267,531);
    pintar(237,531,258,534);
    pintar(231,534,246,537);
    pintar(81,510,120,513);
    pintar(66,513,96,516);
    pintar(57,516,75,519);
    pintar(51,519,66,522);
    pintar(48,522,54,525);
    pintar(45,525,51,528);
    pintar(45,528,48,531);
    pintar(45,531,54,534);
    pintar(48,534,54,537);
    pintar(60,522,72,525);
    pintar(66,525,81,528);
    pintar(69,528,84,531);
    pintar(102,534,111,537);
    pintar(102,537,135,540);
    pintar(120,540,144,543);
    pintar(123,510,132,513);
    pintar(126,513,135,516);
    pintar(129,516,138,519);
    pintar(135,519,144,522);
    pintar(141,522,153,525);
    pintar(141,525,147,528);
    pintar(144,528,150,531);
    pintar(147,531,153,534);
    pintar(150,534,159,537);
    pintar(156,537,162,540);
    pintar(159,540,168,543);
    pintar(165,543,210,546);
    pintar(207,540,216,543);
    pintar(213,534,219,540);
    pintar(210,531,216,534);
    pintar(207,528,213,531);
    pintar(204,525,210,528);
    pintar(197,522,207,525);
    pintar(191,519,204,522);
    pintar(186,516,197,519);
    pintar(186,510,191,516);
    pintar(137,510,143,513);
    pintar(167,510,173,513);
    pintar(140,513,170,516);
    pintar(150,519,189,522);
    pintar(156,522,180,525);
    pintar(159,525,177,528);

    glEnd();
    //FIN BORDE --------------------------------------------

    glutSwapBuffers();
    glFlush();
}


void myResize (int w, int h)
{

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(0, w, 0, h);


}


int main (int argc, char** argv)
{

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(360, 600);

    glutInitWindowPosition(200, 100);

    glutCreateWindow("Duff Beer");

    glutDisplayFunc(myDisplay);

    myInit();

    glutReshapeFunc(myResize);

    glutMainLoop();

    return 0;

}
