/* Interactive Gym Environment and Educational Kit (iGeek) @version 0.x
@link    https://github.com/KabukiStarship/iGeek.git
@file    /geneticpolygontestpanel.cc.inl
@author  Cale McCollough <https://cookingwithcale.org>
@license Copyright (C) 2014-21 Kabuki Starship <kabukistarship.com>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at <https://mozilla.org/MPL/2.0/>. */

#include <_Config.h>

namespace _ {

GeneticPolygonTestPanel::GeneticPolygonTestPanel() {
  setPreferredSize(new Dimension(panelWidth, panelHeight));

  timer = new Timer(timerUpdateInterval, new TimerAction());
  timerOn = false;

  JButton startButton = new JButton("Start");
  JButton stopButton = new JButton("Stop");
  JButton mateButton = new JButton("Mate");
  JButton nextButton = new JButton("Next");

  startButton.addActionListener(new StartAction());
  stopButton.addActionListener(new StopAction());
  mateButton.addActionListener(new MateAction());
  nextButton.addActionListener(new NextAction());

  JPanel buttonPanel = new JPanel();
  buttonPanel.add(startButton);
  buttonPanel.add(stopButton);
  buttonPanel.add(mateButton);
  buttonPanel.add(nextButton);

  initializePopulation();
  cell = new GeneticPolygon(5, (ISC)((double)GeneticPolygon.defaultSize * 1.3),
                            (ISC)((double)GeneticPolygon.defaultSize * 1.3),
                            Color.blue.getRGB(), GeneticPolygon.defaultLifespan,
                            GeneticPolygon.defaultAngle);

  GeneticPolygon adam = population[0], eve = population[1],
                 child = new GeneticPolygon(adam, eve);

  motherPanel =
      new GeneticPolygonPanel(adam, "Father", parentPanelSize, parentPanelSize);
  matGrandPanel = new GeneticPolygonPanel(null, "Maternal Grandparents",
                                          parentPanelSize, parentPanelSize);

  fatherPanel =
      new GeneticPolygonPanel(eve, "Mother", parentPanelSize, parentPanelSize);
  patGrandPanel = new GeneticPolygonPanel(null, "Paternal Grandparents",
                                          parentPanelSize, parentPanelSize);

  childPanel = new GeneticPolygonChildPanel(
      cell, child, "Child", childPanelSize, 2 * parentPanelSize + panelMargin);

  JPanel maternalPanel = new JPanel(new BorderLayout()),
         paternalPanel = new JPanel(new BorderLayout());

  maternalPanel.setPreferredSize(
      new Dimension(parentPanelSize, 2 * parentPanelSize + panelMargin));
  paternalPanel.setPreferredSize(
      new Dimension(parentPanelSize, 2 * parentPanelSize + panelMargin));

  maternalPanel.add(motherPanel, BorderLayout.NORTH);
  maternalPanel.add(matGrandPanel, BorderLayout.SOUTH);

  paternalPanel.add(fatherPanel, BorderLayout.NORTH);
  paternalPanel.add(patGrandPanel, BorderLayout.SOUTH);

  JPanel polygonsPanel = new JPanel();
  polygonsPanel.add(maternalPanel);
  polygonsPanel.add(childPanel);
  polygonsPanel.add(paternalPanel);

  setLayout(new BorderLayout());
  add(polygonsPanel, BorderLayout.CENTER);
  add(buttonPanel, BorderLayout.SOUTH);
}

void GeneticPolygonTestPanel::initializePopulation() {
  populationSize = initPopulationSize;

  population = new GeneticPolygon[initPopulationSize];

  for (ISC i = 0; i < initPopulationSize; i++) {
    ISC numPoints = (ISC)(Math.floor(Math.random() * 5.0 + 3.0));
    population[i] = new GeneticPolygon(
        numPoints, GeneticPolygon.getDefaultColor(numPoints).getRGB());
  }
}

void GeneticPolygonTestPanel::paintComponent(Graphics g) {
  super.paintComponent(g);

  motherPanel.paintComponent(g);
  fatherPanel.paintComponent(g);
  childPanel.paintComponent(g);
}

void GeneticPolygonTestPanel::iterateGeneration() {
  ISC numberToMate =
      (ISC)(GeneticPolygon.matingPercent * (double)populationSize);

  for (ISC i = 0; i < numberToMate; i++) mateRandom();

  for (ISC i = 0; i < populationSize; i++) {
    if (population[i] != null) {
      if (!population[i].age(
              10000))  // The defaultLifespan is x number of seconds.
        population[i] = null;
    }
  }

  repaint();  // Repaint indirectly calls paintComponent.
}

void GeneticPolygonTestPanel::mateRandom() {
  ISC randomIndex, numTries = 0, maxRandomTries = 2 * populationSize;

  do {
    randomIndex = (ISC)(Math.random() * (double)(populationSize - 1));
    numTries++;

    if (numTries == maxRandomTries) {
      for (randomIndex = 0; randomIndex < populationSize; ++randomIndex)
        if (population[randomIndex] != null) break;

      if (randomIndex == populationSize) {
        timerOn = false;
        System.out.print("Error! The entire population is dead!!!\n");
        return;
      } else
        break;
    }
  } while (population[randomIndex] == null);

  GeneticPolygon newFather = population[randomIndex],
                 newMother = childPanel.getChild(),
                 newChild = new GeneticPolygon(newMother, newFather);

  fatherPanel.setGeneticPolygon(newFather);
  motherPanel.setGeneticPolygon(newMother);
  childPanel.setChild(newChild);

  addChild(newChild);
}

void GeneticPolygonTestPanel::addChild(GeneticPolygon newChild) {
  ISC i;
  for (i = 0; i < populationSize; i++) {
    if (population[i] == null) {
      population[i] = newChild;
      return;
    }
  }
  // We couldn't find a hole so increase the array size;
  GeneticPolygon[] newPopulation = new GeneticPolygon[populationSize + 1];

  for (i = 0; i < populationSize; i++) newPopulation[i] = population[i];
  newPopulation[i] = newChild;
  population = newPopulation;
  populationSize++;
}

void StartAction::actionPerformed(ActionEvent e) { timerOn = true; }

void StopAction::actionPerformed(ActionEvent e) { timerOn = false; }

void NextAction::actionPerformed(ActionEvent e) { iterateGeneration(); }

void MateAction::actionPerformed(ActionEvent e) {
  mateRandom();

  repaint();  // Repaint indirectly calls paintComponent.
}

void TimerAction::actionPerformed(ActionEvent e) {
  if (timerOn) {
    iterateGeneration();
  }
}

}  //< namespace _
}
