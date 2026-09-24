#include "renderer/renderer.h"

#include "renderer/context.h"

namespace TGL::GFX
{

    renderer::renderer(void* window_process_address_ptr)
    {
        m_renderer_api = renderer_api::create();
        m_renderer_api->init(window_process_address_ptr);
    }

    void renderer::draw(buffer_id vertex_array_id, i32 index_count, shader_id shader_program_id)
    {
        m_renderer_api->draw_indexed(vertex_array_id, index_count, shader_program_id);
    }

    void renderer::clear_color(const f32 red, const f32 green, const f32 blue, const f32 alpha) const
    {
        m_renderer_api->clear_color(red, green, blue, alpha);
    }

    void renderer::clear(const i32 mask) const
    {
        m_renderer_api->clear(mask);
    }
    
}
