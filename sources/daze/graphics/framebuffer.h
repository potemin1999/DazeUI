#ifndef FRAMEBUFFER_H_INCLUDED
#define FRAMEBUFFER_H_INCLUDED

#include "defines.h"

namespace daze{


class Framebuffer{

private:

    static Framebuffer* current;
    unsigned int pointer;

    inline int bindFramebuffer(){
        if (current==this) return 1;
        glBindFramebuffer(GL_FRAMEBUFFER,pointer);
        current = this;
        return 0;
    }

public:

    Framebuffer(){
        glGenFramebuffers(1,&pointer);
        bindFramebuffer();
    }

    ~Framebuffer(){

    }

    inline int use(){
        return bindFramebuffer();
    }

    int attach(int attachment,Texture* t){
        glFramebufferTexture2D(GL_FRAMEBUFFER, attachment, GL_TEXTURE_2D, t->getPointer(), 0);
        t->onAttach(this);
        return 0;
    }

    int attach(Texture* t){
        glFramebufferTexture2D(GL_FRAMEBUFFER,GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D,t->getPointer(), 0);
        t->onAttach(this);
        return 0;
    }

};



}

#endif // FRAMEBUFFER_H_INCLUDED
