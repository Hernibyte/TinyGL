#pragma once

namespace TGL::GL
{
    
    class gl_context
    {
    public:
        gl_context() = default;
        ~gl_context() = default;

        static void init(void* process_address_ptr);
    };

}