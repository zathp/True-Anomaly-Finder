// ASTR200.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <cmath>
#include "pch.h"
#include <iostream>
double Calc(double E, double o, double eccentricity);
double CalcTrue(double E, double eccen);
int main()
{
	double pi = acos(-1);
	double Ei, Ef, fin;
	double e = 0.9;
	double multi = .1;
	double o = pi * (multi);
	double tolerance = .01;
	printf("mean anomally = pi*");
	scanf_s("%E", &multi);
	printf("\nEnter the error tolerance:");
	scanf_s("%E", &tolerance);
	printf("\n");

	Ei = 0;
	Ef = o;
	do
	{
		Ei = Ef;
		Ef = Calc(Ei, o, e);
		printf("Ef=%e Ei=%e Ef-Ei=%e\n", Ef, Ei, Ef-Ei);
	} while ((Ef - Ei >= tolerance)||(Ei - Ef >= tolerance));

	fin = CalcTrue(Ef, e);
	printf("mean anom=%e :: E=%e :: 0=%E",o,Ef,fin);

	return(0);
}

double Calc(double E, double o, double eccentricity)
{
	double tempE;
	tempE = o + (eccentricity * sin(E));
	return tempE;
}

double CalcTrue(double E, double eccen)
{
	double temp1, temp2, tempf;
	temp1 = (1.0 - pow(eccen, 2)) / (1.0 - eccen * cos(E));
	temp2 = (temp1 - 1.0) / eccen;
	tempf = acos(temp2);
	return tempf;
}