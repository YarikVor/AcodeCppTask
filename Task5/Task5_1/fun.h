#pragma once

const int countTrying = 7;

void printYourGuessIsTooHighOrLow(bool isHigh);

int inputGuess(int attempt);

bool isExit();

void printEndGame();
void printHeader();
void printWin();
void printLoss(int value);

void pause();

int getRandomNumber(int min, int max);
