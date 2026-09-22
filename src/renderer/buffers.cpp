#include "renderer/buffers.h"

#include "glad/gl.h"

#include "platform/assert.h"
#include "renderer/renderer.h"
#include "platform/gl/gl_buffers.h"

namespace TGL::GFX
{
    
    u32 shader_data_type_size(const shader_data_type type)
    {
        switch (type)
        {
            case shader_data_type::none:    return 0;
            case shader_data_type::float_1: return 4;
            case shader_data_type::float_2: return 4 * 2;
            case shader_data_type::float_3: return 4 * 3;
            case shader_data_type::float_4: return 4 * 4;
            case shader_data_type::mat_3:   return 4 * 3 * 3;
            case shader_data_type::mat_4:   return 4 * 4 * 4;
            case shader_data_type::int_1:   return 4;
            case shader_data_type::int_2:   return 4 * 2;
            case shader_data_type::int_3:   return 4 * 3;
            case shader_data_type::int_4:   return 4 * 4;
            case shader_data_type::bool_1:  return 1;
        }
        
        TGL_CORE_ASSERT(false, "Unknown shader data type");
        return 0;
    }
    
    u32 shader_data_type_to_glsl_type(const shader_data_type type)
    {
        switch (type)
        {
            case shader_data_type::none:    return 0;
            case shader_data_type::float_1: return GL_FLOAT;
            case shader_data_type::float_2: return GL_FLOAT;
            case shader_data_type::float_3: return GL_FLOAT;
            case shader_data_type::float_4: return GL_FLOAT;
            case shader_data_type::mat_3:   return GL_FLOAT;
            case shader_data_type::mat_4:   return GL_FLOAT;
            case shader_data_type::int_1:   return GL_INT;
            case shader_data_type::int_2:   return GL_INT;
            case shader_data_type::int_3:   return GL_INT;
            case shader_data_type::int_4:   return GL_INT;
            case shader_data_type::bool_1:  return GL_BOOL;
        }
        
        TGL_CORE_ASSERT(false, "Unknown shader data type");
        return 0;
    }
    
    vertex_attributes::vertex_attributes(const shader_data_type type, const std::string& name, const bool normalized)
        : m_name(name), m_type(type), m_normalized(normalized), m_size(shader_data_type_size(type)), m_offset(0) {}
    
    /////////////////////////////////////////////////////////////////
    // VERTEX ATTRIBUTES ////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////
    
    void vertex_attributes_layout::set_attribute_layout() const
    {
        i32 index = 0;
        for (auto& attribute : m_attributes)
        {
            glEnableVertexAttribArray(index);
            glVertexAttribPointer(
                index, 
                attribute.get_attribute_count(), 
                shader_data_type_to_glsl_type(attribute.m_type),
                attribute.m_normalized, 
                m_stride, 
                reinterpret_cast<void*>(attribute.m_offset)
            );
            
            index++;
        }
    }
    
    /////////////////////////////////////////////////////////////////
    // VERTEX BUFFER ////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////

    std::unique_ptr<vertex_buffer> vertex_buffer::create(const vertex_buffer_info& info)
    {
        return create(info.vertices, info.size);
    }
    
    std::unique_ptr<vertex_buffer> vertex_buffer::create(const f32* vertices, const u32 size)
    {
        switch (renderer::get_api())
        {
        case GFX::gfx_api::none:
            TGL_ASSERT_LOG(false, "RENDER BUFFER: [NONE] Platform not supported!");
            break;
        
        case GFX::gfx_api::opengl:
            //
            return std::make_unique<GL::gl_vertex_buffer>(vertices, size);
            break;
        
        default:
            TGL_ASSERT_LOG(false, "RENDER BUFFER: Platform not supported!");
            break;
        }
            
        return nullptr;
    }
    
    /////////////////////////////////////////////////////////////////
    // INDEX BUFFER /////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////
    
    std::unique_ptr<index_buffer> index_buffer::create(const index_buffer_info& info)
    {
        return create(info.indices, info.count);
    }
    
    std::unique_ptr<index_buffer> index_buffer::create(const u32* indices, const i32 count)
    {
        switch (renderer::get_api())
        {
        case GFX::gfx_api::none:
            TGL_ASSERT_LOG(false, "RENDER BUFFER: [NONE] Platform not supported!");
            break;
        
        case GFX::gfx_api::opengl:
            //
            return std::make_unique<GL::gl_index_buffer>(indices, count);
            break;
        
        default:
            TGL_ASSERT_LOG(false, "RENDER BUFFER: Platform not supported!");
            break;
        }
            
        return nullptr;
    }

}