#pragma once

#include "platform/default_types.h"

#include "events/event.h"
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
        
        void set_on_event_callback(event::callback_fn callback) { m_window_data.on_event = callback; }
        
        void close();
        bool should_close();

        void swap_buffers();
        void poll_events();

        bool get_key_pressed(i32 keycode);
        bool get_mouse_button_pressed(i32 button);

    private:
        struct window_data
        {
            GLFWwindow* window = nullptr;
            i32 width;
            i32 height;
            const char* title;
            event::callback_fn on_event;
        };
        window_data m_window_data;

        void init();
    };
    
}