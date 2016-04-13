#include "Breakout.h"

Breakout::Breakout() {
	Running = true;
}

int Breakout::OnExecute() {
	if (OnInit() == false) {
		return -1;
	}
	else
	{
		if (!LoadFont())
		{
			printf("Failed to load font\n");
		}
		else
		{
			SDL_Event Event;
			while (Running) {
				while (SDL_PollEvent(&Event)) {
					OnEvent(&Event);
				}

				OnLoop();
				OnRender();
			}
		}

	}



	OnCleanup();

	return 0;
}

int main(int argc, char* argv[]) {
	Breakout theApp;

	return theApp.OnExecute();
}