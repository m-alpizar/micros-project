#pragma once
#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <stdio.h>
#include <sstream>
#include <string>
#include <windows.h>

namespace Com {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			findPorts();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::IO::Ports::SerialPort^  serialPort1;
	protected:
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::Label^  label3;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(571, 88);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(185, 33);
			this->comboBox1->TabIndex = 0;
			// 
			// comboBox2
			// 
			this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"9600", L"115200" });
			this->comboBox2->Location = System::Drawing::Point(571, 191);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(185, 33);
			this->comboBox2->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(425, 191);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(113, 25);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Baud Rate";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(425, 88);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(117, 25);
			this->label2->TabIndex = 3;
			this->label2->Text = L"COM Ports";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(571, 300);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(144, 47);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Inicio";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(571, 394);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(144, 43);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Close Port";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(71, 266);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(333, 31);
			this->textBox1->TabIndex = 6;
			this->textBox1->Text = L"Recibido aqui";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(74, 462);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(192, 31);
			this->textBox2->TabIndex = 7;
			this->textBox2->Text = L"Enter here";
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(71, 362);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(119, 60);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Send";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(253, 362);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(104, 60);
			this->button4->TabIndex = 9;
			this->button4->Text = L"Read";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(71, 133);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(195, 45);
			this->progressBar1->TabIndex = 10;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(66, 72);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(129, 25);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Port Status";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(820, 730);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void findPorts(void)
	{
		// get port names
		array<Object^>^ objectArray = SerialPort::GetPortNames();
		// add string array to combobox
		this->comboBox1->Items->AddRange(objectArray);

	}

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	};
			 
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
			 //init button
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		this->textBox1->Text = String::Empty;
		if (this->comboBox1->Text == String::Empty || this->comboBox2->Text == String::Empty)
			this->textBox1->Text = "Please Select Port Settings";
		else {
			try {
				// make sure port isn't open	
				if (!this->serialPort1->IsOpen) {
					this->serialPort1->PortName = this->comboBox1->Text;
					//this->textBox1->Text=this->comboBox1->Text;
					this->serialPort1->BaudRate = Int32::Parse(this->comboBox2->Text);
					//this->textBox1->Text=this->comboBox2->Text;
					this->textBox2->Text = "Enter Message Here";
					//open serial port 
					this->serialPort1->Open();
					this->progressBar1->Value = 100;

					//----------------------------------------------------------------------------
					cv::VideoCapture cap(1); //capture the video from webcam
					int posX;
					int posY;

					if (!cap.isOpened())  // if not success, exit program
					{
						std::cout << "Cannot open the web cam" << std::endl;

					}

					cv::namedWindow("Control", CV_WINDOW_AUTOSIZE); //create a window called "Control"

					int iLowH = 170;
					int iHighH = 179;

					int iLowS = 150;
					int iHighS = 255;

					int iLowV = 60;
					int iHighV = 255;

					//Create trackbars in "Control" window
					cv::createTrackbar("LowH", "Control", &iLowH, 179); //Hue (0 - 179)
					cv::createTrackbar("HighH", "Control", &iHighH, 179);

					cv::createTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
					cv::createTrackbar("HighS", "Control", &iHighS, 255);

					cv::createTrackbar("LowV", "Control", &iLowV, 255);//Value (0 - 255)
					cv::createTrackbar("HighV", "Control", &iHighV, 255);

					int iLastX = -1;
					int iLastY = -1;

					//Capture a temporary image from the camera
					cv::Mat imgTmp;
					cap.read(imgTmp);

					//Create a black image with the size as the camera output
					cv::Mat imgLines = cv::Mat::zeros(imgTmp.size(), CV_8UC3);;


					while (true)
					{


						cv::Mat imgOriginal;

						bool bSuccess = cap.read(imgOriginal); // read a new frame from video



						if (!bSuccess) //if not success, break loop
						{
							std::cout << "Cannot read a frame from video stream" << std::endl;
							break;
						}

						cv::Mat imgHSV;

						cvtColor(imgOriginal, imgHSV, cv::COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV

						cv::Mat imgThresholded;

						inRange(imgHSV, cv::Scalar(iLowH, iLowS, iLowV), cv::Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image

																															  //morphological opening (removes small objects from the foreground)
						erode(imgThresholded, imgThresholded, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5)));
						dilate(imgThresholded, imgThresholded, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5)));

						//morphological closing (removes small holes from the foreground)
						dilate(imgThresholded, imgThresholded, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5)));
						erode(imgThresholded, imgThresholded, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5)));

						//Calculate the moments of the thresholded image
						cv::Moments oMoments = moments(imgThresholded);

						double dM01 = oMoments.m01;
						double dM10 = oMoments.m10;
						double dArea = oMoments.m00;

						// if the area <= 10000, I consider that the there are no object in the image and it's because of the noise, the area is not zero 
						if (dArea > 10000)
						{
							//calculate the position of the ball
							posX = dM10 / dArea;
							posY = dM01 / dArea;
							
							

							if (iLastX >= 0 && iLastY >= 0 && posX >= 0 && posY >= 0)
							{
								//Draw a red line from the previous point to the current point
								line(imgLines, cv::Point(posX, posY), cv::Point(iLastX, iLastY), cv::Scalar(0, 0, 255), 2);
							}

							iLastX = posX;
							iLastY = posY;


						}

						imshow("Thresholded Image", imgThresholded); //show the thresholded image
						int posxAnterior;
						int posyAnterior;

						imgOriginal = imgOriginal + imgLines;
						imshow("Original", imgOriginal); //show the original image
														 // add sender name
						System::String^ str = posX.ToString() + ":" + posY.ToString()+"$";
						String^ name = this->serialPort1->PortName;
						// grab text and store in send buffer
						
						Sleep(20);
							//String^ posX = this->textBox2->Text;
						System::Convert::ToString(str);
						// write to serial
							if (this->serialPort1->IsOpen  ) {
								//this->_serialPort->WriteLine(String::Format("<{0}>: {1}",name,message));				
									
										this->serialPort1->WriteLine(str);
										this->textBox2->Text = str;
										
							}
						else
							this->textBox1->Text = "Port Not Opened";

						if (cv::waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
						{
							std::cout << "esc key is pressed by user" << std::endl;
							break;
						}


					};
					
					//---------------------------------------------------------------------------------
				}
				else
					this->textBox2->Text = "Port isn't openned";
			}
			catch (UnauthorizedAccessException^) {
				this->textBox2->Text = "UnauthorizedAccess";
			}
		}
}
			 //close button
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	//close serialPort
	this->serialPort1->Close();
	// update progress bar
	this->progressBar1->Value = 0;
	// Enable read button
	this->button4->Enabled = true;
	// Enable the init button
	this->button1->Enabled = true;
	
}
		 //send button
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	// add sender name
	String^ name = this->serialPort1->PortName;
	// grab text and store in send buffer
	String^ message = this->textBox2->Text;
	// write to serial
	if (this->serialPort1->IsOpen)
		//this->_serialPort->WriteLine(String::Format("<{0}>: {1}",name,message));
		this->serialPort1->WriteLine(message);
	else
		this->textBox1->Text = "Port Not Opened";
}
		 //Read button
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	// check if port is ready for reading
	if (this->serialPort1->IsOpen) {
		// Reset the text in the result label.
		this->textBox1->Text = String::Empty;

		// this will read manually
		try {
			this->textBox2->Text = this->serialPort1->ReadLine();
		}
		catch (TimeoutException^) {
			this->textBox1->Text = "Timeout Exception";
		}
		// Disable the init button
		// the asynchronous operation is done.
		this->button1->Enabled = false;
	}
	else
		// give error warning
		this->textBox1->Text = "Port Not Opened";
}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}
