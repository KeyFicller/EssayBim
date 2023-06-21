#include "gui_value_input_widget_impl.h"

namespace EB
{

    ValueInputWidgetImpl::ValueInputWidgetImpl(BaseWidget* pFacade, const std::string& name, void* data, int component, const ValueInputWidget::ValueBoundary& boundary)
        : BaseWidgetImpl(pFacade, name), m_Data(data), m_Component(component), m_Boundary(boundary)
    {

    }

    void ValueInputWidgetImpl::setValueBoundary(const ValueInputWidget::ValueBoundary& boundary)
    {
        m_Boundary = boundary;
    }

    const ValueInputWidget::ValueBoundary& ValueInputWidgetImpl::valueBoundary()
    {
        return m_Boundary;
    }

    int* ValueInputWidgetImpl::integer() const
    {
        return reinterpret_cast<int*>(m_Data);
    }

    float* ValueInputWidgetImpl::real() const
    {
        return reinterpret_cast<float*>(m_Data);
    }

    int ValueInputWidgetImpl::component() const
    {
        return m_Component;
    }

    std::pair<int, int> ValueInputWidgetImpl::integerVB() const
    {
        return std::make_pair(static_cast<int>(m_Boundary.LowerBound), static_cast<int>(m_Boundary.UpperBound));
    }

    std::pair<float, float> ValueInputWidgetImpl::realVB() const
    {
        return std::make_pair(m_Boundary.LowerBound, m_Boundary.UpperBound);
    }

}