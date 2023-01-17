/* Interactive Gym Environment and Educational Kit (iGeek) @version 0.x
@link    https://github.com/KabukiStarship/iGeek.git
@file    /_Seams.h
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2015-2023 Kabuki Starship <kabukistarship.com>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <_Config.h>

#include "00_foo.h"

#if SEAM >= PROJECT_IGEEK_1
#include "01_bar.h"
#endif

namespace _ {

static const CHA* Test(const CHA* args) {
  return TTestTree<Foo
#if SEAM >= PROJECT_IGEEK_1
                   ,
                   Release
#endif
                   >(seam_log, seam_end, args);
}
}  //< namespace _
