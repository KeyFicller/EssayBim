#pragma once

#include "basic_export.h"
#include "basic_impl_template.h"

#include <string>

namespace EB
{
    /**
     * @brief   this enum defines event category.
     */
    enum eEventCategory : unsigned int
    {
        /** < event category belongs to application > */
        kApplication         = 0x010000,

        /** < event category belongs to input > */
        kInput               = 0x020000,

        /** < event category belongs to key board > */
        kKeyBoard            = 0x040000,

        /** < event category belongs to mouse > */
        kMouse               = 0x080000,

        /** < event category belongs to mouse button > */
        kMouseButton         = 0x100000
    };

    /**
     * @brief  this enum defines event type.
     */
    enum eEventType : unsigned int
    {
        /** < unknown event type > */
        kNone               = 0,

        /** < event type is window closed > */
        kWindowClosed       = eEventCategory::kApplication | 0x01,

        /** < event type is window resized > */
        kWindowResized,

        /** < event type is window focused > */
        kWindowFocused,

        /** < event type is window lost fouces > */
        kWindowLostFocus,

        /** < event type is window moved > */
        kWindowMoved,

        /** < event type is application ticked > */
        kApplicationTicked,

        /** < event type is application updated > */
        kApplicationUpdated,

        /** < event type is application rendered > */
        kApplicationRendered,

        /** < event type is key pressed > */
        kKeyPressed           = eEventCategory::kInput | eEventCategory::kKeyBoard | 0x01,

        /** < event type is key released > */
        kKeyReleased,

        /** < event type is key typed > */
        kKeyTyped,

        /** < event type is mouse moved > */
        kMouseMoved           = eEventCategory::kInput | eEventCategory::kMouse | 0x01,

        /** < event type is mouse scrolled > */
        kMouseScrolled,

        /** < event type is mouse button pressed > */
        kMouseButtonPressed   = eEventCategory::kInput | eEventCategory::kMouseButton | 0x01,

        /** < event type is mouse button released > */
        kMouseButtonReleased
    };

    /**
     * @brief  this class define Event base class.
     */
    class EB_EXPORT Event
    {
        EB_IMPL_DECLARATION_DISABLE_COPY(Event);
    public:
        /**
         * @brief   constructor for event.
         */
        Event();

        /**
         * @biref   constructor for event with specified implement class.
         */
        Event(EventImpl& impl);

        /**
         * @brief   destructor for event.
         */
        virtual ~Event();

    public:
        /**
         * @brief   get event type.
         * @return  event type of event.
         */
        virtual eEventType type() const = 0;

        /**
         * @brief   get event name.
         * @return  event name of event.
         */
        virtual const char* name() const = 0;

        /**
         * @brief   get event string information.
         * @return  string information of event.
         */
        std::string toString() const;

        /**
         * @brief   check if event in category.
         * @param[in]   category    category to check.
         * @return   whether event is category.
         */
        bool isInCategory(eEventCategory category);

        /**
         * @brief   check if event is handled.
         * @return  whether event is handled.
         */
        bool isHandled() const;

        /**
         * @brief   set or reset event handled flag.
         * @param[in]  handled   flag to set.
         */
        void setHandled(bool handled = true);
    };

#define EB_DECLARE_EVENT_TYPE(_type)                                   \
    public:                                                            \
        static eEventType staticType() { return eEventType::_type; }   \
        eEventType type() const override { return staticType(); }      \
        const char* name() const override { return #_type; }
}