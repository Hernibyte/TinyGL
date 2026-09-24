#pragma once

#include "renderer/buffers.h"
#include "platform/default_types.h"

namespace TGL::GL
{
    static u32 shader_data_type_to_glsl_type(const GFX::shader_data_type type);
    
    /////////////////////////////////////////////////////////////////
    // VERTEX BUFFER ////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////
    class gl_vertex_buffer : public GFX::vertex_buffer
    {
    public:
        gl_vertex_buffer(const f32* vertices, const i32 size, const GFX::vertex_attributes_layout& attributes_layout);
        virtual ~gl_vertex_buffer() override;
        
        virtual i32 get_size() override { return m_size; };
        
        virtual void bind() override;
        virtual void unbind() override;
        
    private:
        i32 m_size;
    };
    
    /////////////////////////////////////////////////////////////////
    // INDEX BUFFER /////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////
    class gl_index_buffer : public GFX::index_buffer
    {
    public:
        gl_index_buffer(const i32* indices, const i32 count);
        virtual ~gl_index_buffer() override;
        
        virtual i32 get_count() override { return m_count; };
        
        virtual void bind() override;
        virtual void unbind() override;
        
    private:
        i32 m_count;
    };

}