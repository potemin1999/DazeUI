#include "daze/daze.h"

using namespace daze;


class TestWindow : public Window{

};







int main(int c,char** args){
    TestWindow* w = new TestWindow();
    w->setFullscreen(false);
    w->setName("TestWindow");
    w->setPosition(20,20);
    w->setSize(1280,720);
    w->run(0);
}



