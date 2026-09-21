#pragma once

#include <memory>

#include "platform/default_types.h"
#include "events/event.h"
#include "renderer/renderer.h"
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

        inline std::shared_ptr<GFX::renderer>& get_renderer() { return m_window_props.renderer; }

        void swap_buffers() const;
        void poll_events() const;
        
        void render_something();

        bool get_key_pressed(i32 keycode) const;
        bool get_key_released(i32 keycode) const;
        bool get_mouse_button_pressed(i32 button) const;
        bool get_mouse_button_released(i32 button) const;
        std::pair<f64, f64> get_mouse_position() const;
        f64 get_mouse_x() const { return get_mouse_position().first; }
        f64 get_mouse_y() const { return get_mouse_position().second; }

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
            std::shared_ptr<GFX::renderer> renderer = nullptr;
        };
        window_props m_window_props;

        void init();
    };
    
}