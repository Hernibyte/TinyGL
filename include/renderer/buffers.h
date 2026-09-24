#pragma once

#include <string>
#include <vector>

#include "platform/assert.h"
#include "platform/default_types.h"

namespace TGL::GFX
{
    
    enum class shader_data_type
    {
        none = 0, float_1, float_2, float_3, float_4, mat_3, mat_4, int_1, int_2, int_3, int_4, bool_1
    };
    
    static u32 shader_data_type_size(const shader_data_type type);
    
    struct vertex_attributes
    {
        std::string m_name;
        shader_data_type m_type;
        bool m_normalized;
        u32 m_size;
        u32 m_offset;
        
        vertex_attributes(const shader_data_type type, const std::string& name, const bool normalized = false);
        
        i32 get_attribute_count() const
        {
            switch (m_type)
            {
            case shader_data_type::none:    return 0;
            case shader_data_type::float_1: return 1;
            case shader_data_type::float_2: return 2;
            case shader_data_type::float_3: return 3;
            case shader_data_type::float_4: return 4;
            case shader_data_type::mat_3:   return 3 * 3;
            case shader_data_type::mat_4:   return 4 * 4;
            case shader_data_type::int_1:   return 1;
            case shader_data_type::int_2:   return 2;
            case shader_data_type::int_3:   return 3;
            case shader_data_type::int_4:   return 4;
            case shader_data_type::bool_1:  return 1;
            }
            
            TGL_CORE_ASSERT(false, "Unknown shader data type");
            return 0;
        }
    };
    
    class vertex_attributes_layout
    {
    public:
        vertex_attributes_layout(const std::initializer_list<vertex_attributes>& vertex_attributes) : m_attributes(vertex_attributes)
        {
            calculate_offset_and_stride();
        }
        
        i32 get_stride() const { return m_stride; }
        
        std::vector<vertex_attributes>::iterator begin() { return m_attributes.begin(); }
        std::vector<vertex_attributes>::iterator end() { return m_attributes.end(); }
        
    private:
        void calculate_offset_and_stride()
        {
            u32 offset = 0;
            m_stride = 0;
            for (auto& attribute : m_attributes)
            {
                attribute.m_offset = offset;
                offset += attribute.m_size;
                m_stride += attribute.m_size;
            }
        }
        
        std::vector<vertex_attributes> m_attributes;
        i32 m_stride = 0;
    };
    
    /////////////////////////////////////////////////////////////////
    // VERTEX BUFFER ////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////
    class vertex_buffer
    {
    public:
        struct vertex_buffer_info
        {
            f32* vertices;
            i32 size;
            vertex_attributes_layout layout;
        };
        
        virtual ~vertex_buffer() {}
        
        static std::shared_ptr<vertex_buffer> create(const vertex_buffer_info& info);
        static std::shared_ptr<vertex_buffer> create(const f32* vertices, i32 size, const vertex_attributes_layout& attributes_layout);
        
        buffer_id get_id() const { return m_buffer_id; }
        virtual i32 get_size() = 0;
        
        virtual void bind() = 0;
        virtual void unbind() = 0;
        
    protected:
        buffer_id m_buffer_id = 0;
        vertex_attributes_layout m_attributes_layout {};
    };
    
    /////////////////////////////////////////////////////////////////
    // INDEX BUFFER /////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////
    class index_buffer
    {
    public:
        struct index_buffer_info
        {
            i32* indices;
            i32 count;
        };
        
        virtual ~index_buffer() {}
        
        static std::shared_ptr<index_buffer> create(const index_buffer_info& info);
        static std::shared_ptr<index_buffer> create(const i32* indices, i32 count);
        
        buffer_id get_id() const { return m_buffer_id; }
        virtual i32 get_count() = 0;
        
        virtual void bind() = 0;
        virtual void unbind() = 0;
        
    protected:
        buffer_id m_buffer_id = 0;
    };

}
