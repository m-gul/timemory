// MIT License
//
// Copyright (c) 2019, The Regents of the University of California,
// through Lawrence Berkeley National Laboratory (subject to receipt of any
// required approvals from the U.S. Dept. of Energy).  All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//

#pragma once

#if defined(USE_TIMEMORY)

#    include <timemory/timemory.hpp>

using tim::component::cpu_clock;
using tim::component::cpu_util;
using tim::component::page_rss;
using tim::component::peak_rss;
using tim::component::real_clock;

// some using statements
using tuple_t = tim::component_tuple<real_clock, cpu_clock, cpu_util, page_rss, peak_rss>;
using list_t  = tim::auto_timer_list_t;

using auto_hybrid_t = tim::auto_hybrid<tuple_t, list_t>;

#else

#    include <ostream>
#    include <string>

namespace tim
{
void                              print_env() {}
template <typename... _Args> void timemory_init(_Args...) {}
void                              timemory_finalize() {}

/// this provides "functionality" for *_HANDLE macros
/// and can be omitted if these macros are not utilized
struct dummy
{
    template <typename... _Args> dummy(_Args&&...) {}
    ~dummy()            = default;
    dummy(const dummy&) = default;
    dummy(dummy&&)      = default;
    dummy& operator=(const dummy&) = default;
    dummy& operator=(dummy&&) = default;

    void                              start() {}
    void                              stop() {}
    void                              report_at_exit(bool) {}
    template <typename... _Args> void mark_begin(_Args&&...) {}
    template <typename... _Args> void mark_end(_Args&&...) {}
    friend std::ostream& operator<<(std::ostream& os, const dummy&) { return os; }
};
}  // namespace tim

// creates a label
#    define TIMEMORY_BASIC_LABEL(...) std::string("")
#    define TIMEMORY_LABEL(...) std::string("")

// define an object
#    define TIMEMORY_BLANK_MARKER(...)
#    define TIMEMORY_BASIC_MARKER(...)
#    define TIMEMORY_MARKER(...)

// define an object with a caliper reference
#    define TIMEMORY_BLANK_CALIPER(...)
#    define TIMEMORY_BASIC_CALIPER(...)
#    define TIMEMORY_CALIPER(...)
#    define TIMEMORY_CALIPER_APPLY(...)
#    define TIMEMORY_CALIPER_TYPE_APPLY(...)

// define a static object with a caliper reference
#    define TIMEMORY_STATIC_BLANK_CALIPER(...)
#    define TIMEMORY_STATIC_BASIC_CALIPER(...)
#    define TIMEMORY_STATIC_CALIPER(...)

// define an object
#    define TIMEMORY_BLANK_HANDLE(...) tim::dummy()
#    define TIMEMORY_BASIC_HANDLE(...) tim::dummy()
#    define TIMEMORY_HANDLE(...) tim::dummy()

// debug only
#    define TIMEMORY_DEBUG_BASIC_MARKER(...)
#    define TIMEMORY_DEBUG_MARKER(...)
#    define TIMEMORY_DEBUG_BASIC_MARKER(...)
#    define TIMEMORY_DEBUG_MARKER(...)

// pointers
#    define TIMEMORY_BLANK_POINTER(...)
#    define TIMEMORY_BASIC_POINTER(...)
#    define TIMEMORY_POINTER(...)

#endif
