#ifndef TEXTURE_H_INCLUDED
#define TEXTURE_H_INCLUDED

#include "defines.h"

#ifdef DEBUG_TEXTURE
#define DEBUG_TEXTURE_OUTPUT
#include <iostream>
#endif // DEBUG_TEXTURE

namespace daze{

class Texture{

private:
    static Texture* current;
    bool loaded = false;
    GLuint pointer = -1;
    int format = -1;
    int width = -1;
    int height = -1;
    int min_filter = GL_NEAREST;
    int mag_filter = GL_NEAREST;

    inline int bindTexture(){
        if (current==this) return 1;
        glBindTexture(GL_TEXTURE_2D, pointer);
        current = this;
        return 0;
    }

    inline void gen(unsigned int* pointer){
        glGenTextures(1,pointer);
    }

public:

    Texture(int _format){
        format = _format;
        gen(&pointer);
        bindTexture();
    }

    Texture(int _width,int _height,int _format){
        format = _format;
        gen(&pointer);
        bindTexture();
        setSize(_width,_height);
    }

    Texture(int _width,int _height){
        format = GL_RGBA;
        gen(&pointer);
        bindTexture();
        setSize(_width,_height);
    }

    Texture(int _width,int _height,int _format,void* _data,int _data_type){
        format = _format;
        gen(&pointer);
        bindTexture();
        setSize(_width,_height);
        setData(_data,_data_type);
    }



    ~Texture(){
    }

    void setData(void* _data,int _data_type){
        bindTexture();
        glTexImage2D(GL_TEXTURE_2D,0,format,width,height,0,format,_data_type,_data);
        loaded = true;
    }

    void setSize(int _width,int _height){
        width = _width;
        height = _height;
    }

    void setFilters(int _min_filter,int _mag_filter){
        bindTexture();
        min_filter = _min_filter;
        mag_filter = _mag_filter;
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mag_filter);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, min_filter);
    }

    void use(){
        bindTexture();
    }

    unsigned getPointer(){
        return pointer;
    }

    bool isLoaded(){
        return loaded;
    }

};

}

#endif // TEXTURE_H_INCLUDED
