#pragma once 

#include "platform/default_types.h"

#define TGL_COLOR_BUFFER_BIT 0x00004000
#define TGL_DEPTH_BUFFER_BIT 0x00000100
#define TGL_STENCIL_BUFFER_BIT 0x00000400

namespace TGL::GFX
{
    enum class gfx_api
    {
        none = 0,
        opengl = 1
    };

    class renderer
    {
    public:
        renderer() = delete;
        renderer(void* window_process_address_ptr);
        
        void draw(buffer_id vertex_array_id, i32 index_count, shader_id shader_program_id);
        
        void clear_color(const  f32 red, const f32 green, const f32 blue, const f32 alpha) const;
        void clear(const  i32 mask) const;

        static gfx_api get_api() { return s_gfx_api; }
        
    private:
        static gfx_api s_gfx_api;
        
    };

}