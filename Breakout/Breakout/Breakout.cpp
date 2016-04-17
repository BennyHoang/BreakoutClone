#include "Breakout.h"

Breakout::Breakout() {
	Running = true;
}

int Breakout::OnExecute() {

	//int score = 0;
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
	Score.ReadFile(file);

	system("pause");

	return 0;
}

int main(int argc, char* argv[]) {
	Breakout theApp;

	return theApp.OnExecute();
}