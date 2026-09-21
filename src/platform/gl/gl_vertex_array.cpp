#include "platform/gl/gl_vertex_array.h"

#include "glad/gl.h"

namespace TGL::GL
{
    
    gl_vertex_array::gl_vertex_array()
    {
        glGenVertexArrays(1, &m_vertex_array_id);
    }
    
    gl_vertex_array::~gl_vertex_array()
    {
        glDeleteVertexArrays(1, &m_vertex_array_id);
    }
    
    void gl_vertex_array::bind()
    {
        glBindVertexArray(m_vertex_array_id);
    }
    
    void gl_vertex_array::unbind()
    {
        glBindVertexArray(0);
    }
    
}
