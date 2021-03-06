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
 * system data - place for system functions and definition of default file paths
 */

#ifndef MANDELBULBER2_SRC_SYSTEM_HPP_
#define MANDELBULBER2_SRC_SYSTEM_HPP_

#define MANDELBULBER_VERSION 2.09
#define MANDELBULBER_VERSION_STRING "2.09"
#define TO_STRING(a) #a

#ifdef WIN32 /* WINDOWS */
// #include <windows.h>
#define HAVE_BOOLEAN /* prevent jmorecfg.h from redefining it */
#endif

#ifndef SHARED_DIR
#ifdef WIN32
#elif __APPLE__
#define SHARED_DIR QDir::homePath() + "/share/mandelbulber2"
#else
#define SHARED_DIR "/usr/share/mandelbulber2"
#endif
#endif

#include <QtCore>
#include <qapplication.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct sSystem
{
	QString homedir;
	QString dataDirectory;
	QString sharedDir;
	QString logfileName;
	QString lastSettingsFile;
	QString lastImageFile;
	QString lastImagePaletteFile;
	QString thumbnailDir;
	QString autosaveFile;
	QHash<QString, QString> supportedLanguages;
	int numberOfThreads;
	bool noGui;
	QChar decimalPoint;
	QLocale locale;
	int terminalWidth;
	bool statsOnCLI;
	bool useColor;
	int loggingVerbosity;
	bool settingsLoadedFromCLI;
	QElapsedTimer globalTimer;
	bool globalStopRequest;
};

struct sActualFileNames
{
	QString actualFilenameSettings;
	QString actualFilenameImage;
	QString actualFilenamePalette;
};

extern sSystem systemData;
extern sActualFileNames actualFileNames;

bool InitSystem(void);
void WriteLog(QString text, int verbosityLevel);
void WriteLogDouble(QString text, double value, int verbosityLevel);
void WriteLogString(QString text, QString value, int verbosityLevel);
void handle_winch(int sig);
int get_cpu_count();
bool CreateDefaultFolders(void);
bool CreateFolder(QString name);
void DeleteAllFilesFromDirectory(QString folder, QString filterExpression);
int fcopy(QString source, QString dest);
void Wait(long int time);
void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg);
void UpdateDefaultPaths();
void UpdateUIStyle();
void UpdateUISkin();
void UpdateLanguage(QCoreApplication *app);
void RetrieveToolbarPresets(bool force);
void RetrieveExampleMaterials(bool force);

#endif /* MANDELBULBER2_SRC_SYSTEM_HPP_ */
