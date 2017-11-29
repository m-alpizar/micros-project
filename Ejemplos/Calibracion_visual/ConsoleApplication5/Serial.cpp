#include "stdafx.h"

using namespace System;
using namespace System::IO::Ports;

int main(array<System::String ^> ^args)
{

	SerialPort port("COM3", 9600);
	port.Open();
	
	while (true) {

		String ^a;
		
		a = Console::ReadLine();

		
			
			port.Write(a);
			
		
	}
	return 0;
}
