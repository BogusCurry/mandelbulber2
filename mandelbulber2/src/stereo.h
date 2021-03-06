/**
 * Mandelbulber v2, a 3D fractal generator       ,=#MKNmMMKmmßMNWy,
 *                                             ,B" ]L,,p%%%,,,§;, "K
 * Copyright (C) 2014-16 Krzysztof Marczak     §R-==%w["'~5]m%=L.=~5N
 *                                        ,=mm=§M ]=4 yJKA"/-Nsaj  "Bw,==,,
 * This file is part of Mandelbulber.    §R.r= jw",M  Km .mM  FW ",§=ß., ,TN
 *                                     ,4R =%["w[N=7]J '"5=],""]]M,w,-; T=]M
 * Mandelbulber is free software:     §R.ß~-Q/M=,=5"v"]=Qf,'§"M= =,M.§ Rz]M"Kw
 * you can redistribute it and/or     §w "xDY.J ' -"m=====WeC=\ ""%""y=%"]"" §
 * modify it under the terms of the    "§M=M =D=4"N #"%==A%p M§ M6  R' #"=~.4M
 * GNU General Public License as        §W =, ][T"]C  §  § '§ e===~ U  !§[Z ]N
 * published by the                    4M",,Jm=,"=e~  §  §  j]]""N  BmM"py=ßM
 * Free Software Foundation,          ]§ T,M=& 'YmMMpM9MMM%=w=,,=MT]M m§;'§,
 * either version 3 of the License,    TWw [.j"5=~N[=§%=%W,T ]R,"=="Y[LFT ]N
 * or (at your option)                   TW=,-#"%=;[  =Q:["V""  ],,M.m == ]N
 * any later version.                      J§"mr"] ,=,," =="""J]= M"M"]==ß"
 *                                          §= "=C=4 §"eM "=B:m|4"]#F,§~
 * Mandelbulber is distributed in            "9w=,,]w em%wJ '"~" ,=,,ß"
 * the hope that it will be useful,                 . "K=  ,=RMMMßM"""
 * but WITHOUT ANY WARRANTY;                            .'''
 * without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with Mandelbulber. If not, see <http://www.gnu.org/licenses/>.
 *
 * ###########################################################################
 *
 * Authors: Krzysztof Marczak (buddhi1980@gmail.com)
 *
 * cStereo class - to render stereoscopic images
 */

#ifndef MANDELBULBER2_SRC_STEREO_H_
#define MANDELBULBER2_SRC_STEREO_H_

#include "algebra.hpp"
#include "color_structures.hpp"
#include "region.hpp"

class cStereo
{
public:
	enum enumStereoMode
	{
		stereoDisabled = -1,
		stereoLeftRight = 0,
		stereoTopBottom = 1,
		stereoRedCyan = 2
	};

	enum enumEye
	{
		eyeNone = -1,
		eyeLeft = 0,
		eyeRight = 1
	};

	cStereo();
	~cStereo();
	void SetMode(enumStereoMode mode);
	enumStereoMode GetMode() {return stereoMode;}
	bool isEnabled() {return stereoMode != stereoDisabled;}
	CVector3 CalcEyePosition(
		CVector3 camera, CVector3 direction, CVector3 top, double distance, enumEye eye);
	void ViewVectorCorrection(double correction, const CRotationMatrix &mRot, enumEye eye, CVector3 *viewVector);
	sRGBfloat MixColorsRedCyan(sRGBfloat left, sRGBfloat right);
	CVector2<int> ModifyImageResolution(CVector2<int> resolution);
	enumEye WhichEye(CVector2<double> imagePoint);
	CVector2<double> ModifyImagePoint(CVector2<double> imagePoint);
	double ModifyAspectRatio(double aspectRatio);
	int GetNumberOfRepeats();
	void WhichEyeForAnaglyph(enumEye *eye, int repeat);
	cRegion<int> GetRegion(CVector2<int> imageResolution, enumEye eye);

private:
	bool swapped;
	enumStereoMode stereoMode;
};

#endif /* MANDELBULBER2_SRC_STEREO_H_ */
