#include "QtPainEvent.h"
#include "ui_QtPainEvent.h"

#define VTK_CREATE(type, name) \
  vtkSmartPointer<type> name = vtkSmartPointer<type>::New()

QtPainEvent::QtPainEvent(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::QtPainEvent();
	ui->setupUi(this);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	setWindowState(Qt::WindowMaximized);
}


class vtkResliceCursorCallback : public vtkCommand
{
public:
	static vtkResliceCursorCallback *New()
	{
		return new vtkResliceCursorCallback;
	}

	void Execute(vtkObject *caller, unsigned long ev,
		void *callData)
	{

		if (ev == vtkResliceCursorWidget::WindowLevelEvent ||
			ev == vtkCommand::WindowLevelEvent ||
			ev == vtkResliceCursorWidget::ResliceThicknessChangedEvent)
		{
			// Render everything
			for (int i = 0; i < 3; i++)
			{
				this->RCW[i]->Render();
			}
			this->IPW[0]->GetInteractor()->GetRenderWindow()->Render();
			return;
		}

		vtkImagePlaneWidget* ipw =
			dynamic_cast<vtkImagePlaneWidget*>(caller);
		if (ipw)
		{
			double* wl = static_cast<double*>(callData);

			if (ipw == this->IPW[0])
			{
				this->IPW[1]->SetWindowLevel(wl[0], wl[1], 1);
				this->IPW[2]->SetWindowLevel(wl[0], wl[1], 1);
			}
			else if (ipw == this->IPW[1])
			{
				this->IPW[0]->SetWindowLevel(wl[0], wl[1], 1);
				this->IPW[2]->SetWindowLevel(wl[0], wl[1], 1);
			}
			else if (ipw == this->IPW[2])
			{
				this->IPW[0]->SetWindowLevel(wl[0], wl[1], 1);
				this->IPW[1]->SetWindowLevel(wl[0], wl[1], 1);
			}
		}

		vtkResliceCursorWidget *rcw = dynamic_cast<
			vtkResliceCursorWidget *>(caller);
		if (rcw)
		{
			vtkResliceCursorLineRepresentation *rep = dynamic_cast<
				vtkResliceCursorLineRepresentation *>(rcw->GetRepresentation());
			// Although the return value is not used, we keep the get calls
			// in case they had side-effects
			rep->GetResliceCursorActor()->GetCursorAlgorithm()->GetResliceCursor();
			for (int i = 0; i < 3; i++)
			{
				vtkPlaneSource *ps = static_cast<vtkPlaneSource *>(
					this->IPW[i]->GetPolyDataAlgorithm());
				ps->SetOrigin(this->RCW[i]->GetResliceCursorRepresentation()->
					GetPlaneSource()->GetOrigin());
				ps->SetPoint1(this->RCW[i]->GetResliceCursorRepresentation()->
					GetPlaneSource()->GetPoint1());
				ps->SetPoint2(this->RCW[i]->GetResliceCursorRepresentation()->
					GetPlaneSource()->GetPoint2());

				// If the reslice plane has modified, update it on the 3D widget
				this->IPW[i]->UpdatePlacement();
			}
		}

		// Render everything
		for (int i = 0; i < 3; i++)
		{
			this->RCW[i]->Render();
		}
		this->IPW[0]->GetInteractor()->GetRenderWindow()->Render();
	}

	vtkResliceCursorCallback() {}
	vtkImagePlaneWidget* IPW[3];
	vtkResliceCursorWidget *RCW[3];
};


