#include "renderer/renderer.h"

extern "C" 
{
    #include "glad/gl.h"
}

#include "platform/log.h"

#include "renderer/context.h"

namespace TGL::GFX
{

    gfx_api renderer::s_gfx_api = gfx_api::opengl;

    renderer::renderer(void* window_process_address_ptr)
    {
        context::init(window_process_address_ptr);
    }

    void renderer::draw(buffer_id vertex_array_id, i32 index_count, shader_id shader_program_id)
    {
        glUseProgram(shader_program_id);
        glBindVertexArray(vertex_array_id);
        glDrawElements(GL_TRIANGLES, index_count, GL_UNSIGNED_INT, nullptr);
    }

    void renderer::clear_color(const f32 red, const f32 green, const f32 blue, const f32 alpha) const
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    }

    void renderer::clear(const i32 mask) const
    {
        glClear(mask);
    }
    
}
