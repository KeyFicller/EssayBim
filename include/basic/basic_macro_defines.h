#pragma once

#define EB_EXPAND_MACRO(_macro) _macro

#define EB_STRINGFY(_macro) #_macro

#define EB_ARGS_AUGMENTER(...) unused, __VA_ARGS__