#pragma once

#include "platform/log.h"
#include "renderer/vertex_array.h"
#include "renderer/buffers.h"

namespace TGL::GFX
{
    
    class render_object
    {
    public:
        render_object(vertex_buffer::vertex_buffer_info vertex_buffer_info, GFX::vertex_attributes_layout vertex_attributes_layout, index_buffer::index_buffer_info index_buffer_info);
        ~render_object();
        
        buffer_id get_buffer_id() const
        {
            if (m_vertex_array)
                return m_vertex_array->get_id();
            
            TGL_CORE_ERROR("VERTEX ARRAY IS NULL");
            return -1;
        }
        
        i32 get_index_count() const  { return m_index_buffer->get_count(); }
        
        void bind() const;
        void unbind() const;
        
    private:
        std::unique_ptr<vertex_array> m_vertex_array = nullptr;
        std::unique_ptr<vertex_buffer> m_vertex_buffer = nullptr;
        std::unique_ptr<index_buffer> m_index_buffer = nullptr;
        
    };
    
}
