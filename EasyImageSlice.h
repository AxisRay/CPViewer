//
// Created by rayle on 2016/4/4.
//

#ifndef CPVIEWER_EASYIMAGESLICE_H
#define CPVIEWER_EASYIMAGESLICE_H


#include <vtkImageData.h>
#include <vtkSmartPointer.h>
#include <vtkImageReslice.h>
#include <vtkImageActor.h>
#include <vtkLookupTable.h>
#include <vtkImageMapToRGBA.h>
#include <vtkImageResliceToColors.h>
#include <vtkImageMapper3D.h>

class EasyImageSlice {
public:
    int extent[6];
    double spacing[3];
    double origin[3];
    double ScalarRange[2];
    double center[3];
    double offset[3];

    enum SliceDirection{AXIAL,SAGITTAL,CORONAL};
    enum DataType{CT,OPT};
    DataType type;
    EasyImageSlice(vtkImageData* image,DataType type);
    ~EasyImageSlice();
    vtkSmartPointer<vtkImageActor> getActor(SliceDirection d);

    void SetResliceAxesOrigin(SliceDirection d, double value);

    void SetOffset(double x, double y, double z);
private:


    vtkSmartPointer<vtkImageData> image;
    vtkSmartPointer<vtkImageResliceToColors> axialReslice;
    vtkSmartPointer<vtkImageResliceToColors> sagittalReslice;
    vtkSmartPointer<vtkImageResliceToColors> coronalReslice;
    vtkSmartPointer<vtkLookupTable> colorTable;
    //vtkSmartPointer<vtkImageMapToRGBA> color;

    void InitReslice(vtkImageResliceToColors* reslice,SliceDirection direction);

    void InitColor();


};


#endif //CPVIEWER_EASYIMAGESLICE_H
