/* Interactive Gym Environment and Educational Kit (iGeek) @version 0.x
@link    https://github.com/KabukiStarship/iGeek.git
@file    /geneticpolygonpanel.h
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2015-2023 Kabuki Starship <kabukistarship.com>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <_Config.h>

namespace _ {

class GeneticPolygonPanel : public JPanel {
  static const ISC defaultMargin = 30;

  GeneticPolygonPanel(GeneticPolygon thisShape, AString thisShapeLabel,
                      ISC width, ISC height);

  void paintComponent(Graphics g);

  GeneticPolygon getGeneticPolygon();

  void respawn(ISC numPoints, ISC width, ISC height, ISC color, ISC lifespan,
               double angle);

  void setGeneticPolygon(GeneticPolygon newPoly);

 private:
  GeneticPolygon gPoly;
};

}  //< namespace _
}
