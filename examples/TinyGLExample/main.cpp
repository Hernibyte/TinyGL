#include "TinyGL.h"

void on_event(TGL::event& e)
{
    if (e.get_event_type() == TGL::event_type::window_resize)
    {
        TGL::window_resize_event& resize_event = dynamic_cast<TGL::window_resize_event&>(e);
        TGL_INFO("Window resized to: x={0}, y={1}", resize_event.get_width(), resize_event.get_height());
    }
    else if (e.get_event_type() == TGL::event_type::key_pressed)
    {
        TGL::key_pressed_event& key_event = dynamic_cast<TGL::key_pressed_event&>(e);
        TGL_INFO("Key pressed: {0}", key_event.get_keycode());
    }
    else if (e.get_event_type() == TGL::event_type::mouse_moved)
    {
        TGL::mouse_moved_event& mouse_event = dynamic_cast<TGL::mouse_moved_event&>(e);
        TGL_INFO("Mouse move to: x={0}, y={1}", mouse_event.get_x(), mouse_event.get_y());
    }
    else if (e.get_event_type() == TGL::event_type::mouse_scrolled)
    {
        TGL::mouse_scrolled_event& scroll_event = dynamic_cast<TGL::mouse_scrolled_event&>(e);
        TGL_INFO("Mouse scrolled by: x={0}, y={1}", scroll_event.get_x_offset(), scroll_event.get_y_offset());
    }
    else if (e.get_event_type() == TGL::event_type::mouse_button_pressed)
    {
        TGL::mouse_button_pressed_event& button_event = dynamic_cast<TGL::mouse_button_pressed_event&>(e);
        TGL_INFO("Mouse button pressed: {0}", button_event.get_mouse_button());
    }
    else if (e.get_event_type() == TGL::event_type::mouse_button_released)
    {
        TGL::mouse_button_released_event& button_event = dynamic_cast<TGL::mouse_button_released_event&>(e);
        TGL_INFO("Mouse button released: {0}", button_event.get_mouse_button());
    }
    else if (e.get_event_type() == TGL::event_type::window_framebuffer_resize)
    {
        TGL::window_framebuffer_resize_event& framebuffer_event = dynamic_cast<TGL::window_framebuffer_resize_event&>(e);
        TGL_INFO("Window framebuffer resized to: x={0}, y={1}", framebuffer_event.get_width(), framebuffer_event.get_height());
    }
}

int main()
{
    TGL::CORE::application app{800, 600, "TinyGL Example"};
    app.get_window()->set_on_event_callback(on_event);
    
    while (!app.get_window()->should_close())
    {
        // Render your scene here
        app.get_renderer()->clear_color(0.2f, 0.3f, 0.3f, 1.0f);
        app.get_renderer()->clear(TGL_COLOR_BUFFER_BIT);
        app.draw_square(1.0f, 1.0f, 1.0f);
        //app.draw_square(-1.0f, -1.0f, -1.0f);
        
        app.get_window()->swap_buffers();
        app.get_window()->poll_events();
    }

    return 0;
}