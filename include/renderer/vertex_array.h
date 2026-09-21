#pragma once

#include "platform/default_types.h"

namespace TGL::GFX
{
    
    class vertex_array
    {
    public:
        vertex_array() = default;
        virtual ~vertex_array() = default;
        
        static vertex_array* create();
        
        virtual void bind() = 0;
        virtual void unbind() = 0;
        
        u32 get_id() const { return m_vertex_array_id; }
        
    protected:
        buffer_id m_vertex_array_id;
    };
    
}