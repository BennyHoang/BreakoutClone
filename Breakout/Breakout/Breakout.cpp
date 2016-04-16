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
			int score = 0;
	SDL_Event Event;
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

	system("pause");

	return 0;
}

int main(int argc, char* argv[]) {
	Breakout theApp;

	return theApp.OnExecute();
}