void QtPainEvent::displypicture3d()
{
	vtkSmartPointer< vtkDICOMImageReader > reader =
		vtkSmartPointer< vtkDICOMImageReader >::New();
	//vtkSmartPointer< vtkResliceImageViewer > riw[3];
	//vtkSmartPointer< vtkImagePlaneWidget > planeWidget[3];
	//vtkSmartPointer< vtkResliceImageViewer > riw[3];
	//vtkSmartPointer< vtkImagePlaneWidget > planeWidget[3];
	//ui->groupBox->setVisible(false);
	ui->qvtkWidget->close();
	ui->qvtkWidget_2->close();
	ui->qvtkWidget_3->close();
	ui->qvtkWidget_4->close();
	QString dirname = QFileDialog::getExistingDirectory(this, "open dir", QDir::currentPath());//打开目录
																							   //QString dirname = QFileDialog::getOpenFileName(this,"open dir",QDir::currentPath());// 打开文件
	reader->SetDirectoryName(dirname.toStdString().c_str());
	reader->Update();
	int imageDims[3];//256-256-20
	reader->GetOutput()->GetDimensions(imageDims);


	for (int i = 0; i < 3; i++)
	{
		riw[i] = vtkSmartPointer<vtkResliceImageViewer>::New();
	}

	ui->qvtkWidget->SetRenderWindow(riw[0]->GetRenderWindow());
	riw[0]->SetupInteractor(
		ui->qvtkWidget_2->GetRenderWindow()->GetInteractor());
	//riw[0]->SetResliceMode(1);

	ui->qvtkWidget_2->SetRenderWindow(riw[1]->GetRenderWindow());
	riw[1]->SetupInteractor(
		ui->qvtkWidget_2->GetRenderWindow()->GetInteractor());
	//riw[1]->SetResliceMode(1);

	ui->qvtkWidget_3->SetRenderWindow(riw[2]->GetRenderWindow());
	riw[2]->SetupInteractor(
		ui->qvtkWidget_3->GetRenderWindow()->GetInteractor());
	//riw[2]->SetResliceMode(1);

	for (int i = 0; i < 3; i++)
	{
		// make them all share the same reslice cursor object.
		vtkResliceCursorLineRepresentation *rep =
			vtkResliceCursorLineRepresentation::SafeDownCast(
				riw[i]->GetResliceCursorWidget()->GetRepresentation());
		//riw[i]->GetResliceCursorWidget()->GetRepresentation());
		riw[i]->SetResliceCursor(riw[0]->GetResliceCursor());

		rep->GetResliceCursorActor()->
			GetCursorAlgorithm()->SetReslicePlaneNormal(i);

		riw[i]->SetInputData(reader->GetOutput());
		riw[i]->SetSliceOrientation(i);
		riw[i]->SetResliceModeToAxisAligned();
	}

	vtkSmartPointer<vtkCellPicker> picker =
		vtkSmartPointer<vtkCellPicker>::New();
	picker->SetTolerance(0.005);

	vtkSmartPointer<vtkProperty> ipwProp =
		vtkSmartPointer<vtkProperty>::New();

	vtkSmartPointer< vtkRenderer > ren =
		vtkSmartPointer< vtkRenderer >::New();

	ui->qvtkWidget_4->GetRenderWindow()->AddRenderer(ren);
	vtkRenderWindowInteractor *iren = ui->qvtkWidget_4->GetInteractor();
	for (int i = 0; i < 3; i++)
	{
		planeWidget[i] = vtkSmartPointer<vtkImagePlaneWidget>::New();
		planeWidget[i]->SetInteractor(iren);
		planeWidget[i]->SetPicker(picker);
		planeWidget[i]->RestrictPlaneToVolumeOn();
		double color[3] = { 0, 0, 0 };
		color[i] = 1;
		planeWidget[i]->GetPlaneProperty()->SetColor(color);

		color[0] /= 4.0;
		color[1] /= 4.0;
		color[2] /= 4.0;
		riw[i]->GetRenderer()->SetBackground(color);

		planeWidget[i]->SetTexturePlaneProperty(ipwProp);
		planeWidget[i]->TextureInterpolateOff();
		planeWidget[i]->SetResliceInterpolateToLinear();
		planeWidget[i]->SetInputConnection(reader->GetOutputPort());
		planeWidget[i]->SetPlaneOrientation(i);
		planeWidget[i]->SetSliceIndex(imageDims[i] / 2);
		planeWidget[i]->DisplayTextOn();
		planeWidget[i]->SetDefaultRenderer(ren);
		planeWidget[i]->SetWindowLevel(1358, -27);
		planeWidget[i]->On();
		planeWidget[i]->InteractionOn();
	}

	vtkSmartPointer<vtkResliceCursorCallback> cbk =
		vtkSmartPointer<vtkResliceCursorCallback>::New();

	for (int i = 0; i < 3; i++)
	{
		cbk->IPW[i] = planeWidget[i];
		cbk->RCW[i] = riw[i]->GetResliceCursorWidget();
		riw[i]->GetResliceCursorWidget()->AddObserver(
			vtkResliceCursorWidget::ResliceAxesChangedEvent, cbk);
		riw[i]->GetResliceCursorWidget()->AddObserver(
			vtkResliceCursorWidget::WindowLevelEvent, cbk);
		riw[i]->GetResliceCursorWidget()->AddObserver(
			vtkResliceCursorWidget::ResliceThicknessChangedEvent, cbk);
		riw[i]->GetResliceCursorWidget()->AddObserver(
			vtkResliceCursorWidget::ResetCursorEvent, cbk);
		riw[i]->GetInteractorStyle()->AddObserver(
			vtkCommand::WindowLevelEvent, cbk);

		// Make them all share the same color map.
		riw[i]->SetLookupTable(riw[0]->GetLookupTable());
		planeWidget[i]->GetColorMap()->SetLookupTable(riw[0]->GetLookupTable());
		//planeWidget[i]->GetColorMap()->SetInput(riw[i]->GetResliceCursorWidget()->GetResliceCursorRepresentation()->GetColorMap()->GetInput());
		planeWidget[i]->SetColorMap(riw[i]->GetResliceCursorWidget()->GetResliceCursorRepresentation()->GetColorMap());

	}

	for (int i = 0; i < 3; i++)
	{
		riw[i]->SetResliceMode(1);
		riw[i]->GetRenderer()->ResetCamera();
		riw[i]->Render();
	}
	ui->qvtkWidget->setVisible(true);
	ui->qvtkWidget_2->setVisible(true);
	ui->qvtkWidget_3->setVisible(true);
	ui->qvtkWidget_4->setVisible(true);
}

