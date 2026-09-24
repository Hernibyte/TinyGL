#pragma once 

#include "platform/default_types.h"
#include "renderer/renderer_api.h"

namespace TGL::GFX
{
    
    class renderer
    {
    public:
        renderer() = delete;
        renderer(void* window_process_address_ptr);
        
        void draw(buffer_id vertex_array_id, i32 index_count, shader_id shader_program_id);
        
        void clear_color(const  f32 red, const f32 green, const f32 blue, const f32 alpha) const;
        void clear(const  i32 mask) const;
        
    private:
        std::unique_ptr<renderer_api> m_renderer_api;
    };

}