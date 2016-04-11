#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <vtkRenderWindow.h>
#include <vtkMetaImageReader.h>
#include <vtkSmartPointer.h>
#include <vtkImageReslice.h>
#include <vtkImageData.h>
#include <vtkRenderer.h>
#include <QMainWindow>
#include "EasyImageSlice.h"
#include "EasyVolumeRender.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void run();
private:
    Ui::MainWindow *ui;
    vtkSmartPointer<vtkMetaImageReader> ct_reader;
    vtkSmartPointer<vtkMetaImageReader> opt_reader;
    vtkSmartPointer<vtkRenderWindow> renderWin;
    vtkSmartPointer<vtkRenderWindow> axialWin;
    vtkSmartPointer<vtkRenderWindow> sagittalWin;
    vtkSmartPointer<vtkRenderWindow> coronalWin;

    vtkSmartPointer<vtkRenderer> ctRen;
    vtkSmartPointer<vtkRenderer> optRen;

    vtkSmartPointer<vtkRenderer> axialRen;
    vtkSmartPointer<vtkRenderer> sagittalRen;
    vtkSmartPointer<vtkRenderer> coronalRen;
    EasyImageSlice* ct_slice;
    EasyImageSlice* opt_slice;
    EasyVolumeRender* ct_render;
    EasyVolumeRender* opt_render;

    void InitSliceViewer(EasyImageSlice* slice);
    void InitRenderWin(vtkRenderWindow* win);
    void InitVolumeRender();
    void InitSlider(int *extent);
private slots:
    void on_pbLoadCT_clicked();
    void on_pbLoadOPT_clicked();

    void UpdateSlice();

    void on_hsAxisX_valueChanged(int value);

    void on_hsAxisY_valueChanged(int value);

    void on_hsAxisZ_valueChanged(int value);
};

#endif // MAINWINDOW_H
