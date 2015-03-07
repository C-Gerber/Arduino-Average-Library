/*
	Average.cpp - Library for computing average and standard deviation

	Created by Boris A. Gribovskiy, March 7, 2015.
	Released into the public domain
*/
#include "Arduino.h"
#include "Average.h"

Average::Average()
{
	_ind = 0;
	_n = 0;
	_calc = true; // new calulation is necessary
}


void putValue(float value)
{
	_values[_ind] = value;
	_ind++;
	_ind %= N_AVG;
	if (_n < N_AVG) _n++;
	_calc = true;
}

float getAverage();
{
	if (_calc) {
		float fn = (float)_n;
		for(int j = 0; j < _n; j++) {
			_avg += _values[j];
			_sigma += _values[j]*_values[j];
		}
		_avg /= fn;
		_sigma /= fn;
		_sigma = sqrt((_sigma - _avg*_avg)/fn);
	}
	_calc = false;
	return _avg;
}

float getSigma()
{
	if(_calc) getAverage();
	return _sigma;
}


unsigned short CRC16::crc(byte* data, unsigned short cnt)
{
	byte uchCRCHi = 0xFF;  /* high CRC byte initialized */
	byte uchCRCLo = 0xFF;  /* low CRC byte initialized  */ 
	unsigned uIndex;       /* will index into CRC lookup*/ 
						   /* table                  */ 
	while (cnt--)          /* pass through message buffer */ 
	{
		uIndex = uchCRCHi ^ *data++; /* calculate the CRC */ 
		uchCRCHi = uchCRCLo ^ auchCRCHi[uIndex];
		uchCRCLo = auchCRCLo[uIndex];
	}

	return (uchCRCLo << 8 | uchCRCHi);
}