#pragma once

#include "window_export.h"

#include "basic_impl_template.h"

#include <string>
#include <functional>
#include <windows.h>
#undef min
#undef max

struct GLFWwindow;

namespace EB
{
    class Event;

    /**
     * @brief  this struct defines basic properties of window.
     */
    struct EB_WINDOW_EXPORT WindowProperties
    {
        /** < title of window > */
        std::string Title;

        /** < width of window > */
        unsigned int Width = 1200;

        /** < height of window > */
        unsigned int Height = 800;
    };

    /**
     * @brief  this class defines window class
     */
    class EB_WINDOW_EXPORT Window
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(Window);
    public:
        using EventCallbackFn = std::function<void(Event&)>;

    public:
        /**
         * @brief  create a window with properties.
         * @param[in]   properties   properties of window.
         * @return   shared pointer of created window.
         */
        static Shared<Window> create(const WindowProperties& properties);

        /**
         * @brief  get window instance by window title.
         * @param[in]   title        title of window.
         * @return   shared point of found window.
         */
        static Shared<Window> instance(const std::string& title);

        /**
         * @brief  destroy a window by window title.
         * @param[in]   title        title of window.
         */
        static void destroy(const std::string& title);

    public:
        /**
         * @brief   constructor of window.
         * @param[in]   properties    properties of window.
         */
        Window(const WindowProperties& properties);

        /**
         * @brief   destructor of window.
         */
        ~Window();

    public:
        /**
         * @brief  get width of window.
         * @return  width of window.
         */
        unsigned int width() const;

        /**
         * @brief  get height of window.
         * @return   height of window.
         */
        unsigned int height() const;

        /**
         * @brief  is vertical sync on.
         * @return whether vertical sync is enabled.
         */
        bool isVSync() const;

        /**
         * @brief  enable of disable vertical sync.
         * @param[in]   enable   option to enable or disable.
         */
        void setVSync(bool enable = true);

        /**
         * @brief  set event handle call back to window.
         * @param[in]   callback    event handle call back.
         */
        void setEventCallback(const EventCallbackFn& callback);

        /**
         * @brief   get glfw window native pointer.
         * @return   glfw window native pointer.
         */
        GLFWwindow* native() const;

        /**
         * @brief   get win32 hwnd.
         * @return    win32 hwnd.
         */
        HWND hwnd() const;

        /**
         * @brief   is key pressed for this window.
         * @param[in]    keyCode    key identifier.
         * @return    whether key is pressed.
         */
        bool isKeyPressed(int keyCode);

        /**
         * @brief   is mouse button pressed for this window.
         * @param[in]    mouseButton   mouse button identifer.
         * @return    whether mouse button is pressed.
         */
        bool isMouseButtonPressed(int mouseButton);

        /**
         * @brief   get cursor pos of this window.
         * @return   pair of cursor pos x and y.
         */
        std::pair<float, float> cursorPos();

    public:
        /**
         * @brief   update window data.
         */
        void onUpdate();

    };
}