#include "platform/gl/gl_shader.h"

#include "glad/gl.h"

#include "platform/log.h"

namespace TGL::GL
{

    shader_id gl_shader::create(cstr_ptr vertex_source, cstr_ptr fragment_source)
    {
        shader_id shader_vertex_id = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(shader_vertex_id, 1, &vertex_source, NULL);
        glCompileShader(shader_vertex_id);
        
        shader_id shader_fragment_id = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(shader_fragment_id, 1, &fragment_source, NULL);
        glCompileShader(shader_fragment_id);
        
        i32 success = true;
        glGetShaderiv(shader_vertex_id, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            char info_log[512];
            glGetShaderInfoLog(shader_vertex_id, 512, NULL, info_log);
            TGL_CORE_ERROR("Vertex shader compilation failed: {0}", info_log);
        }
        
        glGetShaderiv(shader_fragment_id, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            char info_log[512];
            glGetShaderInfoLog(shader_fragment_id, 512, NULL, info_log);
            TGL_CORE_ERROR("Fragment shader compilation failed: {0}", info_log);
        }
        
        shader_id shader_program_id = glCreateProgram();
        glAttachShader(shader_program_id, shader_vertex_id);
        glAttachShader(shader_program_id, shader_fragment_id);
        glLinkProgram(shader_program_id);

        glGetProgramiv(shader_program_id, GL_LINK_STATUS, &success);
        if (!success)
        {
            char info_log[512];
            glGetProgramInfoLog(shader_program_id, 512, NULL, info_log);
            TGL_CORE_ERROR("Shader program linking failed: {0}", info_log);
        }

        glDeleteShader(shader_vertex_id);
        glDeleteShader(shader_fragment_id);

        return shader_program_id;
    }

    void gl_shader::clear(shader_id shader_program_id)
    {
        glDeleteProgram(shader_program_id);
    }
}