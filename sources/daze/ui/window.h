#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include <thread>
#include "string.h"
#include "stdlib.h"

namespace daze{

class Window{

private:

    bool fullscreen = false;
    int* size = new int[2];
    int* position = new int[2];
    char* name;
    std::thread* main;

    virtual int internal_run(void* parameters);
    int resize(char pointer...);
    int key(char pointer...);

public:

    Window();
    virtual ~Window();

    virtual void onCreate();
    virtual void onDestroy();
    virtual void onDraw();
    virtual void onPause();
    virtual void onResume();

    virtual int run(void* parameters){
        internal_run(0);
        //main = (std::thread*) malloc(sizeof(std::thread));
        //std::thread(&this->internal_run,this,parameters);
        return 0;
    }

    void setFullscreen(bool is){
        fullscreen = is;
    }

    bool isFullscreen(){return fullscreen;}

    void setSize(int width,int height){
        size[0] = width;
        size[1] = height;
    }

    int* getSize(){return size;}

    void setPosition(int x,int y){
        position[0] = x;
        position[1] = y;
    }

    int* getPosition(){return position;}

    void setName(char* _name){
        name = new char[strlen(_name)];
        strcpy(name,_name);
        delete _name;
    }

    char* getName(){return name;}
};


}

/** typical use
  Create your own custom class
  Window* w = new CustomWindow();
  It runs in a new thread
  w->run();

*/


#endif // WINDOW_H_INCLUDED
