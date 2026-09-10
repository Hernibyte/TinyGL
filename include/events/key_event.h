#pragma once 

#include "events/event.h"

namespace TGL
{

    class key_event : public event
    {
    public:
        inline i32 get_keycode() const { return m_keycode; }

        EVENT_CLASS_CATEGORY(event_category::keyboard | event_category::input)

    protected:
        key_event(i32 keycode)
            : m_keycode(keycode) {}

        i32 m_keycode;
    };

    class key_pressed_event : public key_event
    {
    public:
        key_pressed_event(i32 keycode, i32 repeat_count)
            : key_event(keycode), m_repeat_count(repeat_count) {}

        inline i32 get_repeat_count() const { return m_repeat_count; }

        std::string to_string() const override
        {
            return std::string(get_name()) + ": " + std::to_string(m_keycode) + " (" + std::to_string(m_repeat_count) + " repeats)";
        }

        EVENT_CLASS_TYPE(key_pressed)
    private:
        i32 m_repeat_count;
    };

    class key_released_event : public key_event
    {
    public:
        key_released_event(i32 keycode)
            : key_event(keycode) {}

        std::string to_string() const override
        {
            return std::string(get_name()) + ": " + std::to_string(m_keycode);
        }

        EVENT_CLASS_TYPE(key_released)
    };

}