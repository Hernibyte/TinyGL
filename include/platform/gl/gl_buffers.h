#pragma once

#include "renderer/buffers.h"
#include "platform/default_types.h"

namespace TGL::GL
{
    /////////////////////////////////////////////////////////////////
    // VERTEX BUFFER ////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////
    class gl_vertex_buffer : public GFX::vertex_buffer
    {
    public:
        gl_vertex_buffer(const f32* vertices, const u32 size);
        virtual ~gl_vertex_buffer() override;
        
        virtual u32 get_size() override { return m_size; };
        
        virtual void bind() override;
        virtual void unbind() override;
        
    private:
        u32 m_size;
    };
    
    /////////////////////////////////////////////////////////////////
    // INDEX BUFFER /////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////
    class gl_index_buffer : public GFX::index_buffer
    {
    public:
        gl_index_buffer(const u32* indices, const u32 count);
        virtual ~gl_index_buffer() override;
        
        virtual u32 get_count() override { return m_count; };
        
        virtual void bind() override;
        virtual void unbind() override;
        
    private:
        u32 m_count;
    };

}