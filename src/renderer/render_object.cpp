#include "renderer/render_object.h"

namespace TGL::GFX
{
    
    render_object::render_object(const vertex_buffer::vertex_buffer_info vertex_buffer_info, const index_buffer::index_buffer_info index_buffer_info)
    {
        m_vertex_array = vertex_array::create();
        m_vertex_array->bind();
        
        m_vertex_buffer = vertex_buffer::create(vertex_buffer_info);
        
        m_index_buffer = index_buffer::create(index_buffer_info);
        
        //m_vertex_array->unbind();
    }
    
    render_object::~render_object()
    {
        if (m_vertex_array)
            delete m_vertex_array;
        if (m_vertex_buffer)
            delete m_vertex_buffer;
        if (m_index_buffer)
            delete m_index_buffer;
    }

    void render_object::bind() const
    {
        m_vertex_array->bind();
    }

    void render_object::unbind() const
    {
        m_vertex_array->unbind();
    }
    
}
