//
// Created by rayle on 2016/4/4.
//


#include "EasyImageSlice.h"
EasyImageSlice::EasyImageSlice(vtkImageData* image,DataType type) {
    this->image=image;
    this->type=type;
    image->GetExtent(extent);
    image->GetSpacing(spacing);
    image->GetOrigin(origin);
    image->GetScalarRange(ScalarRange);

    colorTable = vtkSmartPointer<vtkLookupTable>::New();

    axialReslice = vtkSmartPointer<vtkImageResliceToColors>::New();
    sagittalReslice = vtkSmartPointer<vtkImageResliceToColors>::New();
    coronalReslice = vtkSmartPointer<vtkImageResliceToColors>::New();

    InitColor();
    InitReslice(axialReslice,SliceDirection::AXIAL);
    InitReslice(sagittalReslice,SliceDirection::SAGITTAL);
    InitReslice(coronalReslice,SliceDirection::CORONAL);

}
EasyImageSlice::~EasyImageSlice() {

}
void EasyImageSlice::InitReslice(vtkImageResliceToColors* reslice,SliceDirection direction) {


    for (int i = 0; i < 3; ++i) {
        center[i] = origin[i] + spacing[i] * 0.5 * (extent[i*2] + extent[i*2+1]);
    }
    reslice->SetInputData(image);
    reslice->SetOutputDimensionality(2);
    reslice->SetInterpolationModeToCubic();

    switch (direction){
        default:
        case AXIAL:
            reslice->SetResliceAxesDirectionCosines(
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1
            );
            break;
        case SAGITTAL:
            reslice->SetResliceAxesDirectionCosines(
                    0, 0, 1,
                    0, 1, 0,
                    1, 0, 0
            );
            break;
        case CORONAL:
            reslice->SetResliceAxesDirectionCosines(
                    1, 0, 0,
                    0, 0, 1,
                    0,-1, 0
            );
            break;
    }
    reslice->SetResliceAxesOrigin(center[0],center[1],center[2]);
    reslice->SetLookupTable(colorTable);
    reslice->SetOutputFormatToRGBA();
}
void EasyImageSlice::InitColor() {
    colorTable->SetTableRange(ScalarRange[0],ScalarRange[1]);
    colorTable->SetValueRange(0.0,1.0);
    colorTable->SetRampToLinear();
    switch(type){
        default:
        case CT:
            colorTable->SetSaturationRange(0.0,0.0);
            break;
        case OPT:
            colorTable->SetTableRange(ScalarRange[1]/10,4*ScalarRange[1]/5);
            colorTable->SetHueRange(0.0,1.0);
            colorTable->SetAlphaRange(0.8,1.0);
            colorTable->SetSaturationRange(1.0,1.0);
            colorTable->SetValueRange(0.5,1.0);
            colorTable->SetBelowRangeColor(1.0,1.0,1.0,0.0);
            colorTable->SetUseBelowRangeColor(1);
            break;
    }
    colorTable->Build();
}
vtkSmartPointer<vtkImageActor> EasyImageSlice::getActor(SliceDirection d){
    vtkSmartPointer<vtkImageActor> actor =
            vtkSmartPointer<vtkImageActor>::New();
    switch(d){
        default:
        case AXIAL:
            actor->GetMapper()->SetInputConnection(axialReslice->GetOutputPort());
            break;
        case SAGITTAL:
            actor->GetMapper()->SetInputConnection(sagittalReslice->GetOutputPort());
            break;
        case CORONAL:
            actor->GetMapper()->SetInputConnection(coronalReslice->GetOutputPort());
            break;
    }
    return actor;
}

void EasyImageSlice::SetResliceAxesOrigin(SliceDirection d, double value) {
    switch (d) {
        case AXIAL:
            axialReslice->SetResliceAxesOrigin(center[0] + offset[0], center[1] + offset[1], value + offset[2]);
            break;
        case CORONAL:
            coronalReslice->SetResliceAxesOrigin(center[0] + offset[0], value + offset[1], center[2] + offset[2]);
            break;
        case SAGITTAL:
            sagittalReslice->SetResliceAxesOrigin(value + offset[0], center[1] + offset[1], center[2] + offset[2]);
            break;
        default:
            break;
    }
}

void EasyImageSlice::SetOffset(double x, double y, double z) {
    offset[0] = x;
    offset[1] = y;
    offset[2] = z;
}