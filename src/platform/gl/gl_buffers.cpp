#include "platform/gl/gl_buffers.h"

#include "glad/gl.h"

namespace TGL::GL
{
    
    u32 shader_data_type_to_glsl_type(const GFX::shader_data_type type)
    {
        switch (type)
        {
        case GFX::shader_data_type::none:    return 0; 
        case GFX::shader_data_type::float_1: return GL_FLOAT; 
        case GFX::shader_data_type::float_2: return GL_FLOAT; 
        case GFX::shader_data_type::float_3: return GL_FLOAT; 
        case GFX::shader_data_type::float_4: return GL_FLOAT;
        case GFX::shader_data_type::mat_3:   return GL_FLOAT;
        case GFX::shader_data_type::mat_4:   return GL_FLOAT;
        case GFX::shader_data_type::int_1:   return GL_INT;
        case GFX::shader_data_type::int_2:   return GL_INT;
        case GFX::shader_data_type::int_3:   return GL_INT;
        case GFX::shader_data_type::int_4:   return GL_INT;
        case GFX::shader_data_type::bool_1:  return GL_BOOL;
        }
        
        TGL_CORE_ASSERT(false, "Unknown shader data type");
        return 0;
    }
    
    /////////////////////////////////////////////////////////////////
    // VERTEX BUFFER ////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////
    
    gl_vertex_buffer::gl_vertex_buffer(const f32* vertices, const i32 size, const GFX::vertex_attributes_layout& attributes_layout)
    {
        m_size = size;
        m_attributes_layout = attributes_layout;
        
        glGenBuffers(1, &m_buffer_id);
        glBindBuffer(GL_ARRAY_BUFFER, m_buffer_id);
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
        
        i32 index = 0;
        for (auto& attribute : m_attributes_layout)
        {
            glEnableVertexAttribArray(index);
            glVertexAttribPointer(
                index, 
                attribute.get_attribute_count(), 
                shader_data_type_to_glsl_type(attribute.m_type),
                attribute.m_normalized,
                m_attributes_layout.get_stride(),
                reinterpret_cast<void*>(attribute.m_offset)
            );
            
            index++;
        }
        
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
    
    gl_index_buffer::gl_index_buffer(const i32* indices, const i32 count)
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
