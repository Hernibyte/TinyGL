#include "renderer/vertex_array.h"

#include "platform/assert.h"
#include "renderer/renderer.h"

#include "platform/gl/gl_vertex_array.h"

namespace TGL::GFX
{
    std::unique_ptr<vertex_array> vertex_array::create()
    {
        switch (renderer::get_api())
        {
        case GFX::gfx_api::none:
            TGL_ASSERT_LOG(false, "RENDER BUFFER: [NONE] Platform not supported!");
            break;
        
        case GFX::gfx_api::opengl:
            //
            return std::make_unique<GL::gl_vertex_array>();
            break;
        
        default:
            TGL_ASSERT_LOG(false, "RENDER BUFFER: Platform not supported!");
            break;
        }
            
        return nullptr;
    }
    
}