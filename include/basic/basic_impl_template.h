#pragma once

#include "basic_macro_defines.h"
#include "basic_pointer.h"

#define EB_IMPL_DECLARATION(_class)     \
    friend class _class##Impl;          \
    protected:                          \
    Scoped<_class##Impl> m_pImpl;

#define EB_IMPL_BASE()                   \
    (m_pImpl)

#define EB_IMPL_DERIVED(_class)          \
    static_cast<_class##Impl*>(EB_IMPL_BASE().get())

#define EB_IMPL(...) EB_EXPAND_MACRO(EB_IMPL_GET_MACRO(EB_ARGS_AUGMENTER(__VA_ARGS__))(__VA_ARGS__))
#define EB_IMPL_GET_MACRO(...) EB_EXPAND_MACRO(EB_IMPL_GET_MACRO_NAME(__VA_ARGS__, EB_IMPL_DERIVED, EB_IMPL_BASE))
#define EB_IMPL_GET_MACRO_NAME(_arg1, _arg2, _macro, ...) _macro

#define EB_FACADE_BASE()                 \
    (m_pFacade)

#define EB_FACADE_DERIVED(_class)        \
    static_cast<_class*>(EB_FACADE_BASE())

#define EB_FACADE(...) EB_EXPAND_MACRO(EB_FACADE_GET_MACRO(EB_ARGS_AUGMENTER(__VA_ARGS__))(__VA_ARGS__))
#define EB_FACADE_GET_MACRO(...) EB_EXPAND_MACRO(EB_FACADE_GET_MACRO_NAME(__VA_ARGS__, EB_FACADE_DERIVED, EB_FACADE_BASE))
#define EB_FACADE_GET_MACRO_NAME(_arg1, _arg2, _macro, ...) _macro

#define EB_IMPL_DISABLE_COPY(_class)                        \
    private:                                                \
    _class(const _class& other) = delete;                   \
    _class& operator = (const _class& other) = delete;

#define EB_IMPL_ENABLE_COPY(_class)                        \
    public:                                                \
    _class(const _class& other);                           \
    _class& operator = (const _class& other);

#define EB_IMPL_DECLARATION_DISABLE_COPY(_class)         \
    EB_IMPL_DECLARATION(_class)                          \
    EB_IMPL_DISABLE_COPY(_class)

#define EB_IMPL_DECLARATION_ENABLE_COPY(_class)          \
    EB_IMPL_DECLARATION(_class)                          \
    EB_IMPL_ENABLE_COPY(_class)

#define EB_IMPL_DEFAULT_COPY_IMPLEMENT(_class)                     \
    _class::_class(const _class& other) {                          \
        m_pImpl = createScoped<_class##Impl>(*other.m_pImpl);      \
    }                                                              \
    _class& _class::operator = (const _class& other) {             \
        m_pImpl = createScoped<_class##Impl>(*other.m_pImpl);      \
        return *this;                                              \
    }