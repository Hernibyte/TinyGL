#pragma once

#include <memory>

#include "platform/default_types.h"
#include "events/event.h"
#include "core/renderer.h"
#include "events/app_event.h"
#include "events/key_event.h"
#include "events/mouse_event.h"

struct GLFWwindow;

namespace TGL::CORE
{

    struct window_info
    {
        i32 width;
        i32 height;
        const char* title;
    };

    class window
    {
    public:
        window(i32 width, i32 height, const char* title);
        explicit window(window_info& info);
        ~window();
        
        void set_on_event_callback(event::callback_fn callback) { m_window_props.on_event = callback; }
        
        void close();
        bool should_close();

        inline std::shared_ptr<renderer>& get_renderer() { return m_window_props.renderer; }

        void swap_buffers();
        void poll_events();

        bool get_key_pressed(i32 keycode);
        bool get_mouse_button_pressed(i32 button);

    private:
        struct window_props
        {
            GLFWwindow* window = nullptr;
            i32 width;
            i32 height;
            i32 framebuffer_width;
            i32 framebuffer_height;
            const char* title;
            event::callback_fn on_event;
            std::shared_ptr<renderer> renderer;
        };
        window_props m_window_props;

        void init();
    };
    
}