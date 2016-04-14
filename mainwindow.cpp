
#include <QtWidgets/qfiledialog.h>
#include <vtkInteractorStyleImage.h>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow) {
    ui->setupUi(this);
    //connect(ui->pbLoadCT,SIGNAL(clicked()),this,SLOT(on_pbLoadCT_clicked()));
    connect(ui->hsAxisX, SIGNAL(valueChanged(int)), this, SLOT(ValueChanged(int)));
    connect(ui->hsAxisY, SIGNAL(valueChanged(int)), this, SLOT(ValueChanged(int)));
    connect(ui->hsAxisZ, SIGNAL(valueChanged(int)), this, SLOT(ValueChanged(int)));

    connect(ui->dsOffsetX, SIGNAL(valueChanged(int)), this, SLOT(OffsetChangedX(int)));
    connect(ui->dsOffsetY, SIGNAL(valueChanged(int)), this, SLOT(OffsetChangedY(int)));
    connect(ui->dsOffsetZ, SIGNAL(valueChanged(int)), this, SLOT(OffsetChangedZ(int)));

    connect(ui->hsOffsetX, SIGNAL(valueChanged(int)), this, SLOT(OffsetChangedX(int)));
    connect(ui->hsOffsetY, SIGNAL(valueChanged(int)), this, SLOT(OffsetChangedY(int)));
    connect(ui->hsOffsetZ, SIGNAL(valueChanged(int)), this, SLOT(OffsetChangedZ(int)));


    ct_slice = NULL;
    opt_slice = NULL;
    ct_reader = vtkSmartPointer<vtkMetaImageReader>::New();
    opt_reader = vtkSmartPointer<vtkMetaImageReader>::New();
    renderWin = vtkSmartPointer<vtkRenderWindow>::New();
    axialWin = vtkSmartPointer<vtkRenderWindow>::New();
    sagittalWin = vtkSmartPointer<vtkRenderWindow>::New();
    coronalWin = vtkSmartPointer<vtkRenderWindow>::New();
    ui->qvtkRenderView->SetRenderWindow(renderWin);
    ui->qvtkAxialView->SetRenderWindow(axialWin);
    ui->qvtkSagittalView->SetRenderWindow(sagittalWin);
    ui->qvtkCoronalView->SetRenderWindow(coronalWin);

    axialRen = vtkSmartPointer<vtkRenderer>::New();
    sagittalRen = vtkSmartPointer<vtkRenderer>::New();
    coronalRen = vtkSmartPointer<vtkRenderer>::New();

    axialWin->AddRenderer(axialRen);
    sagittalWin->AddRenderer(sagittalRen);
    coronalWin->AddRenderer(coronalRen);
    InitRenderWin(axialWin);
    InitRenderWin(sagittalWin);
    InitRenderWin(coronalWin);
    InitVolumeRender();

//    vtkSmartPointer<vtkInteractorStyleImage> imageStyle1 =
//            vtkSmartPointer<vtkInteractorStyleImage>::New();
//    vtkSmartPointer<vtkInteractorStyleImage> imageStyle2 =
//            vtkSmartPointer<vtkInteractorStyleImage>::New();
//    vtkSmartPointer<vtkInteractorStyleImage> imageStyle3 =
//            vtkSmartPointer<vtkInteractorStyleImage>::New();
//    vtkSmartPointer<vtkRenderWindowInteractor> interactor1 =
//            vtkSmartPointer<vtkRenderWindowInteractor>::New();
//    vtkSmartPointer<vtkRenderWindowInteractor> interactor2 =
//            vtkSmartPointer<vtkRenderWindowInteractor>::New();
//    vtkSmartPointer<vtkRenderWindowInteractor> interactor3 =
//            vtkSmartPointer<vtkRenderWindowInteractor>::New();
//    interactor1->SetInteractorStyle(imageStyle1);
//    interactor2->SetInteractorStyle(imageStyle2);
//    interactor3->SetInteractorStyle(imageStyle3);
//    axialWin->SetInteractor(interactor1);
//    sagittalWin->SetInteractor(interactor2);
//    coronalWin->SetInteractor(interactor3);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::run() {

}

