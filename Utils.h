#ifndef WIPER_UTILS_H
#define WIPER_UTILS_H

//#define WINDOWS

#ifdef WINDOWS
#define M_CHAR wchar_t
#define M_STRING std::wstring
#define TO_M_STRING std::to_wstring
#define __M(quote_string) L ## quote_string

#else
#define M_CHAR char
#define M_STRING std::string
#define TO_M_STRING std::to_string
#define __M(quote_string) quote_string
#endif


#endif //WIPER_UTILS_H
