#pragma once

#include "events/event.h"

namespace TGL
{

    class window_resize_event : public event
    {
    public:
        window_resize_event(i32 width, i32 height)
            : m_width(width), m_height(height) {}

        inline u32 get_width() const { return m_width; }
        inline u32 get_height() const { return m_height; }

        std::string to_string() const override
        {
            return std::string(get_name()) + ": " + std::to_string(m_width) + ", " + std::to_string(m_height);
        }

        EVENT_CLASS_TYPE(window_resize)
        EVENT_CLASS_CATEGORY(event_category::application)
    private:
        u32 m_width;
        u32 m_height;
    };

    class window_close_event : public event
    {
    public:
        window_close_event() {}

        EVENT_CLASS_TYPE(window_close)
        EVENT_CLASS_CATEGORY(event_category::application)

    };

    class app_tick_event : public event
    {
    public:
        app_tick_event() {}

        EVENT_CLASS_TYPE(app_tick)
        EVENT_CLASS_CATEGORY(event_category::application)
    };

    class app_update_event : public event
    {
    public:
        app_update_event() {}

        EVENT_CLASS_TYPE(app_update)
        EVENT_CLASS_CATEGORY(event_category::application)
    };

    class app_render_event : public event
    {
    public:
        app_render_event() {}

        EVENT_CLASS_TYPE(app_render)
        EVENT_CLASS_CATEGORY(event_category::application)
    };

    class window_focus_event : public event
    {
    public:
        window_focus_event(bool focused) : m_focused(focused) {}

        inline bool is_focused() const { return m_focused; }

        EVENT_CLASS_TYPE(window_focus)
        EVENT_CLASS_CATEGORY(event_category::application)
    private:
        bool m_focused;
    };

    class window_framebuffer_resize_event : public event
    {
    public:
        window_framebuffer_resize_event(i32 width, i32 height)
            : m_width(width), m_height(height) {}

        inline i32 get_width() const { return m_width; }
        inline i32 get_height() const { return m_height; }

        std::string to_string() const override
        {
            return std::string(get_name()) + ": " + std::to_string(m_width) + ", " + std::to_string(m_height);
        }

        EVENT_CLASS_TYPE(window_framebuffer_resize)
        EVENT_CLASS_CATEGORY(event_category::application)
    private:
        i32 m_width;
        i32 m_height;
    };
}