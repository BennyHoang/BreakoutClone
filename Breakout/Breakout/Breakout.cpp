#include "Breakout.h"

Breakout::Breakout() {
	Running = true;
}

int Breakout::OnExecute() {
	if (OnInit() == false) {
		return -1;
	}

	SDL_Event Event;

	while (Running) {
		while (SDL_PollEvent(&Event)) {
			OnEvent(&Event);
		}

		if (!text1.initControll())
		{
			std::cout << "something went wrong" << std::endl;
			system("Pause");
			return -1;
		}
		

		OnLoop();
		OnRender();
	}

	OnCleanup();

	return 0;
}

int main(int argc, char* argv[]) {
	Breakout theApp;

	return theApp.OnExecute();
}