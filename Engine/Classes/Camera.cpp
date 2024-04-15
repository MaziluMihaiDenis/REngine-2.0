#include "Camera.h"
#include <Core/Math.h>
#include <Application/Application.h>
#include <Graphics/Graphics.h>

void RE::Camera::UpdateViewport()
{
	Graphics::GetInstance()->UpdateViewport();
}

float* RE::Camera::getProjectionMatrix()
{
	if (!ProjectionMatrix)
	{
		if (ProjectionType == PROJECTION_MODE::ORTHOGRAPHIC)
		{
			Window window = Application::GetInstance()->GetWindow();
			ProjectionMatrix = RE::Math::MakeProjectionMatrix(
				0,
				window.GetWidth(),
				0,
				window.GetHeight()
			);
		}
	}
	return ProjectionMatrix;
}
