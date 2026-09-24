#include "renderer/shapes/shape.h"

namespace TGL::SHAPE
{
    
    triangle::triangle(const std::shared_ptr<GFX::shader_program>& shader_program)
    {
        m_shader_program = shader_program;
        
        float vertices[3 * 3] = {
            -0.5f, -0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
             0.0f,  0.5f, 0.0f
        };  
    
        i32 indices[3] = {
            0, 1, 2
        };
    
        TGL::GFX::vertex_buffer::vertex_buffer_info vertex_buffer_info = {
            vertices, 
            9 * sizeof(float),
{ {TGL::GFX::shader_data_type::float_3, "a_Position"} }
        };
        
        TGL::GFX::index_buffer::index_buffer_info index_buffer_info = {
            indices, 
            3 * sizeof(u32)
        };
        
        m_render_object = std::make_shared<GFX::render_object>(vertex_buffer_info, index_buffer_info);
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
    
        i32 indices[3 * 2] = {
            0, 1, 3,
            1, 2, 3
        };
    
        TGL::GFX::vertex_buffer::vertex_buffer_info vertex_buffer_info = {
            vertices, 
            12 * sizeof(float),
            { { TGL::GFX::shader_data_type::float_3, "a_Position" } }
        };
        
        TGL::GFX::index_buffer::index_buffer_info index_buffer_info = {
            indices, 
            6 * sizeof(i32)
        };
        
        m_render_object = std::make_shared<GFX::render_object>(vertex_buffer_info, index_buffer_info);
    }
    
}
