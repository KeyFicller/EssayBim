#pragma once

#include "gui_value_input_widget.h"

#include "gui_base_widget_impl.h"

namespace EB
{
    class ValueInputWidgetImpl : public BaseWidgetImpl
    {
    public:
        ValueInputWidgetImpl(BaseWidget* pFacade, const std::string& name,
            void* data, int component, const ValueInputWidget::ValueBoundary& boundary);
        
    public:
        void setValueBoundary(const ValueInputWidget::ValueBoundary& boundary);
        const ValueInputWidget::ValueBoundary& valueBoundary();
        int* integer() const;
        float* real() const;
        int component() const;
        std::pair<int, int> integerVB() const;
        std::pair<float, float> realVB() const;

    protected:
        void* m_Data;
        int m_Component;
        ValueInputWidget::ValueBoundary m_Boundary;
    };
}