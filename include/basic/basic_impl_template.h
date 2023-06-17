#pragma once

#include "basic_pointer.h"

#define EB_IMPL_DECLARATION(_class)     \
    friend class _class##Impl;          \
    protected:                            \
    Scoped<_class##Impl> m_pImpl;

#define EB_IMPL                         \
    (m_pImpl)

#define EB_IMPL_D(_class)               \
    static_cast<_class##Impl*>(EB_IMPL.get())

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