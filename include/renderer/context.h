#pragma once 

namespace TGL::GFX
{

    class context
    {
    public:
        context() = default;

        static void init(void* process_address_ptr);
    };

}