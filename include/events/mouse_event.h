#pragma once

#include "events/event.h"

namespace TGL
{

    class mouse_moved_event : public event
    {
    public:
        mouse_moved_event(f32 x, f32 y)
            : m_mouse_x(x), m_mouse_y(y) {}

        inline f32 get_x() const { return m_mouse_x; }
        inline f32 get_y() const { return m_mouse_y; }

        std::string to_string() const override
        {
            return std::string(get_name()) + ": " + std::to_string(m_mouse_x) + ", " + std::to_string(m_mouse_y);
        }

        EVENT_CLASS_TYPE(mouse_moved)
        EVENT_CLASS_CATEGORY(event_category::mouse | event_category::input)
    private:
        f32 m_mouse_x;
        f32 m_mouse_y;
    };

    class mouse_scrolled_event : public event
    {
    public:
        mouse_scrolled_event(f32 x_offset, f32 y_offset)
            : m_x_offset(x_offset), m_y_offset(y_offset) {}

        inline f32 get_x_offset() const { return m_x_offset; }
        inline f32 get_y_offset() const { return m_y_offset; }

        std::string to_string() const override
        {
            return std::string(get_name()) + ": " + std::to_string(m_x_offset) + ", " + std::to_string(m_y_offset);
        }

        EVENT_CLASS_TYPE(mouse_scrolled)
        EVENT_CLASS_CATEGORY(event_category::mouse | event_category::input)
    private:
        f32 m_x_offset;
        f32 m_y_offset;
    };

    class mouse_button_event : public event
    {
    public:
        inline i32 get_mouse_button() const { return m_button; }

        EVENT_CLASS_CATEGORY(event_category::mouse | event_category::input | event_category::mouse_button)
    protected:
        mouse_button_event(i32 button)
            : m_button(button) {}

        i32 m_button;
    };

    class mouse_button_pressed_event : public mouse_button_event
    {
    public:
        mouse_button_pressed_event(i32 button)
            : mouse_button_event(button) {}

        std::string to_string() const override
        {
            return std::string(get_name()) + ": " + std::to_string(m_button);
        }

        EVENT_CLASS_TYPE(mouse_button_pressed)
    };

    class mouse_button_released_event : public mouse_button_event
    {
    public:
        mouse_button_released_event(i32 button)
            : mouse_button_event(button) {}

        std::string to_string() const override
        {
            return std::string(get_name()) + ": " + std::to_string(m_button);
        }

        EVENT_CLASS_TYPE(mouse_button_released)
    };
}