void MainWindow::on_pbLoadCT_clicked() {
    QString filename = QFileDialog::getOpenFileName(this,"Open CT_Data File",".","MatedataFiles(*.mhd)");
    if(filename.isEmpty())return;
    ui->tbx_CT->setText(filename);
    ct_reader->SetFileName(filename.toLocal8Bit().data());
    ct_reader->Update();
    vtkSmartPointer<vtkImageData> ct_image =
            ct_reader->GetOutput();
    ct_slice=new EasyImageSlice(ct_image,EasyImageSlice::CT);
    InitSliceViewer(ct_slice);

    ct_render=new EasyVolumeRender(ct_image,EasyVolumeRender::CT);
    ctRen->AddViewProp(ct_render->GetVolume());
    ctRen->ResetCamera();
    renderWin->Render();

    InitSlider(ct_slice->extent);
}
void MainWindow::InitRenderWin(vtkRenderWindow* win){

    vtkSmartPointer<vtkInteractorStyleImage> imageStyle =
            vtkSmartPointer<vtkInteractorStyleImage>::New();
    vtkSmartPointer<vtkRenderWindowInteractor> interactor =
            vtkSmartPointer<vtkRenderWindowInteractor>::New();
    interactor->SetInteractorStyle(imageStyle);
    win->SetInteractor(interactor);
    win->Render();
}
void MainWindow::InitSliceViewer(EasyImageSlice* slice){
    axialRen->AddActor(slice->getActor(EasyImageSlice::AXIAL));
    axialWin->Render();
    sagittalRen->AddActor(slice->getActor(EasyImageSlice::SAGITTAL));
    sagittalWin->Render();
    coronalRen->AddActor(slice->getActor(EasyImageSlice::CORONAL));
    coronalWin->Render();


//    vtkSmartPointer<vtkRenderer> renderer =
//            vtkSmartPointer<vtkRenderer>::New();
//    renderer->AddActor(slice->getActor(EasyImageSlice::AXIAL));
//    vtkSmartPointer<vtkRenderWindow> window =
//            vtkSmartPointer<vtkRenderWindow>::New();
//    window->AddRenderer(renderer);
//
//    // Set up the interaction
//    vtkSmartPointer<vtkInteractorStyleImage> imageStyle =
//            vtkSmartPointer<vtkInteractorStyleImage>::New();
//    vtkSmartPointer<vtkRenderWindowInteractor> interactor =
//            vtkSmartPointer<vtkRenderWindowInteractor>::New();
//    interactor->SetInteractorStyle(imageStyle);
//    window->SetInteractor(interactor);
//    window->Render();
//    interactor->Start();
}
void MainWindow::on_pbLoadOPT_clicked(){
    QString filename = QFileDialog::getOpenFileName(this,"Open OPT_Data File",".","MatedataFiles(*.mhd)");
    if(filename.isEmpty())return;
    ui->tbx_OPT->setText(filename);
    opt_reader->SetFileName(filename.toLocal8Bit().data());
    opt_reader->Update();
    vtkSmartPointer<vtkImageData> opt_image =
            opt_reader->GetOutput();
    opt_slice=new EasyImageSlice(opt_image,EasyImageSlice::OPT);
    InitSliceViewer(opt_slice);

    opt_render=new EasyVolumeRender(opt_image,EasyVolumeRender::OPT);
    optRen->AddViewProp(opt_render->GetVolume());
    optRen->ResetCamera();
    renderWin->Render();
    InitSlider(opt_slice->extent);
    InitOffsetSlider(opt_slice->extent);
}

void MainWindow::InitVolumeRender() {
    renderWin->SetNumberOfLayers(2);
    ctRen = vtkSmartPointer<vtkRenderer>::New();
    optRen = vtkSmartPointer<vtkRenderer>::New();
    ctRen->SetLayer(0);
    optRen->SetLayer(1);
    ctRen->SetActiveCamera(optRen->GetActiveCamera());
    renderWin->AddRenderer(ctRen);
    renderWin->AddRenderer(optRen);
    renderWin->Render();
}

void MainWindow::InitSlider(int* extent){
    ui->hsAxisX->setRange(extent[0], extent[1]);
    ui->hsAxisX->setValue(extent[1] / 2);
    ui->hsAxisX->setEnabled(true);
    ui->hsAxisY->setRange(extent[2], extent[3]);
    ui->hsAxisY->setValue(extent[3] / 2);
    ui->hsAxisY->setEnabled(true);
    ui->hsAxisZ->setRange(extent[4], extent[5]);
    ui->hsAxisZ->setValue(extent[5] / 2);
    ui->hsAxisZ->setEnabled(true);

}
void MainWindow::UpdateSlice(){
    sagittalWin->Render();
    coronalWin->Render();
    axialWin->Render();
}

void MainWindow::opt_offset() {
    opt_slice->SetOffset(ui->dsOffsetX->value(),
                         ui->dsOffsetY->value(),
                         ui->dsOffsetZ->value());
    ValueChanged(0);
}

void MainWindow::ValueChanged(int value) {
    if (ct_slice != NULL) {
        ct_slice->SetResliceAxesOrigin(EasyImageSlice::SAGITTAL, ui->hsAxisX->value());
        ct_slice->SetResliceAxesOrigin(EasyImageSlice::CORONAL, ui->hsAxisY->value());
        ct_slice->SetResliceAxesOrigin(EasyImageSlice::AXIAL, ui->hsAxisZ->value());
    }
    if (opt_slice != NULL) {
        opt_slice->SetResliceAxesOrigin(EasyImageSlice::SAGITTAL, ui->hsAxisX->value());
        opt_slice->SetResliceAxesOrigin(EasyImageSlice::CORONAL, ui->hsAxisY->value());
        opt_slice->SetResliceAxesOrigin(EasyImageSlice::AXIAL, ui->hsAxisZ->value());
    }
    UpdateSlice();
}

void MainWindow::InitOffsetSlider(int *extent) {
    ui->dsOffsetX->setRange(-extent[1], extent[1]);
    ui->dsOffsetY->setRange(-extent[3], extent[3]);
    ui->dsOffsetZ->setRange(-extent[5], extent[5]);
    ui->hsOffsetX->setRange(-extent[1], extent[1]);
    ui->hsOffsetY->setRange(-extent[3], extent[3]);
    ui->hsOffsetZ->setRange(-extent[5], extent[5]);
    ui->dsOffsetX->setEnabled(true);
    ui->dsOffsetY->setEnabled(true);
    ui->dsOffsetZ->setEnabled(true);
    ui->hsOffsetX->setEnabled(true);
    ui->hsOffsetY->setEnabled(true);
    ui->hsOffsetZ->setEnabled(true);
}


void MainWindow::OffsetChangedX(int value) {
    ui->hsOffsetX->setValue(value);
    ui->dsOffsetX->setValue(value);
    opt_offset();
}

void MainWindow::OffsetChangedY(int value) {
    ui->hsOffsetY->setValue(value);
    ui->dsOffsetY->setValue(value);
    opt_offset();
}

void MainWindow::OffsetChangedZ(int value) {
    ui->hsOffsetZ->setValue(value);
    ui->dsOffsetZ->setValue(value);
    opt_offset();
}
