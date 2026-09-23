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
        window_framebuffer_resize,
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
        virtual ~event() = default;
        
        using callback_fn = std::function<void(event&)>;

        virtual event_type get_event_type() const = 0;
        virtual const char* get_name() const = 0;
        virtual i32 get_category_flags() const = 0;
        virtual std::string to_string() const { return get_name(); }

        bool is_in_category(event_category category) const
        {
            return get_category_flags() & category;
        }
        
        void set_handled(bool handled) { m_handled = handled; }
        
    protected:
        bool m_handled = false;
    };
    
    class event_handler
    {
    private:
        template<typename T>
        using event_fn = std::function<bool(T&)>;
        
    public:
        explicit event_handler(event& in_event) : m_event(in_event) {}
        
        template<typename T>
        bool dispatch(event_fn<T> function)
        {
            if (m_event.get_event_type() == T::get_static_type())
            {
                m_event.set_handled(function(*static_cast<T*>(&m_event)));
                return true;
            }
            return false;
        }
        
    private:
        event& m_event;
    };

}

#define BIND_EVENT_METHOD(fn) std::bind(&fn, this, std::placeholders::_1);