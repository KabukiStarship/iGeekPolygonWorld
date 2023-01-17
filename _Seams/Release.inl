/* Astartup Cookbook @version 0.x
@link    https://github.com/KabukiStarship/astartup.cookbook.git
@file    /_Seams/01.release.h
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright 2015-2023 (C) Cale McCollough; all rights reserved (R). This
source code form is covered under the Kabuki Strong Source-available License.
A copy of the license that YOU MUST READ can be found in the readme.md file
in this folder. */

#pragma once
#include <_Config.h>

#if SEAM == ASTARTUP_COOKBOOK_RELEASE
#include "_Debug.inl"
#else
#include "_Release.inl"
#endif

using namespace _;

namespace astartup { namespace cookbook { 
inline const CHA* Release (CHA* seam_log, CHA* seam_end, const CHA* args) {
#if SEAM >= ASTARTUP_COOKBOOK_RELEASE
  TEST_BEGIN;

  PRINT_HEADING ("Testing Foo fun.");

#endif
  return 0;
}
}  //< namespace cookbook
}  //< namespace astartup
