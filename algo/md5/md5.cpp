
////////////////////////////////////////////
// Generated by BRCC 1.3
// BRCC Compiled on: Dec  3 2008 14:25:23
////////////////////////////////////////////

#include "brook/brook.h"
#include "md5_gpu.h"
#include "md5.h"
#line 1 "md5.br"

#

#line 1 "d:\\my\\work\\barswf\\algo\\md5\\md5.h"

#

#pragma once

#line 2 "md5.br"

#

void  __hello_brook_check_cpu_inner(const __BrtFloat1  &input,
                                   __BrtFloat1  &output,
                                   const __BrtFloat1  &val)
{
  if (input > val)
  {
    output = __BrtFloat1(1.000000f);
  }

  else
  {
    output = __BrtFloat1(0.000000f);
  }

}
void  __hello_brook_check_cpu(::brt::KernelC *__k, const std::vector<void *>&args, int __brt_idxstart, int __brt_idxend, bool __brt_isreduce)
{
  ::brt::StreamInterface *arg_input = (::brt::StreamInterface *) args[0];
  ::brt::StreamInterface *arg_output = (::brt::StreamInterface *) args[1];
  __BrtFloat1 *arg_val = (__BrtFloat1 *) args[2];
  
    for(int __brt_idx=__brt_idxstart; __brt_idx<__brt_idxend; __brt_idx++) {
  if(!(__k->isValidAddress(__brt_idx))){ continue; }
    Addressable <__BrtFloat1  > __out_arg_output((__BrtFloat1 *) __k->FetchElem(arg_output, __brt_idx));
    __hello_brook_check_cpu_inner (
                                   Addressable <__BrtFloat1 >((__BrtFloat1 *) __k->FetchElem(arg_input, __brt_idx)),
                                   __out_arg_output,
                                   *arg_val);
    *reinterpret_cast<__BrtFloat1 *>(__out_arg_output.address) = __out_arg_output.castToArg(*reinterpret_cast<__BrtFloat1 *>(__out_arg_output.address));
  }
}
void __hello_brook_check::operator()(::brook::Stream< float > input,
		::brook::Stream<  float > output,
		const float  val)
{
  static const void *__hello_brook_check_fp[] = {
     "ps30", __hello_brook_check_ps30,
     "cal", __hello_brook_check_cal,
     "cpu", (void *) __hello_brook_check_cpu,
     NULL, NULL };

  static ::brook::Kernel  __k(__hello_brook_check_fp, brook::KERNEL_MAP);
  ::brook::ArgumentInfo __argumentInfo;

  __argumentInfo.inputArguments[0] = input;
  __k.PushStream(input);
  __argumentInfo.outputArguments[1] = output;
  __k.PushOutput(output);
  brook::Constant<float > constant_2(val);
  __argumentInfo.constArguments[2] = constant_2;
  __k.PushConstant(constant_2);
  __argumentInfo.startExecDomain = _domainOffset;
  __argumentInfo.domainDimension = _domainSize;


  __k.run(&__argumentInfo);

}

__hello_brook_check hello_brook_check;


