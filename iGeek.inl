/* Interactive Gym Environment and Educational Kit (iGeek) @version 0.x
@link    https://github.com/KabukiStarship/iGeek.git
@file    /iGeek.inl
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2015-2023 Kabuki Starship <kabukistarship.com>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include <_Config.h>

#include "c_iGeek.h"

namespace _ {

Cell_IGA::Cell_IGA() { add(new LeukocyteWar()); }

static void Cell_IGA::main(AString[] args) {
  JFrame window = new JFrame("Kabuki.Cell_IGA");
  window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

  JScrollPane scrollableArea = new JScrollPane(new LeukocyteWar());

  window.setContentPane(scrollableArea);

  window.pack();
  window.setVisible(true);
}

}  //< namespace _
}
