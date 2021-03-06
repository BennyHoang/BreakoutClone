#include "Breakout.h"

Breakout::Breakout() {
	Running = true;
}

int Breakout::OnExecute() {

	if (OnInit() == false)
	{
		printf("failed to init");
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
			menu_screen.init(gRenderer, window, zFont);
			fpsTimer.start();
			while (Running)
			{
				while (SDL_PollEvent(&Event))
				{
					OnEvent(&Event);
				}

				OnLoop();
				OnRender();
			}
		}
	}

	OnCleanup();
	Score.OpenFile(file);
	return 0;
}

int main(int argc, char* argv[]) {
	Breakout theApp;

	return theApp.OnExecute();
}