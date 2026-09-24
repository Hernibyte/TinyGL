#pragma once 

#include "renderer/vertex_array.h"

namespace TGL::GL
{
    
    class gl_vertex_array : public GFX::vertex_array
    {
    public:
        gl_vertex_array();
        virtual ~gl_vertex_array() override;
    
        virtual void bind() override;
        virtual void unbind() override;
    };
    
}