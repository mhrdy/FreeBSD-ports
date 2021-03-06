--- deps/v8/src/libsampler/sampler.cc.orig	2016-11-08 18:53:14 UTC
+++ deps/v8/src/libsampler/sampler.cc
@@ -499,9 +499,9 @@ void SignalHandler::FillRegisterState(vo
   state->sp = reinterpret_cast<void*>(mcontext.mc_rsp);
   state->fp = reinterpret_cast<void*>(mcontext.mc_rbp);
 #elif V8_HOST_ARCH_ARM
-  state->pc = reinterpret_cast<void*>(mcontext.mc_r15);
-  state->sp = reinterpret_cast<void*>(mcontext.mc_r13);
-  state->fp = reinterpret_cast<void*>(mcontext.mc_r11);
+  state->pc = reinterpret_cast<void*>(mcontext.__gregs[_REG_PC]);
+  state->sp = reinterpret_cast<void*>(mcontext.__gregs[_REG_SP]);
+  state->fp = reinterpret_cast<void*>(mcontext.__gregs[_REG_FP]);
 #endif  // V8_HOST_ARCH_*
 #elif V8_OS_NETBSD
 #if V8_HOST_ARCH_IA32
