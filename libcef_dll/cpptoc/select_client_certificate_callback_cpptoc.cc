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
// $hash=4d0bcfb4123d37b0e9fd61b31e574c697f8258ba$
//

#include "libcef_dll/cpptoc/select_client_certificate_callback_cpptoc.h"
#include "libcef_dll/cpptoc/x509certificate_cpptoc.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

void CEF_CALLBACK select_client_certificate_callback_select(
    struct _cef_select_client_certificate_callback_t* self,
    struct _cef_x509certificate_t* cert) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Unverified params: cert

  // Execute
  CefSelectClientCertificateCallbackCppToC::Get(self)->Select(
      CefX509CertificateCppToC::Unwrap(cert));
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

CefSelectClientCertificateCallbackCppToC::
    CefSelectClientCertificateCallbackCppToC() {
  GetStruct()->select = select_client_certificate_callback_select;
}

template <>
CefRefPtr<CefSelectClientCertificateCallback>
CefCppToCRefCounted<CefSelectClientCertificateCallbackCppToC,
                    CefSelectClientCertificateCallback,
                    cef_select_client_certificate_callback_t>::
    UnwrapDerived(CefWrapperType type,
                  cef_select_client_certificate_callback_t* s) {
  NOTREACHED() << "Unexpected class type: " << type;
  return NULL;
}

#if DCHECK_IS_ON()
template <>
base::AtomicRefCount CefCppToCRefCounted<
    CefSelectClientCertificateCallbackCppToC,
    CefSelectClientCertificateCallback,
    cef_select_client_certificate_callback_t>::DebugObjCt ATOMIC_DECLARATION;
#endif

template <>
CefWrapperType CefCppToCRefCounted<
    CefSelectClientCertificateCallbackCppToC,
    CefSelectClientCertificateCallback,
    cef_select_client_certificate_callback_t>::kWrapperType =
    WT_SELECT_CLIENT_CERTIFICATE_CALLBACK;
