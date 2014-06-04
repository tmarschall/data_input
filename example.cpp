#include "file_input.h"
#include <iostream>

int main()
{
	// Read data from the file "sd0000000000.dat", which has space separated data
	// The second argument indicates that the file has a header
	DatFileInput data("sd0000008000.dat", true);
	
	int nRows = data.getRows();
	int nColumns = data.getColumns();
	int nHeaderLength = data.getHeadLen();
	std::cout << "The data has " << nRows << " rows, " << nColumns << " columns, and a header of length " << nHeaderLength << std::endl;
	
	// Return the value of the first column of the header, as an integer
	int nParticles = data.getHeadInt(0);
	// Get the second value in the header as a double precision floating point
	double dBoxLength = data.getHeadFloat(1);
	double dPackingFraction = data.getHeadFloat(2);
	double dGamma = data.getHeadFloat(3);
	double dTotalGamma = data.getHeadFloat(4);
	double dGammaDot = data.getHeadFloat(5);
	double dIntegrationStep = data.getHeadFloat(6);
	std::cout << "\nRun configuration:\n" << nParticles << " spherocylinders\n" << "box length: " << dBoxLength 
			  << "\npacking fraction: " << dPackingFraction << "\ngamma: " << dGamma << " (" << dTotalGamma << " total)\n"
			<< "strain rate: " << dGammaDot << "\nintegration step size: " << dIntegrationStep << std::endl;
			  
	double *pdX = new double[nRows];
	double *pdY = new double[nRows];
	double *pdTheta = new double[nRows];
	double *pdR = new double[nRows];
	double *pdA = new double[nRows];
	
	// Put the data from the first column into the array pdX
	data.getColumn(pdX, 0);
	data.getColumn(pdY, 1);
	data.getColumn(pdTheta, 2);
	data.getColumn(pdR, 3);
	data.getColumn(pdA, 4);
	
	std::cout << "\nFirst 10 spherocylinders: " << std::endl;
	for (int p = 0; p < 10; p++) {
		std::cout << "x=" << pdX[p] << ", y=" << pdY[p] << ", theta=" << pdTheta[p] << ", R=" << pdR[p] << ", A=" << pdA[p] << std::endl;
	}
	
	delete[] pdX;
	delete[] pdY;
	delete[] pdTheta;
	delete[] pdR;
	delete[] pdA;

	return 0;
}