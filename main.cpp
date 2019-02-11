#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <OpenGL/glext.h>

void DrawCube(GLfloat size)
{
    glBegin(GL_QUADS);
    // левая грань
    glVertex3f( -size / 2, -size / 2, -size / 2);
    glVertex3f( -size / 2,  size / 2, -size / 2);
    glVertex3f( -size / 2,  size / 2,  size / 2);
    glVertex3f( -size / 2, -size / 2,  size / 2);
    // правая грань
    glVertex3f(  size / 2, -size / 2, -size / 2);
    glVertex3f(  size / 2, -size / 2,  size / 2);
    glVertex3f(  size / 2,  size / 2,  size / 2);
    glVertex3f(  size / 2,  size / 2, -size / 2);
    // нижняя грань
    glVertex3f( -size / 2, -size / 2, -size / 2);
    glVertex3f( -size / 2, -size / 2,  size / 2);
    glVertex3f(  size / 2, -size / 2,  size / 2);
    glVertex3f(  size / 2, -size / 2, -size / 2);
    // верхняя грань
    glVertex3f( -size / 2, size / 2, -size / 2);
    glVertex3f( -size / 2, size / 2,  size / 2);
    glVertex3f(  size / 2, size / 2,  size / 2);
    glVertex3f(  size / 2, size / 2, -size / 2);
    // задняя грань
    glVertex3f( -size / 2, -size / 2, -size / 2);
    glVertex3f(  size / 2, -size / 2, -size / 2);
    glVertex3f(  size / 2,  size / 2, -size / 2);
    glVertex3f( -size / 2,  size / 2, -size / 2);
    // передняя грань
    glVertex3f( -size / 2, -size / 2,  size / 2);
    glVertex3f(  size / 2, -size / 2,  size / 2);
    glVertex3f(  size / 2,  size / 2,  size / 2);
    glVertex3f( -size / 2,  size / 2,  size / 2);
    glEnd();
}

int main()
{
    // Create the main window
    sf::RenderWindow App(sf::VideoMode(1600, 1200, 32), "mod1");

    // Create a clock for measuring time elapsed
    sf::Clock Clock;

    //prepare OpenGL surface for HSR
    glClearDepth(1.f);
    glClearColor(0.3f, 0.3f, 0.3f, 0.f);
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);

    //// Setup a perspective projection & Camera position
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.f, 1.f, 1.f, 300.0f);//fov, aspect, zNear, zFar


    bool rotate=true;
    float angle;

    // Start game loop
    while (App.isOpen())
    {
        // Process events
        sf::Event Event;
        while (App.pollEvent(Event))
        {
            // Close window : exit
            if (Event.type == sf::Event::Closed)
                App.close();

            // Escape key : exit
            if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
                App.close();

            if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::A)){
                rotate=!rotate;
            }

        }

        //Prepare for drawing
        // Clear color and depth buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Apply some transformations for the cube
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.f, 0.f, -200.f);

        if(rotate){
            angle=Clock.getElapsedTime().asSeconds();
        }
        glRotatef(angle * 50, 1.f, 0.f, 0.f);
        glRotatef(angle * 30, 0.f, 1.f, 0.f);
        glRotatef(angle * 90, 0.f, 0.f, 1.f);

        glLineWidth(2);       // ширину линии
        // устанавливаем 1
        glBegin(GL_LINES);

        glColor3d(1,0,0);     // красный цвет
        glVertex3d(0,0,0); // первая линия
        glVertex3d(50,0,0);

        glColor3d(0,1,0);     // зеленый
        glVertex3d(0,0,0); // вторая линия
        glVertex3d(-50,0,0);

        glColor3d(0,0,1);
        glVertex3d(0,0,0);
        glVertex3d(0,50,0);

        glColor3d(0,1,1);
        glVertex3d(0,0,0);
        glVertex3d(0,-50,0);

        glEnd();

        //DrawCube(100);

        //Draw a cube
//        glBegin(GL_QUADS);//draw some squares
//        glColor3f(0,1,1); //cyan
//        glVertex3f(-50.f, -50.f, -50.f);
//        glVertex3f(-50.f,  50.f, -50.f);
//        glVertex3f( 50.f,  50.f, -50.f);
//        glVertex3f( 50.f, -50.f, -50.f);
//
//        glColor3f(0,0,1); //blue
//        glVertex3f( 50.f, -50.f, 50.f);
//        glVertex3f( 50.f,  50.f, 50.f);
//        glVertex3f(-50.f,  50.f, 50.f);
//        glVertex3f(-50.f, -50.f, 50.f);
//
//        glColor3f(1,0,1); //magenta
//        glVertex3f(-50.f, -50.f,  50.f);
//        glVertex3f(-50.f,  50.f,  50.f);
//        glVertex3f(-50.f,  50.f, -50.f);
//        glVertex3f(-50.f, -50.f, -50.f);
//
//        glColor3f(0,1,0); //green
//        glVertex3f(50.f, -50.f, -50.f);
//        glVertex3f(50.f,  50.f, -50.f);
//        glVertex3f(50.f,  50.f,  50.f);
//        glVertex3f(50.f, -50.f,  50.f);
//
//        glColor3f(1,1,0); //yellow
//        glVertex3f(-50.f, -50.f,  50.f);
//        glVertex3f(-50.f, -50.f, -50.f);
//        glVertex3f( 50.f, -50.f, -50.f);
//        glVertex3f( 50.f, -50.f,  50.f);
//
//        glColor3f(1,0,0); //red
//        glVertex3f( 50.f, 50.f,  50.f);
//        glVertex3f( 50.f, 50.f, -50.f);
//        glVertex3f(-50.f, 50.f, -50.f);
//        glVertex3f(-50.f, 50.f,  50.f);
//        glEnd();

        // Finally, display rendered frame on screen
        App.display();
    }

    return EXIT_SUCCESS;
}


// https://www.codeproject.com/Articles/14154/OpenGL-Terrain-Generation-An-Introduction
// https://medium.com/@edkins.sarah/set-up-sdl2-on-your-mac-without-xcode-6b0c33b723f7
// https://github.com/itoral/gl-terrain-demo

//https://habr.com/en/post/311808/
//https://compgraphics.info/OpenGL/draw_a_cube.php
//https://gist.github.com/kenpower/4018118