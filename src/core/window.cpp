#include "core/window.h"

#include <iostream>
#include <stdlib.h>

#include <glad/gl.h>
#include "GLFW/glfw3.h"
#include "platform/log.h"

namespace TGL::CORE
{
    
    window::window(int width, int height, const char* title)
    {
        m_window_data.title = title;
        m_window_data.height = height;
        m_window_data.width = width;

        init();
    }

    window::window(window_info& info)
    {
        m_window_data.width = info.width;
        m_window_data.height = info.height;
        m_window_data.title = info.title;

        init();
    }
    
    window::~window()
    {
        if (m_window_data.window)
        {
            glfwDestroyWindow(m_window_data.window);
            glfwTerminate();
        }
    }
    
    void window::init()
    {
        LOG::logger::init();

        if (!glfwInit())
        {
            TGL_CORE_ERROR("Failed to initialize GLFW");
            exit(EXIT_FAILURE);
        }
        
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        
        m_window_data.window = glfwCreateWindow(m_window_data.width, m_window_data.height, m_window_data.title, NULL, NULL);
        if (!m_window_data.window)
        {
            TGL_CORE_ERROR("Failed to create GLFW window");
            glfwTerminate();
        }
        
        glfwMakeContextCurrent(m_window_data.window);
        glfwSetWindowUserPointer(m_window_data.window, &m_window_data);

        // glfw callbacks
        glfwSetWindowSizeCallback(m_window_data.window, [](GLFWwindow* window, i32 width, i32 height)
        {
            window_data& data = *(window_data*)glfwGetWindowUserPointer(window);
            data.width = width;
            data.height = height;

            window_resize_event event(width, height);
            data.on_event(event);
        });

        glfwSetKeyCallback(m_window_data.window, [](GLFWwindow* window, i32 key, i32 scancode, i32 action, i32 mods)
        {
            window_data& data = *(window_data*)glfwGetWindowUserPointer(window);

            switch (action)
            {
                case GLFW_PRESS:
                {
                    key_pressed_event event(key, 0);
                    data.on_event(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    key_released_event event(key);
                    data.on_event(event);
                    break;
                }
                case GLFW_REPEAT:
                {
                    key_pressed_event event(key, 1);
                    data.on_event(event);
                    break;
                }
            }
        });

        glfwSetMouseButtonCallback(m_window_data.window, [](GLFWwindow* window, i32 button, i32 action, i32 mods)
        {
            window_data& data = *(window_data*)glfwGetWindowUserPointer(window);

            switch (action)
            {
                case GLFW_PRESS:
                {
                    mouse_button_pressed_event event(button);
                    data.on_event(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    mouse_button_released_event event(button);
                    data.on_event(event);
                    break;
                }
            }
        });

        glfwSetScrollCallback(m_window_data.window, [](GLFWwindow* window, f64 xoffset, f64 yoffset)
        {
            window_data& data = *(window_data*)glfwGetWindowUserPointer(window);

            mouse_scrolled_event event((f32)xoffset, (f32)yoffset);
            data.on_event(event);
        });

        glfwSetCursorPosCallback(m_window_data.window, [](GLFWwindow* window, f64 xpos, f64 ypos)
        {
            window_data& data = *(window_data*)glfwGetWindowUserPointer(window);

            mouse_moved_event event((f32)xpos, (f32)ypos);
            data.on_event(event);
        });
    }

    void window::close()
    {
        glfwSetWindowShouldClose(m_window_data.window, true);
    }

    bool window::should_close()
    {
        return glfwWindowShouldClose(m_window_data.window);
    }

    void window::swap_buffers()
    {
        glfwSwapBuffers(m_window_data.window);
    }

    void window::poll_events()
    {
        glfwPollEvents();
    }

    bool window::get_key_pressed(i32 keycode)
    {
        return glfwGetKey(m_window_data.window, keycode) == GLFW_PRESS;
    }

    bool window::get_mouse_button_pressed(i32 button)
    {
        return glfwGetMouseButton(m_window_data.window, button) == GLFW_PRESS;
    }
}