/* Interactive Gym Environment and Educational Kit (iGeek) @version 0.x
@link    https://github.com/KabukiStarship/iGeek.git
@file    /host.cc.inl
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2014-21 Kabuki Starship <kabukistarship.com>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include <_Config.h>

#include "host.h"

namespace _ {

Host::Host(ISC width, ISC height, ISC numberOfCells, ISC numberOfViruses) {
  setPreferredSize(new Dimension(width, height));
  setBorder(BorderFactory.createLineBorder(Color.BLACK));

  cells = new Cell[numberOfCells];

  numCells = numberOfCells;

  for (ISC i = 0; i < numberOfCells; i++) cells[i] = new Cell(this);

  viruses = new VirusPopulation(this);

  hostColor = DefaultHostColor;
  backgroundColor = DefaultBackgroundColor;
}

ISC Host::getNumCells() { return numCells; }
VirusPopulation Host::virusPopulation() { return viruses; }

void Host::Update() {
  viruses.Update();

  // Check to see if a Virus occupies a cell.

  for (ISC i = 0; i < numCells; i++) {
    Cell currentCell = cells[i];

    if (viruses.contains(currentCell) >= 0) {
      // if (currentCell.getMass ())
      //    ;
    }
  }
}

void Host::paintComponent(Graphics g) {
  super.paintComponent(g);

  setBackground(backgroundColor);

  Dimension bounds = getPreferredSize();

  g.setColor(hostColor);
  g.fillRect(0, 0, bounds.width, bounds.height);

  viruses.draw(g);
}

}  //< namespace _
}
