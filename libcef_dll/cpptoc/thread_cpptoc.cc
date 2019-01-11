// Copyright (c) 2019 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool. If making changes by
// hand only do so within the body of existing method and function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//
// $hash=09da054aa0a5b5e09bf6b96d03c5679d7673b633$
//

#include "libcef_dll/cpptoc/thread_cpptoc.h"
#include "libcef_dll/cpptoc/task_runner_cpptoc.h"

// GLOBAL FUNCTIONS - Body may be edited by hand.

CEF_EXPORT cef_thread_t* cef_thread_create(
    const cef_string_t* display_name,
    cef_thread_priority_t priority,
    cef_message_loop_type_t message_loop_type,
    int stoppable,
    cef_com_init_mode_t com_init_mode) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Unverified params: display_name

  // Execute
  CefRefPtr<CefThread> _retval = CefThread::CreateThread(
      CefString(display_name), priority, message_loop_type,
      stoppable ? true : false, com_init_mode);

  // Return type: refptr_same
  return CefThreadCppToC::Wrap(_retval);
}

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

cef_task_runner_t* CEF_CALLBACK
thread_get_task_runner(struct _cef_thread_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefTaskRunner> _retval =
      CefThreadCppToC::Get(self)->GetTaskRunner();

  // Return type: refptr_same
  return CefTaskRunnerCppToC::Wrap(_retval);
}

cef_platform_thread_id_t CEF_CALLBACK
thread_get_platform_thread_id(struct _cef_thread_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return kInvalidPlatformThreadId;

  // Execute
  cef_platform_thread_id_t _retval =
      CefThreadCppToC::Get(self)->GetPlatformThreadId();

  // Return type: simple
  return _retval;
}

void CEF_CALLBACK thread_stop(struct _cef_thread_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefThreadCppToC::Get(self)->Stop();
}

int CEF_CALLBACK thread_is_running(struct _cef_thread_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefThreadCppToC::Get(self)->IsRunning();

  // Return type: bool
  return _retval;
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

CefThreadCppToC::CefThreadCppToC() {
  GetStruct()->get_task_runner = thread_get_task_runner;
  GetStruct()->get_platform_thread_id = thread_get_platform_thread_id;
  GetStruct()->stop = thread_stop;
  GetStruct()->is_running = thread_is_running;
}

template <>
CefRefPtr<CefThread>
CefCppToCRefCounted<CefThreadCppToC, CefThread, cef_thread_t>::UnwrapDerived(
    CefWrapperType type,
    cef_thread_t* s) {
  NOTREACHED() << "Unexpected class type: " << type;
  return NULL;
}

#if DCHECK_IS_ON()
template <>
base::AtomicRefCount
    CefCppToCRefCounted<CefThreadCppToC, CefThread, cef_thread_t>::DebugObjCt
        ATOMIC_DECLARATION;
#endif

template <>
CefWrapperType CefCppToCRefCounted<CefThreadCppToC, CefThread, cef_thread_t>::
    kWrapperType = WT_THREAD;