void QtPainEvent::openpicture()
{
	//QString filename = QFileDialog::getOpenFileName(this,"open file", "/home","Images (*.png *.xpm *.jpg *.vtk *.stl *.dicom)");
	QString filename = QFileDialog::getOpenFileName(this, "打开", QDir::currentPath(), tr("Image (*.stl *.vtk *.dcm *.exo)"));
	//qDebug() << "filename is :" << filename;
	//QMessageBox::information(this,"info", filename);
	//ui->groupBox->setVisible(false);
	ui->qvtkWidget->close();
	ui->qvtkWidget_2->close();
	ui->qvtkWidget_3->close();
	ui->qvtkWidget_4->close();
	if (filename.contains(".vtk", Qt::CaseSensitive))
	{
		openvtkpicture(filename);
	}
	else if (filename.contains(".stl", Qt::CaseSensitive))
	{
		openstlpicture(filename);
	}
	else if (filename.contains(".dcm", Qt::CaseSensitive))
	{
		opendcmpicture(filename);
	}
	else
		return;
}

void QtPainEvent::openvtkpicture(QString filepathname)
{
	//读取和显示.vtk文件demo start
	vtkSmartPointer<vtkNamedColors> colors =
		vtkSmartPointer<vtkNamedColors>::New();

	// Create the reader for the data.
	std::string filename = filepathname.toStdString();

	std::cout << "Loading " << filename.c_str() << std::endl;
	vtkSmartPointer<vtkUnstructuredGridReader> reader =
		vtkSmartPointer<vtkUnstructuredGridReader>::New();
	reader->SetFileName(filename.c_str());
	reader->Update();

	vtkSmartPointer<vtkExtractEdges> extractEdges =
		vtkSmartPointer<vtkExtractEdges>::New();
	extractEdges->SetInputConnection(reader->GetOutputPort());

	vtkSmartPointer<vtkVariantArray> legendValues =
		vtkSmartPointer<vtkVariantArray>::New();
#if 0
	vtkCellIterator *it = reader->GetOutput()->NewCellIterator();
	for (it->InitTraversal(); !it->IsDoneWithTraversal(); it->GoToNextCell())
	{
		vtkSmartPointer<vtkGenericCell> cell =
			vtkSmartPointer<vtkGenericCell>::New();
		it->GetCell(cell);
		std::string cellName = vtkCellTypes::GetClassNameFromTypeId(cell->GetCellType());
		std::cout << cellName
			<< " NumberOfPoints: " << cell->GetNumberOfPoints()
			<< " CellDimension: " << cell->GetCellDimension()
			<< std::endl;
		legendValues->InsertNextValue(vtkVariant(cellName));
	}
	it->Delete();
#endif
	// Tube the edges

	vtkSmartPointer<vtkTubeFilter> tubes =
		vtkSmartPointer<vtkTubeFilter>::New();
	tubes->SetInputConnection(extractEdges->GetOutputPort());
	tubes->SetRadius(.05);
	tubes->SetNumberOfSides(21);

	vtkSmartPointer<vtkPolyDataMapper> edgeMapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	edgeMapper->SetInputConnection(tubes->GetOutputPort());
	edgeMapper->SetScalarRange(0, 26);

	vtkSmartPointer<vtkActor> edgeActor =
		vtkSmartPointer<vtkActor>::New();
	edgeActor->SetMapper(edgeMapper);
	edgeActor->GetProperty()->SetSpecular(.6);
	edgeActor->GetProperty()->SetSpecularPower(30);
	;

	// Glyph the points
	vtkSmartPointer<vtkSphereSource> sphere =
		vtkSmartPointer<vtkSphereSource>::New();
	sphere->SetPhiResolution(21);
	sphere->SetThetaResolution(21);
	sphere->SetRadius(.08);

	vtkSmartPointer<vtkGlyph3DMapper> pointMapper =
		vtkSmartPointer<vtkGlyph3DMapper>::New();
	pointMapper->SetInputConnection(reader->GetOutputPort());
	pointMapper->SetSourceConnection(sphere->GetOutputPort());
	pointMapper->ScalingOff();
	pointMapper->ScalarVisibilityOff();

	vtkSmartPointer<vtkActor> pointActor =
		vtkSmartPointer<vtkActor>::New();
	pointActor->SetMapper(pointMapper);
	pointActor->GetProperty()->SetDiffuseColor(colors->GetColor3d("Banana").GetData());
	pointActor->GetProperty()->SetSpecular(.6);
	pointActor->GetProperty()->SetSpecularColor(1.0, 1.0, 1.0);
	pointActor->GetProperty()->SetSpecularPower(100);

	// Label the points
	vtkSmartPointer<vtkLabeledDataMapper> labelMapper =
		vtkSmartPointer<vtkLabeledDataMapper>::New();
	labelMapper->SetInputConnection(reader->GetOutputPort());
	vtkSmartPointer<vtkActor2D> labelActor =
		vtkSmartPointer<vtkActor2D>::New();
	labelActor->SetMapper(labelMapper);

	// The geometry
	vtkSmartPointer<vtkShrinkFilter> geometryShrink =
		vtkSmartPointer<vtkShrinkFilter>::New();
	geometryShrink->SetInputConnection(reader->GetOutputPort());
	geometryShrink->SetShrinkFactor(.8);



	vtkSmartPointer<vtkDataSetMapper> geometryMapper =
		vtkSmartPointer<vtkDataSetMapper>::New();
	geometryMapper->SetInputConnection(geometryShrink->GetOutputPort());
	geometryMapper->SetScalarModeToUseCellData();
	geometryMapper->SetScalarRange(0, 11);

	vtkSmartPointer<vtkActor> geometryActor =
		vtkSmartPointer<vtkActor>::New();
	geometryActor->SetMapper(geometryMapper);
	geometryActor->GetProperty()->SetLineWidth(3);
	geometryActor->GetProperty()->EdgeVisibilityOn();
	geometryActor->GetProperty()->SetEdgeColor(0, 0, 0);

	vtkSmartPointer<vtkRenderer> renderer =
		vtkSmartPointer<vtkRenderer>::New();
	vtkSmartPointer<vtkRenderWindow> renderWindow =
		vtkSmartPointer<vtkRenderWindow>::New();
	renderWindow->AddRenderer(renderer);
	//vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
	//	vtkSmartPointer<vtkRenderWindowInteractor>::New();
	//renderWindowInteractor->SetRenderWindow(renderWindow);

	renderer->AddActor(geometryActor);
	renderer->SetBackground(.3, .6, .3); // Background color green
	renderWindow->SetSize(640, 480);
	//renderWindow->Render(); //如果将这条注释打开，将会先弹出另外一个窗口然后再弹出qvtkWidget窗口
	//renderWindow->GlobalWarningDisplayOff();
	//renderWindow->Render();
	//renderWindowInteractor->Start();
	ui->qvtkWidget->SetRenderWindow(renderWindow);
	ui->qvtkWidget->setVisible(true);
	ui->qvtkWidget_2->setVisible(false);
	ui->qvtkWidget_3->setVisible(false);
	ui->qvtkWidget_4->setVisible(false);
	return;
}

