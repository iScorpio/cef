// Copyright (c) 2018 Marshall A. Greenblatt. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//    * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//    * Neither the name of Google Inc. nor the name Chromium Embedded
// Framework nor the names of its contributors may be used to endorse
// or promote products derived from this software without specific prior
// written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// ---------------------------------------------------------------------------
//
// The contents of this file must follow a specific format in order to
// support the CEF translator tool. See the translator.README.txt file in the
// tools directory for more information.
//

#ifndef CEF_INCLUDE_CEF_AUDIO_HANDLER_H_
#define CEF_INCLUDE_CEF_AUDIO_HANDLER_H_
#pragma once

#include "include/cef_base.h"
#include "include/cef_browser.h"

///
// Implement this interface to handle audio events
// All methods will be called on the UI thread
///
/*--cef(source=client)--*/
class CefAudioHandler : public virtual CefBaseRefCounted {
 public:
  typedef cef_channel_layout_t ChannelLayout;

  ///
  // Event handler for every new audio stream, |audio_stream_id|
  // will identify this stream in future events, and is unique across
  // all other audio stream. OnAudioStreamStarted can be called also
  // after OnAudioSteamStopped was called. |channels| amount of channels
  // used on stream and |channel_layout| the used layout of the channels,
  // |sample_rate| define the used sample rate of stream. With
  // |frames_per_buffer| becomes the normally used amount of frames
  // on called stream defined.
  // On |process| can be the used class added who handle to stream.
  ///
  /*--cef()--*/
  virtual void OnAudioStreamStarted(CefRefPtr<CefBrowser> browser,
                                    int audio_stream_id,
                                    int channels,
                                    ChannelLayout channel_layout,
                                    int sample_rate,
                                    int frames_per_buffer) {}

  ///
  // Event handler for new audio packet from |audio_stream_id|,
  // |data| is an array representing raw PCM data.
  // |frames| is the number of frames in the PCM packet.
  ///
  /*--cef()--*/
  virtual void OnAudioStreamPacket(CefRefPtr<CefBrowser> browser,
                                   int audio_stream_id,
                                   const void** data,
                                   int frames,
                                   int64_t pts) {}

  ///
  // Event handler for stream |audio_stream_id| has been stopped,
  // for every OnAudioStreamStarted, OnAudioSteamStopped will be
  // called.
  ///
  /*--cef()--*/
  virtual void OnAudioStreamStopped(CefRefPtr<CefBrowser> browser,
                                    int audio_stream_id) {}
};

#endif  // CEF_INCLUDE_CEF_AUDIO_HANDLER_H_
