/* Astartup Cookbook @version 0.x
@link    https://github.com/KabukiStarship/astartup.cookbook.git
@file    /_Seams/00.test.h
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright 2015-2023 (C) Cale McCollough; all rights reserved (R). This
source code form is covered under the Kabuki Strong Source-available License.
A copy of the license that YOU MUST READ can be found in the readme.md file
in this folder. */

#pragma once
#include <_Config.h>

#if SEAM == ASTARTUP_COOKBOOK_TEST
#include "_Debug.inl"
#else
#include "_Release.inl"
#endif

using namespace _;

namespace astartup {
namespace cookbook {
inline const CHA* _0_Foo(CHA* seam_log, CHA* seam_end, const CHA* args) {
#if SEAM >= ASTARTUP_COOKBOOK_TEST
  TEST_BEGIN;

  PRINT_HEADING("Testing Foo Fun.");

#endif
  return 0;
}
}  //< namespace cookbook
}  //< namespace astartup