/*
打开stl文件参考链接
//https://www.cnblogs.com/21207-iHome/p/6429714.html
//https://blog.csdn.net/yuyangyg/article/details/78521321 读取3D图像
*/
void QtPainEvent::openstlpicture(QString filepathname)
{
	std::string inputFilename = filepathname.toStdString();

	vtkSmartPointer<vtkSTLReader> reader =
		vtkSmartPointer<vtkSTLReader>::New();
	reader->SetFileName(inputFilename.c_str());
	reader->Update();

	// Visualize
	vtkSmartPointer<vtkPolyDataMapper> mapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper->SetInputConnection(reader->GetOutputPort());

	vtkSmartPointer<vtkActor> actor =
		vtkSmartPointer<vtkActor>::New();
	actor->SetMapper(mapper);

	vtkSmartPointer<vtkRenderer> renderer =
		vtkSmartPointer<vtkRenderer>::New();
	vtkSmartPointer<vtkRenderWindow> renderWindow =
		vtkSmartPointer<vtkRenderWindow>::New();
	renderWindow->AddRenderer(renderer);
	//vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
	//	vtkSmartPointer<vtkRenderWindowInteractor>::New();
	//renderWindowInteractor->SetRenderWindow(renderWindow);

	renderer->AddActor(actor);
	renderer->SetBackground(.3, .6, .3); // Background color green

										 //renderWindow->Render();
										 //renderWindowInteractor->Start();
	ui->qvtkWidget->SetRenderWindow(renderWindow);
	ui->qvtkWidget->setVisible(true);
	return;
}

