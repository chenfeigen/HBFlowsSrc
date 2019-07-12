#pragma once
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
#include <QTextCodec>
#include <QDialog>
#include <QPainter>
#include <QPixmap>
#include <QDateTime>
#include "vtkAutoInit.h"
VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);
VTK_MODULE_INIT(vtkRenderingFreeType);

#include <vtkDataObjectToTable.h>
#include <vtkElevationFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkQtTableView.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkVectorText.h>
#include "vtkImageData.h"
#include "vtkDICOMImageReader.h"
#include "vtkImageActor.h"
#include "vtkRenderer.h"
#include "vtkImageMapper3D.h"
#include "vtkPNGReader.h"
#include "vtkSTLReader.h"
#include <vtkVersion.h>
#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkSphereSource.h>
#include <vtkMetaImageWriter.h>
#include <vtkPolyDataToImageStencil.h>
#include <vtkImageStencil.h>
#include <vtkPointData.h>
#include <vtkCutter.h>
#include <vtkPlane.h>
#include <vtkStripper.h>
#include <vtkLinearExtrusionFilter.h>
#include <vtkXMLPolyDataWriter.h>
#include <vtkMetaImageReader.h>
#include <vtkInteractorStyleImage.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkPolyDataReader.h>
#include <vtkStructuredGridReader.h>
#include <qpushbutton.h>
#include <vtkUnstructuredGridReader.h>
#include <vtkUnstructuredGrid.h>
#include <vtkGenericCell.h>
#include <vtkExtractEdges.h>
#include <vtkTubeFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkGlyph3DMapper.h>
#include <vtkSphereSource.h>
#include <vtkPolyData.h>
#include <vtkTextMapper.h>
#include <vtkShrinkFilter.h>
#include <vtkCategoryLegend.h>
#include <vtkBrush.h>
#include <vtkCellData.h>
#include <vtkColor.h>
#include <vtkContextScene.h>
#include <vtkContextTransform.h>
#include <vtkContextView.h>
#include <vtkLookupTable.h>
#include <vtkScalarsToColors.h>
#include <vtkVariant.h>
#include <vtkVariantArray.h>
#include <vtkActor.h>
#include <vtkActor2D.h>
#include <vtkCamera.h>
#include <vtkDataSetMapper.h>
#include <vtkNamedColors.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkCellIterator.h>
#include <vtkCellTypes.h>
#include <vtkLabeledDataMapper.h>
#include <vtkExodusIIReader.h>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QDebug>
#include <QAction>
#include <QMessageBox>
#include <qt>
#include <QMenu>
#include "vtkResliceImageViewer.h"
#include "vtkResliceCursorLineRepresentation.h"

#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include "vtkResliceCursorLineRepresentation.h"
#include "vtkResliceCursorThickLineRepresentation.h"
#include "vtkResliceCursorWidget.h"
#include "vtkResliceCursorActor.h"
#include "vtkResliceCursorPolyDataAlgorithm.h"
#include "vtkResliceCursor.h"
#include "vtkDICOMImageReader.h"
#include "vtkCellPicker.h"
#include "vtkProperty.h"
#include "vtkPlane.h"
#include "vtkImageData.h"
#include "vtkCommand.h"
#include "vtkPlaneSource.h"
#include "vtkLookupTable.h"
#include "vtkImageMapToWindowLevelColors.h"
#include "vtkInteractorStyleImage.h"
#include "vtkImageSlabReslice.h"
#include "vtkBoundedPlanePointPlacer.h"
#include "vtkDistanceWidget.h"
#include "vtkDistanceRepresentation.h"
#include "vtkHandleRepresentation.h"
#include "vtkResliceImageViewerMeasurements.h"
#include "vtkDistanceRepresentation2D.h"
#include "vtkPointHandleRepresentation3D.h"
#include "vtkPointHandleRepresentation2D.h"

#include<vtkRenderer.h>
#include<vtkRenderWindow.h>
#include<vtkRenderWindowInteractor.h>
#include<vtkDICOMImageReader.h>
#include<vtkContourFilter.h>
#include<vtkPolyDataNormals.h>
#include<vtkPolyDataMapper.h>
#include<vtkActor.h>
#include<vtkOutlineFilter.h>
#include<vtkCamera.h>
#include<vtkProperty.h>
#include<vtkTextProperty.h>
#include <QProcess>
#include <QWindow.h>
#include <QAction>
#include <QFileInfo>
#include "vtkImagePlaneWidget.h"
#include "vtkDistanceWidget.h"
#include "vtkResliceImageViewer.h"
namespace Ui { class QtVtkDialog; };

class QtVtkDialog : public QDialog
{
	Q_OBJECT

public:
	QtVtkDialog(QWidget *parent = Q_NULLPTR);
	~QtVtkDialog();

	void displyPicture3d();
	void openpicture();
	void openvtkpicture(QString filepathname);
	void openstlpicture(QString filepathname);
	void opendcmpicture(QString filepathname);
	void openexopicture(QString filepathname);
	void openotherpicture(QString filepathname);

protected:
	vtkSmartPointer< vtkResliceImageViewer > riw[3];
	vtkSmartPointer< vtkImagePlaneWidget > planeWidget[3];
	//vtkSmartPointer< vtkDistanceWidget > DistanceWidget[3];
	//vtkSmartPointer< vtkResliceImageViewerMeasurements > ResliceMeasurements;

private:
	Ui::QtVtkDialog *ui;
};
