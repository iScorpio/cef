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
// $hash=3a32f1847cb1c2ead583d404a0e58988943c968f$
//

#ifndef CEF_LIBCEF_DLL_CTOCPP_REGISTER_CDM_CALLBACK_CTOCPP_H_
#define CEF_LIBCEF_DLL_CTOCPP_REGISTER_CDM_CALLBACK_CTOCPP_H_
#pragma once

#if !defined(BUILDING_CEF_SHARED)
#error This file can be included DLL-side only
#endif

#include "include/capi/cef_browser_capi.h"
#include "include/capi/cef_web_plugin_capi.h"
#include "include/cef_browser.h"
#include "include/cef_web_plugin.h"
#include "libcef_dll/ctocpp/ctocpp_ref_counted.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed DLL-side only.
class CefRegisterCdmCallbackCToCpp
    : public CefCToCppRefCounted<CefRegisterCdmCallbackCToCpp,
                                 CefRegisterCdmCallback,
                                 cef_register_cdm_callback_t> {
 public:
  CefRegisterCdmCallbackCToCpp();

  // CefRegisterCdmCallback methods.
  void OnCdmRegistrationComplete(cef_cdm_registration_error_t result,
                                 const CefString& error_message) override;
};

#endif  // CEF_LIBCEF_DLL_CTOCPP_REGISTER_CDM_CALLBACK_CTOCPP_H_
