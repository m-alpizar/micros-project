#include "MyForm.h"

#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <stdio.h>


using namespace System;
using namespace System::IO::Ports;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args)
{
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Com::MyForm form;
	Application::Run(%form);
	cv::VideoCapture cap(0); //capture the video from webcam

	
	

	
}


