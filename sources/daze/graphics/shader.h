#ifndef SHADER_H_INCLUDED
#define SHADER_H_INCLUDED

#include "defines.h"

namespace daze{


class Shader{
private:
    static Shader* current;
    unsigned int program;
    unsigned int vertex;
    char* vertex_source;
    unsigned int fragment;
    char* fragment_source;

    int create_shader(unsigned int* handle,const char* source,int shader_type){
        *handle = glCreateShader(shader_type);
        if (handle){
            glShaderSource(*handle,1,&source,0);
            glCompileShader(*handle);
            int* status = new int;
            glGetShaderiv(*handle,GL_COMPILE_STATUS,status);
            if (!status){
                char log[1024];
                glGetShaderInfoLog(*handle, 1024, 0, log);
                //printf("vertex shader compile failed : %s\n",log);
                glDeleteShader(*handle);
            }
        }
        return 0;
    }

    int create_program(unsigned int* program, unsigned int* vertex, unsigned int* fragment){
        *program = glCreateProgram();
        if (program){
            glAttachShader(*program,*vertex);
            glAttachShader(*program,*fragment);
            glLinkProgram(*program);
            int* status = new int;
            glGetProgramiv(*program,GL_LINK_STATUS,status);
            if (!status){
                char log[1024];
                glGetProgramInfoLog(*program, 1024, 0, log);
                //printf("shader program linking failed : %s\n",log);
                glDeleteProgram(*program);
            }
            glReleaseShaderCompiler();
        }
        return 0;
    }

public:

    Shader(const char* _vertex_source,const char* _fragment_source){
        vertex_source = new char[strlen(_vertex_source)];
        fragment_source = new char[strlen(_fragment_source)];
        strcpy(vertex_source,_vertex_source);
        strcpy(fragment_source,_fragment_source);
        delete _vertex_source;
        delete _fragment_source;
    }

    ~Shader(){
        free_cache();
    }

    int compile(){
        create_shader(&vertex,(const char*)vertex_source,GL_VERTEX_SHADER);
        create_shader(&fragment,(const char*)fragment_source,GL_FRAGMENT_SHADER);
        create_program(&program,&vertex,&fragment);
        return 0;
    }

    int use(){
        if (current==this) return 1;
        glUseProgram(program);
        current = this;
        return 0;
    }

    int free_cache(){
        if (fragment_source) delete fragment_source;
        if (vertex_source) delete vertex_source;
        return 0;
    }



};





}

#endif // SHADER_H_INCLUDED