void QtPainEvent::opendcmpicture(QString filepathname)
{
	vtkSmartPointer<vtkDICOMImageReader> reader = vtkSmartPointer<vtkDICOMImageReader>::New();
	//reader->SetFileName("E:\\IM12");//Benchmark_tube2.exo
	std::string filename = filepathname.toStdString();
	const char *file = filename.c_str();
	reader->SetFileName(file);
	//reader->SetFileName("E:\\benchmark_norm_00percentoff_imp2.vtk");

	reader->Update();


	vtkSmartPointer<vtkImageActor> actor = vtkSmartPointer<vtkImageActor>::New();
	actor->GetMapper()->SetInputData(reader->GetOutput());
	//actor->SetInputData(reader->GetOutput());
	actor->Update();

	vtkSmartPointer<vtkRenderer> ren = vtkSmartPointer<vtkRenderer>::New();
	ren->AddActor(actor);

	ui->qvtkWidget->GetRenderWindow()->AddRenderer(ren);
	ui->qvtkWidget->setVisible(true);
	ui->qvtkWidget_2->setVisible(false);
	ui->qvtkWidget_3->setVisible(false);
	ui->qvtkWidget_4->setVisible(false);
	return;
}

void QtPainEvent::openexopicture(QString filepathname)
{
	QMessageBox::information(this, "消息", "不能够打开.exo文件！");
	return;
}

void QtPainEvent::openotherpicture(QString filepathname)
{
	vtkSmartPointer<vtkDICOMImageReader> reader = vtkSmartPointer<vtkDICOMImageReader>::New();
	//reader->SetFileName("E:\\IM12");//Benchmark_tube2.exo
	reader->SetFileName("E:\\benchmark_norm_00percentoff_imp2.vtk");

	reader->Update();


	vtkSmartPointer<vtkImageActor> actor = vtkSmartPointer<vtkImageActor>::New();
	actor->GetMapper()->SetInputData(reader->GetOutput());
	//actor->SetInputData(reader->GetOutput());
	actor->Update();

	vtkSmartPointer<vtkRenderer> ren = vtkSmartPointer<vtkRenderer>::New();
	ren->AddActor(actor);

	ui->qvtkWidget->GetRenderWindow()->AddRenderer(ren);
	ui->qvtkWidget->setVisible(true);
	ui->qvtkWidget_2->setVisible(false);
	ui->qvtkWidget_3->setVisible(false);
	ui->qvtkWidget_4->setVisible(false);
	return;
}

QtPainEvent::~QtPainEvent()
{
	delete ui;
}
