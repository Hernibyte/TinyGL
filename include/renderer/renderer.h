#pragma once 

#include "platform/default_types.h"
#include "events/event.h"
#include "renderer/shader.h"

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

        static gfx_api get_api() { return s_gfx_api; }
    private:
        static gfx_api s_gfx_api;
    };

}