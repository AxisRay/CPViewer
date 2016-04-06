
#include <QtWidgets/qfiledialog.h>
#include <vtkInteractorStyleImage.h>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow) {
    ui->setupUi(this);
    //connect(ui->pbLoadCT,SIGNAL(clicked()),this,SLOT(on_pbLoadCT_clicked()));
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

    renderRen = vtkSmartPointer<vtkRenderer>::New();
    axialRen = vtkSmartPointer<vtkRenderer>::New();
    sagittalRen = vtkSmartPointer<vtkRenderer>::New();
    coronalRen = vtkSmartPointer<vtkRenderer>::New();

    renderWin->AddRenderer(renderRen);
    axialWin->AddRenderer(axialRen);
    sagittalWin->AddRenderer(sagittalRen);
    coronalWin->AddRenderer(coronalRen);
    InitRenderWin(axialWin);
    InitRenderWin(sagittalWin);
    InitRenderWin(coronalWin);

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
}