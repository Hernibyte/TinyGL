#pragma once

#include "renderer/render_object.h"
#include "renderer/shader.h"

namespace TGL::SHAPE
{
    
    class shape
    {
    public:
        void set_shader_program_id(const shader_id shader_program_id) { m_shader_program_id = shader_program_id; }
        
        std::shared_ptr<GFX::render_object> get_render_object() const { return m_render_object; };
        shader_id get_shader_program_id() const { return m_shader_program_id; };
        
    protected:
        std::shared_ptr<GFX::render_object> m_render_object;
        shader_id m_shader_program_id = 0;
    };
    
    class triangle : public shape
    {
    public:
        explicit triangle();
    };
    
    class square : public shape
    {
    public:
        explicit square();
    };
    
}
