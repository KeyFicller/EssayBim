#pragma once

#define EB_EXPAND_MACRO(_macro) _macro

#define EB_STRINGFY(_macro) #_macro

#define EB_ARGS_AUGMENTER(...) unused, __VA_ARGS__

#define EB_SAFE_DELETE(_ptr) if (_ptr) {delete _ptr; _ptr = nullptr;}

#define EB_SAFE_ARRAY_DELETE(_ptr) if (_ptr) {delete[] _ptr; _ptr = nullptr;}