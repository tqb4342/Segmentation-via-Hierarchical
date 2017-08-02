#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <itksys/Process.h>
#include <vector>
//#include <dirent.h>

#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageRegionIterator.h"
#include "itkVTKImageIO.h"
#include "itkImageIOBase.h"

#include "vtkPolyDataReader.h"
#include "vtkPolyData.h"
#include "vtkPointSet.h"
#include "vtkCell.h"

#include <itksys/Glob.hxx>
#include <itksys/Process.h>

#include <string>
#include <stdlib.h>
#include <itksys/Glob.hxx>

using namespace std;

class Parameters
{
public:

  Parameters();
  ~Parameters();

  void ReadFile(const char *_FileName);

  void SetModulePath(char *);

  void SetParameterFile(const char *_ParamFile);

  void SetDataList(vector<vector<string> > _List);

  int GetListSize();

  void SetOutputDirectory(const char *_OutputDirectory);

  void SetChooseInputColumnState(bool inputColumn);

  void SetColumnVolumeFile(int column);

  void SetDataNumber(int _DataNumber);

  void SetEnforcedSpace(float _sx, float _sy, float _sz);

  void SetLabel(double _Label);

  void SetLabelState(bool _LabelState);
  void SetRescaleState(bool _RescaleState);

  void SetNumberOfIterations(int _NumIter);

  void SetSubdivLevel(int _SubdivLevel);

  void SetSPHARMDegree(int _SPHARMDegree);
  
  void SetThetaIteration(int _ThetaIteration);
  
  void SetPhiIteration(int _PhiIteration);
  
  void SetMedialMesh(bool _MedialMesh);

  void SetGaussianFilteringState(bool _GaussianFilteringState);

  void SetVarianceBox(int _vx, int _vy, int _vz);

  void SetRegTemplateState(bool _RegTemplateState);

  void SetFlipTemplateState(bool _FlipTemplateState);

  void SetTemplateMState(bool _TemplateMState);

  void SetFlipTemplate(const char *_FlipTemplate);

  void SetRegTemplate(const char *_FlipTemplate);

  void SetParaOut1State(bool _ParaOut1State);

  void SetParaOut2State(bool _ParaOut2State);

  void SetParticlesState(bool _DoParticlesCorrespondence);

  bool GetParticlesState();

  void SetUseProcalign(bool );

  bool GetUseProcalign();

  void SetFinalFlip(int _None_Flip, int _X_Flip, int _Y_Flip, int _Z_Flip, int _XY_Flip, int _YZ_Flip, int _XZ_Flip,
                    int _XYZ_Flip);

  void SetHorizontalGridPara(int _HorizontalGridPara);

  void SetVerticalGridPara(int _VerticalGridPara);

  char * GetModulePath();

  vector<string> GetOutputFileHeaders();

  string GetVolumeFileExtension();

  int GetColumnVolumeFile();

  bool GetChooseInputColumnState();

  const char * GetParameterFile();

  int MeanTemplateExist();

  const char * GetOutputDirectory();

  int GetDataNumber();

  float GetEnforcedSpaceX();

  float GetEnforcedSpaceY();

  float GetEnforcedSpaceZ();

  double GetLabel();

  bool GetLabelState();
  bool GetRescaleState();

  int GetNumberOfIterations();

  double GetSubdivLevel();

  int GetSPHARMDegree();
  
  int GetThetaIteration();
  
  int GetPhiIteration();
  
  bool GetMedialMesh();

  bool GetGaussianFilteringState();

  int GetVarianceBoxX();

  int GetVarianceBoxY();

  int GetVarianceBoxZ();

  bool GetFlipTemplateState();

  bool GetRegTemplateState();

  bool GetTemplateMState();

  char * GetFlipTemplate();

  char * GetRegTemplate();

  bool GetParaOut1State();

  bool GetParaOut2State();

  int GetFinalFlipN();

  int GetFinalFlipX();

  int GetFinalFlipY();

  int GetFinalFlipZ();

  int GetFinalFlipXY();

  int GetFinalFlipYZ();

  int GetFinalFlipXZ();

  int GetFinalFlipXYZ();

  int GetHorizontalGridPara();

  int GetVerticalGridPara();

  string GetNthDataListValue(int line, int column);

  void  SetAllFilesName();

  void SetFilesNameMRML(int);

  // void  SetAllFilesName25(int);
  string GetAllFilesName(int);

  char * GetAllSurfSPHARMFiles(int);

  char * GetAllSurfSPHARMellalignFiles(int);

  char * GetAllSurfSPHARMprocalignFiles(int);

  char * GetAllSurfmeanSPHARMFiles(int);

