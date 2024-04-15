#pragma once

struct Timer
{
	float TimeLeft;
	float Duration;
	bool Loop;

	Timer(float duration, bool loop)
		: TimeLeft(duration), Duration(duration), Loop(loop) {}
};
