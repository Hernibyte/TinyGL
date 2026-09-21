#include "renderer/buffers.h"

#include "platform/assert.h"
#include "renderer/renderer.h"
#include "platform/gl/gl_buffers.h"

namespace TGL::GFX
{
    
    /////////////////////////////////////////////////////////////////
    // VERTEX BUFFER ////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////

    vertex_buffer* vertex_buffer::create(const vertex_buffer_info& info)
    {
        switch (renderer::get_api())
        {
        case GFX::gfx_api::none:
            TGL_ASSERT_LOG(false, "RENDER BUFFER: [NONE] Platform not supported!");
            break;
        
        case GFX::gfx_api::opengl:
            //
            return new GL::gl_vertex_buffer(info.vertices, info.size);
            break;
        
        default:
            TGL_ASSERT_LOG(false, "RENDER BUFFER: Platform not supported!");
            break;
        }
            
        return nullptr;
    }
    
    vertex_buffer* vertex_buffer::create(const f32* vertices, const u32 size)
    {
        switch (renderer::get_api())
        {
        case GFX::gfx_api::none:
            TGL_ASSERT_LOG(false, "RENDER BUFFER: [NONE] Platform not supported!");
            break;
        
        case GFX::gfx_api::opengl:
            //
            return new GL::gl_vertex_buffer(vertices, size);
            break;
        
        default:
            TGL_ASSERT_LOG(false, "RENDER BUFFER: Platform not supported!");
            break;
        }
            
        return nullptr;
    }
    
    /////////////////////////////////////////////////////////////////
    // INDEX BUFFER /////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////
    
    index_buffer* index_buffer::create(const index_buffer_info& info)
    {
        switch (renderer::get_api())
        {
        case GFX::gfx_api::none:
            TGL_ASSERT_LOG(false, "RENDER BUFFER: [NONE] Platform not supported!");
            break;
        
        case GFX::gfx_api::opengl:
            //
            return new GL::gl_index_buffer(info.indices, info.count);
            break;
        
        default:
            TGL_ASSERT_LOG(false, "RENDER BUFFER: Platform not supported!");
            break;
        }
            
        return nullptr;
    }
    
    index_buffer* index_buffer::create(const u32* indices, const u32 count)
    {
        switch (renderer::get_api())
        {
        case GFX::gfx_api::none:
            TGL_ASSERT_LOG(false, "RENDER BUFFER: [NONE] Platform not supported!");
            break;
        
        case GFX::gfx_api::opengl:
            //
            return new GL::gl_index_buffer(indices, count);
            break;
        
        default:
            TGL_ASSERT_LOG(false, "RENDER BUFFER: Platform not supported!");
            break;
        }
            
        return nullptr;
    }

}