  char * GetAllSurfmeanSPHARMellalignFiles(int);

  char * GetAllSurfmeanSPHARMprocalignFiles(int);

  string GetAllPhiFiles(int);

  string GetAllThetaFiles(int);

  void SetImageDimensions(char *);

  vector<double> GetImageDimensions();

  vector<double> GetBox();

  double GetConstantOrientation();

  string GetDirectionToDisplay();

  void  SetEndRegularization(double );

  double GetEndRegularization();

  void SetStartRegularization(double);

  double GetStartRegularization();

  void SetOptimizationIteration(int );

  int GetOptimizationIteration();

  void SetRelativeWeighting(float );

  float GetRelativeWeighting();

  void SetOverwriteSegPostProcess(bool);

  void SetOverwriteGenParaMesh(bool);

  void SetOverwriteParaToSPHARMMesh(bool);

  void SetRandomizeInputs(bool);

  bool GetOverwriteSegPostProcess();

  bool GetOverwriteGenParaMesh();

  bool GetOverwriteParaToSPHARMMesh();

  int GetRandomizeInputs();

  void SetDebug(bool);
  bool GetDebug();

  bool m_DoParticlesCorrespondence;
  bool m_UseProcalign;

  bool DirectoryIsEmpty(const char *);

  void SetEulerNumbers();

  void ModifyCSV(int);

  void ModifyMRML(std::string, std::string, std::string  );

  std::string readMRML(std::string, bool);

  vector<string> m_EulerNumber;
  std::string GetEulerNumber(std::string txtFile);

  vector<string>           m_SphericalTopo;
  std::vector<std::string> EulerFile;
  void FindFiles();

  char * GetPostCorrespondenceFiles(int);

  char * Convert_Double_To_CharArray(double );

  void DeleteTransformsFolders(int type);

  void  FindTemplateFiles(int);

  std::string GetTemplate(int);

  int SetNbSnapShot();

  std::vector<std::string> name_template;
  // string m_ListFiles;
  string m_ListFiles_ellalign;
  string m_ListFiles_procalign;
  string GetListFiles_ellalign();

  // string GetListFiles();
  string GetListFiles_procalign();

  char* * m_ListFiles;
  // string m_ListFiles_ellalign;
  // string m_ListFiles_procalign;
  // string GetListFiles_ellalign();
  char * GetListFiles(int);

  // string GetListFiles_procalign();

  bool m_FlipTemplateState;
  bool m_RegTemplateState;
  bool m_TemplateMState;
  char m_FlipTemplate[512];
  char m_RegTemplate[512];
private:

  char                    m_ModulePath[512];
  vector<vector<string> > m_List;
  vector<string>          m_OutputFileHeaders;
  char                    m_FilesName[512];
  char                    m_MRLMFile[512];
  string                  m_VolumeFileExtension;
  int                     m_ColumnVolume;
  bool                    m_ChooseColumnState;

  float  m_RelativeWeight;
  double m_endRegularization;
  double m_startRegularization;
  int    m_optimizationIteration;

  int ListSize;

  char m_ParamFile[512];
  std::string m_OutputDirectory;
  bool m_RandomizeInputs;
  bool m_debug;

  int m_DataNumber;

  float m_sx;
  float m_sy;
  float m_sz;

  double m_Label;
  bool   m_LabelState;
  bool   m_RescaleState;
  int    m_NumIter;
  int    m_SubdivLevel;
  int    m_SPHARMDegree;
  int 	m_ThetaIteration;
  int		m_PhiIteration;
  bool 	m_MedialMesh;

  bool m_GaussianFilteringState;

  int m_vx;
  int m_vy;
  int m_vz;

  bool m_ParaOut1State;
  bool m_ParaOut2State;

  int m_None_Flip;
  int m_X_Flip;
  int m_Y_Flip;
  int m_Z_Flip;
  int m_XY_Flip;
  int m_YZ_Flip;
  int m_XZ_Flip;
  int m_XYZ_Flip;

  bool m_OverwriteSegPostProcess;
  bool m_OverwriteGenParaMesh;
  bool m_OverwriteParaToSPHARMMesh;

  string         m_directionToDisplay;
  vector<double> m_Dims;
  vector<double> m_Box;

  //char* * m_AllFilesName;
  std::vector < string > m_AllFilesName;
  char* * m_AllFilesName25;
  char* * surfSPHARM_Files;
  char* * surfSPHARM_ellalign_Files;
  char* * surfSPHARM_procalign_Files;
  string  Phi_Files;
  string   Theta_Files;

  int    m_VerticalGridParaGrid;
  int    m_HorizontalGridParaGrid;
  double m_const_orientation;

  char* * Corres_Files;

};

#endif
