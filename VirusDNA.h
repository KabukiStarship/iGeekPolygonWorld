/* Interactive Gym Environment and Educational Kit (iGeek) @version 0.x
@link    https://github.com/KabukiStarship/iGeek.git
@file    /virusdna.h
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2015-2023 Kabuki Starship <kabukistarship.com>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

namespace iGeek {

/* Class that represents a DNA Virus.
A DNA Virus is a type of virus that is made of DNA and replicates itself inside
of the cell cytoplasm.
@see    https:/en.wikipedia.org/wiki/DNA_virus
*/
class DNAVirus : public Virus {
 public:
  DNAVirus(FPD init_x, FPD init_y);
};
}  //< namespace iGeek
