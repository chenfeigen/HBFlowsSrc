#include "HtmlCreatedWord.h"

HtmlCreatedWord::HtmlCreatedWord(QWidget *parent)
	: QDialog(parent)
{
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	CreatePdfByPixmap();
	CreatePdfByText();
	//通过html生成word文档
	QDateTime time1 = QDateTime::currentDateTime();
	QString docname = "log/my_testword.doc";
	QString html = SaveHtmlToWord();
	QFile outFile(docname);
	outFile.open(QIODevice::WriteOnly | QIODevice::Append);
	QTextStream ts(&outFile);
	ts << html << endl;
	QDateTime time2 = QDateTime::currentDateTime();
	qDebug() << "doc time1:" << time1;
	qDebug() << "doc time2:" << time2;
	QMessageBox::about(this,"info","Created word success !");
}

HtmlCreatedWord::~HtmlCreatedWord()
{
}

//将图片生成为pdf
void HtmlCreatedWord::CreatePdfByPixmap()
{
	QPrinter printer_pixmap(QPrinter::HighResolution);
	printer_pixmap.setPageSize(QPrinter::A4);  //设置纸张大小为A4
	printer_pixmap.setOutputFormat(QPrinter::PdfFormat);  //设置输出格式为pdf
	printer_pixmap.setOutputFileName("E:\\test_pixmap.pdf");   //设置输出路径
															   //QPixmap pixmap = QPixmap::grabWidget(main_widget, main_widget->rect());  //获取界面的图片
	QPixmap pixmap("E:\\picture2.png");
	QPainter painter_pixmap;
	painter_pixmap.begin(&printer_pixmap);
	QRect rect = painter_pixmap.viewport();
	int multiple = rect.width() / pixmap.width();
	painter_pixmap.scale(multiple, multiple); //将图像(所有要画的东西)在pdf上放大multiple-1倍
	painter_pixmap.drawPixmap(0, 0, pixmap);  //画图
	painter_pixmap.end();
}

void HtmlCreatedWord::CreatePdfByText()
{
	QPrinter printer_text;
	printer_text.setOutputFormat(QPrinter::PdfFormat);
	printer_text.setOutputFileName("E:\\test_text.pdf");
	QPainter painter_text;
	painter_text.begin(&printer_text);

	QDateTime current_date_time = QDateTime::currentDateTime();
	QString current_date = current_date_time.toString("yyyy-MM-dd hh:mm:ss ddd");

	QPoint point(10, 10);
	for (int i = 1; i <= 5; i++)
	{
		QString message = QString("%1          %2          %3").arg(QString::number(i)).arg(current_date).arg(QStringLiteral("北京"));
		int y = point.y();
		point.setY(y + 20);
		painter_text.drawText(point, message);
		message.clear();
	}
	printer_text.newPage();  //生成新的一页，可继续插入
	for (int i = 1; i <= 5; i++)
	{
		QString message = QString("%1          %2          %3").arg(QString::number(i)).arg(current_date).arg(QStringLiteral("北京"));
		int y = point.y();
		point.setY(y + 20);
		painter_text.drawText(point, message);
		message.clear();
	}
	painter_text.end();
}


