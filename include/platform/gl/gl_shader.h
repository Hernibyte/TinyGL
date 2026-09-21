#pragma once

#include "platform/default_types.h"

namespace TGL::GL
{
    class gl_shader
    {
    public:
        static shader_id create(cstr_ptr vertex_source, cstr_ptr fragment_source);
        static void clear(shader_id shader_program_id);
    };
}