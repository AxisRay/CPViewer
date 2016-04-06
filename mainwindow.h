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

    vtkSmartPointer<vtkRenderer> renderRen;
    vtkSmartPointer<vtkRenderer> axialRen;
    vtkSmartPointer<vtkRenderer> sagittalRen;
    vtkSmartPointer<vtkRenderer> coronalRen;
    EasyImageSlice* ct_slice;
    EasyImageSlice* opt_slice;

    void InitSliceViewer(EasyImageSlice* slice);
    void InitRenderWin(vtkRenderWindow* win);
private slots:
    void on_pbLoadCT_clicked();
    void on_pbLoadOPT_clicked();


};

#endif // MAINWINDOW_H
