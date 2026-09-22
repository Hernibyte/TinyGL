#pragma once

#include "renderer/render_object.h"
#include "renderer/shader.h"

namespace TGL::SHAPE
{
    
    class shape
    {
    public:
        //static shape* create();
        
        std::shared_ptr<GFX::render_object> get_render_object() const { return m_render_object; };
        std::shared_ptr<GFX::shader_program> get_shader_program() const { return m_shader_program; };
        
    protected:
        std::shared_ptr<GFX::render_object> m_render_object;
        std::shared_ptr<GFX::shader_program> m_shader_program;
    };
    
    class triangle : public shape
    {
    public:
        explicit triangle(const std::shared_ptr<GFX::shader_program>& shader_program);
    };
    
    class square : public shape
    {
    public:
        explicit square(const std::shared_ptr<GFX::shader_program>& shader_program);
    };
    
}
