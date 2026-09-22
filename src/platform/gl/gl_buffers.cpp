#include "platform/gl/gl_buffers.h"

#include "glad/gl.h"

namespace TGL::GL
{
    /////////////////////////////////////////////////////////////////
    // VERTEX BUFFER ////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////
    
    gl_vertex_buffer::gl_vertex_buffer(const f32* vertices, const u32 size)
    {
        m_size = size;
        
        glGenBuffers(1, &m_buffer_id);
        glBindBuffer(GL_ARRAY_BUFFER, m_buffer_id);
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
    }

    gl_vertex_buffer::~gl_vertex_buffer()
    {
        glDeleteBuffers(1, &m_buffer_id);
    }

    void gl_vertex_buffer::bind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_buffer_id);
    }

    void gl_vertex_buffer::unbind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    /////////////////////////////////////////////////////////////////
    // INDEX BUFFER /////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////
    
    gl_index_buffer::gl_index_buffer(const u32* indices, const i32 count)
    {
        m_count = count;
        
        glGenBuffers(1, &m_buffer_id);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_buffer_id);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count, indices, GL_STATIC_DRAW);
    }

    gl_index_buffer::~gl_index_buffer()
    {
        glDeleteBuffers(1, &m_buffer_id);
    }

    void gl_index_buffer::bind()
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_buffer_id);
    }

    void gl_index_buffer::unbind()
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
    
}
