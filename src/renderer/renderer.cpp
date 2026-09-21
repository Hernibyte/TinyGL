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

}