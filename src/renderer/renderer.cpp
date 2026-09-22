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

    void renderer::draw(const GFX::render_object& render_object, const GFX::shader_program& shader_program)
    {
        glUseProgram(shader_program.get_shader_program_id());
        glBindVertexArray(render_object.get_buffer_id());
        glDrawElements(GL_TRIANGLES, render_object.get_index_count(), GL_UNSIGNED_INT, nullptr);
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
