#include "core/application.h"

#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "glad/gl.h"

namespace TGL::CORE
{
    
    application::application(i32 width, i32 height, cstr_ptr title)
    {
        m_window = std::make_shared<CORE::window>(width, height, title);
        m_renderer = std::make_shared<GFX::renderer>(m_window->get_proccess_address());
        
        std::string vertex_shader_source = R"(
            #version 330 core

            layout (location = 0) in vec3 a_Position;

            void main()
            {
                gl_Position = vec4(a_Position, 1.0);
            }
        )";
    
        std::string fragment_shader_source = R"(
            #version 330 core

            out vec4 out_Color;
            
            void main()
            {
                out_Color = vec4(0.8, 0.2, 0.3, 1.0);
            }
        )";
        
        m_default_shader_program = std::make_shared<GFX::shader_program>(vertex_shader_source.c_str(), fragment_shader_source.c_str());
        
        triangle_shape = std::make_shared<SHAPE::triangle>(m_default_shader_program);
        square_shape = std::make_shared<SHAPE::square>(m_default_shader_program);
    }

    application::~application()
    {
        
    }

    void application::draw_triangle(f32 x, f32 y, f32 z) const
    {
        m_renderer->draw(
            triangle_shape->get_render_object()->get_buffer_id(), 
            triangle_shape->get_render_object()->get_index_count(), 
            triangle_shape->get_shader_program()->get_shader_program_id()
        );
    }

    void application::draw_square(f32 x, f32 y, f32 z) const
    {
        m_renderer->draw(
            square_shape->get_render_object()->get_buffer_id(), 
            square_shape->get_render_object()->get_index_count(),
            square_shape->get_shader_program()->get_shader_program_id()
        );
    }
    
}
