#include "renderer/shapes/shape.h"

namespace TGL::SHAPE
{
    
    triangle::triangle(const std::shared_ptr<GFX::shader_program>& shader_program)
    {
        m_shader_program = shader_program;
        
        float vertices[3 * 3] = {
            0.5f, 0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            -0.5f,  -0.5f, 0.0f
        };
    
        u32 indices[3 * 2] = {
            0, 1, 3,
            1, 2, 3
        };
    
        TGL::GFX::vertex_buffer::vertex_buffer_info vertex_buffer_info = { vertices, sizeof(vertices) };
        TGL::GFX::index_buffer::index_buffer_info index_buffer_info = { indices, sizeof(indices) };
    
        TGL::GFX::vertex_attributes_layout vertex_attributes_layout = {
            { TGL::GFX::shader_data_type::float_3, "a_Position" }
        };
        
        m_render_object = std::make_shared<GFX::render_object>(vertex_buffer_info, vertex_attributes_layout, index_buffer_info);
    }

    square::square(const std::shared_ptr<GFX::shader_program>& shader_program)
    {
        m_shader_program = shader_program;
        
        float vertices[4 * 3] = {
            0.5f, 0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            -0.5f,  -0.5f, 0.0f,
            -0.5f, 0.5f, 0.0f
        };
    
        u32 indices[3 * 2] = {
            0, 1, 3,
            1, 2, 3
        };
    
        TGL::GFX::vertex_buffer::vertex_buffer_info vertex_buffer_info = { vertices, sizeof(vertices) };
        TGL::GFX::index_buffer::index_buffer_info index_buffer_info = { indices, sizeof(indices) };
    
        TGL::GFX::vertex_attributes_layout vertex_attributes_layout = {
            { TGL::GFX::shader_data_type::float_3, "a_Position" }
        };
        
        m_render_object = std::make_shared<GFX::render_object>(vertex_buffer_info, vertex_attributes_layout, index_buffer_info);
    }
    
}
