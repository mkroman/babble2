#ifndef __BABBLE_HPP
#define __BABBLE_HPP
#include <cstdarg>

static const int kGameWidth  = 720;
static const int kGameHeight = 420;

static int __pretty_print(const char* function, const char* format, ...)
{
	int     result;
	char*   buffer;
	char*   pointer;
	size_t  format_length;
	size_t  function_length;
	size_t  concatenated_length;
	va_list args;

	format_length       = strlen(format);
	function_length     = strlen(function);
	concatenated_length = (format_length + function_length + 3);
	pointer = buffer    = static_cast<char*>(malloc(concatenated_length));

	for (uint i = 0; i < function_length; i++)
		*pointer++ = function[i];

	*pointer++ = ' ';

	for (uint i = 0; i < format_length; i++)
		*pointer++ = format[i];

	*pointer++ = '\n';
	*pointer++ = '\0';

	va_start(args, format);
	result = vprintf(buffer, args);
	va_end(args);

	free(buffer);

	return result;
}

#define _debug(s...) \
	__pretty_print(__PRETTY_FUNCTION__, s);

#endif
