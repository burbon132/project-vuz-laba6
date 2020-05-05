#pragma once
#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_
#include "List.h"
#include "Student.h"
void Compare(List& lst, char* TrainingDirection);
void Compare(List& lst, List& newlst, char* TrainingDirection, int GroupNumber);
void Eldest(List& lst, List& eldestlst);
void Junior(List& lst, List& juniorlst);
void SortList(List& lst);
void Save2Disk(List& lst);
void Read4Disk(List& lst);
void MainInterface();
void OptionalInterface(List& lst);
#endif // !_FUNCTIONS_N_