#if 1
// 组合html生成word
QString HtmlCreatedWord::SaveHtmlToWord()
{
	QString html = "";
	html += "<html>";
	html += "<head>";
	html += "<img src=\"E:/wpicture/picture1.png\" alt=\"picture\" width=\"550\" height=\"100\">";
	html += "<head>";
	html += "<body>";
	html += "<p>";
	html += "Doe, John";
	html += "</p>";
	html += "<p>";
	html += "<code>&nbsp &nbsp Patient ID 10-028-KSH <br/> &nbsp &nbsp CT Study Date 06/20/2018</code>";
	html += "<br/>";
	html += "<code>&nbsp &nbsp Birth Date 07/24/1961 <br/> &nbsp &nbsp Referring Physician Dr. Jim Cardiologist</code>";
	html += "<br/>";
	html += "<code>&nbsp &nbsp HeartFlow ID ANYT-180620-JKD7 <br/> &nbsp &nbsp Institution Anytown Cardiology</code>";
	html += "</p>";
	html += "<img src=\"E:/wpicture/picture2.png\" alt=\"picture\" width=\"550\" height=\"100\">";
	html += "</p>";
	html += "</p>";
	html += "<img src=\"E:/wpicture/picture3.png\" alt=\"picture\" width=\"550\" height=\"150\">";
	html += "</p>";
	html += "</p>";
	html += "<img src=\"E:/wpicture/picture4.png\" alt=\"picture\" width=\"550\" height=\"300\">";
	html += "</p>";
	html += "<p>";
	html += "<code>FFRCT values are specified distal to modeled stenoses > 30%.</p>";
	html += "</p>";
	html += "</p>";
	html += "<img src=\"E:/wpicture/picture5.png\" alt=\"picture\" align=\"middle\"  width=\"200\" height=\"50\">";
	html += "</p>";
	html += "<p>";
	html += "Doe, John";
	html += "</p>";
	html += "<p>";
	html += "<code>&nbsp &nbsp Patient ID 10-028-KSH <br/> &nbsp &nbsp CT Study Date 06/20/2018<\code>";
	html += "<br/>";
	html += "<code>&nbsp &nbsp Birth Date 07/24/1961 <br/> &nbsp &nbsp Referring Physician Dr. Jim Cardiologist</code>";
	html += "<br/>";
	html += "<code>&nbsp &nbsp HeartFlow ID ANYT-180620-JKD7 <br/> &nbsp &nbsp Institution Anytown Cardiology</code>";
	html += "</p>";
	html += "<hr>";
	html += "<img src=\"E:/wpicture/picture6.png\" alt=\"picture\" width=\"250\" height=\"300\">";
	html += "<img src=\"E:/wpicture/picture7.png\" alt=\"picture\" width=\"250\" height=\"300\">";
	html += "<hr>";
	html += "<p>";
	html += "<img src=\"E:/wpicture/picture8.png\" alt=\"picture\" width=\"250\" height=\"300\">";
	html += "</p>";
	html += "<p>";
	html += "WARNING S";
	html += "</p>";
	html += "<p>";
	html += "<code>&nbsp &nbsp Absence of nitrate administration during cCTA acquisition may adversely affect the accuracy of the HeartFlow FFRCT Analysis.HeartFlow Analysis simulates maximal coronary hyperemia.Induction of coronary hyperemia commonly includes vasodilation of the epicardial coronary arteries via nitrate administration.Therefore, HeartFlow recommends following SCCT Guidelines for cCTA acquisition, which include the use of sublingual nitrates at the time of image acquisition.4<\code>";
	html += "</p>";
	html += "<p>";
	html += "<code>&nbsp &nbsp HeartFlow Analysis represents patient conditions at the time of CT acquisition. The duration of time and changes to patient health after CT acquisition must be assessed when interpreting the results.Clinical validation that supports FFRCT was limited to subjects whose CT acquisition occurred within 60 days of FFRcath(mean 18 + / -13 days).<\code>";
	html += "</p>";
	html += "<p>";
	html += "<code>&nbsp &nbsp Qualitative anatomical information presented on the 3D/2D computer generated anatomical models is for orientation purposes only.Quantitative lumen diameter is representative of the geometric model, and the accuracy is dependent on the quality of the CT data provided.It does not represent artery diameter and should not be used for treatment decisions.<\code>";
	html += "</p>";
	html += "<p>";
	html += "<code>&nbsp &nbsp Diagnostic performance of FFRCT using FFRcath as the reference standard is: 86% accurate, 84% sensitive, and 86% specific.3 Refer to product Instructions For Use for patient populations in which FFRCT has been clinically evaluated, relevant clinical data, and product warnings.<\code>";
	html += "</p>";
	html += "<p>";
	html += "<code>&nbsp &nbsp The performance of FFRCT has not been fully characterized in small vessels. Vessels with computed lumen diameters less than 1.8 mm are grayed and FFRCT is unavailable.When lumen diameter decreases below 1.8 mm due to disease, but distally recovers to 1.8 mm or greater, FFRCT remains available.In some instances, continued distal disease and / or recovery may not be presented in the model.<\code>";
	html += "</p>";
	html += "<p>";
	html += "<code>&nbsp &nbsp FFRCT has been studied in patients with prior PCI, but the results have only been validated in vessels without metallic stents.<\code>";
	html += "</p>";
	html += "<p>";
	html += "<code>&nbsp &nbsp Because of physiologic changes in pressure and flow within regions of complex or turbulent flow (i.e. stenosis, bifurcations),pressure measurements may vary, potentially affecting measured FFR.Similarly, computed FFRCT may be affected by flow disturbances in stenoses and bifurcations.<\code>";
	html += "</p>";
	html += "<p>";
	html += "FFR C T ERRO R";
	html += "</p>";
	html += "<p>";
	html += "<img src=\"E:/wpicture/picture9.png\" alt=\"picture\" width=\"250\" height=\"300\">";
	html += "<code>&nbsp &nbsp ? Error from the FFRCT v2.0 Clinical Validation Population. Not indicative of all patient populations. Please refer to complete summary of clinical data provided in the Instructions For Use to determine the population in which the FFRCT technology has been clinically validated.<\code>";
	html += "</p>";
	html += "<p>";
	html += "REFERENCE S";
	html += "</p>";
	html += "<p>";
	html += "<code>&nbsp &nbsp 1.Fractional flow reserve versus angiography for guiding percutaneous coronary intervention. Tonino PA, et al. NEJM 2009; 360:213-224.<\code>";
	html += "</p>";
	html += "<p>";
	html += "<code>&nbsp &nbsp 2.Fractional flow reserve-guided PCI versus medical therapy in stable coronary disease. De Bruyne B, et al. NEJM 2012; 367:991-1001.<\code>";
	html += "</p>";
	html += "<p>";
	html += "<code>&nbsp &nbsp 3.Diagnostic performance of non-invasive fractional flow reserve derived from coronary CT angiography in suspected coronary artery disease: The NXT Trial. Norgaard B, et al. JACC 2014; 63(12):1145-1155.<\code>";
	html += "</p>";
	html += "<p>";
	html += "<code>&nbsp &nbsp 4.SCCT guidelines for the performance and acquisition of coronary computed tomographic angiography. Abbara S, et al. JCCT 2016; DOI: 10.1016/j.jcct.2016.10.002.<\code>";
	html += "</p>";
	html += "</body>";
	html += "</html>";
	return html;
}
#endif
#if 0
// 组合html生成word
QString HtmlCreatedWord::saveHtmlToWord()
{
	QString html = "";
	html += "<html>";
	html += "<head>";
	html += "<title>qt实现生成word文档</title>";
	html += "<head>";
	html += "<body style=\"bgcolor:yellow\">";
	html += "<h1 style=\"background-color:blue\">测试qt实现生成word文档</h1>";
	html += "<hr>";
	html += "<p>word插入图片<img src=\"E:/picture1.png\" alt=\"picture\" width=\"100\" height=\"100\"></p>";
	html += "<hr>";
	html += "<table width=\"100%\" border=\"1\" cellspacing=\"1\" cellpadding=\"4\" align=\"center\">";
	html += "<tr>";
	html += "<td align=\"center\" height=\"60\">编程语言统计</td>";
	html += "</tr>";
	html += "<tr>";
	html += "<td align=\"center\" height=\"25\">2017-01-18---2018-01-18</td>";
	html += "</tr>";
	html += "</table>";
	html += "<table width=\"100%\" border=\"1\" cellspacing=\"1\" cellpadding=\"4\" bgcolor=\"#cccccc\" align=\"center\">";
	html += "<tr>";
	html += "<th>C/C++</th>";
	html += "<th>python</th>";
	html += "<th>java</th>";
	html += "<th>html</th>";
	html += "<th>Qt</th>";
	html += "</tr>";
	html += "<tr>";
	html += "<th>上升</th>";
	html += "<th>上升</th>";
	html += "<th>下降</th>";
	html += "<th>下降</th>";
	html += "<th>上升</th>";
	html += "</tr>";
	html += "</table>";
	html += "</body>";
	html += "</html>";
	return html;
}
#endif