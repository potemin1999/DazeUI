#ifndef FRAMEBUFFER_H_INCLUDED
#define FRAMEBUFFER_H_INCLUDED

#include

namespace daze{


class Framebuffer{
public:

    Framebuffer(){
        glGenFramebuffers(1,&pointer);
        bindFramebuffer();
    }

    ~Framebuffer(){
    }

    int use(){
        return bindFramebuffer();
    }

    int attach(Texture* t){

    }

private:

    static int Framebuffer* current = 0;
    int pointer;

    inline int bindFramebuffer(){
        if (current==this) return 1;
        glBindFramebuffer(GL_FRAMEBUFFER,pointer);
        current = this;
        return 0;
    }
};



}

#endif // FRAMEBUFFER_H_INCLUDED
