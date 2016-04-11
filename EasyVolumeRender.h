//
// Created by rayle on 2016/4/9.
//

#ifndef CPVIEWER_EASYVOLUMERENDER_H
#define CPVIEWER_EASYVOLUMERENDER_H


#include <vtkImageData.h>
#include <vtkSmartPointer.h>
#include <vtkVolume.h>
#include <vtkImageShiftScale.h>
#include <vtkVolumeProperty.h>

class EasyVolumeRender {
public:
    enum DataType{CT,OPT};
    DataType type;
    vtkSmartPointer<vtkVolume> GetVolume();
    EasyVolumeRender(vtkImageData* img,DataType type);
    ~EasyVolumeRender();
private:
    vtkSmartPointer<vtkImageData> image;
    vtkSmartPointer<vtkVolume> volume;
    vtkSmartPointer<vtkVolumeProperty> volumeProperty;
    void InitVolumeProperty(vtkVolumeProperty* volumeProperty);

    void OPT_Property(vtkVolumeProperty *property);

    void CT_Property(vtkVolumeProperty *property);

};


#endif //CPVIEWER_EASYVOLUMERENDER_H
