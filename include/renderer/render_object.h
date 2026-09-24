#pragma once

#include "platform/log.h"
#include "renderer/vertex_array.h"
#include "renderer/buffers.h"

namespace TGL::GFX
{
    
    class render_object
    {
    public:
        render_object();
        ~render_object();
        
        void add_vertex_buffer(const std::shared_ptr<vertex_buffer>& vertex_buffer);
        void add_vertex_buffer(const vertex_buffer::vertex_buffer_info& vertex_buffer_info);
        
        void set_index_buffer(const std::shared_ptr<index_buffer>& index_buffer);
        void set_index_buffer(const index_buffer::index_buffer_info& index_buffer_info);
        
        void bind() const;
        void unbind() const;
        
        buffer_id get_buffer_id() const
        {
            if (m_vertex_array)
                return m_vertex_array->get_id();
            
            TGL_CORE_ERROR("VERTEX ARRAY IS NULL");
            return -1;
        }
        
        i32 get_index_count() const  { return m_index_buffer->get_count(); }
        
    private:
        std::unique_ptr<vertex_array> m_vertex_array;
        std::vector<std::shared_ptr<vertex_buffer>> m_vertex_buffers;
        std::shared_ptr<index_buffer> m_index_buffer;
        
    };
    
}
