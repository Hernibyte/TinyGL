#include "renderer/render_object.h"

namespace TGL::GFX
{
    
    render_object::render_object(const vertex_buffer::vertex_buffer_info vertex_buffer_info, GFX::vertex_attributes_layout vertex_attributes_layout, const index_buffer::index_buffer_info index_buffer_info)
    {
        m_vertex_array = vertex_array::create();
        m_vertex_array->bind();
        
        m_vertex_buffer = vertex_buffer::create(vertex_buffer_info);
        
        m_index_buffer = index_buffer::create(index_buffer_info);
        
        vertex_attributes_layout.set_attribute_layout();
        
        m_vertex_array->unbind();
    }
    
    render_object::~render_object()
    {
        
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
