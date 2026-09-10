#pragma once

#include <string>
#include <functional>

#include "platform/default_types.h"

namespace TGL
{

    enum class event_type
    {
        none = 0,
        window_close,
        window_resize,
        window_focus,
        window_lost_focus,
        window_moved,
        app_tick,
        app_update,
        app_render,
        key_pressed,
        key_released,
        mouse_button_pressed,
        mouse_button_released,
        mouse_moved,
        mouse_scrolled
    };

    enum event_category
    {
        none         = 0,
        application  = BIT(0),
        input        = BIT(1),
        keyboard     = BIT(2),
        mouse        = BIT(3),
        mouse_button = BIT(4)
    };

    #define EVENT_CLASS_TYPE(type) static event_type get_static_type() { return event_type::##type; }\
                                virtual event_type get_event_type() const override { return get_static_type(); }\
                                virtual const char* get_name() const override { return #type; }

    #define EVENT_CLASS_CATEGORY(category) virtual i32 get_category_flags() const override { return category; }

    class event
    {
    public:
        using callback_fn = std::function<void(event&)>;

        virtual event_type get_event_type() const = 0;
        virtual const char* get_name() const = 0;
        virtual i32 get_category_flags() const = 0;
        virtual std::string to_string() const { return get_name(); }

        bool is_in_category(event_category category)
        {
            return get_category_flags() & category;
        }
        
    protected:
        bool m_handled = false;
    };

}

#define BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1);