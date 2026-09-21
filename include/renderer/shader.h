#pragma once

#include <string>

#include "platform/default_types.h"

namespace TGL::GFX
{

    class shader_program
    {
    public:
        shader_program(cstr_ptr vertex_source, cstr_ptr fragment_source);
        ~shader_program();
        
        shader_id get_shader_program_id() const { return m_shader_program_id; }
        std::string get_vertex_source() const { return m_vertex_source; }
        std::string get_fragment_source() const { return m_fragment_source; }

    private:
        shader_id m_shader_program_id;
        
        std::string m_vertex_source;
        std::string m_fragment_source;
    };

}