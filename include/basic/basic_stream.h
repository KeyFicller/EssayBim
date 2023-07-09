#pragma once

#include "basic_export.h"
#include "basic_filer.h"
#include "basic_impl_template.h"

namespace EB
{
    class EB_BASIC_EXPORT Stream : public Filer
    {
    public:
        Stream();
        ~Stream() override;

    public:
        void offer(Filer* filer, int size);
        void accept(Filer* filer);
        int readIndex();
        int readLength();
        void writeIndex(int index);
        void writeLength(int length);
    };
}