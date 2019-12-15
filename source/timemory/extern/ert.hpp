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

/** \file extern/ert.hpp
 * \headerfile extern/ert.hpp "timemory/extern/ert.hpp"
 * Extern template declarations
 *
 */

#pragma once

#if defined(TIMEMORY_EXTERN_TEMPLATES) && !defined(TIMEMORY_BUILD_EXTERN_TEMPLATE)

#    include "timemory/backends/cuda.hpp"
#    include "timemory/backends/device.hpp"
#    include "timemory/components/timing.hpp"
#    include "timemory/ert/configuration.hpp"
#    include "timemory/ert/counter.hpp"
#    include "timemory/ert/data.hpp"

namespace tim
{
namespace ert
{
//
//
extern template struct exec_data<component::wall_clock>;
//
extern template struct counter<device::cpu, float, component::wall_clock>;
extern template struct counter<device::cpu, double, component::wall_clock>;
extern template struct configuration<device::cpu, float, component::wall_clock>;
extern template struct configuration<device::cpu, double, component::wall_clock>;
//
#    if defined(TIMEMORY_USE_CUDA)
//
extern template struct counter<device::gpu, float, component::wall_clock>;
extern template struct counter<device::gpu, double, component::wall_clock>;
extern template struct counter<device::gpu, cuda::fp16_t, component::wall_clock>;
extern template struct configuration<device::gpu, float, component::wall_clock>;
extern template struct configuration<device::gpu, double, component::wall_clock>;
extern template struct configuration<device::gpu, cuda::fp16_t, component::wall_clock>;
//
#    endif
//
//
}  // namespace ert
}  // namespace tim

#endif
