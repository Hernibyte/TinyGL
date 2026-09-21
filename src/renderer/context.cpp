#include "renderer/context.h"

#include "platform/assert.h"
#include "renderer/renderer.h"
#include "platform/gl/gl_context.h"

namespace TGL::GFX
{
    void context::init(void* process_address_ptr)
    {
        switch (renderer::get_api())
        {
        case GFX::gfx_api::none:
            TGL_ASSERT_LOG(false, "RENDER CONTEXT: [NONE] Platform not supported!");
        break;
        
        case GFX::gfx_api::opengl:
            GL::gl_context::init(process_address_ptr);
        break;
        
        default:
            TGL_ASSERT_LOG(false, "RENDER CONTEXT: Platform not supported!");
            break;
        }
    }

}