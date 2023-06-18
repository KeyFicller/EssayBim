#pragma once

#include "basic_export.h"
#include "basic_impl_template.h"

#include <string>

namespace EB
{
    class Window;
    class Event;

    /**
     * @brief  this class defines application class.
     */
    class EB_EXPORT Application
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(Application)
    public:
        /**
         * @brief   constructor for application.
         * @param[in]   name    name of application.
         */
        Application(const std::string& name);

        /**
         * @brief   destructor for application.
         */
        virtual ~Application();

    public:
        /**
         * @brief   get application instance.
         */
        static Application& instance();

    public:
        /**
         * @brief  get application name.
         * @return  application name.
         */
        const std::string& name() const;

        /**
         * @brief  get application window.
         * @param[in]   name    name of window, default is application name.
         */
        Shared<Window> window(const std::string& name = std::string());

        /**
         * @biref   handle application run.
         */
        virtual void run();

        /**
         * @brief   handle application event.
         * @param[in]   e  event.
         */
        virtual void onEvent(Event& e);

        /**
         * @brief   handle application close.
         */
        virtual void close();
    };

    /**
     * @brief  create application entry.
     * @return  pointer to application.
     */
    extern Application * createApplication();
}