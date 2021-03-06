/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2013 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#include <xenia/core/path.h>


void xe_path_join(const xechar_t* left, const xechar_t* right,
                  xechar_t* out_path, size_t out_path_size) {
#if XE_WCHAR
  xesnprintf(out_path, out_path_size, XT("%ls%c%ls"),
             left, XE_PATH_SEPARATOR, right);
#else
  xesnprintf(out_path, out_path_size, XT("%s%c%s"),
             left, XE_PATH_SEPARATOR, right);
#endif  // XE_WCHAR
}

void xe_path_get_absolute(const xechar_t* path, xechar_t* out_abs_path,
                          size_t abs_path_size) {
#if XE_PLATFORM(WIN32)
#if XE_WCHAR
  _wfullpath(out_abs_path, path, abs_path_size);
#else
  _fullpath(out_abs_path, path, abs_path_size);
#endif  // XE_WCHAR
#else
  realpath(path, out_abs_path);
#endif  // WIN32
}
