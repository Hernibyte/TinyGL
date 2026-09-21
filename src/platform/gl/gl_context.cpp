#include "platform/gl/gl_context.h"

#include "glad/gl.h"
#include "platform/assert.h"
#include "platform/log.h"

namespace TGL::GL
{
    
    void gl_context::init(void* process_address_ptr)
    {
        int status = gladLoadGL((GLADloadfunc)process_address_ptr);
        TGL_CORE_ASSERT_LOG(status, "Failed to initialize Glad!");
        
        TGL_INFO("Glad initialized successfully!");
    }

}
