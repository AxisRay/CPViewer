//
// Created by rayle on 2016/4/9.
//

#include <vtkPiecewiseFunction.h>
#include <vtkColorTransferFunction.h>
#include <vtkGPUVolumeRayCastMapper.h>
#include "EasyVolumeRender.h"
EasyVolumeRender::EasyVolumeRender(vtkImageData *img, EasyVolumeRender::DataType type) {
    this->image=img;
    this->type=type;
    volume = vtkSmartPointer<vtkVolume>::New();
    volumeProperty = vtkSmartPointer<vtkVolumeProperty>::New();
}
EasyVolumeRender::~EasyVolumeRender() {

}
vtkSmartPointer<vtkVolume> EasyVolumeRender::GetVolume(){
    vtkSmartPointer<vtkImageShiftScale> shiftScaleFilter =
            vtkSmartPointer<vtkImageShiftScale>::New();
    shiftScaleFilter->SetOutputScalarTypeToUnsignedChar();
    shiftScaleFilter->SetInputData(image);
    shiftScaleFilter->SetScale(255.0 / image->GetScalarRange()[1]);
    shiftScaleFilter->Update();

    vtkSmartPointer<vtkGPUVolumeRayCastMapper> volumeMapper =
            vtkSmartPointer<vtkGPUVolumeRayCastMapper>::New();
    volumeMapper->SetInputConnection(shiftScaleFilter->GetOutputPort());
    volume->SetMapper(volumeMapper);
    InitVolumeProperty(volumeProperty);
    volume->SetProperty(volumeProperty);
    return volume;
}
void EasyVolumeRender::CT_Property(vtkVolumeProperty* property) {
    vtkSmartPointer<vtkPiecewiseFunction> compositeOpacity =
            vtkSmartPointer<vtkPiecewiseFunction>::New();
    compositeOpacity->AddPoint(0.0,  0.0);
    //compositeOpacity->AddPoint(36.0,  0.1);
    //compositeOpacity->AddPoint(72.0,  0.1);
    compositeOpacity->AddPoint(108.0, 0.1);
    //compositeOpacity->AddPoint(144.0, 0.1);
    compositeOpacity->AddPoint(180.0, 0.1);
    //compositeOpacity->AddPoint(216.0, 0.1);
    compositeOpacity->AddPoint(255.0, 0);
    property->SetScalarOpacity(compositeOpacity); // composite first.

    vtkSmartPointer<vtkColorTransferFunction> color =
            vtkSmartPointer<vtkColorTransferFunction>::New();
    color->AddRGBPoint(0.0,  1.0, 1.0, 1.0);
    color->AddRGBPoint(255.0, 1.0, 1.0, 1.0);
    property->SetColor(color);
}
void EasyVolumeRender::OPT_Property(vtkVolumeProperty* property){
    vtkSmartPointer<vtkPiecewiseFunction> compositeOpacity =
            vtkSmartPointer<vtkPiecewiseFunction>::New();
    compositeOpacity->AddPoint(0.0,  0.0);
    compositeOpacity->AddPoint(36.0,  0.125);
    compositeOpacity->AddPoint(72.0,  0.25);
    compositeOpacity->AddPoint(108.0, 0.375);
    compositeOpacity->AddPoint(144.0, 0.5);
    compositeOpacity->AddPoint(180.0, 0.625);
    compositeOpacity->AddPoint(216.0, 0.75);
    compositeOpacity->AddPoint(255.0, 0.875);
    property->SetScalarOpacity(compositeOpacity); // composite first.

    vtkSmartPointer<vtkColorTransferFunction> color =
            vtkSmartPointer<vtkColorTransferFunction>::New();
    color->AddRGBPoint(255.0,  0.0, 0.0, 0.0);
    color->AddRGBPoint(216.0, 1.0, 0.0, 0.0);
    color->AddRGBPoint(180.0, 1.0, 1.0, 0.0);
    color->AddRGBPoint(144.0, 0.0, 1.0, 0.0);
    color->AddRGBPoint(108.0, 0.0, 1.0, 1.0);
    color->AddRGBPoint(72.0, 0.0, 0.0, 1.0);
    color->AddRGBPoint(36.0, 1.0, 0.0, 1.0);
    color->AddRGBPoint(0.0, 1.0, 1.0, 1.0);
    property->SetColor(color);
}
void EasyVolumeRender::InitVolumeProperty(vtkVolumeProperty* volumeProperty){
    volumeProperty->ShadeOff();
    volumeProperty->SetInterpolationType(VTK_LINEAR_INTERPOLATION);
    switch (type){
        default:
        case CT:
            CT_Property(volumeProperty);
            break;
        case OPT:
            OPT_Property(volumeProperty);
            break;
    }
}

