#pragma once

#define EB_IMPL_DECLARATION(_class)     \
    friend class _class##Impl;          \
    private:                            \
    _class##Impl* m_pImpl = nullptr;

#define EB_IMPL                         \
    (m_pImpl)

#define EB_IMPL_DISABLE_COPY(_class)                        \
    private:                                                \
    _class(const _class& other) = delete;                   \
    _class& operator = (const _class& other) = delete;

#define EB_IMPL_ENABLE_COPY(_class)                        \
    private:                                               \
    _class(const _class& other);                           \
    _class& operator = (const _class& other);

#define EB_IMPL_DECLARATION_DISABLE_COPY(_class)         \
    EB_IMPL_DECLARATION(_class)                          \
    EB_IMPL_DISABLE_COPY(_class)

#define EB_IMPL_DECLARATION_ENABLE_COPY(_class)          \
    EB_IMPL_DECLARATION(_class)                          \
    EB_IMPL_ENABLE_COPY(_class)